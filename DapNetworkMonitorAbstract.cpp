#include "DapNetworkMonitorAbstract.h"


DapNetworkMonitorAbstract::DapNetworkMonitorAbstract(QObject *parent)
    : QObject(parent)
{
    connect(this, &DapNetworkMonitorAbstract::sigMonitoringStarted, [=]{
        qDebug() << "Monitoring started";
        m_isMonitoringRunning = true;
    });

    connect(this, &DapNetworkMonitorAbstract::sigMonitoringFinished, [=]{
        qDebug() << "Monitoring finished";
        m_isMonitoringRunning = false;
    });

    connect(this, &DapNetworkMonitorAbstract::sigTunGatewayDefined, [=]{
        m_isTunGatewayDefined = true;
        m_isOtherGatewayDefined = false;
    });

    connect(this, &DapNetworkMonitorAbstract::sigTunGatewayUndefined, [=]{
        m_isTunGatewayDefined = false;
    });

    connect(this, &DapNetworkMonitorAbstract::sigOtherGatewayDefined, [=]{
        m_isOtherGatewayDefined = true;
        m_isTunGatewayDefined = false;
    });

    connect(this, &DapNetworkMonitorAbstract::sigOtherGatewayUndefined, [=]{
        m_isOtherGatewayDefined = false;
    });
}
