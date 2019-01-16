#include "DapNetworkMonitorLinux.h"

void DapNetworkMonitorLinux::cbMonitorNotification(const dap_network_notification_t notification)
{
    if(notification.type == IP_ADDR_ADD || notification.type == IP_ADDR_REMOVE) {

        qInfo() << QString("Interface %1 %2 has IP address %3")
                    .arg(notification.addr.interface_name)
                    .arg((notification.type == IP_ADDR_ADD ? "now" : "no longer"))
                    .arg(notification.addr.s_ip);

    } else if(notification.type == IP_ROUTE_ADD || notification.type == IP_ROUTE_REMOVE) {
        emit instance()->sigRouteChanged();

        qDebug() << QString("%1 route to destination --> %2/%3 proto %4 and gateway %5")
                    .arg((notification.type == IP_ROUTE_ADD ? "Add" : "Delete"))
                    .arg(notification.route.s_destination_address)
                    .arg(notification.route.netmask)
                    .arg(notification.route.protocol)
                    .arg(notification.route.s_gateway_address);

        if (notification.type == IP_ROUTE_REMOVE) {
            if(notification.route.destination_address == DAP_ADRESS_UNDEFINED &&
                    notification.route.gateway_address != DAP_ADRESS_UNDEFINED) {
                QString gatewayAddr(notification.route.s_gateway_address);
                if(gatewayAddr == instance()->m_tunnelGateway) {
                    qInfo() << "Tunnel gateway is undefined";
                    emit instance()->sigTunGatewayUndefined();
                } else {
                    qInfo() << "Other gateway is undefined";
                    emit instance()->sigOtherGatewayUndefined();
                }
            } else if(notification.route.destination_address != DAP_ADRESS_UNDEFINED &&
                      notification.route.gateway_address != DAP_ADRESS_UNDEFINED) {
                if(instance()->isUpstreamRoute(notification.route.s_destination_address,
                                               notification.route.s_gateway_address)) {
                    qInfo() << "Upstream route is undefined";
                    emit instance()->sigUpstreamRouteUndefined();
                }
            }

        } else  if (notification.type == IP_ROUTE_ADD) {
            if(notification.route.destination_address == DAP_ADRESS_UNDEFINED &&
                    notification.route.gateway_address != DAP_ADRESS_UNDEFINED) {
                QString gatewayAddr(notification.route.s_gateway_address);

                if(gatewayAddr == instance()->m_tunnelGateway) {
                    qInfo() << "Tunnel gateway is defined";
                    emit instance()->sigTunGatewayDefined();
                } else {
                    qInfo() << "Other gateway is defined";
                    emit instance()->sigOtherGatewayUndefined();
                }
            } else if(notification.route.destination_address != DAP_ADRESS_UNDEFINED &&
                      notification.route.gateway_address != DAP_ADRESS_UNDEFINED) {
                if(instance()->isUpstreamRoute(notification.route.s_destination_address,
                                               notification.route.s_gateway_address)) {
                    qInfo() << "Upstream route is defined";
                    emit instance()->sigUpstreamRouteDefined();
                }
            }
        }
    }

}

DapNetworkMonitorLinux::DapNetworkMonitorLinux(QObject *parent):
    DapNetworkMonitorAbstract(parent)
{

}

bool DapNetworkMonitorLinux::isTunDriverInstalled() const
{
    return true;
}

bool DapNetworkMonitorLinux::monitoringStart()
{
    qDebug() << "Start network monitoring";
    if(m_isMonitoringRunning == true) {
        qWarning() << "Network monitoring already running";
    }

    if(dap_network_monitor_init(cbMonitorNotification) == 0) {
        m_isMonitoringRunning = true;
    }

    return m_isMonitoringRunning;
}

bool DapNetworkMonitorLinux::monitoringStop()
{
    qDebug() << "Stop network monitoring";
    dap_network_monitor_deinit();

    m_isMonitoringRunning = false;
    return true;
}
