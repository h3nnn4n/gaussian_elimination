 // C implementation of Gaussian elemination
 // for solving linear systems.
 // Features also partial pivotation.
 // Precision limited to Double
 //
 // Renan S Silva
 // Análise Numérica

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void print_matrix(double**,int);

int main(){
    int n,i,j,k,l,p;
    double **a,*b,*c,t,pivot,m;

    double max;
    int maxI;

    printf("Gaussian elimination with partial pivotation.\n Size of the matrix: ");
    scanf("%d",&n);

    a=(double**)malloc(sizeof(double)*n);
    b=(double*) malloc(sizeof(double)*n);
    c=(double*) malloc(sizeof(double)*n);
    for(i=0;i<n;i++){
        a[i]=(double*)malloc(sizeof(double)*(n+1));
    }

    printf("Matrix elements:\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&a[i][j]);
        }
    }

    printf("Solution vector:\n");

    for(i=0;i<n;i++){
        scanf("%lf",&t);
        b[i]=t;
        a[i][n]=t;
    }

    printf("Matrix is:\n\n");
    print_matrix(a,n);
    printf("\n\nSolving...\n");

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i][j]>max){
                max=a[i][j];
                maxI=j;
            }
        }

        for(k=i;k<n+1;k++){
            pivot=a[maxI][k];
            a[maxI][k]=a[i][k];
            a[i][k]=pivot;
        }

        for(k=i+1;k<n;k++){
            m=-a[k][i]/a[i][i];
            for(j=i;j<n+1;j++){
                a[k][j]=a[k][j]+m*a[i][j];
            }
        }
    }

    for(i=n-1;i>=0;i--){
        c[i]=a[i][n]/a[i][i];
        for(k=i-1;k>=0;k--){
            a[k][n]-=a[k][i]*c[i];
        }
    }

    printf("Done!\n\nThe solution is:\n");

    for(i=0;i<n;i++){
        printf("%+.18lf\n",c[i]);
    }

    free(a);
    free(b);
    free(c);

    return EXIT_SUCCESS;
}

void print_matrix(double **a,int n){
    int i,j;
    printf("------------------------------------\n");
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            printf("%lf ",a[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------\n");
}
