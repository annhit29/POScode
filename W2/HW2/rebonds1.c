//1pm~ 1.33pm

//Écrivez le programme rebonds1.c qui calcule et affiche la hauteur à laquelle la balle remonte après le nombre NBR de rebonds spécifié.
#include <stdio.h>
#include <math.h> //pour les fonctions mathématiques tq sqrt()

//TODO: outside or inside main()?
//outside, coz global variable
double const g = 9.81; //read-only variable

int main(void){
    double h; //hauteur initiale de la balle en m (H0) 
    double eps;
    int NBR;
    
    printf("Entrez a hauteur initiale H0 ≥ 0: ");
    
    scanf("%lf", &h);
    printf("Entrez le coefficient de rebond, contrainte 0 ≤ eps < 1: ");
    
    scanf("%lf", &eps);
    printf("Entrez le nombre de rebonds NBR ≥ 0: ");
    
    scanf("%d", &NBR);

    // calcule la hauteur à laquelle la balle remonte après le nombre NBR de rebonds spécifié
    for(int i =1; i <=NBR; ++i){
        double v = sqrt(2.0*g*h);
        double v1 = eps*v;
        double h1 = (v1*v1)/(2*g);
        h =h1; //.⭐update h for next loop iteration coz h1 is a local variable in the loop scope 
        // h1 devient la nouvelle hauteur initiale

        printf("rebond %d : %f\n", i, h);
    }
    

    printf("Au %dème rebond, la hauteur sera de %f m.\n", NBR, h);
    
    return 0;//pour dire que tout le prgm main s'est bien passé
}