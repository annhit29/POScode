//am 10.27~10.38
#include <stdio.h>

//Soit I l'intervalle [-1,1[ dans l'ensemble des réels.

int main(void){
    //idéclaration et nitialisation des variables:
    double x = 0.0;

    //1. demande à l'utilisateur d'entrer un réel ;
    printf("Entrez un réel:\n");
    //2. lit et enregistre la réponse de l'utilisateur dans une variable x de type réel ;
    scanf("%lf", &x);
    //Attention : dans le scanf("%lf", &x);, devant le f c'est un L minuscule et pas in 1 (un) !
    //"lf" pour "long float" (=double)

    //3. teste l'appartenance de x à l'ensemble I et affiche le message:
    if(x>=-1 && x<1){
        printf("x appartient à I\n");
    }else{
        printf("x n'appartient pas à I\n");
    }

    return 0; //pour dire que tout s'est bien passé
}