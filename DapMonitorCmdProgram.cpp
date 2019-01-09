#include "DapMonitorCmdProgram.h"

DapMonitorCmdProgram::DapMonitorCmdProgram(const QString& name,
                                     const QStringList& args,
                                     QObject *parent)
    : QObject(parent), m_name(name), m_args(args)
{

}

void DapMonitorCmdProgram::sltProcessFinished()
{
    qDebug() << "sltProcessFinished";
    m_isRunning = false;
    m_process->deleteLater();
    emit sigFinished();
}

void DapMonitorCmdProgram::sltReadProgramOutput()
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

void DapMonitorCmdProgram::start()
{
    if(m_isRunning) {
        qWarning() << "Can't start monitoring. He is already started";
        return;
    }
    m_process = new QProcess(this);

    connect(m_process,static_cast<void (QProcess::*)(int)>(&QProcess::finished),
            this, &DapMonitorCmdProgram::sltProcessFinished);

    connect(m_process, &QProcess::errorOccurred, [=](QProcess::ProcessError error) {
        qCritical() << "Monitoring process: " << error;
        if(error == QProcess::ProcessError::FailedToStart) {
            emit sigStartError();
            sltProcessFinished();
        }
    });

    connect(m_process, &QProcess::readyRead, this, &DapMonitorCmdProgram::sltReadProgramOutput);

    connect(m_process, &QProcess::started, [=] {
        qInfo() << "Started process network monitor";
        emit sigStarted();
        m_isRunning = true;
    });

    m_process->start(m_name, m_args);
}

void DapMonitorCmdProgram::stop()
{
    m_process->kill();
}
