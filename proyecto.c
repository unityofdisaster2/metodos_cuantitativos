#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
    srand(time(NULL));
    int restricciones;
    printf("Numero de restricciones: ");
    scanf("%d",&restricciones);                     //PIDE CUANTAS RESTRICCIONES VAS A QUERER
    printf("\n");
    float x[5][1],y[5][1],res[5][1],xl[5][1],yl[5][1];  //ARREGLOS PARA GUARDAR LA SRESTRICCIONES
    unsigned char signo[5][1];                          //ARREGLO PARA GUARDAR SIGNO
    char condicion[5][2];                               //'''''''''''''''''''' CONDICION
    float valor_x[5][1],valor_y[5][1];              //ARREGLO PARA GUARDAR DIVISION (LIMITES)
    int j, i=0;
    float xmax=100000,ymax=100000,xmin=0,ymin=0;    //INICIALIZO MIN EN 0(NEGATIVIDAD) Y MAX EN UN N MUY GRANDE.
    for(j = 0; j<restricciones; j++){               //ESTE FOR PEDIRA CADA RESTRICCION
        printf("Restriccion %d: ",j+1);
        scanf("%f %c %f %s %f",&x[j][i],&signo[j][i],&y[j][i],&condicion[j],&res[j][i]);

        if(x[j][i]==0){                             //VALIDACION SI X ES IGUAL A 0
            valor_x[j][i]=0;
            //printf("X %.2f ",valor_x[j][i]);
        }
        else{
            //printf("X %.2f ",x[j][i]);
            valor_x[j][i] = res[j][i] / x[j][i];    //SI X ES DIF DE 0 HACE LA DIVISIÓN
            //printf("LIMX %.2f ",valor_x[j][i]);
        }

        if(y[j][i]==0){                             //VALIDACION SI Y ES IGUAL A 0
            valor_y[j][i]=0;
        }
        else{                                       //SI Y ES DIF DE O HACE LA DIVICION
            valor_y[j][i] = res[j][i]/y[j][i];
        }

        if(signo[j][i]==43){                        //SI EL SIMBOLO ES SUMA (SIGNO VALE 1)
            //printf("suma ");
            signo[j][i]=1;
        }
        else{                                       //SI EL SIGNO ES RESTA (SIGNO VALE 2)
            //printf("resta ");
            signo[j][i]=2;
        }

        if(!strcmp(condicion[j],">=")){             //SI LA CONDICION ES >= ( CONDICION VALE 1 )
            //printf("MAYOR igual\n");
            condicion[j][i]=1;
        }
        else{                                       //SI LA CONDICION ES <= ( CONDICION VALE 2 )
            //printf("MENOR igual\n");
            condicion[j][i]=2;
                                                    //ENTONCES
            if(x[j][i]!=0)                          //SI X DE RESTRICCION ES DIF DE 0
                xl[j][i]=res[j][i]/x[j][i];         //X LIM ES (RES DE RESTRICCION / X DE RESTRICCION)
            else                                    //SI X DE RESTRICCION ES 0
                xl[j][i]=xmax;                      //X LIM ES XMAX

            if(y[j][i]!=0)                          //SI Y DE RESTRICCION ES DIF DE 0
                yl[j][i]=res[j][i]/y[j][i];         //Y LIM ES (RES DE RESTRICCION / Y DE RESTRICCION)
            else                                    //SI Y DE RESTRICCION ES 0
                yl[j][i]=ymax;                      //Y LIM ES YMAX

            if(xl[j][i]<xmax || yl[j][i]<ymax){     //EN CASO DE QUE (X LIM ES MENOR A XMAX) Ó (Y LIM ES MENOR A YMAX)
                xmax=xl[j][i];                      //XMAX ES IGUAL A X LIM
                ymax=yl[j][i];                      //YMAX ES IGUAL A Y LIM
            }                                       //DE ESTA MANERA SE ACTUALIZA LOS LIMITES REALES DE LAS CONDICIONES PARA LA GENERACION DE NUMEROS
        }
    }
    printf("-----------\n",xmax);
    printf("xmax %.2f\n",xmax);
    printf("xmin %.2f\n",xmin);
    printf("ymax %.2f\n",ymax);
    printf("ymin %.2f\n",ymin);
    printf("-----------\n",xmax);

    unsigned char bits;
    int mjx, mjy;
    int limx, limy;
    printf("\nINGRESE EL NUMERO DE BITS: ");
    scanf("%d",&bits);
    limx=(xmax-xmin)*(pow(10,bits));
    limy=(ymax-ymin)*(pow(10,bits));

    mjx= ceil(log(limx)/log(2));
    mjy= ceil(log(limy)/log(2));
    printf("\n\tPara x %d bits",mjx);
    printf("\n\tPara y %d bits",mjy);

    int numbitx, numbity;
    numbitx = pow(2,mjx)-1;                     //SE NECESITA DISMINUIR 2 EN VEZ DE 1 PARA PONER REALIZAR CAMBIOS EN LOS BITS PARA LOS ALEATORIOS
    numbity = pow(2,mjy)-1;
    printf("\nmaxbit x: %d  &  maxbit y: %d\n",numbitx,numbity);
                                                                    //EJEMPLOS CON AND PARA VERIFICAR QUE SE HAGA LA RESTRICCION
    int ej1=25730, ej2=34769;
    printf(" %d \n",ej1&numbitx);
    printf(" %d \n",ej2&numbity);


    system("pause");


    float x1[5][1], y1[5][1], res1[5][1];           //ARREGLOS PARA CREACION DE NUMEROS (AQUI VAMOS A PONER ALEATORIOS)
    int k;
    unsigned char valido;
    for ( j=0 ; j<5 ; j++){
        valido=0;
        while(valido!=restricciones){

            printf("Ingrese X & Y:  ");
            //x1[j][i]=rand();
            //x1[j][i]=x1[j][i] % numbitx;
            //y1[j][i]=rand();
            //y1[j][i]=y1[j][i] % numbity;
            scanf( "%f %f",&x1[j][i],&y1[j][i] );
            for(k=0 ; k<restricciones ; k++){
                if( signo[k][i]==1 ){
                    res1[j][i] = x[k][i]*x1[j][i] + y[k][i]*y1[j][i];
                    if(res1[j][i]>=0){
                        if(condicion[k][i]==1){
                            if(res1[j][i]>=res[k][i]){
                                printf("%c R%d  ",2,k+1);
                                valido++;
                            }
                            else
                                printf("X R%d  ",k+1);
                        }
                        else{
                            if(res1[j][i]<=res[k][i]){
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
                else{
                    res1[j][i] = x[k][i]*x1[j][i] - y[k][i]*y1[j][i];
                    if(res1[j][i]>=0){
                        if(condicion[k][i]==1){
                            if(res1[j][i]>=res[k][i]){
                                printf("%c R%d  ",2,k+1);
                                valido++;
                            }
                            else
                                printf("X R%d  ",k+1);
                        }
                        else{
                            if(res1[j][i]<=res[k][i]){
                                printf("%c R%d  ",2,k+1);
                                valido++;
                            }
                            else
                                printf("X R%d  ",k+1);
                        }
                    }
                    else
                        printf("X R%d",k+1);
                }
                //printf(" %.2f ",res1[j][i]);
            }
            if( valido == restricciones){
                printf("\t%.2f & %.2f es VALIDO\n",x1[j][i],y1[j][i]);
            }
            else{
                printf("\tINTRODUCE UN NUEVO NUMERO\n",x1[j][i],y1[j][i]);
            }

        }
    }
    int g;
    for(g=0 ; g<5 ; g++){
        printf("\t%.2f & %.2f\n",x1[g][i],y1[g][i]);
    }

    printf("\n000000000000000000000000000000\n");
    /*
    if(){

    }
    */


    return 0;
}
