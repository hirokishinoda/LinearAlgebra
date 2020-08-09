#include <stdio.h>

#define N 3

int gauss(double a[N][N+1]){
  int i, j, k;
  double x[N];

  for(k = 0;k < N;k++){
    for(j = k+1;j < N+1;j++){
      a[k][j] = a[k][j] / a[k][k];
      for(i = k+1;i < N;i++){
        a[i][j] = a[i][j] - a[k][j] * a[i][k];
      }
    }
  }

  x[N-1] = a[N-1][N];
  for(k = N-1;k >= 0;k--){
    x[k] = a[k][N];
    for(j=k+1;j < N;j++){
      x[k] = x[k] - a[k][j] * x[j];
    }
  }

  for(i = 0;i < N;i++){
    printf("x[%d] = %f\n",i,x[i]);
  }
}

int main(void){
  /*no22-2 3 4 -6*/
  double map[N][N+1] = {{3, -1, 2, -7},
                        {-1, 5, -3, 35},
                        {1, -1, 3, -19}};

  gauss(map);

    return 0;
}
