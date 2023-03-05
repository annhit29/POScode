//22.33~
//Le prgm mulmat calcule la multiplication de deux matrices.

#include <stdio.h>
#include <stdint.h>

//définissez (#define) une constante N comme la taille maximale pour la dimension d'une matrice
#define N 10// ≡ size_t const N=10; (lect3 p.16) 

// Définissez le type Matrice en utilisant une structure contenant un tableau et deux entiers non signés représentant le nombre de colonnes et le
// nombre de lignes.
//lect3 p.33
struct Matrice
{
    double tab[N];
    uint32_t n; //nb de lignes
    uint32_t m; //nb de colonnes
};

//les fonctions prototypes:
Matrice lire_matrice(void);

int main(void){
    //déclarez deux matrices M1 et M2:
    double M1[N], M2[N];   
}



// lit depuis le clavier les éléments d'une matrice (après avoir demandé ses tailles de lignes et colonnes et vérifié que celles-ci sont plus petites
//que N) et retourne la matrice résultante.
Matrice lire_matrice(void){
    
}