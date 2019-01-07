#include "DapNetworkMonitorDarwin.h"

DapNetworkMonitorDarwin::DapNetworkMonitorDarwin(const QString& dapVpnGateway,
                                                 const QString& upstreamDapServerAddress,
                                                 QObject *parent):
    DapNetworkMonitorAbstract(dapVpnGateway, upstreamDapServerAddress, parent)
{

}

bool DapNetworkMonitorDarwin::isTunDriverInstalled() const
{
    // TODO
    return false;
}

bool DapNetworkMonitorDarwin::isDapGatewayDefined() const
{
    // TODO
    return false;
}
bool DapNetworkMonitorDarwin::isOthersGatewayDefined() const
{
    // TODO
    return false;
}

bool DapNetworkMonitorDarwin::monitoringStart()
{
    // TODO
    return false;
}
bool DapNetworkMonitorDarwin::monitoringStop()
{
    // TODO
    return false;
}
