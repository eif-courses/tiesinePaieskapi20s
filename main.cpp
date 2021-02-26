#include <iostream>
#include <vector>
#include <algorithm>
#include "Studentas.h"

using namespace std;

int TiesinePaieska(const vector<int> &sarasas, int raktinisZodis);

vector<int> TiesinePaieskaSurandintiVisusAtitikmenis(const vector<int> &sarasas, int raktinisZodis);

int DvejetainePaieska(vector<int> &sarasas, int kaire, int desine, int raktinisZodis);

int TiesinePaieska(const vector<Studentas> &sarasas, int raktinisZodis);


int main() {

  vector<int> test{44, 22, 888, 12, 54, 22, 55, 44, 2213, 424, 24141, 55, 44};

  vector<Studentas> studentai{
      Studentas(44, "Tomas", 120.45),
      Studentas(55, "Paulius", 213.45),
      Studentas(123, "Tomas", 876.45),
  };

  //vector<Zmogus> t{Zmogus("wae", 22, 2131, 123, 12)};

  int stop = 1;
  while (stop != 0) {

    cout << "-------------MENIU------------------------" << endl;
    cout << "1. Pagal raktini zodi Tiesine paieska." << endl;
    cout << "2. Pagal raktini zodi Dvejetaine paieska." << endl;
    cout << "3. Pagal raktini zodi is Studentas objekto Dvejetaine paieska." << endl;
    cout << "0. Uzbaigti." << endl;
    cout << "-------------------------------------" << endl;
    cout << "Pasirinkite opcija: ";
    cin >> stop;
    cout << "-------------------------------------" << endl;

    switch (stop) {

      case 1: {

        int raktinisZodis;
        cout << "Nurodykite ko ieskote: ";
        cin >> raktinisZodis;
        int indeksas = TiesinePaieska(test, raktinisZodis);

        vector<int> rastiRezultatai = TiesinePaieskaSurandintiVisusAtitikmenis(test, raktinisZodis);


        cout << "-------TiesinePaieskaSurandintiVisusAtitikmenis()--------------" << endl;

        if (!rastiRezultatai.empty()) {
          for (int it: rastiRezultatai) {
            cout << "Sekmingai rastas pozija: " << it << ", rastas: " << test[it] << endl;
          }
        } else {
          cout << "Deja nepavyko rasti pagal pateikta fraze:  " << "\"" << raktinisZodis << "\"" << endl;
        }

        cout << "-------------------------------------" << endl;

        cout << "------------------TiesinePaieska()-------------------" << endl;
        if (indeksas != -1) {
          cout << "Sekmingai rastas pozija: " << indeksas << endl;
        } else {
          cout << "Deja nepavyko rasti pagal pateikta fraze:  " << "\"" << raktinisZodis << "\"" << endl;
        }
        cout << "-------------------------------------" << endl;
        break;
      }
      case 2: {
        int raktinisZodis;
        cout << "Nurodykite ko ieskote: ";
        cin >> raktinisZodis;
        int indeksas = DvejetainePaieska(test, 0, (int) test.size() - 1, raktinisZodis);
        if (indeksas != -1) {
          cout << "Sekmingai rastas pozija: " << indeksas << ", rastas: " << test[indeksas] << endl;
        } else {
          cout << "Deja nepavyko rasti pagal pateikta fraze:  " << "\"" << raktinisZodis << "\"" << endl;
        }
        break;
      }
      case 3: {
        int raktinisZodis;
        cout << "Nurodykite ko ieskote: ";
        cin >> raktinisZodis;
        int indeksas = TiesinePaieska(studentai, raktinisZodis);
        if (indeksas != -1) {
          cout << "studentas yra! jo indeksas: " << indeksas << ", " << studentai[indeksas].GetVardas() << endl;
        } else {
          cout << "toks studentas neegzistuoja!" << endl;
        }
        break;
      }
      default:
        cout << "nera tokio punkto" << endl;
        break;
    }

  }


  return 0;
}


int DvejetainePaieska(vector<int> &sarasas, int kaire, int desine, int raktinisZodis) {
  std::sort(sarasas.begin(), sarasas.end()); // surikiuoja, surusiuoja
//  for(auto it: sarasas){
//    cout << it<<" ";
//  }


//  12 22 22 44 44 44 54 55 55 424 888 2213 24141
// kaire = 0
// desine = 12
// vidurioElem = 0 + (12 - 0) / 2 = 6
//


  while (kaire <= desine) {
    int vidurioElementas = kaire + (desine - kaire) / 2;

    if (sarasas[vidurioElementas] == raktinisZodis) {
      return vidurioElementas;
    }
    // 54 < 44
    if (sarasas[vidurioElementas] < raktinisZodis) {
      kaire = vidurioElementas + 1; // eiti i desine puse
    } else {
      desine = vidurioElementas - 1; // i kaire puse
    }
  }
  return -1;
}


//vector<int> test{44, 22, 888, 12, 54, 22, 55, 44, 2213, 424, 24141,55, 44};

int TiesinePaieska(const vector<int> &sarasas, int raktinisZodis) {

  for (int i = 0; i < sarasas.size(); ++i) {
    if (raktinisZodis == sarasas[i]) {
      return i;
    }
  }
  return -1;
}

int TiesinePaieska(const vector<Studentas> &sarasas, int raktinisZodis) {
  for (int i = 0; i < sarasas.size(); ++i) {
    if (raktinisZodis == sarasas[i].GetAmzius()) {
      return i;
    }
  }
  return -1;
}


vector<int> TiesinePaieskaSurandintiVisusAtitikmenis(const vector<int> &sarasas, int raktinisZodis) {
  vector<int> laikinasSarasas;
  for (int i = 0; i < sarasas.size(); ++i) {
    if (raktinisZodis == sarasas[i]) {
      laikinasSarasas.emplace_back(i);
    }
  }
  return laikinasSarasas;
}
