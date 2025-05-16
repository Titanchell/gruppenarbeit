#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <thread>

using namespace std;

struct Mitarbeiter {
    int personalnummer;
    string vorname;
    string nachname;
    string geburtsdatum;
    float gehalt;
};

int counter(Mitarbeiter* m);
void save(Mitarbeiter* m, int countEmployee);
void sallery(Mitarbeiter* m, int countEmployee);
void salleryHigh(Mitarbeiter* m, int countEmployee);
void filter(Mitarbeiter* m, int countEmployee);
void output(Mitarbeiter* m);

int main() {
    int countEmployee = 0;
    int mainDec;
    Mitarbeiter m;

    while (true) {
        cout << "Personalchef Programm" << endl;
        cout<<R"(                 1. Mitarbeiterliste
                 2. Lohnkosten
                 3. Lohnerhöhung
                 4. Jahressuche
                 Wählen sie eine Option: )";
        cin >> mainDec;

        if (mainDec == 1)
            output(&m);
        if (mainDec == 2)
            sallery(&m, countEmployee);
        if (mainDec == 3)
            salleryHigh(&m, countEmployee);
        if (mainDec == 4)
            filter(&m, countEmployee);
    }
}

int counter(Mitarbeiter* m) {
    ifstream datei("../TextFile1.txt");
    if (!datei.is_open()) {
        cout << "Die Datei kann nicht geöffnet werden!";
        return 0;
    }

    int j = 0;
    while (datei >> m[j].personalnummer >> m[j].vorname >>
                    m[j].nachname >> m[j].geburtsdatum >> m[j].gehalt) {
        j++;
    }
    datei.close();
    return j;
}
void save(Mitarbeiter* m, int countEmployee) {
    ofstream datei("../TextFile1.txt");
    if (!datei.is_open()) {
        cout << "Die Datei konnte nicht geöffnet werden!";
        return;
    }

    for (int j = 0; j < countEmployee; j++) {
        datei << m[j].personalnummer << "" << m[j].vorname << "" <<
                 m[j].nachname << "" << m[j].geburtsdatum << "" << m[j].gehalt;
    }
    datei.close();
}
void sallery(Mitarbeiter* m, int countEmployee) {
    countEmployee = counter(m);

    float gesamtkosten = 0;

    cout << "Lohnkosten:" << endl;
    for (int i = 0; i < countEmployee; i++) {
        cout << "Name: ";
        cout << m[i].vorname << " " << m[i].nachname << endl;
        cout << "Lohn: ";
        cout << m[i].gehalt << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));

        gesamtkosten = gesamtkosten + m[i].gehalt;
    }
    cout << "Gesamtlohnkosten der Firma: "  << gesamtkosten << endl;
}
void salleryHigh(Mitarbeiter* m, int countEmployee) {
    int salleryDec;
    int nummer;
    float prozent;
    countEmployee = counter(m);

    while (true) {
        cout << "Willkommen bei der Gehaltserhöhung!" << endl;
        output(m);
        cout << endl;
        cout << "Geben sie die Personalnummer ein: ";
        cin >> nummer;
        cout << endl;

        cout << "Um wie viel Prozent möchten sie das Gehalt erhöhen? ";
        cin >> prozent;
        cout << endl;

        m[nummer].gehalt = m[nummer].gehalt * (100/prozent+1);
        save(m, countEmployee);
        cout << "Das Gehalt wurde erfolgreich erhöht!" << endl;
        cout << "Möchten sie das Gehalt einer weiteren Person ändern? JA(1) NEIN(0) ";
        cin >> salleryDec;
        cout << endl;

        if (salleryDec == 0)
            return;

    }

}
void filter(Mitarbeiter* m, int countEmployee) {
    countEmployee = counter(m);
    string geburtsjahr;
    string temp, tempStrcut;
    
    cout <<R"( Jahressuche:
               Nach welchem Geburtsjahr willst du suchen?
               Geburtsjahr: )";
    cin >> geburtsjahr;
    
    for (int i = 0; i < countEmployee; i++) {
        tempStrcut = m[i].geburtsdatum;
        temp.substr(tempStrcut.length()- 5, 4);
        if (geburtsjahr == temp) {
            cout << "Personalnummer: " << m[i].personalnummer << endl;
            cout << "Name: " << m[i].vorname << " " << m[i].nachname << endl;
            cout << "Geburtsdatum: " << m[i].geburtsdatum << endl;
            cout << "Gehalt: " << m[i].gehalt << endl;
        }
    }
}
void output(Mitarbeiter* m) {
    int j = counter(m);

    for (int i = 0; i < j; i++) {
        cout << "Personalnummer: " << m[i].personalnummer << endl;
        cout << "Name: " << m[i].vorname << " " << m[i].nachname << endl;
        cout << "Geburtsdatum: " << m[i].geburtsdatum << endl;
        cout << "Gehalt: " << m[i].gehalt << endl;
    }
}
