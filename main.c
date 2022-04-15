#include <stdio.h>
#include <string.h>
#define TAM 10

// Vars para servidores
char codes_servs[TAM][10]; // campo obrigatório
char nomes[TAM][255]; // campo obrigatório
char SIAPEs[TAM][20]; // nao pode repetir
char RGs[TAM][11]; // obrigatorio
char CPFs[TAM][14]; // não pode repetir
char enderecos[TAM][255]; // nao pode repetir
char salarios[TAM][15]; // nao pode repetir
char datas[TAM][11]; //obrigatorio
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

void exclude_serv() // Exclui os servidores por CPF
{
    char CPF[14];
    printf("Digite o CPF do servidor:");
    fgets(CPF, 13, stdin);
    fflush(stdin);
    int index = -1;
    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(CPFs[i], CPF) == 0)
        {
            index = i;
            ocupados[index] = 0;
            break;

        }
    }

}

void insert_serv()
{
    int index = -1;
    for (int i = 0; i < TAM; ++i)
    {
        if(ocupados[i] == 0 ){
            index = i;
            break;
        }
    }

    char codigo[10];
    char nome[255];
    char SIAPE[20];
    char CPF[13];
    char RG[13];
    char endereco[255];
    char salario[10];
    char data[11];
    char tipo[25];

    printf("codigo:");
    fgets(codigo, 10, stdin);
    fflush(stdin);
    printf("nome:");
    fgets(nome, 255, stdin);
    fflush(stdin);
    printf("SIAPE:");
    fgets(SIAPE, 20, stdin);
    fflush(stdin);
    printf("CPF:");
    fgets(CPF, 12, stdin);
    fflush(stdin);
    printf("RG:");
    fgets(RG, 12, stdin);
    fflush(stdin);
    printf("endereco:");
    fgets(endereco, 255, stdin);
    fflush(stdin);
    printf("salario:");
    fgets(salario, 15, stdin);
    fflush(stdin);
    printf("data de nascimento:");
    fgets(data, 11, stdin);
    fflush(stdin);
    printf("tipo:");
    fgets(tipo, 20, stdin);
    fflush(stdin);
    printf("\n");

    strcpy(codes_servs[index], codigo);
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
            printf("%s#\t%s#\t %s#\t%s#\t%s#\t%s#\t%s#\t%s#\t%s#\n",codes_servs[i], nomes[i], SIAPEs[i], RGs[i], CPFs[i], enderecos[i], salarios[i], datas[i], tipos[i]);
        }
    }
    printf("##################################\n\n");

}

int main()
{
    iniciar();

    insert_serv();

    //insert_serv(1,"Pedro", "1000", "60619967130", "70013003622", "Av. Paulista, 143", "R$1000,00", "03/05/2003", "docente");

    //insert_serv(2, "Victor", "1001", "01253287699", "4312674500", "Rua do Congo, 12", "R$2000,00", "14/02/2000", "tec. adm.");

    list();

    exclude_serv();

    list();

    return 0;
}