#include <stdio.h> //for printf

#define TAILLE_NOM 1024 //cf ecriture.c for the definition of TAILLE_NOM

//p.22 lect4 for reading the caracters of a file


int main(void){
    //nom du fichier à ouvrir (est "data.dat"):
    char const nom_fichier[] = "data.dat";

    //initialisation:
    FILE* entree = NULL; // pointeur vers le fichier à ouvrir (NULL = pointeur nul)
    int age_lu = 0; //age lu dans le fichier : c'est un compteur qui compte le nb de personnes read from the file so far
    int age_somme = 0; //somme des ages des personnes lues dans le fichier
    double age_moyen = 0.0; //age moyen des personnes lues dans le fichier
    int age_max = -1; //just like in algo, put an impossible value which is not possible to be reached, such as -1 
    int age_min = __INT_MAX__; //just like in algo, put an impossible value which is initially to be reached, such as ∞



    //𝐨𝐮𝐯𝐞𝐫𝐭𝐮𝐫𝐞 du fichier en mode lecture seule (r = read):
    entree = fopen(nom_fichier, "r");

    // si le fichier n'existe pas, fopen() retourne NULL car pointe vers NULL
    if(entree==NULL){
        fprintf(stderr, "Erreur : impossible de lire le fichier %s\n", nom_fichier);
        return 1; //MUST: the main prgm returns sth different from 0 means sth went wrong 
    }else{
        // "" car on va lire le fichier commencant par le premier caractère, et ""=empty string
        char prenom[TAILLE_NOM+1]="";
        int age = 0; //age de chaque personne qu'on va lire dans le fichier


        //tant qu'on peut lire un nom de 15 caractères maximum
        //et tant qu'on peut lire un age de 3 caractères maximum :
        while(fscanf(entree, "%15s", prenom) == 1 && fscanf(entree, "%3d", &age)){ //todo:Idk if it's correct to write 2 fscanf() in the same while() condition
            
            printf("%s      %d\n", prenom, age);
            age_lu+=1;
            age_somme+=age;

            if (age>age_max){
                age_max=age;
            }else if(age<age_min){
                age_min=age;
            }
        }

        age_moyen = (double)age_somme/age_lu; //cast to double

        //𝐟𝐞𝐫𝐦𝐞𝐭𝐮𝐫𝐞 du fichier:
        fclose(entree);



        printf("âge minimum : %d\n", age_min);
        printf("âge maximum : %d\n", age_max);
        printf("%d personnes, age moyen: %.1lf ans\n", age_lu, age_moyen);
    }
    return 0;
}