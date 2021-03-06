/****************************************************
 * Copyright (c) 2018, tkorays <tkorays@hotmail.com>
 * All rights reserved.
 * 
 * @file    msg.h
 * @brief   A message component.
 * @version 1.0
 * @author  tkorays<tkorays@hotmail.com>
 * @date    2018-1-3
 ****************************************************/
#ifndef __CF_MSG_H__
#define __CF_MSG_H__

#include <cf/types.h>

CF_DECLS_BEGIN

cf_errno_t cf_msg_init();
cf_errno_t cf_msg_deinit();

CF_DECLS_END

#endif /* __CF_MSG_H__ */
