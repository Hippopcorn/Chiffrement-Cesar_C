#include <stdio.h>
#include <string.h>

#define nbrRefE 101

int main() {
    // on récupère l'entrée de l'utilisateur
    char stringUser[45];
    printf("Entrer votre texte : \n");
    scanf("%s", stringUser);

    // on récupère la taille de la string
    int lengthStringUser = 0;
    while (stringUser[lengthStringUser] != 0) {
        lengthStringUser++;
    }

    // on compte chaque itération pour chaque caractère  et on conserve en letterMax celle que l'on retrouve le plus
    int compteurCarac = 1;
    int indexCarac = 0;
    int iterationMax;
    char letterMax;
    int nbrCorrespondantToLettre;

    for (int indexCarac = 0; indexCarac < lengthStringUser - 1; indexCarac++) {

        for (int i = indexCarac + 1; i < lengthStringUser; i++) {

            if (stringUser[indexCarac] == stringUser[i]) {
                compteurCarac++;
            }

            if (compteurCarac > iterationMax) {
                iterationMax = compteurCarac;
                letterMax = stringUser[indexCarac];
                nbrCorrespondantToLettre = letterMax;
            }
        }
        compteurCarac = 1;
    }

    printf("iteration max : %d\n", iterationMax);
    printf("lettre correspondante : %c\n", letterMax);
    printf("int correspondant : %d\n", nbrCorrespondantToLettre);

    // on calcule l'intervalle du chiffrement et on l'applique à toute la string
    int intervalRef = nbrRefE - nbrCorrespondantToLettre;

    for (int i = 0; i < lengthStringUser; i++) {
        stringUser[i] = stringUser[i] + intervalRef;
    }  

    printf("texte decode : %s\n", stringUser);

    return 0;
}
