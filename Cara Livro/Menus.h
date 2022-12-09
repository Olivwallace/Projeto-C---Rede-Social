#pragma once

#ifndef __MENUS_h__
#define __MENUS_h__

//------- Inclusoes

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

//-------- Fim Inclusoes

//-------- Constantes

#define _MAX_OPC_PRINCIPAL_ (2)

//-------- Fim Constantes

//-------- Modelagem de Funcoes de Manipulacao e tipos 

typedef uint32_t boolean_t;
typedef int opcao_t;

//-------- Fim Modelagem de Funcoes de Manipulacao e tipos


//-------- Enumeradores

/// <summary>
///		Enumerador Posicionamento Texto
/// </summary>
enum {
	_CENTRO_ = 1,
	_DIREITA_,
	_ESQUERDA_
};


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
	_ACOES_PERFIL_
};


/// <summary>
///		Enumerador Funcionalidades Menu Principal
/// </summary>
enum {
	_LINHA_MENU_,
	_LINHA_DIVISORIA_
};

//-------- Fim Enumeradores 


//-------- Assinatura Funcoes 

void criarLinha(int tipoLinha, int alinhamentoPainel, int tamanhoLinha);
void criaLinhaCabecalho(int alinhamentoTexto, int tamanhoDaTela, char* textoCabecalho);
void criaLinhaTexto(int alinhamentoTexto, int tamanhoDaTela, char* textoLinha);

opcao_t lerOpcaoMenu();

opcao_t menuPrincipal();
opcao_t menuFuncionalidadesPerfil(char* nomeUsuarioAtual);
opcao_t menuMeuPerfil(char* nomeUsuarioAtual);


//void validaMenuInicial();

//-------- Fim Assinatura Funcoes 


#endif //__MENUS_h_