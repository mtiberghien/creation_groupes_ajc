#include <iostream>
#include <fstream>

using namespace std;
#define NB_APSIDES 2
#define NB_THALES 5


string getRandomName(string collection[], int choix[], int max, int g)
{
    // Un tirage aléatoire de valeurs allant de 0 à (mag-g) g étant le nombre de groupes créés
    int tirage = rand()%(max - g);
    // L'index de la personne est tiré dans le tableau des choix
    int chx= choix[tirage];
    // Le nomx de la personne est tiré dans le tableau des noms
    string result = collection[chx];
    // Le dernier index des choix est mis à la place du choix tiré (pour que chaque personne ne soit tirée qu'une fois)
    choix[tirage] = choix[max-g-1];
    // L'index du choix tiré est mis à la fin du tableau (il ne sera plus tiré)
    choix[max-g-1]=chx;
    // On retourne le résultat
    return result;
}

void genere_groupe_apsides()
{
    //Création des noms et des indexs de choix
    string avances[]={"Warda", "Sephora"};
    string intermediaires[]={"Karim", ""};
    string debutants[]={"Yacine","Cheikh"};
    // Création des tableaux de choix: ces tableaux contiennent les index des personnes à sélectionner dans chaque groupe
    int choixAvance[]={0,1};
    int choixInter[]={0,1};
    int choixDebutants[]={0,1};

    //Création du fichier en écriture
    ofstream file("Groupes_Apsides.csv");
     // On fait NB_APSIDES nombre de tirages (ça pourrait être un autre nombre mais ça colle pour les votes)
    for(int i=0;i<NB_APSIDES;i++)
    {
        // Ligne de tire
        file << "Tirage n° " << i+1 << endl;
         // On fait NB_APSIDES nombre de groupes
        for(int g=0;g<NB_APSIDES;g++)
        {
            file << "Groupe " << g+1 << ": ";
            
            file << getRandomName(avances, choixAvance, NB_APSIDES, g) << ", " ;
            file << getRandomName(intermediaires, choixInter, NB_APSIDES, g) << ", ";
            file << getRandomName(debutants, choixDebutants, NB_APSIDES, g) << endl;
        }

        file << endl << endl;
    }
    file.close();
}

void genere_groupe_thales()
{
    string avances[]={"Mathias", "Antoine","Lucas","Nicolas", "Kyllien"};
    string intermediaires[]={"Leo","Georges","Ivan","Clement", ""};
    string debutants[]={"Pierrick","Oussama","Cedric","Houssein","Arthur"};
    int choixAvance[]={0,1,2,3,4};
    int choixInter[]={0,1,2,3,4};
    int choixDebutants[]={0,1,2,3,4};

    ofstream file("Groupes_Thales.csv");
    for(int i=0;i<NB_THALES;i++)
    {
        file << "Tirage n° " << i+1 << endl;
        for(int g=0;g<NB_THALES;g++)
        {
            file << "Groupe " << g+1 << ": ";
            
            file << getRandomName(avances, choixAvance, NB_THALES, g) << ", " ;
            file << getRandomName(intermediaires, choixInter, NB_THALES, g) << ", ";
            file << getRandomName(debutants, choixDebutants, NB_THALES, g) << endl;
        }

        file << endl << endl;
    }
    file.close();
}

int main(int argc, char* argv[])
{
    //Initialisation d'un générateur de hasard avec l'année en cours
    srand(2023);

    //Génération aléatoire des groupes pour Apsides
    genere_groupe_apsides();

    //Génération aléatoire des groupes pour Thales
    genere_groupe_thales();
}