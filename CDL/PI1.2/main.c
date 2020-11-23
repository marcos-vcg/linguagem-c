#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include<locale.h>
#include<string.h>

/* Este programa é um conjunto dos 3 jogos mais populares de todos os tempos */

// Primeiro vamos colocar o jogo da forca


// Declaração das variáveis do jogo de Forca
typedef struct{
    char palavra[100];
    struct Palavra *prox;
}Palavra;
Palavra *primeiraPalavra;
Palavra *ultimaPalavra;
int tamanho;


// Chamar as funções no começo do código para serem usadas 
void VerificaChances(int contador);
void MensagemVitoria(char tentativa);
void DesenhaForca(int contador,int flagInicio);
void MostrarLetrasErradas(int erro1,int erro2,int erro3,int erro4,int erro5,char tentativa,int contador);
void VerificaTentativa(char qtdCaracter,char tentativa,int *certo,int *contador,char resposta[]);
void CapturaLetra(char *tentativa);
void VerificaSeErrou(char frase[],int qtdCaracter,int *contador,char tentativa,int *erro1,int *erro2,int *erro3,int *erro4,int *erro5,int *n);
int MenurPrincipal();
char* BuscarPalavra(char nomeArquivo[]);
void CriarListaVazia();
void InseriNaLista(Palavra palavra);
int SorteiaPalavra(int faixa);
void limparLista();


// Função principal do Jogo de Forca
int Forca (){
    setlocale(LC_ALL, "Portuguese");
    int i, contador, n, qtdCaracter, erro1, erro2, erro3, erro4, erro5, certo,opcao;
    char frase[100], resposta[100], tentativa, confirmar, continuar;
    do {
        system("cls");
        DesenhaForca(contador,1);
 		strcpy(frase,BuscarPalavra("lista.txt"));
        certo = 0;
        qtdCaracter=0;
        n = 0;
        i=0;
        contador = 0;
        erro1 = ' ';
        erro2 = ' ';
        erro3 = ' ';
        erro4 = ' ';
        erro5 = ' ';
        tentativa=' ';
        printf("O jogo sera iniciado...\n");
        system("PAUSE");
        system("CLS");
        for(i = 0; i < 100; i++){
            resposta[i]='_';
        }
        
        while(contador < 6){
            n=0;
            certo=0;
            DesenhaForca(contador,0);

            for(i=0; i < 100; i++){
                if(frase[i]=='\0'){
                    qtdCaracter = i;
                    break;
                } else {
                    if(frase[i]==' ') {
                        resposta[i]=' ';
                        printf("%c", resposta[i]);
                    } else {
                        if(frase[i]==tentativa) {
                            resposta[i]=frase[i];
                        }
                    }
                }
                printf("%c ", resposta[i]);
            }

            MostrarLetrasErradas(erro1,erro2,erro3,erro4,erro5,tentativa,contador);
            VerificaChances(contador);
            VerificaTentativa(qtdCaracter,tentativa,&certo,&contador,resposta);
            if(certo!=qtdCaracter){
                CapturaLetra(&tentativa);
            }
            VerificaSeErrou(frase,qtdCaracter,&contador,tentativa,&erro1,&erro2,&erro3,&erro4,&erro5,&n);

            system("cls");
        }

        if(contador==6){
            DesenhaForca(contador,0);
            for(i = 0; i < qtdCaracter; i++){
                if(resposta[i]==frase[i]){
                    printf("%c ", resposta[i]);
                } else {
                    printf("(%c) ", frase[i]);
                }
            }
            MostrarLetrasErradas(erro1,erro2,erro3,erro4,erro5,tentativa,contador);
            printf("\n\n\nVoçê Morreu !!!!\n");
            system("PAUSE");
        }
        
        if(contador==7){
           MensagemVitoria(tentativa);
        }
        
        confirmar = 'S';
        printf("Deseja jogar novamente (S/N)? ");
        fflush(stdin);
        continuar = toupper(getchar());     
   
    } while(continuar=='S');
    
	system("PAUSE");
    return 0;
}


// Função que mostra quantas chances ainda restam
void VerificaChances(int contador){
    switch(contador){
	    case 0:
	        puts("\n\nVoce pode errar 5 vezes");
	        break;
	    case 1:
	        puts("\n\nVoce pode errar 4 vezes");
	        break;
	    case 2:
	        puts("\n\nVoce pode errar 3 vezes");
	        break;
	    case 3:
	        puts("\n\nVoce pode errar 2 vezes");
	        break;
	    case 4:
	        puts("\n\nVoce pode errar apenas mais uma vez");
	        break;
	    case 5:
	        puts("\n\nSe errar agora você morre!!!!");
    }
}


// Função que mostra a mensagem de vitória
void MensagemVitoria(char tentativa){
	printf("\n******************************************************");
	printf("\n***********          PARABÉNS            *************");
	printf("\n***********            VOCÊ              *************");
	printf("\n***********           VENCEU             *************");
	printf("\n******************************************************\n");

    tentativa='_';
}


// Função que desenha a forca
void DesenhaForca(int contador,int flagInicio){
    if(flagInicio==0){
        switch(contador){
	        case 0:
	            printf("____________   \n||         |   \n||        _|_\n||          \n||        \ \n||         \n|| \n|| \n|| \n\n");
	            break;
	        case 1:
	            printf("____________   \n||         |   \n||        _|_\n||         O    \n||         \n||       \n|| \n|| \n|| \n\n");
	            break;
	        case 2:
	            printf("############   \n||         |   \n||        _|_\n||         O    \n||         |      \n||         *\n|| \n|| \n|| \n\n");
	            break;
	        case 3:
	            printf("############   \n||         |   \n||        _|_\n||         O    \n||        /|      \n||         *\n|| \n|| \n|| \n\n");
	            break;
	        case 4:
	            printf("############   \n||         |   \n||        _|_\n||         O    \n||        /|\\    \n||         *\n|| \n|| \n|| \n\n");
	            break;
	        case 5:
	            printf("############   \n||         |   \n||        _|_\n||         O    \n||        /|\\    \n||        /* \n||  \n||  \n|| \n\n");
	            break;
	        case 6:
	            printf("############   \n||         |   \n||        _|_\n||         O    \n||        /|\\    \n||        /*\\ \n||  \n||  \n|| \n\n");
	            break;
        }
    } else {
        puts("############ \n||         |   \n||        _|_\n||         O    \t  \n||        /|\\    \n||        /*\\      \n||       \t       \n||     \t           \n|| \n|| \n|| \n");
    }
}


// Função que mostra as letras erradas
void MostrarLetrasErradas(int erro1,int erro2,int erro3,int erro4,int erro5,char tentativa, int contador){
    if(contador==6) {
    	printf("\n\n%c %c %c %c %c %c\n", erro1, erro2, erro3, erro4, erro5, tentativa);
    } else{
        printf("\n\n%c %c %c %c %c\n", erro1, erro2, erro3, erro4, erro5);
    }
}


// Função que verifica a tentativa
void VerificaTentativa(char qtdCaracter,char tentativa,int *certo,int *contador,char resposta[]){
    int i;
    for(i = 0; i <= qtdCaracter; i++){
        if(tentativa!=' '){
            if(resposta[i]!='_'){
                *certo=*certo+1;
                if(*certo==qtdCaracter){
                    *contador=7;
                    break;
                }
            }
        }
    }
}


// Função que captura a letra digitada da tentativa e passa para lower case
void CapturaLetra(char *tentativa){
    char tecla;
    printf("\n\nDigite uma letra: ");
    fflush(stdin);
    scanf("%c",&tecla);
    *tentativa = tecla;
    *tentativa = tolower(*tentativa);
}


// Função que faz a verificação se acertou a letra digitada
void VerificaSeErrou(char frase[],int qtdCaracter,int *contador,char tentativa,int *erro1,int *erro2,int *erro3,int *erro4,int *erro5,int *n){
    int i;
    for(i = 0; i < qtdCaracter; i++){
        if(tentativa!=frase[i]){
            *n=*n+1;
            if(*n==qtdCaracter){
                *contador=*contador+1;
                if(*contador==1){
                    *erro1 = tentativa;
                }
                if(*contador==2){
                    *erro2 = tentativa;
                }
                if(*contador==3){
                    *erro3 = tentativa;
                }
                if(*contador==4){
                    *erro4 = tentativa;
                }
                if(*contador==5){
                    *erro5 = tentativa;
                }
            }
        }
    }
}


// Função que busca uma palavra no arquivo informado
char* BuscarPalavra(char nomeArquivo[]){
    FILE *pont_arq;
    char linha[1024]; // variável do tipo string
    char palavraSorteada[100];
    Palavra palavra;
    pont_arq = fopen(nomeArquivo, "r");
    
	// Testa se conseguiu abrir o arquivo
	if(pont_arq == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    int i=0;
    tamanho=0;
    CriarListaVazia();
    while(fscanf(pont_arq, " %[^\n]s",linha) != EOF){
        char *ptr;
        ptr = strtok(linha,";");
        strcpy(palavra.palavra,ptr);
        ptr = strtok(NULL,";");
        InseriNaLista(palavra);
        tamanho++;
    }
    fclose(pont_arq);

    Palavra lista[tamanho-1];
    Palavra *palavraAux;
    palavraAux=primeiraPalavra->prox;
    i=0;
    int numero = SorteiaPalavra(tamanho-1);
    while(palavraAux!= NULL){
        if(i==numero){
             strcpy( palavraSorteada,palavraAux->palavra);
        }
        palavraAux=palavraAux->prox;
        i++;
    }
    limparLista();
    return palavraSorteada;
}


// Função que cria uma lista vazia com alocação de meméria dinamicamente de acordo com tamanho da palavra
void CriarListaVazia(){
    primeiraPalavra = (Palavra *)malloc(sizeof(Palavra));
    ultimaPalavra = primeiraPalavra;
}


// Função que insere na lista uma palavra
void InseriNaLista(Palavra palavra){
    Palavra *palavraAux;
    palavraAux = (Palavra *)malloc(sizeof(Palavra));

    strcpy( palavraAux->palavra,palavra.palavra);

    ultimaPalavra->prox = palavraAux;
    ultimaPalavra = ultimaPalavra->prox;
    palavraAux->prox = NULL;
}


// Função que faz o sorteio de uma palavra
int SorteiaPalavra(int faixa){
    srand( (unsigned)time(NULL) );
    return  rand() % faixa;
}


// Função que remove todos os nós da Lista
void limparLista(){
    Palavra *no = primeiraPalavra, *aux;
    while (no != NULL){
        aux = no;
        no = no->prox;
        free (aux);
    }
    primeiraPalavra = NULL;
    ultimaPalavra=NULL;
}




// Aqui o código do Jogo da Velha






// Aqui o código do JokenPo







// Menu Sair
void Sair(){
	
	printf("\n ************ SAIR ************");
	printf("\n ******************************\n");
	printf(" - Obrigado e volte sempre!\n");
	
	//system("pause"); //faz com que o app espere um comando do usuario antes da proxima execucao.
}


// Menu principal da aplicação chamado ao carregar o Main
void Menu(){
	
	int opcao;
  	do {
	  	system("clear||cls");
		printf(" ***** Bem-vindos ao FCDL-Games *****\n");
	    printf(" ********* Menu dos Jogos ***********\n");
	    printf(" * 1 - Forca                        *\n");
	    printf(" * 2 - Jogo da Velha                *\n");
	    printf(" * 3 - JokenPo                      *\n");
	    printf(" * 0 - Sair                         *\n");
	    printf(" ************************************\n"); 
		printf(" Digite aqui o que deseja fazer: ");
		scanf("%d", &opcao);
		system("clear||cls");

	    switch (opcao) {
			case (1): 	
				Forca();
			break;
		
			case (2):
				//Consultar();
			break;
		
			case (3):
				//Alterar();
			break;

			case (0):
				Sair();
			break;
			default: printf("Opcao Invalida!");
			break;
	    }
	    
    } while(opcao != 0);
}


// Função Main carrega o menu principal
int main(int argc, char const *argv[]){
    Menu ();
}


