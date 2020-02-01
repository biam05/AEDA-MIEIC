#include <iostream>
#include <fstream>
#include <vector>
#include "Servico.h"
#include "Habitacao.h"
#include "Condomino.h"
#include "insertionSort.h"
#include "Condominio.h"
#include <algorithm>
#include "sequentialSearch.h"
#include "Excecoes.h"
#include <queue>

using namespace std;

Condominio::Condominio() {
    designacao = "sem designacao";
    localizacao = "sem localizacao";
}

Condominio::Condominio(const string &desi, const string &loc) {
    designacao = desi;
    localizacao = loc;
}

int Condominio::numeroHabitacoes() const {
    return habitacoes.size();
}

int Condominio::numeroVivendas() const {
    int numeroVivendas = 0;
    vector<Habitacao *>::const_iterator it = habitacoes.begin();
    while (it != habitacoes.end()) {
        if ((*it)->tipoHabitacao() == "Vivenda") {
            numeroVivendas++;
        }
        it++;
    }
    return numeroVivendas;
}

vector<Habitacao *> Condominio::getHabitacoesDisponiveis() const {
    unsigned int contador = 0;
    vector<Habitacao *> disponiveis;
    vector<Habitacao *>::const_iterator it = habitacoes.begin();
    while (it != habitacoes.end()) {
        for (unsigned int i = 0 ; i < condominos.size() ; i++) {
            if (condominos[i]->validaHabitacao(*it)) {
                contador++;
            }
        }
        if (contador == 0) {
            disponiveis.push_back(*it);
        }
        it++;
        contador = 0;
    }
    return disponiveis;
}

int Condominio::numeroCondominos() const {
    return condominos.size();
}

int Condominio::numeroAntigosCondominos() const {
    return antigos_condominos.size();
}

void Condominio::adicionaHabitacao(Habitacao *h1) {
    habitacoes.push_back(h1);
}

bool Condominio::validaHabitacao(Habitacao *h1) const {
    if (condominos.size() == 0) return false;
    vector<Condomino *>::const_iterator it = condominos.begin();
    while (it != condominos.end()) {
        if ((*it)->validaHabitacao(h1)) {
            return true;
        }
        it++;
    }
    return false;
}

void Condominio::adicionaCondomino(Condomino *c1) {
    condominos.push_back(c1);
}

void Condominio::adicionaAntigoCondomino(AntigoCondomino *a1) {
    antigos_condominos.insert(a1);
}

vector<Habitacao *> Condominio::getHabitacoes() const {
    return habitacoes;
}

void Condominio::setHabitacoes(const vector<Habitacao *> &h) {
    habitacoes = h;
}

vector<Condomino *> Condominio::getCondominos() const {
    return condominos;
}

priority_queue<Transporte *, vector<Transporte*>, TransportesCmp> Condominio::getTransportes() const {
    return transportes;
}

void Condominio::setCondominos(const vector<Condomino *> &c) {
    condominos = c;
}

HashTabAntigoClienteRecord Condominio::getAntigosCondominos() const {
    return antigos_condominos;
}

void Condominio::setTransportes(const vector<Transporte*> &t){
    while(!transportes.empty())
    {
        transportes.pop();
    }
    vector<Transporte*>::const_iterator it;
    for(it = t.begin(); it != t.end(); it++)
    {
        transportes.push(*it);
    }
}

void Condominio::Mostrar_Habitacoes() const {
    int count = 1;
    vector<Habitacao *>::const_iterator it;
    for(it = habitacoes.begin(); it != habitacoes.end(); it++)
    {
        cout << '[' << count << "] " <<  (*it)->getMorada().getEndereco() << ' ' <<(*it)->getMorada().getCidade()
        << ' ' << (*it)->getMorada().getCodigoPostal() << endl;
        count++;
    }
}

vector<Habitacao *> Condominio::Mostrar_Habitacoes_Disponiveis() const {
    string cp;
    unsigned int contador = 0;
    vector<Habitacao *> disponiveis;
    vector<Habitacao *>::const_iterator it = habitacoes.begin();
    while (it != habitacoes.end()) {
        cp = (*it)->getMorada().getCodigoPostal();
        for (unsigned int i = 0 ; i < condominos.size() ; i++) {
            if (condominos[i]->validaHabitacao(*it)) {
                contador++;
            }
        }
        if (contador == 0) {
            disponiveis.push_back(*it);
        }
        it++;
        contador = 0;
    }
    int count = 1;
    vector<Habitacao *>::const_iterator itd;
    for(itd = disponiveis.begin(); itd != disponiveis.end(); itd++)
    {
        cout << '[' << count << "] " <<  (*itd)->getMorada().getEndereco() << ' ' <<(*itd)->getMorada().getCidade()
             << ' ' << (*itd)->getMorada().getCodigoPostal() << endl;
        count++;
    }
    return disponiveis;
}

void Condominio::Mostrar_Condominos() const {
    int count = 1;
    vector <Condomino *>::const_iterator it;
    for (it = condominos.begin() ; it != condominos.end() ; it++)
    {
        cout << "[" << count << "] " << (*it)->getNome() << " - " << (*it)->getNif() << endl;
        count++;
    }
}

string Condominio::escreveTotalHabitacoes()const {
    stringstream oss;
    vector<Habitacao *>::const_iterator it = habitacoes.begin();
    while (it != habitacoes.end()) {
        oss << (*it)->info() << "----------" << endl << endl;
        it++;
    }
    return oss.str();
}

string Condominio::escreveTotalCondominos()const {
    stringstream oss;
    vector<Condomino *>::const_iterator it = condominos.begin();
    while (it != condominos.end()) {
        oss << (*it)->info() << endl;
        it++;
    }
    return oss.str();
}

string Condominio::escreveInformacoes() const {
    stringstream oss;
    oss << " Condominio: " << designacao << "\n Localizacao: " << localizacao << "\n Numero de Habitacoes: "
        << numeroHabitacoes() << "\n Numero de Vivendas: " << numeroVivendas();
    oss << "\n Numero de Apartamentos: " << numeroHabitacoes() - numeroVivendas() << "\n Numero de Condominos: "
        << numeroCondominos() << "\n Numero de Antigos Condominos: " << numeroAntigosCondominos();
    oss << "\n Numero de Transportes: " << numeroTransportes();
    return oss.str();
}

bool comparaCondominos(const Condomino *c1, const Condomino *c2){
    return c1->getNome() < c2->getNome();
}

void Condominio::ordenaCondominosPorNome(){
    sort(condominos.begin(), condominos.end(), comparaCondominos);
}

void Condominio::ordenaHabitacoesPorAreaHabitacional(){
    insertionSort(habitacoes);
}

void Condominio::Mostrar_Transportes()
{
    vector<Transporte*> aux;
    while(!transportes.empty())
    {
        aux.push_back(transportes.top());
        transportes.pop();
    }
    vector<Transporte*>::const_reverse_iterator it;
    for(it = aux.rbegin(); it != aux.rend(); it++)
    {
        cout << "Tipo: " << (*it)->getTipo() << endl;
        cout << "Destino: " << (*it)->getDestino() << endl;
        cout << "Paragem mais Proxima: " << (*it)->getParagemProxima() << endl;
        cout << "Distancia: " << (*it)->getDistancia() << endl << endl;
    }
    for(it = aux.rbegin(); it != aux.rend(); it++)
    {
        transportes.push(*it);
    }
    aux.clear();
}

string Condominio::getDesignacao() const {
    return designacao;
}

void Condominio::setDesignacao(const string &desi) {
    designacao = desi;
}

string Condominio::getLocalizacao() const {
    return localizacao;
}

void Condominio::setLocalizacao(const string &loc) {
    localizacao = loc;
}

bool Condominio::operator < (const Condominio &c1) const {
    if (habitacoes.size() == c1.habitacoes.size() && numeroVivendas() == c1.numeroVivendas())
        return (designacao < c1.designacao);
    else if (habitacoes.size() == c1.habitacoes.size())
        return (numeroVivendas() < c1.numeroVivendas());
    else return (habitacoes.size() < c1.habitacoes.size());
}

bool Condominio::operator == (const Condominio &c1) const {
    return designacao == c1.designacao;
}

Transporte *Condominio::Procurar_Transporte(string destino){
    vector<Transporte*> aux;
    vector<Transporte*>::const_reverse_iterator it;
    Transporte* answer;
    bool encontrou = false;
    while(!transportes.empty())
    {
        aux.push_back(transportes.top());
        transportes.pop();
    }
    it = aux.rbegin();
    while(it != aux.rend())
    {
        if((*it)->getDestino() == destino){
            answer = (*it);
            encontrou = true;
            break;
        }
        it++;
    }
    for(it = aux.rbegin(); it != aux.rend(); it++)
        transportes.push(*it);
    if (encontrou)
        return answer;

    throw Transporte_Nao_Encontrado(destino);
}

Transporte *Condominio::Procurar_Transporte_Perto(){
    vector<Transporte*> aux;
    vector<Transporte*>::const_reverse_iterator it;
    Transporte* answer;
    while(!transportes.empty())
    {
        aux.push_back(transportes.top());
        transportes.pop();
    }
    it = aux.rbegin();
    answer = (*it);
    for(it = aux.rbegin(); it != aux.rend(); it++)
        transportes.push(*it);
    return answer;
}

void Condominio::adicionaTransporte(Transporte *t) {
    transportes.push(t);
}

void Condominio::Mostrar_Transportes_Edicao(){
    vector<Transporte *> aux;
    while(!transportes.empty())
    {
        aux.push_back(transportes.top());
        transportes.pop();
    }

    int count = 1;
    vector <Transporte *>::const_reverse_iterator it;
    for(it = aux.rbegin(); it != aux.rend(); it++)
    {
        cout << "[" << count << "] " << (*it)->getDestino() << " - " << (*it)->getDistancia() << endl;
        count++;
    }

    for(it = aux.rbegin(); it != aux.rend(); it++)
    {
        transportes.push(*it);
    }
    aux.clear();

}

int Condominio::numeroTransportes() const {
    return transportes.size();
}

Condominio& Condominio::operator=(const Condominio &outro) {
    designacao = outro.designacao;
    localizacao = outro.localizacao;
    habitacoes = outro.getHabitacoes();
    condominos = outro.getCondominos();
    antigos_condominos = outro.getAntigosCondominos();
}
