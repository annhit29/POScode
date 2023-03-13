/*
Ce prgm calcule les statistiques sur les lettres contenues dans un fichier.
*/


#include <stdio.h> //for printf()

#define TAILLE_MAX 1024 //cf ecriture.c for the definition of TAILLE_NOM
#define NB_DEMANDS 3 //nb maximum de demandes en cas d'erreur

//les prototypes:
FILE* demander_fichier();

int main(void){
    //𝐨𝐮𝐯𝐞𝐫𝐭𝐮𝐫𝐞 du fichier:
    FILE* input_file = NULL;
    char const mot[TAILLE_MAX+1];
    demander_fichier();

}

// retourne FILE* correspondant au fichier ouvert (ou NULL sinon) 
FILE* demander_fichier(){
    //initialisation:
    int count_demand = 0;
    char filename[__INT_MAX__]=""; //initialize the file to empty_file at first. This file can contain at most MAX_INT characters.
    // ⚠ `FILE*` ≠ `%s`. These two types are different!


    do{
        printf("Nom du fichier à lire : ");
        scanf("%s", filename);

        
        FILE* entree = fopen(filename, "r"); //https://stackoverflow.com/questions/5517490/file-not-found-exception-in-c-sharp-and-c
        //case1
        if(entree==NULL && count_demand<NB_DEMANDS){ // si le fichier n'existe pas, fopen() retourne NULL car pointe vers NULL
            ++count_demand;
            fprintf(stderr, "-> ERREUR, je ne peux pas lire le fichier %s\n", filename); //It is good practice to redirect all error messages to stderr, while directing regular output to stdout. It is beneficial to do this because anything written to stderr is not buffered, i.e., it is immediately written to the screen so that the user can be warned immediately.
        }//case2
        else if (entree==NULL && count_demand>=NB_DEMANDS){
            printf("=> j'abandonne !\n");
        }//case3
        else{
            printf("-> OK, fichier %s ouvert pour lecture.\n", filename);
            return entree;//ok, coz entree is of type FILE*
        }

    }while(count_demand<NB_DEMANDS);

    return NULL;//if not in case3, then we must return sth of type FILE*, so pointeur NULL ∈ FILE*
}