//------- Inclusões

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "Menus.h"
#include "Uteis.h"

//------- Fim Inclusões


//-------- Funcoes De Menus

opcao_t lerOpcaoMenu() {
	opcao_t opc;
	printf("\n\n\tDIGITE SUA OPCAO:\t");
	scanf("%d%*c", &opc);
	return opc;
}

opcao_t menuPrincipal() {
	opcao_t opcao;
	boolean_t ERRO;
	
	do {
		criaLinhaCabecalho(_CENTRO_, TAM_TELA_UM, "CARA LIVRO");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "1 - LOGIN ");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "2 - CADASTRO");
		criaLinhaTexto(_DIREITA_, TAM_TELA_UM, "0 - FINALIZAR");

		opcao = lerOpcaoMenu();
		ERRO = opcao < _SAIR_ && opcao > _CADASTRO_;

		if (ERRO) printf("ERRO - OPCAO INVALIDA!");
	} while (ERRO);

	return opcao;
}

opcao_t menuFuncionalidadesPerfil(char* nomeUsuarioAtual) {
	opcao_t opcao;
	boolean_t ERRO;

	do {
		criaLinhaCabecalho(_CENTRO_, TAM_TELA_UM, nomeUsuarioAtual);
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "1 - TIME-LINE");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "2 - MEU-PERFIL");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "3 - CONFIGURACOES PERFIL");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "4 - _CRIAR_POST_");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "5 - _ADICIONAR_AMIGOS_");

		criaLinhaTexto(_DIREITA_, TAM_TELA_UM, "0 - SAIR");

		opcao = lerOpcaoMenu();
		ERRO = opcao < _SAIR_&& opcao > _ADICIONAR_AMIGOS_;

		if (ERRO) printf("ERRO - OPCAO INVALIDA!");
	} while (ERRO);

	return opcao;
}

opcao_t menuMeuPerfil(char* nomeUsuarioAtual) {
	opcao_t opcao;
	boolean_t ERRO;

	do {
		criaLinhaCabecalho(_CENTRO_, TAM_TELA_UM, nomeUsuarioAtual);
		criaLinhaCabecalho(_CENTRO_, TAM_TELA_UM, "MEU PERFIL");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "1 - AMIZADES");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "2 - MINHAS POSTAGENS");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "3 - CONFIGURACOES PERFIL");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "4 - CIRAR POST");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "5 - ADICIONAR AMIGOS");
		criaLinhaTexto(_DIREITA_, TAM_TELA_UM, "0 - VOLTAR");

		opcao = lerOpcaoMenu();
		ERRO = opcao < _SAIR_&& opcao > _ADICIONAR_AMIGOS_;

		if (ERRO) printf("ERRO - OPCAO INVALIDA!");
	} while (ERRO);
	
	return opcao;
}


opcao_t menuMeuTimeLine() {
	opcao_t opcao;
	boolean_t ERRO;

	do{
		criarLinha(_LINHA_DIVISORIA_, TAM_TELA_UM);
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "1 - CURTIR");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "2 - DETALHES");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "3 - ROLAR FEED");
		criaLinhaTexto(_ESQUERDA_, TAM_TELA_UM, "4 - RETORNAR AO PERFIL");
		criarLinha(_LINHA_DIVISORIA_, TAM_TELA_UM);

		opcao = lerOpcaoMenu();
		ERRO = opcao < _SAIR_ && opcao > _RETORNAR_AO_PERFIL;

		if (ERRO) printf("ERRO - OPCAO INVALIDA!");
	} while (ERRO);

	return opcao;
}


/*
+------------------------------------+
|             POST GABI              |
+------------------------------------+
| dasdasdas                          |
+------------------------------------+
|@gabi     
|@Jeferson
+-----------

-------------------------------------
1 - Curtir/Descurtir
2 - Detalhes
3 - Rolar Feed
4 - Retornar Perfil
-------------------------------------
*/

//-------- Fim Funcoes De Menus
