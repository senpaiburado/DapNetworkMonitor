#ifndef DAPMONITORPROGRAM_H
#define DAPMONITORPROGRAM_H

#include <QDebug>
#include <QProcess>

class DapMonitorProgram : public QObject
{
    Q_OBJECT
private:
    static const size_t MAX_LINE_LENGTH = 512;

    QString m_name;
    QStringList m_args;
    QProcess* m_process;

    bool m_isRunning = false;
    char m_outputBuffer[MAX_LINE_LENGTH];
public:
    explicit DapMonitorProgram(const QString& name, const QStringList& args, QObject *parent = nullptr);

    bool isProgramRunning() { return m_isRunning; }
signals:
    // split output console program by lines
    void sigProgramOutput(QString line);

    void sigStarted();
    void sigFinished();
    void sigStartError();
private slots:
    void sltProcessFinished();
    void sltMonitorParser();
public slots:
    void start();
    void stop();
};

#endif // DAPMONITORPROGRAM_H
