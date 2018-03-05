/****************************************************
 * Copyright (c) 2018, tkorays <tkorays@hotmail.com>
 * All rights reserved.
 * 
 * @file    cli.h
 * @brief   Command line interface.
 * @version 1.0
 * @author  tkorays<tkorays@hotmail.com>
 * @date    2018-1-6
 ****************************************************/
#ifndef __CF_CLI_H__
#define __CF_CLI_H__

#include <cf/types.h>
#include <cf/list.h>

CF_DECLS_BEGIN

/**
 * @defgroup CFAST Command Line Interface
 * @ingroup CF_CLI
 * @{
 *
 * This module provides an interactive Command Line Interface(CLI).
 */

#define CF_CLI_MAX_BUFF 1024
#define CF_CLI_MAX_ARG  32

typedef struct cf_mpool cf_mpool_t;
typedef struct cf_cli cf_cli_t;
typedef cf_errno_t(*cf_cli_cmd_func)(cf_size_t argc, cf_char_t* argv[]);

typedef struct cf_cli_cfg {
    cf_void_t(*output)(cf_char_t*);
} cf_cli_cfg_t;

typedef struct cf_cli_cmd {
    struct cf_cli_cmd*      prev;
    struct cf_cli_cmd*      next;
    struct cf_cli_cmd*      child;

    const cf_char_t*        name;
    const cf_char_t*        desc;
    cf_cli_cmd_func         func; // process function
} cf_cli_cmd_t;

typedef struct cf_cli {
    cf_void_t(*output)(cf_char_t*);
    cf_cli_cmd_t* cmds;
    cf_mpool_t* pool;
} cf_cli_t;

typedef struct cf_cliarg {
    cf_size_t argc;
    cf_char_t** argv;
    cf_char_t* _buff;
} cf_cliarg_t;

CF_DECLARE(cf_errno_t) cf_cli_init(cf_cli_t* cli, cf_cli_cfg_t* cfg);
CF_DECLARE(cf_errno_t) cf_cli_uninit(cf_cli_t* cli);
CF_DECLARE(cf_void_t)  cf_cli_cfg_default(cf_cli_cfg_t* cfg);
CF_DECLARE(cf_errno_t) cf_cli_input(cf_cli_t* cli, cf_size_t argc, cf_char_t* argv[]);
CF_DECLARE(cf_errno_t) cf_cli_register(cf_cli_t* cli, const cf_char_t* cmd, const cf_char_t* desc, cf_cli_cmd_func func);
CF_DECLARE(cf_errno_t) cf_cli_parse_arg(const cf_char_t* s, cf_cliarg_t* arg);
CF_DECLARE(cf_errno_t) cf_cli_destroy_arg(cf_cliarg_t* arg);

/** @} */

CF_DECLS_END

#endif /* __CF_CLI_H__ */
