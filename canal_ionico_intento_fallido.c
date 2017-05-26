#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double calcularRadio(float nx, float ny, float x, float y);

int main()
{
    float *x, *y;
    int cantidad = 42;
    x = malloc(cantidad*sizeof(float)); /*la cantidad del arreglo por el tipo*/
    y = malloc(cantidad*sizeof(float));
    float xo = 2.0;
    float yo = 5.0; 
    float ro = 5.0;

     
    FILE *canalIonico;
    canalIonico = fopen("canal_ionico.txt", "r");
    FILE *canal_ionico = fopen("CID.txt", "w");
    FILE *canal_ionico1 = fopen("CID1.txt", "w");
    
    
    int i;
    for(i=0; i<42;i++){/*El numero de lineas del archivo es 42*/
    fscanf(canalIonico, "%f %f\n", &x[i], &y[i]); /*asi imprime el numero espacio numero y baja*/
    /*printf("x=%f\n", x[i]), esto serviria para imprimilo en la terminal*/
    /*vamos elegir un x, y, r de acuerdo a las graficas, estos seran 2,5,5*/
    /*por ahora sé que los arreglos x y y tienen las pocisiones de las moléculas.*/  
    
    }
    
    float xrand, yrand; /*variables que guardaran los valores random*/
    float xnovo, ynovo;
    int j, n;
    n = 20000;
    for(j=0; j<n; j++){

    /*los numeros van a tener una varianza de 0.5 en x und y und de 0.3 en r, despues a los valores iniciales les sumo esta varianza, para que se dezplace en un numero random en x und y und lance un nuevo radio con la variacion*/
    xrand = (1-(2*drand48())); 
    xnovo = xo + xrand;	
    yrand = (1-(2*drand48()));
    ynovo = yo + yrand;
    /*aca creo los pasos aleatorio, primero elijo hacia donde y en que magnitud dar el paso y luego le sumo esto al inicial o al anterior.*/
    int k;
    float xoL[n];
    float yoL[n];
    float roL[n];
    int contador;
    for(k=0; k<42; k++){
    double a = calcularRadio(xo,yo, x[k], y[k]);
    double b = calcularRadio(xnovo, ynovo, x[k], y[k]);
		double alpha;
   		alpha = b/a;
		if(alpha >= 1.0){/*si el radio nuevo es mayor que el radio que tenia inicialmente. Las posiciones y radio origen tomarán los valores de estos nuevos datos random*/
			ro = b;
			xo = xnovo;
			yo = ynovo;
		}
		else{/*creo una nueva variable que sera un numero random de 0 a 1*/
	double betta;
	betta = drand48();
		if(betta <= alpha){
			ro = b;
			xo = xnovo;
			yo = ynovo;
		}
		else{
			ro = a;
			xo = xo;
			yo = yo;
		}
	}

xoL[k] = xo;
yoL[k] = yo;
roL[k] = ro;

fprintf(canal_ionico, "%f %f %f\n ", xoL[k], yoL[k], roL[k]);
	}
fclose(canal_ionico);
}

    float *x1, *y1;
    int cantidad1 = 42;
    x1 = malloc(cantidad1*sizeof(float)); /*la cantidad del arreglo por el tipo*/
    y1 = malloc(cantidad1*sizeof(float));
    float xo1 = 2.0;
    float yo1 = 2.0; 
    float ro1 = 2.0;

    FILE *canalIonico1;
    canalIonico1 = fopen("canal_ionico1.txt", "r");
    
    int z;
    for(z=0; z<42;z++){/*El numero de lineas del archivo es 42*/
    fscanf(canalIonico1, "%f %f\n", &x1[z], &y1[z]); /*asi imprime el numero espacio numero y baja*/
    /*printf("x=%f\n", x[i]), esto serviria para imprimilo en la terminal*/
    /*vamos elegir un x, y, r de acuerdo a las graficas, estos seran 2,5,5*/
    /*por ahora sé que los arreglos x y y tienen las pocisiones de las moléculas.*/  
    
    }
    
    float xrand1, yrand1; /*variables que guardaran los valores random*/
    float xnovo1, ynovo1;
    int h;
    for(h=0; h<n; h++){

    /*los numeros van a tener una varianza de 0.5 en x und y und de 0.3 en r, despues a los valores iniciales les sumo esta varianza, para que se dezplace en un numero random en x und y und lance un nuevo radio con la variacion*/
    xrand1 = (1-(2*drand48())); 
    xnovo1 = xo1 + xrand1;	
    yrand1 = (1-(2*drand48()));
    ynovo1 = yo1 + yrand1;
    
    /*aca creo los pasos aleatorio, primero elijo hacia donde y en que magnitud dar el paso y luego le sumo esto al inicial o al anterior.*/
    int q;
    int contador1;
    float xoL1[n];
    float yoL1[n];
    float roL1[n];
    for(q=0; q<42; q++){
    double a1 = calcularRadio(xo,yo,x1[q], y1[q]);
    double b1 = calcularRadio(xnovo, ynovo, x1[q], y1[q]);
		double alpha1;
   		alpha1 = b1/a1;
		if(alpha1 >= 1.0){/*si el radio nuevo es mayor que el radio que tenia inicialmente. Las posiciones y radio origen tomarán los valores de estos nuevos datos random*/
			ro1 = b1;
			xo1 = xnovo1;
			yo1 = ynovo1;
		}
		else{/*creo una nueva variable que sera un numero random de 0 a 1*/
	double betta1;
	betta1 = drand48();
		if(betta1 <= alpha1){
			ro1 = b1;
			xo1 = xnovo1;
			yo1 = ynovo1;
		}
		else{
			ro1 = a1;
			xo1 = xo1;
			yo1 = yo1;
		  }	
		}
xoL1[q] = xo1;
yoL1[q] = yo1;
roL1[q] = ro1;

fprintf(canal_ionico1, "%f %f %f\n ", xoL1[q], yoL1[q], roL1[q]);

	}
fclose(canal_ionico1);		  
  }
}

double calcularRadio(float nx, float ny, float x, float y){
  int j = 0;
  double medidaRadio;
  return medidaRadio = sqrt(pow((nx-x),2)+pow((ny-y),2))-1;
 
}
