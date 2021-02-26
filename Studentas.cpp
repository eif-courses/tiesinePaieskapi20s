//
// Created by Marius on 2/26/2021.
//

#include "Studentas.h"

Studentas::Studentas(int amzius, const string &vardas, double stipendija) : amzius(amzius), vardas(vardas),
                                                                            stipendija(stipendija) {}

int Studentas::GetAmzius() const {
  return amzius;
}

const string &Studentas::GetVardas() const {
  return vardas;
}

double Studentas::GetStipendija() const {
  return stipendija;
}
