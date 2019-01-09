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

    bool m_isMonitoringRunning = false;
public:
    explicit DapNetworkMonitorAbstract(QObject *parent = Q_NULLPTR);

    virtual ~DapNetworkMonitorAbstract() {}

    virtual bool isTunDriverInstalled() const = 0;
    virtual bool isDapGatewayDefined() const = 0;
    virtual bool isOthersGatewayDefined() const = 0;
    virtual bool isMonitoringRunning() const final { return m_isMonitoringRunning; }

signals:
    void sigRouteChanged();
    void sigOtherGatewaysDefined();
    void sigOtherGatewaysUndefined();
    void sigDapGatewayDefined();
    void sigDapGatewayUndefined();
    void sigUpstreamRouteDefined();

    void sigMonitoringFinished();
    void sigMonitoringStarted();
    void sigMonitoringStartError();

public slots:
    void sltSetDefaultGateway(const QString& gw) { m_defaultGateway = gw; }
    void sltSetServerAddress(const QString& servAddr) { m_serverAddress = servAddr; }
    void sltSetTunnelDestination(const QString& tunDest) { m_tunnelDestination = tunDest; }

    virtual void monitoringStart() = 0;
    virtual void monitoringStop() = 0;
};


#endif // NETWORKMONITORABSTRACT_H
