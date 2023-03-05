// 10.38am~11.19am && 11.38m~12.14pm
#include <stdio.h>

// Même problème que l'exo3 avec : I = [2,3[ U ]0,1] U [-10,-2]
// Dans cet exercice, nous autorisons uniquement l'utilisation des opérateurs relationnels < et ==.
// Tous les opérateurs logiques ( &&, ||, etc) sont, par contre, autorisés.

/*
L'idée ici pour exprimer les intérvales avec seulement < ou == est
* écrire <=x comme <x || ==x
* écrire x> comme !(x< || x==) ≡ <x (les deux marchent en C)
* écrire x>= comme !(x< )
* écrire x<= comme (x< || x==) c'est juste les maths
*/

int main(void)
{
    // idéclaration et nitialisation des variables:
    double x = 0.0;

    // 1. demande à l'utilisateur d'entrer un réel ;
    printf("Entrez un réel:\n");
    // 2. lit et enregistre la réponse de l'utilisateur dans une variable x de type réel ;
    scanf("%lf", &x);
    // Attention : dans le scanf("%lf", &x);, devant le f c'est un L minuscule et pas in 1 (un) !
    //"lf" pour "long float" (=double)

    // 3. teste l'appartenance de x à l'ensemble I et affiche le message:
    // (0 < x) peut être écrit comme !(x<0 || x==0) aussi.
    if ((!(x < -10) && (x < -2 || x == -2.0)) || ((0 < x) && (x < 1 || x == 1.0)) || (!(x < 2) && x < 3))
    {
        printf("x appartient à I\n");
    }
    else
    {
        printf("x n'appartient pas à I\n");
    }

    return 0; // pour dire que tout s'est bien passé
}

/*
Remarque :
Il n'est jamais bon de comparer exactement des valeurs de double, 
c.-à-d. ne jamais utiliser == sur des doubles 
car, mis à part quelques cas particuliers (commme par exemple ici la lecture directe de la valeur), 
il est rare que la valeur d'un double soit connue avec assez de précision (accumulation d'erreurs d'arrondi). 
Il est conseillé de plutôt alors utiliser un test sur la valeur absolue de l'écart absolu ou relatif, 
comme par exemple : abs(x-y)<1e-12 ou abs(x-y)/x<1e-12 (pas au voisinage de 0 bien sûr !). 
Dans ce cas, le mieux est de faire une fonction... ...ce que nous verrons la semaine prochaine.
*/