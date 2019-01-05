#ifndef NETWORKMONITORANDROID_H
#define NETWORKMONITORANDROID_H

#include "DapNetworkMonitorAbstract.h"

class DapNetworkMonitorAndroid : public DapNetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit DapNetworkMonitorAndroid(DapNetworkMonitorAbstract *parent = nullptr);

signals:

public slots:
};

#endif // NETWORKMONITORANDROID_H
