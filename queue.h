#ifndef QUEUE_H
#define QUEUE_H

#define name_size 10
#define queue_size 4

#define True 1
#define False 0

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
    int in_queue;

    struct PositionType *next;

} position_type;


position_type *insert_into_queue(position_type *root, position_type *new_position);//insere posição na fila
position_type *get_insert_position(position_type *root, int priority);//busca a posição a inserir o próximo elemento
position_type *create_position(people_type *person);//Cria uma nova posição da fila (Não insere na fila)
position_type *exit_queue(position_type *root);//remove a primeira posição da fila
void setting_old(position_type *inserted_position);//"envelhece" todos as posições posteriores aquela que foi inserida
void print_queue(position_type *root);//printa toda a fila
int is_empty_queue(position_type *root);//verifica se a fila está vazia ou não

#endif