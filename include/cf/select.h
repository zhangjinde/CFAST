/****************************************************
 * Copyright (c) 2018, tkorays <tkorays@hotmail.com>
 * All rights reserved.
 * 
 * @file    select.h
 * @brief   Select for linux/windows.
 * @version 1.0
 * @author  tkorays<tkorays@hotmail.com>
 * @date    2018-2-28
 ****************************************************/
#ifndef __CF_SELECT_H__
#define __CF_SELECT_H__

#include <cf/types.h>
#include <cf/time.h>

#ifdef CF_OS_WIN

#else
#include <sys/select.h>
#endif

CF_DECLS_BEGIN

/**
 * FD_SETSIZE
 */
extern const cf_size_t CF_FD_SETSIZE;

/**
 * fd_set
 */
typedef struct fd_set cf_fdset_t;

typedef struct timeval timeval;

CF_DECLARE(cf_void_t) cf_fd_zero(cf_fdset_t* fdset);
CF_DECLARE(cf_void_t) cf_fd_set(cf_int_t fd, cf_fdset_t* fdset);
CF_DECLARE(cf_void_t) cf_fd_clr(cf_int_t fd, cf_fdset_t* fdset);
CF_DECLARE(cf_bool_t) cf_fd_isset(cf_int_t fd, cf_fdset_t* fdset);
CF_DECLARE(cf_errno_t) cf_select(int maxfdp, cf_fdset_t* rfds, cf_fdset_t* wfds, cf_fdset_t* efds, cf_timeval_t* timeout);

CF_DECLS_END

#endif /* __CF_SELECT_H__ */
