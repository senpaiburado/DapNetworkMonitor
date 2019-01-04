#ifndef NETWORKMONITORLINUX_H
#define NETWORKMONITORLINUX_H

#include "NetworkMonitorAbstract.h"

class NetworkMonitorLinux : public NetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit NetworkMonitorLinux(NetworkMonitorAbstract *parent = nullptr);

signals:

public slots:
};

#endif // NETWORKMONITORLINUX_H
