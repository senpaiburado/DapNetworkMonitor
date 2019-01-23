#ifndef NETWORKMONITORMACOS_H
#define NETWORKMONITORMACOS_H

#include "DapNetworkMonitorAbstract.h"

class DapNetworkMonitorDarwin : public DapNetworkMonitorAbstract
{
    Q_OBJECT
private:

    DapNetworkMonitorDarwin(QObject *parent = Q_NULLPTR);
    DapNetworkMonitorDarwin(const DapNetworkMonitorDarwin&) = delete;
    DapNetworkMonitorDarwin& operator=(const DapNetworkMonitorDarwin&) = delete;

    bool isTunGatewayDefined() const;
    bool isOtherGatewayDefined() const;

public:
    static DapNetworkMonitorDarwin* instance()
        {static DapNetworkMonitorDarwin client; return &client;}

    bool isTunDriverInstalled() const override;
signals:

public slots:
    bool monitoringStart() override;
    bool monitoringStop() override;
};

#endif // NETWORKMONITORMACOS_H
