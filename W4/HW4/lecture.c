#include <stdio.h> //for printf

#define TAILLE_NOM 1024 //cf ecriture.c

//p.22 lect4?
int main(void){
    //nom du fichier à ouvrir (est "data.dat"):
    char const nom_fichier[] = "data.dat";
    FILE* entree = NULL; // pointeur vers le fichier à ouvrir (NULL = pointeur nul)

    //𝐨𝐮𝐯𝐞𝐫𝐭𝐮𝐫𝐞 du fichier en mode lecture seule (r = read):
    entree = fopen(nom_fichier, "r");
    // si le fichier n'existe pas, fopen() retourne NULL car pointe vers NULL
    if(entree==NULL){
        fprintf(stderr, "Erreur : impossible de lire le fichier %s\n", nom_fichier);
        return 1; //MUST: the main prgm returns sth different from 0 means sth went wrong 
    }else{
        // "" car on va lire le fichier commencant par le premier caractère, et ""=empty string
        char prenom[TAILLE_NOM+1]="";
        while(fscanf(entree, "%10s", prenom) == 1){ //tant qu'on peut lire un nom de 10 caractères maximum
            printf("%s", prenom);
        }

        //𝐟𝐞𝐫𝐦𝐞𝐭𝐮𝐫𝐞 du fichier:
        fclose(entree);
    }
    return 0;
}