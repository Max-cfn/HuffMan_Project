#include <stdio.h>
#include <stdlib.h>
#include "Partie 3.h"

Node* create_tab_occurrence()
{
    Element* l = create_list_letter();

    Node* tab = malloc(size_list(l)*sizeof(Element));
    //Node* tab = NULL;

    FILE* fichier;
    fichier=fopen("entree.txt","r+");


    if (fichier != NULL)
    {

        int lettre;
        while( (lettre=fgetc(fichier)) != EOF )
        {
            int i = 0;
            while( (i < size_list(l)) && tab[i].letter != lettre){
                i++;
            }

            if (tab[i].letter == lettre)
            {
                printf("t");
                tab[i].occur += 1;
            }



            else
            {
                Node new_node;
                new_node = *create_node(1, lettre);
                //tab = realloc(tab, i*sizeof(Element));
                tab[i] = new_node;
            }


        }

    }


    return tab;

}

extern void print_tab(Node* tab)
{

    /*int n = size_tab(tab);
    printf("%d", n);*/

    Element* l = create_list_letter();

    if (tab == NULL)
    {
        return;
    }



     else{

        for (int i = 0; i< size_list(l); i++){

            printf("Le noeud comporte la lettre %c de %d occurence(s)\n", tab[i].letter, tab[i].occur);

        }

     }

}

