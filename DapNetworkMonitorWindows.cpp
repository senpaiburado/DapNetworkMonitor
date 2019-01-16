#include "DapNetworkMonitorWindows.h"

DapNetworkMonitorWindows::DapNetworkMonitorWindows(QObject *parent):
    DapNetworkMonitorAbstract(parent)
{

}

bool DapNetworkMonitorWindows::isTunDriverInstalled() const
{
    // TODO
    return false;
}

bool DapNetworkMonitorWindows::isTunGatewayDefined() const
{
    // TODO
    return false;
}
bool DapNetworkMonitorWindows::isOtherGatewayDefined() const
{
    // TODO
    // Add checking all needed parameters for successful monitoring
    return false;
}

bool DapNetworkMonitorWindows::monitoringStart()
{
    // TODO
    return false;
}

bool DapNetworkMonitorWindows::monitoringStop()
{
    // TODO
    return false;
}
