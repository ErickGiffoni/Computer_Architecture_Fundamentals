#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_lower_than_parameter(int * num);
void error();
int is_prime(int *num);
int modular_exponentiation(int *base, int *exp, int *modulo);

int main(){

int base=0, expoente=0, modulo=0;
scanf("%d", &base);
is_lower_than_parameter(&base) ? 1 : error() ;

scanf("%d", &expoente);
is_lower_than_parameter(&expoente) ? 1 : error() ;

scanf("%d", &modulo);
is_lower_than_parameter(&modulo) ? 1 : error() ;

//checar se o modulo e primo
if (!is_prime(&modulo)){
  printf("O modulo nao eh primo.\n");
  exit(0);
}
//
int resultado = modular_exponentiation(&base, &expoente, &modulo);
printf("A exponencial modular de %d elevado a %d (mod %d) eh %d.\n", base, expoente, modulo, resultado);

  return 0;
}

int is_lower_than_parameter(int * num){
  if ( (*num < 65535) & !(*num <= 0) ) return 1;
  else return 0;
}

void error(){
  printf("Entradas invalidas.\n");
  exit(0); //encerra o programa
}

int is_prime(int *num){
  //using algorithm available on https://en.wikipedia.org/wiki/Primality_test
  if (*num <= 3) return *num > 1;
  if ((*num % 2 == 0) || (*num % 3 == 0)) return 0;
  int i = 5;
  while (i*i <= *num){
    if ((*num % i == 0) || (*num % (i+2) == 0)) return 0;
    i += 6;
  }
  return 1;
}

int modular_exponentiation(int *base, int *exp, int *modulo){
  return ( (int)pow(*base, *exp) % *modulo);
}
