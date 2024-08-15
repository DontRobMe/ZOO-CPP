#include <string>
#include <vector>
#include <iostream>


using namespace std;


class Cage {
public:
    virtual string get_type() = 0;

    virtual int get_price_buy() = 0;

    virtual int get_price_sell() = 0;

    virtual int get_capacity() = 0;
};

class Cage_tigre : public Cage {
private:
    string type;
    int price_buy;
    int price_sell;
    int capacity;
public:
    Cage_tigre(string type, int buy, int sell, int capacity) {
        this->type = type;
        this->price_buy = buy;
        this->price_sell = sell;
        this->capacity = capacity;
    }

    virtual int get_price_buy() {
        return price_buy;
    }

    virtual int get_price_sell() {
        return price_sell;
    }

    virtual int get_capacity() {
        return capacity;
    }

    virtual string get_type() {
        return type;
    }
};

class Cage_aigle : public Cage {
private:
    string type;
    int price_buy;
    int price_sell;
    int capacity;
public:
    Cage_aigle(string type, int buy, int sell, int capacity) {
        this->type = type;
        this->price_buy = buy;
        this->price_sell = sell;
        this->capacity = capacity;
    }

    virtual int get_price_buy() {
        return price_buy;
    }

    virtual int get_price_sell() {
        return price_sell;
    }

    virtual int get_capacity() {
        return capacity;
    }

    virtual string get_type() {
        return type;
    }
};

class Cage_poule : public Cage {
private:
    string type;
    int price_buy;
    int price_sell;
    int capacity;
public:
    Cage_poule(string type, int buy, int sell, int capacity) {
        this->type = type;
        this->price_buy = buy;
        this->price_sell = sell;
        this->capacity = capacity;
    }

    virtual int get_price_buy() {
        return price_buy;
    }

    virtual int get_price_sell() {
        return price_sell;
    }

    virtual int get_capacity() {
        return capacity;
    }

    virtual string get_type() {
        return type;
    }
};

class Animal {
public:
    virtual string get_type () = 0;

    virtual string get_name () = 0;

    virtual int get_age () = 0;

    virtual string get_sexe () = 0;

    virtual int get_price_buy() = 0;

    virtual int get_price_sell() = 0;
};

class Tigre : public Animal {
private:
    string type;
    string name;
    int age;
    string sexe;
    int buy;
    int sell;
public:
    Tigre (string type, string name, int age, string sexe,int buy,int sell){
        this -> type = type;
        this -> name = name;
        this -> age = age;
        this -> sexe = sexe;
        this -> buy = buy;
        this -> sell = sell;
    };

    void set_newname(string new_name){
        name = new_name;
    }

    virtual string get_type(){
        return type;
    }

    virtual string get_name(){
        return name;
    }

    virtual int get_age(){
        return age;
    }

    virtual string get_sexe(){
        return sexe;
    }

    virtual int get_price_buy() {
        return buy;
    }

    virtual int get_price_sell() {
        return sell;
    }
};

class Aigle : public Animal {
private:
    string type;
    string name;
    int age;
    string sexe;
    int buy;
    int sell;
public:
    Aigle(string type, string name, int age, string sexe,int buy,int sell){
        this -> type = type;
        this -> name = name;
        this -> age = age;
        this -> sexe = sexe;
        this -> buy = buy;
        this -> sell = sell;
    };

    void set_newname(string new_name){
        name = new_name;
    }

    virtual string get_type(){
        return type;
    }

    virtual string get_name(){
        return name;
    }

    virtual int get_age(){
        return age;
    }

    virtual string get_sexe(){
        return sexe;
    }

    virtual int get_price_buy() {
        return buy;
    }

    virtual int get_price_sell() {
        return sell;
    }
};

class Poule : public Animal {
private:
    string type;
    string name;
    int age;
    string sexe;
    int buy;
    int sell;
public:
    Poule(string type, string name, int age, string sexe,int buy,int sell){
        this -> type = type;
        this -> name = name;
        this -> age = age;
        this -> sexe = sexe;
        this -> buy = buy;
        this -> sell = sell;
    };

    void set_newname(string new_name){
        name = new_name;
    }

    virtual string get_type(){
        return type;
    }

    virtual string get_name(){
        return name;
    }

    virtual int get_age(){
        return age;
    }

    virtual string get_sexe(){
        return sexe;
    }

    virtual int get_price_buy() {
        return buy;
    }

    virtual int get_price_sell() {
        return sell;
    }
};

class Zoo {
private:
    static Zoo *_instance;
    string name;
    int money;
    int graines;
    int viandes;
public:
    vector<Cage *> magasin_cage;
    vector<Cage *> inventaire_cage;
    vector<Animal *> magasin_animal;
    vector<Animal *> inventaire_animal;

    Zoo(string nom, int money) {
        if (_instance == nullptr) {
            _instance = this;
        }
        this->name = nom;
        this->money = money;
    }

    static void print_wallet(Zoo *zoo) {
        cout << "Votre Argent: " << zoo->money << endl;
    }

    static void convertMouthtoYear(int months){
        int years = months / 12;
        int remainingMonths = months % 12;
        cout << years << " ans et " << remainingMonths << " mois ";
    }

    static void rem_argent(Zoo *zoo, int a) {
        int argent = zoo->money;
        zoo->money = argent -= a;
    }

    static void add_argent(Zoo *zoo, int a) {
        int argent = zoo->money;
        zoo->money = argent += a;
    }

    void add_magasin_cage(Cage *cage) {
        magasin_cage.push_back(cage);
    }

    void add_inventaire_cage(Cage *cage) {
        inventaire_cage.push_back(cage);
    }

    void achat_cages(Zoo *zoo) {
        int indice;
        for (int i = 0; i<magasin_cage.size(); i++ ){
            cout << i+1 <<") cage de " << magasin_cage[i]->get_type() << " "<< magasin_cage[i]->get_price_buy()<< " capacite:"<< magasin_cage[i]->get_capacity()<<" animaux"<< endl;
        }
        cout << magasin_cage.size()+1 <<") retour"<<endl;
        indice = entree(4);
        if (indice == 1) {
            rem_argent(zoo, magasin_cage[0]->get_price_buy());
            add_inventaire_cage((magasin_cage[0]));
        } else if (indice == 2) {
            rem_argent(zoo, magasin_cage[1]->get_price_buy());
            add_inventaire_cage((magasin_cage[1]));
        } else if (indice == 3) {
            rem_argent(zoo, magasin_cage[2]->get_price_buy());
            add_inventaire_cage((magasin_cage[2]));
        } else if (indice == 4) {
            menu_cages(zoo);
        }

    }

    void vente_cages(Zoo *zoo) {
        int indice;
        int indexremcage;
        cout << "1) vente cages \n2) retour" << endl;
        indice = entree(2);
        if (indice == 1) {
            cout << "Liste des cages: " << endl;

            // Affichage des cages disponibles avec leur prix de vente
            for (int i = 0; i < inventaire_cage.size(); i++) {
                cout << i + 1 << ") cage " << inventaire_cage[i]->get_type()
                     << " (Prix: " << inventaire_cage[i]->get_price_sell() << "e)" << endl;
            }
            cout << inventaire_cage.size() + 1 << ") retour" << endl;
            cout << "quelle cage vendre ? ";
            indexremcage = entree(inventaire_cage.size() + 1);

            if (indexremcage == inventaire_cage.size() + 1) {
                return;  // Retour direct au menu principal
            }

            indexremcage--;  // Convertir en index basé sur zéro

            int prix_vente = inventaire_cage[indexremcage]->get_price_sell();
            add_argent(zoo, prix_vente);

            // Affichage du prix de vente et de l'argent restant
            cout << "Cage vendue pour " << prix_vente << "e. Argent restant: " << zoo->getInstance()->money << "e." << endl;

            // Suppression de la cage de l'inventaire
            remCages(indexremcage);
        } else if (indice == 2) {
            return;  // Retour direct au menu principal
        }
    }




    void add_magasin_animal(Animal *animal) {
        magasin_animal.push_back(animal);
    }

    void add_inventaire_animal(Animal *animal){
        inventaire_animal.push_back(animal);
    }

    void achat_animals(Zoo *zoo) {
        int indice;
        string type;
        string prenom;

        for (int i = 0; i < magasin_animal.size(); i++) {
            if (magasin_animal[i]->get_type() == "coq" || magasin_animal[i]->get_type() == "poule") {
                cout << i + 1 << ") " << magasin_animal[i]->get_type() << " age: ";
                convertMouthtoYear(magasin_animal[i]->get_age());
                cout << "prix: " << magasin_animal[i]->get_price_buy() << "e" << endl;
            } else {
                cout << i + 1 << ") " << magasin_animal[i]->get_type() << " " << magasin_animal[i]->get_sexe() << " ,age: ";
                convertMouthtoYear(magasin_animal[i]->get_age());
                cout << " mois, prix: " << magasin_animal[i]->get_price_buy() << "e" << endl;
            }
        }

        indice = entree(6) - 0;  // Convertir le char en int
        if (indice < 1 || indice > magasin_animal.size()) {
            cout << "Indice invalide!" << endl;
            return;
        }

        rem_argent(zoo, magasin_animal[indice - 1]->get_price_buy());
        prenom = donner_prenom(magasin_animal[indice - 1]->get_type());

        if (indice == 1 || indice == 2) {
            add_inventaire_animal(new Tigre(magasin_animal[indice - 1]->get_type(), prenom, magasin_animal[indice - 1]->get_age(), magasin_animal[indice - 1]->get_sexe(), magasin_animal[indice - 1]->get_price_buy(), magasin_animal[indice - 1]->get_price_sell()));
        } else if (indice == 3 || indice == 4) {
            add_inventaire_animal(new Aigle(magasin_animal[indice - 1]->get_type(), prenom, magasin_animal[indice - 1]->get_age(), magasin_animal[indice - 1]->get_sexe(), magasin_animal[indice - 1]->get_price_buy(), magasin_animal[indice - 1]->get_price_sell()));
        } else if (indice == 5 || indice == 6) {
            add_inventaire_animal(new Poule(magasin_animal[indice - 1]->get_type(), prenom, magasin_animal[indice - 1]->get_age(), magasin_animal[indice - 1]->get_sexe(), magasin_animal[indice - 1]->get_price_buy(), magasin_animal[indice - 1]->get_price_sell()));
        }
    }


    void vente_animals(Zoo *zoo) {
        int indice;
        cout << "Liste des animaux:" << endl;

        // Affichage des animaux disponibles avec leur prix de vente
        for (int i = 0; i < inventaire_animal.size(); i++) {
            cout << i + 1 << ") " << inventaire_animal[i]->get_type()
                 << " - " << inventaire_animal[i]->get_name()
                 << " (Prix: " << inventaire_animal[i]->get_price_sell() << "e)" << endl;
        }
        cout << inventaire_animal.size() + 1 << ") retour" << endl;

        // Sélection de l'animal à vendre
        indice = entree(inventaire_animal.size() + 1);

        // Vérification de l'option de retour
        if (indice == inventaire_animal.size() + 1) {
            return;  // Retour direct au menu principal
        }

        int indexremanimal = indice - 1;

        // Vérification de la validité de l'indice
        if (indexremanimal >= 0 && indexremanimal < inventaire_animal.size()) {
            // Ajout de l'argent pour la vente
            int prix_vente = inventaire_animal[indexremanimal]->get_price_sell();
            add_argent(zoo, prix_vente);

            // Affichage du prix de vente et de l'argent restant
            cout << "Animal vendu pour " << prix_vente << "e. Argent restant: " << zoo->getInstance()->money << "e." << endl;

            // Suppression de l'animal de l'inventaire
            remAnimal(indexremanimal);
        } else {
            cout << "Erreur: Indice d'animal invalide." << endl;
        }
    }







    int achat_viandes(Zoo *zoo) {
        int poids;
        const int prix_par_kg = 5; // Prix par kg en euros
        cout << "Combien de kg de viandes voulez-vous acheter?" << endl;
        cout << "Votre solde actuel: " << zoo->money << "e" << endl;
        cout << "Prix: " << prix_par_kg << "e par kg" << endl;
        cout << "Quantité (kg): ";
        cin >> poids;

        if (poids <= 0) {
            cout << "Quantité invalide!" << endl;
            return 0;
        }

        int cout_total = poids * prix_par_kg;
        if (zoo->money < cout_total) {
            cout << "Fonds insuffisants!" << endl;
            return 0;
        }

        rem_argent(zoo, cout_total);
        viandes += poids;

        cout << "Vous avez acheté " << poids << " kg de viandes pour " << cout_total << "e." << endl;
        cout << "Quantité actuelle de viandes: " << viandes << "kg" << endl;
        return poids;
    }


    int achat_graines(Zoo *zoo) {
        int poids;
        const int prix_par_kg = 3; // Prix par kg en euros
        cout << "Combien de kg de graines voulez-vous acheter?" << endl;
        cout << "Votre solde actuel: " << zoo->money << "e" << endl;
        cout << "Prix: " << prix_par_kg << "e par kg" << endl;
        cout << "Quantité (kg): ";
        cin >> poids;

        if (poids <= 0) {
            cout << "Quantité invalide!" << endl;
            return 0;
        }

        int cout_total = poids * prix_par_kg;
        if (zoo->money < cout_total) {
            cout << "Fonds insuffisants!" << endl;
            return 0;
        }

        rem_argent(zoo, cout_total);
        graines += poids;

        cout << "Vous avez acheté " << poids << " kg de graines pour " << cout_total << "e." << endl;
        cout << "Quantité actuelle de graines: " << graines << "kg" << endl;
        return poids;
    }


    void afficher_temps(int nbmois) {
        int real_mouth;
        const string mois[12]
                = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre",
                   "Novembre", "Decembre"};
        if (nbmois <= 12) {
            real_mouth = nbmois - 1;
        } else {
            real_mouth = (nbmois % 12) - 1;
        }
        cout << "Bienvenue dans le mois de " << mois[real_mouth] << "." << endl;
    }



    void remAnimal(int entree) {
        inventaire_animal.erase(inventaire_animal.begin() + entree - 1); //penser a afficher une liste animaux avec index normal
    }

    void remCages(int entree) {
        inventaire_cage.erase(inventaire_cage.begin() + entree - 1);
    }

    string donner_prenom(string animal) {
        string name;
        string valid;
        cout << "Prenom: ";
        cin >> name;
        cout << name << animal << " cela vous convient-il ? o/n:";
        cin >> valid;
        while (valid != "o" && valid != "O") {
            cout << "Prenom: ";
            cin >> name;
            cout << name << animal << " cela vous convient-il ? o/n:";
            cin >> valid;
        }
        return name;
    }

    static int entree(int nb_reponse) {
        char entree;
        int choice;

        cout << "entree: ";
        cin >> entree;

        while (!isdigit(entree) || (choice = entree - '0') < 1 || choice > nb_reponse) {
            cout << "erreur entree non valide" << endl;
            cout << "entree: ";
            cin >> entree;
        }

        return choice;
    }


    void menu_cages(Zoo *zoo) {
        int indice;
        cout << "1) achat cages \n2) vente cages\n3) retour" << endl;
        indice = entree(3);
        if (indice == 1) {
            achat_cages(zoo);
        } else if (indice == 2) {
            vente_cages(zoo);
        } else if (indice == 3) {
            menu(zoo);
        }
    }

    void menu_animals(Zoo *zoo) {
        int indice;
        cout << "1) achat animals \n2) vente animals\n3) retour" << endl;
        indice = entree(3);
        if (indice == 1) {
            achat_animals(zoo);
        } else if (indice == 2) {
            vente_animals(zoo);
        } else if (indice == 3) {
            menu(zoo);
        }
    }

    void menu_nourritures(Zoo *zoo) {
        int indice;
        cout << "vous avez: " << viandes << "kg de viandes!" << endl;
        cout << "vous avez: " << graines << "kg de graines!" << endl;
        cout << "1) achat viandes \n2) achat graines\n3) retour" << endl;
        indice = entree(3);
        if (indice == 1) {
            achat_viandes(zoo);
        } else if (indice == 2) {
            achat_graines(zoo);
        } else if (indice == 3) {
            menu(zoo);
        }
    }


    void menu(Zoo *zoo) {

        int indice = '0';
        while (indice != '4') {
            print_wallet(zoo);
            cout << "1) achat/vente cage \n2) achat/vente animal \n3) achat nouriture \n4) tour suivant" << endl;
            indice = entree(4);
            if (indice == 1) {
                menu_cages(zoo);
            } else if (indice == 2) {
                menu_animals(zoo);
            } else if (indice == 3) {
                menu_nourritures(zoo);
            } else if (indice == 4) {
                return;
            }
        }
    }

    static Zoo *getInstance() {
        return _instance;
    }
};

Zoo *Zoo::_instance = nullptr;

int main() {
    Zoo zoo("Mon zoo", 80000);
    zoo.add_magasin_cage(new Cage_tigre("tigre", 2000, 500, 2));
    zoo.add_magasin_cage(new Cage_aigle("aigle", 2000, 500, 4));
    zoo.add_magasin_cage(new Cage_poule("poule", 300, 50, 10));
    zoo.add_magasin_animal(new Tigre("tigre", "bob", 6, "male", 3000, 1500));
    zoo.add_magasin_animal(new Tigre("tigre", "michele", 6, "female", 3000, 1500));
    zoo.add_magasin_animal(new Aigle("aigle", "bob", 6, "male", 1000, 500));
    zoo.add_magasin_animal(new Aigle("aigle", "michele", 6, "female", 1000, 500));
    zoo.add_magasin_animal(new Poule("coq", "bob", 6, "male",100,20));
    zoo.add_magasin_animal(new Poule("poule", "bob", 6, "female",20,10));
    cout << "Bienvenue dans votre nouveau Zoo, bonne chance !!" << endl;
    for (int mois = 1; mois < 120; mois++) {
        zoo.afficher_temps(mois);
        zoo.menu(&zoo);
    }
}
