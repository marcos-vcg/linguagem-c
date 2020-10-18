#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

FILE *arq, *bkp, *temp;



void Cadastrar() {
	arq = fopen("dados.txt","a");
	
	if (arq == NULL){
		printf("ERRO! O arquivo não foi aberto!\n"); // Caso dê algum erro no momento de abertura do arquivo, aparece essa menssagem.
	} else {
	
		char ip[20], pc[20], so[20], versao[20], responsavel[20], setor[20];
		printf("****Cadastrar um novo computador****\n");
		
		printf("Informe o IP da maquina: ");
		scanf("%s", &ip);
		
		printf("Informe o nome da maquina: ");
		scanf("%s", &pc);
		
		printf("Informe o SO instalado na maquina: ");
		scanf("%s", &so);
		
		printf("Informe a versao do SO instalada: ");
		scanf("%s", &versao);
		
		printf("Informe o usuario responsavel pela maquina: ");
		scanf("%s", &responsavel);
		
		printf("Em qual setor o PC esta instalado: ");
		scanf("%s", &setor);
		
		fprintf(arq, "%s ; s ; %s ; %s ; %s ; %s\n", ip, pc, so, versao, responsavel, setor);
		fclose(arq);
		
	  	printf("\n");
	  	printf("************************************\n");
		printf("Cadastro do computador efetuado com sucesso!\n");
		printf("************************************\n");
		
	  	sleep(3);
  	}
}

void Consultar(){
	char consulta[20];
	printf("****Consultar um computador****\n");
	printf("Informe o IP do computador: ");
	scanf("%s", &consulta);
	
	char ip[20], pc[20], so[20], versao[20], responsavel[20], setor[20], registro[200];
	int cont = 0;
	arq = fopen("dados.txt", "r");

	if (arq == NULL){
		printf("ERRO! O arquivo não foi aberto!\n");
	} else {
	  	while(!feof(arq)){
	    	setbuf(stdin,NULL);
			fscanf(arq, "%s ; %s ; %s ; %s ; %s ; %s", &ip, &pc, &so, &versao, &responsavel, &setor);
	    
		    if(!strcmp(ip, consulta)){
		      printf("\nIP da maquina: %s", ip);
		      printf("\nNome da maquina: %s", pc);
		      printf("\nSO da maquina: %s", so);
		      printf("\nVersao do SO: %s", versao);
		      printf("\nUsuario responsavel: %s", responsavel);
		      printf("\nSetor que o PC esta instalado: %s", setor);
		      printf("\n\n****************************\n\n");
		
		      cont++;
		    }
		    
		    ip[0] = '\0';
			pc[0] = '\0';
			so[0] = '\0';
			versao[0] = '\0';
			responsavel[0] = '\0';
			setor[0] = '\0';
	    
	  	}
	  	
	  	fclose(arq);
		system("pause"); //faz com que o app espere um comando do usuário antes da proxima execução.
  		
	}
	

}

void Alterar(){
	float pIp;
	printf("****Alterar um computador****\n");
	printf("Informe o IP do computador: ");
	scanf("%f", &pIp);
}

void Excluir(){
	float pIp;
	printf("****Excluir um computador****\n");
	printf("Informe o IP do computador: ");
	scanf("%f", &pIp);
}

void Listar(){
	printf("****Listar todos os computadores****\n");
	printf("A lista dos computadores cadastrados é:\n");

	char ip[20], pc[20], so[20], versao[20], responsavel[20], setor[20], registro[200];
	int cont = 0;
	arq = fopen("dados.txt", "r");

	if (arq == NULL){
		printf("ERRO! O arquivo não foi aberto!\n");
	} else {
	  	while(!feof(arq)){
	    	setbuf(stdin,NULL);
			fscanf(arq, "%s ; %s ; %s ; %s ; %s ; %s", &ip, &pc, &so, &versao, &responsavel, &setor);
	    
		    if(ip[0] != '\0'){
		      printf("\nIP da maquina: %s", ip);
		      printf("\nNome da maquina: %s", pc);
		      printf("\nSO da maquina: %s", so);
		      printf("\nVersao do SO: %s", versao);
		      printf("\nUsuario responsavel: %s", responsavel);
		      printf("\nSetor que o PC esta instalado: %s", setor);
		      printf("\n\n****************************\n\n");
		
		      cont++;
		      ip[0] = '\0';
			  pc[0] = '\0';
			  so[0] = '\0';
			  versao[0] = '\0';
			  responsavel[0] = '\0';
			  setor[0] = '\0';
		    }
	    
	  	}
	  	
	  	fclose(arq);
		system("pause"); //faz com que o app espere um comando do usuário antes da proxima execução.
  		
	}

  
}

void Backup(){
	printf("****Gerar backup****\n");
	printf("Gerando beckup:\n");
}

void Sair(){
	printf("****SAIR****\n");
	printf("Obrigado e volte sempre!");
}


void Menu(){
	int opcao;
  do{
  	system("clear||cls");
	printf("****Bem-vindos ao sistema CADTI****\n");
    printf("********* Menu do sistema**********\n");
    printf("1 - Cadastrar um novo computador\n");
    printf("2 - Consultar um computador\n");
    printf("3 - Alterar um computador\n");
    printf("4 - Excluir um computador\n");
    printf("5 - Listar todos os computadores\n");
    printf("6 - Gerar backup\n");
    printf("0 - Sair\n");
    printf("************************************\n");
    printf("Digite aqui o que deseja fazer: ");
	  scanf("%d", &opcao);
	  system("clear||cls");

    switch (opcao) {
      case (1): 	
        Cadastrar();
      break;
      case (2):
        Consultar();
      break;
      case (3):
        Alterar();
      break;
      case (4):
        Excluir();
      break;
      case (5):
        Listar();
      break;
      case (6):
        Backup();
      break;
      case (0):
        Sair();
      break;
      default: printf("Opcao Invalida!");
      break;
    }
  } while(opcao != 0);
}


int main(int argc, char const *argv[])
{
    Menu ();
}