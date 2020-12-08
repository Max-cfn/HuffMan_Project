#ifndef PARTIE_2_H_INCLUDED
#define PARTIE_2_H_INCLUDED

typedef struct Element{
    int occurence;
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
int maximum_letter(Element* l);
int maximum_occurence(Element* l);
int size_list(Element *l);
int recup_occurence(Element *l);
int nbr_occurence(Element* l);
int fill_chain(char* c, Tree a, Element* l);
Element* create_elem_List(int lettre);
Element* creat_list_letter();
Element* supp_element(Element** l, int maxi);
Element* create_element(int nouv_info);
Node* create_node(int occur, char letter);
Node* tree_huffman(Element* l);

#endif // PARTIE_2_H_INCLUDED
