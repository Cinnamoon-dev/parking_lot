#include <stdio.h>
#include <string.h>
#define TAM 10

// Vars para servidores
int codes_servs[TAM]; // campo obrigatório
char nomes[TAM][255]; // campo obrigatório
char SIAPEs[TAM][20]; // nao pode repetir
char RGs[TAM][11]; // obrigatorio
char CPFs[TAM][20]; // não pode repetir
char enderecos[TAM][255]; // nao pode repetir
char salarios[TAM][10]; // nao pode repetir
char datas[TAM][10]; //obrigatorio
char tipos[TAM][20]; // obrigatorio
char ocupados[TAM]; // Diz qual espaço da lista está vazio

// Vars para veículos
int codes_cars[TAM]; // obrigatorio
// codes_servs[TAM]; // de novo
char descs[TAM][255]; // obrigatorio
char placas[TAM][8]; // obrigatorio
char marcas[TAM][20]; // obrigatorio
char modelos[TAM][20]; // obrigatorio

void iniciar() // Diz que todos os lugares na lista estao desocupados
{
    for (int i = 0; i < TAM; ++i) {
        ocupados[i] = 0;
    }
}

void insert_serv(int codigo, char nome[], char SIAPE[], char CPF[], char RG[], char endereco[], char salario[], char data[], char tipo[])
{
    int index = -1;
    for (int i = 0; i < TAM; ++i)
    {
        if(ocupados[i] == 0 ){
            index = i;
            break;
        }
    }

    codes_servs[index] = codigo;
    strcpy(nomes[index], nome);
    strcpy(SIAPEs[index], SIAPE);
    strcpy(CPFs[index] , CPF);
    strcpy(RGs[index], RG);
    strcpy(enderecos[index], endereco);
    strcpy(salarios[index], salario);
    strcpy(datas[index], data);
    strcpy(tipos[index], tipo);
    ocupados[index] = 1;
}

void list()
{
    printf("############ LISTAGEM ############\n");

    for (int i = 0; i < TAM; ++i)
    {
        if(ocupados[i] == 1 ){
            printf("%d\t%s\t %s\t%s\t%s\t%s\t%s\t%s\t%s\n",codes_servs[i], nomes[i], SIAPEs[i], RGs[i], CPFs[i], enderecos[i], salarios[i], datas[i], tipos[i]);
        }
    }
    printf("##################################\n\n");

}

int main()
{
    iniciar();

    insert_serv(1,"Pedro", "1000", "60618863303", "20076005644", "Av. Paulista, 143", "R$1000,00", "03/05/2003", "docente");
    list();

    return 0;
}