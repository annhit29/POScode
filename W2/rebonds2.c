//1pm~ 1.33pm

//Écrivez le programme rebonds2.c qui calcule et affiche le nombrede  rebonds NBR en fonction de
//combien de rebonds fait cette balle avant que la hauteur à laquelle elle rebondit soit plus petite que (ou égale à) une hauteur donnée h_fin.

#include <stdio.h>
#include <math.h> //pour les fonctions mathématiques tq sqrt()

//TODO: outside or inside main()?
//outside, coz global variable
double const g = 9.81; //read-only variable

int main(void){
    double h; //hauteur initiale de la balle en m (H0) 
    double eps;
    int NBR;
    double h_fin;
    
    printf("Entrez a hauteur initiale H0 ≥ 0: ");
    
    scanf("%lf", &h);
    printf("Entrez le coefficient de rebond, contrainte 0 ≤ eps < 1: ");
    
    scanf("%lf", &eps);
    printf("Entrez la hauteur finale h_fin ≥ 0: ");
    
    scanf("%lf", &h_fin);

    // calcule la hauteur à laquelle la balle remonte après le nombre NBR de rebonds spécifié

    do{
        double v = sqrt(2.0*g*h);
        double v1 = eps*v;
        double h1 = (v1*v1)/(2*g);
        h =h1; //.⭐update h for next loop iteration coz h1 is a local variable in the loop scope 
        // h1 devient la nouvelle hauteur initiale
        printf("DEBUG NBR %d = :\n", NBR);
    }while(h>=h_fin);
    

    printf("Le nombre de rebonds NBR%d est\n", NBR);
    
    return 0;//pour dire que tout le prgm main s'est bien passé
}