#ifndef NETWORKMONITORMACOS_H
#define NETWORKMONITORMACOS_H

#include "DapNetworkMonitorAbstract.h"

class DapNetworkMonitorMacOS : public DapNetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit DapNetworkMonitorMacOS(DapNetworkMonitorAbstract *parent = nullptr);

signals:

public slots:
};

#endif // NETWORKMONITORMACOS_H
