//------- Inclusoes

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "Menus.h"

//-------- Fim Inclusoes


//-------- Funcoes De Menus

void criarLinha(int tipoLinha, int alinhamentoPainel, int tamanhoLinha) {

	printf("\n\t");

	switch (tipoLinha) {
	case _LINHA_MENU_:
		printf("+");
		for (int i = 0; i < tamanhoLinha; i++) printf("-");
		printf("+");
		break;
	case _LINHA_DIVISORIA_:
		for (int i = 0; i < tamanhoLinha; i++) printf("-");
	default:
		break;
	}
}

void criaLinhaTexto(int alinhamentoTexto, int tamanhoDaTela, char* textoLinha) {
	if (alinhamentoTexto == _ESQUERDA_) printf("\n\t| %s%*s |", textoLinha, (int)(((tamanhoDaTela - 2) - strlen(textoLinha))), " ");
	else if (alinhamentoTexto == _CENTRO_) printf("\n\t| %*s%s%*s |", ((int)(tamanhoDaTela - strlen(textoLinha) / 2), " ", textoLinha, (int)(tamanhoDaTela - strlen(textoLinha) / 2), " "));
	else printf("\n\t| %*s%s |", ((int)((tamanhoDaTela - 2) - strlen(textoLinha))), " ", textoLinha);

	criarLinha(_LINHA_MENU_, alinhamentoTexto, tamanhoDaTela);
}

void criaLinhaCabecalho(int alinhamentoTexto, int tamanhoDaTela, char* textoCabecalho) {
	criarLinha(_LINHA_MENU_, alinhamentoTexto, tamanhoDaTela);
	printf("\n\t| %*s%s%*s |", (((tamanhoDaTela - 1) - strlen(textoCabecalho)) / 2), " ", textoCabecalho, (((tamanhoDaTela - 2) - strlen(textoCabecalho) + 1) / 2), " ");
	criarLinha(_LINHA_MENU_, alinhamentoTexto, tamanhoDaTela);
}

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
		criaLinhaCabecalho(_CENTRO_, 50, "CARA LIVRO");
		criaLinhaTexto(_ESQUERDA_, 50, "1 - LOGIN ");
		criaLinhaTexto(_ESQUERDA_, 50, "2 - CADASTRO");
		criaLinhaTexto(_DIREITA_, 50, "0 - FINALIZAR");

		opcao = lerOpcaoMenu();
		ERRO = opcao < _SAIR_&& opcao > _CADASTRO_;

		if (ERRO) printf("ERRO - OPCAO INVALIDA!");
	} while (ERRO);

	return opcao;
}

opcao_t menuFuncionalidadesPerfil(char* nomeUsuarioAtual) {
	opcao_t opcao;
	boolean_t ERRO;

	do {
		criaLinhaCabecalho(_CENTRO_, 50, nomeUsuarioAtual);
		criaLinhaTexto(_ESQUERDA_, 50, "1 - TIME-LINE");
		criaLinhaTexto(_ESQUERDA_, 50, "2 - MEU-PERFIL");
		criaLinhaTexto(_ESQUERDA_, 50, "3 - CONFIGURACOES PERFIL");
		criaLinhaTexto(_ESQUERDA_, 50, "4 - ACOES PERFIL");
		criaLinhaTexto(_DIREITA_, 50, "0 - SAIR");

		opcao = lerOpcaoMenu();
		ERRO = opcao < _SAIR_&& opcao > _ACOES_PERFIL_;

		if (ERRO) printf("ERRO - OPCAO INVALIDA!");
	} while (ERRO);
}

opcao_t menuMeuPerfil(char* nomeUsuarioAtual) {
	opcao_t opcao;
	boolean_t ERRO;

	do {
		criaLinhaCabecalho(_CENTRO_, 50, nomeUsuarioAtual);
		criaLinhaCabecalho(_CENTRO_, 50, "MEU PERFIL");
		criaLinhaTexto(_ESQUERDA_, 50, "1 - AMIZADES");
		criaLinhaTexto(_ESQUERDA_, 50, "2 - MINHAS POSTAGENS");
		criaLinhaTexto(_ESQUERDA_, 50, "3 - CONFIGURACOES PERFIL");
		criaLinhaTexto(_ESQUERDA_, 50, "4 - ACOES PERFIL");
		criaLinhaTexto(_DIREITA_, 50, "0 - VOLTAR");

		opcao = lerOpcaoMenu();
		ERRO = opcao < _SAIR_&& opcao > _ACOES_PERFIL_;

		if (ERRO) printf("ERRO - OPCAO INVALIDA!");
	} while (ERRO);
}

/*
void menuMeuTimeLine(perfil_t* usuarioAtual, postagem_t *postAtual) {
	criaLinhaCabecalho(_CENTRO_, 50, usuarioAtual->dadosUsuario.nome);
	criaLinhaTexto(_CENTRO_, 50, "MEU PERFIL");
	criaLinhaTexto(_ESQUERDA_, 50, "1 - AMIZADES");
	criaLinhaTexto(_ESQUERDA_, 50, "3 - MINHAS POSTAGENS");
	criaLinhaTexto(_ESQUERDA_, 50, "3 - CONFIGURACOES PERFIL");
	criaLinhaTexto(_ESQUERDA_, 50, "4 - ACOES PERFIL");
	criaLinhaTexto(_DIREITA_, 50, "0 - VOLTAR");
}*/

/*
+------------------------------------+
|             POST GABI              |
+------------------------------------+
| dasdasdas                          |
+------------------------------------+
| VC + 100 Pessoas Curtiram isso     |
+------------------------------------+

-------------------------------------
1 - Curtir/Descurtir
2 - Detalhes
3 - Rolar Feed
4 - Retornar Perfil
-------------------------------------
*/

//-------- Fim Funcoes De Menus