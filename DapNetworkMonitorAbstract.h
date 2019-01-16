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
    QString m_tunnelGateway;

    bool m_isMonitoringRunning = false;

    bool m_isTunGatewayDefined = false;
    bool m_isOtherGatewayDefined = false;
public:
    explicit DapNetworkMonitorAbstract(QObject *parent = Q_NULLPTR);

    virtual ~DapNetworkMonitorAbstract() {}

    virtual bool isTunDriverInstalled() const = 0;

    bool isTunGatewayDefined() { return  m_isTunGatewayDefined; }
    bool isOtherGatewayDefined() { return  m_isOtherGatewayDefined; }

    virtual bool isMonitoringRunning() const final { return m_isMonitoringRunning; }

    bool isUpstreamRoute(const QString& destination, const QString& gateway)  {
        return destination == m_serverAddress && gateway == m_defaultGateway;
    }

signals:
    void sigRouteChanged();
    void sigOtherGatewayDefined();
    void sigOtherGatewayUndefined();
    void sigTunGatewayDefined();
    void sigTunGatewayUndefined();
    void sigUpstreamRouteDefined();
    void sigUpstreamRouteUndefined();

    void sigMonitoringFinished();
    void sigMonitoringStarted();
    void sigMonitoringStartError();

public slots:
    void sltSetDefaultGateway(const QString& gw) { m_defaultGateway = gw; }
    void sltSetTunGateway(const QString& gw) { m_tunnelGateway = gw; }
    void sltSetServerAddress(const QString& servAddr) { m_serverAddress = servAddr; }
    void sltSetTunnelDestination(const QString& tunDest) { m_tunnelDestination = tunDest; }

    // returns true if operation successfully
    virtual bool monitoringStart() = 0;
    virtual bool monitoringStop() = 0;
};


#endif // NETWORKMONITORABSTRACT_H
