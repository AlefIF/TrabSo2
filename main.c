#include "queue.h"
#include "threads.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

people_type peoples[queue_size] = {
    {0, "Sueli", 0, 0},
    {1, "Paula", 1, 0},
    {2, "Vanda", 2, 0},
    {3, "Maria", 3, 0},
};

int get_random_number(int max, int min);//gera um número aleatório com base no máximo e mínimo

int main(int argc, char **argv)
{
    srand(time(NULL));
   
    printf("Iniciando  \n");
    position_type *root = create_position(&peoples[0]);
    position_type *new_position = create_position(&peoples[1]);
    position_type *new_position2 = create_position(&peoples[2]);
    position_type *new_position3 = create_position(&peoples[3]);

    root = insert_into_queue(root, new_position);
    root = insert_into_queue(root, new_position2);
    root = insert_into_queue(root, new_position3);

    for(int i = 0; i < 15; i++)
    {
        printf("%d\n", get_random_number(5, 3));
    }
    
    return 0;
}

void thread(position_type *root, int person_id)
{
    int qnt_runs = 2;

    for(int i = 0; i < qnt_runs; i++)
    {
        //sleep(random) -> esperar um tempo aleatório até entrar na fila
        //lock_mutex
        position_type *person = create_position(&peoples[person_id]);
        root = insert_into_queue(root, person);

        //retiraria a pessoa da fila
        //desblock mutex
        //sleep()
    }

}

int get_random_number(int max, int min)
{
    return rand() % (max-min) + min; 
}