#include "graphe.h"



typedef struct MatriceConnexe MatriceConnexe;
struct MatriceConnexe{   
    int n;
    ulong x, y;
	int *data;
};

typedef struct MatriceCompacte MatriceCompacte;
struct MatriceCompacte{
    int n; 
    int IndexLigne; 
    int ImdexColone; 
    struct MatriceCompacte *next; 
};

MatriceConnexe ComposanteConnexe(Graphe * Graphe);
int rechercheConnexe(Graphe *Graphe,MatriceConnexe * MC, ulong index, int c);
MatriceConnexe Suppr4V(Graphe*Graphe, MatriceConnexe MC);
void print_MC(Graphe *GRAPHE);