//------- Inclusões
////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "Perfil.h"
#include "ListaE.h"
#include "Grafo.h"
#include "Postagem.h"
#include "Pilha.h"

//------- Fim Inclusões


//-------- Funcoes Perfil

boolean_t autenticarLogin(perfil_t** perfisRede, uint32_t numPerfis, char* login, char* senha){
	boolean_t resultado = FALSE;
	perfil_t* perfilTestado = encontrarPerfil(perfisRede, numPerfis, login);

	if (perfilTestado != NULL) {
		resultado = (strcmp(perfilTestado->dadosPerfil.login, login) == 0 && strcmp(perfilTestado->dadosPerfil.senha, senha) == 0);
	}

	return resultado;
}

perfil_t* encontrarPerfil(perfil_t** perfisRede, uint32_t numPerfis, char* login) {
	int i;
	perfil_t* perfil = NULL;
	boolean_t encontrado = FALSE;

	for (i = 0; i < numPerfis && !encontrado; i++) {
		if (strcmp(perfisRede[i]->dadosPerfil.login, login) == 0) {
			perfil = perfisRede[i];
			encontrado = TRUE;
		}
	}

	return perfil;
}

perfil_t* criarNovoPerfil(char* nome, char* login, char* senha, uint32_t idUnico) {
	perfil_t* novo = (perfil_t*)malloc(sizeof(perfil_t));

	if (novo != NULL) {

		//Inicializa Config Perfil
		novo->idUnicioPerfil = idUnico;
		novo->visibilidade = TRUE;
		inicializaLista(&novo->postagens);

		//Inicializa Dados do Perfil
		strcpy(novo->dadosPerfil.login, login);
		strcpy(novo->dadosPerfil.nome, nome);
		strcpy(novo->dadosPerfil.senha, senha);
	}

	return novo;
}

boolean_t desativarPerfil(perfil_t* usuario) {
	if (usuario != NULL) {
		usuario->visibilidade = FALSE;
	}
}

boolean_t reativarPerfil(perfil_t* usuario) {
	if (usuario != NULL) {
		usuario->visibilidade = TRUE;
	}
}

boolean_t novoPostPerfil(perfil_t* usuario) {
	char conteudo[MAX_CONTEUDO];

	criaLinhaCabecalho(_CENTRO_, TAM_TELA_UM, "NOVO POST");
	printf("\n\tDIGITE O CONTEUDO [MAX - 50caracteres]:\n\t");
	lerString(conteudo, MAX_CONTEUDO);

	return insereInicioLista(&usuario->postagens, postagemCria(conteudo, usuario->dadosPerfil.login, usuario->postagens.numItens), addPostPerfil);
}

boolean_t deletarPostagem(perfil_t* usuario, post_t* postagem) {
	boolean_t removida = FALSE;
	
	if (retiraItemLista(&usuario->postagens, postagem, postagemCompara)) {
		removida = postagemDeleta(postagem);
	}

	return removida;
}

boolean_t curtiPostagem(perfil_t* usuario, post_t* postagem) {
	return tabelaHash_insere(&postagem->tabelaInteracoes, usuario->dadosPerfil.login);
}

boolean_t descurtirPostagem(perfil_t* usuario, post_t* postagem) {
	boolean_t removido = FALSE;

	if (tabelaHash_estaPresente(&postagem->tabelaInteracoes, usuario->dadosPerfil.login)) {
		removido = tabelaHash_remove(&postagem->tabelaInteracoes, usuario->dadosPerfil.login);
	}

	return removido;
}

//void visitarPerfil(perfil_t* usuarioLogado, perfil_t* perfilOrigem, perfil_t* perfilVisitado, perfil_t** perfisRede);

//void imprimirAmigos(perfil_t* perfil, perfil_t** perfisRede);

void preparaPilhaImpressao(pilha_t* pilha, perfil_t* perfil) {
	int i;

	for (i = 0; i < pilha->capacidade; i++) {
		post_t postBusca;
		postBusca.idPost = i;

		empilhaPilha(pilha, buscarItemLista(&perfil->postagens, &postBusca, postagemCompara), addPostPilha);
	}
}

void imprimirPostagens(perfil_t* perfil, boolean_t postDetalhado) {
	int i, numPost = perfil->postagens.numItens;
	pilha_t pilhaImpressao;
	inicializaPilha(&pilhaImpressao, numPost);

	preparaPilhaImpressao(&pilhaImpressao, perfil);

	if (postDetalhado) {

		for (i = 0; i < numPost; i++) {
			post_t posImprimir;
			desempilhaPilha(&pilhaImpressao, &posImprimir, addPostPerfil);
			postagemDetalhadaImprime(&posImprimir, perfil->dadosPerfil.login);
		}

	}
	else {

		for (i = 0; i < numPost; i++) {
			post_t posImprimir;
			desempilhaPilha(&pilhaImpressao, &posImprimir, addPostPerfil);
			postagemImprime(&posImprimir, perfil->dadosPerfil.login);
		}

	}
}

//void imprimirTimeLine(perfil_t* usuario, perfil_t** perfisRede);


boolean_t adicionarAmizade(perfil_t* usuario, perfil_t* perfilVisitado, grafo_t *grafo) {
	criaAdjacencia(grafo, usuario->endGrafo, perfilVisitado->idUnicioPerfil);
}

boolean_t desfazerAmizade(perfil_t* usuario, perfil_t* perfilVisitado, grafo_t* grafo) {
	removeAdjacencia(grafo, usuario->endGrafo, perfilVisitado->idUnicioPerfil);
}

//-------- Fim Funcoes Hash Aberto