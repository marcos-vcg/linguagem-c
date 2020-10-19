#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

FILE *arq, *bkp, *temp;


void Cadastrar() {
	arq = fopen("dados.txt","a");
	
	if (arq == NULL){
		printf("ERRO! O arquivo nao foi aberto!\n"); // Caso dê algum erro no momento de abertura do arquivo, aparece essa menssagem.
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
		
		fprintf(arq, "%s ; %s ; %s ; %s ; %s ; %s\n", ip, pc, so, versao, responsavel, setor);
		fclose(arq);
		
	  	printf("\n");
	  	printf("************************************\n");
		printf("Cadastro do computador efetuado com sucesso!\n");
		printf("************************************\n");
		
	  	sleep(3);
  	}
}

void Consultar(){
	char busca[20];
	printf("****Consultar um computador****\n");
	printf("Informe o IP do computador: ");
	scanf("%s", &busca);
	
	char ip[20], pc[20], so[20], versao[20], responsavel[20], setor[20], registro[200];
	int cont = 0;
	arq = fopen("dados.txt", "r");

  	while(!feof(arq)){
    	setbuf(stdin,NULL);
		fscanf(arq, "%s ; %s ; %s ; %s ; %s ; %s", &ip, &pc, &so, &versao, &responsavel, &setor);
    
	    if(strcmp(ip, busca) == 0){
			printf("\n*******************************************");
			printf("\nIP da maquina: %s", ip);
			printf("\nNome da maquina: %s", pc);
			printf("\nSO da maquina: %s", so);
			printf("\nVersao do SO: %s", versao);
			printf("\nUsuario responsavel: %s", responsavel);
			printf("\nSetor que o PC esta instalado: %s", setor);
			printf("\n*******************************************\n");
			
			cont++;
	    }
	    
	    ip[0] = '\0';
		pc[0] = '\0';
		so[0] = '\0';
		versao[0] = '\0';
		responsavel[0] = '\0';
		setor[0] = '\0';
  	}
  	
  	if(cont == 0) {
  		printf("\n*******************************************");	
	  	printf("\nEste IP nao esta cadastrado no sitema!");
	  	printf("\n*******************************************\n");
	}
  	
  	fclose(arq);
	system("pause"); //faz com que o app espere um comando do usuário antes da proxima execução.	
}

void Alterar(){
	char busca[20];
	printf("\n\t****Alterar um computador****\n");
	printf("\n*******************************************");
	printf("\nInforme o IP do computador: ");
	scanf("%s", &busca);
	
	char ip[20], pc[20], so[20], versao[20], responsavel[20], setor[20], texto[1001];
	ip[0] = '\0';
	int linha_selecionada = 0;
	int linha_atual = 1;
	
	arq = fopen("dados.txt","r");
	
	while(!feof(arq)){
    	setbuf(stdin,NULL);
		fscanf(arq, "%s ; %s ; %s ; %s ; %s ; %s", &ip, &pc, &so, &versao, &responsavel, &setor);
    
	    if(!strcmp(ip, busca)){
			printf("\n\t****IP Encontrado!****");
			printf("\n*******************************************");
			printf("\nIP da maquina: %s", ip);
			printf("\nNome da maquina: %s", pc);
			printf("\nSO da maquina: %s", so);
			printf("\nVersao do SO: %s", versao);
			printf("\nUsuario responsavel: %s", responsavel);
			printf("\nSetor que o PC esta instalado: %s", setor);
			printf("\n*******************************************\n");
			linha_selecionada = linha_atual; 
			break;
	    }
	    
	    ip[0] = '\0';
		pc[0] = '\0';
		so[0] = '\0';
		versao[0] = '\0';
		responsavel[0] = '\0';
		setor[0] = '\0';
		
		linha_atual += 1;
  	}
  	
  	fclose(arq);
  	
  	
	printf("****Atualizar cadastro do computador****\n");	
	printf("Informe o novo IP da maquina: ");
	scanf("%s", &ip);
	printf("Informe o novo nome da maquina: ");
	scanf("%s", &pc);
	printf("Informe o novo SO instalado na maquina: ");
	scanf("%s", &so);
	printf("Informe a nova versao do SO instalada: ");
	scanf("%s", &versao);
	printf("Informe o novo usuario responsavel pela maquina: ");
	scanf("%s", &responsavel);
	printf("Em qual novo setor o PC esta instalado: ");
	scanf("%s", &setor);
  	
  	
	arq = fopen("dados.txt","r");
	temp = fopen("temp.txt","a");
	
	linha_atual = 1;
	if(linha_selecionada != 0){
  		while (fgets(texto, 1001, arq) != NULL){	
			if(linha_atual != linha_selecionada){
				fputs (texto,temp);	
		  	} else {
		  		fprintf(temp, "%s ; %s ; %s ; %s ; %s ; %s\n", ip, pc, so, versao, responsavel, setor);
			}
		  	memset(texto, 0, sizeof(char) * 1001);
			linha_atual += 1;
    	}
    	
    	fclose(arq);
		fclose(temp);
		remove("dados.txt");
		rename("temp.txt", "dados.txt");
		
		printf("\n\nExclusao do PC efetuada com sucesso!");
  		printf("\n*******************************************\n");	  
    	
	} else {
		printf("\n\t****IP nao Encontrado!****");
		printf("\n\nExclusao do PC nao efetuada!");
  		printf("\n*******************************************\n");
  		
  		fclose(arq);
		fclose(temp);
	}    

	system("pause");
}

void Excluir(){
	
	char busca[20];
	printf("\n\t****Excluir um computador****\n");
	printf("\n*******************************************");
	printf("\nInforme o IP do computador: ");
	scanf("%s", &busca);
	
	char ip[20], pc[20], so[20], versao[20], responsavel[20], setor[20], texto[1001];
	int linha_selecionada = 0;
	int linha_atual = 1;
	
	arq = fopen("dados.txt","r");
	
	while(!feof(arq)){
    	setbuf(stdin,NULL);
		fscanf(arq, "%s ; %s ; %s ; %s ; %s ; %s", &ip, &pc, &so, &versao, &responsavel, &setor);
    
	    if(!strcmp(ip, busca)){
			printf("\n\t****IP Encontrado!****");
			linha_selecionada = linha_atual; 
			break;
	    }
	    
	    ip[0] = '\0';
		pc[0] = '\0';
		so[0] = '\0';
		versao[0] = '\0';
		responsavel[0] = '\0';
		setor[0] = '\0';
		
		linha_atual += 1;
  	}
  	
	fclose(arq);
	arq = fopen("dados.txt","r");
	temp = fopen("temp.txt","a");
	
	
	linha_atual = 1;
	if(linha_selecionada != 0){
  		while (fgets(texto, 1001, arq) != NULL){	
			if(linha_atual != linha_selecionada){
				fputs (texto,temp);	
		  	}
		  	memset(texto, 0, sizeof(char) * 1001);
			linha_atual += 1;
    	}
    	
    	fclose(arq);
		fclose(temp);
		remove("dados.txt");
		rename("temp.txt", "dados.txt");
		
		printf("\n\nExclusao do PC efetuada com sucesso!");
  		printf("\n*******************************************\n");	  
    	
	} else {
		printf("\n\t****IP nao Encontrado!****");
		printf("\n\nExclusao do PC nao efetuada!");
  		printf("\n*******************************************\n");
  		
  		fclose(arq);
		fclose(temp);
	}    

	sleep(3);
}

void Listar(){
	printf("****Listar todos os computadores****\n");
	printf("A lista dos computadores cadastrados e:\n");

	char ip[20], pc[20], so[20], versao[20], responsavel[20], setor[20], registro[200];
	ip[0] = '\0';
	int cont = 0;
	arq = fopen("dados.txt", "r");

	
  	while(!feof(arq)){
    	setbuf(stdin,NULL);
		fscanf(arq, "%s ; %s ; %s ; %s ; %s ; %s", &ip, &pc, &so, &versao, &responsavel, &setor);
    
	    if(ip[0] != '\0'){
			printf("\n*******************************************");
			printf("\nIP da maquina: %s", ip);
			printf("\nNome da maquina: %s", pc);
			printf("\nSO da maquina: %s", so);
			printf("\nVersao do SO: %s", versao);
			printf("\nUsuario responsavel: %s", responsavel);
			printf("\nSetor que o PC esta instalado: %s", setor);
			printf("\n*******************************************\n");
			
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

void Backup(){
	printf("\n\t****Gerar backup****\n");
	printf("\n*******************************************");
	
	char linha[2000];
	arq = fopen("dados.txt", "r");
	bkp = fopen("bkp.txt","w");
	
	if (arq==NULL || bkp==NULL){
        printf("ERRO na abertura do arquivo. O programa ser� fechado!\n");
        system("pause");
        exit(1);
    } else {
		while (fgets(linha,2000,arq) != NULL){
		  fputs (linha,bkp);		           
	    }	    
	  printf("\nBeckup do arquivo gerado com sucesso!");
	  printf("\n*******************************************\n");
	  system("pause");	  
	}
	
	fclose(arq);
	fclose(bkp);
}

void Sair(){
	printf("****SAIR****\n");
	printf("Obrigado e volte sempre!");
}


void Menu(){
	int opcao;
  	do {
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
	arq = fopen("dados.txt", "a");
	fclose(arq);
    Menu ();
}

