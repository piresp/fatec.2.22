#include <stdio.h>

int mdc(int num1, int num2)
{
    if(num1%num2 == 0)
        return num2;
    else
        return mdc(num2, num1%num2);
}

int main()
{
    int num1, num2, func;

    printf("Numero maior e menor:");
    scanf("%d %d", &num1, &num2);
    
    func = mdc(num1, num2);
    printf("%d\n", func);
}
