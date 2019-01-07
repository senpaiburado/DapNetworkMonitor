#ifndef DAPNETWORKMONITOR_H
#define DAPNETWORKMONITOR_H

#include <QtGlobal>

#if defined(Q_OS_ANDROID)
#include "DapNetworkMonitorAndroid.h"
typedef class DapNetworkMonitorAndroid DapNetworkMonitor;
#elif defined(Q_OS_LINUX)
#include "DapNetworkMonitorLinux.h"
typedef class DapNetworkMonitorLinux DapNetworkMonitor;
#elif defined(Q_OS_WIN)
#include "DapNetworkMonitorWindows.h"
typedef class DapNetworkMonitorWindows DapNetworkMonitor;
#elif defined(Q_OS_DARWIN)
#include "DapNetworkMonitorDarwin.h"
typedef class DapNetworkMonitorDarwin DapNetworkMonitor;
#endif

#endif // DAPNETWORKMONITOR_H
