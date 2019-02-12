#include <winsock2.h>
#include <iphlpapi.h>
#include <windows.h>
#include <QThread>

#include "DapNetworkMonitorWindows.h"
#include "tuntap.h"

DapNetworkMonitorWindows::DapNetworkMonitorWindows(QObject *parent):
    DapNetworkMonitorAbstract(parent)
{
    qInfo() << "starting Windows network monitor";
     QtConcurrent::run(this, &DapNetworkMonitorWindows::internalWorker);
}

bool DapNetworkMonitorWindows::isTunDriverInstalled() const
{
    return true;
}

bool DapNetworkMonitorWindows::isTunGatewayDefined() const
{
    return m_isTunGatewayDefined;
}
bool DapNetworkMonitorWindows::isOtherGatewayDefined() const
{
    return m_isOtherGatewayDefined;
}

bool DapNetworkMonitorWindows::monitoringStart()
{
    QMutexLocker lock(&mutex);
    m_isMonitoringRunning = true;
    return m_isMonitoringRunning;
}

bool DapNetworkMonitorWindows::monitoringStop()
{
    QMutexLocker lock(&mutex);
    m_isMonitoringRunning = false;
    return m_isMonitoringRunning;
}

void DapNetworkMonitorWindows::internalWorker() {
    HANDLE hAddrChange, hRouteChange;
    OVERLAPPED ovAddrChange, ovRouteChange;

    ovAddrChange.hEvent  = WSACreateEvent();
    ovRouteChange.hEvent = WSACreateEvent();

    bool bNoDefaultGateWay = false;

    while (true)
    {
        DWORD dwRet = NotifyAddrChange(&hAddrChange, &ovAddrChange);
        if ( dwRet != NO_ERROR && WSAGetLastError() != WSA_IO_PENDING ) {
            qDebug() << "NotifyAddrChange failed, error code ==" << QString::number(WSAGetLastError())
                     << ", shutdown DapNetworkWindowsMonitor";
            return;
        }

        if ( (dwRet = NotifyRouteChange(&hRouteChange, &ovRouteChange)) != NO_ERROR && WSAGetLastError() != WSA_IO_PENDING ) {
            qDebug() << "NotifyRouteChange failed, error code ==" << QString::number(WSAGetLastError())
                     << ", shutdown DapNetworkWindowsMonitor";
            return;
        }

        HANDLE hEvents[2] = {ovAddrChange.hEvent, ovRouteChange.hEvent};

        dwRet = WaitForMultipleObjects(sizeof(hEvents)/sizeof(HANDLE), hEvents, false, INFINITE);

        if ( m_isMonitoringRunning && ( dwRet == WAIT_OBJECT_0 || dwRet == (WAIT_OBJECT_0 + 1) ) ) {
            qDebug() << "[DapNetworkWindowsMonitor] : some event happend";
            emit sigRouteChanged();

            if (!TunTap::getInstance().getDefaultGateWayCount() && !bNoDefaultGateWay) {
                bNoDefaultGateWay = true;
                qDebug() << "[SapNetworkWindowsMonitor] : happend sigDefaultGatewayUndefined situation";
                emit sigTunGatewayUndefined();
            }

            if (TunTap::getInstance().getDefaultGateWayCount() && bNoDefaultGateWay) {
                bNoDefaultGateWay = false;
                qDebug() << "[SapNetworkWindowsMonitor] : happend sigDefaultGatewayDefined situation";
                emit sigTunGatewayDefined();
            }
        }
    }
}
