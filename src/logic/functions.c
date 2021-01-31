#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../includes/functions.h"


// ********* les fonctions :
// ** Gestion des adhérents :

adherent * modifier_adherent(adherent* adh,adh_info* nouv_info){
    adh->info_adh = *(nouv_info);
    return adh;
}
list_adherent recherche_adherent(list_adherent tete,char nom[]){
    list_adherent list_res = NULL; // list_res est la liste des adherents ayant le nom recherché.
    adherent *p = tete;
    adherent *r = list_res;
    while(p!=NULL){
        if(!strcmp(p->info_adh.nom_adh,nom)){ // càd si nom == inf_adh.nom_adh :
            r = Malloc(adherent,1);
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

adherent * modifier_livre(livre* liv,liv_info* nouv_info){
    liv->info_liv = *(nouv_info);
    return liv;
}
list_livre recherche_livre(list_livre tete,char categ[]){
    list_adherent list_res = NULL; // list_res est la liste des livres ayant la catégorie recherché.
    livre *p = tete;
    livre *r = list_res;
    // on suppose que la liste est déja ordonné par les catégories.
    while((p!=NULL)&&(strcmp(p->info_liv.categ_liv,categ))){// on cherche le premier livre dans la liste avec cette catégorie.
        p = p->next;
    }
    while((p!=NULL)&&(!strcmp(p->info_liv.categ_liv,categ))){// on ajoute tout les livres avec cette catégorie à use autre liste qu'on retourn.
        r = Malloc(livre,1);
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
    liv->info_liv.emprunteur_liv = 0;
    emprunteur->info_adh.nbre_emprunts_adh-=1;
}

