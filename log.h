#ifndef LOG_H
#define LOG_H


#ifdef ESP8266

#include "espressif/esp_common.h"
#define log(line, ...) printf(line)
#else
#include <cstdio>
#define log(line, ...) fprintf(stderr, line, ## __VA_ARGS__ )
#endif

#endif // LOG_H
