#pragma once

#define RESTCLIENT_VERSION "DBJ_RESTCLIENT"

#include "curl7.64.1/include/curl/curl.h"
#include "connection.h"
#include "helpers.h"
#include "restclient.h"

#ifdef _WIN64
#pragma comment(lib, "curlcpp/curl7.64.1/AMD64/libcurl.lib")
#elif defined(WIN32)
#pragma comment(lib, "curlcpp/curl7.64.1/x86/libcurl.lib")
#else
#error Only Win32 or Win64 please
#endif

// sadly to match the dll to the build there is no more feasible
// solution (in vstudio) but to copy paste by hand
// to the dorectory where the exe is
