#include <stdio.h> //for printf

// TAILLE_NOM est utilisée pour stocker les noms entrés par l'utilisateur, y compris les noms "Jo", "Marc", "Ted", "Andy", "Werner" et "OldBob" du fichier donné en exemple.
#define TAILLE_NOM 1024//longueur maximale pour un nom = 1024 est un choix arbitraire

int main(void){
    
    FILE* fichier = NULL; // pointeur vers le fichier à ouvrir (NULL = pointeur nul)
    // le tableau prenom est utilisé pour stocker le nom entré par l'utilisateur à chaque itération de la boucle, un nom à la fois. Le tableau peut stocker jusqu'à TAILLE_NOM caractères pour chaque nom entré.
    char prenom[TAILLE_NOM +1]; //+1 pour le caractère de fin de chaîne '\0' (null character) qui est ajouté automatiquement par scanf

    fichier = fopen(prenom, "w"); // ouverture du fichier en mode écriture (w = write)
    // Jo      24 
    // Marc    35 
    // Ted     74 
    // Andy    3 
    // Werner  48 
    // OldBob  103   


    return 0;
}