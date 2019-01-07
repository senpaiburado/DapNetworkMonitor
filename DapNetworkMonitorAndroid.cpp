#include "DapNetworkMonitorAndroid.h"

DapNetworkMonitorAndroid::DapNetworkMonitorAndroid(const QString& dapVpnGateway,
                                                   const QString& upstreamDapServerAddress,
                                                   QObject *parent):
    DapNetworkMonitorAbstract(dapVpnGateway, upstreamDapServerAddress, parent)
{

}

bool DapNetworkMonitorAndroid::isTunDriverInstalled() const
{
    // TODO
    return false;
}

bool DapNetworkMonitorAndroid::isDapGatewayDefined() const
{
    // TODO
    return false;
}
bool DapNetworkMonitorAndroid::isOthersGatewayDefined() const
{
    // TODO
    return false;
}

bool DapNetworkMonitorAndroid::monitoringStart()
{
    // TODO
    return false;
}
bool DapNetworkMonitorAndroid::monitoringStop()
{
    // TODO
    return false;
}
