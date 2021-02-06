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

GtkWidget *lables[1000];


// les variables et lists utilisés :

list_adherent adhh;
list_livre livh;


int numAdh = 1;
int numLiv = 1;
int adhOuLiv = 1; // 1 si on veut afficher les adherents et 0 sinon.

void ll(GtkButton *b){
    printf("%d \n",adhOuLiv);
}

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
    if(adhOuLiv==0){
        afficher_liv(numLiv,livh,adhs,lables);
    }
    else{
        afficher_adh(numAdh,adhh,adhs,lables);
    }
    free(livh->info_liv);
    free(livh);
    
    

    // signals :
    g_signal_connect(searchB,"clicked",G_CALLBACK(ll),NULL);
    g_signal_connect(mainWindow,"destroy",G_CALLBACK(destr),NULL);
    g_signal_connect(rl,"toggled",G_CALLBACK(on_liv_taggeled),&adhOuLiv);
    g_signal_connect(ra,"toggled",G_CALLBACK(on_adh_taggeled),&adhOuLiv);
    gtk_builder_connect_signals(builder,NULL);

    gtk_widget_show_all(mainWindow);
    

    gtk_main();
    return 0;
}
