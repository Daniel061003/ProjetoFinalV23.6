#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<conio.h>

typedef struct cliente CLIENTE;
struct cliente{
	int codigo;
	char nome[30];
	char telefone[16];
	char sexo[1];
	int quantidade;
}cliente;

typedef struct produto PRODUTO;
struct produto{
	char nome[30];
	float valor;
	char setor[30];
	int quantidade;
	int codigo;
	
}produto;


FILE *arquivo;

void menu_cliente();
void inputDado();
void consultar();
void buscar();
void alterar();
void excluir_cliente();

void menu_produto();
void cadastrar_produto();
void remover_produto();

int main(){
	int opcao;
	int opcao_cli;
	int opcao_prod;
	int quant = 0;
	setlocale (LC_ALL, "Portuguese");

	
	do
	{
	
	printf("---------------------------------------\n");
	printf("Escolha uma das opcoes seguintes :D !\n");
	printf("---------------------------------------\n");
	printf("1- Menu do cliente \n");
	printf("2 - Menu dos produtos\n");
	printf("3 - Menu de compra/venda\n");
	printf("0 - Para sair\n");
	scanf("%d", &opcao);
	system("cls");

		switch(opcao){
		
				case 1:
			
					menu_cliente();
					break;
				
				case 2:
					
					menu_produto();
					break;   
				case 3:
					printf("Bem-vindo ao menu de compra/venda! :D \n");
					break;
				
			case 0:
				system("pause");
				
		default:
			printf("Nao possui essa opcao\n");
	}
	
	
	
	
    } while (opcao =! 0);
	
	

	
	
	
	
	
	printf("Programa encerrado");
		
		
	
	
	}
	
void inputDado(){
	
	FILE* arquivo;
	arquivo = fopen("arquivo.txt", "a+b");
	
	if(arquivo == NULL){
		printf("ERRO!\n");
	}
	else{
		do{
			
			fflush(stdin);
			printf("Digite o codigo: \n");
			scanf("%d", &cliente.codigo);
			
			fflush(stdin);
			printf("Digite o nome: \n");
			gets(cliente.nome);
			
			fflush(stdin);
			printf("Digite o telefone: \n");
			gets(cliente.telefone);
			
			fflush(stdin);
			printf("Digite o sexo (M ou F): \n");
			gets(cliente.sexo);
			
			
			cliente.quantidade++;
			
			fwrite(&cliente, sizeof(CLIENTE), 1, arquivo);
			printf("Cadastro concluido com sucesso! \n ");
			getchar();
			
		} while(getche == 's');
		
		fclose(arquivo);
		
	}
	
	
	
}

void consultar(){
	int i = 1;
	int id;
	FILE* arquivo;
	arquivo = fopen("arquivo.txt", "rb");
	
	if(arquivo == NULL){
		printf("ERRO!\n");
	}
	else{
			printf("\t Lista de clientes: \n");
			printf("------------------------------------------\n");
		while(fread (&cliente, sizeof(CLIENTE), 1, arquivo) == 1 ){
			printf("Indice: %d\n", i);
			printf("Nome: %s\n", cliente.nome);
			printf("Telefone: %s\n", cliente.telefone);
			printf("Sexo: %s\n", cliente.sexo);	
			printf("Codigo: %d\n", cliente.codigo);
			printf("------------------------------------------\n");
			i++;
		}
		
	}
	fclose(arquivo);
	
}

void buscar(){
	FILE* arquivo;
	char nome[30];
	
	arquivo = fopen("arquivo.txt", "rb");
	
	if(arquivo == NULL){
	printf("ERRO!\n");
	}
	else{
		fflush(stdin);
		printf("Digite o nome desejado: ");
		gets(nome);
		
		while( fread(&cliente, sizeof(CLIENTE), 1, arquivo) == 1 ){
			if(strcmp(nome, cliente.nome) == 0 ){
				printf("Codigo: %d\n", cliente.codigo);
				printf("Nome: %s\n", cliente.nome);
				printf("Telefone: %s\n", cliente.telefone);
				printf("Sexo: %s\n", cliente.sexo);
				printf("------------------------------------------\n");
			}
		}
	}
	
	fclose(arquivo);
	
}	

void alterar(){
	FILE* arquivo;
	arquivo = fopen("arquivo.txt", "rb+");
	int i = 1;
	int id;
	
	if(arquivo){
	
		printf("\t Lista de clientes: \n");
		printf("------------------------------------------\n");
		
		while(fread(&cliente, sizeof(CLIENTE), 1, arquivo)){
			printf("Indice: %d\n", i );
			printf("Nome: %s\n", cliente.nome);
			printf("Telefone: %s\n", cliente.telefone);
			printf("Sexo: %s\n", cliente.sexo);
			printf("------------------------------------------\n");
			i++;
		}
		printf("Digite o ?ndice do cliente que deseja alterar:\n\n");
		scanf("%d", &id);
		getchar();
		id--;
		
		if(id >= 0 && id < i -1){
			printf("Digite o nome: ");
			scanf("%s", &cliente.nome);
			printf("Digite o telefone: ");
			scanf("%s", &cliente.telefone);
			printf("Digite o sexo: ");
			scanf("%s", &cliente.sexo);
			
			fseek(arquivo, id * sizeof(CLIENTE), SEEK_SET);
			fwrite(&cliente, sizeof(CLIENTE), 1, arquivo);
			printf("Dados atualizados com sucesso! :D\n");
		}
		fclose(arquivo);
		
		}
	
	else{
		printf("ERRO!");
	}
	
}

void excluir_cliente(){
	FILE* arquivo = fopen("arquivo.txt", "rw");
    FILE* novoArquivo = fopen("temporario.txt", "w");
    int codigo;
	
	consultar();
	
	
	printf("Digite o codigo do usuario a ser excluido: ");
	scanf("%d", &codigo);
				
	while(fread(&cliente, sizeof(cliente), 1, arquivo)){
		    if(codigo != cliente.codigo){
		          fwrite(&cliente, sizeof(cliente), 1, novoArquivo);
		       }
		   }
		    fclose(novoArquivo);
		    fclose(arquivo);
		    remove("arquivo.txt");
		    rename("temporario.txt", "arquivo.txt");
		    cliente.quantidade--;
		    printf("Cliente removido com sucesso!\n");
		    
}

void menu_cliente(){
		int opcao_cli;
		
		system("cls");
		printf("\t\t     ---------------------------------------\n");
		printf("\t\t\tBem-vindo ao menu do cliente! :D \n");
		printf("\t\t      ---------------------------------------\n");
		printf("Escolha uma das opcoes seguintes: \n");			
		printf("1 - Cadastro \n");
		printf("2 - Remover cadastro\n");
		printf("3 - Atualizar cadastro\n");
		printf("4 - Consultar dados\n");
		printf("5 - Buscar por cliente\n");
		printf("6 - Verificar quantidade de clientes\n");
		printf("0 - Voltar para o menu anterior\n");
		scanf("%d", &opcao_cli);

		switch(opcao_cli){
				
					case 1:
						system("cls");
						inputDado();
						printf("Aperte qualquer tecla para continuar!\n");
						getch();
						system("cls");
						break;
					
					case 2:
						system("cls");
						excluir_cliente();
						printf("Aperte qualquer tecla para continuar!\n");
						getch();
						system("cls");
						break;
				
					case 3:
						system("cls");
						alterar();
						printf("Aperte qualquer tecla para continuar!\n");
						getch();
						system("cls");
						break;
				
					case 4:
						system("cls");
						consultar();
						printf("Aperte qualquer tecla para continuar!\n");
						getch();
						system("cls");
						break;
				
					case 5:
						system("cls");
						buscar();
						printf("Aperte qualquer tecla para continuar!\n");
						getch();
						system("cls");
						break;	
					
					case 6:
						system("cls");
						printf("Quantidade de clientes cadastrados: %d\n", cliente.quantidade);
						getch();
						system("cls");
						break;	
					
					case 0:
						system("cls");
				
			
			}						
	}

void menu_produto(){
		int opcao_prod;
		
		system("cls");
		printf("\t\t     ---------------------------------------\n");
		printf("\t\t\tBem-vindo ao menu dos produtos ! :D \n");
		printf("\t\t      ---------------------------------------\n");
		printf("Escolha uma das opcoes seguintes: \n");
		printf("1 - Cadastro de produtos \n");
		printf("2 - Remover produto\n");
		printf("3 - Atualizar produto\n");
		printf("4 - Listagem dos produtos\n");
		printf("5 - Voltar para o menu anterior \n");
		scanf("%d", &opcao_prod);
		
			switch(opcao_prod){
				
				case 1:
					system("cls");
					cadastrar_produto();
					printf("Aperte qualquer tecla para continuar!\n");
					getch();
					system("cls");
					break;
				
				case 2:
					system("cls");
					remover_produto();
					printf("Aperte qualquer tecla para continuar!\n");
					getch();
					system("cls");
					break;			
				
				case 3:
					system("cls");
					atualizar_produto();
					printf("Aperte qualquer tecla para continuar!\n");
					getch();
					system("cls");
					break;		
				case 4:
					system("cls");
					listar_produto();
					printf("Aperte qualquer tecla para continuar!\n");
					getch();
					system("cls");
					break;
			}
}
			
void cadastrar_produto(){
	
	FILE* arquivoProduto;
	arquivoProduto = fopen("arquivoProduto.txt", "a+b");
	
	if(arquivoProduto == NULL){
		printf("ERRO!\n");
	}
	else{
		do{
			
			
			fflush(stdin);
			printf("Digite o nome: \n");
			gets(produto.nome);
			
			fflush(stdin);
			printf("Digite o valor: \n");
			scanf("%f", &produto.valor);
			
			fflush(stdin);
			printf("Digite o setor: \n");
			gets(produto.setor);
			
			fflush(stdin);
			printf("Digite a quantidade: \n");
			scanf("%d", &produto.quantidade);
			
			fflush(stdin);
			printf("Digite o código: \n");
			scanf("%d", &produto.codigo);
						
			
			fwrite(&produto, sizeof(PRODUTO), 1, arquivoProduto);
			printf("Cadastro de produtos concluido com sucesso! \n ");
			getchar();
			
		} while(getche == 's');
		
		fclose(arquivoProduto);
		
	}
	
	
	
}
	
void listar_produto(){
	int i = 1;
	int id;
	FILE* arquivoProduto;
	arquivoProduto = fopen("arquivoProduto.txt", "rb");
	
	if(arquivoProduto == NULL){
		printf("ERRO!\n");
	}
	else{
			printf("\t Lista de produtos: \n");
			printf("------------------------------------------\n");
		while(fread (&produto, sizeof(produto), 1, arquivoProduto) == 1 ){
			printf("Indice: %d\n", i);
			printf("Nome: %s\n", produto.nome);
			printf("Valor: %.2f\n", produto.valor);
			printf("Setor: %s\n", produto.setor);	
			printf("Quantidade: %d\n", produto.quantidade);
			printf("Codigo: %d\n", produto.codigo);
			printf("------------------------------------------\n");
			i++;
		}
		
	}
	fclose(arquivoProduto);
	
}
	
void remover_produto(){
	FILE* arquivoProduto = fopen("arquivoProduto.txt", "rw");
    FILE* novoArquivoProduto = fopen("temporarioProduto.txt", "w");
    int codigo;
	
	listar_produto();
	
	
	printf("Digite o codigo do produto a ser excluido: ");
	scanf("%d", &codigo);
				
	while(fread(&produto, sizeof(produto), 1, arquivoProduto)){
		    if(codigo != produto.codigo){
		          fwrite(&produto, sizeof(produto), 1, novoArquivoProduto);
		       }
		   }
		    fclose(novoArquivoProduto);
		    fclose(arquivoProduto);
		    remove("arquivoProduto.txt");
		    rename("temporarioProduto.txt", "arquivoProduto.txt");
		    printf("Produto removido do catalogo com sucesso!\n");
		    
}
	
void atualizar_produto(){
	FILE* arquivoProduto;
	arquivoProduto = fopen("arquivoProduto.txt", "rb+");
	int i = 1;
	int id;
	
	if(arquivoProduto){
	
		printf("\t Lista de produtos: \n");
		printf("------------------------------------------\n");
		
		while(fread(&produto, sizeof(produto), 1, arquivoProduto)){
			printf("Indice: %d\n", i );
			printf("Nome: %s\n", produto.nome);
			printf("Setor: %s\n", produto.setor);
			printf("Valor: %.2f\n", produto.valor);
			printf("Quantidade: %d\n", produto.quantidade);
			printf("------------------------------------------\n");
			i++;
		}
		printf("Digite o indice do produto que deseja alterar:\n\n");
		scanf("%d", &id);
		getchar();
		id--;
		
		if(id >= 0 && id < i -1){
			printf("Digite o nome: ");
			scanf(" %s", &produto.nome);
			getchar();
			printf("Digite o valor: ");
			scanf(" %f", &produto.valor);
			getchar();
			printf("Digite o setor: ");
			scanf("%s", &produto.setor);
			getchar();
			printf("Digite a quantidade: ");
			scanf("%d", &produto.quantidade);
			getchar();
			printf("Digite o codigo: ");
			scanf("%d", &produto.codigo);
			
			fseek(arquivoProduto, id * sizeof(produto), SEEK_SET);
			fwrite(&produto, sizeof(produto), 1, arquivoProduto);
			printf("Dados atualizados com sucesso! :D\n");
		}
		fclose(arquivoProduto);
		
		}
	
	else{
		printf("ERRO!");
	}
	
}

	
		
	







		
	

	

