#include "DapNetworkMonitorAbstract.h"


DapNetworkMonitorAbstract::DapNetworkMonitorAbstract(QObject *parent)
    : QObject(parent)
{
    connect(this, &DapNetworkMonitorAbstract::sigMonitoringStarted, [=] {
        qDebug() << "Monitoring started";
        m_isMonitoringRunning = true;
    });

    connect(this, &DapNetworkMonitorAbstract::sigMonitoringFinished, [=]{
        qDebug() << "Monitoring finished";
        m_isMonitoringRunning = false;
    });
}
