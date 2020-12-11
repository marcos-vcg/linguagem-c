#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


void Forca () {
	
 int i, contador, n, nchar, e1, e2, e3, e4, e5, certo, animacao, animacao2;
 char frase[100], resposta[100], tentativa, confirmar, continuar;
 
 do{
  system("cls");
  puts("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|        / \\ \n| \n| \n| \n");
  puts("Instrucoes: esse jogo e para ser jogado de duas pessoas. \n A primeira pessoa digita uma palavra e a segunda tenta advinhar.\n");
  confirmar = 'n';
  
  while(confirmar != 'S') {
  	
      certo = 0;
      nchar=0;
      n = 0;
      i=0;
      contador = 0;
      e1 = ' ';
      e2 = ' ';
      e3 = ' ';
      e4 = ' ';
      e5 = ' ';
      printf("\nCertifique-se que o outro jogador nao veja e digite a palavra desejada: ");
      fflush(stdin);
      gets (frase);
      printf("%s, confirmar? (digite 's' para confirmar e 'n' para digitar novamente: ", frase);
      fflush(stdin);
      scanf("%c", &confirmar);
      switch(confirmar)
        {
          case 's':
          printf("O jogo sera iniciado...\n");
          system("PAUSE");
          system("CLS");
          for(i = 0; i < 100; i++)
            {
              resposta[i]='_';
            }
          while(contador < 6)
            {
              n=0;
              certo=0;
              switch(contador) {
                  case 0: printf("___________   \n|         |   \n|        _|_\n|          \n|        \ \n|         \n| \n| \n| \n\n"); 
                          break;
                      
                  case 1: printf("___________   \n|         |   \n|        _|_\n|         O    \n|         \n|       \n| \n| \n| \n\n");
                          break;
                      
                  case 2: printf("___________   \n|         |   \n|        _|_\n|         O    \n|         |    \n|         \n| \n| \n| \n\n");
                          break;
                      
                  case 3: printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|    \n|         \n| \n| \n| \n\n");
                          break;
                      
                  case 4: printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|         \n| \n| \n| \n\n");
                          break;
                      
                  case 5: printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|        /  \n| \n| \n| \n\n");
                          break;
                }
                
              for(i=0; i < 100; i++)
                {
                  if(frase[i]=='\0')
                    {
                      nchar = i;
                      break;
                    }
                  else
                    {
                      if(frase[i]==' ')
                        {
                          resposta[i]=' ';
                          printf("%c", resposta[i]);
                        }
                      else
                        {
                          if(frase[i]==tentativa)
                            {
                              resposta[i]=frase[i];
                            }
                        }
                    }
                  printf("%c ", resposta[i]);    
                }
              printf("\n\n%c %c %c %c %c\n", e1, e2, e3, e4, e5);
              
			  
			  switch(contador) {
                  case 0: puts("\n\nVoce pode errar 5 vezes");
                          break;
                  case 1: puts("\n\nVoce pode errar 4 vezes");
                          break;
                  case 2: puts("\n\nVoce pode errar 3 vezes");
                          break;
                  case 3: puts("\n\nVoce pode errar 2 vezes");
                          break;
                  case 4: puts("\n\nVoce pode errar apenas mais uma vez");
                          break;
                  case 5: puts("\n\nSe errar agora morre!!!!");
                }
                
                
                for(i = 0; i <= nchar; i++)
                {
                 if(tentativa!=' ')
                   {
                    if(resposta[i]!='_')
                      {
                        certo++;
                        if(certo==nchar)
                          {
                            contador=7;                          
                            break;
                          }
                      }
                   }
                }
              if(certo!=nchar)
              {
              printf("\n\nDigite uma letra: ");
              fflush(stdin);
              scanf("%c", &tentativa);
              tentativa = tolower(tentativa);
              }
              for(i = 0; i < nchar; i++)
                {
                  if(tentativa!=frase[i])
                    {
                      n++;
                      if(n==nchar)
                        {
                          contador++;
                          if(contador==1) 
                            {
                              e1 = tentativa;
                            }
                          if(contador==2) 
                            {
                              e2 = tentativa;
                            }
                          if(contador==3) 
                            {
                              e3 = tentativa;
                            }
                          if(contador==4) 
                            {
                              e4 = tentativa;
                            }
                          if(contador==5) 
                            {
                              e5 = tentativa;
                            }
                        }
                    }
              }
              system("cls");
            }
          default: confirmar = 'n'; 
        }
      
	  if(contador==6)
        {
          printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|        / \\ \n| \n| \n| \n\n");
          for(i = 0; i < nchar; i++)
            {
              if(resposta[i]==frase[i])
                {
                  printf("%c ", resposta[i]);
                }
              else
                {
                  printf("(%c) ", frase[i]);
                }
            }
          printf("\n\n%c %c %c %c %c %c\n", e1, e2, e3, e4, e5, tentativa);
          printf("\n\n\nVocê Morreu!!!!\n");
          system("PAUSE");
        }
      
	  if(contador==7)
        {
          for(animacao=0;animacao<7;animacao++)
            {
              for(animacao2=0;animacao2<5;animacao2++)
              {
                system("cls");
                printf("Parabens!! Voce Venceu!!\n");
                printf("___________ \n|         | \n|        _|_\n|\n|\n|         O \n|        /|\\ \n|        / \\\n|\n\n");
              }
              for(animacao2=0;animacao2<5;animacao2++)
              {
                system("cls");
                printf("Parabens!! Voce Venceu!!\n");
                printf("___________ \n|         | \n|        _|_\n|\n|\n|\n|        _O_\n|         | \n|        / \\\n\n");                
              }
              for(animacao2=0;animacao2<5;animacao2++)
              {
                system("cls");
                printf("Parabens!! Voce Venceu!!\n");
                printf("___________ \n|         | \n|        _|_\n|\n|\n|        \\O/\n|         | \n|        / \\\n|\n\n");
              }
            }
            
          system("cls");
          printf("Parabens!! Voce Venceu!!\n");
          printf("___________ \n|         | \n|        _|_\n|\n|\n|\n|        \\O/\n|         | \n|        / \\\n\n");
          tentativa='_';
        }
        
      confirmar = 'S';
      printf("Deseja jogar novamente (S/N)? ");
      fflush(stdin);
      continuar = toupper(getchar());
    }
    
 }while(continuar=='S');
 
 system("PAUSE");

}



// Aqui o código do Jogo da Velha




void tabuleiro (char casas2[9]){
      system("cls");
      
      printf("\nInstrucoes:\n");
	  printf ("\n1- A primeira jogada sera do 'X', e a segunda do 'O', e assim sucessivamente.");
	  printf ("\n2- Faca a sua jogada digitandio o numero da casa desejada de acordo com o exemplo.");
	  printf ("\n3- O primeiro jogador a fazer um trio na horizontal, na diagonal ou na vertical, ganha o jogo.");
	  printf ("\n4- Caso niguem consiga fazer o trio, o jogo dara empate!\n\n");
      
      
      
      
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


int jogo_velha(){
	
	char casas [9] = {'1','2','3','4','5','6','7','8','9'};    
	tabuleiro (casas);
	char res;
	int cont_jogadas,jogada,vez = 0,i;   	  
 
    
	// limpa com espaço todas as casas.  
	do{          
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
	        }else if (casas[jogada-1] != ' '){
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
	        
		    //Determina quem ganha    
			if (casas[0]== 'X' && casas [1]== 'X' && casas[2]=='X') {cont_jogadas = 11;}  
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





// Jogo do Jokenpo
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


// Função Main carrega o menu principal
int main(int argc, char const *argv[]){
    Menu ();
}


