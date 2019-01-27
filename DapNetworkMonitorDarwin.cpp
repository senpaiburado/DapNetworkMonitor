#include "DapNetworkMonitorDarwin.h"
#include <QProcess>

DapNetworkMonitorDarwin::DapNetworkMonitorDarwin(QObject *parent):
    DapNetworkMonitorAbstract(parent)
{
    QString monitorProgramName = "route";
    QStringList monitorProgramArgs; monitorProgramArgs << "monitor";

    m_monitorProcess = new QProcess(this);
    m_monitorProcess->setProcessChannelMode(QProcess::MergedChannels);


    connect(m_monitorProcess,&QProcess::started, [=] {
        qInfo() << "Started network monitor";
    });
    connect(m_monitorProcess,static_cast<void (QProcess::*)(int) >(&QProcess::finished), [=] {
        qInfo() << "Stopped network monitor";
    });
    // No need to define a slot function...
    connect(m_monitorProcess, &QProcess::errorOccurred, [=](QProcess::ProcessError error) {
        qWarning() << "Network monitor error: " << error << endl;
    });

    connect(m_monitorProcess, &QProcess::readyReadStandardOutput, this, [=] {
        QString strRead(m_monitorProcess->readAllStandardOutput());

        if (!isMonitoringRunning())
            return;

        QStringList cmds = strRead.split("\n");
        for(int i = 0 ; i < cmds.size() ; i ++) {
                //qInfo() << "---------------------- " << cmds.at(i);
                monitorParser(cmds.at(i));
        }
    });

    m_monitorProcess->start(monitorProgramName, monitorProgramArgs);
}

bool DapNetworkMonitorDarwin::isTunDriverInstalled() const
{
    // TODO
    return false;
}


bool DapNetworkMonitorDarwin::monitoringStart()
{
    m_isMonitoringRunning = true;
    return m_isMonitoringRunning;
}
bool DapNetworkMonitorDarwin::monitoringStop()
{
    m_isMonitoringRunning = false;
    return m_isMonitoringRunning;
}

void DapNetworkMonitorDarwin::monitorParser(QString monOut)
{
    QStringList res = monOut.split(" ");
    //qDebug() << "res " << res ;

    if( monOut == ""){
        //qDebug() << "Parsed path ends";
        m_parsedPath = "";
    }

    if( m_parsedPath == "" ){ /// Parser start
        if( ( res[0] == "got" ) && ( res[1] == "message" ) ){
            m_parsedPath = "got_message";
            //qDebug() << "Parsed path "<< parsedPath;
        }
    }else if( m_parsedPath == "got_message" ){ /// got message from route monitor
    //qDebug() << "monOut = "<<monOut;
        if( res[0] == "RTM_GET:" ){
            m_parsedPath = "got_message_rtm_get";
            //qDebug() << "Parsed path "<< parsedPath;
        }else if( res[0] == "RTM_DELETE:" ){
            m_parsedPath = "got_message_rtm_delete";
            //qDebug() << "Parsed path "<< parsedPath;
            if( monOut.contains("GATEWAY") ){
                m_parsedPath = "got_message_rtm_delete_gateway";
                //qDebug() << "Parsed path "<< parsedPath;
            }
        }else if( res[0] == "RTM_ADD:" ){
            m_parsedPath = "got_message_rtm_add";
            //qDebug() << "Parsed path "<< parsedPath;
            if( monOut.contains("GATEWAY") ){
                m_parsedPath = "got_message_rtm_add_gateway";
                //qDebug() << "Parsed path "<< parsedPath;
            }else if (monOut.contains("HOST")){
                m_parsedPath = "got_message_rtm_add_route";
                //qDebug() << "Parsed path "<< parsedPath;
            }
        }else if( res[0].left(4) == "RTM_"){
            m_parsedPath = "rtm_smth";
            //qDebug() << "Parsed path "<< parsedPath;
        }else
            qWarning() << "Unknown message ";

    }else if( m_parsedPath == "got_message_rtm_add_gateway") {  /// RTM_ADD_GATEWAY
        if ( res[0] == "sockaddrs:" ){
            m_parsedPath = "got_message_rtm_add_gateway_sockaddr";
            //qDebug() << "Parsed path "<< parsedPath;
            if( res[1].contains("GATEWAY") ){
                m_parsedPath = "got_message_rtm_add_gateway_sockaddr_gateway";
                //qDebug() << "Parsed path "<< parsedPath;
            }
        }
    }else if( m_parsedPath == "got_message_rtm_add_route") {  /// RTM_ADD_GATEWAY
        if ( res[0] == "sockaddrs:" ){
            m_parsedPath = "got_message_rtm_add_route_sockaddr";
            //qDebug() << "Parsed path "<< parsedPath;
            if( res[1].contains("GATEWAY") ){
                m_parsedPath = "got_message_rtm_add_route_sockaddr_gateway";
                //qDebug() << "Parsed path "<< parsedPath;
            }
        }
    }else if( m_parsedPath == "got_message_rtm_add_gateway_sockaddr_gateway"){ /// RTM_ADD_GATEWAY  sockaddr
        if( res[0] == ""){
            if( res[1] == "default" ){
                qInfo()<< "add default gateway "<<res[2];
                if ( res[2] == m_tunnelGateway )
                    emit sigTunGatewayDefined();
                else
                    emit sigOtherGatewayDefined(res[2]);
            }else if (res[1] == m_serverAddress ){
                qDebug() << "add upstream gateway, res = "<< res;
            }
        }
    }else if( m_parsedPath == "got_message_rtm_add_route_sockaddr_gateway"){ /// RTM_ADD_GATEWAY  sockaddr
        if( res[0] == ""){
            if( res[1] == m_tunnelGateway)
                if ( res[2] == m_tunnelDestination ){
                    qInfo() << "Upstream route is defined";
                    emit sigUpstreamRouteDefined();
                }
        }
    }else if ( m_parsedPath == "got_message_rtm_delete" ) { /// RTM_DELETE  for single route records
        if ( res[0] == "sockaddrs:" ){
            m_parsedPath = "got_message_rtm_delete_sockaddr";
            //qDebug() << "Parsed path "<< parsedPath;
            if( res[1].contains("GATEWAY") && res[1].contains("DST") ){
                m_parsedPath = "got_message_rtm_delete_sockaddr_gateway";
                //qDebug() << "Parsed path "<< parsedPath;
            }
        }

    } else if( m_parsedPath == "got_message_rtm_delete_gateway") {  /// RTM_DEL_GATEWAY
        if ( res[0] == "sockaddrs:" ){
            m_parsedPath = "got_message_rtm_delete_gateway_sockaddr";
            //qDebug() << "Parsed path "<< parsedPath;
            if( res[1].contains("GATEWAY") && res[1].contains("DST")  ){
                m_parsedPath = "got_message_rtm_delete_gateway_sockaddr_gateway";
                //qDebug() << "Parsed path "<< parsedPath;
            }
        }
    }else if( m_parsedPath == "got_message_rtm_delete_sockaddr_gateway"){ /// RTM_DEL sockaddr gateway
        if( res[0] == ""){
            if( res[1] == m_tunnelGateway && res[2] == m_tunnelDestination ){
                qInfo() << "delete route  " << res[1] << " to " << res[2];
                emit sigUpstreamRouteUndefined();
            }
        }
    }else if( m_parsedPath == "got_message_rtm_delete_gateway_sockaddr_gateway"){ /// RTM_DEL_GATEWAY  sockaddr gateway
        if( res[0] == ""){
            //qInfo()<< "delete gateway "<<res[2];
            if( res[1] == "default" ){
                qInfo()<< "delete default gateway "<<res[2];
                if ( res[2] == m_tunnelGateway ){
                    emit sigTunGatewayUndefined();
                    emit instance()->sigInterfaceUndefined();
                }
                else if(isOtherGatewayDefined() && !isOtherGatewayDefinedInnerCheck()){
                    emit sigOtherGatewayUndefined();
                    emit instance()->sigInterfaceUndefined();
                }
            }
        }
    }

}

/**
 * @brief SapNetworkMonitorDarwin::isOtherGatewayDefined
 * @return
 */
bool DapNetworkMonitorDarwin::isOtherGatewayDefinedInnerCheck() const
{
    int ret;
    if(m_tunnelGateway.size()>0){
        ret =  ::system(QString("netstat -nr |grep default | grep --invert-match '%1' > /dev/null").arg(m_tunnelGateway)
                        .toLatin1().constData());
        if( ret!= 0){
            qDebug() << "[-] No default gateway, checking direct route to upstream";
            ret =  ::system(QString("netstat -nr |grep '%1' | grep '%2' > /dev/null")
                            .arg(m_serverAddress).arg(m_defaultGateway)
                            .toLatin1().constData());
            if(ret==0){
                qDebug() << "[+] Direct route to "<< m_serverAddress <<" is present, checking if its actual";
                ret =  ::system(QString("netstat -nr | awk '{print $1;}' |egrep '%1'$ > /dev/null").arg(m_defaultGateway)
                                .toLatin1().constData());
                if(ret==0){
                    qDebug() << "[+] Route to "<< m_defaultGateway <<" is present";
                }else{
                    qDebug() << "[-] No route to "<< m_defaultGateway <<" in the routing table";
                }
            }else
                qDebug() << "[-] No direct route to "<< m_serverAddress <<" in the routing table";
        }

    }else
        ret =  ::system(QString("netstat -nr |grep default > /dev/null").toLatin1().constData());

    if(ret == 0 ){
        qInfo() << "[+] Others gateway defined";
        return true;
    }else{
        qInfo() << "[-] Others gateway undefined";
        return false;
    }
}

/**
 * @brief SapNetworkMonitorDarwin::isTunGatewayDefined
 * @return
 */
bool DapNetworkMonitorDarwin::isTunGatewayDefinedInnerCheck() const
{
    int ret;
    if(m_tunnelGateway.size()>0)
        ret =  ::system(QString("netstat -nr |grep default | grep %1 > /dev/null ").arg(m_tunnelGateway)
                        .toLatin1().constData());
    else
        ret =  ::system(QString("netstat -nr |grep default > /dev/null").toLatin1().constData());

    if(ret == 0 ){
        qInfo() << "[+] Tunnel gateway defined";
        return true;
    }else{
        qInfo() << "[-] Tunnel gateway undefined";
        return false;
    }

}

