#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Mitarbeiter {
    int personalnummer;
    string vorname;
    string nachname;
    string geburtsdatum;
    float gehalt;
};

void datenLaden(vector<Mitarbeiter>& daten) {
    ifstream file("textfile.txt");
    if (!file) return;

    Mitarbeiter m;
    while (file >> m.personalnummer >> m.vorname >> m.nachname >> m.geburtsdatum >> m.gehalt) {
        daten.push_back(m);
    }
    file.close();
}

void datenSpeichern(const vector<Mitarbeiter>& daten) {
    ofstream file("textfile.txt");
    for (const auto& m : daten) {
        file << m.personalnummer << " " << m.vorname << " " << m.nachname << " "
            << m.geburtsdatum << " " << m.gehalt << "\n";
    }
    file.close();
}

int main() {
    vector<Mitarbeiter> daten;
    datenLaden(daten);

    int wahl;
    do {
        cout << "\n--- Mitarbeiterprogramm ---\n";
        cout << "1. Datensatz hinzufuegen\n";
        cout << "2. Alle Datensaetze anzeigen\n";
        cout << "0. Beenden\n> ";
        cin >> wahl;

        if (wahl == 1) {
            Mitarbeiter m;
            cout << "Personalnummer: "; cin >> m.personalnummer;
            cout << "Vorname: "; cin >> m.vorname;
            cout << "Nachname: "; cin >> m.nachname;
            cout << "Geburtsdatum (TT.MM.JJJJ): "; cin >> m.geburtsdatum;
            cout << "Gehalt: "; cin >> m.gehalt;
            daten.push_back(m);
            datenSpeichern(daten);
        }
        else if (wahl == 2) {
            for (const auto& m : daten) {
                cout << m.personalnummer << ": " << m.vorname << " " << m.nachname
                    << ", " << m.geburtsdatum << ", Gehalt: " << m.gehalt << " EUR\n";
            }
        }

    } while (wahl != 0);
    
    return 0;
}
