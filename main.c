#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

people_type peoples[queue_size] = {
    {0, "Sueli", 0, 0},
    {1, "Paula", 1, 0},
    {2, "Vanda", 2, 0},
    {3, "Maria", 3, 0},
};

int main(int argc, char **argv)
{

    position_type *root = create_position(&peoples[0]);

    position_type *new_position = create_position(&peoples[1]);
    root = insert_into_queue(root, new_position);

    print_queue(root);
    return 0;
}