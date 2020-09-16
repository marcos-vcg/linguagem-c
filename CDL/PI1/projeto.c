#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int opcao = Menu ();
    SubMenu(opcao);
}


int Menu (){
	int opcao;
	printf("****Bem-vindos ao sistema CADTI****\n");
    printf("********* Menu do sistema**********\n");
    printf("1 - Cadastrar um novo computador\n");
    printf("2 - Consultar um computador\n");
    printf("3 - Alterar um computador\n");
    printf("4 - Excluir um computador\n");
    printf("5 - Listar todos os computadores\n");
    printf("6 - Gerar backup\n");
    printf("9 - Sair\n");
    printf("************************************\n");
    printf("Digite aqui o que deseja fazer: ");
    scanf("%d", &opcao);
    printf("\n");
    return(opcao);
}

int SubMenu (int vl_opcao) {
	int opcao = vl_opcao;
	
	typedef struct {
    	char ip[15];
    	char pc[15]; 
		char so[10];
		char versao[10];
		char responsavel[20]; 
		char setor[15]; 
		char lista[50];
	} cad;
	cad comp[20];
	int id = 0;
	
	switch (opcao) {
		case 1: 	
			printf("****Cadastrar um novo computador****\n");
			id++;
			cad comp[id];			
			printf("Informe o IP da maquina: ");
			scanf("%s", &comp[id].ip);
			printf("Informe o nome da maquina: ");
			scanf("%s", &comp[id].pc);
			printf("Informe o SO instalado na maquina: ");
			scanf("%s", &comp[id].so);
			printf("Informe a versao do SO instalada: ");
			scanf("%s", &comp[id].versao);
			printf("Informe o usuario responsavel pela maquina: ");
			scanf("%s", &comp[id].responsavel);
			printf("Em qual setor o PC esta instalado: ");
			scanf("%s", &comp[id].setor);
			printf("************************************\n");
			printf("Cadastro do computador efetuado com sucesso!\n");
			printf("************************************\n");
			//imprimir(concat(comp[id].pc, comp[id].ip, comp[id].so, comp[id].versao, comp[id].responsavel, comp[id].setor));
			printf("\n");
			Menu();
			//return(comp[id]);
			break;
		case 2:
			float pIp;
			printf("****Consultar um computador****\n");
			printf("Informe o IP do computador: ");
			scanf("%f", &pIp);
			break;
		case 3:
			float pIp;
			printf("****Alterar um computador****\n");
			printf("Informe o IP do computador: ");
			scanf("%f", &pIp);
			break;
		case 4:
			float pIp;
			printf("****Excluir um computador****\n");
			printf("Informe o IP do computador: ");
			scanf("%f", &pIp);
			break;
		case 5:
			printf("****Listar todos os computadores****\n");
			printf("A lista dos computadores e:\n");
			printf("");
			break;
		case 6:
			printf("****Gerar backup****\n");
			printf("Gerando beckup:\n");
			printf(pLista);
			break;
		case 9:
			printf("****SAIR****\n");
			printf("Obrigado e volte sempre!");
			break;
		default: printf("Opcao Invalida!");
	}
    
}


/*char imprimir(char str1[], char str2[], char str3[], char str4[], char str5[], char str6[]){
	printf(str1);
	printf(str2);
	printf(str3);
	printf(str4);
	printf(str5);
	printf(str6);
}*/


/*void Concat(char str1[], char str2[], char str3[], char str4[], char str5[], char str6[], char str[]) {
    strcat(str1, ";");
    strcat(str1, str2);
}*/
