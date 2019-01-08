#include "DapNetworkMonitorAbstract.h"


DapNetworkMonitorAbstract::DapNetworkMonitorAbstract(QObject *parent)
    : QObject(parent)
{
    m_isMonitoringRunning = false;
}
