#ifndef NETWORKMONITORWINDOWS_H
#define NETWORKMONITORWINDOWS_H

#include "DapNetworkMonitorAbstract.h"
#include <QtConcurrent/QtConcurrent>

class DapNetworkMonitorWindows : public DapNetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit DapNetworkMonitorWindows(QObject *parent = Q_NULLPTR);

    static DapNetworkMonitorWindows *instance() {
        static DapNetworkMonitorWindows me;
        return &me;
    }

    bool isTunDriverInstalled() const override;
    bool isTunGatewayDefined() const;
    bool isOtherGatewayDefined() const;
    bool monitoringStart() override;
    bool monitoringStop() override;

private:
    void internalWorker();
    QMutex mutex;

signals:

public slots:
};

#endif // NETWORKMONITORWINDOWS_H
