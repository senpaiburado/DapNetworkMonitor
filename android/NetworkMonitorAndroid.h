#ifndef NETWORKMONITORANDROID_H
#define NETWORKMONITORANDROID_H

#include "NetworkMonitorAbstract.h"

class NetworkMonitorAndroid : public NetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit NetworkMonitorAndroid(NetworkMonitorAbstract *parent = nullptr);

signals:

public slots:
};

#endif // NETWORKMONITORANDROID_H
