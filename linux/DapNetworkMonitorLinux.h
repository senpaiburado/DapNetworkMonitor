#ifndef NETWORKMONITORLINUX_H
#define NETWORKMONITORLINUX_H

#include "DapNetworkMonitorAbstract.h"

class DapNetworkMonitorLinux : public DapNetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit DapNetworkMonitorLinux(DapNetworkMonitorAbstract *parent = nullptr);

signals:

public slots:
};

#endif // NETWORKMONITORLINUX_H
