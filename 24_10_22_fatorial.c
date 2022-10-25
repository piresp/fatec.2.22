// Fatorial

#include <stdio.h>
#include <locale.h>

int fatorial(int fat) {
	if (fat == 1 || fat == 0) {
		return 1;
	}
	else return fat * fatorial(fat - 1);
}

int main() {
	int fat;
	printf("Insira o fatorial: ");
	scanf("%d", &fat);
	
	int fato = fatorial(fat);
	printf("%d \n\t", fato);
}
