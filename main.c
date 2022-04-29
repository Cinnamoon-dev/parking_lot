#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 10

// Vars para servidores
char codes_servs[TAM][20]; // campo obrigatório
char nomes[TAM][255]; // campo obrigatório
char SIAPEs[TAM][20]; // campo obrigatório
char RGs[TAM][20];
char CPFs[TAM][20]; // não pode repetir e campo obrigatório
char enderecos[TAM][255];
char salarios[TAM][20];
char datas[TAM][20]; //campo obrigatório
char tipos[TAM][30];
char ocupados[TAM]; // Diz qual espaço da lista está vazio

// Vars para veículos
char codes_cars[TAM][20]; // obrigatorio
char codes_servs_cars[TAM][20]; // de novo
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

    for (int j = 0; j < TAM; j++) {
        strcpy(codes_servs[j], "-1");
        strcpy(nomes[j], " ");
        strcpy(SIAPEs[j], "-1");
        strcpy(RGs[j], "-1");
        strcpy(CPFs[j], "-1");
        strcpy(enderecos[j], " ");
        strcpy(salarios[j], " ");
        strcpy(datas[j], " ");
        strcpy(tipos[j], " ");
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

    strcpy(codes_servs[index], "-1");
    strcpy(nomes[index], "-1");
    strcpy(SIAPEs[index], "-1");
    strcpy(CPFs[index] , "-1");
    strcpy(RGs[index], "-1");
    strcpy(enderecos[index], "-1");
    strcpy(salarios[index], "-1");
    strcpy(datas[index], "-1");
    strcpy(tipos[index], "-1");
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

    input(codigo, 20, "codigo:");
    int cmp_count = 0;
    for(int j = 0; j < TAM; j++) {
        if(strcmp(codigo, codes_servs[j]) == 0) {
            cmp_count++;
        }
    }
    for (int i = 1; i > 0; i++) {
        if (strlen(codigo) == 0 || cmp_count != 0) {
            do {
                input(codigo, 20, "Esse valor nao pode ficar em branco ou ja foi cadastrado:");
                cmp_count = 0;
                for(int j = 0; j < 5; j++) {
                    if(strcmp(codigo, codes_servs[j]) == 0) {
                        cmp_count++;
                    }
                }
            } while (strlen(codigo) == 0 || cmp_count != 0);

        }
        else
            break;
    }
    cmp_count = 0;

    input(nome, 255, "nome:");
    for (int i = 1; i > 0; i++) {
        if (strlen(nome) == 0) {
            do {
                input(nome, 20, "Esse valor nao pode ficar em branco:");
            } while (strlen(nome) == 0);

        }
        else
            break;
    }

    input(SIAPE, 20, "SIAPE:");
    for(int j = 0; j < TAM; j++) {
        if(strcmp(SIAPE, SIAPEs[j]) == 0) {
            cmp_count++;
        }
    }
    for (int i = 1; i > 0; i++) {
        if (strlen(SIAPE) == 0 || cmp_count != 0) {
            do {
                input(SIAPE, 20, "Esse valor nao pode ficar em branco ou ja foi cadastrado:");
                cmp_count = 0;
                for(int j = 0; j < 5; j++) {
                    if(strcmp(SIAPE, SIAPEs[j]) == 0) {
                        cmp_count++;
                    }
                }
            } while (strlen(SIAPE) == 0 || cmp_count != 0);

        }
        else
            break;
    }
    cmp_count = 0;

    input(CPF, 20, "CPF:");
    for(int j = 0; j < TAM; j++) {
        if(strcmp(CPF, CPFs[j]) == 0) {
            cmp_count++;
        }
    }
    for (int i = 1; i > 0; i++) {
        if (strlen(CPF) == 0 || cmp_count != 0) {
            do {
                input(CPF, 20, "Esse valor nao pode ficar em branco ou ja foi cadastrado:");
                cmp_count = 0;
                for(int j = 0; j < 5; j++) {
                    if(strcmp(CPF, CPFs[j]) == 0) {
                        cmp_count++;
                    }
                }
            } while (strlen(CPF) == 0 || cmp_count != 0);

        }
        else
            break;
    }
    cmp_count = 0;

    input(RG, 20, "RG:");
    input(endereco, 255, "endereco:");
    input(salario, 20, "salario:");
    input(data, 20, "data de nascimento:");
    for (int i = 1; i > 0; i++) {
        if (strlen(data) == 0) {
            do {
                input(data, 20, "Esse valor nao pode ficar em branco:");
            } while (strlen(data) == 0);

        }
        else
            break;
    }

    input(tipo, 30, "tipo(1 para docente, 2 para tecnico administrativo):");
    if(strcmp(tipo, "1") == 0) {
        strcpy(tipo, "docente");
    }
    else if(strcmp(tipo, "2") == 0) {
        strcpy(tipo, "tecnico administrativo");
    }
    printf("\n");

    lower_case(codigo, 20);
    lower_case(nome, 255);
    lower_case(SIAPE, 20);
    lower_case(CPF, 20);
    lower_case(RG, 20);
    lower_case(endereco, 255);
    lower_case(salario, 20);
    lower_case(data, 20);
    lower_case(tipo, 30);

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
            char CPF[20];
            char RG[20];
            char endereco[255];
            char salario[20];
            char data[20];
            char tipo[30];

            input(nome, 255, "nome:");
            input(SIAPE, 20, "SIAPE:");
            input(CPF, 20, "CPF:");
            input(RG, 20, "RG:");
            input(endereco, 255, "endereco:");
            input(salario, 20, "salario:");
            input(data, 20, "data de nascimento:");
            input(tipo, 30, "tipo:");
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

    return 0;
}