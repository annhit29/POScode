//22min
#include <stdio.h>
#include <string.h> //for memset()

//le macro:
#define DIM 10 //la taille de la grille (carrée: 10 x 10).

//les csts:
char const VIDE = '.';
char const REMPLI = '#';
//les csts pour les valeurs booleennes de `canBeFilled`:
int const TRUE = 1;
int const FALSE = 0;


//la struct Grille
typedef struct{
    size_t longueur;
    int ligne;
    int colonne;
    char direction;
    char gr[DIM][DIM];
} Grille;

//le prototype de la fonction remplitGrille() :
int remplitGrille(Grille grille, size_t ligne, size_t colonne, char direction, size_t longueur);
void initializeGrid(Grille grille);
void addElemOnGrid(Grille grille);
void displayFinalGrid(Grille grille);

int main(void){
    Grille grille;
    initializeGrid(grille);
    addElemOnGrid(grille);
    displayFinalGrid(grille);
    return 0;
}


//initialiser la grille avec '.':
void initializeGrid(Grille grille){
    for (size_t i=0; i<DIM; ++i){
        for (size_t j=0; j<DIM; ++j){
            grille.gr[i][j] = VIDE; //bonne pratique: pas de magic nb!
        }
    }
}

// affiche la grille resultante:
void displayFinalGrid(Grille grille){
    for (size_t i=0; i<DIM; ++i){
        for (size_t j=0; j<DIM; ++j){
            printf("grille.gr[i][j]= %c", grille.gr[i][j]);
        }
        putchar('\n');// put the character `'\n'`: to go to another line when going from one row to the other row of the matrix
    }
}

//demande à l'utilisateur de spécifier la position, la direction et la taille des objets à placer:
void addElemOnGrid(Grille grille){
    //declaration & initialization(so set to the default value) variables we will need:
    int x=1, y=1; //the coord (x, y) set at (1, 1)
    char direction;
    size_t fillRange = 1;

    
    do{
        printf("Entrez coord. x: ");
        scanf("%d", &x);
    }while(x<0 || x> DIM);

    do{
        printf("Entrez coord. y: ");
        scanf("%d", &y);
    }while(y<0 || y > DIM);

    //FIXME: pk printf deux fois?
    do{
        printf("Entrez direction (N,S,E,O):");
        scanf("%c", &direction);
    }while(direction!= 'N' && direction!= 'S' && direction!= 'E' && direction!= 'O');

    do{
        printf("Entrez taille:");
        scanf("%zu", &fillRange);
    }while(fillRange<0 || fillRange>DIM);

    printf("Placement en (%d,%d) direction %c longueur %zu -> ",x, y, direction, fillRange); 
    if (remplitGrille(grille, x, y, direction, fillRange)){
        // ≡ if (remplitGrille(grille, x, y, direction, fillRange)){...}
        printf("succès\n");
    }else{
        printf("ECHEC\n");
    }
}


// vérifier si le placement dans une grille d'un objet de dimension longueur est possible, en partant de la coordonnée (ligne,colonne) et dans la direction définie par direction (Nord, Sud, Est ou Ouest).

//Si le placement est possible, la fonction devra de plus effectuer ce placement (voir ci-dessous la description de la grille).
//La fonction devra indiquer (par la valeur de retour) si le placement a pu être réalisé ou non: cette meth retourne donc en fait une valeur booleenne.
int remplitGrille(Grille grille, size_t ligne, size_t colonne, char direction, size_t longueur){
    
    //declae et initialize (set the default value) of canBeFilled = FALSE:
    int canBeFilled = FALSE;

    //TODO: pour représenter la direction, vous pouvez soit utiliser un caractère ('N' pour nord. 'S' pour sud, etc..., plus facile), soit un type enuméré (plus
    //difficile : pensez à l'interface avec l'utilisateur).
    //enum Direction {Nord, Sud, Est, Ouest};

    // Si le placement est possible, la fonction devra de plus effectuer ce placement (voir ci-dessous la description de la grille).
    int dx=0, dy=0; //✨ as we need to move the position, so we need to define variables x, and y (as they aren't provided in the arg list of remplitGrille())
    switch (direction){//TODO: why sol: N = (dx, dy) = (-1, 0)?
        case 'N': dy = dy-1;
            break;
        case 'S': dy = dy+1;
            break;
        case 'E': dx = dx+1;
            break;
        case 'O':dx = dx-1;
            break;
        //default:;
    }

    // indique si le placement a pu être réalisé ou non:
    int isPossible = TRUE; //isPossible = "c'est possible de mettre tous les elems dans le nombre de cases que prendra l'objet dans la direction donnée (Nord, Sud, Est ou Ouest) à partir des coordonnées (ligne, colonne) spécifiées ?"
    size_t l=0, i=0, j=0;
    for (l=0, i=0, j = 0; isPossible && i<DIM && j<DIM; ++l, i+=dx, j+=dy){
        if(grille.gr[i][j]==REMPLI){
            isPossible=FALSE;
        }//o/w isPossible = TRUE; and so just fill in the cases
    }
    
    /* Si l == longueur c'est que j'ai pu placer l'objet sur toute sa longueur.
    * Il se pourrait en effet que je sois sorti de la boucle ci-dessus parce que
    * i >= DIM ou j >= DIM... ...ce qui n'a pas modifié possible jusqu'ici
    */
    isPossible = isPossible && (l == longueur);

    if(isPossible){ // si isPossible est TRUE
        for(l=0, i=ligne,j=colonne; l<longueur; ++l, i+=dx, j+=dy){
            grille.gr[i][j]=REMPLI;
        }
    }


    return canBeFilled;
}



/* functionalities:
1) initializeGrid(): initialiser la grille avec '.'
2) addElemOnGrid(): si peut remplir la matrice, remplis avec '#' qui depend du switch et de la valeur booleanne canBeFilled
3) displayFinalGrid(): affiche la grille resultante
*/
//These main functionalities ⟹ put in the main prgm