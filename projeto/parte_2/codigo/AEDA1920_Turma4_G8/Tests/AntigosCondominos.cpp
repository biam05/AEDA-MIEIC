#include <iostream>
#include <string>
#include <algorithm>

#include "AntigosCondominos.h"

using namespace std;

AntigoCondomino::AntigoCondomino(const string &nm, const string &ni, const int &pr){
    nome = nm;
    nif = ni;
    periodo = pr;
}

AntigoCondomino::AntigoCondomino() {
    nome = "sem nome";
    nif = "sem NIF";
    periodo = 0;
}

string AntigoCondomino::getNome() const {
    return nome;
}

void AntigoCondomino::setNome(const string &nm) {
    nome = nm;
}

string AntigoCondomino::getNif() const {
    return nif;
}

void AntigoCondomino::setNif(const string &ni) {
    nif = ni;
}

int AntigoCondomino::getPeriodo() const {
    return periodo;
}

void AntigoCondomino::setPeriodo(const int &pr) {
    periodo = pr;
}

string AntigoCondomino::info() const {
    stringstream oss;
    oss << "Nome: " << nome << endl;
    oss << "NIF: " << nif << endl;
    oss << "Periodo: " << periodo << " meses" << endl;
    return oss.str();
}

bool AntigoCondomino::operator == (const AntigoCondomino &c1) const {
    return nif == c1.nif;
}

AntigoCondominoRecord::AntigoCondominoRecord(AntigoCondomino *antigoCondomino) {
    AntigoCondominoPtr = antigoCondomino;
}

string AntigoCondominoRecord::getName() const {
    return AntigoCondominoPtr->getNome();
}

string AntigoCondominoRecord::getNIF() const {
    return AntigoCondominoPtr->getNif();
}

void AntigoCondominoRecord::setNIF(const string &nif) {
    AntigoCondominoPtr->setNif(nif);
}

AntigoCondomino* AntigoCondominoRecord::getAntigoCondominoPointer() const {
    return AntigoCondominoPtr;
}
