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
list_adherent recherche_adherent(list_adherent tete,char nom[],int *num){
    if(!strcmp(nom,"")) return tete;
    list_adherent list_res = Malloc(adherent); // list_res est la liste des adherents ayant le nom recherché.
    adherent *p = tete;
    adherent *r = list_res;
    *num = 0;
    while(p->next!=NULL){
        if(!strcmp(p->info_adh->nom_adh,nom)){ // càd si nom == inf_adh->nom_adh :
            if(r!=NULL){
                (*num)++;
                r->info_adh = p->info_adh;
                r->next = Malloc(adherent);;
                r = r->next;
                p = p->next;
            }
            else{
                printf("erreur!! pas d'espace memoire.");
                exit(1);
            }
        }
        else{
            p = p->next;
        }
    }
    return list_res;
}
list_adherent recherche_emprenteurs(list_adherent tete,int* num){
    list_adherent list_res = Malloc(adherent); // list_res est la liste des adherents ayant le nom recherché.
    adherent *p = tete;
    adherent *r = list_res;
    *num = 0;
    while(p->next!=NULL){
        if(p->info_adh->nbre_emprunts_adh>0){ // càd si nom == inf_adh->nom_adh :
            if(r!=NULL){
                (*num)++;
                r->info_adh = p->info_adh;
                r->next = Malloc(adherent);;
                r = r->next;
                p = p->next;
            }
            else{
                printf("erreur!! pas d'espace memoire.");
                exit(1);
            }
        }
        else{
            p = p->next;
        }
    }
    return list_res;
}
int test_vide(adherent* li){
    if (li==NULL){
        return 1;
    }
}
adherent* ajouter_adherent(adherent* ptr,adh_info* new_adh){
    adherent* p  = Malloc(adherent);
    p->info_adh=new_adh;
    if(ptr==NULL){
        adherent* c = Malloc(adherent);
        c->next = NULL;
        p->next=c;
        return p;
    }
    p->next=ptr;
    return p;
}
adherent* supprimes_adherent(adherent* ptr,int code,int* numAdh,livre** ptrl){
    livre *l = (*ptrl);
    while(l->next!=NULL){
        if(l->info_liv->emprunteur_liv==code){
            l->info_liv->emprunteur_liv = -1;
        }
        l = l->next;
    }
    if(ptr->next==NULL) return ptr;
    if (ptr->info_adh->num_adh==code){
        ptr=ptr->next;
        (*numAdh)--;
        return ptr;
    }
    adherent* p;
    p=ptr;
    while(p->next->info_adh->num_adh!=code && p->next->next!=NULL){
        p=p->next;
    }
    if (p->next->next!=NULL){
        adherent* c=p->next;
        p->next=p->next->next;
        (*numAdh)--;
        free(c);
        return ptr;
    }
    else{
        if(p->next->info_adh->num_adh!=code){
            return ptr;
        }
        else{
            (*numAdh)--;
            free(p->next);
            p->next = NULL;
            return ptr;
        }
    }
}


// ** Gestion des Livres :

livre * modifier_livre(livre* liv,liv_info* nouv_info){
    liv->info_liv = nouv_info;
    return liv;
}
list_livre recherche_livre(list_livre tete,char categ[],char titre[],int* num){
    *num = 0;
    list_livre list_res = Malloc(livre); // list_res est la liste des livres ayant la catégorie recherché.
    livre *p = tete;
    livre *r = list_res;
    if(!strcmp(titre,"")){
        while((p->next!=NULL)){
            if((!strcmp(p->info_liv->categ_liv,categ))){
                if(r!=NULL){
                    (*num)++;
                    r->info_liv = p->info_liv;
                    r->next = NULL;
                    r->next = Malloc(livre);
                    r = r->next;
                    p = p->next;
                }
                else{
                    printf("erreur!! pas d'espace memoire.");
                    exit(1);
                }
            }
            else{
                p = p->next;
            } 
        }
    }
    else if(!strcmp(categ,"")){
        while((p->next!=NULL)){
            if((!strcmp(p->info_liv->titre_livre,titre))){
                if(r!=NULL){
                    (*num)++;
                    r->info_liv = p->info_liv;
                    r->next = NULL;
                    r->next = Malloc(livre);
                    r = r->next;
                    p = p->next;
                }
                else{
                    printf("erreur!! pas d'espace memoire.");
                    exit(1);
                }
            }
            else{
                p = p->next;
            } 
        }
    }
    else{
        while((p->next!=NULL)){
            if((!strcmp(p->info_liv->titre_livre,titre))&&(!strcmp(p->info_liv->categ_liv,categ))){
                if(r!=NULL){
                    (*num)++;
                    r->info_liv = p->info_liv;
                    r->next = NULL;
                    r->next = Malloc(livre);
                    r = r->next;
                    p = p->next;
                }
                else{
                    printf("erreur!! pas d'espace memoire.");
                    exit(1);
                }
            }
            else{
                p = p->next;
            } 
        }
    }
    
    return list_res;
}
list_livre recherche_livres_emptuntes(list_livre tete,int* num){
    *num = 0;
    list_livre list_res = Malloc(livre); // list_res est la liste des livres ayant la catégorie recherché.
    livre *p = tete;
    livre *r = list_res;
    while((p->next!=NULL)){
        if((p->info_liv->emprunteur_liv)>-1){
            if(r!=NULL){
                (*num)++;
                r->info_liv = p->info_liv;
                r->next = NULL;
                r->next = Malloc(livre);
                  r = r->next;
                p = p->next;
            }
            else{
                printf("erreur!! pas d'espace memoire.");
                exit(1);
            }
        }
        else{
            p = p->next;
        } 
    }
    return list_res;
}
int test_videl(livre* li){
    if (li==NULL){
        return 1;
    }
}
livre* ajouter_livre(livre* ptr,liv_info* new_liv){
    livre* p = Malloc(livre);
    p->info_liv=new_liv;
    if (ptr==NULL){
        livre* c = Malloc(livre);
        c->next = NULL;
        p->next=c;
        return p;
    }
    p->next=ptr;
    return p;
}
livre* supprimes_livre(livre* ptr,int code,int *numLiv){
    if(ptr->next==NULL) return ptr;
    if (ptr->info_liv->num_liv==code){
        ptr=ptr->next;
        (*numLiv)--;
        return ptr;
    }
    livre* p;
    p=ptr;
    while(p->next->info_liv->num_liv!=code && p->next->next!=NULL){
        p=p->next;
    }
    if (p->next->next!=NULL){
        livre* c=p->next;
        p->next=p->next->next;
        free(c);
        (*numLiv)--;
        return ptr;
    }
    else{
        if(p->next->info_liv->num_liv!=code){
            return ptr;
        }
        else{
            (*numLiv)--;
            free(p->next);
            p->next = NULL;
            return ptr;
        }
    }
}

// ** Gestion des emprunts :

void rendre_liv(livre** ptrl,int codel,adherent** ptra){
    livre* l;
    l=(*ptrl);
    while((l->info_liv->num_liv!=codel)&&(l->next->next!=NULL)){
        l=l->next;
    }
    if(l->info_liv->num_liv!=codel) return;
    if(l->info_liv->emprunteur_liv==-1) return;
    int codea = l->info_liv->emprunteur_liv;
    l->info_liv->emprunteur_liv = -1;
    adherent* a;
    a=(*ptra);
    while((a->info_adh->num_adh!=codea)&&(a->next->next!=NULL)){
        a=a->next;
    }
    if(a->info_adh->num_adh!=codea) return;
    if(a->info_adh->nbre_emprunts_adh<=0){
        return;
    }
    (a->info_adh->nbre_emprunts_adh)--;
    return;
}
void enprunter_livre(adherent** ptra,livre** ptrl,int codea,int codel){
    adherent* a;
    a=(*ptra);
    while((a->info_adh->num_adh!=codea)&&(a->next->next!=NULL)){
        a=a->next;
    }
    if(a->info_adh->num_adh!=codea) return;
    if(a->info_adh->nbre_emprunts_adh>=3){
        return;
    }
    livre* l;
    l=(*ptrl);
    while((l->info_liv->num_liv!=codel)&&(l->next->next!=NULL)){
        l=l->next;
    }
    if(l->info_liv->num_liv!=codel) return;
    if(l->info_liv->emprunteur_liv != a->info_adh->num_adh) {   (a->info_adh->nbre_emprunts_adh)++;} 
    l->info_liv->emprunteur_liv = a->info_adh->num_adh;
    return;
}

// ** les fichier de stockage :

void charger(int *numAdh,list_adherent *ladh,int *numLiv,list_livre *lliv){
    int i = 0;
    *ladh = Malloc(adherent);
    *lliv = Malloc(livre);
    (*ladh)->next = NULL;
    (*lliv)->next = NULL;
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
            tempadh->info_adh = Malloc(adh_info);
            fread(tempadh->info_adh,sizeof(adh_info),1,fAdh);
            tempadh->next = Malloc(adherent);
            tempadh = tempadh->next;
            i++;
        }
        i = 0;
        fclose(fAdh);
        fread(numLiv,sizeof(int),1,fLiv);
        while(!feof(fLiv)&&i<*numLiv){
            templiv->info_liv = Malloc(liv_info);
            fread(templiv->info_liv,sizeof(liv_info),1,fLiv);
            templiv->next = Malloc(livre);
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
        while(ladh->next!=NULL){
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
        while(lliv->next!=NULL){
            fwrite(lliv->info_liv,sizeof(liv_info),1,fLiv);
            lliv = lliv->next;
        }
        fclose(fLiv);
    }
    return;
}

// ** libération de la mémoire :

void clear_list_adh(adherent** ladh){
    if((*ladh)->next==NULL){
        free((*ladh));
        return;
    }
    clear_list_adh(&((*ladh)->next));
    free((*ladh));
    return;
}
void clear_list_liv(livre** lliv){
    if((*lliv)->next==NULL){
        free((*lliv));
        return;
    }
    clear_list_liv(&((*lliv)->next));
    free((*lliv));
    return;
}

