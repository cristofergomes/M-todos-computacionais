#include <stdio.h>
#include<stdlib.h>
#include <math.h>

int main(){
	int n, i;
	double a, b, deltax, div;
	double resultado = 0;
	
	printf("Integral da funcao  (1/x) \n\n");
	printf("Digite o limite inferior: ");
	scanf("%lf", &a);
	printf("Digite o limite superior: ");
	scanf("%lf", &b);
	// Recusar valor se a>b
	if(a>b){
		printf("\nO valor superior deve ser maior que o inferior");
	}
	else{
		printf("Digite o valor da divisao dos intervalos: ");
		scanf("%d", &n);
		// Recusar valor se a divisao for menor que 1
		if(n<1){
			printf("\nO valor da divisao deve ser maior que 1");
		}
		else{
			div = n;
			deltax = (b-a)/div;
			// I(a,b) = Deltax/2 * (F(a) + F(a+deltax)) ... Deltax/2 * (F(n) + F(b))
			for(i = 0; i < n; i++){
			resultado = resultado + ((deltax/2)*((1/a)+(1/(a+deltax))));
			a = a + deltax;
			}
		printf("\nO resultado da integral eh %lf", resultado);
		}
	}

	return 0;
}
