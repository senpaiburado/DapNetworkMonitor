#ifndef NETWORKMONITORMACOS_H
#define NETWORKMONITORMACOS_H

#include "DapNetworkMonitorAbstract.h"

class DapNetworkMonitorDarwin : public DapNetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit DapNetworkMonitorDarwin(QObject *parent = Q_NULLPTR);

    bool isTunDriverInstalled() const override;
    bool isDapGatewayDefined() const override;
    bool isOthersGatewayDefined() const override;
    bool monitoringStart() override;
    bool monitoringStop() override;
signals:

public slots:
};

#endif // NETWORKMONITORMACOS_H
