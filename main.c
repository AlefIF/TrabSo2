#include "queue.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define DEFAULT_RUNS 10

int get_random_number(int max, int min);//gera um número aleatório com base no máximo e mínimo
void init_threads();
void wake_up(position_type *position);

pthread_mutex_t mutex_fila  = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t thread_condition[queue_size];

people_type peoples[queue_size] = {
    {0, "Sueli", 0, 0},
    {1, "Paula", 1, 0},
    {2, "Vanda", 2, 0},
    {3, "Maria", 3, 0},
};

position_type *root = NULL;
int run_times;
int is_using = 0;//variável de controle para o caixa

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

    pthread_cond_init(&(thread_condition[current_people->id]), NULL);

    //sleep(random) -> esperar um tempo aleatório até entrar na fila
    sleep(get_random_number(3, 2));//sleepa entre 1 e 3 segundos
    for(int i = 0; i < run_times; i++)
    {   
        current_position = create_position(*current_people);
        //se o caixa estiver em uso, entramos na fila e esperamos o signal do caixa
        //para continuarmos
        //Bloqueia a fila para que não haja concorrência entre as threads
        pthread_mutex_lock(&mutex_fila);
        if(is_using)
        {
            //desbloqueia a mutex
            //insere na fila  printa
            root = insert_into_queue(root, current_position);
            printf("%s entrou na fila ",current_people->name);
            print_queue(root);
            //Espera um signal para voltar a executar
            pthread_cond_wait(&thread_condition[current_people->id], &mutex_fila);
            pthread_mutex_unlock(&mutex_fila);
        }else
        {
            is_using = True;
            pthread_mutex_unlock(&mutex_fila);
        }

        printf("%s está em atendimento ", current_people->name);
        print_queue(root);
        sleep(2);

        pthread_mutex_lock(&mutex_fila);
        root = exit_queue(root);//saimos da fila
        if(is_empty_queue(root))
            is_using = False;
        else
        {
            printf("%s\n", root->person.name);
            wake_up(root);
        }

        printf("%s foi para casa\n", current_people->name);
        pthread_mutex_unlock(&mutex_fila);

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

        //Se as threads funcionar, testar o join aki
        // pthread_join(threads[i], NULL);
    }

    for(int i = 0; i < queue_size; i++)
    {
        pthread_join(threads[i], NULL);
    }
}

void wake_up(position_type *position)
{
    pthread_cond_signal(&thread_condition[position->person.id]);
}