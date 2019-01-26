#ifndef NETWORKMONITORWINDOWS_H
#define NETWORKMONITORWINDOWS_H

#include "DapNetworkMonitorAbstract.h"

class DapNetworkMonitorWindows : public DapNetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit DapNetworkMonitorWindows(QObject *parent = Q_NULLPTR);

    bool isTunDriverInstalled() const override;
    bool isTunGatewayDefined() const override;
    bool isOtherGatewayDefined() const override;
    bool monitoringStart() override;
    bool monitoringStop() override;

signals:

public slots:
};

#endif // NETWORKMONITORWINDOWS_H
