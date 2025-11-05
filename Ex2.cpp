 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

 
class Auteur {
private:
    string nom;
    bool prime;
public:
    Auteur(string n, bool p = false) : nom(n), prime(p) {}
    string getNom() const { return nom; }
    bool getPrix() const { return prime; }

    // Interdire la copie
    Auteur(const Auteur&) = delete;
    Auteur& operator=(const Auteur&) = delete;
};

 
class Oeuvre {
private:
    string titre;
    const Auteur& auteur;
    string langue;
public:
    Oeuvre(string t, const Auteur& a, string l)
        : titre(t), auteur(a), langue(l) {}

    string getTitre() const { return titre; }
    const Auteur& getAuteur() const { return auteur; }
    string getLangue() const { return langue; }

    void affiche() const {
        cout << titre << ", " << auteur.getNom() << ", en " << langue << endl;
    }

    ~Oeuvre() {
        cout << "L’oeuvre \"" << titre << ", " << auteur.getNom()
             << ", en " << langue << "\" n’est plus disponible." << endl;
    }

     
    Oeuvre(const Oeuvre&) = delete;
    Oeuvre& operator=(const Oeuvre&) = delete;
};

 
class Exemplaire {
private:
    const Oeuvre& oeuvre;
public:
    Exemplaire(const Oeuvre& o) : oeuvre(o) {
        cout << "Nouvel exemplaire de : ";
        oeuvre.affiche();
    }

    Exemplaire(const Exemplaire& e) : oeuvre(e.oeuvre) {
        cout << "Copie d’un exemplaire de : " << oeuvre.getTitre()
             << ", " << oeuvre.getAuteur().getNom()
             << ", en " << oeuvre.getLangue() << endl;
    }

    ~Exemplaire() {
        cout << "Un exemplaire de \"" << oeuvre.getTitre() << ", "
             << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue()
             << "\" a été jeté !" << endl;
    }

    const Oeuvre& getOeuvre() const { return oeuvre; }

    void affiche() const {
        cout << "Exemplaire de : " << oeuvre.getTitre() << ", "
             << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue();
    }
};

 
class Bibliotheque {
private:
    string nom;
    vector<Exemplaire*> exemplaires;
public:
    Bibliotheque(string n) : nom(n) {
        cout << "La bibliothèque " << nom << " est ouverte !" << endl;
    }

    string getNom() const { return nom; }

    void stocker(const Oeuvre& o, int n = 1) {
        for (int i = 0; i < n; ++i) {
            exemplaires.push_back(new Exemplaire(o));
        }
    }

    void lister_exemplaires(string langue = "") const {
        for (auto e : exemplaires) {
            if (langue == "" || e->getOeuvre().getLangue() == langue) {
                e->affiche();
                cout << endl;
            }
        }
    }

    int compter_exemplaires(const Oeuvre& o) const {
        int c = 0;
        for (auto e : exemplaires) {
            if (&(e->getOeuvre()) == &o) c++;
        }
        return c;
    }

    void afficher_auteurs(bool avecPrix = false) const {
        for (auto e : exemplaires) {
            const Auteur& a = e->getOeuvre().getAuteur();
            if (!avecPrix || a.getPrix()) {
                cout << a.getNom() << endl;
            }
        }
    }

    ~Bibliotheque() {
        cout << "La bibliothèque " << nom << " ferme ses portes," << endl;
        cout << "et détruit ses exemplaires :" << endl;
        for (auto e : exemplaires) {
            delete e;
        }
    }
};
 
