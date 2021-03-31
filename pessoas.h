#define tamanho_nome 10
#define tamanho_fila 4

// #include <time.h>
// #define random srand(time(NULL));rand() % 2 + 3;

typedef struct
{

    int id;
    char nome[tamanho_nome];
    int prioridade;
    int envelhecer;

} tipo_pessoa;

typedef struct TipoFila
{
    tipo_pessoa *current;

    struct TipoFila *proximo;

} tipo_fila;

tipo_pessoa pessoas[tamanho_fila] = {
    {0, "Sueli", 0, 0},
    {1, "Paula", 1, 0},
    {2, "Vanda", 2, 0},
    {3, "Maria", 3, 0},
}