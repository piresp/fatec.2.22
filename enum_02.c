#include <stdio.h>

enum Year_months {
	Janeiro = 1, Fevereiro, Marco, Abril, Maio, Junho, Julho, Agosto, Setembro, Outubro, Novembro, Dezembro, Last
} month;

const char* months[] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

void get_all_months() {
	for(int i = 0; i < Dezembro; i++) {
		printf("%d - %s\n", i + 1, months[i]);
	}
}

int set_month() {
	printf("\nMeses do ano:");
	scanf("%d", &month);
	
	return month;
}

int get_select_month(int month) {
	printf("%d - %s\n", month, months[month - 1]);
}

int main(void) {
	
	get_all_months();
	int m = set_month();
	get_select_month(m);
	
}
