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


// les variables et lists utilisés :

list_adherent adhh;
list_livre livh;


int numAdh;
int numLiv;
int adhOuLiv = 1; // 1 si on veut afficher les adherents et 0 sinon.

void ll(GtkButton *b){
    printf("%d \n",adhOuLiv);
}

int main(int argc,char **argv){
    
    //charger(&numAdh,&adhh,&numLiv,&livh);

    gtk_init(&argc,&argv);

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
    int lign = 0;
    int colon = 2;
    /*for (int i = 0; i < numButtons; i++)
    {
        if(colon == 2){
            colon = 0;
            lign++;
            gtk_grid_insert_row(GTK_GRID(adhs),2*lign);
        }
        colon++;
        buttons[i] = gtk_button_new_with_label(i);
        gtk_widget_set_hexpand (buttons[i], TRUE);
        gtk_widget_set_vexpand (buttons[i], TRUE);
        gtk_widget_set_valign (buttons[i], GTK_ALIGN_CENTER);
        gtk_widget_set_halign (buttons[i], GTK_ALIGN_CENTER);
        gtk_grid_attach(GTK_GRID(adhs),buttons[i],i%3,i/3,1,1);
    }*/
    

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
