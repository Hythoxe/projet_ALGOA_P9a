#include "liste.h"

//Initialise une liste de noeud
GrListe *init_GListe( Noeud *data){
    GrListe *tete  = malloc(sizeof(GrListe));
    tete->data = data;
    tete->next = NULL;
    return tete;
}
//Initialise une liste de liste de noeud
Liste *init_Liste(GrListe *data){ 
    Liste *tete = malloc(sizeof(Liste));
    tete->data = data;
    tete->next = NULL;
    return tete;
}

int find_GListe(GrListe *tete,Noeud *data){
    if(!tete)
        return -1;
    while(tete){
        if(tete->data->x == data->x)
            return 1;
        tete = tete->next;
    }
    return 0;
}

//ajoute a la liste un noeud
GrListe *add_GListe(GrListe *tete,Noeud *data){
    if(!tete){
        fprintf(stderr,"%s\n","Erreur d'allocation");
        return NULL;
    }
    GrListe *tmp = tete;
    while(tmp->next)
        tmp = tmp->next;

    GrListe *suiv = malloc(sizeof(GrListe));
    assert(suiv);
    suiv->data = data;
    tmp->next = suiv;
    return tete;
}
//ajout a la liste de liste de noeud
Liste *add_Liste(Liste *tete,GrListe *data){   
    if(!tete){
        fprintf(stderr,"%s\n","Erreur d'allocation");
        return NULL;
    }
    Liste *tmp = tete;
    while(tmp->next)
        tmp = tmp->next;

    Liste *suiv = malloc(sizeof(Liste)); 
    suiv->data = data;
    tmp->next = suiv;
    return tete;
}
//free la liste de noeud
void free_GListe(GrListe *tete){
    if(!tete)
        return ;
    free_GListe(tete->next);
    free(tete);
}
//free la liste de liste de noeud
void free_Liste(Liste *tete){
    if(!tete)
        return ;
    free_Liste(tete->next);
    free_GListe(tete->data);
    free_Liste(tete);
}
