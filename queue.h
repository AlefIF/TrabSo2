#ifndef QUEUE_H
#define QUEUE_H


#define name_size 10
#define queue_size 4


#define True 1
#define False 0
// #include <time.h>
// #define random srand(time(NULL));rand() % 2 + 3;

typedef struct
{

    int id;
    char name[name_size];
    int priority;
    int current_aging;

} people_type;

typedef struct PositionType
{
    people_type *person;
    int position_number;

    struct PositionType *next;

} position_type;


int is_empty_queue(position_type *root);//verifica se a fila está vazia ou não
position_type *create_position(people_type *person);//Cria uma nova posição da fila (Não insere na fila)
void setting_old(position_type *inserted_position);
position_type *get_insert_position(position_type *root, int priority);//busca a posição a inserir o próximo elemento
position_type *insert_into_queue(position_type *root, position_type *new_position);
void print_queue(position_type *root);//printa toda a fila
void exit_queue();
void clean_people();



#endif