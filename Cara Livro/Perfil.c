//------- Inclusoes

#include "Perfil.h"

//-------- Fim Inclusoes


//-------- Funcoes Hash Aberto

boolean_t autenticarLogin(perfil_t** perfisRede, uint32_t qtdPerfis ,char* login, char* senha) {
	boolean_t resultado = FALSE;
	perfil_t* perfilTestado = buscaPerfil(perfisRede, qtdPerfis, login);
	
	if (perfilTestado != NULL) {
		resultado = (strcmp(perfilTestado->dadosPerfil.login, login) == 0 && strcmp(perfilTestado->dadosPerfil.senha, senha) == 0);
	}

	return resultado;
}

perfil_t* buscaPerfil(perfil_t** perfisRede, uint32_t qtdPerfis, char* login) {
	int i;
	perfil_t* perfil = NULL;
	boolean_t encontrado = FALSE;
	
	for (i = 0; i < qtdPerfis && !encontrado; i++) {
		if (strcmp(perfisRede[i]->dadosPerfil.login, login) == 0) {
			perfil = perfisRede[i];
			encontrado == TRUE;
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


//-------- Fim Funcoes Hash Aberto