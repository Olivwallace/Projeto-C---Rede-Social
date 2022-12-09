#pragma once

#ifndef __PERFIL_h__
#define __PERFIL_h__

//------- Inclusoes

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "Postagem.h"
#include "ListaE.h"

//-------- Fim Inclusoes


//-------- Constantes

#define MAX_NOME  (45 + 1)
#define MAX_LOGIN (15 + 1)
#define MAX_SENHA (6 + 1)

//-------- Fim Constantes

//-------- Dado Armazenado 
//-------- Fim Dado Armazenado

//-------- Modelagem de Funcoes de Manipulacao e tipos 

typedef uint32_t boolean_t;

//-------- Fim Modelagem de Funcoes de Manipulacao e tipos


//-------- Estrutura 

struct dadosPerfil_s {
	char login[MAX_LOGIN];
	char senha[MAX_SENHA];
	char nome[MAX_NOME];
};

typedef struct dadosPerfil_s dadosPerfil_t;

struct perfil_s {
	uint32_t idUnicioPerfil;
	dadosPerfil_t dadosPerfil;
	listaE_t postagens;
	uint32_t posicaoGrafo;
	boolean_t visibilidade;
};

typedef struct perfil_s perfil_t;

//-------- Fim Estrutura 


//-------- Assinatura Funcoes 

boolean_t autenticarLogin(perfil_t** perfisRede, uint32_t qtdPerfis, char* login, char* senha);
perfil_t* buscaPerfil(perfil_t** perfisRede, uint32_t qtdPerfis, char* login);
perfil_t* criarNovoPerfil(char* nome, char* login, char* senha, uint32_t idUnico);

//-------- Fim Assinatura Funcoes 


#endif //__PERFIL_h_
