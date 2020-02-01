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

using namespace std;


int Condominio::numeroHabitacoes() const {
    return habitacoes.size();
}

int Condominio::numeroServicos() const {
    return servicos.size();
}

int Condominio::numeroCondominos() const {
    return condominos.size();
}

int Condominio::numeroServicosEfetuados() const {
    return servicos_efetuados.size();
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

void Condominio::adicionaServico(Servico *s1) {
    servicos.push_back(s1);
}
void Condominio::adicionaCondomino(Condomino *c1) {
    condominos.push_back(c1);
}

void Condominio::adicionaServicoEfetuado(Servico *s1) {
    servicos_efetuados.push_back(s1);
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

void Condominio::setCondominos(const vector<Condomino *> &c) {
    condominos = c;
}

vector<Servico *> Condominio::getServicos() const {
    return servicos;
}

void Condominio::setServicos(const vector<Servico *> &v) {
    servicos = v;
}

vector<Servico *> Condominio::getServicosEfetuados() const {
    return servicos_efetuados;
}

void Condominio::setServicosEfetuados(const vector<Servico *> &v) {
    servicos_efetuados = v;
}

// FUNCOES DE LEITURA E ESCRITA

void Condominio::Ler_Habitacoes(const string &ficheiro)
{
    habitacoes.clear();
    ifstream ler;
    string end ,cid ,cp, tipo_habitacao, separacao;
    float area_habitacional;
    try{
        ler.open(ficheiro);
    }
    catch (Erro_Ler(&ficheiro)){
        cout << "Erro a Ler Habitacoes\n";
        exit(1);
    }
    do{
    getline(ler, end);
    getline(ler, cid);
    getline(ler, cp);
    Morada *morada = new Morada(end,cid,cp);
    ler >> area_habitacional;
    ler.ignore(1000, '\n');
    getline(ler, tipo_habitacao);
    if(tipo_habitacao == "Vivenda")
    {
        float area_exterior;
        bool com_piscina;
        ler >> area_exterior;
        ler.ignore(1000, '\n');
        ler >> com_piscina;
        ler.ignore(1000, '\n');
        getline(ler, separacao);
        Habitacao *vivenda = new Vivenda(area_habitacional,*morada, area_exterior,com_piscina); //troquei vivenda por habitacao no inicio
        habitacoes.push_back(vivenda);
    }
    else
    {
        string tipologia;
        int piso;
        getline(ler, tipologia);
        ler >> piso;
        ler.ignore(1000, '\n');
        getline(ler, separacao);
        Habitacao *apartamento = new Apartamento(area_habitacional, *morada, tipologia, piso); // mesma coisa que em cima
        habitacoes.push_back(apartamento);
    }
    } while (!ler.eof());
    ler.close();
}

void Condominio::Escrever_Habitacoes(const string &ficheiro)
{
    ofstream escrever;
    vector<Habitacao *>::const_iterator it;
    try{
        escrever.open(ficheiro);
    }
    catch (Erro_Escrita(&ficheiro)){
        cout << "Erro a Escrever Habitacoes\n";
        exit(1);
    }
    for(it = habitacoes.begin(); it != habitacoes.end(); it++)
    {
        if(it == habitacoes.begin())
            (*it)->escrever_habitacao(escrever);
        else
        {
            escrever << endl;
            (*it)->escrever_habitacao(escrever);
        }
    }
    escrever.close();
}

void Condominio::Ler_Condominos(const string &ficheiro)
{
    condominos.clear();
    ifstream ler;
    string nome, nif, cp, serv, custo, horas, nome_prestador, total_horas;
    try{
        ler.open(ficheiro);
    }
    catch (Erro_Ler(&ficheiro)){
        cout << "Erro a Ler Condominos\n";
        exit(1);
    }
    do{
        getline(ler, nome);
        getline(ler, nif);
        Condomino *condomino = new Condomino(nome, nif);
        getline (ler, cp);
        while (cp != "-----")
        {
            try {
                Habitacao *habitacao = Procurar_Habitacao(cp);
                condomino->adicionaHabitacao(habitacao);
                getline(ler, cp);
            }
            catch (Habitacao_Nao_Encontrada(&cp)){
                cout << "\nHabitacao Nao Encontrada! \n";
            }
        }
        getline(ler, serv);
        while (serv != "----------")
        {
            if (serv == "Servico de Limpeza") {
                getline (ler, custo);
                getline(ler, horas);
                getline(ler, nome_prestador);
                getline(ler, total_horas);
                Servico* servico = new ServicoLimpeza(1,serv,stof(custo), stof(horas));
                ((ServicoLimpeza *) servico)->setPrestador(new PrestadorServicoLimpeza(nome_prestador,stof(total_horas)));
                condomino->adicionaServico(servico);
            }
            else {
                getline (ler, custo);
                Servico* servico = new Servico(serv, stof(custo));
                condomino->adicionaServico(servico);
            }
            getline(ler, serv);
        }
        condominos.push_back(condomino);
    } while (!ler.eof());
    ler.close();
}

void Condominio::Escrever_Condominos(const string &ficheiro)
{
    ofstream escrever;
    vector<Condomino *>::const_iterator itc;
    vector<Habitacao *>::const_iterator ith;
    vector<Servico *>::const_iterator its;
    try{
        escrever.open(ficheiro);
    }
    catch (Erro_Escrita(&ficheiro)){
        cout << "Erro a Escrever Condominos\n";
        exit(1);
    }
    for (itc = condominos.begin() ; itc != condominos.end() ; itc++)
    {
        if (itc == condominos.begin())
            escrever << (*itc)->getNome() << endl << (*itc)->getNif() << endl;
        else
            escrever << endl << (*itc)->getNome() << endl << (*itc)->getNif() << endl;
        vector<Habitacao *> vetor_h = (*itc)->getHabitacoes();
        for (ith = vetor_h.begin() ; ith != vetor_h.end() ; ith++)
        {
            escrever << (*ith)->getMorada().getCodigoPostal() << endl;
        }
        escrever << "-----" << endl;
        vector <Servico *> vetor_s = (*itc)->getServicos();
        for (its = vetor_s.begin() ; its != vetor_s.end() ; its++)
        {
            if ((*its)->getDescricao() == "Servico de Limpeza") {
                escrever << (*its)->getDescricao() << endl << (*its)->getCusto() << endl;
                escrever << ((ServicoLimpeza*)(*its))->getDuracao() << endl << ((ServicoLimpeza*)(*its))->getPrestador().getNome() << endl << ((ServicoLimpeza*)(*its))->getPrestador().getTotalHoras() << endl;
            }
            else
                escrever << (*its)->getDescricao() << endl << (*its)->getCusto() << endl;
        }
        escrever << "----------";
    }
    escrever.close();
}

void Condominio::Ler_Servicos(const string &ficheiro)
{
    servicos.clear();
    ifstream ler;
    string descricao, separacao, custo;
    int id;
    try{
        ler.open(ficheiro);
    }
    catch (Erro_Ler(&ficheiro)){
        cout << "Erro a Ler Servicos\n";
        exit(1);
    }
    cin.ignore(1000,'\n');
    do{
    ler >> id;
    ler.ignore(1000,'\n');
    getline(ler,descricao);
    getline(ler, custo);
    getline(ler, separacao);
    Servico *service = new Servico(id,descricao,stof(custo));
    servicos.push_back(service);
    } while (!ler.eof());
    ler.close();
    Servico::ultimo_id = servicos[servicos.size()-1]->getId();
}

void Condominio::Escrever_Servicos(const string &ficheiro)
{
    ofstream escrever;
    vector<Servico *>::const_iterator it;
    try{
        escrever.open(ficheiro);
    }
    catch (Erro_Escrita(&ficheiro)){
        cout << "Erro a Escrever Servicos Efetuados\n";
        exit(1);
    }
    for (it = servicos.begin() ; it != servicos.end() ; it++)
    {
        if (it == servicos.begin())
            escrever << (*it)->getId() << endl << (*it)->getDescricao() << endl << (*it)->getCusto() << endl << "----------";
        else
            escrever << endl << (*it)->getId() << endl << (*it)->getDescricao() << endl << (*it)->getCusto() << endl << "----------";
    }
    escrever.close();
}

void Condominio::Ler_Servicos_Efetuados(const string &ficheiro)
{
    servicos_efetuados.clear();
    int id;
    string descricao, custo, separacao, horas, nome_prestador, total_horas;
    ifstream ler;
    try{
        ler.open(ficheiro);
    }
    catch (Erro_Ler(&ficheiro)){
        cout << "Erro a Ler Servicos Efetuados\n";
        exit(1);
    }
    do{
        Servico *service;
        ler >> id;
        ler.ignore(1000,'\n');
        getline(ler,descricao);
        getline(ler, custo);
        if (descricao == "Servico de Limpeza"){
            getline(ler, horas);
            getline(ler, nome_prestador);
            getline (ler, total_horas);
            Servico *service = new ServicoLimpeza(id,descricao,stof(custo),stof(horas));
            ((ServicoLimpeza *) service)->setPrestador(new PrestadorServicoLimpeza(nome_prestador,stof(total_horas)));
            servicos_efetuados.push_back(service);
        }
        else{
            Servico *service = new Servico(id, descricao, stof(custo));
            servicos_efetuados.push_back(service);
        }
        getline(ler, separacao);
    } while (!ler.eof());
    ler.close();
}

void Condominio::Escrever_Servicos_Efetuados(const string &ficheiro)
{
    ofstream escrever;
    vector<Servico *>::const_iterator it;
    try{
        escrever.open(ficheiro);
    }
    catch (Erro_Escrita(&ficheiro)){
        cout << "Erro a Escrevrer Habitações\n";
        exit(1);
    }
    for (it = servicos_efetuados.begin() ; it != servicos_efetuados.end() ; it++)
    {
        Servico *service;
        if (it == servicos_efetuados.begin()) {
            if ((*it)->getDescricao() == "Servico de Limpeza") {
                escrever << (*it)->getId() << endl << (*it)->getDescricao() << endl << (*it)->getCusto() << endl << ((ServicoLimpeza *) *it)->getDuracao() << endl << ((ServicoLimpeza *) *it)->getPrestador().getNome() << endl << ((ServicoLimpeza *) *it)->getPrestador().getTotalHoras() << endl << "----------";
            }
            else
                escrever << (*it)->getId() << endl << (*it)->getDescricao() << endl << (*it)->getCusto() << endl << "----------";
        }
        else {
            if ((*it)->getDescricao() == "Servico de Limpeza") {
                escrever << endl << (*it)->getId() << endl << (*it)->getDescricao() << endl << (*it)->getCusto() << endl << ((ServicoLimpeza *) *it)->getDuracao() << endl << ((ServicoLimpeza *) *it)->getPrestador().getNome() << endl << ((ServicoLimpeza *) *it)->getPrestador().getTotalHoras() << endl << "----------";
            }
            else
                escrever << endl << (*it)->getId() << endl << (*it)->getDescricao() << endl << (*it)->getCusto() << endl << "----------";
        }
    }
    escrever.close();
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

void Condominio::Mostrar_Condominos() const {
    int count = 1;
    vector <Condomino *>::const_iterator it;
    for (it = condominos.begin() ; it != condominos.end() ; it++)
    {
        cout << "[" << count << "] " << (*it)->getNome() << " - " << (*it)->getNif() << endl;
        count++;
    }
}

void Condominio::Mostrar_Servicos() const
{
    vector<Servico *>::const_iterator it;
    for (it = servicos.begin() ; it != servicos.end() ; it++)
        cout << "[" << (*it)->getId() << "] " << (*it)->getDescricao() << endl;
}

Habitacao*  Condominio::Procurar_Habitacao(string cp) const {
    vector<Habitacao *>::const_iterator it;
    for (it = habitacoes.begin() ; it != habitacoes.end() ; it++)
    {
        if ((*it)->getMorada().getCodigoPostal() == cp) {
            return (*it);
        }
    }
    throw Habitacao_Nao_Encontrada(cp);
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

string Condominio::escreveTotalServicos() const {
    stringstream oss;
    vector<Servico *>::const_iterator it = servicos.begin();
    while (it != servicos.end()) {
        oss << (*it)->info() << endl;
        it++;
    }
    return oss.str();
}

Condomino* Condominio::Procurar_Condomino(string nif) const {
    vector<Condomino *>::const_iterator it;
    for (it = condominos.begin() ; it != condominos.end() ; it++){
        if ((*it)->getNif() == nif) {
            return (*it);
        }
    }
    throw Condomino_Nao_Encontrado(nif);
}

void Condominio::Mostrar_Servicos_e_Prestadores(CondomiX &gestao) {
    vector<Servico *>::const_iterator it;
    for (it = servicos.begin() ; it != servicos.end() ; it++)
    {
        cout << "[" << (*it)->getId() << "] " << (*it)->getDescricao() << endl;
        if((*it)->getDescricao() == "Servico de Limpeza") gestao.Mostrar_Prestadores();
    }     
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

vector <Habitacao *> Condominio::Mostrar_Habitacoes_Disponiveis() const {
    int count = 1;
    vector<Habitacao *>::const_iterator it;
    vector<Habitacao *>res;
    for(it = habitacoes.begin(); it != habitacoes.end(); it++)
    {
        if(!validaHabitacao(*it))
        {
            cout << '[' << count << "] " <<  (*it)->getMorada().getEndereco() << ' ' <<(*it)->getMorada().getCidade()
                 << ' ' << (*it)->getMorada().getCodigoPostal() << endl;
            count++;
            res.push_back(*it);
        }
    }
    return res;
}
