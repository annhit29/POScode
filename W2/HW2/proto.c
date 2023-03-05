//12.47pm~1pm 

#include <stdio.h>

//pour Q3:
//déclaration de la fonction demander_nombre sans corps = prototype:
int demander_nombre(int, int); //prototype is for the 𝐞𝐱𝐩𝐥𝐢𝐜𝐢𝐭𝐞 declaration of the function demander_nombre

//pour Q4:
//déclaration de la fonction demander_bornes sans corps = prototype:
void demander_bornes(int*, int*);


int main(void){
    int borne_minimale=23, borne_maximale=24;

    //si on veut modifier les valeurs de borne_minimale et borne_maximale, on doit passer les adresses de ces variables en paramètres
    //i.e. passage par reference,
    //donc on utilise des pointeurs
    //donc des & devant les noms des variables
    //csq: on doit déclarer les variables comme des pointeurs dans la fonction demander_bornes,
    //D'où dans la def de demander_nombre:
    //on doit utiliser des * devant les noms des variables ayant un `&` devant, dans la fonction demander_bornes:
    //i.e. mets des `*` partout pour les varianles ayant un `&` devant, (*borne_minimale,*borne_maximale)
    demander_bornes(&borne_minimale, &borne_maximale); 
    
    //pour la donction demander_nombre: les borne_minimale et borne_maximale sont passées par valeur(= copier la valeur des variables)
    //donc pas besoin de `&` devant les noms des variables
    //D'où dans la def de demander_nombre: pas besoin d'ajouter des `*` devant les noms des variables ayant un `&`
    printf("%d",demander_nombre(borne_minimale, borne_maximale));

    return 0;
}

//Cette fonction doit demander un entier à l'utilisateur et retourner sa valeur.
//définition de la fonction demander_nombre:
int demander_nombre(int borne_minimale, int borne_maximale){
    int int_nb;

    do{
        printf("Entrez un nombre entier: ");
        scanf("%d", &int_nb);
        printf("DEBUG: int_nb, borne_min, bornre_max= %d, %d, %d\n", int_nb, borne_minimale, borne_maximale); //Rappel: y'a pas de retour à la ligne automatique dans printf
        //Chappe deux conseils:
        //mets tjs des `printf` pour debug
        //1) dans printf, ecris 𝐃𝐄𝐁𝐔𝐆 pour dire que c'est pour debugger
        //2) ensuite mets tjs les noms des variables que je veux afficher pour debugger

    }while(int_nb<borne_minimale|| int_nb>borne_maximale);

    return int_nb;
}

//pour Q4:  
void demander_bornes(int *borne_minimale, int *borne_maximale){

    printf("Entrez la borne minimale: ");
    scanf("%d", borne_minimale); //*& ≡ identity
    printf("Entrez la borne maximale: ");
    scanf("%d", borne_maximale);


    //si la borne minimale est plus grande que la borne maximale, on les échange
    if(*borne_minimale>*borne_maximale){
        int temp = *borne_minimale;
        *borne_minimale = *borne_maximale;
        *borne_maximale = temp;
    };


    printf("Entrez un nombre entier entre %d et %d: ", *borne_minimale, *borne_maximale);

}