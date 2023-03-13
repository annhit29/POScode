/*
Ce prgm calcule les statistiques sur les lettres contenues dans un fichier.
*/


#include <stdio.h> //for printf()

#define TAILLE_MAX 1024 //cf ecriture.c for the definition of TAILLE_NOM
#define NB_DEMANDS 3 //nb maximum de demandes en cas d'erreur

//les prototypes:
FILE* demander_fichier(FILE* entree, char mot[]);

int main(void){
    //𝐨𝐮𝐯𝐞𝐫𝐭𝐮𝐫𝐞 du fichier:
    FILE* input_file = NULL;
    char const mot[TAILLE_MAX+1];
    demander_fichier(input_file, mot);

}

// retourne FILE* correspondant au fichier ouvert (ou NULL sinon) 
FILE* demander_fichier(FILE* file_name, char mot[]){ //todo: mais du coup pas besoin de mot[TAILLE_FIXE]?
    int count_demand = 0;

    do{
        printf("Nom du fichier à lire : ");
        scanf("%s\n", file_name);
        
        FILE* entree = fopen(file_name, "r"); //https://stackoverflow.com/questions/5517490/file-not-found-exception-in-c-sharp-and-c
        if(entree==NULL && count_demand<3){ // si le fichier n'existe pas, fopen() retourne NULL car pointe vers NULL
            ++count_demand;
            fprintf(stderr, "-> ERREUR, je ne peux pas lire le fichier %s\n", file_name); //It is good practice to redirect all error messages to stderr, while directing regular output to stdout. It is beneficial to do this because anything written to stderr is not buffered, i.e., it is immediately written to the screen so that the user can be warned immediately.
        }else if (entree==NULL && count_demand>=3){
            printf("=> j'abandonne !\n");
        }else{
            printf("-> OK, fichier %s ouvert pour lecture.\n", file_name);
            return entree;//todo: ok?
        }

    }while(count_demand<NB_DEMANDS);
//todo: printf is type FILE?

    



}