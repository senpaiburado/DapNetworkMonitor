#ifndef NETWORKMONITORABSTRACT_H
#define NETWORKMONITORABSTRACT_H

#include <QObject>

class DapNetworkMonitorAbstract : public QObject
{
    Q_OBJECT
public:
    explicit DapNetworkMonitorAbstract(QObject *parent = nullptr);
    virtual ~DapNetworkMonitorAbstract(){}
signals:

public slots:
};

#endif // NETWORKMONITORABSTRACT_H
