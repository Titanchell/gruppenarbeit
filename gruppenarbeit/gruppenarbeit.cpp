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

// Liest bestehende Datensätze aus der Datei und speichert sie im Vektor
void datenLaden(vector<Mitarbeiter>& daten) {
    ifstream file("../TextFile1.txt", ios::in);
    if (!file) return;

    Mitarbeiter m;
    while (file >> m.personalnummer >> m.vorname >> m.nachname >> m.geburtsdatum >> m.gehalt) {
        daten.push_back(m);
    }
    file.close();
}

// Schreibt alle Datensätze aus dem Vektor in die Datei (überschreibt alte Datei)
void datenSpeichern(const vector<Mitarbeiter>& daten) {
    ofstream file("../TextFile1.txt");
    for (const auto& s : daten) {
        file << s.personalnummer << " " << s.vorname << " " << s.nachname << " "
            << s.geburtsdatum << " " << s.gehalt << "\n";
    }
    file.close();
}

int main() {
    vector<Mitarbeiter> daten;
    datenLaden(daten);  // Bestehende Daten beim Start laden

    int wahl;
    do {
        // Menüauswahl anzeigen
        cout << "\n--- Mitarbeiterprogramm ---\n";
        cout << "1. Datensatz hinzufuegen\n";
        cout << "2. Alle Datensaetze anzeigen\n";
        cout << "0. Beenden\n> ";
        cin >> wahl;

        if (wahl == 1) {
            // Neuen Datensatz erfassen und speichern
            Mitarbeiter s;
            cout << "Personalnummer: "; cin >> s.personalnummer;
            cout << "Vorname: "; cin >> s.vorname;
            cout << "Nachname: "; cin >> s.nachname;
            cout << "Geburtsdatum (TT.MM.JJJJ): "; cin >> s.geburtsdatum;
            cout << "Gehalt: "; cin >> s.gehalt;
            daten.push_back(s);
            datenSpeichern(daten);
        }
        else if (wahl == 2) {
            // Alle gespeicherten Datensätze anzeigen
            for (const auto& m : daten) {
                cout << m.personalnummer << ": " << m.vorname << " " << m.nachname
                    << ", " << m.geburtsdatum << ", Gehalt: " << m.gehalt << " EUR\n";
            }
        }

    } while (wahl != 0);  // Programm läuft bis zur Eingabe von 0
    return 0;
}