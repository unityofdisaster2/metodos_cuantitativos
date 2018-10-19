#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
    float xob=0.2, yob=0.5;                                 //VARIABLES PARA GUARDAR LA FUNCION OBJETIVO
    unsigned char signoob=1;                          //VARIABLES PARA GUARDAR LA FUNCION OBJETIVO
    /*
    printf("\nIntroduce la funcion objetivo:  ");
    scanf("%f %c %f",&xob,&signoob,&yob);
    if(signoob==43)                                 //SI EL SIMBOLO ES SUMA (SIGNO VALE 1)
            signoob=1;
    else                                            //SI EL SIGNO ES RESTA (SIGNO VALE 2)
            signoob=2;
    */
    srand(time(NULL));
    int restricciones=3;
    /*
    printf("\nNumero de restricciones: ");
    scanf("%d",&restricciones);                     //PIDE CUANTAS RESTRICCIONES VAS A QUERER
    printf("\n");
    */
    float x[5]={1,1,1,0,0},y[5]={6,1,0,0,0},res[5]={20000,6000,4000,0,0},xl[5],yl[5];  //ARREGLOS PARA GUARDAR LAS RESTRICCIONES
    unsigned char signo[5]={1,1,1,0,0};                          //ARREGLO PARA GUARDAR SIGNO
    char condicion[5][2]={1,1,1,0,0};                               //'''''''''''''''''''' CONDICION
    float valor_x[5],valor_y[5];              //ARREGLO PARA GUARDAR DIVISION (LIMITES)
    int j, i=0;
    float xmax=100000,ymax=100000,xmin=0,ymin=0;    //INICIALIZO MIN EN 0(NEGATIVIDAD) Y MAX EN UN N MUY GRANDE
    for(j = 0; j<restricciones; j++){               //ESTE FOR PEDIRA CADA RESTRICCION
        /*
        printf("Restriccion %d: ",j+1);
        scanf("%f %c %f %s %f",&x[j],&signo[j][i],&y[j],&condicion[j],&res[j][i]);
        */

        if(x[j]==0){                             //VALIDACION SI X ES IGUAL A 0
            valor_x[j]=0;
            //printf("X %.2f ",valor_x[j]);
        }
        else{
            //printf("X %.2f ",x[j]);
            valor_x[j] = res[j] / x[j];    //SI X ES DIF DE 0 HACE LA DIVISIÓN
            //printf("LIMX %.2f ",valor_x[j]);
        }

        if(y[j]==0){                             //VALIDACION SI Y ES IGUAL A 0
            valor_y[j]=0;
        }
        else{                                       //SI Y ES DIF DE 0 HACE LA DIVICION
            valor_y[j] = res[j]/y[j];
        }

        if(signo[j]==43){                        //SI EL SIMBOLO ES SUMA (SIGNO VALE 1)
            //printf("suma ");
            signo[j]=1;
        }
        else{                                       //SI EL SIGNO ES RESTA (SIGNO VALE 2)
            //printf("resta ");
            signo[j]=2;
        }

        if(!strcmp(condicion[j],">=")){             //SI LA CONDICION ES >= ( CONDICION VALE 1 )
            //printf("MAYOR igual\n");
            condicion[j][i]=1;
        }
        else{                                       //SI LA CONDICION ES <= ( CONDICION VALE 2 )
            //printf("MENOR igual\n");
            condicion[j][i]=2;
                                                    //ENTONCES
            if(x[j]!=0)                          //SI X DE RESTRICCION ES DIF DE 0
                xl[j]=res[j]/x[j];         //X LIM ES (RES DE RESTRICCION / X DE RESTRICCION)
            else                                    //SI X DE RESTRICCION ES 0
                xl[j]=xmax;                      //X LIM ES XMAX

            if(y[j]!=0)                          //SI Y DE RESTRICCION ES DIF DE 0
                yl[j]=res[j]/y[j];         //Y LIM ES (RES DE RESTRICCION / Y DE RESTRICCION)
            else                                    //SI Y DE RESTRICCION ES 0
                yl[j]=ymax;                      //Y LIM ES YMAX

            if(xl[j]<xmax || yl[j]<ymax){     //EN CASO DE QUE (X LIM ES MENOR A XMAX) Ó (Y LIM ES MENOR A YMAX)
                xmax=xl[j];                      //XMAX ES IGUAL A X LIM
                ymax=yl[j];                      //YMAX ES IGUAL A Y LIM
            }                                       //DE ESTA MANERA SE ACTUALIZA LOS LIMITES REALES DE LAS CONDICIONES PARA LA GENERACION DE NUMEROS
        }
    }
    /*
    printf("-----------\n",xmax);
    printf("xmax %.2f\n",xmax);
    printf("xmin %.2f\n",xmin);
    printf("ymax %.2f\n",ymax);
    printf("ymin %.2f\n",ymin);
    printf("-----------\n",xmax);
    */

    unsigned char bits=0;
    int mjx, mjy;
    int limx, limy;
    /*
    printf("\nINGRESE EL NUMERO DE BITS: ");
    scanf("%d",&bits);
    */
    limx=(xmax-xmin)*(pow(10,bits));
    limy=(ymax-ymin)*(pow(10,bits));

    mjx= ceil(log(limx)/log(2));
    mjy= ceil(log(limy)/log(2));
    /*
    printf("\n\tPara x %d bits",mjx);
    printf("\n\tPara y %d bits",mjy);
    */

    int numbitx, numbity;
    numbitx = pow(2,mjx)-1;                     //SE NECESITA DISMINUIR 2 EN VEZ DE 1 PARA PONER REALIZAR CAMBIOS EN LOS BITS PARA LOS ALEATORIOS
    numbity = pow(2,mjy)-1;
    //printf("\nmaxbit x: %d  &  maxbit y: %d\n",numbitx,numbity);

    int auxintx=0, auxinty=0;
    float auxfloatx=0, auxfloaty=0;
    unsigned char valido;
    int k;
    int f;
    float taux=0;

    printf("\nCuantos numeros deseas generar:  ");
    scanf("%d",&f);
    printf("\n");

    float tx[f],ty[f],tzj[f],tzj1[f],tzjacum[f],tale[f],tvect[f]; //ARREGLOS PARA CALCULOS DE F1

    float x1[f], y1[f], res1[f];           //ARREGLOS PARA CREACION DE NUMEROS (AQUI VAMOS A PONER ALEATORIOS)
    for ( j=0 ; j<f ; j++){
        valido=0;
        while(valido!=restricciones){
            x1[j]=rand()%numbitx;
            y1[j]=rand()%numbity;
            for(k=0 ; k<restricciones ; k++){
                if( signo[k]==1 ){
                    res1[j] = x[k]*x1[j] + y[k]*y1[j];
                    if(res1[j]>=0){
                        if(condicion[k][i]==1){
                            if(res1[j]>=res[k]){
                                printf("%c R%d  ",2,k+1);
                                valido++;
                            }
                            else
                                printf("X R%d  ",k+1);
                        }
                        else{
                            if(res1[j]<=res[k]){
                                printf("%c R%d  ",2,k+1);
                                valido++;
                            }
                            else
                                printf("X R%d  ",k+1);
                        }
                    }
                    else{
                        printf("X R%d  ",k+1);
                    }
                }
                else{
                    res1[j] = x[k]*x1[j] - y[k]*y1[j];
                    if(res1[j]>=0){
                        if(condicion[k][i]==1){
                            if(res1[j]>=res[k]){
                                printf("%c R%d  ",2,k+1);
                                valido++;
                            }
                            else
                                printf("X R%d  ",k+1);
                        }
                        else{
                            if(res1[j]<=res[k]){
                                printf("%c R%d  ",2,k+1);
                                valido++;
                            }
                            else
                                printf("X R%d  ",k+1);
                        }
                    }
                    else
                        printf("X R%d  ",k+1);
                }
            }
            if( valido == restricciones){
                printf("\t%.2f & %.2f es VALIDO\n",x1[j],y1[j]);
                                                                        //ESTA SERA UNA FUNCIÓN
                tx[j]= xmin + ( x1[j]*( (xmax-xmin)/numbitx) );
                ty[j]= ymin + ( y1[j]*( (ymax-ymin)/numbity) );
                if(signoob==1)
                    tzj[j]=tx[j]+ty[j];
                else
                    tzj[j]=tx[j]-ty[j];
                taux=taux+tzj[j];
                                                                        //AQUI TERMINARA LA FUNCIÓN
            }
            else{
                printf("\tINTRODUCE UN NUEVO NUMERO\n",x1[j],y1[j]);
                valido=0;
            }
        }
    }
    printf("\n");
    int g;
    for(g=0 ; g<f ; g++){
        //printf("\t%d.-   %.2f & %.2f\n",g+1,x1[g][i],y1[g][i]);
        printf("%.2f | %.2f | %.2f | %.4f\n",tx[g],ty[g],tzj[g],tzj[g]/taux);
    }
    return 0;
}
