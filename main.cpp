#include <iostream>
#include <string>
#include <vector>
#include <format>
#include "ingredient.h"
#include "PizzaSpecial.h"
#include "PizzaPersonalisee.h"
using namespace std;


void AfficherEnTete(const string& message);
void MenuPrincipal(vector <Pizza*> commande, int& compteurPerso, int& compteurSpecial, double& sousTotal);
int LireSaisi(const string& message);
void AjoutPizzaPersonnalise(vector <Pizza*>& commande, int& compteurPerso);
void AfficherMenu();
void AjouterPizzaSpeciale(vector <Pizza*>& commande, int& compteurSpecial);
void AfficherCommande(vector<Pizza*>& commande, double& sousTotal);
void PayerFacture(double& sousTotal, vector<Pizza*>& commande);
void AffichagePrix(const string& message, double prix);

void AffichagePrix(const string& message, double prix) {
    cout << message << format("{:.2f}", prix) << " $" << endl;
}

// Définition des constantes pour les choix du menu
enum choix {
    AjoutPzPs = 1, AjoutPzSpeciaciale = 2, Afficher = 3, Payer = 0
};

int LireSaisi(const string& message) {

    while (true) {
        string saisie = " ";
        std::cout << message;
        std::getline(std::cin, saisie);

        if (saisie == "0" || saisie == "1" ||
            saisie == "2" || saisie == "3") {

            return saisie[0] - '0';
        }
        std::cout << "Entree invalide. Veuillez entrer un choix valide du menu.\n";
    }
}




void AfficherMenu() {

    cout << "--- MENU DE COMMANDE ----" << endl;
    cout << AjoutPzPs << ". Ajouter une Pizza Personnalisee" << endl;
    cout << AjoutPzSpeciaciale << ". Ajouter une Pizza Speciale " << endl;
    cout << Afficher << ". Afficher commande " << endl;
    cout << Payer << ". Payer" << endl;
}

void AfficherEnTete(const string& message) {
    cout << "*******************************************" << endl;
    cout << "  " << message << endl;
    cout << "*******************************************" << endl;

}

void MenuPrincipal(vector <Pizza*> commande, int& compteurPerso, int& compteurSpecial, double& sousTotal) {
    AfficherEnTete("BIENVENUE CHEZ PIZZA C++");
    while (true) {
        cout << "\n";
        AfficherMenu();
        int leChoix = LireSaisi("Votre choix: ");

        // Si panier vide, bloquer certaines options

        switch (leChoix) {
        case AjoutPzPs:
            AjoutPizzaPersonnalise(commande, compteurPerso);
            break;
        case AjoutPzSpeciaciale: AjouterPizzaSpeciale(commande, compteurSpecial);
            break;
        case Afficher: AfficherCommande(commande, sousTotal);
            break;
        case Payer:
            cout << "-> Passage a la caisse en cours...\n" << endl;
            PayerFacture(sousTotal, commande);
            return;
        }
    }

}

// Instanciation dynamique des pizzas pour permettre le polymorphisme dans le vecteur
void AjoutPizzaPersonnalise(vector <Pizza*>& commande, int& compteurPerso) {

    Pizza* p = new PizzaPersonalisee("Pizza Perso #" + std::to_string(compteurPerso), 12.00);

    p->ajouterIngredient(new Ingredient("Double Fromage", 2.50));
    p->ajouterIngredient(new Ingredient("Pepperoni", 3.00));
    p->ajouterIngredient(new Ingredient("Champignons", 1.50));

    commande.push_back(p);
    compteurPerso++;

    cout << "-> Pizza Personnalise ajoutee a la commande !" << endl;

}

void AjouterPizzaSpeciale(vector<Pizza*>& commande, int& compteurSpecial) {
    Pizza* p = new PizzaSpecial("Pizza Special #" + to_string(compteurSpecial), 15.00);

    p->ajouterIngredient(new Ingredient("Poulet Epice", 4.00));
    p->ajouterIngredient(new Ingredient("Oignons", 1.00));
    p->ajouterIngredient(new Ingredient("Sauce BBQ", 0.75));

    commande.push_back(p);
    compteurSpecial++;
    cout << "-> Pizza Special ajoutee a la commande !" << endl;

}

// Parcours du vecteur et appel des méthodes virtuelles pour le calcul et l'affichage
void AfficherCommande(vector<Pizza*>& commande, double& sousTotal) {
    cout << "\n";
    AfficherEnTete(" COMMANDE EN COURS ");
    if (commande.empty()) {
        cout << "Votre commande est actuellement vide." << endl;
        return;
    };


    for (const Pizza* p : commande) {
        p->afficherFacture();
        double prix = p->calculerPrix();
        AffichagePrix("Prix de cette pizza : ", prix);
        sousTotal += prix;
    }



    cout << "-------------------------------------------" << endl;
    AffichagePrix("SOUS-TOTAL ACTUEL : ", sousTotal);
    cout << "-------------------------------------------" << endl;

}


void PayerFacture(double& sousTotal, vector<Pizza*>& commande) {
    if (!commande.empty()) {
        AfficherEnTete("FACTURE FINALE");
        for (const Pizza* p : commande) {
            p->afficherFacture();
            double prix = p->calculerPrix();
            AffichagePrix("Prix : ", prix);
        }

        // Calcul des taxes et du montant final
        double tps = sousTotal * 0.05;
        double tvq = sousTotal * 0.09975;
        double total = sousTotal + tps + tvq;

        cout << "\n===========================================" << endl;
        cout << "SOUS_TOTAL   : " << format("{:.2f}", sousTotal) << " $" << endl;
        cout << "TPS          : " << format("{:.2f}", tps) << " $\n";
        cout << "TVQ          : " << format("{:.2f}", tvq) << " $\n";
        cout << "-------------------------------------------" << endl;
        cout << "TOTAL A PAYER: " << format("{:.2f}", total) << " $\n";
        cout << "==================================================" << endl;

        // Libération de la mémoire allouée dynamiquement pour éviter les fuites
        cout << "\n--- Nettoyage memoire en cours ---" << endl;
        for (Pizza* p : commande) {
            delete p;
        }
        cout << "programme termine avec succes." << endl;

    }
    else {
        cout << "->Magasiner chez-nous pour avoir une facture" << endl;
    }
}



int main()
{
    double sousTotal = 0;
    vector <Pizza*> commande;
    int compteurPerso = 1;
    int compteurSpecial = 1;

    MenuPrincipal(commande, compteurPerso, compteurSpecial, sousTotal);
    return 0;
}
