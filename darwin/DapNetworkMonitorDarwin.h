#ifndef NETWORKMONITORMACOS_H
#define NETWORKMONITORMACOS_H

#include "DapNetworkMonitorAbstract.h"

class DapNetworkMonitorDarwin : public DapNetworkMonitorAbstract
{
    Q_OBJECT
public:
    explicit DapNetworkMonitorDarwin(DapNetworkMonitorAbstract *parent = nullptr);

signals:

public slots:
};

#endif // NETWORKMONITORMACOS_H
