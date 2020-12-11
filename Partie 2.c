#include <stdio.h>
#include <stdlib.h>
#include "Partie 2.h"

Element* create_elem_List(int lettre)
{
    if(lettre == EOF)
    {
        exit(1);
    }
    else
    {
        Element* liste= malloc(sizeof(Element));
        liste->lettre=lettre;
        liste->occurrence=1;
        liste->next= NULL;
        return liste;
    }
}

Element* create_list_letter()
{
    FILE* fichier = NULL;
    Element* l = NULL;
    Element* temp = NULL;
    int stock;
    fichier = fopen("entree.txt", "r");

    if(fichier != NULL)
    {
        l = create_elem_List(fgetc(fichier));
        while((stock = fgetc(fichier)) != EOF)
        {
            if(stock != '\n')
            {
                temp = l;
                while( ((temp->next) != NULL) && (stock != (temp->lettre)) )
                    temp = temp->next;
                if(stock == temp->lettre)
                    (temp->occurrence)++;
                else
                    temp->next = create_elem_List(stock);
            }
        }
    }
    return l;
}

int maximum_occurrence(Element* l)
{

    Element* temp;
    temp=(l);
    int max;
    if((l)==NULL)
    {
        exit(1);
    }
    max=temp->occurrence;

    while(temp->next!=NULL)
    {
        temp=temp->next;
        if((temp->occurrence) > max)
        {
            max=temp->occurrence;
        }
    }

    return max;
}

int maximum_letter(Element* l)
{

    Element* temp;
    temp=(l);
    int max;
    if((l)==NULL)
    {
        exit(1);
    }
    max=temp->occurrence;

    while(temp->next!=NULL)
    {
        temp=temp->next;

        if((temp->occurrence) > max)
        {
            max=temp->occurrence;
        }
    }

    temp=(l);

    while(temp!=NULL)
    {

        if (temp->occurrence == max)
        {

            max = temp->lettre;


        }
        temp = temp->next;

    }

    return max;

}

Element* supp_element(Element** l, int occurrence, char letter)
{


    Element* ancien;
    Element* temporel;
    Element* temp = (*l);

    if ( (temp->occurrence == occurrence) && (temp->lettre == letter))
    {
        (*l)=(*l)->next;
        temp->next = NULL;
        free(temp);
    }

    while(temp->next!=NULL)
    {
        if( (temp->next->occurrence == occurrence) && (temp->next->lettre == letter))
        {
            ancien=temp->next->next;
            temporel=temp->next;
            temp->next=ancien;
            temporel->next=NULL;

        }
        temp=temp->next;
    }
    return *l;




}

int size_list(Element *l)
{

    if (l == NULL)
    {

        return NULL;
    }
    else
    {
        return 1 + size_list(l->next);
    }

}

int recup_occurrence(Element *l)
{
    if(l==NULL)
    {
        exit(1);
    }
    return l->occurrence;
}

Element* create_element(int nouv_info)
{
    Element* nouv_elem;
    nouv_elem = (Element*)malloc(sizeof(Element));
    nouv_elem->occurrence = nouv_info;
    nouv_elem->next = NULL;
    return nouv_elem;
}

Node* create_node(int occur, char letter)
{

    Node* n = (Node*)malloc(sizeof(Node));
    n->sad = NULL;
    n->sag = NULL;
    n->occur = occur;
    n->letter = letter;
    return n;

}

Node* tree_huffman(Element* l)
{

    if (size_list(l) == 0)
    {
        return NULL;
    }

    if (l->next == NULL)
    {
        return create_node(l->occurrence, l->lettre);

    }

    int occurrence_max = maximum_occurrence(l);

    char lettre_max = maximum_letter(l);

    Node* node = create_node(nbr_occurrence(l), 0);

    node->sag = create_node(occurrence_max, lettre_max);

    l = supp_element(&l, occurrence_max, lettre_max);

    node->sad = tree_huffman(l);


    return node;

}

int nbr_occurrence(Element* l)
{

    if (l == NULL)
    {

        return 0;
    }
    else
    {

        return (l->occurrence) + nbr_occurrence(l->next);
    }



}

void print_list(Element* l)
{

    if (l == NULL)
    {

        return;
    }
    else
    {

        printf("(%d,%c)", l->occurrence, l->lettre);
        print_list(l->next);
    }

}

void print_tree(Tree a)
{

    if ( a == NULL)
    {
        return;
    }

    else
    {


        print_tree(a->sad);
        printf("(%d,%c)\n", a->occur, a->letter);
        print_tree(a->sag);

    }


}

extern void add_1_or_0(char* c, int nbr)
{

    int cmp = 0;

    while( c[cmp] != '\0')
    {
        cmp++;
    }


    if (nbr == 0)
    {
        c[cmp] = '0';
    }
    else
    {
        c[cmp] = '1';
    }

    c[cmp+1] = '\0';


}

extern void reset_chain(char* c)
{

    *c = '\0';

}

int fill_chain(char* c, Tree a, char letter)
{
    if ( a == NULL)
    {
        exit(1);
    }

    else if ( (a->sad == NULL) && (a->sag == NULL)  )
    {
        if(a->letter != letter)
        {
            printf("letter \"%c\" is not in tree", letter);
            exit(1);
        }
        return 0;
    }

    else if ( a->sag->letter == letter )
    {
        add_1_or_0(c, 0);
        return 0;
    }

    else
    {
        add_1_or_0(c, 1);
        return fill_chain(c, a->sad, letter);
    }
}

extern void dico_huffman(Tree a, Element* l)
{

    if ( a == NULL)
    {
        return;
    }

    char chain[60] = "\0";
    FILE* fichier;
    fichier = fopen("dico.txt","r+");

    while ( l != NULL)
    {

        fill_chain(chain, a, l->lettre);
        fprintf(fichier, "%c:", l->lettre);
        fprintf(fichier, "%s", chain);
        fputs("\n", fichier);
        reset_chain(chain);
        l = l->next;

    }

    fclose(fichier);

}

extern void encoding()
{

    FILE* fichier1 = NULL;
    FILE* fichier2 = NULL;
    FILE* fichier3 = NULL;

    fichier1=fopen("entree.txt","r");
    fichier2=fopen("dico.txt", "r");
    fichier3=fopen("sortieCompressee.txt","a");


    if( (fichier1 != NULL) && (fichier2 != NULL) && (fichier3 != NULL) )
    {

        int char_fichier1;
        int char_fichier2;
        int char_fichier3;


        while( (char_fichier1 = fgetc(fichier1)) != EOF )
        {
            while( (char_fichier2 = fgetc(fichier2)) != EOF )
            {
                if ( (char_fichier2 == char_fichier1) )
                {
                    fseek(fichier2,2, SEEK_CUR);
                    while( (char_fichier3 = fgetc(fichier2)) != '\n')
                    {
                        fputc(char_fichier3, fichier3);
                    }
                    fseek(fichier2,0, SEEK_END);
                }
            }
            rewind(fichier2);
        }
        fclose(fichier1);
        fclose(fichier2);
        fclose(fichier3);
        return;
    }
    else //On gère les cas d'erreur d'ouverture des fichiers
    {
        if(fichier1 == NULL)
        {

            if(fichier2 == NULL)
            {

                if(fichier3 == NULL)
                    printf("Erreur d'ouverture de l'un des fichiers");
                exit(1);

            }
            else if( fichier3 == NULL )
            {
                printf("Erreur d'ouverture du fichier sortieCompressee");
                exit(1);
            }
        }
        else if(fichier2 == NULL)
        {
            if(fichier3 == NULL)
            {
                printf("Erreur d'ouverture de l'un des fichiers");
                exit(1);
            }

        }
    }
    return;
}





