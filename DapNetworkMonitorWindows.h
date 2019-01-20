#ifndef NETWORKMONITORWINDOWS_H
#define NETWORKMONITORWINDOWS_H

#include "DapNetworkMonitorAbstract.h"

class DapNetworkMonitorWindows : public DapNetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit DapNetworkMonitorWindows(QObject *parent = Q_NULLPTR);

    bool isTunDriverInstalled() const override;
    bool isTunGatewayDefined() const;
    bool isOtherGatewayDefined() const;
    bool monitoringStart() override;
    bool monitoringStop() override;
    static DapNetworkMonitorWindows* instance() {
        static DapNetworkMonitorWindows client; return &client;
    }
signals:

public slots:
};

#endif // NETWORKMONITORWINDOWS_H
