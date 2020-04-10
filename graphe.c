#include "graphe.h"
#define LIM 9

//fonction de verification pour savoir si 2 pixel sont de la meme couleur
float Pixel_Identique(GLubyte *pixel1, GLubyte *pixel2){
	return sqrt(pow(pixel1[0] - pixel2[0],2)+pow(pixel1[1] - pixel2[1],2) + pow(pixel1[2] - pixel2[2],2));
}

//fonction de conversion des pixel de l'image en 3 graphe RGB
Graphe* ImageEnGraphe(Image *Image){
    Graphe *GRAPHE = malloc(sizeof(Graphe));
    GRAPHE->liste = malloc(sizeof(Noeud)*Image->sizeX *Image->sizeY);
    GRAPHE->sizeX =Image->sizeX;
    GRAPHE->sizeY =Image->sizeY;
    ulong Size = GRAPHE->sizeX *GRAPHE->sizeY;
    GRAPHE->data=Size;
    for (int i = 0; i < GRAPHE->data ; i++){		
        ulong j = i*3;
        GRAPHE->liste[i].ajout = malloc(sizeof(ulong) * 4 );
        if(i < Image->sizeX){				
            GRAPHE->liste[i].data = 0;
            GRAPHE->liste[i].x = i;
            GRAPHE->liste[i].R = Image->data [j];
            GRAPHE->liste[i].G = Image->data [j+1];
            GRAPHE->liste[i].B = Image->data [j+2];
            if(Pixel_Identique(Image->data + j, Image->data + j + Image->sizeX * 3)<LIM)
                GRAPHE->liste[i].ajout[GRAPHE->liste[i].data++] = i + Image->sizeX;

            if(i%Image->sizeX-1>0 && Pixel_Identique(Image->data+j , Image->data+j-3)<LIM)
                GRAPHE->liste[i].ajout[GRAPHE->liste[i].data++] = i - 1;

            if((i+1)/Image->sizeY == i/Image->sizeY && Pixel_Identique(Image->data + j, Image->data + j +  3)<LIM)
                GRAPHE->liste[i].ajout[GRAPHE->liste[i].data++] = i + 1;
        }
        else if(i + Image->sizeX < Size){
            GRAPHE->liste[i].x = i;
            GRAPHE->liste[i].R = Image->data [j];
            GRAPHE->liste[i].G = Image->data [j+1];
            GRAPHE->liste[i].B = Image->data [j+2];
            if(Pixel_Identique(Image->data+j,Image->data + j + Image->sizeX * 3 )<LIM)
                GRAPHE->liste[i].ajout[GRAPHE->liste[i].data++] = i +Image->sizeX;

            if(Pixel_Identique(Image->data+j,Image->data + j - Image->sizeX * 3 ) <LIM)
                GRAPHE->liste[i].ajout[GRAPHE->liste[i].data++] = i -Image->sizeX;

            if(i%Image->sizeX-1>0 && Pixel_Identique(Image->data+j , Image->data+j-3)<LIM)
                GRAPHE->liste[i].ajout[GRAPHE->liste[i].data++] = i - 1;

            if((i+1)/Image->sizeY == i/Image->sizeY && Pixel_Identique(Image->data + j, Image->data + j +  3)<LIM)
                GRAPHE->liste[i].ajout[GRAPHE->liste[i].data++] = i + 1;
        }
        else{
            GRAPHE->liste[i].x = i;
            GRAPHE->liste[i].R = Image->data [j];
            GRAPHE->liste[i].G = Image->data [j+1]; 	
            GRAPHE->liste[i].B = Image->data [j+2];	
            if(Pixel_Identique(Image->data+j,Image->data + j - Image->sizeX * 3 ) <LIM)
                GRAPHE->liste[i].ajout[GRAPHE->liste[i].data++] = i - Image->sizeX*3;

            if(i%Image->sizeX-1>0 && Pixel_Identique(Image->data+j , Image->data+j-3)<LIM)
                GRAPHE->liste[i].ajout[GRAPHE->liste[i].data++] = i - 1;
                
            if((i+1)/Image->sizeY == i/Image->sizeY && Pixel_Identique(Image->data + j, Image->data + j +  3)<LIM)
                GRAPHE->liste[i].ajout[GRAPHE->liste[i].data++] = i + 1;
        }	
        //printf("X:%ld R:%d G:%d B:%d\n",GRAPHE->liste[i].x, GRAPHE->liste[i].R,GRAPHE->liste[i].G,GRAPHE->liste[i].B);

    }
    return GRAPHE;
}


//fonction de comversion de graphe vers image avec visualisation des borres afficher le borre de l'image
int GrapheEnImage(Graphe *GRAPHE, Image *Image){
    for (ulong i = 0; i < GRAPHE->data; ++i){	
		if(GRAPHE->liste[i].data==4){
			Image->data[i*3] = GRAPHE->liste[i].R;
			Image->data[i*3+1] = GRAPHE->liste[i].G;
			Image->data[i*3+2] = GRAPHE->liste[i].B;
		}
		else{
			Image->data[i*3] = GRAPHE->liste[i].R*2;
			Image->data[i*3+1] = GRAPHE->liste[i].G;
			Image->data[i*3+2] = 0;
		}
    //printf("X:%ld R:%d G:%d B:%d\n",GRAPHE->liste[i].x, GRAPHE->liste[i].R,GRAPHE->liste[i].G,GRAPHE->liste[i].B);
	}
    return 1;
}

//fonction pour liberer le graphe
void freeGraphe(Graphe *GRAPHE){
    if(GRAPHE){
        for (ulong i = 0; i<GRAPHE->data; i++){
            free(GRAPHE->liste[i].ajout);
        }
        free(GRAPHE->liste);
    }
}