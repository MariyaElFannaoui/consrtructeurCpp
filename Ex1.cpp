 
#include <iostream>
#include <string>
using namespace std;

class Souris {
private:
    double poids;
    string couleur;
    unsigned int age;
    unsigned int esperance_vie;
    bool clonee;

public: 
    Souris(double p, string c, unsigned int a = 0, unsigned int e = 36)
        : poids(p), couleur(c), age(a), esperance_vie(e), clonee(false)
    {
        cout << "Une nouvelle souris !" << endl;
    }

    
    Souris(const Souris& autre)
        : poids(autre.poids), couleur(autre.couleur), age(autre.age),
          esperance_vie(autre.esperance_vie * 4 / 5), clonee(true)
    {
        cout << "Clonage d’une souris !" << endl;
    }

  
    ~Souris() {
        cout << "Fin d’une souris..." << endl;
    }

    
    void afficher() const {
        cout << "Une souris " << couleur;
        if (clonee) cout << ", clonee,";
        cout << " de " << age << " mois et pesant " << poids << " grammes" << endl;
    }

   
    void vieillir() {
        age++;
        if (clonee && age > esperance_vie / 2 && couleur != "verte") {
            couleur = "verte";
        }
    }

    
    void evolue() {
        while (age < esperance_vie) {
            vieillir();
        }
    }
};
 
