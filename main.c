#include "queue.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define DEFAULT_RUNS 2

int get_random_number(int max, int min);//gera um número aleatório com base no máximo e mínimo
void init_threads();
void wake_up(position_type *position);
void wait(position_type *position);
void working(position_type *position);
void go_to_queue(position_type *position);

pthread_mutex_t mutex_fila  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_caixa = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t thread_condition[queue_size];

people_type peoples[queue_size] = {
    {0, "Sueli", 0, 0},
    {1, "Paula", 1, 0},
    {2, "Vanda", 2, 0},
    {3, "Maria", 3, 0},
};

int run_times;

position_type *root = NULL;
int is_using = False;//variável de controle para o caixa

int main(int argc, char **argv)
{
    srand(time(NULL));

    
    if(argc < 2)
        run_times = DEFAULT_RUNS;
    else
        run_times = atoi(argv[1]);

    init_threads();
    
    return 0;
}

void *thread(void *args)
{

    people_type *current_people = (people_type *) args;
    position_type *current_position = NULL;

    pthread_cond_init(&thread_condition[current_people->id], NULL);

    sleep(get_random_number(3, 2));
    for(int i = 0; i < run_times; i++)
    {
        current_position = create_position(*current_people);

        pthread_mutex_lock(&mutex_fila);
        root = insert_into_queue(root, current_position);
        printf("%s está na fila do caixa ", current_people->name);
        print_queue(root);

        if(is_using)
        {
            pthread_cond_wait(&thread_condition[current_people->id], &mutex_fila);
        }else{
            is_using = True;
        }
        root = exit_queue(root);
        pthread_mutex_unlock(&mutex_fila);

        printf("%s está sendo atendido(a) ", current_people->name);
        print_queue(root);
        sleep(2);

        if(is_empty_queue(root))
        {
            pthread_mutex_lock(&mutex_fila);
            is_using = False;
            pthread_mutex_unlock(&mutex_fila);
        }else
        {
            // printf("Vou chamar a %s", root->person.name);
            pthread_cond_signal(&thread_condition[root->person.id]);
        }
        

        printf("%s vai para casa ", current_people->name);
        print_queue(root);
        
        sleep(get_random_number(5, 3));
    }
}

int get_random_number(int max, int min)
{
    return rand() % (max-min) + min; 
}

void init_threads()
{
    pthread_t threads[queue_size];
    
    for(int i = 0; i < queue_size; i++)
    {
        if(pthread_create(&threads[i], NULL, thread, &(peoples[i])))
            exit(3);
    }

    for(int i = 0; i < queue_size; i++)
    {
        pthread_join(threads[i], NULL);
    }
}