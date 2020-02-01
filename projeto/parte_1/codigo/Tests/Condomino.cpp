#include "Condomino.h"
#include <string>
#include <algorithm>

using namespace std;

Condomino::Condomino(const string &nm, const string &ni) {
    nome = nm;
    nif = ni;
}

Condomino::Condomino() {
    nome = "sem nome";
    nif = "sem NIF";
}

bool Condomino::operator == (const Condomino &c1) const {
    return nif == c1.nif;
}

string Condomino::getNome() const {
    return nome;
}

void Condomino::setNome(const string &nm) {
    nome = nm;
}

string Condomino::getNif() const {
    return nif;
}

void Condomino::setNif(const string &ni) {
    nif = ni;
}

vector<Habitacao *> Condomino::getHabitacoes() const {
    return habitacoes;
}

void Condomino::setHabitacoes(const vector<Habitacao *> &v) {
    habitacoes = v;
}

vector<Servico *> Condomino::getServicos() const {
    return servicos;
}

void Condomino::setServicos(const vector<Servico *> &v) {
    servicos = v;
}

int Condomino::numeroHabitacoes() const {
    return habitacoes.size();
}

void Condomino::adicionaHabitacao(Habitacao *v1) {
    habitacoes.push_back(v1);
}

bool Condomino::validaHabitacao(Habitacao *h1) const {
    if (habitacoes.size() == 0) return false;
    vector<Habitacao *>::const_iterator it = habitacoes.begin();
    while (it != habitacoes.end()) {
        if ((*it)->getMorada().getCodigoPostal() == h1->getMorada().getCodigoPostal()) {
            return true;
        }
        it++;
    }
    return false;
}

void Condomino::adicionaServico(Servico *s1) {
    servicos.push_back(s1);
}

void Condomino::Mostrar_Servicos() const {
    vector<Servico *>::const_iterator it;
    int contador = 1;
    for (it = servicos.begin() ; it != servicos.end() ; it++) {
        cout << "[" << contador << "] ";
        (*it)->mostrar();
        contador++;
    }
}

void Condomino::Mostrar_Habitacoes() const {
    vector <Habitacao *>::const_iterator it;
    int contador = 1;
    for (it = habitacoes.begin(); it != habitacoes.end(); it++)
    {
        cout << "[" << contador << "] ";
        (*it)->mostrar();
        contador++;
    }
}

string Condomino::info() const {
    stringstream oss;
    int contador = 1;
    vector<Habitacao *>::const_iterator ith;
    vector<Servico *>::const_iterator its;
    oss << "Nome: " << nome << endl;
    oss << "NIF: " << nif << endl;
    oss << "Habitacoes: ";
    if (habitacoes.size() == 0)
        oss << "Nenhuma Habitacao" << endl;
    for (ith = habitacoes.begin() ; ith != habitacoes.end() ; ith++)
    {
        if (contador == habitacoes.size())
            oss << (*ith)->getMorada().getCodigoPostal() << endl;
        else
            oss << (*ith)->getMorada().getCodigoPostal() << ", ";
        contador++;
    }
    contador = 1;
    oss << "Servicos: ";
    if (servicos.size() == 0)
        oss << "Nenhum Servico" << endl;
    for (its = servicos.begin() ; its != servicos.end() ; its++)
    {
        if (contador == servicos.size())
            oss << (*its)->getDescricao() << endl;
        else
            oss << (*its)->getDescricao() << ", ";
        contador++;
    }
    oss << "Valor Mensal de Condominio (Habitacoes e Servicos): " << totalCondominio() << endl;
    return oss.str();
}

float Condomino::totalCondominio() const {
    float total = 0;
    vector<Habitacao *>::const_iterator it = habitacoes.begin();
    vector<Servico *>::const_iterator its = servicos.begin();
    while (it != habitacoes.end()) {
        total += (*it)->calculaCondominio();
        it++;
    }
    while (its != servicos.end()){
        total += (*its)->getCustoMensal();
        its++;
    }
    return total;
}

vector<Habitacao *> Condomino::operator()(float areaHabitacional) const {
    vector<Habitacao *> habitacoesArea;
    if (habitacoes.size() == 0) return habitacoesArea;
    vector<Habitacao *>::const_iterator it = habitacoes.begin();
    while (it != habitacoes.end()) {
        if ((*it)->getAreaHabitacional() == areaHabitacional)
            habitacoesArea.push_back(*it);
        it++;
    }
    return habitacoesArea;
}

string Condomino::escreveHabitacoes() const {
    stringstream oss;
    vector<Habitacao *>::const_iterator it = habitacoes.begin();
    while (it != habitacoes.end()) {
        oss << (*it)->info() << endl;
        it++;
    }
    return oss.str();
}

