#include "liste.h"


typedef struct Graphe Graphe;
struct Graphe{
    ulong data;
    ulong sizeX, sizeY;
    Noeud *liste;
};


Graphe* ImageEnGraphe(Image *Image);
int GrapheEnImage(Graphe * Graphe, Image * Image);
void freeGraphe(Graphe *Graphe);