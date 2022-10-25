// Faça uma rotina recursiva para calcular a somatoria de todos os numeros de 1 a N

#include <stdio.h>
#include <locale.h>

int soma_num (int num) {
	int resultado;
	
	if(num == 1) {
		return (1);
	}
	else {
		resultado = num + soma_num(num-1);
	}
	return resultado;
}

int main() {
	
	int num_N;
	int somatorio;
	
	setlocale(LC_ALL, "portuguese");
	
	printf("Somatoria 1 a N: ");
	scanf("%d", &num_N);
	somatorio = soma_num(num_N);
	
	printf("Somatorio de 1 até %d\n%d", num_N, somatorio);
}
