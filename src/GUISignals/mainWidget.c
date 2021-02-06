#include <stdio.h>
#include <stdlib.h>
#include "../../includes/mainWidget.h"


void destr(){
    exit(0);
}
void on_adh_taggeled(GtkRadioButton *b,int *adhOuLiv){
    gboolean t = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if(t){
        *adhOuLiv = 1;
    }
    printf("%d",*adhOuLiv);
    return;
}
void on_liv_taggeled(GtkRadioButton *b,int *adhOuLiv){
    gboolean t = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if(t){
        *adhOuLiv = 0;
    }
    printf("%d",*adhOuLiv);
    return;
}