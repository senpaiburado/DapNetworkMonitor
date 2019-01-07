#include "DapNetworkMonitorAndroid.h"

DapNetworkMonitorAndroid::DapNetworkMonitorAndroid(QObject *parent):
    DapNetworkMonitorAbstract(parent)
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
    // Add checking all needed parameters for successful monitoring
    return false;
}
bool DapNetworkMonitorAndroid::monitoringStop()
{
    // TODO
    return false;
}
