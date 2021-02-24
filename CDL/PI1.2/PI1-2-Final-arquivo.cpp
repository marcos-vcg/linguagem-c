#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include<locale.h>
#include<string.h>

/* Este programa � um conjunto dos 3 jogos mais populares de todos os tempos 
   
   Projeto Integrado 2 - Desenvolvido por:
   2020012061 - Marcos Vin�cius Costa Gomes
   2020011810 - Douglas Viana Lima
   2020011821 - Jonatha de Araujo

*/

// Primeiro vamos colocar o jogo da forca


// Declara��o das vari�veis do jogo de Forca
typedef struct{
    char palavra[100];
    struct Palavra *prox;
}Palavra;
Palavra *primeiraPalavra;
Palavra *ultimaPalavra;
int tamanho;


// Chamar as fun��es no come�o do c�digo para serem usadas 
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


// Fun��o principal do Jogo de Forca
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
            printf("\n\n\nVo�� Morreu !!!!\n");
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


// Fun��o que mostra quantas chances ainda restam
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
	        puts("\n\nSe errar agora voc� morre!!!!");
    }
}


// Fun��o que mostra a mensagem de vit�ria
void MensagemVitoria(char tentativa){
	printf("\n******************************************************");
	printf("\n***********          PARAB�NS            *************");
	printf("\n***********            VOC�              *************");
	printf("\n***********           VENCEU             *************");
	printf("\n******************************************************\n");

    tentativa='_';
}


// Fun��o que desenha a forca
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


// Fun��o que mostra as letras erradas
void MostrarLetrasErradas(int erro1,int erro2,int erro3,int erro4,int erro5,char tentativa, int contador){
    if(contador==6) {
    	printf("\n\n%c %c %c %c %c %c\n", erro1, erro2, erro3, erro4, erro5, tentativa);
    } else{
        printf("\n\n%c %c %c %c %c\n", erro1, erro2, erro3, erro4, erro5);
    }
}


// Fun��o que verifica a tentativa
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


// Fun��o que captura a letra digitada da tentativa e passa para lower case
void CapturaLetra(char *tentativa){
    char tecla;
    printf("\n\nDigite uma letra: ");
    fflush(stdin);
    scanf("%c",&tecla);
    *tentativa = tecla;
    *tentativa = tolower(*tentativa);
}


// Fun��o que faz a verifica��o se acertou a letra digitada
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


// Fun��o que busca uma palavra no arquivo informado
char* BuscarPalavra(char nomeArquivo[]){
    FILE *pont_arq;
    char linha[1024]; // vari�vel do tipo string
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


// Fun��o que cria uma lista vazia com aloca��o de mem�ria dinamicamente de acordo com tamanho da palavra
void CriarListaVazia(){
    primeiraPalavra = (Palavra *)malloc(sizeof(Palavra));
    ultimaPalavra = primeiraPalavra;
}


// Fun��o que insere na lista uma palavra
void InseriNaLista(Palavra palavra){
    Palavra *palavraAux;
    palavraAux = (Palavra *)malloc(sizeof(Palavra));

    strcpy( palavraAux->palavra,palavra.palavra);

    ultimaPalavra->prox = palavraAux;
    ultimaPalavra = ultimaPalavra->prox;
    palavraAux->prox = NULL;
}


// Fun��o que faz o sorteio de uma palavra
int SorteiaPalavra(int faixa){
    srand( (unsigned)time(NULL) );
    return  rand() % faixa;
}


// Fun��o que remove todos os n�s da Lista
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




// Aqui o c�digo do Jogo da Velha

void regras_velha (){ 
	printf("\nInstrucoes:\n");
	printf ("\n1- No primeiro jogo o 'X' inicia a partida.");
	printf ("\n2- Faca a sua jogada digitandio o numero da casa desejada de acordo com o exemplo.");
	printf ("\n3- O primeiro jogador a fazer um trio na horizontal, na diagonal ou na vertical, ganha o jogo.");
	printf ("\n4- Caso niguem consiga fazer o trio, o jogo dara empate!");
	printf ("\n5- Ao terminio da partida, se o 'X' for o ultimo a jogar o 'O' passa a ser o primeiro na segunda partida.\n\n");
}


void tabuleiro (char casas2[9]){
      system("cls");
      int casa1= 1 ,casa2= 2 ,casa3= 3 ,casa4= 4 ,casa5= 5 ,casa6= 6 ,casa7= 7 ,casa8= 8 ,casa9= 9;
      printf ("\nExemplo de posicoes das casas no tabuleiro:\n\n ");
      printf ("\t %i | %i | %i \n",casa1,casa2,casa3);
      printf ("\t-----------\n");
      printf ("\t %i | %i | %i \n",casa4,casa5,casa6);
      printf ("\t-----------\n");
      printf ("\t %i | %i | %i \n",casa7,casa8,casa9);
          
      printf("\n******************************************\n\n"); //tabuleiro que sera uzado para prencher com as jogadas
	      
      printf ("\t %c | %c | %c \n",casas2 [0],casas2 [1],casas2[2]);
      printf ("\t-----------\n");
      printf ("\t %c | %c | %c \n",casas2 [3],casas2 [4],casas2[5]);
      printf ("\t-----------\n");
      printf ("\t %c | %c | %c \n",casas2 [6],casas2 [7],casas2[8]);               
    }

void jogo_velha(){	  
      char casas [9] = {'1','2','3','4','5','6','7','8','9'};    
      tabuleiro (casas);
      char res;
      int cont_jogadas,jogada,vez = 0,i;   	  
 
     do{ // limpa com espa�o todas as casas.
          cont_jogadas = 1;
          for (i=0;i<=8;i++){
         casas[i] = ' ';
        }
     do{
          tabuleiro(casas);
          printf ("\nDigite a casa para marcar[1-9]: ");
          scanf("%i",&jogada);
          
		  if (jogada < 1 || jogada > 9){
              jogada = 0;
            }
			else if (casas[jogada-1] != ' '){
                  jogada = 0;
                }else{
                      if (vez %2==0){
                          casas [jogada-1]= 'X';
                        }else{
                              casas [jogada-1]= 'O';
                            }
                      cont_jogadas++;
                      vez++;
                    }
   if (casas[0]== 'X' && casas [1]== 'X' && casas[2]=='X') {cont_jogadas = 11;}  //Determina quem ganha
   if (casas[3]== 'X' && casas [4]== 'X' && casas[5]=='X') {cont_jogadas = 11;}
   if (casas[6]== 'X' && casas [7]== 'X' && casas[8]=='X') {cont_jogadas = 11;}
   if (casas[0]== 'X' && casas [3]== 'X' && casas[6]=='X') {cont_jogadas = 11;}
   if (casas[1]== 'X' && casas [4]== 'X' && casas[7]=='X') {cont_jogadas = 11;}
   if (casas[2]== 'X' && casas [5]== 'X' && casas[8]=='X') {cont_jogadas = 11;}
   if (casas[0]== 'X' && casas [4]== 'X' && casas[8]=='X') {cont_jogadas = 11;}
   if (casas[2]== 'X' && casas [4]== 'X' && casas[6]=='X') {cont_jogadas = 11;}
   
   if (casas[0]== 'O' && casas [1]== 'O' && casas[2]=='O') {cont_jogadas = 12;}
   if (casas[3]== 'O' && casas [4]== 'O' && casas[5]=='O') {cont_jogadas = 12;}
   if (casas[6]== 'O' && casas [7]== 'O' && casas[8]=='O') {cont_jogadas = 12;}
   if (casas[0]== 'O' && casas [3]== 'O' && casas[6]=='O') {cont_jogadas = 12;}
   if (casas[1]== 'O' && casas [4]== 'O' && casas[7]=='O') {cont_jogadas = 12;}
   if (casas[2]== 'O' && casas [5]== 'O' && casas[8]=='O') {cont_jogadas = 12;}
   if (casas[0]== 'O' && casas [4]== 'O' && casas[8]=='O') {cont_jogadas = 12;}
   if (casas[2]== 'O' && casas [4]== 'O' && casas[6]=='O') {cont_jogadas = 12;}
   
   
   
   
   
   
  }while (cont_jogadas <= 9);
  tabuleiro(casas);
  if(cont_jogadas==10){
   printf ("\nDeu velha - Jogo empatado!\n");
  }if (cont_jogadas==11){
   printf ("\nVencedor X!!\n");
  }if(cont_jogadas==12){
   printf ("\nVencedor O!!\n");
   
  }
  printf ("\nDeseja jogar novamente?[S-N]\n");
  scanf ("%s",&res);
 }while(res=='s');
 return 0;
 
}




// Aqui o c�digo do JokenPo

int Jokenpo() {
	
	int jogador, cpu;
	int pontos_jogador=0, pontos_cpu=0;
	
	
	do {
		printf ("---JokenPo---\n");
		printf ("%d Jogador X CPU %d\n", pontos_jogador, pontos_cpu);
		printf ("-------------\n");
		printf ("0. Pedra\n");
		printf ("1. Papel\n");
		printf ("2. Tesoura\n");
		printf ("9. Sair\n");
		printf ("\nOpcao: ");
		scanf ("%d", &jogador);
      
      
      	if (jogador == 9){
      		return 0;
		}else if (jogador == 0 || jogador == 1 || jogador == 2 ){
		  			  
      	} else{
      		
      	  	printf ("Opcao invalida!\n");		  
		  	system ("pause");
          	system ("cls");
		  	continue;
		}
	
	
	    //gera um numero aleatorio
	    srand(time(NULL));
	    cpu = rand() % 3; 
	    
		switch(cpu) {
	        case 0: printf ("\nCPU -> Pedra\n"); break;
	        case 1: printf ("\nCPU -> Papel\n"); break;
	        case 2: printf ("\nCPU -> Tesoura\n"); break;
	    }
    
    
	    //verifica se o jogador venceu
	    if ((jogador == 0 && cpu==2) || (jogador == 1 && cpu == 0) || (jogador == 2 && cpu == 1)) {	        
			printf("\nVoce venceu!\n");
	        pontos_jogador++;
	        system ("pause");
	        system ("cls");   
	    }else if (jogador == cpu) { //verifica se houve empate
	        printf ("\nEmpate!\n");
	        system ("pause");
	        system ("cls");
		} else {
	        printf ("\nCPU venceu!\n");
	        pontos_cpu++;
	        system ("pause");
	        system ("cls");
	    }
		        		  
    } while (jogador != 9);
            
	return 0;
}





// Menu Sair
void Sair(){
	
	printf("\n ************ SAIR ************");
	printf("\n ******************************\n");
	printf(" - Obrigado e volte sempre!\n");
	
	//system("pause"); //faz com que o app espere um comando do usuario antes da proxima execucao.
}


// Menu principal da aplica��o chamado ao carregar o Main
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
			    regras_velha();
			    system("pause");
				jogo_velha();
			break;
		
			case (3):
				Jokenpo();
			break;

			case (0):
				Sair();
			break;
			default: printf("Opcao Invalida!");
			break;
	    }
	    
    } while(opcao != 0);
}


// Fun��o Main carrega o menu principal
int main(int argc, char const *argv[]){
    Menu ();
}


