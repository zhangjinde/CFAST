/**********************************************
 * Copyright (c) 2018, tkorays
 * All rights reserved.
 * 
 * @file    cf_log_if.h
 * @brief   CFAST的日志模块对外接口
 * @version 1.0
 * @author  tkorays<tkorays@hotmail.com>
 * @date    2018-1-3
 *********************************************/
#ifndef __CF_LOG_IF_H__
#define __CF_LOG_IF_H__

#include "cf_def.h"

typedef enum {
    CF_LOG_LEVEL_DEBUG      = 0x0001,
    CF_LOG_LEVEL_INFO       = 0x0002,
    CF_LOG_LEVEL_WARNING    = 0x0004,
    CF_LOG_LEVEL_ERROR      = 0x0008,
    CF_LOG_LEVEL_FATAL      = 0x0010
} cf_log_level_t;

typedef struct cf_log_s cf_log_t;

#define CF_LOG(level, fmtstr, ...)  cf_log_put(__FILE__, __LINE__, level, fmtstr, __VA_ARGS__)
#define CF_LOG_DEBUG(fmtstr, ...)   CF_LOG(CF_LOG_LEVEL_DEBUG, fmtstr, __VA_ARGS__)
#define CF_LOG_INFO(fmtstr, ...)    CF_LOG(CF_LOG_LEVEL_INFO, fmtstr, __VA_ARGS__)
#define CF_LOG_WARNING(fmtstr, ...) CF_LOG(CF_LOG_LEVEL_WARNING, fmtstr, __VA_ARGS__)
#define CF_LOG_ERROR(fmtstr, ...)   CF_LOG(CF_LOG_LEVEL_ERROR, fmtstr, __VA_ARGS__)
#define CF_LOG_FATAL(fmtstr, ...)   CF_LOG(CF_LOG_LEVEL_FATAL, fmtstr, __VA_ARGS__)

cf_log_t*   cf_log_create(const cf_char_t* filename);
cf_void_t   cf_log_destroy(cf_log_t* log);
cf_void_t   cf_log_set();
cf_void_t   cf_log_put(const cf_char_t* filename, const cf_char_t* line, cf_log_level_t level, const cf_char_t* fmtstr, ...);

#endif /* __CF_LOG_IF_H__ */
