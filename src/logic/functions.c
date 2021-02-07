#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../includes/functions.h"


// ********* les fonctions :
// ** Gestion des adhérents :

adherent * modifier_adherent(adherent* adh,adh_info* nouv_info){
    adh->info_adh = nouv_info;
    return adh;
}
list_adherent recherche_adherent(list_adherent tete,char nom[]){
    list_adherent list_res = NULL; // list_res est la liste des adherents ayant le nom recherché.
    adherent *p = tete;
    adherent *r = list_res;
    while(p!=NULL){
        if(!strcmp(p->info_adh->nom_adh,nom)){ // càd si nom == inf_adh->nom_adh :
            r = Malloc(adherent);
            if(r!=NULL){
                r->info_adh = p->info_adh;
                r->next = NULL;
                r = r->next;
                p = p->next;
            }
            else{
                printf("erreur!! pas d'espace memoire.");
                exit(1);
            }
        }
    }
    return list_res;
}

// ** Gestion des Livres :

livre * modifier_livre(livre* liv,liv_info* nouv_info){
    liv->info_liv = nouv_info;
    return liv;
}
list_livre recherche_livre(list_livre tete,char categ[]){
    list_livre list_res = NULL; // list_res est la liste des livres ayant la catégorie recherché.
    livre *p = tete;
    livre *r = list_res;
    // on suppose que la liste est déja ordonné par les catégories.
    while((p!=NULL)&&(strcmp(p->info_liv->categ_liv,categ))){// on cherche le premier livre dans la liste avec cette catégorie.
        p = p->next;
    }
    while((p!=NULL)&&(!strcmp(p->info_liv->categ_liv,categ))){// on ajoute tout les livres avec cette catégorie à use autre liste qu'on retourn.
        r = Malloc(livre);
        if(r!=NULL){
            r->info_liv = p->info_liv;
            r->next = NULL;
            r = r->next;
            p = p->next;
        }
        else{
            printf("erreur!! pas d'espace memoire.");
            exit(1);
        }
    }
    return list_res;
}

// ** Gestion des emprunts :

void Rendre_liv(livre* liv,adherent* emprunteur){
    liv->info_liv->emprunteur_liv = 0;
    emprunteur->info_adh->nbre_emprunts_adh-=1;
}


// ** les fichier de stockage.

void charger(int *numAdh,list_adherent *ladh,int *numLiv,list_livre *lliv){
    list_adherent *tempadh = ladh;
    list_livre *templiv = lliv;
    FILE *fAdh,*fLiv;
    fAdh = fopen("src/donnes/adh_donnes.data","rb");
    fLiv = fopen("src/donnes/liv_donnes.data","rb");
    if(fAdh==NULL||fLiv==NULL){
        exit(1);
    }
    else{
        fread(numAdh,sizeof(int),1,fAdh);
        while(!feof(fAdh)){
            
        }
    }
}
void sauvegarder(int numAdh,list_adherent ladh,int numLiv,list_livre lliv){
    FILE *fAdh,*fLiv;
    fAdh = fopen("src/donnes/adh_donnes.data","wb");
    fLiv = fopen("src/donnes/liv_donnes.data","wb");
    if(fAdh==NULL||fLiv==NULL){
        exit(1);
    }
    else{
        fwrite(&numAdh,sizeof(int),1,fAdh);
        while(ladh!=NULL){
            fwrite(ladh->info_adh,sizeof(adh_info),1,fAdh);
        }
        fclose(fAdh);
        fwrite(&numLiv,sizeof(int),1,fAdh);
        while(lliv!=NULL){
            fwrite(lliv->info_liv,sizeof(liv_info),1,fLiv);
        }
        fclose(fLiv);
    }
}
int test_vide(adherent* li){
    if (li==NULL){
        return 1;
    }
}

/*--------------------------------------------------------*/

int test_videl(livre* li){
    if (li==NULL){
        return 1;
    }
}

/*--------------------------------------------------------*/

adherent* ajouter_adherent(adherent* ptr,adh_info* new_adh){
    adherent* p;
    p=(adherent*)malloc(sizeof(adherent));
    p->info_adh=new_adh;
    if(ptr==NULL){
         p->next=NULL;
         return p;
    }
    p->next=ptr->next;
    return p;   
}


/*---------------------------------------------------*/

adherent* supprimes_adherent(adherent* ptr,int code){
    adherent* p;
    p=ptr;
    if (p->info_adh->num_adh==code){
        ptr=p->next;
        free(p);
        return ptr;
    }
    while(p->next->info_adh->num_adh!=code && p->next->next!=NULL){
        p=p->next;
    }
    if (p->next->next!=NULL){
        adherent* c=p->next;
        p->next=p->next->next;
        free(c);
        return ptr;
    }
    else{
        adherent* c=p->next;
        p->next=NULL;
        free(c);
        return ptr;
    }
}

/*-------------------------------------------------------------*/

livre* ajouter_livre(livre* ptr,liv_info* new_liv){
    livre* p;
    p=(livre*)malloc(sizeof(livre));
    p->info_liv=new_liv;
    if (ptr==NULL){
        p->next=NULL;
        return p;
    }
    p->next=ptr->next;
    return p;
}

/*--------------------------------------------------------*/
livre* supprimes_livre(livre* ptr,int code){
    livre* p;
    p=ptr;
    if (p->info_liv->num_liv==code){
        ptr=p->next;
        free(p);
        return ptr;
    }
    while(p->next->info_liv->num_liv!=code && p->next->next!=NULL){
        p=p->next;
    }
    if (p->next->next!=NULL){
        livre* c=p->next;
        p->next=p->next->next;
        free(c);
        return ptr;
    }
    else{
        livre* c=p->next;
        p->next=NULL;
        free(c);
        return ptr;
    }
}

/*-------------------------------------------------*/

void enprunter_livre(adherent* ptra,livre* ptrl,int codea,int codel){
    adherent* a;
    a=ptra;
    while(a->info_adh->num_adh!=codea){
        a=a->next;
    }
    if(a->info_adh->nbre_emprunts_adh>=3){
        printf("tu ne peux pas emprunter un autre livre");
        exit(EXIT_FAILURE);
    }
    livre* l;
    l=ptrl;
    while(l->info_liv->num_liv!=codel){
        l=l->next;
    }
    l->info_liv->emprunteur_liv=codea;
}

