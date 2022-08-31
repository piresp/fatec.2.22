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
	Identity identity;
	float price;
} Order;

void clear() {
	system("@cls||clear");
}

void break_line() {
	printf("\n--------------------------------\n");
}

void display(const char* menu) {
	clear();
	printf("\n\n");
	printf(menu);
	break_line();
}

void welcome() {
	display("BEM VINDO!");
	printf("O programa a seguir simula a compra de tickets para viajar\npor uma companhia ficticia de viacao.\n\nDesenvolvido com fins academicos\npor: Gabriel Firmino Pires Pereira\n\nLinkedIn: https://www.linkedin.com/in/devpires/\n\n");
	Sleep(2000);

	int i;
	for(i=3; i>0; i--) {
		printf("Iniciado em %d \r", i);
		Sleep(1000);
	}
}

void restart() {
	display("FIQUEI COM PREGUIÇA DE IMPLEMENTAR!");
	break_line();
	printf("Ele não vai reiniciar sozinho kkkk...\n\n");
	int i;
	for(i=5; i>0; i--) {
		printf("Finalizando programa em em %d \r", i);
		Sleep(1000);
	}
}

void end() {
	display("OBRIGADO, VOLTE SEMPRE!");

	int i;
	for(i=5; i>0; i--) {
		printf("Finalizando programa em em %d \r", i);
		Sleep(1000);
	}
}

Identity get_identity(Identity id) {
	
	break_line();
	printf("IDENTIDADE:");
	printf("\n\nNOME: %s",id.name);
	printf("CPF: %s",id.cpf);
	printf("IDADE: %d",id.age);
	
	break_line();
}

Identity set_identity(Identity id) {
	
	display("CADASTRO: DADOS PESSOAIS");
	
	printf("NOME: ");
	fgets(id.name, 100, stdin);
	
	printf("CPF: ");
	fgets(id.cpf, 20, stdin);
	
	printf("IDADE: ");
	scanf("%d", &id.age);
	
	return id;
}

int read_where(int number) {
	int confirm = 0;
	
	do {
		puts("INSIRA O NÚMERO DE ONDE DESEJA IR: ");
		scanf("%d", &confirm);
	} while (confirm <1 || confirm > number);
	
	return confirm;
}

int main() {

	setlocale(LC_ALL, "Portuguese");
	
	welcome();
	
	Identity id;
	id = set_identity(id);
	get_identity(id);
	
	return 0;
}
