int main(int argc, char const *argv[])
{
    int opcao;
    float ip, versao;
    char pc[15], so[10], responsavel[15], setor[10];
    
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
    printf("\n");
    
    switch (opcao) {
		case (1): 	
			printf("****Cadastrar um novo computador****\n");
			printf("Informe o nome da maquina: ");
			scanf("%s", &pc);
			printf("Informe o IP da maquina: ");
			scanf("%f", &ip);
			printf("Informe o SO instalado na maquina: ");
			scanf("%s", &so);
			printf("Informe a versao do SO instalada: ");
			scanf("%f", &versao);
			printf("Informe o usuario responsavel pela maquina: ");
			scanf("%s", &responsavel);
			printf("Em qual setor o PC esta instalado: ");
			scanf("%s", &setor);
			printf("Cadastro do novo computador efetuado com sucesso!\n");
			printf("************************************\n");
		break;
		case (2):
			printf("****Consultar um computador****\n");
			printf("Informe o IP do computador: ");
			scanf("%f", &ip);
		break;
		case (3):
			printf("****Alterar um computador****\n");
			printf("Informe o IP do computador: ");
			scanf("%f", &ip);
		break;
		case (4):
			printf("****Excluir um computador****\n");
			printf("Informe o IP do computador: ");
			scanf("%f", &ip);
		break;
		case (5):
			printf("****Listar todos os computadores****\n");
			printf("A lista dos computadores �:\n");
			printf("");
		break;
		case (6):
			printf("****Gerar backup****\n");
			printf("Gerando beckup:\n");
			scanf("%f", &ip);
		break;
		case (0):
			printf("****SAIR****\n");
			printf("Obrigado e volte sempre!");
		break;
		default: printf("Opcao Invalida!");
	}
    return 0;
}
