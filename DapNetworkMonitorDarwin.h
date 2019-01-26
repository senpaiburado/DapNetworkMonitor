#ifndef NETWORKMONITORMACOS_H
#define NETWORKMONITORMACOS_H

#include "DapNetworkMonitorAbstract.h"
#include <QProcess>

class DapNetworkMonitorDarwin : public DapNetworkMonitorAbstract
{
    Q_OBJECT
private:

    DapNetworkMonitorDarwin(QObject *parent = Q_NULLPTR);
    DapNetworkMonitorDarwin(const DapNetworkMonitorDarwin&) = delete;
    DapNetworkMonitorDarwin& operator=(const DapNetworkMonitorDarwin&) = delete;

    bool isTunGatewayDefined() const;
    bool isOtherGatewayDefined() const;
    void setMonitorActive(bool a_isActive);
    bool getMonitorActive();

public:
    static DapNetworkMonitorDarwin* instance()
        {static DapNetworkMonitorDarwin client; return &client;}

    bool isTunDriverInstalled() const override;
    void monitorParser(QString monOut);

private:
    QString parsedPath;
    QObject *parentForMonitor;
    QProcess *m_monitorProcess;
    QMutex m_mutex;
    bool m_isMonitorActive;

signals:

public slots:
    bool monitoringStart() override;
    bool monitoringStop() override;
};

#endif // NETWORKMONITORMACOS_H
