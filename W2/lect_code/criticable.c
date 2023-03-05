#include <stdio.h>
#include <math.h>

// ======================================================================
int main(void)
{
  double x = 0.0;
  printf("Entrez un nombre réel : ");
  scanf("%lf", &x);

  double resultat = 0.0;

  // Expression 1
  printf("Expression 1 : ");
  if (x == 0.0) {
      printf("non définie\n");
  } else {
      resultat = x / (1.0 - exp(x));
      printf("%f\n", resultat);
  }

  // Expression 2
  printf("Expression 2 : ");
  if ((x <= 0.0) || (1.0 == x)) {
      printf("non définie\n");
  } else {
      resultat = x * log(x) * exp( 2.0 / (x-1.0) ) ;
      printf("%f\n", resultat);
  }

  // Expression 3
  printf("Expression 3 : ");
  if ( (x > 0.0) && (x < 8.0) ) {
      printf("non définie\n");
  } else {
      resultat = ( -x - sqrt(x*x - 8.0*x) ) / (2.0-x) ;
      printf("%f\n", resultat);
  }

  // Expression 4
  printf("Expression 4 : ");
  if  ((x <= 1.0 ) && (x >= 0.0)) {
      printf("non définie\n");
  } else  {
      resultat = (sin(x) - x/20.0) * log(sqrt(x*x - 1.0/x));
      if (resultat <= 0.0) {
          printf("non définie\n");
      } else {
          printf("%f\n", sqrt(resultat));
      }
  }

  return 0;
}
