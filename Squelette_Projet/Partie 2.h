/*****************************************************************//**
 * \file   Partie 2.h
 * \brief  Header for the partie 2.h
 * 
 * \author Maxence Cerfontaine 
 * \date   December 2020
 *********************************************************************/

#ifndef PARTIE_2_H_INCLUDED
#define PARTIE_2_H_INCLUDED

typedef struct Element{
    int occurrence;
    int lettre;
    struct Element* next;
}Element;

typedef struct Node{
    struct Node* sad;
    struct Node* sag;
    int  occur;
    char letter;
}Node;

typedef Node* Tree;

extern void print_list(Element* l);
extern void print_tree(Tree a);
extern void add_1_or_0(char* c, int nbr);
extern void reset_chain(char* c);
extern void dico_huffman(Tree a, Element* l);
extern void encoding();
int maximum_letter(Element* l);
int maximum_occurrence(Element* l);
int size_list(Element *l);
int recup_occurrence(Element *l);
int nbr_occurrence(Element* l);
int fill_chain(char* c, Tree a, char letter);
Element* create_elem_List(int lettre);
Element* create_list_letter();
Element* supp_element(Element** l, int occurrence, char letter);
Element* create_element(int nouv_info);
Node* create_node(int occur, char letter);
Node* tree_huffman(Element* l);


#endif // PARTIE_2_H_INCLUDED
