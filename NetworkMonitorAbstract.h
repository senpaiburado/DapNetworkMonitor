#ifndef NETWORKMONITORABSTRACT_H
#define NETWORKMONITORABSTRACT_H

#include <QObject>

class NetworkMonitorAbstract : public QObject
{
    Q_OBJECT
public:
    explicit NetworkMonitorAbstract(QObject *parent = nullptr);
    virtual ~NetworkMonitorAbstract(){}
signals:

public slots:
};

#endif // NETWORKMONITORABSTRACT_H
