#include "connexe.h"

MatriceConnexe ComposanteConnexe(Graphe *GRAPHE)
{
    MatriceConnexe MC;
    MC.n = GRAPHE->data;
    MC.data = malloc(sizeof(int)*GRAPHE->data);
    memset(MC.data,0,GRAPHE->data*4);
    ulong c = 1;
    for (ulong i = 0; i < GRAPHE->data ; ++i){
        if(MC.data[i]==0){
            MC.data[i]=c;
            for (int j = 0; j <GRAPHE->liste[i].data ; ++j){
                rechercheConnexe(GRAPHE,&MC,GRAPHE->liste[i].ajout[j],c);
            }
            c++;
        }
    }
    printf("Les connexes sont faites\n\n");
    return  MC;
}

int rechercheConnexe(Graphe *GRAPHE,MatriceConnexe *MC, ulong index, int c){
    if(MC->data[index]==0){
        MC->data[index] = c;
        for(int i = 0;i<GRAPHE->liste[index].data;i++)
            rechercheConnexe(GRAPHE,MC,GRAPHE->liste[index].ajout[i],c);
    }
    return 1;
}

MatriceConnexe Suppr4V(Graphe *GRAPHE, MatriceConnexe MC){
    ulong c = 0;
    MatriceConnexe tmp;
    for (ulong i = 0; i <GRAPHE->data ; ++i){
        if(GRAPHE->liste[i].data<4)
            c++;
    }
    printf("Avant suppression: %ld\n",GRAPHE->data);
    printf("Apres suppression: %ld\n",c);
    tmp.n = c;
    tmp.data = malloc(sizeof(int)*c);
    c=0;
    for (ulong i = 0; i <GRAPHE->data ; ++i){
        if(GRAPHE->liste[i].data<4){   
            tmp.data[c] = GRAPHE->liste[i].x;
            c++;
        }
    }
    printf("\n");
    return tmp;
}

void print_MC(Graphe *GRAPHE){	
    ulong c;
	for (int i = 0; i < GRAPHE->data; ++i){	
        if(GRAPHE->liste[i].data>0){
            c++;
            for (int j = 0; j < GRAPHE->liste[i].data; ++j){
                //printf("X:%ld R:%d G:%d B:%d\n",GRAPHE->liste[i].x, GRAPHE->liste[i].R,GRAPHE->liste[i].G,GRAPHE->liste[i].B);
                printf("%ld,",GRAPHE->liste[i].ajout[j]);
            }
            printf("\n");
        }
	}
}

/*void compressionMatriceCompacte(Graphe *GRAPHE, MatriceConnexe MC, Image *Image) { 
    struct MatriceCompact *temp, *r; 
    temp = ; 
    if (temp == NULL) {

        temp = (struct Node *) malloc (sizeof(struct Node)); 
        temp->value = n; 
        temp->ligne = IndexLigne; 
        temp->colone = ImdexColone; 
        temp->next = NULL; 
        *start = temp; 
  
    } 
    else
    { 
        while (temp->next != NULL) 
            temp = temp->next; 

        r = (struct Node *) malloc (sizeof(struct Node)); 
        r->value = n; 
        r->ligne = IndexLigne; 
        r->colone = column_index; 
        r->next = NULL; 
        temp->next = r; 
  
    } 
} 
*/