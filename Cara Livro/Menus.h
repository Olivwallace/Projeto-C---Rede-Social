#pragma once

#ifndef __MENUS_h__
#define __MENUS_h__

//------- Inclusões

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


#include "Uteis.h" 

//------- Fim Inclusões

//-------- Constantes

#define _MAX_OPC_PRINCIPAL_ (2)

//-------- Fim Constantes

//-------- Modelagem de Funcoes de Manipulacao e tipos 

typedef uint32_t boolean_t;
typedef int opcao_t;

//-------- Fim Modelagem de Funcoes de Manipulacao e tipos


//-------- Enumeradores

/// <summary>
///		Enumerador Funcionalidades Menu Principal
/// </summary>
enum {
	_SAIR_,
	_LOGIN_,
	_CADASTRO_,
	/*_ALTERAR_DADOS_,
	_DESATIVAR_PERFIL_*/
};


/// <summary>
///		Enumerador Funcionalidades Do Perfil
/// </summary>
enum {
	_TIME_LINE_ = 1,
	_MEU_PERFIL_,
	//_CONFIG_PERFIL_,
	//_ACOES_PERFIL_,
};

/// <summary>
///		Enumerador Funcionalidades Menu Principal
/// </summary>
enum {
	_AMIZADES_ = 1,
	_MINHAS_POSTAGENS_,
	_CONFIG_PERFIL_,
	_CRIAR_POST_,
	_ADICIONAR_AMIGOS_
};

enum {
	_CURTIR_ = 1,
	_DETALHES_,
	_ROLAR_FEED_,
	_RETORNAR_AO_PERFIL
};

/// <summary>
///		Enumerador Funcionalidades Menu Acoes do Perfil
/// </summary>



//-------- Fim Enumeradores 


//-------- Assinatura Funcoes 

opcao_t lerOpcaoMenu();

opcao_t menuPrincipal();
opcao_t menuFuncionalidadesPerfil(char* nomeUsuarioAtual);
opcao_t menuMeuPerfil(char* nomeUsuarioAtual);
opcao_t menuMeuPerfil(char* nomeUsuarioAtual);
opcao_t menuMeuTimeLine();

//void validaMenuInicial();

//-------- Fim Assinatura Funcoes 


#endif //__MENUS_h_