#include "Transportes.h"
#include <sstream>

using namespace std;

Transporte::Transporte(string t, string d, string pp, int dist) : tipo(t), destino(d), paragem_proxima(pp), distancia(dist){
}

string Transporte::getParagemProxima() const {
    return paragem_proxima;
}

string Transporte::getTipo() const {
    return tipo;
}

string Transporte::getDestino() const {
    return destino;
}

int Transporte::getDistancia() const {
    return distancia;
}

void Transporte::setTipo(string &t) {
    tipo = t;
}

void Transporte::setDestino(string &d) {
    destino = d;
}

void Transporte::setParagemProxima(string &pp) {
    paragem_proxima = pp;
}

void Transporte::setDistancia(int &metros) {
    distancia = metros;
}

bool Transporte::operator<(Transporte &transporte) {
    return distancia < transporte.distancia;
}

string Transporte::info() const {
    stringstream oss;
    oss << "Tipo: " << tipo << endl;
    oss << "Destino: " << destino << endl;
    oss << "Paragem mais Proxima: " << paragem_proxima << endl;
    oss << "Distancia: " << distancia << endl;
    return oss.str();
}




