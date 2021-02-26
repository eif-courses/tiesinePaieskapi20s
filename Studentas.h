//
// Created by Marius on 2/26/2021.
//

#ifndef TIESINEPAIESKAPI20S_STUDENTAS_H
#define TIESINEPAIESKAPI20S_STUDENTAS_H
#include <iostream>

using namespace std;

class Studentas {
private:
  int amzius;
  string vardas;
  double stipendija;
public:
  Studentas(int amzius, const string &vardas, double stipendija);

  int GetAmzius() const;

  const string &GetVardas() const;

  double GetStipendija() const;
};


#endif //TIESINEPAIESKAPI20S_STUDENTAS_H
