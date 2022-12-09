#pragma once

#ifndef __POSTAGEM_h__
#define __POSTAGEM_h__

//------- Inclusoes

#include <stdio.h>
#include <stdint.h>


//-------- Fim Inclusoes


//-------- Constantes

//-------- Fim Constantes


//-------- Dado Armazenado 

//-------- Fim Dado Armazenado


//-------- Modelagem de Funcoes de Manipulacao e tipos 

typedef char infoPost_t;

//-------- Fim Modelagem de Funcoes de Manipulacao e tipos


//-------- Estrutura 

struct post_s {
	infoPost_t post[50 + 1];

};

typedef struct post_s post_t;	
//-------- Fim Estrutura 


//-------- Assinatura Funcoes 



//-------- Fim Assinatura Funcoes 




#endif //__POSTAGEM_h_
