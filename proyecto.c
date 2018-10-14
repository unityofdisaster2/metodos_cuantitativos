#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    int restricciones;
    scanf("%d",&restricciones);
    float x[5][1],y[5][1],res[5][1];
    unsigned char signo[5][1];
    char condicion[5][2];
    float valor_x[5][1],valor_y[5][1];
    int j, i=0;
    for(j = 0; j<restricciones; j++){
        scanf("%f %c %f %s %f",&x[j][i],&signo[j][i],&y[j][i],&condicion[j],&res[j][i]);

        if(x[j][i]==0){
            valor_x[j][i]=0;
            printf("X %.2f ",valor_x[j][i]);
        }
        else{
            printf("X %.2f ",x[j][i]);
            valor_x[j][i] = res[j][i] / x[j][i];
            printf("LIMX %.2f ",valor_x[j][i]);
        }

        if(y[j][i]==0){
            valor_y[j][i]=0;
        }
        else{
            valor_y[j][i] = res[j][i]/y[j][i];
        }

        if(signo[j][i]==43){
            printf("suma ");
            signo[j][i]=1;
        }
        else{
            printf("resta ");
            signo[j][i]=2;
        }

        if(!strcmp(condicion[j],">=")){
            printf("MAYOR igual\n");
            condicion[j][i]=1;
        }
        else{
            printf("MENOR igual\n");
            condicion[j][i]=2;
        }
    }

    float xmax=0,ymax=0,xmin=0,ymin=0;

    if(valor_x[0][0]>valor_x[1][0]){
        xmax = valor_x[0][0];
    }
    else{
        xmax = valor_x[1][0];
    }
    for (j=2; j<restricciones; j++){
        if(valor_x[j][0]>xmax){
            xmax = valor_x[j][0];
        }
    }

    if(valor_y[0][0]>valor_y[1][0]){
        ymax = valor_y[0][0];
    }
    else{
        ymax = valor_y[1][0];
    }
    for (j=2; j<restricciones; j++){
        if(valor_y[j][0]>ymax){
            ymax = valor_y[j][0];
        }
    }

    printf("-----------\n",xmax);
    printf("xmax %.2f\n",xmax);
    printf("xmin %.2f\n",xmin);
    printf("ymax %.2f\n",ymax);
    printf("ymin %.2f\n",ymin);

    float x1[5][1], y1[5][1], res1[5][1];
    int k;
    for ( j=0 ; j<3 ; j++){
        scanf( "%f %f",&x1[j][i],&y1[j][i] );
        for(k=0 ; k<restricciones ; k++){       //CHECAR QUE HAGA TODAS LAS CONDICIONES
            if( signo[k][i]==1 ){
                res1[j][i]=x1[j][i]+y1[j][i];
                if(condicion[k][i]==1){
                    if(res1[j][i]>res[k][i]){
                        printf("VALIDO1\n");
                    }
                    else
                        printf("INVALIDO2 pedir nuevo\n");
                }
                else{
                    if(res1[j][i]>res[k][i]){
                        printf("INVALIDO3 pedir nuevo\n");
                    }
                    else
                        printf("VALIDO4\n");
                }
            }
            else{
                res1[j][i]=x1[j][i]-y1[j][i];
                if(condicion[k][i]==1){
                    if(res1[j][i]>res[k][i]){
                        printf("VALIDO5\n");
                    }
                    else
                        printf("INVALIDO6 pedir nuevo\n");
                }
                else{
                    if(res1[j][i]>res[k][i]){
                        printf("INVALIDO7 pedir nuevo\n");
                    }
                    else
                        printf("VALIDO8\n");
                }
            }
        }
        printf("\t%.2f\n",res1[j][i]);
    }
    return 0;
}
