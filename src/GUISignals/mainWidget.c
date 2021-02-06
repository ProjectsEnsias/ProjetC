#include <stdio.h>
#include <stdlib.h>
#include "../../includes/mainWidget.h"
#include <string.h>
#include <gtk/gtk.h>


void destr(){
    exit(0);
}

void on_adh_taggeled(GtkRadioButton *b,int *adhOuLiv){
    gboolean t = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if(t){
        *adhOuLiv = 1;
    }
    return;
}
void on_liv_taggeled(GtkRadioButton *b,int *adhOuLiv){
    gboolean t = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if(t){
        *adhOuLiv = 0;
    }
    return;
}
void afficher_liv(int numLiv,list_livre head,GtkWidget *adhs,GtkWidget *lables[1000]){
    int i;
    char *temp = (char*)malloc(1000*sizeof(char));
    char *temp1 = (char*)malloc(50*sizeof(char));;
    for(i=0;i<numLiv;i++){
        sprintf(temp,"titre : %s\n",head->info_liv->titre_livre);
        temp = strcat(temp,"Auteur : ");
        temp = strcat(temp,head->info_liv->auteur_liv.prenom_aut);
        temp = strcat(temp," ");
        temp = strcat(temp,head->info_liv->auteur_liv.nom_aut);
        temp = strcat(temp,"\n");
        temp = strcat(temp,"Catégorie : ");
        temp = strcat(temp,head->info_liv->categ_liv);
        temp = strcat(temp,"\n");
        temp = strcat(temp,"Numéro de livre : ");
        sprintf(temp1,"%d\n",head->info_liv->num_liv);
        temp = strcat(temp,temp1);
        temp = strcat(temp,"Numéro de l'emprunteur : ");
        sprintf(temp1,"%d\n",head->info_liv->emprunteur_liv);
        temp = strcat(temp,temp1);
        temp = strcat(temp,"___________________________________________________________________________________________\n\n");
        lables[i] = gtk_label_new(temp);
        gtk_grid_attach(GTK_GRID(adhs),lables[i],1,i,1,1);
    }
    free(temp);
    free(temp1);
}
void afficher_adh(int numAdh,list_adherent head,GtkWidget *adhs,GtkWidget *lables[1000]){
    int i;
    char *temp = (char*)malloc(1000*sizeof(char));
    char *temp1 = (char*)malloc(50*sizeof(char));;
    for(i=0;i<numAdh;i++){
        sprintf(temp,"Prénom : %s\n",head->info_adh->prenom_adh);
        temp = strcat(temp,"Nom : ");
        temp = strcat(temp,head->info_adh->nom_adh);
        temp = strcat(temp,"\n");
        temp = strcat(temp,"émail : ");
        temp = strcat(temp,head->info_adh->email_adh);
        temp = strcat(temp,"\n");
        temp = strcat(temp,"Address : ");
        temp = strcat(temp,head->info_adh->adress_adh);
        temp = strcat(temp,"\n");
        sprintf(temp1,"nombre d'emprunts : %d\n",head->info_adh->nbre_emprunts_adh);
        temp = strcat(temp,temp1);
        temp = strcat(temp,"___________________________________________________________________________________________\n\n");
        lables[i] = gtk_label_new(temp);
        gtk_grid_attach(GTK_GRID(adhs),lables[i],1,i,1,1);
    }
    free(temp);
    free(temp1);
}