//10am~10.27am
#include <stdio.h> //pour pouvoir utiliser printf et scanf
//scanf pour lire (rdw)
//printf pour afficher (lwd)


int main(void){
    //déclaration et initialisation des variables:
    int age = 0;
    int const annee = 2023; //année actuelle; `const` est read-only
    int annee_naissance = 0;

    //1. demande son âge à l'utilisateur ;
    //Pour demander à l'utilisateur son âge, affichez un message à l'aide de l'instruction suivante :
    printf("Quel age avez-vous ?");

    //2. lit la réponse de l'utilisateur et l'enregistre dans une variable age de type entier ;
    //Pour lire la réponse de l'utilisateur et l'enregistrer dans la variable age de type entier, utilisez l'instruction suivante :
    scanf("%d", &age);
    //3. calcule l'année de naissance (à un an près) de l'utilisateur et l'enregistre dans la variable annee de type entier ;
    annee_naissance = annee-age;
    
    //4. affiche l'année de naissance ainsi calculée.
    printf("Vous etes ne(e) en %d\n", annee_naissance);
    // \n pour aller à la ligne

    /*
    Pour afficher du texte et des variables entières, indiquez chaque variable par un code spécifique ( %d pour les entiers, %f pour les réels), et
    passez ensuite ces variables comme paramètres supplémentaire à printf.
    Exemple :
    printf("message 1 %d, message2 %d\n", var1, var2);

    Donc ici:
    printf("msg %d\n", variable);
    */

    return 0;//pour dire que tout s'est bien passé
}



