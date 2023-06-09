#include <stdio.h>  //biblioteca de comunica��o do usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em m�moria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //Salva o valor da vari�vel
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
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	       printf("\nEssas s�o as informa��es do usu�rio: ");
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
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0;  //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	      system("cls");   //limpar a tela
	
	      setlocale (LC_ALL, "Portuguese"); //definindo linguagem
	
	      printf("\t_Cart�rio EBAC_\n\n");  //in�cio do menu
              printf("Escolha a op��o desejada do menu:\n\n");
              printf("\t1 - Registrar nome\n");
	      printf("\t2 - Consultar nome\n");
	      printf("\t3 - Deletar nome\n\n\n"); 
	      printf("\t4 - Sair do sistema \n\n");
	      printf("Op��o: ");  //fim do menu

              scanf("%d", &opcao);  //armazenando a escolha do usu�rio
    
	
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
                        
                        case 4:
		        printf("Obrigado por utilizar o sistema");
		        return 0;
		        break;
		    
		    
		        default:
		        printf("Essa op��o n�o est� dispon�vel.\n");
	    	        system("pause");
	    	        break;
		}
       }	
}
