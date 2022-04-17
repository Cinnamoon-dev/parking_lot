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
char codes_cars[TAM]; // obrigatorio
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

void input(char str[], int tam) // Pega o input do usuario, limpa o buffer e tira o \n do final caso tenha
{
    fgets(str, tam, stdin);
    fflush(stdin);

    size_t ln = strlen(str) - 1;
    if (str[ln] == '\n')
        str[ln] = '\0';
}

void exclude_serv() // Exclui os servidores por CPF
{
    char cpf[13];
    printf("Digite o codigo do servidor:");
    input(cpf, 13);
    int index = -1;
    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(codes_servs[i], cpf) == 0)
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
    input(codigo, 10);
    printf("nome:");
    input(nome, 255);
    printf("SIAPE:");
    input(SIAPE, 20);
    printf("CPF:");
    input(CPF, 13);
    printf("RG:");
    input(RG, 13);
    printf("endereco:");
    input(endereco, 255);
    printf("salario:");
    input(salario, 10);
    printf("data de nascimento:");
    input(data, 11);
    printf("tipo:");
    input(tipo, 20);
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
            printf("#%s\n#%s\n#%s\n#%s\n#%s\n#%s\n#%s\n#%s\n#%s\n",codes_servs[i], nomes[i], SIAPEs[i], RGs[i], CPFs[i], enderecos[i], salarios[i], datas[i], tipos[i]);
        }
    }
    printf("##################################\n\n");

}

int main()
{
    iniciar();

    insert_serv();

    list();

    exclude_serv();

    list();

    return 0;
}