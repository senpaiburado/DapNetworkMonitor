#ifndef NETWORKMONITORWINDOWS_H
#define NETWORKMONITORWINDOWS_H

#include "NetworkMonitorAbstract.h"

class NetworkMonitorWindows : public NetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit NetworkMonitorWindows(NetworkMonitorAbstract *parent = nullptr);

signals:

public slots:
};

#endif // NETWORKMONITORWINDOWS_H
