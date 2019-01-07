#include "DapNetworkMonitorWindows.h"

DapNetworkMonitorWindows::DapNetworkMonitorWindows(const QString& dapVpnGateway,
                                                   const QString& upstreamDapServerAddress,
                                                   QObject *parent):
    DapNetworkMonitorAbstract(dapVpnGateway, upstreamDapServerAddress, parent)
{

}

bool DapNetworkMonitorWindows::isTunDriverInstalled() const
{
    // TODO
    return false;
}

bool DapNetworkMonitorWindows::isDapGatewayDefined() const
{
    // TODO
    return false;
}
bool DapNetworkMonitorWindows::isOthersGatewayDefined() const
{
    // TODO
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
