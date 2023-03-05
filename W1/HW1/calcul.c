//11.19am~11.38am
#include <stdio.h>

int main(void){
    // 1. déclare les variables x et y de type entier(ensuite réel; ensuite x entier et y réel) ;
    //int x, y;

    //double x, y;
    
    int x;
    double y;

    // 2. déclare les variables a, b, c et d de type réel ;
    double a, b, c, d;
    // 3. affecte la valeur 2 à x et 4 à y ;
    x=2;
    y=4;
    // 4. calcule la somme, la différence, le produit, et le quotient de x par y, et affecte les résultats à a, b, c et d ;
    a=x+y;
    b=x-y;
    c=x*y;
    d=x/y;
    // 5. affiche les valeurs de a, b, c et d.
    printf("a= %lf, b= %lf, c= %lf, d= %lf\n", a, b, c, d);
    /*
    Pour afficher du texte et des variables entières, indiquez chaque variable par un code spécifique ( %d pour les entiers, %f pour les réels), et
    passez ensuite ces variables comme paramètres supplémentaire à printf.
    Exemple :
    printf("message1 %d, message2 %d\n", var1, var2);

    Donc ici:
    printf("a= %lf, b= %lf, c= %lf, d= %lf\n", a, b, c, d);
    */

    return 0;
}

//avec int x, y;
//a= 6.000000, b= -2.000000, c= 8.000000, d= 0.000000

//avec double x, y;
//a= 6.000000, b= -2.000000, c= 8.000000, d= 0.500000

//Que constatez-vous ?
//avec int x, y; x/y est une division entière, donc le résultat est 0
//avec double x, y; x/y est une division réelle, donc le résultat est 0.5
//cf Obsidian intro en C §Operateurs division:

//avec int x; double y;
//a= 6.000000, b= -2.000000, c= 8.000000, d= 0.500000
//Que constatez-vous ?
//x est un entier, y est un réel, donc x/y est une division réelle, donc le résultat est 0.5

/*
Dès qu'une opérande est de type double, c'est une division réelle qui est effectuée.
C'est-à-dire que le résultat est la valeur (approchée à la précision des double) du nombre réel correspondant.
*/