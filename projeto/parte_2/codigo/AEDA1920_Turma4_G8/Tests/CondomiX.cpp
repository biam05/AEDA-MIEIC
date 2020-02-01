#include "CondomiX.h"
#include "Excecoes.h"
#include <fstream>
#include <iostream>
#include <string>
#include "bst.h"
#include <time.h>

CondomiX::CondomiX(): condominios(Condominio("","")){}

BST<Condominio> CondomiX::getCondominios() const {
    return condominios;
}

void CondomiX::adicionaCondominio(const Condominio &c1){
    condominios.insert(c1);
}

void CondomiX::adicionaCondominios(const vector<Condominio> &condominios1){
    for (int i = 0; i < condominios1.size(); i++) {
        condominios.insert(condominios1[i]);
    }
}

void CondomiX::imprime() const {
    iteratorBST<Condominio> it2 = condominios.begin();
    while (it2!=condominios.end()) {
        cout << (*it2).getDesignacao() << endl << (*it2).getLocalizacao() << endl;
        it2++;
    }
}

vector<string> CondomiX::getDesignacoesPorLocalizacao(string localizacao) {
    vector<string> res;
    BSTItrIn<Condominio> it(condominios);
    while (!it.isAtEnd()) {
        if (it.retrieve().getLocalizacao() == localizacao)
            res.push_back(it.retrieve().getDesignacao());
        it.advance();
    }
    return res;
}

vector<Condominio> CondomiX::getCondominiosPorHabitacoes(int numeroHabitacoes) {
    vector<Condominio> res;
    BSTItrIn<Condominio> it(condominios);
    while (!it.isAtEnd()) {
        if (it.retrieve().numeroHabitacoes() <= numeroHabitacoes)
            res.push_back(it.retrieve());
        it.advance();
    }
    return res;
}

void CondomiX::removeCondominio(const Condominio &c1) {
    condominios.remove(c1);
}

bool CondomiX::removeCondominioPorDesignacao(string designacao) {
    BSTItrIn<Condominio> it(condominios);
    while (!it.isAtEnd()) {
        if (it.retrieve().getDesignacao() == designacao){
            condominios.remove(it.retrieve());
            return true;
        }
        it.advance();
    }
    return false;
}

Condominio CondomiX::getCondominioPorDesignacao(string designacao)
{
    BSTItrIn<Condominio> it(condominios);
    while (!it.isAtEnd()) {
        if (it.retrieve().getDesignacao() == designacao){
            return it.retrieve();
        }
        it.advance();
    }
}

int CondomiX::numeroCondominios() const {
    int contador = 0;
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        contador++;
        ita.advance();
    }
    return contador;
}

int CondomiX::numeroServicos() const {
    return servicos.size();
}

int CondomiX::numeroServicosEfetuados() const {
    return servicos_efetuados.size();
}

void CondomiX::adicionaServico(Servico *s1) {
    servicos.push_back(s1);
}

void CondomiX::adicionaServicoEfetuado(Servico *s1) {
    servicos_efetuados.push_back(s1);
}

vector<Servico *> CondomiX::getServicos() const {
    return servicos;
}

vector<PrestadorServicoLimpeza *>  CondomiX::getPrestadores() const {
    return prestadoresServicoLimpeza;
}

vector<Servico *> CondomiX::getServicosEfetuados() const {
    return servicos_efetuados;
}

void CondomiX::setServicos(const vector<Servico *> &v) {
    servicos = v;
}

void CondomiX::setServicosEfetuados(const vector<Servico *> &v) {
    servicos_efetuados = v;
}

string CondomiX::escreveTotalServicos() const {
    stringstream oss;
    vector<Servico *>::const_iterator it = servicos.begin();
    while (it != servicos.end()) {
        oss << (*it)->info() << endl;
        it++;
    }
    return oss.str();
}

string CondomiX::escreverTotalPrestadoresServicoLimpeza() const {
    stringstream oss;
    vector<PrestadorServicoLimpeza *>::const_iterator it = prestadoresServicoLimpeza.begin();
    while (it != prestadoresServicoLimpeza.end()) {
        oss << (*it)->info() << endl;
        it++;
    }
    return oss.str();
}

string CondomiX::escreveTotalAntigosCondominos() const {
    stringstream oss;
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        HashTabAntigoClienteRecord ant_cond = ita.retrieve().getAntigosCondominos();
        HashTabAntigoClienteRecord::const_iterator it = ant_cond.begin();
        oss << "Condominio: " << ita.retrieve().getDesignacao() << " - " << ita.retrieve().getLocalizacao() << " (" << ita.retrieve().numeroHabitacoes() << " habitacoes, " << ita.retrieve().numeroCondominos() << " condominos)"<< endl << endl;
        while (it != ant_cond.end()) {
            oss << (*it).getAntigoCondominoPointer()->info() << endl;
            it++;
        }
        ita.advance();
    }
    return oss.str();
}

Habitacao*  CondomiX::Procurar_Habitacao(string cp, string &designacao, string &localizacao) const {
    vector<Habitacao *>::const_iterator it;
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        vector<Habitacao *> vetor = ita.retrieve().getHabitacoes();
        for (it = vetor.begin(); it != vetor.end(); it++) {
            if ((*it)->getMorada().getCodigoPostal() == cp) {
                designacao = ita.retrieve().getDesignacao();
                localizacao = ita.retrieve().getLocalizacao();
                return (*it);
            }
        }
        ita.advance();
    }
    throw Habitacao_Nao_Encontrada(cp);
}

Condomino* CondomiX::Procurar_Condomino(string nif, string &designacao, string &localizacao) const {
    vector<Condomino *>::const_iterator it;
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        vector<Condomino *> vetor = ita.retrieve().getCondominos();
        for (it = vetor.begin(); it != vetor.end(); it++) {
            if ((*it)->getNif() == nif) {
                designacao = ita.retrieve().getDesignacao();
                localizacao = ita.retrieve().getLocalizacao();
                return (*it);
            }
        }
        ita.advance();
    }
    throw Condomino_Nao_Encontrado(nif);
}

AntigoCondomino* CondomiX::Procurar_Antigo_Condomino(string nif, string &designacao, string &localizacao) const {
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        HashTabAntigoClienteRecord ant_cond = ita.retrieve().getAntigosCondominos();
        HashTabAntigoClienteRecord::const_iterator it = ant_cond.begin();
        while (it != ant_cond.end()) {
            if ((*it).getNIF() == nif) {
                designacao = ita.retrieve().getDesignacao();
                localizacao = ita.retrieve().getLocalizacao();
                return (*it).getAntigoCondominoPointer();
            }
            it++;
        }
        ita.advance();
    }
    throw Condomino_Nao_Encontrado(nif);
}

void CondomiX::Mostrar_Servicos() const
{
    vector<Servico *>::const_iterator it;
    for (it = servicos.begin() ; it != servicos.end() ; it++)
        cout << "[" << (*it)->getId() << "] " << (*it)->getDescricao() << endl;
}

void CondomiX::Mostrar_Prestadores() const {
    vector<PrestadorServicoLimpeza *>::const_iterator it;
    int counter = 1;
    for (it = prestadoresServicoLimpeza.begin() ; it != prestadoresServicoLimpeza.end() ; it++) {
        cout << "\tNome: " << (*it)->getNome() << " Horas: " << (*it)->getTotalHoras()<< endl;
        counter++;
    }
}

void CondomiX::Mostrar_Servicos_e_Prestadores() const{
    vector<Servico *>::const_iterator it;
    for (it = servicos.begin(); it != servicos.end(); it++) {
        cout << "[" << (*it)->getId() << "] " << (*it)->getDescricao() << endl;
        if ((*it)->getDescricao() == "Servico de Limpeza") Mostrar_Prestadores();
    }
}

void CondomiX::Mostrar_Condominios() const {
    int count = 1;
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        Condominio cond = ita.retrieve();
        cout << "[" << count << "] " << cond.getDesignacao() << " - " << cond.getLocalizacao() << endl;
        count++;
        ita.advance();
    }
}

void CondomiX::Ler_Servicos(const string &ficheiro)
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

void CondomiX::Ler_Prestadores(const string &ficheiro)
{
    prestadoresServicoLimpeza.clear();
    ifstream ler;
    string nome, separacao;
    float horas;
    try{
        ler.open(ficheiro);
    }
    catch (Erro_Ler(&ficheiro)){
        cout << "Erro a Ler Prestadores\n";
        exit(1);
    }
    while (!ler.eof())
    {
        getline(ler, nome);
        ler >> horas;
        ler.ignore(1000,'\n');
        getline(ler, separacao);
        PrestadorServicoLimpeza *prestador = new PrestadorServicoLimpeza(nome,horas);
        prestadoresServicoLimpeza.push_back(prestador);
    }
    ler.close();
}

void CondomiX::Ler_Servicos_Efetuados(const string &ficheiro)
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

void CondomiX::Ler_Habitacoes(const string &ficheiro)
{
    ifstream ler;
    string designacao, localizacao, end ,cid ,cp, tipo_habitacao, separacao, temp;
    float area_habitacional;
    try{
        ler.open(ficheiro);
    }
    catch (Erro_Ler(&ficheiro)){
        cout << "Erro a Ler Habitacoes\n";
        exit(1);
    }
    condominios.makeEmpty();
    do{
        getline(ler, designacao);
        getline(ler, localizacao);
        Condominio cond(designacao, localizacao);
        while(end != "--------------------")
        {
            getline(ler, temp);
            if (temp == "--------------------")
            {
                end = temp;
            }
            else
            {
                end = temp;
                getline(ler, cid);
                getline(ler, cp);
                Morada *morada = new Morada(end, cid, cp);
                ler >> area_habitacional;
                ler.ignore(1000, '\n');
                getline(ler, tipo_habitacao);
                if (tipo_habitacao == "Vivenda") {
                    float area_exterior;
                    bool com_piscina;
                    ler >> area_exterior;
                    ler.ignore(1000, '\n');
                    ler >> com_piscina;
                    ler.ignore(1000, '\n');
                    getline(ler, separacao);
                    Habitacao *vivenda = new Vivenda(area_habitacional, *morada, area_exterior, com_piscina);
                    cond.adicionaHabitacao(vivenda);
                }
                else {
                    string tipologia;
                    int piso;
                    getline(ler, tipologia);
                    ler >> piso;
                    ler.ignore(1000, '\n');
                    getline(ler, separacao);
                    Habitacao *apartamento = new Apartamento(area_habitacional, *morada, tipologia, piso);
                    cond.adicionaHabitacao(apartamento);
                }
            }
        }
        adicionaCondominio(cond);
        end = "";
    } while (!ler.eof());
    ler.close();
}

void CondomiX::Ler_Condominos(const string &ficheiro)
{
    ifstream ler;
    string designacao, localizacao, nome, nif, cp, serv, custo, horas, nome_prestador, total_horas, design_temp, local_temp, dia, mes, ano;
    try{
        ler.open(ficheiro);
    }
    catch (Erro_Ler(&ficheiro)){
        cout << "Erro a Ler Condominos\n";
        exit(1);
    }
    do {
        getline(ler, designacao);
        getline(ler, localizacao);
        Condominio cond(designacao, localizacao);
        BSTItrIn<Condominio> it(condominios);
        while(!it.isAtEnd())
        {
            if(it.retrieve().getDesignacao() == designacao){
                Condominio cond = it.retrieve();
                vector<Condomino *> clear;
                cond.setCondominos(clear);
                do
                {
                    getline(ler, nome);
                    if(nome == "--------------------")
                        break;
                    getline(ler, nif);
                    Condomino *condomino = new Condomino(nome, nif);
                    getline(ler, dia);
                    getline(ler, mes);
                    getline(ler, ano);
                    time_t now = time(NULL);
                    struct tm Data = *localtime(&now);
                    Data.tm_hour = 0;
                    Data.tm_min = 0;
                    Data.tm_sec = 0;
                    Data.tm_mon = stoi(mes)-1;
                    Data.tm_mday = stoi(dia);
                    Data.tm_year = stoi(ano) - 1900;
                    condomino->setDataEntrada(Data);
                    getline(ler, cp);
                    while (cp != "-----") {
                        try {
                            Habitacao *habitacao = Procurar_Habitacao(cp, design_temp, local_temp);
                            condomino->adicionaHabitacao(habitacao);
                            getline(ler, cp);
                        }
                        catch (Habitacao_Nao_Encontrada(&cp)) {
                            cout << "\nHabitacao Nao Encontrada! \n";
                        }
                    }
                    getline(ler, serv);
                    while (serv != "----------" && serv != "--------------------") {
                        if (serv == "Servico de Limpeza") {
                            getline(ler, custo);
                            getline(ler, horas);
                            getline(ler, nome_prestador);
                            getline(ler, total_horas);
                            Servico *servico = new ServicoLimpeza(1, serv, stof(custo), stof(horas));
                            ((ServicoLimpeza *) servico)->setPrestador(
                                    new PrestadorServicoLimpeza(nome_prestador, stof(total_horas)));
                            condomino->adicionaServico(servico);
                        } else {
                            getline(ler, custo);
                            Servico *servico = new Servico(serv, stof(custo));
                            condomino->adicionaServico(servico);
                        }
                        getline(ler, serv);
                    }
                    cond.adicionaCondomino(condomino);
                } while(serv != "--------------------");
                removeCondominioPorDesignacao(designacao);
                adicionaCondominio(cond);
                break;
            }
            it.advance();
        }
    } while (!ler.eof());
    ler.close();
}

void CondomiX::Ler_Antigos_Condominos(const string &ficheiro) {
    ifstream ler;
    string designacao, localizacao, nome, nif, periodo, separacao, temp;
    int contador = 0;
    try{
        ler.open(ficheiro);
    }
    catch (Erro_Ler(&ficheiro)) {
        cout << "Erro a Ler Antigos Condominos\n";
        exit(1);
    }
    do{
        getline(ler,designacao);
        getline(ler, localizacao);
        getline(ler, temp);
        if (temp == "--------------------") {
            continue;
        }
        Condominio cond(designacao,localizacao);
        BSTItrIn<Condominio> ita(condominios);
        while (!ita.isAtEnd()) {
            if (ita.retrieve().getDesignacao() == designacao) {
                Condominio cond = ita.retrieve();
                contador = 0;
                removeCondominioPorDesignacao(designacao);
                do {
                    if (contador == 0)
                        nome = temp;
                    else
                        getline(ler, nome);
                    getline(ler, nif);
                    getline(ler, periodo);
                    getline(ler, separacao);
                    AntigoCondomino *ant_cond = new AntigoCondomino(nome, nif, stoi(periodo));
                    cond.adicionaAntigoCondomino(ant_cond);
                    contador++;
                } while (separacao != "--------------------");
                adicionaCondominio(cond);
                break;
            }
            ita.advance();
        }
    } while (!ler.eof());
    ler.close();
}

void CondomiX::Ler_Transportes(const string &ficheiro) {
    ifstream ler;
    string designacao, localizacao, tipo, destino, paragem_proxima, separacao, temp;
    int distancia, contador;
    try{
        ler.open(ficheiro);
    }
    catch (Erro_Ler(&ficheiro)) {
        cout << "Erro a Ler Transportes\n";
        exit(1);
    }
    do{
        getline(ler,designacao);
        getline(ler, localizacao);
        getline(ler, temp);
        if (temp == "--------------------") {
            continue;
        }
        Condominio cond(designacao,localizacao);
        BSTItrIn<Condominio> ita(condominios);
        while (!ita.isAtEnd()) {
            if (ita.retrieve().getDesignacao() == designacao) {
                contador = 0;
                Condominio cond = ita.retrieve();
                vector<Transporte *> clear;
                cond.setTransportes(clear);
                do {
                    if (contador == 0)
                        tipo = temp;
                    else
                        getline(ler, tipo);
                    getline(ler, destino);
                    getline(ler, paragem_proxima);
                    ler >> distancia;
                    ler.ignore(1000, '\n');
                    getline(ler, separacao);
                    Transporte * transporte = new Transporte(tipo, destino, paragem_proxima, distancia);
                    cond.adicionaTransporte(transporte);
                    contador++;
                } while (separacao != "--------------------");
                removeCondominioPorDesignacao(designacao);
                adicionaCondominio(cond);
                break;
            }
            ita.advance();
        }
    } while (!ler.eof());
    ler.close();
}

void CondomiX::Escrever_Servicos(const string &ficheiro)
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

void CondomiX::Escrever_Prestadores(const string &ficheiro)
{
    ofstream escrever;
    int contador = 1;
    vector<PrestadorServicoLimpeza *>::const_iterator it;
    try{
        escrever.open(ficheiro);
    }
    catch (Erro_Escrita(&ficheiro)){
        cout << "Erro a Escrever Prestadores\n";
        exit(1);
    }
    for (it = prestadoresServicoLimpeza.begin() ; it != prestadoresServicoLimpeza.end() ; it++)
    {
        if (contador == prestadoresServicoLimpeza.size())
            escrever << (*it)->getNome() << endl << (*it)->getTotalHoras() << endl << "----------";
        else
            escrever << (*it)->getNome() << endl << (*it)->getTotalHoras() << endl << "----------" << endl;
        contador++;
    }
    escrever.close();
}

void CondomiX::Escrever_Servicos_Efetuados(const string &ficheiro)
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

void CondomiX::Escrever_Habitacoes(const string &ficheiro)
{
    ofstream escrever;
    bool inicio = true;
    BSTItrIn<Condominio> ita(condominios);
    vector<Habitacao *>::const_iterator it;
    try{
        escrever.open(ficheiro);
    }
    catch (Erro_Escrita(&ficheiro)){
        cout << "Erro a Escrever Habitacoes\n";
        exit(1);
    }
    while (!ita.isAtEnd()) {
        vector<Habitacao *> habitacoes = ita.retrieve().getHabitacoes();
        if (inicio) {
            escrever << ita.retrieve().getDesignacao() << endl << ita.retrieve().getLocalizacao() << endl;
            inicio = false;
        }
        else
            escrever << endl << ita.retrieve().getDesignacao() << endl << ita.retrieve().getLocalizacao() << endl;
        for (it = habitacoes.begin(); it != habitacoes.end(); it++) {
            if (it == habitacoes.begin())
                (*it)->escrever_habitacao(escrever);
            else {
                escrever << endl;
                (*it)->escrever_habitacao(escrever);
            }
        }
        if(habitacoes.size() != 0)
            escrever << endl << "--------------------";
        else
            escrever << "--------------------";
        ita.advance();
    }
    escrever.close();
}

void CondomiX::Escrever_Condominos(const string &ficheiro)
{
    ofstream escrever;
    bool inicial = true;
    BSTItrIn<Condominio> ita(condominios);
    vector<Condomino *>::const_iterator itc;
    vector<Habitacao *>::const_iterator ith;
    vector<Servico *>::const_iterator its;
    try {
        escrever.open(ficheiro);
    }
    catch (Erro_Escrita(&ficheiro)) {
        cout << "Erro a Escrever Condominos\n";
        exit(1);
    }
    while (!ita.isAtEnd()) {
        if (inicial) {
            if(ita.retrieve().numeroCondominos() == 0)
                escrever << ita.retrieve().getDesignacao() << endl << ita.retrieve().getLocalizacao();
            else
                escrever << ita.retrieve().getDesignacao() << endl << ita.retrieve().getLocalizacao() << endl;
            inicial = false;
        }
        else
            if(ita.retrieve().numeroCondominos() == 0)
                escrever << endl << "--------------------" << endl << ita.retrieve().getDesignacao() << endl << ita.retrieve().getLocalizacao();
            else
                escrever << endl << "--------------------" << endl << ita.retrieve().getDesignacao() << endl << ita.retrieve().getLocalizacao() << endl;
        vector<Condomino *> condominos = ita.retrieve().getCondominos();
        for (itc = condominos.begin(); itc != condominos.end(); itc++) {
            if (itc == condominos.begin())
                escrever << (*itc)->getNome() << endl << (*itc)->getNif() << endl;
            else
                escrever << endl << (*itc)->getNome() << endl << (*itc)->getNif() << endl;
            escrever << (*itc)->getDataEntrada().tm_mday << endl << (*itc)->getDataEntrada().tm_mon + 1 << endl << (*itc)->getDataEntrada().tm_year + 1900 << endl;
            vector<Habitacao *> vetor_h = (*itc)->getHabitacoes();
            for (ith = vetor_h.begin(); ith != vetor_h.end(); ith++) {
                escrever << (*ith)->getMorada().getCodigoPostal() << endl;
            }
            escrever << "-----" << endl;
            vector<Servico *> vetor_s = (*itc)->getServicos();
            for (its = vetor_s.begin(); its != vetor_s.end(); its++) {
                if ((*its)->getDescricao() == "Servico de Limpeza") {
                    escrever << (*its)->getDescricao() << endl << (*its)->getCusto() << endl;
                    escrever << ((ServicoLimpeza *) (*its))->getDuracao() << endl
                             << ((ServicoLimpeza *) (*its))->getPrestador().getNome() << endl
                             << ((ServicoLimpeza *) (*its))->getPrestador().getTotalHoras() << endl;
                } else
                    escrever << (*its)->getDescricao() << endl << (*its)->getCusto() << endl;
            }
            escrever << "----------";
        }
        ita.advance();
    }
    escrever << endl << "--------------------";
    escrever.close();
}

void CondomiX::Escrever_Antigos_Condominos(const string &ficheiro) {
    ofstream escrever;
    bool inicio = true;
    BSTItrIn<Condominio> ita(condominios);
    try{
        escrever.open(ficheiro);
    }
    catch (Erro_Escrita(&ficheiro)){
        cout << "Erro a Escrever Antigos Condominos\n";
        exit(1);
    }
    while (!ita.isAtEnd()) {
        Condominio cond = ita.retrieve();
        if (inicio) {
            escrever << cond.getDesignacao() << endl << cond.getLocalizacao() << endl;
            inicio = false;
        }
        else {
            escrever << endl << cond.getDesignacao() << endl << cond.getLocalizacao() << endl;
        }
        HashTabAntigoClienteRecord ant_cond = cond.getAntigosCondominos();
        if (ant_cond.size() == 0) {
            escrever << "--------------------";
            ita.advance();
            continue;
        }
        HashTabAntigoClienteRecord::const_iterator it = ant_cond.begin();
        int contador = 1;
        while (it != ant_cond.end()) {
            if (ant_cond.size() == 1) {
                escrever << (*it).getName() << endl << (*it).getNIF() << endl << (*it).getAntigoCondominoPointer()->getPeriodo() << endl << "--------------------";
            }
            else if (contador == 1) {
                escrever << (*it).getName() << endl << (*it).getNIF() << endl << (*it).getAntigoCondominoPointer()->getPeriodo() << endl << "----------";
            }
            else if (contador == ant_cond.size()) {
                escrever << endl << (*it).getName() << endl << (*it).getNIF() << endl << (*it).getAntigoCondominoPointer()->getPeriodo() << endl << "--------------------";
            }
            else {
                escrever << endl << (*it).getName() << endl << (*it).getNIF() << endl << (*it).getAntigoCondominoPointer()->getPeriodo() << endl << "----------";
            }
            contador++;
            it++;
        }
        ita.advance();
    }
}

void CondomiX::Escrever_Transportes(const string &ficheiro) {
    ofstream escrever;
    bool inicio = true;
    vector<Transporte*> aux;
    BSTItrIn<Condominio> ita(condominios);
    try{
        escrever.open(ficheiro);
    }
    catch (Erro_Escrita(&ficheiro)){
        cout << "Erro a Escrever Transportes\n";
        exit(1);
    }

    while (!ita.isAtEnd()) {
        priority_queue<Transporte *, vector<Transporte*>, TransportesCmp> transportes = ita.retrieve().getTransportes();
        vector<Transporte*> aux;
        while(!transportes.empty())
        {
            aux.push_back(transportes.top());
            transportes.pop();
        }
        vector<Transporte*>::const_reverse_iterator it;
        vector<Transporte*>::const_iterator itt;
        for(it = aux.rbegin(); it != aux.rend(); it++)
        {
            transportes.push(*it);
        }

        if (inicio) {
            escrever << ita.retrieve().getDesignacao() << endl << ita.retrieve().getLocalizacao() << endl;
            inicio = false;
        }
        else
            escrever << endl << ita.retrieve().getDesignacao() << endl << ita.retrieve().getLocalizacao() << endl;
        for (itt = aux.begin(); itt != aux.end(); itt++) {
            if (itt == aux.begin())
            {
                escrever << (*itt)->getTipo() << endl;
                escrever << (*itt)->getDestino() << endl;
                escrever << (*itt)->getParagemProxima()  << endl;
                escrever << (*itt)->getDistancia();
            }
            else {
                escrever << endl;
                escrever << "----------" << endl;
                escrever << (*itt)->getTipo() << endl;
                escrever << (*itt)->getDestino() << endl;
                escrever << (*itt)->getParagemProxima()  << endl;
                escrever << (*itt)->getDistancia();
            }
        }
        if(aux.size() != 0)
            escrever << endl << "--------------------";
        else
            escrever << "--------------------";
        ita.advance();
    }
}

PrestadorServicoLimpeza *CondomiX::procurarPrestadorServicoLimpeza() const {
    vector<PrestadorServicoLimpeza *>::const_iterator it = prestadoresServicoLimpeza.begin();
    PrestadorServicoLimpeza * menorPsl = (*it);
    it++;
    while (it != prestadoresServicoLimpeza.end()) {
        PrestadorServicoLimpeza * psl1 = (*it);
        if (psl1->getTotalHoras() < menorPsl->getTotalHoras()) menorPsl = psl1;
        it++;
    }
    return menorPsl;
}
