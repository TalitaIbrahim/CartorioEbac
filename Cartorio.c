#include <stdio.h> // bliblioteca de comunica��o com o usu�rio
#include <stdlib.h> // bliblioteca de aloca��o de espa�o em memoria
#include <locale.h> // bliblioteca de aloca��es de texto por regi�o
#include <string.h> // bliblioteaca respons�vel por cuidar das string

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
	
	strcpy(Arquivo, CPF); // Respons�vel por copiar os valores das string
	
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
		printf("N�o foi poss�vel localizar o arquivo, n�o localizado!.\n");
	}
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n");
	}
	system("pause");
}

int deletar()
{
	char CPF[40];

    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", CPF);

    if (remove(CPF) == 0)
    {
        printf("Cadastro do usu�rio com CPF %s foi deletado com sucesso!\n", CPF);
    }
    else
    {
        printf("O usu�rio n�o se encontra no sistema ou n�o foi poss�vel remov�-lo!\n");
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
	int opcao=0; // Definindo variav�is
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
		printf("### Cart�rio da EBAC ###\n\n"); // Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n"); 
		printf("\t3 - Deletar os nomes\n\n");
		printf("Op��o: "); // fim do menu
		
		scanf("%d", &opcao); // armazenando a escolha do usu�rio
		
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
		printf("Est� opcao n�o est� dispon�vel!\n"); // fim da sele��o
		system("pause");
		break;
	}
	}
}

