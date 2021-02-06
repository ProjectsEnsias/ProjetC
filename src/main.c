#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "../includes/functions.h"
#include "../includes/mainWidget.h"

//declaration des fenetres:


GtkBuilder *builder;
GtkWidget *mainWindow;
GtkWidget *mainGrid;
GtkWidget *header;
GtkWidget *panel;
GtkWidget *addA;
GtkWidget *addL;
GtkWidget *sideNav;
GtkWidget *listPort;
GtkWidget *typeL;
GtkWidget *radPort;
GtkWidget *catL;
GtkWidget *catPort;
GtkWidget *radGrid;
GtkWidget *ra;
GtkWidget *rl;
GtkWidget *all;
GtkWidget *spec;
GtkWidget *cats;
GtkWidget *catGrid;
GtkWidget *list;
GtkWidget *listGrid;
GtkWidget *sgrid;
GtkWidget *adhs;
GtkWidget *searchB;
GtkWidget *searchEnt;

// variables et tables utilisés.

GtkWidget *lables[1000];
int numAdh = 1;
int numLiv = 1;
int adhOuLiv = 0; // 1 si on veut afficher les adherents et 0 sinon.
list_adherent adhh;
list_livre livh;

//declaration des signaux :
void destr();
void on_adh_taggeled(GtkRadioButton *);
void on_liv_taggeled(GtkRadioButton *);
void afficher_liv(int,list_livre,GtkWidget *lables[1000]);
void afficher_adh(int,list_adherent,GtkWidget *lables[1000]);


int main(int argc,char **argv){
    //charger(&numAdh,&adhh,&numLiv,&livh);
    livh = Malloc(livre);
    livh->info_liv = Malloc(liv_info);
    sprintf(livh->info_liv->titre_livre,"jkbkjbkjbkjb");
    livh->info_liv->num_liv = 5;
    gtk_init(&argc,&argv);
    adhh = Malloc(adherent);
    adhh->info_adh = Malloc(adh_info);
    sprintf(adhh->info_adh->email_adh,"farfora@haha.com");
    sprintf(adhh->info_adh->nom_adh,"hammmiiid");
    sprintf(adhh->info_adh->prenom_adh,"dhdhdh");
    adhh->info_adh->nbre_emprunts_adh = 5;

    builder = gtk_builder_new_from_file ("./src/glade/GUIMain.glade");
    mainWindow = GTK_WIDGET(gtk_builder_get_object(builder,"mainWindow"));
    mainGrid = GTK_WIDGET(gtk_builder_get_object(builder,"mainGrid"));
    header = GTK_WIDGET(gtk_builder_get_object(builder,"header"));
    panel = GTK_WIDGET(gtk_builder_get_object(builder,"panel"));
    all = GTK_WIDGET(gtk_builder_get_object(builder,"all"));
    spec = GTK_WIDGET(gtk_builder_get_object(builder,"spec"));
    addA = GTK_WIDGET(gtk_builder_get_object(builder,"addA"));
    addL = GTK_WIDGET(gtk_builder_get_object(builder,"addL"));
    sideNav = GTK_WIDGET(gtk_builder_get_object(builder,"sideNav"));
    listPort = GTK_WIDGET(gtk_builder_get_object(builder,"listPort"));
    listGrid = GTK_WIDGET(gtk_builder_get_object(builder,"listGrid"));
    sgrid = GTK_WIDGET(gtk_builder_get_object(builder,"sgrid"));
    adhs = GTK_WIDGET(gtk_builder_get_object(builder,"adhs"));
    radPort = GTK_WIDGET(gtk_builder_get_object(builder,"radPort"));
    searchB = GTK_WIDGET(gtk_builder_get_object(builder,"searchB"));
    catL = GTK_WIDGET(gtk_builder_get_object(builder,"catL"));
    catPort = GTK_WIDGET(gtk_builder_get_object(builder,"catPort"));
    radGrid = GTK_WIDGET(gtk_builder_get_object(builder,"radGrid"));
    list = GTK_WIDGET(gtk_builder_get_object(builder,"list"));
    typeL = GTK_WIDGET(gtk_builder_get_object(builder,"typeL"));
    searchEnt = GTK_WIDGET(gtk_builder_get_object(builder,"searchEnt"));
    ra = GTK_WIDGET(gtk_builder_get_object(builder,"ra"));
    rl = GTK_WIDGET(gtk_builder_get_object(builder,"rl"));

    //affichage :
    int i;
    for(i=0;i<1000;i++){
        lables[i] = gtk_label_new("");
        gtk_grid_attach(GTK_GRID(adhs),lables[i],1,i,1,1);
    }
    if(adhOuLiv==0){
        afficher_liv(numLiv,livh,lables);
    }
    else{
        afficher_adh(numAdh,adhh,lables);
    }
    
    

    // signals :
    // radio buttons : 
    dd da,dl;
    da.aol = adhOuLiv;
    da.num = numAdh;
    da.la = adhh;
    da.lab = lables;
    dl.aol = adhOuLiv;
    dl.num = numLiv;
    dl.ll = livh;
    dl.lab = lables;
    g_signal_connect(searchB,"clicked",G_CALLBACK(ll),NULL);
    g_signal_connect(mainWindow,"destroy",G_CALLBACK(destr),NULL);
    g_signal_connect(rl,"toggled",G_CALLBACK(on_liv_taggeled),&da);
    g_signal_connect(ra,"toggled",G_CALLBACK(on_adh_taggeled),&dl);
    gtk_builder_connect_signals(builder,NULL);

    gtk_widget_show_all(mainWindow);
    

    gtk_main();
    free(livh->info_liv);
    free(livh);
    free(adhh->info_adh);
    free(adhh);
    return 0;
}

// code des signaux:
void destr(){
    exit(0);
}

void on_adh_taggeled(GtkRadioButton *b,dd *da){
    gboolean t = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if(t){
        da->aol = 1;
        afficher_adh(da->num,da->la,da->lab);
    }
    return;
}
void on_liv_taggeled(GtkRadioButton *b,dd *dl){
    gboolean t = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if(t){
        dl->aol = 0;
        afficher_liv(dl->num,dl->ll,dl->lab);
        }
    return;
}
void afficher_liv(int numLiv,list_livre head,GtkWidget *lables[1000]){
    int i;
    list_livre p = head;
    char *temp = (char*)malloc(1000*sizeof(char));
    char *temp1 = (char*)malloc(50*sizeof(char));
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
        gtk_label_set_text(GTK_LABEL(lables[i]),temp);
        p = p->next;
    }
    free(temp);
    free(temp1);
}
void afficher_adh(int numAdh,list_adherent head,GtkWidget *lables[1000]){
    int i;
    list_adherent p = head;
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
        gtk_label_set_text(GTK_LABEL(lables[i]),temp);
        p = p->next;
    }
    free(temp);
    free(temp1);
}
