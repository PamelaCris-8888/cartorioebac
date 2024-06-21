#include <stdio.h>  //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema.
{	
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis
	
	printf("Digite o cpf a ser cadastrado: "); // responsavel por copiar valores da string
	scanf("%s", cpf); //%s refere-se as string/ neste caso escanear o que o usuario digitar e armazenando a string cpf.
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; // cria arquivo
	file = fopen(arquivo, "w"); // cria arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva dentro do arquivo o valor da variável cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo que esta salvo dentro da variavel chamada arquivo e atualizar com novos valores
	fprintf(file,","); //escreve uma virgula dentro do arquivo para separar as informações
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado: ");// responsavel por copiar valores da string
	scanf("%s", nome); //%s refere-se a string, neste caso armazena (salva) a string nome.
	
	file = fopen(arquivo,"a"); //abrir arquivo que esta salvo dentro da variavel chamada arquivo e atualizar com novos valores
	fprintf(file,nome); //salva dentro do arquivo o valor da variável nome
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo que esta salvo dentro da variavel chamada arquivo e atualizar com novos valores
	fprintf(file,","); //escreve uma virgula dentro do arquivo para separar as informações
	fclose(file); //fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // responsavel por copiar valores da string
	scanf("%s", sobrenome); //%s refere-se a string, neste caso escanear o que o usuario digitar e armazena (salva) a string sobrenome
	
	file = fopen(arquivo,"a"); //abrir arquivo que esta salvo dentro da variavel chamada arquivo e atualizar com novos valores
	fprintf(file, sobrenome); //salva dentro do arquivo o valor da variável sobrenome
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo que esta salvo dentro da variavel chamada arquivo e atualizar com novos valores
	fprintf(file,","); //escreve uma virgula dentro do arquivo para separar as informações
	fclose(file); //fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  // responsavel por copiar valores da string
	scanf("%s", cargo);  //%s refere-se a string, neste casoescanear o que o usuario digitar e armazena a string cargo
	
	file = fopen(arquivo,"a"); //abrir arquivo que esta salvo dentro da variavel chamada arquivo e atualizar com novos valores
	fprintf(file, cargo);  //salva arquivo dentro da variavel sobrenome
	fclose(file); //fecha arquivo
	
	system("pause"); //pausar tela até que um novo comando seja solicitado.
	
	
} //fim do registro de informações do usuário

int consulta() //Função responsável por consultar informações do os usuários no sistema.

{
	setlocale(LC_ALL, "Portuguese"); //Definido a linguagem
	
	//inicio de criação da variavel string
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // responsavel por copiar valores da string
	scanf("%s", cpf); //%s refere-se as string/ neste caso escanear o que o usuario digitar armazenando a string cpf.
	
	FILE *file; // cria arquivo
	file = fopen(cpf, "r"); //abrir arquivo que esta salvo dentro da variavel cpf e ler o valor que esta dentro dele
	
	if(file == NULL) //se dentro do arquivo for igual a nulo, estiver vazio então aparecerá mensagem:
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n"); // responsavel por copiar valores da string
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto conteudo de até 200 caracteres estiver dentro do aruivo ele vai buscar, e só vai parar quando for nulo

	{
		printf("\nEssas são as informações do usuário: "); // responsavel por copiar valores da string
		printf("%s", conteudo); //%s refere-se as string/ neste caso salva a string 
		printf("\n\n"); //"\n\n" pular linhas
	}
	
	system("pause"); //pausar tela até que um novo comando seja solicitado.
	
} //fim da função consultar

int deletar() //Função responsável por deletar informações do os usuários no sistema

{	//inicio da criação da variavel string
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); // responsavel por copiar valores da string
	scanf("%s", cpf); //%s refere-se as string/ neste caso escanear o que o usuario digitar e armazenando a string cpf.
	
	remove(cpf); //esta função vai deletar o arquivo cpf que foi digitado pelo usuario
	
	FILE *file; //criar arquivo
	file = fopen(cpf, "r"); //abrir arquivo que esta salvo dentro da variavel cpf e ler o valor que esta dentro dele
	
	if(file == NULL)  //se dentro do arquivo for igual a nulo, estiver vazio então aparecerá mensagem:
	{
		printf("O usuário não se encontra no sistema!.\n"); // responsavel por copiar valores da string
		system("pause"); //pausar tela até que um novo comando seja solicitado.
	}
		
} //fim da função deletar 

int main() //Função principal 
{	  
	int opcao=0; //função responsavel por guardar uma variavel do tipo inteiro chamada opção que começa com valor 0 zero
	int laco=1; //função responsavel por guardar uma variavel do tipo inteira chamada laco que o valor começa com 1
	
	for (laco=1;laco=1;) //repita laço sempre que for igual a 1, só sai do programa se quiser 
	
	{   //incio do laco
	
		system("cls"); // responsável por limpar a tela

	
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
		printf("###Cartório da EBAC###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n"); // responsavel por copiar valores da string
		printf("\t1 - Registrar nomes\n"); //"\t" cria uma espaço, // responsavel por copiar valores da string 
		printf("\t2 - Consultar nomes\n"); //"\t" cria uma espaço, // responsavel por copiar valores da string
		printf("\t3 - Deletar nomes\n\n"); //"\t" cria uma espaço, // responsavel por copiar valores da string
		printf("opção:"); // fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario   
    
    	system("cls"); // responsável por limpar a tela
    	
    	switch (opcao) //inicio da seleção do menu
    	
    	{   //inicio de verificação de opções do menu
    	
    		case 1: //caso opção 1
    		registro(); //chamar a função registro
    		break; //parar atividade e seguir para a próxima
    		
    		case 2: //caso opção 2
    		consulta(); //chamar a função consulta
			break; //parar atividade e seguir para a próxima
			
			case 3: //caso opção 3
			deletar(); //chamar a função deletar
    		break; //parar atividade e seguir para a próxima
    		
    		default: //função caso nenhuma nenhuma das opções acontecer faça 
    		printf("esta opção não esta disponivel!\n"); // responsavel por copiar valores da string
			system("pause"); //pausar tela até que um novo comando seja solicitado.
    		break; //parar atividade e seguir para a próxima
						
    	} //fim da verificação do menu
    
    	
	} //fim do laco
	
} //fim da função principal
