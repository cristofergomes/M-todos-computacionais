#include <stdio.h>
#include <math.h>

	double x, y, angulo, v, vx, vy, vx_0, vy_0, g, theta;
	double dt, t;
	double B;
	double y_0, p, p_0;
	double alvoy, alvox, yf;

int main (){
	FILE *file;
	file = fopen("Grafico_4.txt", "w");
	
	printf("Digite a posicao do alvo no eixo x: " );
	scanf("%lf", &alvox);
	printf("Agora no eixo y (altitude do canhao = 0, use sinal negativo quando abaixo): ");
	scanf("%lf", &alvoy);
	printf("Digite o valor da velocidade de disparo em (m/s): ");
	scanf("%lf", &v);
	printf("Digite o angulo de inclinacao do canhao: ");
	scanf("%lf", &angulo);
	

// dados fixos

	angulo = 180/angulo;
	theta = M_PI/angulo;
	vx_0 = v*cos(theta);
	vx = vx_0;
	vy_0 = v*sin(theta);
	vy = vy_0;
	x= 0.0, y = 0.0;
	t = 0;
	g = 9.81;
	// constante de arraste B = B2/m = 5*10^-5
	B = 0.00005;
	//densidade do ar	
	p_0 = 1.2;
	y_0 = 10000;
	dt = 0.0005;

// metodo de Euler
	while(x < alvox){
		fprintf(file, "%lf %lf\n", x, y);
		v = sqrt(vx*vx + vy*vy);
		// densidade em funcao da altitude
		p = p_0*exp(-y/y_0);
		vx = vx - (p/p_0)*B*v*vx*dt;
		vy = vy - g*dt - (p/p_0)*B*v*vy*dt;
		x = x + vx*dt;
		y = y + vy*dt;
		t = t + dt;
	}
	// Arredondamento
	
	yf = roundf(y);

	
	if(yf == alvoy){		
		printf("Voce acertou o alvo");
	
		}
	else{
		printf("Voce errou o alvo");
			}
}
