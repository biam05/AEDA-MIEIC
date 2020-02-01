#include "Servico.h"
#include <iostream>

using namespace std;

Servico::Servico(int i, const string &desc, const float &c) {
    id = i;
    descricao = desc;
    custo = c;
}

int Servico::ultimo_id = 0;

Servico::Servico(const string &desc, const float &c) : id(++ultimo_id) {
    descricao = desc;
    custo = c;
}

int Servico::getId() const {
    return id;
}

void Servico::setId(const int &i) {
    id = i;
}

string Servico::getDescricao() const {
    return descricao;
}

void Servico::setDescricao(const string &desc) {
    descricao = desc;
}

float Servico::getCusto() const {
    return custo;
}

float Servico::getCustoMensal() const {
    return custo;
}

void Servico::setCusto(const float &c) {
    custo = c;
}

void Servico::mostrar() const {
    cout << descricao << endl;
}

string Servico::info() const {
    stringstream oss;
    oss << "ID: " << id << endl;
    oss << "Descricao: " << descricao << endl;
    oss << "Custo: " << custo << endl;
    return oss.str();
}

ServicoLimpeza::ServicoLimpeza(int id, const string &desc, const float &c, float d) : Servico(id, desc, c) {
    duracao = d;
}

float ServicoLimpeza::getDuracao() const {
    return duracao;
}

float ServicoLimpeza::getCustoMensal() const {
    return duracao*custo;
}

PrestadorServicoLimpeza ServicoLimpeza::getPrestador() const {
    return prestadorServicoLimpeza;
}

void ServicoLimpeza::setPrestador(PrestadorServicoLimpeza *prestador){
    prestadorServicoLimpeza.setTotalHoras(prestador->getTotalHoras());
    prestadorServicoLimpeza.setNome(prestador->getNome());
}

void ServicoLimpeza::mostrar() const {
    cout << descricao << " - " << duracao << " horas" << endl;
}

string ServicoLimpeza::info() const {
    stringstream oss;
    oss << "ID: " << id << endl;
    oss << "Tipo de Servico: Limpeza" << endl;
    oss << "Custo por hora: " << custo << endl;
    oss << "Custo total: " << custo*duracao << endl;
    oss << "Duracao: " << duracao << endl;
    oss << "Prestador: " << prestadorServicoLimpeza.getNome() << endl;
    return oss.str();
}



