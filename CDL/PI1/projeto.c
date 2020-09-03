int main(int argc, char const *argv[])
{
    int vl_opcao;
    
	printf("****Bem-vindos ao sistema CADTI****\n");
    printf("********* Menu do sistema**********\n");
    printf("1 - Cadastrar um novo computador\n");
    printf("2 - Consultar um computador\n");
    printf("3 - Alterar um computador\n");
    printf("4 - Excluir um computador\n");
    printf("5 - Listar todos os computadores\n");
    printf("6 - Gerar backup\n");
    printf("7 - Sair\n");
    printf("************************************\n");
    printf("Digite aqui o que deseja fazer: ");
    scanf("%d", &vl_opcao);
    printf("\n");
    
    switch (vl_opcao) {
		case (1): 
			printf("************************************\n");	
			printf("****Cadastrar um novo computador****\n");
			printf("Informe o nome da maquina:\n");
			printf("Informe o IP da maquina:\n");
			printf("Informe o SO instalado na maquina:\n");
			printf("Informe a versao do SO instalada:\n");
			printf("Informe o usuario responsavel pela maquina:\n");
			printf("Qual setor/departamento o PC esta instalado:\n");
			printf("Cadastro do novo computador efetuado com sucesso!\n");
			printf("************************************\n");
		break;
	}
    return 0;
}
