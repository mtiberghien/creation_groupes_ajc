#include <iostream>
#include <fstream>

using namespace std;
#define NB_APSIDES 2
#define NB_THALES 5

string getRandomName(string collection[], int choix[], int max, int g)
{
    // Un tirage aléatoire de valeurs allant de 0 à (mag-g) g étant le nombre de groupes créés
    int tirage = rand() % (max - g);
    // L'index de la personne est tiré dans le tableau des choix
    int chx = choix[tirage];
    // Le nomx de la personne est tiré dans le tableau des noms
    string result = collection[chx];
    // Le dernier index des choix est mis à la place du choix tiré (pour que chaque personne ne soit tirée qu'une fois)
    choix[tirage] = choix[max - g - 1];
    // L'index du choix tiré est mis à la fin du tableau (il ne sera plus tiré)
    choix[max - g - 1] = chx;
    // On retourne le résultat
    return result;
}

string getFirstName(string collection[], int choix[], int max, int g)
{
    // Le tirage est la première valeur disponible
    int tirage = 0;
    // L'index de la personne est tiré dans le tableau des choix
    int chx = choix[tirage];
    // Le nomx de la personne est tiré dans le tableau des noms
    string result = collection[chx];
    // Le premier index devient le prochain index du tableau
    if(g<(max-1))
    {
        choix[0]=choix[g+1];
    }
    return result;
}

void reset(int choix[], int max, int first)
{
    choix[0]=first;
    for(int i=1;i<max;i++)
    {
        if(i<=first)
        {
            choix[i]= i-1;
        }
        else
        {
            choix[i]=i;
        }

    }
}

void genere_random_groupe_apsides()
{
    // Création des noms et des indexs de choix
    string avances[] = {"Warda", "Sephora"};
    string intermediaires[] = {"Karim", ""};
    string debutants[] = {"Yacine", "Cheikh"};
    // Création des tableaux de choix: ces tableaux contiennent les index des personnes à sélectionner dans chaque groupe
    int choixAvance[] = {0, 1};
    int choixInter[] = {0, 1};
    int choixDebutants[] = {0, 1};

    // Création du fichier en écriture
    ofstream file("Groupes_Apsides.csv");
    // On fait NB_APSIDES nombre de tirages (ça pourrait être un autre nombre mais ça colle pour les votes)
    for (int i = 0; i < NB_APSIDES; i++)
    {
        // Ligne de tire
        file << "Tirage n° " << i + 1 << endl;
        // On fait NB_APSIDES nombre de groupes
        for (int g = 0; g < NB_APSIDES; g++)
        {
            file << "Groupe " << g + 1 << ": ";

            file << getRandomName(avances, choixAvance, NB_APSIDES, g) << ", ";
            file << getRandomName(intermediaires, choixInter, NB_APSIDES, g) << ", ";
            file << getRandomName(debutants, choixDebutants, NB_APSIDES, g) << endl;
        }

        file << endl;
    }
    file.close();
}

void genere_all_groupe_apsides()
{
    // Création des noms et des indexs de choix
    string avances[] = {"Warda", "Sephora"};
    string intermediaires[] = {"Karim", ""};
    string debutants[] = {"Yacine", "Cheikh"};
    // Création des tableaux de choix: ces tableaux contiennent les index des personnes à sélectionner dans chaque groupe
    int choixAvance[] = {0, 1};
    int choixInter[] = {0, 1};
    int choixDebutants[] = {0, 1};

    // Création du fichier en écriture
    ofstream file("Groupes_Apsides_All.csv");
     // On fait NB_APSIDES nombre de tirages (ça pourrait être un autre nombre mais ça colle pour les votes)
    for (int i=0;i<NB_APSIDES*NB_APSIDES*NB_APSIDES;i++)
    {
        reset(choixAvance, NB_APSIDES, i/(NB_APSIDES*NB_APSIDES));
        reset(choixInter, NB_APSIDES, (i/NB_APSIDES)%NB_APSIDES);
        reset(choixDebutants, NB_APSIDES, i%NB_APSIDES);
        // Ligne de tire
        file << "Tirage n° " << i + 1 << endl;
        // On fait NB_APSIDES nombre de groupes
        for (int g = 0; g < NB_APSIDES; g++)
        {
            file << "Groupe " << g + 1 << ": ";

            file << getFirstName(avances, choixAvance, NB_APSIDES, g) << ", ";
            file << getFirstName(intermediaires, choixInter, NB_APSIDES, g) << ", ";
            file << getFirstName(debutants, choixDebutants, NB_APSIDES, g) << endl;
        }

        file << endl;
    }
}

void genere_random_groupe_thales()
{
    string avances[] = {"Mathias", "Antoine", "Lucas", "Nicolas", "Kyllien"};
    string intermediaires[] = {"Leo", "Georges", "Ivan", "Clement", ""};
    string debutants[] = {"Pierrick", "Oussama", "Cedric", "Houssein", "Arthur"};
    int choixAvance[] = {0, 1, 2, 3, 4};
    int choixInter[] = {0, 1, 2, 3, 4};
    int choixDebutants[] = {0, 1, 2, 3, 4};

    ofstream file("Groupes_Thales.csv");
    for (int i = 0; i < NB_THALES; i++)
    {
        file << "Tirage n° " << i + 1 << endl;
        for (int g = 0; g < NB_THALES; g++)
        {
            file << "Groupe " << g + 1 << ": ";

            file << getRandomName(avances, choixAvance, NB_THALES, g) << ", ";
            file << getRandomName(intermediaires, choixInter, NB_THALES, g) << ", ";
            file << getRandomName(debutants, choixDebutants, NB_THALES, g) << endl;
        }

        file << endl;
    }
    file.close();
}

void genere_all_groupe_thales()
{
     string avances[] = {"Mathias", "Antoine", "Lucas", "Nicolas", "Kyllien"};
    string intermediaires[] = {"Leo", "Georges", "Ivan", "Clement", ""};
    string debutants[] = {"Pierrick", "Oussama", "Cedric", "Houssein", "Arthur"};
    int choixAvance[] = {0, 1, 2, 3, 4};
    int choixInter[] = {0, 1, 2, 3, 4};
    int choixDebutants[] = {0, 1, 2, 3, 4};

    // Création du fichier en écriture
    ofstream file("Groupes_Thales_All.csv");
     // On fait NB_APSIDES nombre de tirages (ça pourrait être un autre nombre mais ça colle pour les votes)
    for (int i=0;i<NB_THALES*NB_THALES*NB_THALES;i++)
    {
        reset(choixAvance, NB_THALES, i/(NB_THALES*NB_THALES));
        reset(choixInter, NB_THALES, (i/NB_THALES)%NB_THALES);
        reset(choixDebutants, NB_THALES, i%NB_THALES);
        // Ligne de tire
        file << "Tirage n° " << i + 1 << endl;
        // On fait NB_APSIDES nombre de groupes
        for (int g = 0; g < NB_THALES; g++)
        {
            file << "Groupe " << g + 1 << ": ";

            file << getFirstName(avances, choixAvance, NB_THALES, g) << ", ";
            file << getFirstName(intermediaires, choixInter, NB_THALES, g) << ", ";
            file << getFirstName(debutants, choixDebutants, NB_THALES, g) << endl;
        }

        file << endl ;
    }
}

int main(int argc, char *argv[])
{  
    //Initialisation d'un générateur de hasard avec l'année en cours
    srand(2023);

    //Génération aléatoire des groupes pour Apsides
    genere_random_groupe_apsides();
    genere_all_groupe_apsides();

    //Génération aléatoire des groupes pour Thales
    genere_random_groupe_thales();
    genere_all_groupe_thales();
}