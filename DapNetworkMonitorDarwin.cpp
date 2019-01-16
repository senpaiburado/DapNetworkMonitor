#include "DapNetworkMonitorDarwin.h"

DapNetworkMonitorDarwin::DapNetworkMonitorDarwin(QObject *parent):
    DapNetworkMonitorAbstract(parent)
{

}

bool DapNetworkMonitorDarwin::isTunDriverInstalled() const
{
    // TODO
    return false;
}

bool DapNetworkMonitorDarwin::isTunGatewayDefined() const
{
    // TODO
    return false;
}
bool DapNetworkMonitorDarwin::isOtherGatewayDefined() const
{
    // TODO
    return false;
}

bool DapNetworkMonitorDarwin::monitoringStart()
{
    // TODO
    // Add checking all needed parameters for successful monitoring
    return false;
}
bool DapNetworkMonitorDarwin::monitoringStop()
{
    // TODO
    return false;
}
