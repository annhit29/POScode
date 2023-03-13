/*
Ce prgm calcule les statistiques sur les lettres contenues dans un fichier.
*/


#include <stdio.h> //for printf()
//#include <stdbool.h> //for bool values

#define TAILLE_MAX 1024 //cf ecriture.c for the definition of TAILLE_NOM
#define NB_DEMANDS 3 //nb maximum de demandes en cas d'erreur
#define FILE_MAX_CHAR_NB 10000

//les prototypes:
FILE* demander_fichier();

int main(void){
    //𝐨𝐮𝐯𝐞𝐫𝐭𝐮𝐫𝐞 du fichier:
    FILE* input_file = NULL;
    char const mot[TAILLE_MAX+1];
    input_file = demander_fichier();

}

// retourne FILE* correspondant au fichier ouvert (ou NULL sinon) 
FILE* demander_fichier(){
    //initialisation:
    int count_demand = 1;
    char filename[FILE_MAX_CHAR_NB]=""; //initialize the file to empty_file at first. This file can contain at most MAX_INT characters.
    // ⚠ `FILE*` ≠ `%s`. These two types are different!
    // si on ecrit `char filename[__INT_MAX__]="";`, on aura l'erreur https://stackoverflow.com/questions/7902228/segmentation-fault-large-arrays

    int is_abondonned= 0; //flemme d'import stdbool.h . Cette variable sert à savoir qd je sors de la boucle while sans avoir besoin d'utiliser un `break;` dans la case2 
    do{
        printf("Nom du fichier à lire : ");
        scanf("%s", filename);

        
        FILE* entree = fopen(filename, "r"); //https://stackoverflow.com/questions/5517490/file-not-found-exception-in-c-sharp-and-c
        //case1
        if(entree==NULL && count_demand<NB_DEMANDS){ // si le fichier n'existe pas, fopen() retourne NULL car pointe vers NULL
            ++count_demand;
            fprintf(stderr, "-> ERREUR, je ne peux pas lire le fichier %s\n", filename); //It is good practice to redirect all error messages to stderr, while directing regular output to stdout. It is beneficial to do this because anything written to stderr is not buffered, i.e., it is immediately written to the screen so that the user can be warned immediately.
        }//case2
        else if (entree==NULL && count_demand>=NB_DEMANDS){ //the condition between count_demand & ND_DEMANDS is to control the 𝐞𝐫𝐫𝐨𝐫 msg printed out
            is_abondonned=1;
            fprintf(stderr, "=> j'abandonne !\n");
            //break;
        }//case3
        else{
            printf("-> OK, fichier %s ouvert pour lecture.\n", filename);
            return entree;//ok, coz entree is of type FILE*
        }

    }while(is_abondonned==0); //Nein `count_demand<=NB_DEMANDS ||`

    return NULL;//if not in case3, then we must return sth of type FILE*, so pointeur NULL ∈ FILE*
}