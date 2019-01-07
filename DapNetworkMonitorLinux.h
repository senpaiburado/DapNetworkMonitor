#ifndef NETWORKMONITORLINUX_H
#define NETWORKMONITORLINUX_H

#include "DapNetworkMonitorAbstract.h"

class DapNetworkMonitorLinux : public DapNetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit DapNetworkMonitorLinux(QObject *parent = Q_NULLPTR);

    bool isTunDriverInstalled() const override;
    bool isDapGatewayDefined() const override;
    bool isOthersGatewayDefined() const override;
    bool monitoringStart() override;
    bool monitoringStop() override;

signals:

public slots:
};

#endif // NETWORKMONITORLINUX_H
