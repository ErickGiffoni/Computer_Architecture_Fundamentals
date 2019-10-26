#include <stdio.h>

void read_inputs(int *x, int *e);
int verify_inputs(int *x, int *e);
double my_sqrt(int *x, int *e, int *iterations);
void error(int error_code, int *x);
//void print_out(double *result, int *x, int *iterations);

int main(){

  int x, e, iterations=0;
  double result;

  read_inputs(&x, &e);

  if (verify_inputs(&x, &e) == 0){
      error(0, &x);
      return 0;
  }

  result = my_sqrt(&x, &e, &iterations);
  printf("result = %.15lf\niterations = %d\n", result, iterations);

  if (result == 0) error(1, &x);

  //print_out(&result, &x, &iterations);

  return 0;
}

void read_inputs(int *x, int *e){
  scanf("%d", x);
  scanf("%d", e);
}

int verify_inputs(int *x, int *e){
// x > 1
// e > 0
  if(*x < 2 || *e <= 0) return 0; //error
  return 1; //all right
}

double my_sqrt(int *x, int *e, int *iterations){
//calculate error
  double prox_error = 10.0 ;
  for(int i=2; i <= *e; i++) prox_error = prox_error * 10.0;
  prox_error = 1.0/prox_error;
//find a1 and b1
  double an = 10.0;
  double bn = *x / 10.0; //duvida: isso da double ou int ?
  *iterations += 1;
  double error = bn - an;

while(*iterations < 100){
  if(error < 0) error *= (-1); //set error to a positive value
  if (error < prox_error) return bn;
  printf("iteration %d\n\n\terror = %.7lf\n\n\tprox_error = %.7lf\n\n", *iterations, error, prox_error);
  an = (an + bn) / 2.0;
  bn = *x / an;
  error = bn - an;
  printf("actual error = %.7lf\n", error);
  *iterations += 1;
}

  return 0;
}

void error(int error_code, int *x){
// 0 -> invalid input
  if(error_code == 0) printf("Entradas invalidas.\n");
// 1 -> iterations out of limit
  else if(error_code == 1) printf("Nao foi possivel calcular sqrt(%d)\n", *x);
  return ;
}

//void print_out(double *result, int *x, int *iterations){
//
//}
