#include "DapNetworkMonitorAbstract.h"


DapNetworkMonitorAbstract::DapNetworkMonitorAbstract(const QString& dapVpnGateway,
                                                     const QString& upstreamDapServerAddress,
                                                     QObject *parent)
    : QObject(parent), m_dapVpnGateway(dapVpnGateway), m_upstreamDapServerAddress(upstreamDapServerAddress)
{
    if(dapVpnGateway.isEmpty() || upstreamDapServerAddress.isEmpty()) {
        qCritical() << "Gateway or upstreamAddress is empty";
    }
}
