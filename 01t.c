#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <locale.h>

#define YEARS 18

typedef struct {
	int age;
	char name[60];
	char cpf[20];
} Identity;

typedef struct {
	Identity *identity;
	float price;
	char origin[40];
	char destiny[40];
} Order;

void clear() {
	system("@cls||clear");
}

void breakLine() {
	printf("\n--------------------------------\n");
}

void display(const char* menu) {
	clear();
	printf("\n\n");
	printf(menu);
	breakLine();
}

void welcome() {
	display("BEM VINDO!");
	printf("O programa a seguir simula a compra de tickets para viajar\npor uma companhia ficticia de viacao.\n\nDesenvolvido com fins academicos\npor: Gabriel Firmino Pires Pereira\n\nLinkedIn: https://www.linkedin.com/in/devpires/\n\n");
	Sleep(2000);

	int i;
	for(i=3; i>0; i--) {
		printf("Iniciado em %d \3\r", i);
		Sleep(1000);
	}
}

void restart() {
	display("FIQUEI COM PREGUIÇA DE IMPLEMENTAR!");
	breakLine();
	printf("Ele não vai reiniciar sozinho kkkk...\n\n");
	int i;
	for(i=5; i>0; i--) {
		printf("Finalizando programa em em %d \3\r", i);
		Sleep(1000);
	}
}

void end() {
	display("OBRIGADO, VOLTE SEMPRE!");

	int i;
	for(i=5; i>0; i--) {
		printf("Finalizando programa em em %d \3\r", i);
		Sleep(1000);
	}
}

Identity readIdentity() {
	
	Identity id;
	
	display("CADASTRO: DADOS PESSOAIS");
	
	printf("NOME: ");
	fgets(id.name, 100, stdin);
	
	printf("CPF: ");
	fgets(id.cpf, 20, stdin);
	
	printf("IDADE: ");
	scanf("%d", &id.age);
	
	return id;
}

void destiny(const char* init, const char* cap) {
	printf("%c - %c\n", init, cap);
	breakLine();
}

void regions() {
	display("DESTINOS");
	destiny("1", "SUL");
	destiny("2", "SUDESTE");
	destiny("3", "CENTRO-OESTE");
	destiny("4", "NORDESTE");
	destiny("5", "NORTE");
	
	int confirmRegion = readWhereGo(5);
	
	
	return confirmRegion;
}

void southSt() {
	display("DESTINOS: SUL");
	destiny("1", "RIO GRANDE DO SUL");
	destiny("2", "FLORIANÓPOLIS");
	destiny("3", "CURITIBA");
}

void southEastSt() {
	display("DESTINOS: SUDESTE");
	destiny("1", "SÃO PAULO");
	destiny("2", "BELO HORIZONTE");
	destiny("3", "RIO DE JANEIRO");
	destiny("4", "VITÓRIA");
}

void midwestSt() {
	display("DESTINOS: CENTRO-OESTE");
	destiny("1", "BRASÍLIA");
	destiny("2", "GOIÂNIA");
	destiny("3", "CUIABÁ");
	destiny("4", "CAMPO GRANDE");
}

void northEastSt() {
	display("DESTINOS: NORDESTE");
	destiny("1", "SÃO LUÍS");
	destiny("2", "TERESINA");
	destiny("3", "FORTALEZA");
	destiny("4", "NATAL");
	destiny("5", "JOÃO PESSOA");
	destiny("6", "RECIFE");
	destiny("7", "MACEIÓ");
	destiny("8", "ARACAJU");
	destiny("9", "SALVADOR");
}

void northSt() {
	display("DESTINOS: NORTE");
	destiny("1", "ACRE");
	destiny("2", "AMAPÁ");
	destiny("3", "AMAZONAS");
	destiny("4", "PARÁ");
	destiny("5", "RONDÔNIA");
	destiny("6", "RORAIMA");
	destiny("7", "TOCANTINS");
}

void readWhereGo(int number) {
	int confirm = 0;
	
	do {
		puts("INSIRA O NÚMERO DE ONDE DESEJA IR: ");
		scanf("%d", &confirm);
	} while (confirm <1 || confirm > number);
	
	return confirm;
}

Order readOrder() {
	
	Order ticket;
	
	regions();
	
	breakLine();
	
	int confirmRegion = readWhereGo(5);
	
	switch (confirmRegion){
		case 1: 
			southSt();
			int confirmState = readWhereGo(3);
		
		case 2:
			southEastSt();
			int confirmState = readWhereGo(4);
			
		case 3:
			midwestSt();
			int confirmState = readWhereGo(4);
		
		case 4:
			northEastSt();
			int confirmState = readWhereGo(9);
		
		case 5:
			northSt();
			int confirmState = readWhereGo(7);
			
		default:
			readOrder();
	}
	
}

void confirmOrder() {
	
	Order ticket;
	
	display("PASSAGEM ADQUIRIDA");
	
	printf("Nome: %s\t", ticket.identity.name);
	printf("CPF: %s", ticket.identity.cpf);
	
	breakLine();
	
	printf("Destino: %s/t", ticket.destiny);
	printf("Preço: %f", ticket.price);
	
	breakLine();

	char confirm[1];
	
	do {
		puts("Confirmar?\n's' - sim\n'n' - não\n");
		scanf("%c", &confirm);
	} while (confirm != "n" || confirm != "s");
	
	if (confirm == "n")
		restart();

	if (confirm == "s")
		end();
}

int main() {

	setlocale(LC_ALL, "Portuguese");
	
	Order ticket;
	
	welcome();
	readIdentity();
	
	
	confirmOrder();

	return 0;
}
