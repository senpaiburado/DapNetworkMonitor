#include "DapNetworkMonitorLinux.h"

DapNetworkMonitorLinux::DapNetworkMonitorLinux(QObject *parent):
    DapNetworkMonitorAbstract(parent)
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
    // Add checking all needed parameters for successful monitoring
    return false;
}

bool DapNetworkMonitorLinux::monitoringStart()
{
    // TODO
    return false;
}
bool DapNetworkMonitorLinux::monitoringStop()
{
    // TODO
    return false;
}
