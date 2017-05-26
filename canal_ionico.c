#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    float *x, *y;
    int cantidad = 42;
    x = malloc(cantidad*sizeof(float)); /*la cantidad del arreglo por el tipo*/
    y = malloc(cantidad*sizeof(float));
    float xo = 2.0;
    float yo = 5.0; 
    float ro = 5.0;
    float varDis = 0.2;
    float varRad = 0.1;

     
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
    
    float xrand, yrand, rrand; /*variables que guardaran los valores random*/
    float xnovo, ynovo, rnovo;
    int j;
    for(j=0; j<400; j++){

    /*los numeros van a tener una varianza de 0.5 en x und y und de 0.3 en r, despues a los valores iniciales les sumo esta varianza, para que se dezplace en un numero random en x und y und lance un nuevo radio con la variacion*/
    xrand = (1-(2*drand48()))*varDis; 
    xnovo = xo + xrand;	
    yrand = (1-(2*drand48()))*varDis;
    ynovo = yo + yrand;
    rrand = (1-(2*drand48()))*varRad;
    rnovo = ro + rrand;		
    /*aca creo los pasos aleatorio, primero elijo hacia donde y en que magnitud dar el paso y luego le sumo esto al inicial o al anterior.*/
    int k;
    float xoL[400];
    float yoL[400];
    float roL[400];
    int contador;
    for(k=0; k<42; k++){
          double a = pow((rnovo + 1.2),2);
    double b = pow((xnovo-x[k]),2)+pow((ynovo-y[k]),2);
    	if(a>=b){
    	contador++;}
   	 	} 
    
	if(contador == 0){
		double alpha;
   		alpha = rnovo/ro;
		if(alpha >= 1.0){/*si el radio nuevo es mayor que el radio que tenia inicialmente. Las posiciones y radio origen tomarán los valores de estos nuevos datos random*/
			ro = rnovo;
			xo = xnovo;
			yo = ynovo;
		}
		else{/*creo una nueva variable que sera un numero random de 0 a 1*/
	double betta;
	betta = drand48();
		if(betta <= alpha){
			ro = rnovo;
			xo = xnovo;
			yo = ynovo;
		}
		else{
			ro = ro;
			xo = xo;
			yo = yo;
		}
	
			}
		}

xoL[k] = xo;
yoL[k] = yo;
roL[k] = ro;

fprintf(canal_ionico, "%f %f %f\n ", xoL[k], yoL[k], roL[k]);

	}
fclose(canal_ionico);

float *x1, *y1;
    int cantidad1 = 42;
    x1 = malloc(cantidad1*sizeof(float)); /*la cantidad del arreglo por el tipo*/
    y1 = malloc(cantidad1*sizeof(float));
    float xo1 = 2.0;
    float yo1 = 2.0; 
    float ro1 = 2.0;
    float varDis1 = 0.2;
    float varRad1 = 0.1;
    
    


    FILE *canalIonico1;
    canalIonico1 = fopen("canal_ionico1.txt", "r");
    
    int z;
    for(z=0; z<42;z++){/*El numero de lineas del archivo es 42*/
    fscanf(canalIonico1, "%f %f\n", &x1[z], &y1[z]); /*asi imprime el numero espacio numero y baja*/
    /*printf("x=%f\n", x[i]), esto serviria para imprimilo en la terminal*/
    /*vamos elegir un x, y, r de acuerdo a las graficas, estos seran 2,5,5*/
    /*por ahora sé que los arreglos x y y tienen las pocisiones de las moléculas.*/  
    
    }
    
    float xrand1, yrand1, rrand1; /*variables que guardaran los valores random*/
    float xnovo1, ynovo1, rnovo1;
    int h;
    for(h=0; h<20000.0; h++){

    /*los numeros van a tener una varianza de 0.5 en x und y und de 0.3 en r, despues a los valores iniciales les sumo esta varianza, para que se dezplace en un numero random en x und y und lance un nuevo radio con la variacion*/
    xrand1 = (1-(2*drand48()))/2; 
    xnovo1 = xo1 + xrand1;	
    yrand1 = (1-(2*drand48()))/2;
    ynovo1 = yo1 + yrand1;
    rrand1 = (1-(2*drand48()))/3;
    rnovo1 = ro1 + rrand1;		
    /*aca creo los pasos aleatorio, primero elijo hacia donde y en que magnitud dar el paso y luego le sumo esto al inicial o al anterior.*/
    int q;
    int contador1;
    float xoL1[400];
    float yoL1[400];
    float roL1[400];
    for(q=0; q<42; q++){
    double a = pow((rnovo1 + 1.2),2);
    double b = pow((xnovo1-x1[q]),2)+pow((ynovo1-y1[q]),2);
    	if(a>=b){
    	contador1++;}
   	 	} 
    
	if(contador1 == 0){
		double alpha1;
   		alpha1 = rnovo1/ro1;
		if(alpha1 >= 1.0){/*si el radio nuevo es mayor que el radio que tenia inicialmente. Las posiciones y radio origen tomarán los valores de estos nuevos datos random*/
			ro1 = rnovo1;
			xo1 = xnovo1;
			yo1 = ynovo1;
		}
		else{/*creo una nueva variable que sera un numero random de 0 a 1*/
	double betta1;
	betta1 = drand48();
		if(betta1 <= alpha1){
			ro1 = rnovo1;
			xo1 = xnovo1;
			yo1 = ynovo1;
		}
		else{
			ro1 = ro1;
			xo1 = xo1;
			yo1 = yo1;
		}	
			}
		}
xoL1[q] = xo1;
yoL1[q] = yo1;
roL1[q] = ro1;

fprintf(canal_ionico1, "%f %f %f\n ", xoL1[q], yoL1[q], roL1[q]);

	}
fclose(canal_ionico1);		  
}
