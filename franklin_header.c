#ifdef USE_GTTHREAD

#include "gtthread.h"

#define thread_t gtthread_t
#define thread_mutex_t gtthread_mutex_t

void thread_init(long period) {

    gtthread_init(period);
}

int thread_create(thread_t *thread,void *(*start_routine)(void *),void *arg) {
    return gtthread_create(thread,start_routine,arg);
}

int thread_join(thread_t thread, void **status) {
    return gtthread_join(thread,status);
}

void thread_exit(void *retval) {
    gtthread_exit(retval);
}

void thread_yield() {
    gtthread_yield();
}

int thread_equal(thread_t t1, thread_t t2) {
    return gtthread_equal(t1, t2);
}
int  thread_cancel(thread_t thread) {
    return gtthread_cancel(thread);
}

thread_t thread_self() {
    return gtthread_self();
}

int  thread_mutex_init(thread_mutex_t *mutex) {
    return gtthread_mutex_init(mutex);
}
int  thread_mutex_lock(thread_mutex_t *mutex) {
    return gtthread_mutex_lock(mutex);
}
int  thread_mutex_unlock(thread_mutex_t *mutex) {
    return gtthread_mutex_unlock(mutex);
}

int  thread_mutex_destroy(thread_mutex_t *mutex) {
    return gtthread_mutex_destroy(mutex);
}

#else

#include <pthread.h>

#define thread_t pthread_t
#define thread_mutex_t pthread_mutex_t

void thread_init(long period) {

   printf("Do nothing with pthread\n");
}

int thread_create(thread_t *thread,void *(*start_routine)(void *),void *arg) {
    return pthread_create(thread,NULL,start_routine,arg);
}

int thread_join(thread_t thread, void **status) {
    return pthread_join(thread,status);
}

void thread_exit(void *retval) {
    pthread_exit(retval);
}

void thread_yield() {
    pthread_yield();
}

int thread_equal(thread_t t1, thread_t t2) {
    return pthread_equal(t1, t2);
}
int  thread_cancel(thread_t thread) {
    return pthread_cancel(thread);
}

thread_t thread_self() {
    return pthread_self();
}

int  thread_mutex_init(thread_mutex_t *mutex) {
    return pthread_mutex_init(mutex,NULL);
}
int  thread_mutex_lock(thread_mutex_t *mutex) {
    return pthread_mutex_lock(mutex);
}
int  thread_mutex_unlock(thread_mutex_t *mutex) {
    return pthread_mutex_unlock(mutex);
}

int  thread_mutex_destroy(thread_mutex_t *mutex) {
    return pthread_mutex_destroy(mutex);
}

#endif
