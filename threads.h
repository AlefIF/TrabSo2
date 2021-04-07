#ifndef THREADS_H
#define THREADS_H

#include "queue.h"
#include <pthread.h>
#define queue_size 4

pthread_cond_t flag[queue_size];

void create_threads(pthread_t *threads, people_type *arguments);//cria as threads
void *task_threads(void *arguments);
#endif