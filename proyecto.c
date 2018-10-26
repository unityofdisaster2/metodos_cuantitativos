#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
    float aob=0.2,bob=0.5,cob=0,dob=0,eob=0;                                 //VARIABLES PARA GUARDAR LA FUNCION OBJETIVO
    //unsigned char signoob=1;                              //VARIABLES PARA GUARDAR LA FUNCION OBJETIVO
    /*
    printf("\nIntroduce la funcion objetivo:  ");
    scanf("%f %c %f",&xob,&signoob,&yob);
    if(signoob==43)                                 //SI EL SIMBOLO ES SUMA (SIGNO VALE 1)
            signoob=1;
    else                                            //SI EL SIGNO ES RESTA (SIGNO VALE 2)
            signoob=2;
    */
    srand(time(NULL));
    int rest=4;
    /*
    printf("\nNumero de rest: ");
    scanf("%d",&rest);                     //PIDE CUANTAS rest VAS A QUERER
    printf("\n");
    */
    float a[5]={1,1,1,0,0},b[5]={6,1,0,0,0},c[5]={0,0,0,1,0},d[5]={0,0,0,0,0},e[5]={0,0,0,0,0},res[5]={20000,6000,4000,2000,0};  //ARREGLOS PARA GUARDAR LAS rest
    float al[5],bl[5],cl[5],dl[5],el[5];
    char condicion[5][2]={1,1,1,1,0};                                   //ARREGLO PARA GUARDAR CONDICION(NECESITA [>><<][>><<] POR QUE SON DOS CARACTERES)
    float valor_a[5],valor_b[5],valor_c[5],valor_d[5],valor_e[5];       //ARREGLO PARA GUARDAR DIVISION (LIMITES)
    int j, i=0;
    float amax=100000,amin=0,bmax=100000,bmin=0,cmax=100000,cmin=0,dmax=1,dmin=0,emax=1,emin=0;    //INICIALIZO MIN EN 0(NEGATIVIDAD) Y MAX EN UN N MUY GRANDE
    for(j = 0; j<rest; j++){                    //ESTE FOR PEDIRA CADA RESTRICCION

/*************************************************************************************/

        if(a[j]==0)                             //VALIDACION SI A ES IGUAL A 0
            valor_a[j]=0;
        else                                    //SI A ES DIF DE 0 HACE LA DIVISIÓN
            valor_a[j] = res[j] / a[j];

        if(b[j]==0)                             //VALIDACION SI B ES IGUAL A 0
            valor_b[j]=0;
        else                                    //SI B ES DIF DE 0 HACE LA DIVICION
            valor_b[j] = res[j]/b[j];

        if(c[j]==0)                             //VALIDACION SI C ES IGUAL A 0
            valor_c[j]=0;
        else                                    //SI C ES DIF DE 0 HACE LA DIVISIÓN
            valor_c[j] = res[j] / c[j];

        if(d[j]==0)                             //VALIDACION SI D ES IGUAL A 0
            valor_d[j]=0;
        else                                    //SI D ES DIF DE 0 HACE LA DIVISIÓN
            valor_d[j] = res[j] / d[j];

        if(e[j]==0)                             //VALIDACION SI E ES IGUAL A 0
            valor_e[j]=0;
        else                                    //SI E ES DIF DE 0 HACE LA DIVISIÓN
            valor_e[j] = res[j] / e[j];


        if(!strcmp(condicion[j],">="))             //SI LA CONDICION ES <= ( CONDICION VALE 1 )
            condicion[j][i]=1;
        else{                                       //SI LA CONDICION ES >= ( CONDICION VALE 2 )
            condicion[j][i]=2;
            printf("Menor\n");
                                                    //ENTONCES
            if(a[j]!=0)                             //SI A DE RESTRICCION ES DIF DE 0
                al[j]=res[j]/a[j];                  //A LIM ES (RES DE RESTRICCION / A DE RESTRICCION)
            else                                    //SI A DE RESTRICCION ES 0
                al[j]=amax;                         //A LIM ES AMAX

            if(b[j]!=0)                             //SI B DE RESTRICCION ES DIF DE 0
                bl[j]=res[j]/b[j];                  //B LIM ES (RES DE RESTRICCION / B DE RESTRICCION)
            else                                    //SI B DE RESTRICCION ES 0
                bl[j]=bmax;                         //B LIM ES BMAX

            if(c[j]!=0)                             //SI C DE RESTRICCION ES DIF DE 0
                cl[j]=res[j]/c[j];                  //C LIM ES (RES DE RESTRICCION / C DE RESTRICCION)
            else                                    //SI C DE RESTRICCION ES 0
                cl[j]=cmax;                         //C LIM ES CMAX

            if(d[j]!=0)                             //SI D DE RESTRICCION ES DIF DE 0
                dl[j]=res[j]/d[j];                  //D LIM ES (RES DE RESTRICCION / D DE RESTRICCION)
            else                                    //SI D DE RESTRICCION ES 0
                dl[j]=dmax;                         //D LIM ES DMAX

            if(e[j]!=0)                             //SI E DE RESTRICCION ES DIF DE 0
                el[j]=res[j]/e[j];                  //E LIM ES (RES DE RESTRICCION / E DE RESTRICCION)
            else                                    //SI E DE RESTRICCION ES 0
                el[j]=emax;                         //E LIM ES EMAX

            if(al[j]<amax || bl[j]<bmax || cl[j]<cmax || dl[j]<dmax || el[j]<emax){     //EN CASO DE QUE (A LIM ES MENOR A AMAX) Ó (B LIM ES MENOR A BMAX+++)
                amax=al[j];                         //AMAX ES IGUAL A A LIM
                bmax=bl[j];                         //BMAX ES IGUAL A B LIM
                cmax=cl[j];                         //CMAX ES IGUAL A C LIM
                dmax=dl[j];                         //DMAX ES IGUAL A D LIM
                emax=el[j];                         //EMAX ES IGUAL A XE LIM
            }                                       //DE ESTA MANERA SE ACTUALIZA LOS LIMITES REALES DE LAS CONDICIONES PARA LA GENERACION DE NUMEROS
        }
    }

    printf("---------------------\n");
    printf("Amax %.2f   Amin %.2f\n",amax,amin);
    printf("Bmax %.2f   Bmin %.2f\n",bmax,bmin);
    printf("Cmax %.2f   Cmin %.2f\n",cmax,cmin);
    printf("Dmax %.2f   Dmin %.2f\n",dmax,dmin);
    printf("Emax %.2f   Emin %.2f\n",emax,emin);
    printf("---------------------");

/*************************************************************************************/

    unsigned char bits=0;
    int mja,mjb,mjc,mjd,mje;
    int lima,limb,limc,limd,lime;;
    /*
    printf("\nINGRESE EL NUMERO DE BITS: ");
    scanf("%d",&bits);
    */
    lima=(amax-amin)*(pow(10,bits));
    limb=(bmax-bmin)*(pow(10,bits));
    limc=(cmax-cmin)*(pow(10,bits));
    limd=(dmax-dmin)*(pow(10,bits));
    lime=(emax-emin)*(pow(10,bits));

    mja= ceil(log(lima)/log(2));
    mjb= ceil(log(limb)/log(2));
    mjc= ceil(log(limc)/log(2));
    mjd= ceil(log(limd)/log(2));
    mje= ceil(log(lime)/log(2));

    printf("\n\tPara A %d bits",mja);
    printf("\n\tPara B %d bits",mjb);
    printf("\n\tPara C %d bits",mjc);
    printf("\n\tPara D %d bits",mjd);
    printf("\n\tPara E %d bits",mje);
    printf("\n---------------------");

/*************************************************************************************/

    int numbita,numbitb,numbitc,numbitd,numbite;
    numbita = pow(2,mja)-1;                     //SE NECESITA DISMINUIR 2 EN VEZ DE 1 PARA PONER REALIZAR CAMBIOS EN LOS BITS PARA LOS ALEATORIOS
    numbitb = pow(2,mjb)-1;
    numbitc = pow(2,mjc)-1;                     //SE NECESITA DISMINUIR 2 EN VEZ DE 1 PARA PONER REALIZAR CAMBIOS EN LOS BITS PARA LOS ALEATORIOS
    numbitd = pow(2,mjd)-1;
    numbite = pow(2,mje)-1;                     //SE NECESITA DISMINUIR 2 EN VEZ DE 1 PARA PONER REALIZAR CAMBIOS EN LOS BITS PARA LOS ALEATORIOS
    if(numbita==0)
        numbita=1;
    if(numbitb==0)
        numbitb=1;
    if(numbitc==0)
        numbitc=1;
    if(numbitd==0)
        numbitd=1;
    if(numbite==0)
        numbite=1;

    printf("\n\nmaxbit A: %d | maxbit B: %d | maxbit C: %d | maxbit D: %d | maxbit E: %d",numbita,numbitb,numbitc,numbitd,numbite);

/*************************************************************************************/

    int auxintx=0, auxinty=0;
    float auxfloatx=0, auxfloaty=0;
    unsigned char valido;
    int k;              //VARIABLES PARA EL FOR DE COMPARACION DE rest CON LOS NUMERO GENERADOS
    int f;              //VARIABLES PARA CUANTOS NUMEROS SE DESEAN GENERAR.
    float taux=0;       //VARIABLES PARA DETERMINAR LA SUMA DE LOS VALORES PROMEDIOS DE ZJ (tzj[>><<])

    printf("\n\nCuantos numeros deseas generar:  ");
    scanf("%d",&f);

    float ta[f],tb[f],tc[f],td[f],te[f],tzj[f],tpzj[f],tzjacum[f],tzjacc=0,tale[f],tvect[f]; //ARREGLOS PARA CALCULOS DE F1

    float a1[f],b1[f],c1[f],d1[f],e1[f],res1[f];           //ARREGLOS PARA CREACION DE NUMEROS (AQUI VAMOS A PONER ALEATORIOS)
    for ( j=0 ; j<f ; j++){
        valido=0;
        while(valido!=rest){
            a1[j]=rand()%numbita;
            b1[j]=rand()%numbitb;
            c1[j]=rand()%numbitc;
            d1[j]=rand()%numbitd;
            e1[j]=rand()%numbite;
//            printf("\nA%.0f  B%.0f  C%.0f  D%.0f  E%.0f\n",a1[j],b1[j],c1[j],d1[j],e1[j]);
            for(k=0 ; k<rest ; k++){
                res1[j] = a[k]*a1[j] + b[k]*b1[j] + c[k]*c1[j] + d[k]*d1[j] + e[k]*e1[j];
                if(res1[j]>=0){
                    if(condicion[k][i]==1){             //RESTRICCION MAYOR IGUAL
                        if(res1[j]>=res[k]){
                            //printf("%c R%d  ",2,k+1);
                            valido++;
                        }
                        //else
                            //printf("X R%d  ",k+1);
                    }
                    else{                               //RESTRICCION MENOR IGUAL
                        if(res1[j]<=res[k]){
                            //printf("%c R%d  ",2,k+1);
                            valido++;
                        }
                        //else
                            //printf("X R%d  ",k+1);
                    }
                }

            }
            if( valido == rest){
                                                                        //ESTA SERA UNA FUNCIÓN
                ta[j]= amin + ( a1[j]*( (amax-amin)/numbita) );
                tb[j]= bmin + ( b1[j]*( (bmax-bmin)/numbitb) );
                tc[j]= cmin + ( c1[j]*( (cmax-cmin)/numbitc) );
                td[j]= dmin + ( d1[j]*( (dmax-dmin)/numbitd) );
                te[j]= emin + ( e1[j]*( (emax-emin)/numbite) );

                tzj[j]=aob*ta[j] + bob*tb[j] + cob*tc[j] + dob*td[j] + eob*te[j];
                taux=taux+tzj[j];
                                                                        //AQUI TERMINARA LA FUNCIÓN
            }
            else{
                //printf("\tINTRODUCE UN NUEVO NUMERO\n",x1[j],y1[j]);
                valido=0;
            }
        }
    }
    printf("\n");
/*************************************************************************************/
    int g;

    tzjacum[0]=0;
    int conta[f];
    for(g=0 ; g<f ; g++){
        //printf("\t%d.-   %.2f & %.2f\n",g+1,x1[g][i],y1[g][i]);
        tpzj[g]=tzj[g]/taux;
        tzjacc=tzjacc+tpzj[g];
        tzjacum[g]=tzjacc;
//        printf("  %d  %.2f | %.2f | %.2f | %.5f | %.5f\n",g+1,tx[g],ty[g],tzj[g],tpzj[g],tzjacum[g]);
        conta[g]=0;
    }

/*************************************************************************************/

    printf(" VEC |   A    |    B    |    C    |  D   |  E   |   ZJ    |   PZJ   |  PZJAC  |  #RAND  | VECTOR\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    float alet[f];
    for(g=0 ; g<f ; g++){
        alet[g]=(rand()%1000)/1000.0;
        printf("  %d  |%.2f | %.2f\t| %.2f | %.2f | %.2f | %.2f  | %.5f | %.5f | %.3f\t| ",g+1,ta[g],tb[g],tc[g],td[g],te[g],tzj[g],tpzj[g],tzjacum[g],alet[g]);
        for(j=0 ; j<f ; j++){
            if(alet[g]>tzjacum[j]){
//                printf("\t%d\n",j);
            }
            else{
                printf("Vect %d\n",j+1);
                conta[j]++;
                j=f;
            }
        }
    }

/*************************************************************************************/

    for(g=0 ; g<f ; g++){
        if(conta[g]==0)
            printf("\n  Vector  %d  NO APARECE",g+1,conta[g]);
        else if(conta[g]==1)
            printf("\n  Vector  %d  aparece  %d  vez",g+1,conta[g]);
        else
            printf("\n  Vector  %d  aparece  %d  veces",g+1,conta[g]);
    }
    printf("\n");

    return 0;
}
