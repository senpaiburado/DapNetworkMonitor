#ifndef NETWORKMONITORMACOS_H
#define NETWORKMONITORMACOS_H

#include "NetworkMonitorAbstract.h"

class NetworkMonitorMacos : public NetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit NetworkMonitorMacos(NetworkMonitorAbstract *parent = nullptr);

signals:

public slots:
};

#endif // NETWORKMONITORMACOS_H
