#include "CondomiX.h"
#include "Excecoes.h"
#include <fstream>

/*PrestadorServicoLimpeza* prestador1 = new PrestadorServicoLimpeza("Sr Antonio",0);
PrestadorServicoLimpeza* prestador2 = new PrestadorServicoLimpeza("Sr Benedito",0);
PrestadorServicoLimpeza* prestador3 = new PrestadorServicoLimpeza("Sr Carlos",0);
PrestadorServicoLimpeza* prestador4 = new PrestadorServicoLimpeza("Sr Dinis",0);
PrestadorServicoLimpeza* prestador5 = new PrestadorServicoLimpeza("Sr Eugenio",0);

vector<PrestadorServicoLimpeza *> CondomiX::prestadoresServicoLimpeza = {prestador1, prestador2, prestador3, prestador4, prestador5};*/

vector<PrestadorServicoLimpeza *>  CondomiX::getPrestadores() {
    return prestadoresServicoLimpeza;
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

/*PrestadorServicoLimpeza* CondomiX::procurarPrestadorServicoLimpeza() const {
    vector<PrestadorServicoLimpeza *>::const_iterator it = prestadoresServicoLimpeza.begin();
    PrestadorServicoLimpeza * menorPsl = (*it);
    it++;
    while (it != prestadoresServicoLimpeza.end()) {
        PrestadorServicoLimpeza * psl1 = (*it);
        if (psl1 < menorPsl) menorPsl = psl1;
        it++;
    }
    return menorPsl;
}*/

void CondomiX::Mostrar_Prestadores() const {
    vector<PrestadorServicoLimpeza *>::const_iterator it;
    int counter = 1;
    for (it = prestadoresServicoLimpeza.begin() ; it != prestadoresServicoLimpeza.end() ; it++) {
        cout << "\tNome: " << (*it)->getNome() << " Horas: " << (*it)->getTotalHoras()<< endl;
        counter++;
    }
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
