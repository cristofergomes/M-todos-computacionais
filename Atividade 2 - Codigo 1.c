#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int i, n;
float x, dx, deltax, x1, x2, f1, f2;

int main(){
	printf("Digite o valor do chute inicial: ");
	scanf ("%f", &x);
	printf("\nDigite o numero de iteracoes: ");
	scanf("%d", &n);
	printf("\nDigite o deltax: ");
	scanf("%f", &deltax);

	for (i = 1; i <= n; i++){
	// Calculo da derivada para F(x) = exp(2x) - x - 6
	// dx = F(x+deltax) - F(x-deltax) / 2*deltax
	// dx = F(x1) - F(x2) / 2*deltax)
	x1 = x+deltax;
	x2 = x-deltax;
	//F(x1) = f1 e F(x2) = f2
	f1 = exp(2*(x1)) - x1 - 6;
	f2 = exp(2*(x2)) - x2 - 6;
	dx = (f1-f2)/(2*deltax);
		x = x - ((exp(2*x)-x-6)/(dx));
		printf("Para a iteracao %d = %f\n", i, x);
	}

	printf ("\nO valor encontrado para a raiz eh: %f", x);
	return 0;
}
