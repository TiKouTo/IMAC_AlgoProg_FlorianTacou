#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
    // your code
};

struct DynaTableau{
    int* donnees;
    int taillemax;
    int taillereelle;
    // your code
};

//pas demandées
void initialise(Liste* liste)
{
    Noeud* premier=nullptr;
    //liste vide 0 = nullptr
}

bool est_vide(const Liste* liste)
{
    return false;
}
void affiche(const Liste* liste)
{

}
//demandées


void ajoute(Liste* liste, int valeur)
{
    Noeud* nouveaunoeud= new Noeud;
    
    Noeud*versledernier=liste->premier->suivant;
    while (versledernier->suivant!=nullptr)
    {
        versledernier=versledernier->suivant;
    }
    versledernier->suivant=nouveaunoeud;
    nouveaunoeud->suivant=nullptr;
    nouveaunoeud->donnee=valeur;
}



Noeud* recupere(const Liste* liste, int n)
{
    int compteur=0;
    Noeud* verslenieme=liste->premier;
    while(compteur<n)
    {
        verslenieme=verslenieme->suivant;
    }
    return verslenieme;
}

int cherche(const Liste* liste, int valeur)
{
    Noeud*versceluiqueloncherche=liste->premier;
    int compteur=0;
    while(versceluiqueloncherche!=nullptr)
    {
        
        if(versceluiqueloncherche->donnee==valeur)return compteur;
        versceluiqueloncherche=versceluiqueloncherche->suivant;
        compteur++;
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    recupere(liste,n)->donnee=valeur;
}



//pas demandées
void initialise(DynaTableau* tableau, int capacite)
{

}

bool est_vide(const DynaTableau* liste)
{
    return false;
}

void affiche(const DynaTableau* tableau)
{

}
//demandées
void ajoutetab(DynaTableau* tableau, int valeur)
{
    if(tableau->taillereelle==tableau->taillemax)tableau->taillemax+=100;
    tableau->donnees[tableau->taillereelle]=valeur;
    tableau->taillereelle+=1;
}
int recuperetab(const DynaTableau* tableau, int n)
{
    return tableau->donnees[n];
}

int cherchetab(const DynaTableau* tableau, int valeur)
{
    for (int i=0;i<tableau->taillereelle;i++)
    {
        if (tableau->donnees[i])return i;
    }
    return -1;
}

void stocketab(DynaTableau* tableau, int n, int valeur)
{
    tableau->donnees[n]=valeur;
}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{
    Noeud*nouveaunoeudn2=new Noeud;
    nouveaunoeudn2->donnee=liste->premier->donnee;
    nouveaunoeudn2->suivant=liste->premier->suivant;
    liste->premier->donnee=valeur;
    liste->premier->suivant=nouveaunoeudn2;    
}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    liste->premier;
    
    
    Noeud*dernier=liste->premier;
    Noeud*avantdernier=liste->premier;
    while(dernier->suivant!=nullptr)
    {
        avantdernier=dernier;
        dernier=dernier->suivant;
    }
    avantdernier->suivant=nullptr;
    return dernier->donnee;

}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{
    ajoute(liste,valeur);
}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
   retire_file(liste); //pour file comme pile on retire le dernier;
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoutetab(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recuperetab(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherchetab(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocketab(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
