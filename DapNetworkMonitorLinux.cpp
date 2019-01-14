#include "DapNetworkMonitorLinux.h"

void DapNetworkMonitorLinux::cbMonitorNotification(const dap_network_notification_t notification)
{
    if(notification.type == IP_ADDR_ADD || notification.type == IP_ADDR_REMOVE) {

        qDebug() << QString("Interface %1 %2 has IP address %3")
                    .arg(notification.addr.interface_name)
                    .arg((notification.type == IP_ADDR_ADD ? "now" : "no longer"))
                    .arg(notification.addr.s_ip);


    } else if(notification.type == IP_ROUTE_ADD || notification.type == IP_ROUTE_REMOVE) {
        if (notification.type == IP_ROUTE_REMOVE) {
            qDebug() << QString("Delete route to destination --> %1/%2 proto %3 and gateway %4")
                        .arg(notification.route.s_destination_address)
                        .arg(notification.route.netmask)
                        .arg(notification.route.protocol)
                        .arg(notification.route.s_gateway_address);

        } else  if (notification.type == IP_ROUTE_ADD) {
            qDebug() << QString("Adding route to destination --> %1/%2 proto %3 and gateway %4")
                        .arg(notification.route.s_destination_address)
                        .arg(notification.route.netmask)
                        .arg(notification.route.protocol)
                        .arg(notification.route.s_gateway_address);
        }
    }

}

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
    return false;
}

void DapNetworkMonitorLinux::monitoringStart()
{
    qDebug() << "Start network monitoring";
    if(m_isMonitoringRunning == true) {
        qWarning() << "Network monitoring already running";
        return;
    }

    if(dap_network_monitor_init(cbMonitorNotification) == 0) {
        m_isMonitoringRunning = true;
    }
}

void DapNetworkMonitorLinux::monitoringStop()
{
    qDebug() << "Stop network monitoring";
    dap_network_monitor_deinit();

    m_isMonitoringRunning = false;
}
