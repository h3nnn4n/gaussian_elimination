// C implementation of Gaussian elemination
// for solving linear systems.
// Features also partial pivotation.
// Precision limited to Double
// The rows are statics,
// they are swapped using a symbolic vector.
//
// Renan S Silva
// Análise Numérica

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void print_matrix(double**,int);

int main(){
    int n,i,j,k,q,*l;
    double **a,*b,*c,*p,t,pivot,m;

    double rmax,smax;
    int maxI;

    printf("Gaussian elimination with partial pivotation.\n Size of the matrix: ");
    scanf("%d",&n);

    a=(double**)malloc(sizeof(double)*n);
    b=(double*) malloc(sizeof(double)*n);
    c=(double*) malloc(sizeof(double)*n);
    p=(double*) malloc(sizeof(double)*n);
    l=(int*) malloc(sizeof(int)*n);
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
    printf("\n\nSolving...\n\n");

    for(i=0;i<n;i++){
        l[i]=i;
        smax=0;
        for(j=0;j<n;j++){
            if(fabs(a[i][j])>smax){
                smax=fabs(a[i][j]);
            }
        }
        p[i]=smax;
    }

    for(i=0;i<n;i++){
        rmax=0;
        for(k=i;k<n;k++){
            t=fabs(a[l[k]][i]/p[l[k]]);
            if(t>rmax){
                rmax=t;
                j=k;
            }
        }

        m=l[j];
        l[j]=l[i];
        l[i]=m;

        for(k=i+1;k<n;k++){
            m=-a[l[k]][i]/a[l[i]][i];
            for(j=i;j<n+1;j++){
                a[l[k]][j]=a[l[k]][j]+m*a[l[i]][j];
            }
        }
    }

    c[n-1]=a[l[n-1]][n]/a[l[n-1]][n-1];
    for(i=n-2;i>=0;i--){
        m=a[l[i]][n];
        for(k=i+1;k<n;k++){
            m-=a[l[i]][k]*c[k];
        }
        c[i]=m/a[l[i]][i];
    }

    printf("Done!\n\nThe solution is:\n");

    for(i=0;i<n;i++){
        printf("%+lf\n",c[i]);
    }

    free(a);
    free(b);
    free(c);
    free(l);
    free(p);

    return EXIT_SUCCESS;
}

void print_matrix(double **a,int n){
    int i,j;
    printf("------------------------------------\n");
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            printf("%7.2lf\t",a[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------\n");
}
