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

//
int resultado = modular_exponentiation(&base, &expoente, &modulo);
printf("A exponencial modular de %d elevado a %d (mod %d) eh %d\n", base, expoente, modulo, resultado);

  return 0;
}

int is_lower_than_parameter(int * num){
  if ( (*num < 65535) & !(*num < 0) ) return 1;
  else return 0;
}

void error(){
  printf("Entradas inválidas\n");
  exit(0); //encerra o programa
}

int is_prime(int *num){
  double m = round(sqrt(*num));
}

int modular_exponentiation(int *base, int *exp, int *modulo){
  return ( (int)pow(*base, *exp) % *modulo);
}
