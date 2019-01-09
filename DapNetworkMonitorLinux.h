#ifndef NETWORKMONITORLINUX_H
#define NETWORKMONITORLINUX_H

#include "DapNetworkMonitorAbstract.h"
#include "DapMonitorCmdProgram.h"

class DapNetworkMonitorLinux : public DapNetworkMonitorAbstract
{
    Q_OBJECT
private:
    DapMonitorCmdProgram m_cmdProgram;
public:
    explicit DapNetworkMonitorLinux(QObject *parent = Q_NULLPTR);

    bool isTunDriverInstalled() const override;
    bool isDapGatewayDefined() const override;
    bool isOthersGatewayDefined() const override;
signals:

public slots:
    void monitoringStart() override;
    void monitoringStop() override;
};

#endif // NETWORKMONITORLINUX_H
