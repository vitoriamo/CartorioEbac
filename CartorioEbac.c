#include <stdio.h>  //biblioteca de comunicação do usuário
#include <stdlib.h> //biblioteca de alocação de espaço em mémoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale (LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	    printf("Não foi possível abrir o arquivo, não localizado!. \n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	    printf("\nEssas são as informações do usuário: ");
	    printf("%s", conteudo);
	    printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	    printf("O usuário não se encontra no sistema.\n");
	    system("pause");
	}
}

int main()
{

	int opcao=0;  //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    system("cls");   //limpar a tela
	
	    setlocale (LC_ALL, "Portuguese"); //definindo linguagem
	
	    printf("\t__Cartório EBAC__\n\n");  //início do menu
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - Registrar nome\n");
	    printf("\t2 - Consultar nome\n");
	    printf("\t3 - Deletar nome\n\n\n"); 
	    printf("Opção: ");  //fim do menu

            scanf("%d", &opcao);  //armazenando a escolha do usuário
    
	
	    system("cls");  //limpar a tela
	    
	    
	    switch(opcao)
	    {
	    	case 1:
	    	registro();
	        break;
	        
	        case 2:
	        consultar();
	        break;
		    
		case 3:
		deletar();
		break;
		    
		default:
		printf("Essa opção não está disponível.\n");
	    	system("pause");
	    	break;    
	    }
      }	
}
