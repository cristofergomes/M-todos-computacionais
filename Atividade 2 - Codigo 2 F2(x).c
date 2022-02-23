#include <stdio.h>
#include<stdlib.h>
#include <math.h>

int main(){
	int n, i;
	double  a, b, deltax, div, f1, f2;
	double resultado = 0;
	
	printf("Integral da funcao  raiz de (1 - x^2)  \n\n");
	printf("\nDigite o limite inferior: ");
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
			printf("\nO valor dos intervalos deve ser maior que 1");
		}

		else{
			div = n;
			deltax = (b-a)/div;
			// I(a,b) = Deltax/2 * (F(a) + F(a+deltax)) ... Deltax/2 * (F(n) + F(b))
			// f1 = F(a) e f2 = F(a+deltax)
			for(i = 0; i < n; i++){
			f1 = (sqrt(1-(pow(a,2))));
			f2 = (sqrt(1-(pow((a+deltax),2))));
			resultado = resultado + (deltax/2)*((f1)+(f2));
			a = a+deltax;
			}
			printf("\nO resultado da integral eh %lf", resultado);

		}
	}
	return 0;
}
