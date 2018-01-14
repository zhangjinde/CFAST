/****************************************************
 * Copyright (c) 2018, tkorays <tkorays@hotmail.com>
 * All rights reserved.
 * 
 * @file    cf_file_if.h
 * @brief   File operations.
 * @version 1.0
 * @author  tkorays<tkorays@hotmail.com>
 * @date    2018-1-14
 ****************************************************/
#ifndef __CF_FILE_IF_H__
#define __CF_FILE_IF_H__

#include "cfast/cf_file_if.h"

typedef enum {
    CF_FILE_TYPE_NOT_DEF = 0,
    CF_FILE_TYPE_REGULAR,
    CF_FILE_TYPE_DIR,
    CF_FILE_TYPE_CHAR,
    CF_FILE_TYPE_BLOCK,
    CF_FILE_TYPE_PIPE,
    CF_FILE_TYPE_LINK,
    CF_FILE_TYPE_SOCK,
    CF_FILE_TYPE_UNKNOWN
} cf_filetype_t;


typedef struct cf_file_s cf_file_t;
typedef struct cf_file_dir_s cf_file_dir_t;
typedef struct cf_file_dirent_s cf_file_dirent_t;


cf_file_t*  cf_file_open(const cf_char_t* filename, const cf_char_t* mode);
cf_errno_t  cf_file_close(cf_file_t* f);
cf_size_t   cf_file_write(cf_file_t* f, cf_char_t* buff, cf_size_t size, cf_size_t cnt);
cf_size_t   cf_file_read(cf_file_t* f, cf_char_t* buff, cf_size_t size, cf_size_t cnt);

cf_file_dir_t*  cf_file_opendir(const cf_char_t* path);
cf_errno_t  cf_file_closedir(cf_file_dir_t* dir);
cf_file_dirent_t* cf_file_readdir(cf_file_dir_t* dir);

cf_bool_t   cf_file_exist(const cf_char_t* filename);
cf_errno_t  cf_file_rmdir(const cf_char_t* dirname);
cf_errno_t  cf_file_remove(const cf_char_t* filename);
cf_errno_t  cf_file_copyto(const cf_char_t* src, const cf_char_t* dst);
cf_errno_t  cf_file_move(const cf_char_t* src, const cf_char_t* dst);

cf_errno_t  cf_file_get_extension(const cf_char_t* path, cf_char_t* buf, cf_size_t size);
cf_errno_t  cf_file_get_basedir(const cf_char_t* path, cf_char_t* buf, cf_size_t size);
cf_errno_t  cf_file_path_join(cf_char_t* buff, cf_size_t size, const cf_char_t* p1, const cf_char_t* p2);

#endif /* __CF_FILE_IF_H__ */