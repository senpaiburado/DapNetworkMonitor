#ifndef NETWORKMONITORLINUX_H
#define NETWORKMONITORLINUX_H

#include "DapNetworkMonitorAbstract.h"
#include "DapMonitorCmdProgram.h"
#include "dap_network_monitor.h"


class DapNetworkMonitorLinux : public DapNetworkMonitorAbstract
{
    Q_OBJECT
private:

    static void cbMonitorNotification(const dap_network_notification_t notification);

    DapNetworkMonitorLinux(QObject *parent = Q_NULLPTR);
    DapNetworkMonitorLinux(const DapNetworkMonitorLinux&) = delete;
    DapNetworkMonitorLinux& operator=(const DapNetworkMonitorLinux&) = delete;
public:
    static DapNetworkMonitorLinux* instance()
        {static DapNetworkMonitorLinux client; return &client;}

    bool isTunDriverInstalled() const override;
signals:

public slots:
    bool monitoringStart() override;
    bool monitoringStop() override;
};

#endif // NETWORKMONITORLINUX_H
