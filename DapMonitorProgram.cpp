#include "DapMonitorProgram.h"

DapMonitorProgram::DapMonitorProgram(const QString& name,
                                     const QStringList& args,
                                     QObject *parent)
    : QObject(parent), m_name(name), m_args(args)
{

}

void DapMonitorProgram::sltProcessFinished()
{
    qDebug() << "sltProcessFinished";
    m_isRunning = false;
    m_process->deleteLater();
}

void DapMonitorProgram::sltMonitorParser()
{
    while (!m_process->atEnd()) {
        qint64 count_bytes = m_process->readLine(m_outputBuffer, MAX_LINE_LENGTH);
        if(count_bytes == 0) {
            qWarning() << "Read 0 bytes";
            continue;
        }
        if(count_bytes == -1) {
            qWarning() << "Error read line";
            break;
        }
        // qDebug() << "monitoring proces out:" << m_outputBuffer;
        sigProgramOutput(m_outputBuffer);
    }
}

void DapMonitorProgram::start()
{
    if(m_isRunning) {
        qWarning() << "Can't start monitoring. He is already started";
        return;
    }
    m_process = new QProcess(this);

    connect(m_process,static_cast<void (QProcess::*)(int)>(&QProcess::finished),
            this, &DapMonitorProgram::sltProcessFinished);

    connect(m_process, &QProcess::errorOccurred, [=](QProcess::ProcessError error) {
        qCritical() << "Monitoring process: " << error;
        if(error == QProcess::ProcessError::FailedToStart) {
            emit sigStartError();
            sltProcessFinished();
        }
    });

    connect(m_process, &QProcess::readyRead, this, &DapMonitorProgram::sltMonitorParser);

    connect(m_process, &QProcess::started, [=] {
        qInfo() << "Started process network monitor";
        m_isRunning = true;
    });

    m_process->start(m_name, m_args);
}

void DapMonitorProgram::stop()
{
    m_process->kill();
}
