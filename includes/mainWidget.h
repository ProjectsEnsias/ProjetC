#ifndef _MW
#define _MW
#include <gtk/gtk.h>
#include "./functions.h"

void destr();
void on_adh_taggeled(GtkRadioButton *b,int *adhOuLiv);
void on_liv_taggeled(GtkRadioButton *b,int *adhOuLiv);
void afficher_liv(int,list_livre,GtkWidget*,GtkWidget *lables[1000]);
void afficher_adh(int,list_adherent,GtkWidget*,GtkWidget *lables[1000]);

#endif // !_MW