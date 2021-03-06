#ifndef __CF_THREAD_H__
#define __CF_THREAD_H__

#include <cf/types.h>
#ifdef CF_OS_WIN
#include <Windows.h>
#else
#include <pthread.h>
#endif

CF_DECLS_BEGIN

#ifdef CF_OS_WIN
#define CF_THREAD_DEF_PROC(name, arg) cf_uint32_t WINAPI name(cf_void_t* arg)
#define CF_THREAD_RET(ret) ((cf_uint32_t)(ret))
typedef HANDLE cf_thread_t;
typedef SECURITY_ATTRIBUTES cf_thread_attr_t;
typedef cf_uint32_t(WINAPI *cf_thread_proc_t)(cf_void_t*);
#else
#define CF_THREAD_DEF_PROC(name, arg) cf_void_t* name(cf_void_t* arg)
#define CF_THREAD_RET(ret) ((cf_void_t*)(ret))
typedef pthread_t cf_thread_t;
typedef pthread_attr_t cf_thread_attr_t;
typedef cf_void_t*(*cf_thread_proc_t)(cf_void_t*);
#endif

cf_errno_t cf_thread_create(cf_thread_t* t, cf_thread_attr_t* attr,
    cf_thread_proc_t proc, cf_void_t* arg);
cf_void_t cf_thread_exit(cf_uint32_t code);
cf_errno_t cf_thread_join(cf_thread_t t, cf_uint32_t* retval);
cf_errno_t cf_thread_detach(cf_thread_t t);
cf_errno_t cf_thread_cancel(cf_thread_t t);
cf_bool_t cf_thread_equal(cf_thread_t t1, cf_thread_t t2);
cf_thread_t cf_thread_self();
cf_errno_t cf_thread_attr_init(cf_thread_attr_t* attr);
cf_errno_t cf_thread_attr_destroy(cf_thread_attr_t* attr);

cf_uint_t cf_getpid();
cf_uint_t cf_gettid();

CF_DECLS_END

#endif /* __CF_THREAD_H__ */
