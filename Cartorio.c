#include <stdio.h> // bliblioteca de comunicação com o usuário
#include <stdlib.h> // bliblioteca de alocação de espaço em memoria
#include <locale.h> // bliblioteca de alocações de texto por região
#include <string.h> // bliblioteaca responsável por cuidar das string

int registro()
{
	setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	char Arquivo[40];
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",CPF);
	
	strcpy(Arquivo, CPF); // Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(Arquivo, "w"); // cria o arquivo
	fprintf(file,CPF); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(Arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",Nome);
	
	file = fopen(Arquivo, "a");
	fprintf(file,Nome);
	fclose(file);
	
	file = fopen(Arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",Sobrenome);
	
	file = fopen(Arquivo, "a");
	fprintf(file,Sobrenome);
	fclose(file);
	
	file = fopen(Arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",Cargo);
	
	file = fopen(Arquivo, "a");
	fprintf(file,Cargo);
	fclose(file);	
	
    system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	char CPF[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", CPF);
	
	FILE *file;
	file= fopen(CPF, "r");
	
	if (file == NULL)
	{
		printf("Não foi possível localizar o arquivo, não localizado!.\n");
	}
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n");
	}
	system("pause");
}

int deletar()
{
	char CPF[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", CPF);

    if (remove(CPF) == 0)
    {
        printf("Cadastro do usuário com CPF %s foi deletado com sucesso!\n", CPF);
    }
    else
    {
        printf("O usuário não se encontra no sistema ou não foi possível removê-lo!\n");
    }

    FILE *file;
    file = fopen(CPF, "r");

    if (file != NULL)
    {
        fclose(file);
        printf("O arquivo associado ao CPF ainda existe. Algo pode estar errado!\n");
    }

    system("pause");
}
int main ()
{
	int opcao=0; // Definindo variavéis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
		printf("### Cartório da EBAC ###\n\n"); // Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n"); 
		printf("\t3 - Deletar os nomes\n\n");
		printf("Opção: "); // fim do menu
		
		scanf("%d", &opcao); // armazenando a escolha do usuário
		
		system("cls");
		
		switch(opcao)
		{
		case 1:
		registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("Está opcao não está disponível!\n"); // fim da seleção
		system("pause");
		break;
	}
	}
}

