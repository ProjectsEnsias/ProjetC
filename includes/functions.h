
#ifndef _FONC
#define _FONC
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define rep(i,n) int i;for(i=0;i<n;i++)
#define Malloc(type) (type*)malloc(sizeof(type))





// ********* les structures:

typedef struct _AUTEUR{
    char nom_aut[20];
    char prenom_aut[20];
}auteur;

typedef struct _ADHERENT_INFO{
    int num_adh;
    char nom_adh[20];
    char prenom_adh[20];
    char email_adh[60];
    char adress_adh[100];
    int nbre_emprunts_adh;
}adh_info;

typedef struct adherant{
    adh_info *info_adh;
    struct adherant *next;
}adherent;
typedef struct _LIVRE_INFO{
    int num_liv;
    char titre_livre[20];
    char categ_liv[30]; // codes des catégories ; par exemple : 00 pour la litairature ...
    auteur auteur_liv;
    int emprunteur_liv;
}liv_info;

typedef struct _LIVRE{
    liv_info *info_liv;
    struct _LIVRE * next;
}livre;


typedef adherent* list_adherent; // c'est juste pour différencier les adherents des listes d'adherents
typedef livre* list_livre;

// ********* les fonctions :
// ** Gestion des adhérents :
adherent * modifier_adherent(adherent*,adh_info*);
list_adherent recherche_adherent(list_adherent,char[],int*);
list_adherent ajouter_adherent(list_adherent,adh_info*);
list_adherent recherche_emprenteurs(list_adherent,int*);
int test_vide(adherent*);
adherent* supprimes_adherent(adherent*,int);

// ** Gestion des Livres :
livre * modifier_livre(livre*,liv_info*);
list_livre recherche_livre(list_livre,char[],char[] , int*);
list_livre recherche_livres_emptuntes(list_livre,int*);
int test_videl(livre* );
livre* ajouter_livre(livre*,liv_info*);
livre* supprimes_livre(livre* ,int);

// ** Gestion des emprunts :
void enprunter_livre(adherent* ,livre* ,int ,int );
void Rendre_liv(livre*,adherent*);


// ** les fichiers de stockage.
void charger(int*,list_adherent*,int*,list_livre*);
void sauvegarder(int,list_adherent,int,list_livre);

#endif
