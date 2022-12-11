//------- Inclusões

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "Rede.h"
#include "Uteis.h"
#include "Perfil.h"
#include "Menus.h"
#include "Postagem.h"
#include "ListaE.h"
#include "tabHash.h"

//------- Fim Inclusões


//------- Constantes Rede

#define SUCESSO (0)

//------- Fim Constantes Rede


//-------- Fim Assinaturas de Funções Principais


int main(int argc, char** argv){
    caraLivro_t redeSocial;
    boolean_t continuarRodandoSistema = TRUE;
    boolean_t logado = FALSE, cadastrado = FALSE;

    inicializaRede(&redeSocial);
    do {
        opcao_t retornoMenu = menuPrincipal();

        switch (retornoMenu){
        case _LOGIN_:
            logado = realizarLogin(&redeSocial);
                
            if (logado) {
                do {

                    retornoMenu = menuFuncionalidadesPerfil(redeSocial.perfilAtivo->dadosPerfil.nome);

                    switch (retornoMenu) {
                    case _TIME_LINE_:

                        break;
                    case _MEU_PERFIL_:
                        retornoMenu = menuMeuPerfil(redeSocial.perfilAtivo->dadosPerfil.nome); 
                        
                            switch(retornoMenu){
                            case _AMIZADES_:

                                break;
                        
                            case _MINHAS_POSTAGENS_:

                                break;

                            case _CONFIG_PERFIL_:

                                break;

                            case _CRIAR_POST_:

								criarPost(redeSocial.perfilAtivo);

                                break;

                            case _ADICIONAR_AMIGOS_:

                                break;

							default:
								criaLinhaCabecalho(_CENTRO_, TAM_TELA_UM, "SAINDO SISTEMA - OBRIGADO!");
								continuarRodandoSistema = FALSE;
								break;

                            }

                        break;

                    case _CONFIG_PERFIL_:
                        
                    
                        break;

                    case _CRIAR_POST_:
                        
                        criarPost(redeSocial.perfilAtivo);

                        break;
						
                    case _ADICIONAR_AMIGOS_:

                      

                         break;
                    default:
                        logado = FALSE;
                        break;
                    }

                }while(logado);
            }

            break;

        case _CADASTRO_:
            cadastrado = cadastrarNovoPerfil(&redeSocial);

            if (cadastrado) {
                criaLinhaCabecalho(_CENTRO_, TAM_TELA_UM, "USUARIO CADASTRADO COM SUCESSO ");
            }
            else {
                criaLinhaCabecalho(_CENTRO_, TAM_TELA_UM, "ERRO AO CADASTRAR USUARIO");
            }

            break;
        default:
            criaLinhaCabecalho(_CENTRO_, TAM_TELA_UM, "SAINDO SISTEMA - OBRIGADO!");
            continuarRodandoSistema = FALSE;
            break;
    }
    } while (continuarRodandoSistema);


    return SUCESSO;
}
