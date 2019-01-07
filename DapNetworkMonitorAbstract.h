#ifndef NETWORKMONITORABSTRACT_H
#define NETWORKMONITORABSTRACT_H

#include <QDebug>
#include <QObject>

class DapNetworkMonitorAbstract : public QObject
{
    Q_OBJECT
protected:
    QString m_dapVpnGateway;
    QString m_upstreamDapServerAddress;
public:
    explicit DapNetworkMonitorAbstract(const QString& dapVpnGateway,
                                       const QString& upstreamDapServerAddress,
                                       QObject *parent = Q_NULLPTR);

    virtual ~DapNetworkMonitorAbstract() {}

    virtual bool isTunDriverInstalled() const = 0;
    virtual bool isDapGatewayDefined() const = 0;
    virtual bool isOthersGatewayDefined() const = 0;

    // Returns true if operation successfully
    virtual bool monitoringStart() = 0;
    virtual bool monitoringStop() = 0;
signals:
    void sigRouteChanged();
    void sigOtherGatewaysDefined();
    void sigOtherGatewaysUndefined();
    void sigDapGatewayDefined();
    void sigDapGatewayUndefined();
    void sigUpstreamRouteDefined();

public slots:
    void onDapVpnGatewayChanged(const QString& gw) { m_dapVpnGateway = gw;}
    void onUpstreamDapServerAddressChanged(const QString& upstreamAddr)
    { m_upstreamDapServerAddress = upstreamAddr; }
};

#endif // NETWORKMONITORABSTRACT_H
