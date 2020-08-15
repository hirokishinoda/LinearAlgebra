#include <stdio.h>
#include <math.h>

#define N 2
//#define M_PI 3.141592653589793
#define CNT_MAX 100
#define EPS 0.000000001

void jacobi(double mat[N][N], double x[N][N]);
void disp_eigenval(double mat[N][N]);
void disp_eigenvec(double x[N][N]);

int main(void){
  double mat[N][N] = {{ 2, -2},
                      {-2, -1}};
  double x[N][N] = {0};

  jacobi(mat, x);

  return 0;
}

void jacobi(double mat[N][N], double x[N][N]){
  int i,j,k,m,count;
  double max_nd, tmp_max_nd, theta, co, si, co_sq, si_sq, cosi, aii, aij, ajj, aik, ajk;

  for(i = 0;i < N;i++){
    for(j = 0;j < N;j++){
      if (i == j) x[i][j] = 1;
      else x[i][j] = 0;
    }
  }
  count = 0;
  while(count < CNT_MAX){
    max_nd = 0.0;
    for(k = 0;k < N-1;k++){
      for(m = k+1;m < N;m++){
        tmp_max_nd = fabs(mat[k][m]);
        if(tmp_max_nd > max_nd){
          i = k;
          j = m;
          max_nd = tmp_max_nd;
        }
      }
    }

    if(max_nd <= EPS) break;
    else{
      aii = mat[i][i];
      ajj = mat[j][j];
      aij = mat[i][j];

      if(fabs(aii - ajj) < EPS){
        theta = 0.25* M_PI *aij / fabs(aij);
      }else{
        theta = 0.5 * atan(2.0 * aij / (aii - ajj));
      }
      co = cos(theta);
      si = sin(theta);
      co_sq = co * co;
      si_sq = si * si;
      cosi = co * si;

      mat[i][i] = co_sq * aii + 2.0 * cosi * aij + si_sq * ajj;
      mat[j][j] = si_sq * aii - 2.0 * cosi * aij + co_sq * ajj;
      mat[i][j] = mat[j][i] = 0;

      for(k = 0;k < N;k++){
        if(k != i && k!= j){
          ajk = mat[k][j];
          aik = mat[k][i];
          mat[k][i] = co * aik + si * ajk;
          mat[i][k] = mat[k][i];
          mat[k][j] = -si * aik + co * ajk;
          mat[j][k] = mat[k][j];
        }
      }

      for(k = 0;k < N;k++){
        ajk = x[k][j];
        aik = x[k][i];
        x[k][i] = co * aik + si *ajk;
        x[k][j] = -si * aik + co * ajk;
      }

      count++;
    }
  }

  disp_eigenval(mat);
  disp_eigenvec(x);
}

void disp_eigenval(double mat[N][N]){
  int i,j;

  for(i = 0;i < N;i++){
    for(j = 0;j < N;j++){
      if (i == j) printf("%lf, ", mat[i][j]);
    }
  }
  puts("");
}

void disp_eigenvec(double x[N][N]){
  int i,j;
  for(i = 0;i < N;i++){
    for(j = 0;j < N;j++){
      printf("%lf, ", x[i][j]);
    }
    puts("");
  }
}
