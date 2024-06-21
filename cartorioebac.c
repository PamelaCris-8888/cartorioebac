#include <stdio.h>  //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema.
{	
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
	
	printf("Digite o cpf a ser cadastrado: "); // responsavel por copiar valores da string
	scanf("%s", cpf); //%s refere-se as string/ neste caso escanear o que o usuario digitar e armazenando a string cpf.
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; // cria arquivo
	file = fopen(arquivo, "w"); // cria arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva dentro do arquivo o valor da vari�vel cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo que esta salvo dentro da variavel chamada arquivo e atualizar com novos valores
	fprintf(file,","); //escreve uma virgula dentro do arquivo para separar as informa��es
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado: ");// responsavel por copiar valores da string
	scanf("%s", nome); //%s refere-se a string, neste caso armazena (salva) a string nome.
	
	file = fopen(arquivo,"a"); //abrir arquivo que esta salvo dentro da variavel chamada arquivo e atualizar com novos valores
	fprintf(file,nome); //salva dentro do arquivo o valor da vari�vel nome
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo que esta salvo dentro da variavel chamada arquivo e atualizar com novos valores
	fprintf(file,","); //escreve uma virgula dentro do arquivo para separar as informa��es
	fclose(file); //fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // responsavel por copiar valores da string
	scanf("%s", sobrenome); //%s refere-se a string, neste caso escanear o que o usuario digitar e armazena (salva) a string sobrenome
	
	file = fopen(arquivo,"a"); //abrir arquivo que esta salvo dentro da variavel chamada arquivo e atualizar com novos valores
	fprintf(file, sobrenome); //salva dentro do arquivo o valor da vari�vel sobrenome
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo que esta salvo dentro da variavel chamada arquivo e atualizar com novos valores
	fprintf(file,","); //escreve uma virgula dentro do arquivo para separar as informa��es
	fclose(file); //fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  // responsavel por copiar valores da string
	scanf("%s", cargo);  //%s refere-se a string, neste casoescanear o que o usuario digitar e armazena a string cargo
	
	file = fopen(arquivo,"a"); //abrir arquivo que esta salvo dentro da variavel chamada arquivo e atualizar com novos valores
	fprintf(file, cargo);  //salva arquivo dentro da variavel sobrenome
	fclose(file); //fecha arquivo
	
	system("pause"); //pausar tela at� que um novo comando seja solicitado.
	
	
} //fim do registro de informa��es do usu�rio

int consulta() //Fun��o respons�vel por consultar informa��es do os usu�rios no sistema.

{
	setlocale(LC_ALL, "Portuguese"); //Definido a linguagem
	
	//inicio de cria��o da variavel string
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // responsavel por copiar valores da string
	scanf("%s", cpf); //%s refere-se as string/ neste caso escanear o que o usuario digitar armazenando a string cpf.
	
	FILE *file; // cria arquivo
	file = fopen(cpf, "r"); //abrir arquivo que esta salvo dentro da variavel cpf e ler o valor que esta dentro dele
	
	if(file == NULL) //se dentro do arquivo for igual a nulo, estiver vazio ent�o aparecer� mensagem:
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado.\n"); // responsavel por copiar valores da string
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto conteudo de at� 200 caracteres estiver dentro do aruivo ele vai buscar, e s� vai parar quando for nulo

	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // responsavel por copiar valores da string
		printf("%s", conteudo); //%s refere-se as string/ neste caso salva a string 
		printf("\n\n"); //"\n\n" pular linhas
	}
	
	system("pause"); //pausar tela at� que um novo comando seja solicitado.
	
} //fim da fun��o consultar

int deletar() //Fun��o respons�vel por deletar informa��es do os usu�rios no sistema

{	//inicio da cria��o da variavel string
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // responsavel por copiar valores da string
	scanf("%s", cpf); //%s refere-se as string/ neste caso escanear o que o usuario digitar e armazenando a string cpf.
	
	remove(cpf); //esta fun��o vai deletar o arquivo cpf que foi digitado pelo usuario
	
	FILE *file; //criar arquivo
	file = fopen(cpf, "r"); //abrir arquivo que esta salvo dentro da variavel cpf e ler o valor que esta dentro dele
	
	if(file == NULL)  //se dentro do arquivo for igual a nulo, estiver vazio ent�o aparecer� mensagem:
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); // responsavel por copiar valores da string
		system("pause"); //pausar tela at� que um novo comando seja solicitado.
	}
		
} //fim da fun��o deletar 

int main() //Fun��o principal 
{	  
	int opcao=0; //fun��o responsavel por guardar uma variavel do tipo inteiro chamada op��o que come�a com valor 0 zero
	int laco=1; //fun��o responsavel por guardar uma variavel do tipo inteira chamada laco que o valor come�a com 1
	
	for (laco=1;laco=1;) //repita la�o sempre que for igual a 1, s� sai do programa se quiser 
	
	{   //incio do laco
	
		system("cls"); // respons�vel por limpar a tela

	
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
		printf("###Cart�rio da EBAC###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n"); // responsavel por copiar valores da string
		printf("\t1 - Registrar nomes\n"); //"\t" cria uma espa�o, // responsavel por copiar valores da string 
		printf("\t2 - Consultar nomes\n"); //"\t" cria uma espa�o, // responsavel por copiar valores da string
		printf("\t3 - Deletar nomes\n\n"); //"\t" cria uma espa�o, // responsavel por copiar valores da string
		printf("op��o:"); // fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario   
    
    	system("cls"); // respons�vel por limpar a tela
    	
    	switch (opcao) //inicio da sele��o do menu
    	
    	{   //inicio de verifica��o de op��es do menu
    	
    		case 1: //caso op��o 1
    		registro(); //chamar a fun��o registro
    		break; //parar atividade e seguir para a pr�xima
    		
    		case 2: //caso op��o 2
    		consulta(); //chamar a fun��o consulta
			break; //parar atividade e seguir para a pr�xima
			
			case 3: //caso op��o 3
			deletar(); //chamar a fun��o deletar
    		break; //parar atividade e seguir para a pr�xima
    		
    		default: //fun��o caso nenhuma nenhuma das op��es acontecer fa�a 
    		printf("esta op��o n�o esta disponivel!\n"); // responsavel por copiar valores da string
			system("pause"); //pausar tela at� que um novo comando seja solicitado.
    		break; //parar atividade e seguir para a pr�xima
						
    	} //fim da verifica��o do menu
    
    	
	} //fim do laco
	
} //fim da fun��o principal
