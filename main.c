#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 10

// Vars para servidores
char codes_servs[TAM][20]; // campo obrigatório e não pode repetir
char nomes[TAM][255]; // campo obrigatório
char SIAPEs[TAM][20]; // campo obrigatório e não pode repetir
char RGs[TAM][20];
char CPFs[TAM][20]; // não pode repetir e campo obrigatório
char enderecos[TAM][255];
char salarios[TAM][20];
char datas[TAM][20]; //campo obrigatório
char tipos[TAM][30];
char ocupados[TAM]; // Diz qual espaço da lista está vazio

// Vars para veículos
char codes_cars[TAM][TAM][20]; // obrigatorio
char codes_servs_cars[TAM][TAM][20]; // de novo
char descs[TAM][TAM][255]; // obrigatorio
char placas[TAM][TAM][20]; // obrigatorio
char marcas[TAM][TAM][20]; // obrigatorio
char modelos[TAM][TAM][255]; // obrigatorio
char ocupados_cars[TAM][TAM]; //Diz qual espaço da lista está vazio

void lower_case(char str[], int tam) // Passa todos os caracteres para caixa baixa
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
        strcpy(codes_servs[j], "");
        strcpy(nomes[j], "");
        strcpy(SIAPEs[j], "");
        strcpy(RGs[j], "");
        strcpy(CPFs[j], "");
        strcpy(enderecos[j], "");
        strcpy(salarios[j], "");
        strcpy(datas[j], "");
        strcpy(tipos[j], "");
    }
}

void iniciar_cars() // Diz que todos os lugares na lista estao desocupados
{
    for (int i = 0; i < TAM; ++i) {
        for (int j = 0; j < TAM; ++j) {
            ocupados_cars[i][j] = '0';
        }
    }

    for (int i = 0; i < TAM; ++i) {
        for (int j = 0; j < TAM; ++j) {
            strcpy(codes_cars[i][j], "0");
            strcpy(codes_servs_cars[i][j], "0");
            strcpy(descs[i][j], "0");
            strcpy(placas[i][j], "0");
            strcpy(marcas[i][j], "0");
            strcpy(modelos[i][j], "0");
        }
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

void exclude_serv() // Exclui os servidores por codigo
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

    strcpy(codes_servs[index], "");
    strcpy(nomes[index], "");
    strcpy(SIAPEs[index], "");
    strcpy(CPFs[index] , "");
    strcpy(RGs[index], "");
    strcpy(enderecos[index], "");
    strcpy(salarios[index], "");
    strcpy(datas[index], "");
    strcpy(tipos[index], "");
}

void exclude_car() { // Exclui os veiculos pelo codigo do veiculo
    char code[10];
    input(code, 10, "Digite o codigo do veiculo para excluir o veiculo:");
    int index1 = -1;
    int index2 = -1;
    for (int i = 0; i < TAM; ++i) {
        for (int j = 0; j < TAM; ++j) {
            if(strcmp(codes_cars[i][j], code) == 0) {
                index1 = i;
                index2 = j;
                break;
            }
        }
    }

    strcpy(codes_cars[index1][index2], "0");
    strcpy(codes_servs_cars[index1][index2], "0");
    strcpy(descs[index1][index2], "0");
    strcpy(placas[index1][index2], "0");
    strcpy(marcas[index1][index2], "0");
    strcpy(modelos[index1][index2], "0");
    ocupados_cars[index1][index2] = '0';
} //

void insert_car() //
{
    char v[20];
    int index1 = -1;
    input(v, 20, "digite o codigo do servidor para inserir o veiculo:");
    for (int i = 0; i < TAM; ++i) {
        if (strcmp(codes_servs[i], v) == 0) {
            index1 = i;
            break;
        }
    }
    int index2 = -1;
    for (int j = 0; j < TAM; ++j) {
        if (ocupados_cars[index1][j] == '0') {
            index2 = j;
            break;
        }
    }
    ocupados_cars[index1][index2] = '1';

    char code_car[20];
    char desc[255];
    char placa[20];
    char marca[20];
    char modelo[20];
    int cmp_count = 0;

    input(code_car, 20, "codigo do veiculo:");
    for (int j = 0; j < TAM; j++) {
        if (strcmp(code_car, codes_cars[index1][j]) == 0)
            cmp_count++;
    }
    if (strlen(code_car) == 0 || cmp_count != 0) {
        do {
            input(code_car, 20, "Esse valor nao pode ficar em branco ou ja foi cadastrado:");
            cmp_count = 0;
            for (int j = 0; j < TAM; j++) {
                if (strcmp(code_car, codes_cars[index1][j]) == 0)
                    cmp_count++;
            }
        } while (strlen(code_car) == 0 || cmp_count != 0);
    }
    cmp_count = 0;

    input(desc, 255, "descricao:");
    for (int j = 0; j < TAM; j++) {
        if (strcmp(desc, descs[index1][j]) == 0)
            cmp_count++;
    }
    if (strlen(desc) == 0 || cmp_count != 0) {
        do {
            input(desc, 20, "Esse valor nao pode ficar em branco ou ja foi cadastrado:");
            cmp_count = 0;
            for (int j = 0; j < TAM; j++) {
                if (strcmp(desc, descs[index1][j]) == 0)
                    cmp_count++;
            }
        } while (strlen(desc) == 0 || cmp_count != 0);
    }
    cmp_count = 0;

    input(placa, 20, "placa:");
        if (strlen(placa) == 0) {
            do {
                input(placa, 20, "Esse valor nao pode ficar em branco:");
            } while (strlen(placa) == 0);
        }

    input(marca, 20, "marca:");
        if (strlen(marca) == 0) {
            do {
                input(marca, 20, "Esse valor nao pode ficar em branco:");
            } while (strlen(marca) == 0);
        }

    input(modelo, 255, "modelo:");
        if (strlen(modelo) == 0) {
            do {
                input(modelo, 20, "Esse valor nao pode ficar em branco:");
            } while (strlen(modelo) == 0);
        }

    lower_case(code_car, 20);
    lower_case(desc, 255);
    lower_case(placa, 20);
    lower_case(marca, 20);
    lower_case(modelo, 255);

    strcpy(codes_servs_cars[index1][index2], v);
    strcpy(codes_cars[index1][index2], code_car);
    strcpy(descs[index1][index2], desc);
    strcpy(placas[index1][index2], placa);
    strcpy(marcas[index1][index2], marca);
    strcpy(modelos[index1][index2], modelo);
}

void insert_serv()
{
    int index = -1;
    for (int i = 0; i < TAM; ++i) {
        if(ocupados[i] == 0 ) {
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
        if(strcmp(codigo, codes_servs[j]) == 0)
            cmp_count++;
    }
    if (strlen(codigo) == 0 || cmp_count != 0) {
        do {
            input(codigo, 20, "Esse valor nao pode ficar em branco ou ja foi cadastrado:");
            cmp_count = 0;
            for(int j = 0; j < TAM; j++) {
                if(strcmp(codigo, codes_servs[j]) == 0)
                    cmp_count++;
            }
        } while (strlen(codigo) == 0 || cmp_count != 0);
    }
    cmp_count = 0;

    input(nome, 255, "nome:");
        if (strlen(nome) == 0) {
            do {
                input(nome, 20, "Esse valor nao pode ficar em branco:");
            } while (strlen(nome) == 0);
        }

    input(SIAPE, 20, "SIAPE:");
    for(int j = 0; j < TAM; j++) {
        if(strcmp(SIAPE, SIAPEs[j]) == 0)
            cmp_count++;
    }
    if (strlen(SIAPE) == 0 || cmp_count != 0) {
        do {
            input(SIAPE, 20, "Esse valor nao pode ficar em branco ou ja foi cadastrado:");
            cmp_count = 0;
            for(int j = 0; j < TAM; j++) {
                if(strcmp(SIAPE, SIAPEs[j]) == 0)
                    cmp_count++;
            }
        } while (strlen(SIAPE) == 0 || cmp_count != 0);
    }
    cmp_count = 0;

    input(CPF, 20, "CPF:");
    for(int j = 0; j < TAM; j++) {
        if(strcmp(CPF, CPFs[j]) == 0)
            cmp_count++;
    }
    if (strlen(CPF) == 0 || cmp_count != 0) {
        do {
            input(CPF, 20, "Esse valor nao pode ficar em branco ou ja foi cadastrado:");
            cmp_count = 0;
            for(int j = 0; j < TAM; j++) {
                if(strcmp(CPF, CPFs[j]) == 0)
                    cmp_count++;
            }
        } while (strlen(CPF) == 0 || cmp_count != 0);
    }
    cmp_count = 0;

    input(RG, 20, "RG:");
    if(strlen(RG) == 0)
        strcpy(RG, "omitido");

    input(endereco, 255, "endereco:");
    if(strlen(endereco) == 0)
        strcpy(endereco, "omitido");

    input(salario, 20, "salario:");
    if(strlen(salario) == 0)
        strcpy(salario, "omitido");

    input(data, 20, "data de nascimento:");
        if (strlen(data) == 0) {
            do {
                input(data, 20, "Esse valor nao pode ficar em branco:");
            } while (strlen(data) == 0);
        }

    input(tipo, 30, "tipo (1 para docente, 2 para tecnico administrativo):");
    if(strcmp(tipo, "1") == 0)
        strcpy(tipo, "docente");

    else if(strcmp(tipo, "2") == 0)
        strcpy(tipo, "tecnico administrativo");

    else if(strcmp(tipo, "1") != 0 || strcmp(tipo, "2") != 0 && strlen(tipo) != 0)
        strcpy(tipo, "omitido");

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
} //

void list_serv() //
{
    printf("############ LISTAGEM ############\n");

    for (int i = 0; i < TAM; ++i)
    {
        if(ocupados[i] == 1 )
            printf("\n#CODIGO: %s\n#NOME: %s\n#SIAPE: %s\n#RG: %s\n#CPF: %s\n#ENDERECO: %s\n#SALARIO: %s\n#DATA NASC: %s\n#TIPO: %s\n",codes_servs[i], nomes[i], SIAPEs[i], RGs[i], CPFs[i], enderecos[i], salarios[i], datas[i], tipos[i]);
    }
    printf("##################################\n\n");
}

void list_order_ab() {
    int indices[TAM];
    for (int i = 0; i < TAM; i++) {
        indices[i] = i;
    }

    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < (TAM - 1) - i; j++) {
            if (strcmp(nomes[indices[j]], nomes[indices[j + 1]]) > 0) {
                int tmp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = tmp;

            }
        }
    }

    printf("\n##########LISTA ORDENADA ALFABETICAMENTE##########\n");
    for (int i = 0; i < TAM ; i++) {
        if(ocupados[indices[i]] == 1) {
            printf("\n#CODIGO:\t%s\n#NOME: \t\t\t%s\n#NUMERO SIAPE: \t\t%s\n#RG: \t\t\t%s\n#CPF: \t\t\t%s\n#ENDERECO: \t\t%s\n#SALARIO: \t\t%s\n#DATA DE NASCIMENTO: \t%s\n#TIPO: \t\t\t%s\n",
                   codes_servs[indices[i]], nomes[indices[i]], SIAPEs[indices[i]], RGs[indices[i]], CPFs[indices[i]],
                   enderecos[indices[i]], salarios[indices[i]], datas[indices[i]], tipos[indices[i]]);
            printf("##########################################\n\n");
        }
    }
} //

void list_serv_tec()
{
    char type[10];
    input(type, 10, "Digite 1 para listar docentes e 2 para listar tecnicos administrativos:");
    printf("############ LISTAGEM ############\n");

    for (int i = 0; i < TAM; ++i)
    {
        if(ocupados[i] == 1 && (!strcmp(type, "1")) && (!strcmp(tipos[i],"docente"))) {
            printf("\n#CODIGO: %s\n#NOME: %s\n#SIAPE: %s\n#RG: %s\n#CPF: %s\n#ENDERECO: %s\n#SALARIO: %s\n#DATA NASC: %s\n#TIPO: %s\n",codes_servs[i], nomes[i], SIAPEs[i], RGs[i], CPFs[i], enderecos[i], salarios[i], datas[i], tipos[i]);
        }
        else if(ocupados[i] == 1 && (!strcmp(type, "2")) && (!strcmp(tipos[i],"tecnico administrativo"))) {
            printf("\n#CODIGO: %s\n#NOME: %s\n#SIAPE: %s\n#RG: %s\n#CPF: %s\n#ENDERECO: %s\n#SALARIO: %s\n#DATA NASC: %s\n#TIPO: %s\n",codes_servs[i], nomes[i], SIAPEs[i], RGs[i], CPFs[i], enderecos[i], salarios[i], datas[i], tipos[i]);
        }
    }
    printf("##################################\n\n");
} //

void list_serv_code() //
{
    char code[10];
    input(code, 10, "Digite o codigo do servidor para listar:");
    for(int i = 0; i < TAM; i++)
    {
        if(!(strcmp(codes_servs[i], code)) && ocupados[i] == 1)
            printf("\n#CODIGO: %s\n#NOME: %s\n#SIAPE: %s\n#RG: %s\n#CPF: %s\n#ENDERECO: %s\n#SALARIO: %s\n#DATA NASC: %s\n#TIPO: %s\n",codes_servs[i], nomes[i], SIAPEs[i], RGs[i], CPFs[i], enderecos[i], salarios[i], datas[i], tipos[i]);
    }
}

void list_car_code() { // Pegar um veiculo de um servidor e lista ele
    char code[10];
    input(code, 10, "Digite o codigo do veiculo para listar:");
    int index1 = -1;
    int index2 = -1;

    for (int i = 0; i < TAM; ++i) {
        for (int j = 0; j < TAM; ++j) {
            if(strcmp(codes_cars[i][j], code) == 0) {
                index1 = i;
                index2 = j;
                break;
            }
        }
    }
    for(int i = 0; i < TAM; i++)
    {
        if((strcmp(codes_cars[index1][index2], code) == 0))
        {
            printf("\n#CODIGO DO VEICULO: %s\n#CODIGO DO SERVIDOR: %s\n#DESCRICAO: %s\n#PLACA: %s\n#MARCA: %s\n#MODELO: %s\n",codes_cars[index1][index2], codes_servs_cars[index1][index2], descs[index1][index2], placas[index1][index2], marcas[index1][index2], modelos[index1][index2]);
            break;
        }
    }
} //

void edit_car() {
    int index1 = -1;
    int index2 = -1;
    char code[10];
    input(code, 10, "Digite o codigo do veiculo para edição:");
    for (int i = 0; i < TAM; ++i) {
        for (int j = 0; j < TAM; ++j) {
            if(strcmp(codes_cars[i][j], code) == 0) {
                index1 = i;
                index2 = j;

                strcpy(codes_cars[index1][index2], "0");
                strcpy(codes_servs_cars[index1][index2], "0");
                strcpy(descs[index1][index2], "0");
                strcpy(placas[index1][index2], "0");
                strcpy(marcas[index1][index2], "0");
                strcpy(modelos[index1][index2], "0");

                char code_car[20];
                char desc[20];
                char placa[20];
                char marca[20];
                char modelo[255];

                input(code_car, 20, "Codigo do veiculo");
                int cmp_count = 0;
                for(int m = 0; m < TAM; m++) {
                    for (int k = 0; k < TAM; ++k) {
                        if(strcmp(code_car, codes_cars[m][k]) == 0)
                            cmp_count++;
                    }
                }
                if (cmp_count != 0 || strlen(code_car) == 0) {
                    do {
                        input(code_car, 20, "O codigo não pode se repetir e nao pode estar em branco:");
                        cmp_count = 0;
                        for(int m = 0; m < TAM; m++) {
                            for (int k = 0; k < TAM; ++k) {
                                if(strcmp(code_car, codes_cars[m][k]) == 0)
                                    cmp_count++;
                            }
                        }
                    } while (cmp_count != 0 || strlen(code_car) == 0);
                }
                cmp_count = 0;

                input(desc, 20, "Descricao do veiculo:");
                cmp_count = 0;
                for(int m = 0; m < TAM; m++) {
                    for (int k = 0; k < TAM; ++k) {
                        if(strcmp(desc, descs[m][k]) == 0)
                            cmp_count++;
                    }
                }
                for (int n = 1; n > 0; n++) {
                    if (strlen(desc) == 0 || cmp_count != 0) {
                        do {
                            input(desc, 20, "Esse valor nao pode ficar em branco ou ja foi cadastrado:");
                            cmp_count = 0;
                            for(int m = 0; m < TAM; m++) {
                                for (int k = 0; k < TAM; ++k) {
                                    if(strcmp(desc, descs[m][k]) == 0)
                                        cmp_count++;
                                }
                            }
                        } while (strlen(desc) == 0 || cmp_count != 0);
                    }
                    else
                        break;
                }
                cmp_count = 0;

                input(placa, 20, "Placa do veiculo:");
                    if (strlen(placa) == 0) {
                        do {
                            input(placa, 20, "Esse valor nao pode ficar em branco:");
                        } while (strlen(placa) == 0);
                    }

                input(marca, 20, "marca:");
                    if (strlen(marca) == 0) {
                        do {
                            input(marca, 20, "Esse valor nao pode ficar em branco:");
                        } while (strlen(marca) == 0);
                    }

                input(modelo, 255, "modelo do veiculo:");
                    if (strlen(modelo) == 0) {
                        do {
                            input(modelo, 20, "Esse valor nao pode ficar em branco:");
                        } while (strlen(modelo) == 0);
                    }

                printf("\n");

                lower_case(code_car, 20);
                lower_case(desc, 255);
                lower_case(placa, 20);
                lower_case(marca, 20);
                lower_case(modelo, 20);

                strcpy(codes_cars[index1][index2], code_car);
                strcpy(descs[index1][index2], desc);
                strcpy(placas[index1][index2] , placa);
                strcpy(marcas[index1][index2], marca);
                strcpy(modelos[index1][index2], modelo);
                break;
            }
        }
    }
} //

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
            strcpy(nomes[index], "");
            strcpy(SIAPEs[index], "");
            strcpy(CPFs[index] , "");
            strcpy(RGs[index], "");
            strcpy(enderecos[index], "");
            strcpy(salarios[index], "");
            strcpy(datas[index], "");
            strcpy(tipos[index], "");

            char nome[255];
            char SIAPE[20];
            char CPF[20];
            char RG[20];
            char endereco[255];
            char salario[20];
            char data[20];
            char tipo[30];

            input(nome, 255, "nome:");
            if (strlen(nome) == 0) {
                do {
                    input(nome, 20, "Esse valor nao pode ficar em branco:");
                } while (strlen(nome) == 0);
            }

            input(SIAPE, 20, "SIAPE:");
            int cmp_count = 0;
            for(int j = 0; j < TAM; j++) {
                if(strcmp(SIAPE, SIAPEs[j]) == 0)
                    cmp_count++;
            }
            if (strlen(SIAPE) == 0 || cmp_count != 0) {
                do {
                    input(SIAPE, 20, "Esse valor nao pode ficar em branco ou ja foi cadastrado:");
                    cmp_count = 0;
                    for(int k = 0; k < 5; k++) {
                        if(strcmp(SIAPE, SIAPEs[k]) == 0)
                            cmp_count++;
                    }
                } while (strlen(SIAPE) == 0 || cmp_count != 0);
            }
            cmp_count = 0;

            input(CPF, 20, "CPF:");
            for(int j = 0; j < TAM; j++) {
                if(strcmp(CPF, CPFs[j]) == 0)
                    cmp_count++;
            }
            if (strlen(CPF) == 0 || cmp_count != 0) {
                do {
                    input(CPF, 20, "Esse valor nao pode ficar em branco ou ja foi cadastrado:");
                    cmp_count = 0;
                    for(int k = 0; k < 5; k++) {
                        if(strcmp(CPF, CPFs[k]) == 0)
                            cmp_count++;
                    }
                } while (strlen(CPF) == 0 || cmp_count != 0);
            }
            cmp_count = 0;

            input(RG, 20, "RG:");
            if(strlen(RG) == 0)
                strcpy(RG, "omitido");

            input(endereco, 255, "endereco:");
            if(strlen(endereco) == 0)
                strcpy(endereco, "omitido");

            input(salario, 20, "salario:");
            if(strlen(salario) == 0)
                strcpy(salario, "omitido");

            input(data, 20, "data de nascimento:");
            if (strlen(data) == 0) {
                do {
                    input(data, 20, "Esse valor nao pode ficar em branco:");
                } while (strlen(data) == 0);
            }

            input(tipo, 30, "tipo (1 para docente e 2 para tecnico administrativo):");
            if(strcmp(tipo, "1") == 0)
                strcpy(tipo, "docente");

            else if(strcmp(tipo, "2") == 0)
                strcpy(tipo, "tecnico administrativo");

            else if(strcmp(tipo, "1") != 0 || strcmp(tipo, "2") != 0 && strlen(tipo) != 0)
                strcpy(tipo, "omitido");

            printf("\n");

            lower_case(nome, 255);
            lower_case(SIAPE, 20);
            lower_case(CPF, 20);
            lower_case(RG, 20);
            lower_case(endereco, 255);
            lower_case(salario, 20);
            lower_case(data, 20);
            lower_case(tipo, 30);

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

void list_cars_code_serv() { // Lista os carros de um servidor com base no codigo do servidor
    char code[20];
    input(code, 20, "Digite o codigo do servidor para listar: ");
    int index = -1;
    for (int i = 0; i < TAM; ++i) {
        for (int j = 0; j < TAM; ++j) {
            if(strcmp(codes_servs_cars[i][j], code) == 0) {
                index = i;
                break;
            }
        }
    }

    printf("\n##########LISTA DOS VEICULOS DO SERVIDOR##########\n");
    for (int i = 0; i < TAM ; i++) {
        if(ocupados_cars[index][i] == '1') {
            printf("\n#CODIGO DO VEICULO:%s\n#CODIGO DO SERVIDOR DO VEICULO: %s\n#DESCRICAO: %s\n#PLACA: %s\n#MARCA: %s\n#MODELO: %s\n",
                   codes_cars[index][i], codes_servs_cars[index][i], descs[index][i], placas[index][i], marcas[index][i],
                   modelos[index][i]);
            printf("##########################################\n\n");
        }
    }
} //

void list_cars_ordem_ab() {
    char code[20];
    input(code, 20, "Digite o codigo do servidor para listar: ");
    int index = -1;
    for (int i = 0; i < TAM; ++i) {
        for (int j = 0; j < TAM; ++j) {
            if(strcmp(codes_servs_cars[i][j], code) == 0) {
                index = i;
                break;
            }
        }
    }
    int indices[TAM];
    for (int i = 0; i < TAM; i++) {
        indices[i] = i;
    }

    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < (TAM - 1) - i; j++) {
            if (strcmp(modelos[index][indices[j]], modelos[index][indices[j + 1]]) > 0) {
                int tmp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = tmp;

            }
        }
    }

    printf("\n##########LISTA ORDENADA ALFABETICAMENTE##########\n");
    for (int i = 0; i < TAM ; i++) {
        if(ocupados_cars[index][indices[i]] == '1') {
            printf("\n#CODIGO DO VEICULO: %s\n#CODIGO DO SERVIDOR DO VEICULO: %s\n#DESCRICAO: %s\n#PLACA: %s\n#MARCA: %s\n#MODELO: %s\n",
                   codes_cars[index][indices[i]], codes_servs_cars[index][indices[i]], descs[index][indices[i]], placas[index][indices[i]], marcas[index][indices[i]],
                   modelos[index][indices[i]]);
            printf("##########################################\n\n");
        }
    }
} //

int main()
{
    return 0;
}