#include <stdio.h>
#include <stdlib.h>
#include "pessoas.h"


tipo_fila *inicializar_fila()
{
    tipo_fila *fila = malloc(sizeof(tipo_fila));

    fila->current = NULL;
    fila->proximo = NULL;

    return fila;
}

void adicionar_fila()
{
    //while até a posição de chegada da pessoa
    //interceptamos o ponteiro próximo
    //vinculamos na pessoa a ser inserida
    //vinculados o próximo da pessoa inserida, na outra pessoa
    //chama a funcão de envelhecimento

   // pessoa   -> pessoa4 ->  pessoa2   -> pessoa3


}

void envelhecer_posteriores()
{
    //while da posição inserida até o final
    //envelhece todas as pessoas que aparecerem



}

void sair_fila()
{
    //muda o nó raiz da fila para o próximo
    //caso seja o final, chama a função de desalocar da fila


}

void desaloca_pessoa()
{
    //desaloca o espaço de memória da pessoa
    //destoi a thread


}


void imprime_fila()
{
    //percorre todas as posições da fila e printa



}


void is_fila_vazia()
{
    //verifica se o primeiro elemento é nulo


}