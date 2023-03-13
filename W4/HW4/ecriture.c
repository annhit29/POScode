#include <stdio.h> //for printf

// TAILLE_NOM est utilisée pour stocker les noms entrés par l'utilisateur, y compris les noms "Jo", "Marc", "Ted", "Andy", "Werner" et "OldBob" du fichier donné en exemple.
#define TAILLE_NOM 1024//longueur maximale pour un nom = 1024 est un choix arbitraire

int main(void){
    
    //initialisation:
    FILE* output_bytes = NULL; // pointeur vers le fichier à ouvrir (NULL = pointeur nul)
    // le tableau prenom est utilisé pour stocker le nom entré par l'utilisateur à chaque itération de la boucle, un nom à la fois. Le tableau peut stocker jusqu'à TAILLE_NOM caractères pour chaque nom entré.
    char prenom[TAILLE_NOM +1]; //+1 pour le caractère de fin de chaîne '\0' (null character) qui est ajouté automatiquement par scanf
    int age=0;


    // 𝐨𝐮𝐯𝐞𝐫𝐭𝐮𝐫𝐞 du fichier en mode écriture (w = write)
    output_bytes = fopen("data.dat", "w");
    //must write:
    // Jo      24 
    // Marc    35 
    // Ted     74 
    // Andy    3 
    // Werner  48 
    // OldBob  103   

    //ecriture dans le fichier avec iteration while (preferable):

        do{
            printf("Entrez un nom (CTRL+D pour terminer) :");
            //scanf("%s", prenom); // lecture du nom entré par l'utilisateur
            if(scanf("%s", prenom)!=EOF){ // EOF = End of File
                            //no need `&` for prenom, coz it's an array

                printf("Entrez un age (CTRL+D pour terminer) :");
                //scanf("%d",&age); //read the age
                if(scanf("%d",&age) != EOF){
                    //ecris prenom et age dans le fichier
                    fprintf(output_bytes,"%s %d\n",prenom, age);
                }
            }
        }while(!feof(stdin) && !ferror(stdin));// boucle jusqu'à ce que l'utilisateur tape CTRL+D (fin de fichier) pour terminer l'entrée des noms (CTRL+D est équivalent à EOF = End Of File)




    //fwrite(prenom, sizeof(char), TAILLE_NOM, fichier); this line is useless coz we already wrote it (by scanf) the prenom and the age.

    //𝐟𝐞𝐫𝐦𝐞𝐭𝐮𝐫𝐞 du fichier
    fclose(output_bytes);//always, and must!

    return 0;
}