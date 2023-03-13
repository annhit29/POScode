/*
On recoit un fichier, on veut l'affichier, genre dumper quoooi.
*/

#include <stdio.h>


//TODO: a meth that reads the code in hexa

// ======================================================================

// Q: pourquoi on peut pas passer par `FILE* filename` ?
//A: car FILE* est deja un flot, mais on veut juste passer le fichier, qui est le point de depart! pas encore un flot!
// Notre but est de: on recoit une chaine de caractere et on retourne 

int dump(const char* filename) //const car on veut garantir de ne pas modifier le file 
{
  int err=0;

  if(filename == NULL){
    fprintf(stderr, "....\n");
    return 1;
  }

// Avant d'ouvrir le fichier, on vérifie si filename == NULL
//Si elle est fausse, alors on ouvre le fichier puis on vérifie si file == NULL.
//Si la première condition est vraie, pourquoi la seconde serait fausse?
//A:
//car deja, pour la condition1: filename==NULL ≡ on a rien recu comme chaine de carac
//et condition2: stream == NULL ≡ on a recu au moins une chaine de carac mais est-ce qu'on a reussi à l'ouvrir
// Ces deux conditions testent totalement deux choses differentes!


  FILE* stream = fopen(filename, "rb"); // soit on initialise stream à NULL, soit on l'assigne directement une valeur comme ce qu'on fait mtn.
  //Reflex: Si j'ouvre un fichier, alors je verifie par reflex si le flot n'existe pas (aka pointeur `NULL`):
  if (stream==NULL){ //si le flot n'existe pas, alors affiche l'erreur & retourne qqch ≠ 0 pour dire que le prgm a echoue.
    fprintf(stderr, "......\n");
    return 2;
  }

  //verifie si le prgm n'a pas encore termine et si le fichier n'a pas d'erreur:
  //while() //TODO: complete the code

  return err; //si tout s'est bien passé.
}

// ======================================================================
int main(int argc, char *argv[])
{
  if (argc <= 1) {
    fprintf(stderr, "Please provide a filename\n"); //Error1
    fprintf(stderr, "usage: dump filename\n"); //Error2
    return 1;
  }

  return dump(argv[1]);
}
