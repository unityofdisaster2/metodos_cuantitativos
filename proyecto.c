#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    int restricciones,j=0;
    scanf("%d",&restricciones);
    int x[5][1],y[5][1],res[5][1];
    unsigned char signo[5][1];
    char condicion[5][2];
    float valor_x[5][1],valor_y[5][1];
    int i;
    for(i = 0; i<restricciones;i++)
    {
        scanf("%d %c %d %s %d",&x[j][i],&signo[j][i],&y[j][i],&condicion[j],&res[j][i]);
        valor_x[j][i] = res[j][i]/x[j][i];
        valor_y[j][i] = res[j][i]/y[j][i];
        if(signo[j][i]==43)
        {
            printf("suma\n");
        }
        else{
            printf("resta\n");
        }
        if(!strcmp(condicion[j],">="))
        {
            printf("1\n");
        }
        else{
            printf("-1\n");
        }
        j +=1;
    }

    float xmax=0,ymax=0,xmin=0,ymin=0;
    if(valor_x[0][0]>valor_x[1][0])
    {
        xmax = valor_x[0][0];
    }
    else
    {
        xmax = valor_x[1][0];
    }
    for (j=2; j<restricciones; j++)
    {
        if(valor_x[j][0]>xmax)
        {
            xmax = valor_x[j][0];
        }
    }
    printf("%f\n",xmax);
    printf("%f\n",xmin);

    return 0;
}