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

    bool isTunGatewayDefinedInnerCheck() const;
    bool isOtherGatewayDefinedInnerCheck() const;

public:
    static DapNetworkMonitorDarwin* instance()
        {static DapNetworkMonitorDarwin client; return &client;}

    bool isTunDriverInstalled() const override;
    void monitorParser(QString monOut);

private:
    QString m_parsedPath;
    QProcess *m_monitorProcess;

signals:

public slots:
    bool monitoringStart() override;
    bool monitoringStop() override;
};

#endif // NETWORKMONITORMACOS_H
