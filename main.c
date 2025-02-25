#include <stdio.h>
#include <string.h>

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

    // on compte chaque itération pour chaque caractère
    int compteurCarac = 1;
    int indexCarac = 0;
    int iterationMax;
    char letterMax;
    int nbrCorrespondantToLettre;
    int nbrRefE = 101;

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


    int intervalRef = nbrRefE - nbrCorrespondantToLettre;

    for (int i = 0; i < lengthStringUser; i++) {
        stringUser[i] = stringUser[i] + intervalRef;
    }  

    printf("texte decode : %s\n", stringUser);

    return 0;
}
