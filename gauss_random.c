#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int n,i,j,k,l,p,maxI;
    double **a,*b,*c,t,pivot,m,max;

    // The size of the matrix
    n=2000;

    a=(double**)malloc(sizeof(double)*n);
    b=(double*) malloc(sizeof(double)*n);
    c=(double*) malloc(sizeof(double)*n);
    for(i=0;i<n;i++){
        a[i]=(double*)malloc(sizeof(double)*(n+1));
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j]=(drand48()*500)-1000;
        }
    }

    for(i=0;i<n;i++){
        t=(drand48()*500)-1000;
        b[i]=t;
        a[i][n]=t;
    }

    // Gaussian elimination
    for(i=0;i<n;i++){
        for(k=i+1;k<n;k++){
            m=-a[k][i]/a[i][i];
            for(j=i;j<n+1;j++){
                a[k][j]=a[k][j]+m*a[i][j];
            }
        }
    }

    // Backward substitute
    for(i=n-1;i>=0;i--){
        c[i]=a[i][n]/a[i][i];
        for(k=i-1;k>=0;k--){
            //printf("%d %d %d\n",i,k,n);
            a[k][n]-=a[k][i]*c[i];
        }
    }

    for(i=0;i<n;i++){
        printf("%+.18lf\n",c[i]);
    }

    return EXIT_SUCCESS;
}
