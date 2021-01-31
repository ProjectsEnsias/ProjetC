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
GtkWidget *cats;
GtkWidget *catGrid;
GtkWidget *list;
GtkWidget *listGrid;
GtkWidget *sgrid;
GtkWidget *adhs;
GtkWidget *searchB;
GtkWidget *searchEnt;

// les variables et lists utilisés :

list_adherent head;


int main(int argc,char **argv){
    
    gtk_init(&argc,&argv);

    builder = gtk_builder_new_from_file ("./src/glade/GUIMain.glade");
    mainWindow = GTK_WIDGET(gtk_builder_get_object(builder,"mainWindow"));
    mainGrid = GTK_WIDGET(gtk_builder_get_object(builder,"mainGrid"));
    header = GTK_WIDGET(gtk_builder_get_object(builder,"header"));
    panel = GTK_WIDGET(gtk_builder_get_object(builder,"panel"));
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
    searchEnt = GTK_WIDGET(gtk_builder_get_object(builder,"searchEnt"))


    g_signal_connect(mainWindow,"destroy",G_CALLBACK(destr),NULL);
    gtk_builder_connect_signals(builder,NULL);
    gtk_widget_show_all(mainWindow);

    gtk_main();
    return 0;
}
