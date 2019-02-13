#ifndef NETWORKMONITORANDROID_H
#define NETWORKMONITORANDROID_H

#include "DapNetworkMonitorAbstract.h"

class DapNetworkMonitorAndroid : public DapNetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit DapNetworkMonitorAndroid(QObject *parent = Q_NULLPTR);

    bool isTunDriverInstalled() const override;
    bool isTunGatewayDefined() const;
    bool isOtherGatewayDefined() const;
    bool monitoringStart() override;
    bool monitoringStop() override;
signals:

public slots:
};

#endif // NETWORKMONITORANDROID_H
