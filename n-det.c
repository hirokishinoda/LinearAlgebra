#include <stdio.h>

#define N 4

double dateminant(double mat[N][N]);
void print_mat(double mat[N][N]);

int main(void){
  /* p.49 ex1 ans=7
  double mat[N][N] = {{2, 3, 0},
                   {0, 2, 1},
                   {5,-4,-4}};*/
  /*p.61 No17-1 ans=66 
  double mat[N][N] = {{-1, 2, 3},
                      {4, 0, 2},
                      {-2, 3,-4}};*/

  /*p.61 No17-1 ans=-900 */
  double mat[N][N] = {{2, 4, -3, 4},
                      {-5, 2, 1, 5},
                      {-3, 4, 2, -1},
                      {4, 6, -7, -2}};

  printf("%lf\n",dateminant(mat));

  return 0;
}

double init_table(double mat[N][N]){
  int i,j;

  for(i = 0;i < N;i++){
    for(j = 0;j < N;j++;){
      map[i][j] = 0;
    }
  }
}

double dateminant(double mat[N][N]){
  double det = 1;
  double tmp = 0;
  int i,j,k;

  for (k = 0;k < N;k++){
    if(mat[k][k] == 0){
      for(i = k+1;i < N;i++){
        if(mat[i][k] != 0){
          for(j = k+1;j < N;j++){
            tmp = mat[i][j];
            mat[i][j] = mat[k][j];
            mat[k][j] = tmp;
          }
        }
      }
    }else{
      for(i = k+1;i < N;i++){
        for(j = k+1;j < N;j++){
          mat[i][j] -= (mat[k][j] / mat[k][k]) * mat[i][k];
        }
      }
    }
    det *= mat[k][k];
    //print_mat(mat);
  }
  return det;
}

void print_mat(double mat[N][N]){
  int i,j;

  for(i = 0;i < N;i++){
    for(j = 0;j < N;j++){
      printf("%f ", mat[i][j]);
    }
    puts("");
  }
}
