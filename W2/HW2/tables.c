//12.19pm ~ 12.47pm
//Objectif: Ecris un prgm qui affiche les tables de multiplication de 2 à 10.

#include <stdio.h>

int main(void){
    printf("Tables de multiplication\n\n");
    // \n pour sauter une ligne, donc \n\n pour sauter 2 lignes càd 1 ligne vide dans l'output.

    for(int i=2; i<=10; ++i){//d'abord incrémente i, puis évalue i
        printf("Table de %d :\n", i);
        for(int j=1; j<=10; ++j){
            printf("%d * %d = %d\n", j, i, i*j);
            //va à la ligne d'après
        }
    }
    return 0;
}

    /*
    Pour afficher du texte et des variables entières, indiquez chaque variable par un code spécifique ( %d pour les entiers, %f pour les floats, %lf pour les doubles), et
    passez ensuite ces variables comme paramètres supplémentaire à printf.
    
    Syntaxe:
    printf("msgs que je veux écrire", les variables que je veux afficher)
    
    Exemple :
    printf("message1 %d, message2 %d\n", var1, var2);
    => out: message1 var1, message2 var2

    Donc ici:
    printf("%d * %d = %d\n", i, j, i*j);
    => out: i * j = i*j
    */
