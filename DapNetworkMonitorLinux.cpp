#include "DapNetworkMonitorLinux.h"

DapNetworkMonitorLinux::DapNetworkMonitorLinux(QObject *parent):
    DapNetworkMonitorAbstract(parent), m_process("ip", {"monitor"}, this)
{

}

bool DapNetworkMonitorLinux::isTunDriverInstalled() const
{
    // TODO
    return false;
}

bool DapNetworkMonitorLinux::isDapGatewayDefined() const
{
    // TODO
    return false;
}
bool DapNetworkMonitorLinux::isOthersGatewayDefined() const
{
    // TODO
    return false;
}

bool DapNetworkMonitorLinux::isMonitoringRunning() const
{
    // TODO
    return false;
}

void DapNetworkMonitorLinux::monitoringStart()
{
    qDebug() << "Start network monitoring";
    m_process.start();
}

void DapNetworkMonitorLinux::monitoringStop()
{
    qDebug() << "Stop network monitoring";
    m_process.stop();
}
