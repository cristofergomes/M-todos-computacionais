#include <stdio.h>
#include <math.h>

	double x, y, angulo, v, vx, vy, vx_0, vy_0, g, theta;
	double dt, t;

int main (){
	FILE *file;
	file = fopen("Grafico_1a.txt", "w");

	printf("Digite o valor da velocidade de disparo em (m/s): ");
	scanf("%lf", &v);
	printf("Digite o angulo de inclinacao do canhao: ");
	scanf("%lf", &angulo);
	

// inserir os dados iniciais

	dt = 0.0005;


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

// metodo de Euler
	while(y>=0){
		fprintf(file, "%lf %lf\n", x, y);
		v = sqrt(vx*vx + vy*vy);
		vx = vx;
		vy = vy - g*dt;
		x = x + vx*dt;
		y = y + vy*dt;
		t = t + dt;
	}	
}
