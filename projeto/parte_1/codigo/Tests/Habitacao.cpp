#include "Habitacao.h"
#include <iostream>
#include <string>

using namespace std;

float Vivenda::valorBaseCondominioVivenda = 1000; //POR EXEMPLO

float Apartamento::valorBaseCondominioApartamento = 2000; //POR EXEMPLO

Morada::Morada(string e, string c, string cp) : endereco(e), cidade(c), codigoPostal(cp) {
}

string Morada::getEndereco() const {
    return endereco;
}

string Morada::getCidade() const {
    return cidade;
}

string Morada::getCodigoPostal() const {
    return codigoPostal;
}

void Morada::setEndereco(const string &e) {
    endereco = e;
}

void Morada::setCidade(const string &c) {
    cidade = c;
}

void Morada::setCodigoPostal(const string &cp) {
    codigoPostal = cp;
}

string Morada::info() const {
    stringstream oss;
    oss << "Endereco: " << endereco << endl;
    oss << "Cidade: " << cidade << endl;
    oss << "Codigo Postal: " << codigoPostal << endl;
    return oss.str();
}

bool Morada::operator==(const Morada &m1) const {
    return codigoPostal == m1.codigoPostal;
}

Habitacao::Habitacao(float ah, Morada m) : morada(m) {
    areaHabitacional = ah;
}


Morada Habitacao::getMorada() const {
    return morada;
}


void Habitacao::setMorada(const Morada &m) {
    morada = m;
}


float Habitacao::getAreaHabitacional() const {
    return areaHabitacional;
}


void Habitacao::setAreaHabitacional(const float ah) {
    areaHabitacional = ah;
}


string Habitacao::info() const {
    stringstream oss;
    oss << morada.info() << endl;
    oss << "Area Habitacional: " << areaHabitacional << endl;
    return oss.str();
}

bool Habitacao::operator==(const Habitacao &v) const {
    return morada == v.morada;
}

bool Habitacao::operator<(const Habitacao &v) const {
    return areaHabitacional < v.areaHabitacional;
}

void Habitacao::escrever_habitacao(ostream &o) const {
    o << morada.getEndereco() << endl << morada.getCidade() << endl << morada.getCodigoPostal() << endl;
    o << areaHabitacional << endl;
}

void Habitacao::mostrar() const {
    cout << morada.getCodigoPostal() << endl;
}

Vivenda::Vivenda(float ah, Morada m, float ae, bool cp) : Habitacao(ah, m) {
    areaExterior = ae;
    comPiscina = cp;
}

string Vivenda::info() const {
    stringstream oss;
    oss << "Tipo de Habitacao: Vivenda" << endl;
    oss << Habitacao::info();
    oss << "Area Exterior: " << areaExterior << endl;
    if (comPiscina)
        oss << "Piscina: Sim" << endl << endl;
    else
        oss << "Piscina: Nao" << endl << endl;
    return oss.str();
}

//INCOMPLETO!
float Vivenda::calculaCondominio() const {
    if (comPiscina) {
        return 5 * areaExterior +
               Vivenda::valorBaseCondominioVivenda; //  C/PISCINA PAGA 5 VEZES A AREA EXTERIOR (POR EXEMPLO)
    }
    return 3 * areaExterior +
           Vivenda::valorBaseCondominioVivenda; // S/PISCINA PAGA 3 VEZES A AREA EXTERIOR (POR EXEMPLO)
}

float Vivenda::getAreaExterior() const {
    return areaExterior;
}

bool Vivenda::getComPiscina() const {
    return comPiscina;
}

void Vivenda::setAreaExterior(const float ae) {
    areaExterior = ae;
}

void Vivenda::setComPiscina(const bool cp) {
    comPiscina = cp;
}

void Vivenda::escrever_habitacao(ostream &o) const {
    Habitacao::escrever_habitacao(o);
    o << "Vivenda" << endl;
    o << areaExterior << endl;
    o << comPiscina << endl;
    o << "----------";
}

Apartamento::Apartamento(float ah, Morada m, string tipologia, int piso) : Habitacao(ah, m),
                                                                           tipologia(tipologia),
                                                                           piso(piso) {}

string Apartamento::getTipologia() const {
    return tipologia;
}

int Apartamento::getPiso() const {
    return piso;
}

string Apartamento::info() const {
    stringstream oss;
    oss << "Tipo de Habitacao: Apartamento" << endl;
    oss << Habitacao::info();
    oss << "Tipologia: " << tipologia << endl;
    oss << "Piso: " << piso << endl << endl;;
    return oss.str();
}

//INCOMPLETO!
// REMOVER NÚMEROS MÁGICOS
float Apartamento::calculaCondominio() const {
    if (tipologia == "T0" || tipologia == "t0") {
        return (piso <= 3) ? 200 + Apartamento::valorBaseCondominioApartamento : 175 +
                                                                                 Apartamento::valorBaseCondominioApartamento;
    } else if (tipologia == "T1" || tipologia == "t1") {
        return (piso <= 3) ? 250 + Apartamento::valorBaseCondominioApartamento : 225 +
                                                                                 Apartamento::valorBaseCondominioApartamento;
    } else if (tipologia == "T2" || tipologia == "t2") {
        return (piso <= 3) ? 350 + Apartamento::valorBaseCondominioApartamento : 300 +
                                                                                 Apartamento::valorBaseCondominioApartamento;
    } else if (tipologia == "T3" || tipologia == "t3") {
        return (piso <= 3) ? 400 + Apartamento::valorBaseCondominioApartamento : 325 +
                                                                                 Apartamento::valorBaseCondominioApartamento;
    } else if (tipologia == "T4" || tipologia == "t4") {
        return (piso <= 3) ? 450 + Apartamento::valorBaseCondominioApartamento : 350 +
                                                                                 Apartamento::valorBaseCondominioApartamento;
    } else if (tipologia == "T5" || tipologia == "t5") {
        return (piso <= 3) ? 500 + Apartamento::valorBaseCondominioApartamento : 375 +
                                                                                 Apartamento::valorBaseCondominioApartamento;
    }
    return 500 + Apartamento::valorBaseCondominioApartamento;
}

void Apartamento::escrever_habitacao(ostream &o) const {
    Habitacao::escrever_habitacao(o);
    o << "Apartamento" << endl;
    o << tipologia << endl;
    o << piso << endl;
    o << "----------";
}

void Apartamento::setTipologia(const string tp) {
    tipologia = tp;
}

void Apartamento::setPiso(const int p) {
    piso = p;
}
