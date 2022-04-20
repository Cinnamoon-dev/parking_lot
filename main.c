#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 10

// Vars para servidores
char codes_servs[TAM][20]; // campo obrigatório
char nomes[TAM][255]; // campo obrigatório
char SIAPEs[TAM][20]; // nao pode repetir
char RGs[TAM][20]; // obrigatorio
char CPFs[TAM][20]; // não pode repetir
char enderecos[TAM][255]; // nao pode repetir
char salarios[TAM][20]; // nao pode repetir
char datas[TAM][20]; //obrigatorio
char tipos[TAM][30]; // obrigatorio
char ocupados[TAM]; // Diz qual espaço da lista está vazio

// Vars para veículos
char codes_cars[TAM]; // obrigatorio
// codes_servs[TAM]; // de novo
char descs[TAM][255]; // obrigatorio
char placas[TAM][20]; // obrigatorio
char marcas[TAM][20]; // obrigatorio
char modelos[TAM][20]; // obrigatorio

void lower_case(char str[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        str[i] = tolower(str[i]);
    }
}


void iniciar() // Diz que todos os lugares na lista estao desocupados
{
    for (int i = 0; i < TAM; ++i) {
        ocupados[i] = 0;
    }
}

void input(char str[], int tam, char *msg) // Pega o input do usuario, limpa o buffer, tira o \n do final caso tenha e printa uma pergunta na tela
{
    printf("%s", msg);
    fgets(str, tam, stdin);
    fflush(stdin);

    size_t ln = strlen(str) - 1;
    if (str[ln] == '\n')
        str[ln] = '\0';
}

void exclude_serv() // Exclui os servidores por CPF
{
    char code[10];
    input(code, 10, "Digite o codigo para excluir o servidor:");
    int index = -1;
    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(codes_servs[i], code) == 0)
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

    char codigo[20];
    char nome[255];
    char SIAPE[20];
    char CPF[20];
    char RG[20];
    char endereco[255];
    char salario[20];
    char data[20];
    char tipo[30];

    input(codigo, 10, "codigo:");
    input(nome, 255, "nome:");
    input(SIAPE, 20, "SIAPE:");
    input(CPF, 20, "CPF:");
    input(RG, 20, "RG:");
    input(endereco, 255, "endereco:");
    input(salario, 20, "salario:");
    input(data, 20, "data de nascimento:");
    input(tipo, 20, "tipo:");
    printf("\n");

    lower_case(codigo, 20);
    lower_case(nome, 255);
    lower_case(SIAPE, 20);
    lower_case(CPF, 20);
    lower_case(RG, 20);
    lower_case(endereco, 255);
    lower_case(salario, 20);
    lower_case(data, 20);
    lower_case(tipo, 20);

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
            printf("\n#%s\n#%s\n#%s\n#%s\n#%s\n#%s\n#%s\n#%s\n#%s\n",codes_servs[i], nomes[i], SIAPEs[i], RGs[i], CPFs[i], enderecos[i], salarios[i], datas[i], tipos[i]);
        }
    }
    printf("##################################\n\n");
}

void list_code()
{
    char code[10];
    input(code, 10, "Digite o codigo do servidor para listar:");
    for(int i = 0; i < TAM; i++)
    {
        if(strcmp(codes_servs[i], code) == 0)
        {
            printf("\n#%s\n#%s\n#%s\n#%s\n#%s\n#%s\n#%s\n#%s\n#%s\n",codes_servs[i], nomes[i], SIAPEs[i], RGs[i], CPFs[i], enderecos[i], salarios[i], datas[i], tipos[i]);
        }
    }
}

void edit_serv() //Edição de servidor por código, vai ser alterado tudo menos o código
{
    int index = -1;
    char code[10];
    input(code, 10, "Digite o codigo do servidor para edição:");
    for(int i = 0; i < TAM; i++)
    {
        index = i;
        if(strcmp(codes_servs[i], code) == 0)
        {
            char nome[255];
            char SIAPE[20];
            char CPF[13];
            char RG[13];
            char endereco[255];
            char salario[10];
            char data[11];
            char tipo[25];

            input(nome, 255, "nome:");
            input(SIAPE, 20, "SIAPE:");
            input(CPF, 13, "CPF:");
            input(RG, 13, "RG:");
            input(endereco, 255, "endereco:");
            input(salario, 10, "salario:");
            input(data, 11, "data de nascimento:");
            input(tipo, 20, "tipo:");
            printf("\n");

            strcpy(nomes[index], nome);
            strcpy(SIAPEs[index], SIAPE);
            strcpy(CPFs[index] , CPF);
            strcpy(RGs[index], RG);
            strcpy(enderecos[index], endereco);
            strcpy(salarios[index], salario);
            strcpy(datas[index], data);
            strcpy(tipos[index], tipo);
            break;
        }
    }
}

int main()
{
    iniciar();

    insert_serv();

    list();

    insert_serv();

    list();

    list_code();

    edit_serv();

    list();

    exclude_serv();

    list();

    return 0;
}