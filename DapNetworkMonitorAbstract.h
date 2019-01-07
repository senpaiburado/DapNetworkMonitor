#ifndef NETWORKMONITORABSTRACT_H
#define NETWORKMONITORABSTRACT_H

#include <QDebug>
#include <QObject>

class DapNetworkMonitorAbstract : public QObject
{
    Q_OBJECT
protected:
    // default gateway before install tunneling
    QString m_defaultGateway;

    QString m_tunnelDestination;
    QString m_serverAddress;
public:
    explicit DapNetworkMonitorAbstract(QObject *parent = Q_NULLPTR);

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
    void sltSetDefaultGateway(const QString& gw) { m_defaultGateway = gw; }
    void sltSetServerAddress(const QString& servAddr) { m_serverAddress = servAddr; }
    void sltSetTunnelDestination(const QString& tunDest) { m_tunnelDestination = tunDest; }
};

#endif // NETWORKMONITORABSTRACT_H
