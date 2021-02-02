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

list_adherent head;
int numButtons;

int main(int argc,char **argv){
    
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
    int lign = 0;
    int colon = 2;
    for (int i = 0; i < numButtons; i++)
    {
        if(colon == 2){
            colon = 0;
            lign++;
            gtk_grid_insert_row(GTK_GRID(adhs),2*lign);
        }
        colon++;
        buttons[i] = gtk_button_new_with_label("\t\t\tehm\t\t\t");
        gtk_widget_set_hexpand (buttons[i], TRUE);
        gtk_widget_set_vexpand (buttons[i], TRUE);
        gtk_widget_set_valign (buttons[i], GTK_ALIGN_CENTER);
        gtk_widget_set_halign (buttons[i], GTK_ALIGN_CENTER);
        gtk_grid_attach(GTK_GRID(adhs),buttons[i],i%3,i/3,1,1);
    }
    


    g_signal_connect(mainWindow,"destroy",G_CALLBACK(destr),NULL);
    gtk_builder_connect_signals(builder,NULL);
    gtk_widget_show_all(mainWindow);

    gtk_main();
    return 0;
}
