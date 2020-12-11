#include <stdio.h>
#include <stdlib.h>
#include "Partie 1.h"
#include "Partie 2.h"
#include "Partie 3.h"

int main(int argc, char *argv[])
{

    Element* l;
    Tree a = NULL;
    int choice;

    do
    {

        printf("\n\nBienvenue sur le Projet Huffman !\n");

        printf("\nLes commandes sont a appeler dans l ordre croissant pour le bon fonctionnement de la compression.\n");
        printf("---|Huffman P1|--\n");
        printf("1) | Lire un texte dans un fichier, et le traduire en son equivalent 0 et 1 dans un autre fichier (QA).\n");
        printf("2) | Afficher le nombre de caracteres dans un fichier txt(QB).\n");
        printf("---|Huffman P2|--\n");
        printf("3) | Renvoyer une liste contenant chaque caractere present dans le texte, ainsi que le nombre d occurrences de ce caractere(QC). \n");
        printf("4) | Renvoyer un arbre de Huffman, a partir d une liste d occurrences(QD).\n");
        printf("5) | Stocker dans un fichier txt le dictionnaire issu de l arbre de Huffman(QE). \n");
        printf("6) | Compresser un fichier texte. Le fichier d entree ne sera pas modifie, un autre fichier, contenant le texte compresse sera cree(QF/G). \n");
        printf("\n0) | Quitter\n");

        printf("Entrez un nombre pour faire votre choix : ");
        choice = Saisie_securisee_menu();

        switch(choice)
        {


        case 1:
            translate();
            system("cls");
            break;


        case 2:
            count_number();
            break;


        case 3:
           l = create_list_letter();
           print_list(l);
            break;


        case 4:
           a = tree_huffman(l);
           print_tree(a);
            break;


        case 5:
            l = create_list_letter();
            dico_huffman(a, l);
            break;


        case 6:
            encoding();
            break;

        default:
            printf("Au revoir !");
            break;


    }
    }
    while(choice!=0);
    return 0;



    free(a);
    free(l);

    return 0;

}

