//------- Inclusões

#include <stdio.h>
#include <string.h>

#include "Menus.h"
#include "Perfil.h"
#include "ListaE.h"
#include "Postagem.h"

//------- Fim Inclusões


//------- Constantes Rede

#define SUCESSO (0)

//------- Fim Constantes Rede


//-------- Estrutura Padrão Rede

struct caraLivro_s {
    perfil_t *perfilAtivo;
    uint32_t numPerfis;
    perfil_t** vetorPerfis;
    //grafo_t relacoesPerfis;
};

typedef struct caraLivro_s caraLivro_t;

//-------- Estrutura Padrão Rede


//-------- Assinaturas de Funções Principais

void inicializaRede(caraLivro_t* estruturaSistema);
boolean_t cadastrarNovoPerfil(caraLivro_t* estruturaSistema);

//-------- Fim Assinaturas de Funções Principais

int main(int argc, char** argv){
    caraLivro_t redeSocial;
    inicializaRede(&redeSocial);
    cadastrarNovoPerfil(&redeSocial);
    cadastrarNovoPerfil(&redeSocial);


    return SUCESSO;
}


void removeBarraEne(char *string) {
    int i;
    char lixo;
    for (i = 0; i < strlen(string); i++) {
        if (string[i] == '\n') {
            string[i] = '\0';
        }
    }
}

void inicializaRede(caraLivro_t* estruturaSistema) {
    estruturaSistema->numPerfis = 0;
    estruturaSistema->perfilAtivo = NULL;
    estruturaSistema->vetorPerfis = NULL;
}

boolean_t cadastrarNovoPerfil(caraLivro_t* estruturaSistema) {
    boolean_t cadastrado = FALSE;
    char lixo;
    uint32_t qtdPerfisAtual = estruturaSistema->numPerfis;
    perfil_t** vertorPerfis = estruturaSistema->vetorPerfis;

    char nome[MAX_NOME], login[MAX_LOGIN], senha[MAX_SENHA];

    criarLinha(_LINHA_DIVISORIA_, _CENTRO_, 50);
    printf("\n\tEscolha seu login [MAX 15 Caracteres]: ");
    fgets(login, MAX_LOGIN, stdin);
    removeBarraEne(login);

    if (buscaPerfil(vertorPerfis, qtdPerfisAtual, login) == NULL) {
        estruturaSistema->vetorPerfis = realloc(estruturaSistema->vetorPerfis, (qtdPerfisAtual + 1) * sizeof(perfil_t*));
        if (estruturaSistema->vetorPerfis != NULL) {

            printf("\tEscolha seu senha [MAX 6 Caracteres]: ");
            fgets(senha, MAX_SENHA, stdin);
            removeBarraEne(senha);

            printf("\tDigite seu nome [MAX 50 Caracteres]: ");
            fgets(nome, MAX_NOME, stdin);
            removeBarraEne(nome);

            estruturaSistema->vetorPerfis[qtdPerfisAtual] = criarNovoPerfil(nome, login, senha, (qtdPerfisAtual + 1));
            estruturaSistema->numPerfis++;
        }
    }
    else {
        criaLinhaCabecalho(_CENTRO_, 50, "LOGIN JÁ EXISTE");
    }

    return cadastrado;
}