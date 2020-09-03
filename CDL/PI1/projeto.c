#include <string.h>
int main(int argc, char const *argv[])
{
    int opcao;
    opcao = Menu ();
    SubMenu(opcao);
}


int Menu (){
	int vl_opcao;
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
    scanf("%d", &vl_opcao);
    printf("\n");
    return(vl_opcao);
}

int SubMenu (int vl_opcao) {
	switch (vl_opcao) {
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
			Beckup();
		break;
		case (0):
			Sair();
		break;
		default: printf("Opcao Invalida!");
	}
    return 0;
}

void Cadastrar() {
	char ip[15];
    char pc[15], so[10], versao[10], responsavel[15], setor[10], lista[50];
	printf("****Cadastrar um novo computador****\n");
	printf("Informe o IP da maquina: ");
	scanf("%s", &ip);
	Concat(lista, ip);
	printf("Informe o nome da maquina: ");
	scanf("%s", &pc);
	Concat(lista, pc);
	printf("Informe o SO instalado na maquina: ");
	scanf("%s", &so);
	Concat(lista, so);
	printf("Informe a versao do SO instalada: ");
	scanf("%s", &versao);
	Concat(lista, versao);
	printf("Informe o usuario responsavel pela maquina: ");
	scanf("%s", &responsavel);
	Concat(lista, responsavel);
	printf("Em qual setor o PC esta instalado: ");
	scanf("%s", &setor);
	Concat(lista, setor);
	printf("Cadastro do computador efetuado com sucesso!\n");
	printf("************************************\n");
	printf("%s", ip);
	printf(lista);
	return(ip, lista);
}

void Consultar(){
	float pIp;
	printf("****Consultar um computador****\n");
	printf("Informe o IP do computador: ");
	scanf("%f", &pIp);
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
	printf("A lista dos computadores e:\n");
	printf("");
}

void Beckup(pLista){
	printf("****Gerar backup****\n");
	printf("Gerando beckup:\n");
	printf(pLista);
}

void Sair(){
	printf("****SAIR****\n");
	printf("Obrigado e volte sempre!");
}

void Concat(char str1[], char str2[]) {
    strcat(str1, ";");
    strcat(str1, str2);
}
