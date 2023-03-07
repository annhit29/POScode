//2h03min
//Le prgm mulmat calcule la multiplication de deux matrices.

#include <stdio.h>
#include <string.h> // for memset()

//définissez (#define) une constante N comme la taille maximale pour la dimension d'une matrice
#define N 10// ≡ size_t const N=10; (lect3 p.16) 

// Définissez le type Matrice en utilisant une structure contenant un tableau et deux entiers non signés représentant le nombre de colonnes et le
// nombre de lignes.
//lect3 p.33
typedef struct{
    size_t n; //nb de lignes
    size_t m; //nb de colonnes
    double tab[N][N];
} Matrice;
//vois `struct` comme la def de l'objet `Matrice`.
//Et `n`, `m` et `tab[N][N]` comme les fields de l'objet.

//les fonctions prototypes:

Matrice lire_matrice(void);
Matrice multiplication(const Matrice a, const Matrice b);
void affiche_matrice(const Matrice m);


int main(void){
    //déclarez deux matrices M1 et M2:
    //1. lire depuis le clavier les dimensions l1 (nombre de lignes) et c1 (nombre de colonnes) de la première matrice M1
    // puis lire le contenu de M1.
    //De même, lire les dimensions puis le contenu de la seconde matrice M2
    Matrice M1 = lire_matrice();
    Matrice M2 = lire_matrice();

    //déclare la matrice M:
    Matrice M;
    if(M1.m != M2.n){
        printf("Multiplication de matrices impossible !\n");
    }else{
        M = multiplication(M1, M2);
        // afficher le résultat ligne par ligne:
        affiche_matrice(M);
    }

    //⭐⭐⭐⭐⭐ return 0; !!!!!
    return 0;
}


//defs des fonctions prototypes:

// lit depuis le clavier les éléments d'une matrice (après avoir demandé ses tailles de lignes et colonnes et vérifié que celles-ci sont plus petites
//que N) et retourne la matrice résultante.
Matrice lire_matrice(void){ // ≡ initialize_matrix 

    // initialisation de la matrice resultante.
    // Pour `n` et `m`: c'est pas on doit, mais il faut: car on utilise `struct`: les `n` et `m` sont definis dans le `struct` mais pas dans d'autres blocs:
    size_t n = 0;
    size_t m = 0;
    //declare la matrice resultante:
    Matrice resMat;

    printf("Saisie d'une matrice :\n");

    do{
        printf("Entrez le nb de lignes n de la matrice:");
        scanf("%zu", &n); // pour lire un entier, utiliser "%d" (et pour lire un size_t, "%zu").
    }while(1>n || n >N);


    do{
        printf("Entrez le nb de colonnes m de la matrice:");
        scanf("%zu", &m); 
    }while(1>m || m > N);


    resMat.n = n;
    resMat.m = m;
    for (size_t i=0; i<n; ++i){
        for (size_t j=0; j<m; ++j){
            printf("M[%zu][%zu] = ", i, j);
            scanf("%lf", &resMat.tab[i][j]);
        }
    }
    return resMat;
    
}


//multiplie deux matrices de tailles compatibles et affecte le résultat:
Matrice multiplication(const Matrice a, const Matrice b){
    
    //declare la struct multMat:
    Matrice multMat;
    
    
    memset(&multMat, 0, sizeof(multMat)); //bonne practice: initialise tjs la struct (ici la struct est multMat) à 0
    //printf("DEBUG (pour voir si toutes les composantes de multMat sont bien initialisées à 0.0): multMat.n = %zu, multMat.m = %zu, multMat.tab[N][N] = %lf: ", multMat.n, multMat.m, multMat.tab);

    //vérifie que l'on peut faire la multiplication des matrices:
    if(a.m== b.n){
        multMat.n=a.n;
        multMat.m=b.m;   
    }//Ici, on ne modifie tjs pas la taille de la struct multMat, 
    // mais seulement dire que "je vais utiliser telles lignes et telles colonnes de la struct multMat."
    //Et du coup les composantes non utilisées de multMat seront remplies par des `0` en raison de l'initialisation avec `memset` 
    //On verra plus tard cmt modifier la taille des tableaux avec les pointeurs.


    //fais la multiplication des matrices:
    for (size_t i=0; i<a.n; ++i){
        for (size_t j=0; j<b.m; ++j){
            for(size_t k=0; k<a.m; ++k){
                multMat.tab[i][j] += a.tab[i][k]*b.tab[k][j];
            }
        }
    } 
    return multMat;
}


// affiche le contenu d'une matrice ligne par ligne
void affiche_matrice(const Matrice m){
    for (size_t i=0; i<m.n; ++i){
        for (size_t j=0; j<m.m; ++j){
            printf("M[%zu][%zu] = %lf  ", i, j, m.tab[i][j]);
        }
        putchar('\n');// put the character `'\n'`: to go to another line when going from one row to the other row of the matrix
    }
}