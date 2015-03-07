#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int n,i,j,k,l,p;
    double *c,t,pivot,m;

    double max;
    int maxI;

    // The size of the matrix
    n=4;

    c=(double*) malloc(sizeof(double)*n);

    // This is already the expanded matrix
    // Dont mess up the
    double a[4][5]={
       {4   ,-2  ,-3   ,6   ,12   },
       {-6  ,7   ,6.5  ,-6  ,-6.5 },
       {1   ,7.5 ,6.25 ,5.5 ,16   },
       {-12 ,22  ,15.5 ,-1  ,17   },
    };

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
            a[k][n]-=a[k][i]*c[i];
        }
    }

    for(i=0;i<n;i++){
        printf("%+.18lf\n",c[i]);
    }

    free(c);

    return EXIT_SUCCESS;
}
