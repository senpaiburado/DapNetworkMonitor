#ifndef NETWORKMONITORWINDOWS_H
#define NETWORKMONITORWINDOWS_H

#include "DapNetworkMonitorAbstract.h"

class DapNetworkMonitorWindows : public DapNetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit DapNetworkMonitorWindows(DapNetworkMonitorAbstract *parent = nullptr);

signals:

public slots:
};

#endif // NETWORKMONITORWINDOWS_H
