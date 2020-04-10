#include "ima.h"

typedef struct Noeud Noeud;
struct Noeud{
    ulong x,y;
    GLubyte R,G,B;
    int data;
    ulong *ajout;
};

typedef struct GrListe GrListe;
struct GrListe{
	Noeud *data;
	GrListe *next;
};

typedef struct Liste Liste;
 struct Liste{
    GrListe *data;
    Liste *next;
};


GrListe *init_GListe( Noeud *data);
Liste *init_Liste(GrListe *data);

int find_GListe(GrListe *tete, Noeud *data);

GrListe *add_GListe(GrListe *tete, Noeud * data);
Liste *add_Liste(Liste *tete, GrListe *data);

void free_GListe(GrListe *tete);
void free_Liste(Liste *tete);