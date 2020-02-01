#include "PrestadorServicoLimpeza.h"
#include <iostream>

using namespace std;

PrestadorServicoLimpeza::PrestadorServicoLimpeza(const string &n, float th) : nome(n), totalHoras(th) {}

PrestadorServicoLimpeza::PrestadorServicoLimpeza() {
    nome = "sem nome";
    totalHoras = 0;
}

void PrestadorServicoLimpeza::setNome(const string &nm) {
    nome = nm;
}

string PrestadorServicoLimpeza::getNome() const {
    return nome;
}

float PrestadorServicoLimpeza::getTotalHoras() const {
    return totalHoras;
}

void PrestadorServicoLimpeza::setTotalHoras(float horas) {
    totalHoras = horas;
}

string PrestadorServicoLimpeza::info() const {
    stringstream oss;
    oss << "Nome: " << nome << endl;
    oss << "Total Horas: " << totalHoras << endl;
    return oss.str();
}

bool PrestadorServicoLimpeza::operator < (const PrestadorServicoLimpeza &psl) const {
    return totalHoras < psl.totalHoras;
}

