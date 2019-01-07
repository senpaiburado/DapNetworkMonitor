#include "DapNetworkMonitorLinux.h"

DapNetworkMonitorLinux::DapNetworkMonitorLinux(const QString& dapVpnGateway,
                                               const QString& upstreamDapServerAddress,
                                               QObject *parent):
    DapNetworkMonitorAbstract(dapVpnGateway, upstreamDapServerAddress, parent)
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
