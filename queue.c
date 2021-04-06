#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


//Inicializa a fila vazia
position_type *create_position(people_type *person)
{
    position_type *position = malloc(sizeof(position_type));

    position->person = person;
    position->next = NULL;
    position->position_number = 0;

    return position;
}

//adiciona uma pessoa na fila de acordo com a sua prioridade
position_type *insert_into_queue(position_type *root, position_type *new_position)
{
    position_type *insert_position = get_insert_position(root, new_position->person->priority);

    if(insert_position == NULL)
    {
        insert_position = new_position;
        insert_position->next = root;
        root = insert_position; /*  MODIFICAR  */
    }else
    if(insert_position->next == NULL)
    {
        insert_position->next = new_position;
        
    }else
    {
        position_type *moved_position = insert_position->next;
        insert_position->next = new_position;
        new_position->next = moved_position;
    }

    setting_old(new_position);
    return root;
}

//envelhece todas as pessoas de menor prioridade que a pessoa indicada
void setting_old(position_type *inserted_position)
{
    //while da posição inserida até o final
    //envelhece todas as pessoas que aparecerem
    position_type *current_position = inserted_position;

    while(current_position->next != NULL)
    {
        current_position = current_position->next;

        if(current_position->person->current_aging == 2)
        {
            current_position->person->priority++;
            current_position->person->current_aging = 0;
        }else
        {
            current_position->person->current_aging++;
        }
    }
}

void exit_queue()
{
    //muda o nó raiz da fila para o próximo
    //caso seja o final, chama a função de desalocar da fila


}

void clean_people()
{
    //desaloca o espaço de memória da pessoa
    //destoi a thread


}

void print_queue(position_type *root)
{
    //percorre todas as posições da fila e printa
    if(is_empty_queue(root))
    {
        printf("A fila está vazia\n");
        return;
    }

    position_type *position = root;

    do
    {
        printf("%s está na fila, priority: %d\n", position->person->name, position->person->priority);

        if(position->next != NULL)
            position = position->next;

    }while(position->next != NULL);

}


//verifica se o primeiro elemento é nulo
int is_empty_queue(position_type *root)
{
    if(root->person == NULL)
        return True;

    return False;
}

//busca a posição onde será inserido o próximo elemento
position_type *get_insert_position(position_type *root, int priority)
{
    if(is_empty_queue(root))
    {
        printf("A fila está vazia\n");
        return NULL;
    }

    position_type *aux = root;
    position_type *previous_aux = NULL;

    do
    {
        if(aux->person->priority < priority)
            return previous_aux;

        if(aux->person->priority >= priority)
            previous_aux = aux;
        
        if(aux->next != NULL)
            aux = aux->next;

    } while (aux->next != NULL);
    
    return previous_aux;
}