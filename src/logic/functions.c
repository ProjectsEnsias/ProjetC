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
    int i = 0;
    list_adherent tempadh = (*ladh);
    list_livre templiv = (*lliv);
    FILE *fAdh,*fLiv;
    fAdh = fopen("./donnes/adh_donnes.data","rb");
    fLiv = fopen("./donnes/liv_donnes.data","rb");
    if(fAdh==NULL||fLiv==NULL){
        exit(1);
    }
    else{
        fread(numAdh,sizeof(int),1,fAdh);
        while(!feof(fAdh)&&i<*numAdh){
            tempadh = Malloc(adherent);
            tempadh->info_adh = Malloc(adh_info);
            tempadh->next = NULL;
            fread(tempadh->info_adh,sizeof(adh_info),1,fAdh);
            tempadh = tempadh->next;
            i++;
        }
        fclose(fAdh);
        printf("kjdfk  %d \n ",(*ladh)->info_adh->nbre_emprunts_adh);
        fread(numLiv,sizeof(int),1,fLiv);
        while(!feof(fLiv)){
            i = 0;
            templiv = Malloc(livre);
            templiv->info_liv = Malloc(liv_info);
            templiv->next = NULL;
            fread(templiv->info_liv,sizeof(adh_info),1,fLiv);
            templiv = templiv->next;
            i++;
        }
        fclose(fLiv);
    }
}
void sauvegarder(int numAdh,list_adherent ladh,int numLiv,list_livre lliv){
    FILE *fAdh,*fLiv;
    fAdh = fopen("donnes/adh_donnes.data","wb");
    if(fAdh==NULL){
        exit(1);
    }
    else{
        fwrite(&numAdh,sizeof(int),1,fAdh);
        while(ladh!=NULL){
            fwrite(ladh->info_adh,sizeof(adh_info),1,fAdh);
            ladh = ladh->next;
        }
        fclose(fAdh);
    }
    fLiv = fopen("donnes/liv_donnes.data","wb");
    if(fLiv==NULL){
        exit(1);
    }
    else{
        fwrite(&numLiv,sizeof(int),1,fLiv);
        while(lliv!=NULL){
            fwrite(&(lliv->info_liv->num_liv),sizeof(int),1,fLiv);
            fwrite(lliv->info_liv->titre_livre,20*sizeof(char),1,fLiv);
            fwrite(lliv->info_liv->categ_liv,30*sizeof(char),1,fLiv);
            fwrite(&(lliv->info_liv->emprunteur_liv),sizeof(int),1,fLiv);
            fwrite(&(lliv->info_liv->auteur_liv),sizeof(auteur),1,fLiv);
            lliv = lliv->next;
        }
        fclose(fLiv);
    }
    return;
}



