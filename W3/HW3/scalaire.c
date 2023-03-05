//38min
#include <stdio.h>

// la fonction qui calcule le produit scalaire. Le prototype:
double scalaire(const double u[], const double v[], size_t taille);



int main(void){
    //(lect2) les variables déclarées à l’intérieur d’un bloc sont appelées variables locales (au bloc).
    // Elles ne sont accessibles qu’à l’intérieur du bloc.
    //les csts:
    //~~int N_MAX = 10;~~
    size_t const N_MAX = 10;
    
    double v1[N_MAX];
    double v2[N_MAX];
    
    int n;
    do{
        printf("Entrez n:");
        scanf("%d", &n);
    }while(1>n || n> N_MAX); // not(1 ≤ n ≤ N_MAX)

    for(int i=0; i<n; ++i){
        printf("Entrez une valeur pour v1[%d]:", i);
        scanf("%lf", &v1[i]);
    }
        for(int i=0; i<n; ++i){
        printf("Entrez une valeur pour v2[%d]:", i);
        scanf("%lf", &v2[i]);
    }

    double scalar = scalaire(v1, v2, n);
    printf("Le résultat du produit scalaire entre v1 et v2 = %lf \n", scalar);
}


// la fonction qui calcule le produit scalaire de u et v:
double scalaire(const double u[], const double v[], size_t taille){
    double scalar = 0.0;
    for (int i=0; i< taille; ++i){
        scalar += u[i]*v[i];
    }
    return scalar;
}