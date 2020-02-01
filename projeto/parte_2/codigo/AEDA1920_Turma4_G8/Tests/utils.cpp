#include <iostream>

#include "utils.h"
#include "Excecoes.h"
#include "CondomiX.h"
#include "PedidoPrestacaoServico.h"
#include <time.h>

using namespace std;

void Menu_Adicionar_Habitacao();
void Menu_Principal();

// Funcoes Uteis

void Logotipo()
{
    cout <<  "   ____                _                 ___  __\n";
    cout << "  / ___|___  _ __   __| | ___  _ __ ___ (_) \\/ /\n";
    cout << " | |   / _ \\| '_ \\ / _` |/ _ \\| '_ ` _ \\| |\\  / \n";
    cout << " | |__| (_) | | | | (_| | (_) | | | | | | |/  \\ \n";
    cout <<"  \\____\\___/|_| |_|\\__,_|\\___/|_| |_| |_|_/_/\\_\\";
}

char Sair_Programa()
{
    char sair;
    cout << "Sair do Programa? (S/N)\n\n";
    do{
        cout << "R: ";
        cin >> sair;
    } while(sair != 'N' && sair != 'n' && sair != 'S' && sair != 's');
    return sair;
}

bool existeDesignacao(CondomiX &gestao, string designacao)
{
    BSTItrIn<Condominio> it(gestao.getCondominios());
    while(!it.isAtEnd())
    {
        if(it.retrieve().getDesignacao() == designacao)
            return true;
        it.advance();
    }
    return false;
}

bool existe_cp(Condominio &condominio, const string &cp)
{
    vector<Habitacao *> habitacoes = condominio.getHabitacoes();
    vector<Habitacao *>::const_iterator it;
    for (it = habitacoes.begin() ; it != habitacoes.end() ; it++) {
        if ((*it)->getMorada().getCodigoPostal() == cp)
            return true;
    }
    return false;
}

bool existe_nif(CondomiX &gestao, const string &nif)
{
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        Condominio cond = ita.retrieve();
        vector<Condomino *> condominos = cond.getCondominos();
        vector<Condomino *>::const_iterator it;
        for (it = condominos.begin() ; it != condominos.end() ; it++) {
            if ((*it)->getNif() == nif)
                return true;
        }
        ita.advance();
    }
    return false;
}

// Funcoes Principais

void Visualizar_Todos_Condominios(CondomiX &gestao) {
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de Todos os Condominios \n\n";
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    gestao.Ler_Antigos_Condominos("AntigosCondominos.txt");
    gestao.Ler_Transportes("Transportes.txt");
    BST<Condominio> arvore = gestao.getCondominios();
    BSTItrIn<Condominio> ita(arvore);
    while (!ita.isAtEnd()) {
        Condominio cond = ita.retrieve();
        cout << cond.escreveInformacoes();
        cout << "\n\n ---------- \n" << endl;
        ita.advance();
    }
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Visualizar_Condominio_Numero_Habitacoes(CondomiX &gestao) {
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de Condominios com um dado numero maximo de Habitacoes \n\n";
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    gestao.Ler_Antigos_Condominos("AntigosCondominos.txt");
    gestao.Ler_Transportes("Transportes.txt");
    int numero;
    bool encontrou = false;
    while (!encontrou)
    {
        try {
            cout << "\nNumero maximo de Habitacoes dos Condominios a procurar: ";
            cin.clear();
            cin >> numero;
            cin.ignore(1000,'\n');
            vector<Condominio> vetor = gestao.getCondominiosPorHabitacoes(numero);
            if (vetor.empty()) {
                throw Condominio_Nao_Encontrado(numero);
            }
            cout << endl;
            for (unsigned int i = 0 ; i < vetor.size() ; i++) {
                cout << vetor[i].escreveInformacoes();
                cout << "\n\n ---------- \n" << endl;
            }
            encontrou = true;
        }
        catch (Condominio_Nao_Encontrado(numero)) {
            cout << "\nCondominios Nao Encontrados! \n";
        }
    }
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Visualizar_Todas_Habitacoes (CondomiX &gestao)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de Todas as Habitacoes (Ordem Decrescente de Area Habitacional) \n\n";
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        Condominio condominio = ita.retrieve();
        cout << "Condominio: " << condominio.getDesignacao() << " - " << condominio.getLocalizacao() << " (" << condominio.numeroHabitacoes() << " habitacoes, " << condominio.numeroCondominos() << " condominos)"<< endl << endl;
        condominio.ordenaHabitacoesPorAreaHabitacional();
        cout << condominio.escreveTotalHabitacoes();
        ita.advance();
    }
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Visualizar_Habitacao_Morada(CondomiX &gestao)
{
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de uma Habitacao pela Morada \n\n";
    string cp, designacao, localizacao;
    bool encontrou = false;
    cin.ignore(1000,'\n');
    while (!encontrou)
    {
        try {
            cout << "\nCodigo-postal da Habitacao a procurar: ";
            getline(cin, cp);
            Habitacao *habit = gestao.Procurar_Habitacao(cp, designacao, localizacao);
            Condominio cond = gestao.getCondominioPorDesignacao(designacao);
            cout << "\n ---------- \n" << endl;
            cout << "Condominio: " << designacao << " - " << localizacao << " (" << cond.numeroHabitacoes() << " habitacoes, " << cond.numeroCondominos() << " condominos)"<< endl << endl;
            cout << habit->info();
            cout << " ---------- \n" << endl;
            encontrou = true;
        }
        catch (Habitacao_Nao_Encontrada(&cp)) {
            cout << "\nHabitacao Nao Encontrada! \n";
        }
    }
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Visualizar_Todos_Condominos (CondomiX &gestao)
{

    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de Todos os Condominos (Ordem Crescente do Nome) \n\n";
    gestao.Ler_Servicos("Servicos.txt");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        Condominio condominio = ita.retrieve();
        cout << "Condominio: " << condominio.getDesignacao() << " - " << condominio.getLocalizacao() << " (" << condominio.numeroHabitacoes() << " habitacoes, " << condominio.numeroCondominos() << " condominos)"<< endl << endl;
        condominio.ordenaCondominosPorNome();
        cout << condominio.escreveTotalCondominos();
        ita.advance();
    }
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Visualizar_Condominos_NIF(CondomiX &gestao)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de um Condomino pelo NIF \n\n";
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Servicos("Servicos.txt");
    gestao.Ler_Condominos("Condominos.txt");
    string nif, designacao, localizacao;
    bool encontrou = false;
    while (!encontrou)
    {
        try {
            cout << "\nNIF do Condomino a procurar: ";
            getline(cin, nif);
            Condomino* cond = gestao.Procurar_Condomino(nif, designacao, localizacao);
            Condominio condominio = gestao.getCondominioPorDesignacao(designacao);
            cout << "\n ---------- \n" << endl;
            cout << "Condominio: " << designacao << " - " << localizacao << " (" << condominio.numeroHabitacoes() << " habitacoes, " << condominio.numeroCondominos() << " condominos)"<< endl << endl;
            cout << cond->info();
            cout << "\n ---------- \n" << endl;
            encontrou = true;
        }
        catch (Condomino_Nao_Encontrado(&nif)) {
            cout << "\nCondomino Nao Encontrado! \n";
        }
    }
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Visualizar_Todos_Antigos_Condominos (CondomiX &gestao) {
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de Todos os Antigos Condominos \n\n";
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    gestao.Ler_Antigos_Condominos("AntigosCondominos.txt");
    cout << gestao.escreveTotalAntigosCondominos();
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Visualizar_Antigos_Condominos_NIF(CondomiX &gestao) {
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de um Antigo Condomino pelo NIF \n\n";
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    gestao.Ler_Antigos_Condominos("AntigosCondominos.txt");
    cin.ignore(1000,'\n');
    string nif, designacao, localizacao;
    bool encontrou = false;
    while (!encontrou)
    {
        try {
            cout << "\nNIF do Antigo Condomino a procurar: ";
            getline(cin, nif);
            AntigoCondomino* ant_cond = gestao.Procurar_Antigo_Condomino(nif, designacao, localizacao);
            Condominio cond = gestao.getCondominioPorDesignacao(designacao);
            cout << "\n ---------- \n" << endl;
            cout << "Condominio: " << designacao << " - " << localizacao << " (" << cond.numeroHabitacoes() << " habitacoes, " << cond.numeroCondominos() << " condominos)"<< endl << endl;
            cout << ant_cond->info();
            cout << "\n ---------- \n" << endl;
            encontrou = true;
        }
        catch (Condomino_Nao_Encontrado(&nif)) {
            cout << "\nAntigo Condomino Nao Encontrado! \n";
        }
    }
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Visualizar_Servicos(Condominio &condominio, CondomiX &gestao)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de Servicos \n\n";
    gestao.Ler_Servicos("Servicos.txt");
    cout << gestao.escreveTotalServicos();
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Visualizar_Prestadores(Condominio &condominio, CondomiX &gestao)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de Prestadores \n\n";
    gestao.Ler_Prestadores("Prestadores.txt");
    vector<PrestadorServicoLimpeza *>::const_iterator it;
    vector<PrestadorServicoLimpeza *> vetor = gestao.getPrestadores();
    for (it = vetor.begin() ; it != vetor.end() ; it++)
        cout << (*it)->info() << endl;
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Adicionar_Habitacao(CondomiX &gestao)
{
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    char opcao;
    string area_habitacional,e ,c ,cp, tipologia, area_ext, piscina, piso_s, tipo;
    float areaExterior, ah;
    bool comPiscina;
    int piso, cond_id, contador = 1;
    gestao.Mostrar_Condominios();
    do {
        cout << "\nCondominio a que a Habitacao vai pertencer: ";
        cin >> cond_id;
        cin.ignore(1000, '\n');
    } while (cond_id < 1 || cond_id > gestao.numeroCondominios());
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        if (contador == cond_id) {
            Condominio cond = ita.retrieve();
            cout << "\n\t\t     Tipo de Habitacao \n\n";
            cout << "[1] Vivenda \n";
            cout << "[2] Apartamento \n";
            cout << "\nOpcao: ";
            string name;
            cin >> name;
            if(name.size() == 1) opcao = name[0];
            else opcao = '9';
            cin.ignore(1000,'\n');
            do
            {
                cout << "\nEndereco: ";
                getline(cin, e);
                if (e.find_first_not_of(alphabetplusnum + "-.") != string::npos || e == "")
                    cout << "Invalid input" << endl;
            } while (e.find_first_not_of(alphabetplusnum +"-.") != string::npos|| e == "");

            do
            {
                cout << "\nCidade: ";
                getline(cin, c);
                if (c.find_first_not_of(alphabet+"-") != string::npos || c == "")
                    cout << "Invalid input" << endl;
            } while (c.find_first_not_of(alphabet+"-") != string::npos|| c == "");

            do
            {
                try {
                    cout << "\nCodigo Postal: ";
                    getline(cin, cp);
                    if (cp.find_first_not_of("1234567890-\n") != string::npos || cp == "")
                        cout << "Invalid input" << endl;
                    if (existe_cp(cond, cp))
                        throw CP_Ja_Existente(cp);
                }
                catch (CP_Ja_Existente(&cp)) {
                    cout << "\nCodigo-Postal Ja Existente!\n";
                }
            } while (cp.find_first_not_of("1234567890-\n") != string::npos || cp == "" || existe_cp(cond,cp));

            Morada *morada = new Morada(e, c, cp);
            do
            {
                cout << "\nArea Habitacional: ";
                cin >> area_habitacional;
                if (area_habitacional.find_first_not_of("1234567890.\n") != string::npos || area_habitacional == "")
                    cout << "Invalid input" << endl;
            } while (area_habitacional.find_first_not_of("1234567890.\n") != string::npos || area_habitacional == "");
            ah = stof(area_habitacional);
            cin.ignore(1000, '\n');
            switch(opcao)
            {
                case '1':
                {
                    tipo = "Vivenda";
                    do
                    {
                        cout << "\nArea Exterior: ";
                        cin >> area_ext;
                        if (area_ext.find_first_not_of("1234567890.\n") != string::npos || area_ext == "")
                            cout << "Invalid input" << endl;
                    } while (area_ext.find_first_not_of("1234567890.\n") != string::npos || area_ext == "");
                    areaExterior = stof(area_ext);
                    cin.ignore(1000, '\n');
                    do {
                        cout << "\nCom Piscina? [S/N]: ";
                        getline(cin, piscina);
                        if (piscina == "S" || piscina == "s") comPiscina = true;
                        else if (piscina == "N" || piscina == "n") comPiscina = false;
                    } while (piscina != "N" && piscina != "n" && piscina != "S" && piscina != "s");
                    Habitacao *vivenda = new Vivenda(ah,*morada, areaExterior,comPiscina);
                    cond.adicionaHabitacao(vivenda);
                    cout << "\n\nVivenda Adicionada!\n\n";
                    break;
                }
                case '2':
                {
                    tipo = "Apartamento";
                    do
                    {
                        cout << "\nTipologia: ";
                        getline(cin, tipologia);
                        if (tipologia.find_first_not_of(alphabetplusnum) != string::npos || tipologia == "")
                            cout << "Invalid input" << endl;
                    } while (tipologia.find_first_not_of(alphabetplusnum) != string::npos|| tipologia == "");

                    do
                    {
                        cout << "\nPiso: ";
                        cin >> piso_s;
                        if (piso_s.find_first_not_of("1234567890\n") != string::npos)
                            cout << "Invalid input" << endl;
                    } while (piso_s.find_first_not_of("1234567890\n") != string::npos);
                    piso = stoi(piso_s);
                    cin.ignore(1000, '\n');
                    Habitacao *apartamento = new Apartamento(ah, *morada, tipologia, piso);
                    cond.adicionaHabitacao(apartamento);
                    cout << "\n\nApartamento Adicionado!\n\n";
                    break;
                }
                default:
                    Menu_Adicionar_Habitacao(); break;
            }
            gestao.removeCondominioPorDesignacao(cond.getDesignacao());
            gestao.adicionaCondominio(cond);
            break;
        }
        contador++;
        ita.advance();
    }

}

void Editar_Habitacao(CondomiX &gestao)
{
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    string tipo;
    int id, tp, cond_id, contador = 1;
    gestao.Mostrar_Condominios();
    do {
        cout << "\nCondominio da Habitacao a editar: ";
        cin >> cond_id;
        cin.ignore(1000, '\n');
    } while (cond_id < 1 || cond_id > gestao.numeroCondominios());
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        if (contador == cond_id) {
            Condominio cond = ita.retrieve();
            vector<Habitacao *> vetor = cond.getHabitacoes();
            if (vetor.empty()) {
                cout << "\nEste Condominio nao possui Habitacoes!\n\n";
                return;
            }
            cout << endl;
            cond.Mostrar_Habitacoes();
            cout << "\nHabitacao a alterar: ";
            do {
                cin.clear();
                cin >> id;
                cin.ignore(1000, '\n');
            }while(id < 1 || id >cond.numeroHabitacoes());
            cout << "\n A alterar habitacao numero " << id << "... " << endl << endl;

            for(int i = 0; i < cond.numeroHabitacoes(); i++)
            {
                if(i == (id-1))
                {
                    string areaHabitacional;
                    float ah;
                    string e, c, cp;
                    do
                    {
                        cout << "\nNova Area Habitacional: ";
                        cin >> areaHabitacional;
                        if (areaHabitacional.find_first_not_of("1234567890.\n") != string::npos || areaHabitacional =="")
                            cout << "Invalid input" << endl;
                    } while (areaHabitacional.find_first_not_of("1234567890.\n") != string::npos || areaHabitacional =="");
                    ah = stof(areaHabitacional);
                    cin.ignore(1000, '\n');
                    do
                    {
                        cout << "\nNovo Endereco: ";
                        getline(cin, e);
                        if (e.find_first_not_of(alphabetplusnum+"-.") != string::npos || e == "")
                            cout << "Invalid input" << endl;
                    } while (e.find_first_not_of(alphabetplusnum+"-.") != string::npos|| e == "");
                    do
                    {
                        cout << "\nNova Cidade: ";
                        getline(cin, c);
                        if (c.find_first_not_of(alphabetplusnum+"-") != string::npos || c == "")
                            cout << "Invalid input" << endl;
                    } while (c.find_first_not_of(alphabetplusnum+"-") != string::npos|| c == "");

                    do
                    {
                        cout << "\nNovo Codigo Postal: ";
                        getline(cin, cp);
                        if (cp.find_first_not_of("1234567890-\n") != string::npos || cp == "")
                            cout << "Invalid input" << endl;
                    } while (cp.find_first_not_of("1234567890-\n") != string::npos || cp == "");
                    Morada *morada = new Morada(e,c, cp);
                    vetor[i]->setMorada(*morada);
                    vetor[i]->setAreaHabitacional(ah);
                    cout << "\nTipo da Habitacao: \n";
                    cout <<  "\n[1] Vivenda";
                    cout << "\n[2] Apartamento";
                    do {
                        cout << "\n\nOpcao: ";
                        cin >> tp;
                        cin.ignore(1000,'\n');
                    } while (tp != 1 && tp != 2);
                    if (tp == 1) tipo = "Vivenda";
                    if (tp == 2) tipo = "Apartamento";
                    if(tipo == "Vivenda")
                    {
                        string ae;
                        float areaExterior;
                        char piscina;
                        bool comPiscina;
                        do
                        {
                            cout << "\nNova Area Exterior: ";
                            cin >> ae;
                            if (ae.find_first_not_of("1234567890.\n") != string::npos)
                                cout << "Invalid input" << endl;
                        } while (ae.find_first_not_of("1234567890.\n") != string::npos);
                        areaExterior = stof(ae);
                        cin.ignore(1000, '\n');
                        cout << endl << "Com Piscina? [S/N]";
                        cin.clear();
                        cin >> piscina;
                        cin.ignore(1000,'\n');
                        if(piscina == 'S' || piscina == 's') comPiscina = true;
                        else comPiscina = false;
                        ((Vivenda *) vetor[i])->setAreaExterior(areaExterior);
                        ((Vivenda *) vetor[i])->setComPiscina(comPiscina);

                    }
                    else if (tipo == "Apartamento")
                    {
                        string piso_s;
                        string tipologia;
                        int piso;
                        do
                        {
                            cout << "\nNova Tipologia: ";
                            getline(cin, tipologia);
                            if (tipologia.find_first_not_of(alphabetplusnum) != string::npos || tipologia == "")
                                cout << "Invalid input" << endl;
                        } while (tipologia.find_first_not_of(alphabetplusnum) != string::npos|| tipologia == "");
                        do
                        {
                            cout << "\nNova Piso: ";
                            cin >> piso_s;
                            if (piso_s.find_first_not_of("1234567890.\n") != string::npos)
                                cout << "Invalid input" << endl;
                        } while (piso_s.find_first_not_of("1234567890.\n") != string::npos);
                        piso = stoi(piso_s);
                        cin.ignore(1000, '\n');
                        ((Apartamento *) vetor[i])->setTipologia(tipologia);
                        ((Apartamento *) vetor[i])->setPiso(piso);
                    }
                    break;
                }
            }
            cond.setHabitacoes(vetor);
            gestao.removeCondominioPorDesignacao(cond.getDesignacao());
            gestao.adicionaCondominio(cond);
            break;
        }
        contador++;
        ita.advance();
    }
    cout << "\n\nHabitacao Editada!\n\n";
}

void Eliminar_Habitacao(CondomiX &gestao)
{
    int id, contador = 1, cond_id, contador_cond = 1;
    vector <Habitacao *>::const_iterator it;
    gestao.Mostrar_Condominios();
    do {
        cout << "\nCondominio da Habitacao a eliminar: ";
        cin >> cond_id;
        cin.ignore(1000, '\n');
    } while (cond_id < 1 || cond_id > gestao.numeroCondominios());
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        if (contador_cond == cond_id) {
            Condominio cond = ita.retrieve();
            cout << endl;
            vector<Habitacao *> vetor = cond.Mostrar_Habitacoes_Disponiveis();
            cout << "\n Habitacao a eliminar (apenas habitacoes nao adquiridas): ";
            do{
                cin.clear();
                cin >> id;
                cin.ignore(1000, '\n');
            }while (id < 1 || id > vetor.size());
            cout << "\n A eliminar habitacao numero " << id << "... " << endl;
            for (it = vetor.begin() ; it != vetor.end() ; it++)
            {
                if (contador == id)
                {
                    vector<Habitacao *> habitacoes = cond.getHabitacoes();
                    if (habitacoes.empty()) {
                        cout << "\nEste Condominio nao possui Habitacoes!\n\n";
                        return;
                    }
                    vector<Habitacao *>::const_iterator ith = habitacoes.begin();
                    while (ith != habitacoes.end()) {
                        if ((*it)->getMorada().getCodigoPostal() == (*ith)->getMorada().getCodigoPostal()) {
                            habitacoes.erase(ith);
                            break;
                        }
                        ith++;
                    }
                    cond.setHabitacoes(habitacoes);
                    break;
                }
                contador++;
            }
            gestao.removeCondominioPorDesignacao(cond.getDesignacao());
            gestao.adicionaCondominio(cond);
            break;
        }
        contador_cond++;
        ita.advance();
    }
    cout << "\n\nHabitacao Eliminada!\n\n";
}

void Adicionar_Condomino(CondomiX &gestao)
{
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    string nome, nif;
    int cond_id, contador = 1;
    cin.ignore(1000,'\n');
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    gestao.Mostrar_Condominios();
    do {
        cout << "\nCondominio a que vai pertencer o Novo Condomino: ";
        cin >> cond_id;
        cin.ignore(1000, '\n');
    } while (cond_id < 1 || cond_id > gestao.numeroCondominios());
    while (!ita.isAtEnd()) {
        if (contador == cond_id) {
            Condominio cond = ita.retrieve();
            vector<Habitacao *> disponiveis = cond.getHabitacoesDisponiveis();
            if (disponiveis.empty()) {
                cout << "\nNao e possivel Adicionar um Novo Condomino - Sem Habitacoes Disponiveis\n";
                return;
            }
            do
            {
                cout << "\nNome: ";
                getline(cin, nome);
                if (nome.find_first_not_of(alphabet) != string::npos || nome =="")
                    cout << "Invalid input" << endl;
            } while (nome.find_first_not_of(alphabet) != string::npos || nome =="");
            do
            {
                try {
                    cout << "\nNIF: ";
                    getline(cin, nif);
                    if (nif.find_first_not_of("1234567890\n") != string::npos || nif == "")
                        cout << "Invalid input" << endl;
                    if (existe_nif(gestao, nif))
                        throw NIF_Ja_Existente(nif);
                }
                catch(NIF_Ja_Existente(&nif)) {
                    cout << "\nNIF Ja Existente!\n";
                }
            } while (nif.find_first_not_of("1234567890\n") != string::npos || nif == "" || existe_nif(gestao,nif));
            Condomino *condomino = new Condomino(nome,nif);
            cout << endl;
            cond.Mostrar_Habitacoes_Disponiveis();
            cout << "\nHabitacao a adquirir pelo novo Condomino: ";
            unsigned int id, count = 1;
            do{
                cin.clear();
                cin >> id;
                cin.ignore(1000, '\n');
            }while (id < 1 || id > disponiveis.size());
            for (unsigned int i = 0 ; i < disponiveis.size() ; i++) {
                if (count == id) {
                    condomino->adicionaHabitacao(disponiveis[i]);
                    break;
                }
                count++;
            }
            cond.adicionaCondomino(condomino);
            gestao.removeCondominioPorDesignacao(cond.getDesignacao());
            gestao.adicionaCondominio(cond);
            break;
        }
        contador++;
        ita.advance();
    }
    cout << "\n\nCondomino Adicionado!\n\n";
}

void Editar_Condomino(CondomiX &gestao)
{
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    string nome, nif;
    int id, cond_id, contador = 1;
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    gestao.Mostrar_Condominios();
    do {
        cout << "\nCondominio da Habitacao a eliminar: ";
        cin >> cond_id;
        cin.ignore(1000, '\n');
    } while (cond_id < 1 || cond_id > gestao.numeroCondominios());
    while (!ita.isAtEnd()) {
        if (contador == cond_id) {
            Condominio cond = ita.retrieve();
            vector<Condomino *> vetor = cond.getCondominos();
            cout << endl;
            cond.Mostrar_Condominos();
            cout << "\n Condomino a alterar: ";
            do{
                cin.clear();
                cin >> id;
                cin.ignore(1000, '\n');
            }while (id < 1 || id > cond.numeroCondominos());
            cout << "\n A alterar condomino numero " << id << "... " << endl;
            for (unsigned int i = 0 ; i < vetor.size() ; i++)
            {
                if (i == id-1)
                {
                    do
                    {
                        cout << "\n Novo Nome: ";
                        getline(cin, nome);
                        if (nome.find_first_not_of(alphabet) != string::npos || nome =="")
                            cout << "\n Invalid input" << endl;
                    } while (nome.find_first_not_of(alphabet) != string::npos || nome =="");
                    do
                    {
                        cout << "\n Novo NIF: ";
                        getline(cin, nif);
                        if (nif.find_first_not_of("1234567890\n") != string::npos || nif == "")
                            cout << "\n Invalid input" << endl;
                    } while (nif.find_first_not_of("1234567890\n") != string::npos || nif == "");
                    vetor[i]->setNome(nome);
                    vetor[i]->setNif(nif);
                }
            }
            cond.setCondominos(vetor);
            gestao.removeCondominioPorDesignacao(cond.getDesignacao());
            gestao.adicionaCondominio(cond);
            break;
        }
        contador++;
        ita.advance();
    }
    cout << "\n\nCondomino Editado!\n\n";
}

void Eliminar_Condomino(CondomiX &gestao)
{
    int id, contador = 1, cond_id, contador_cond = 1;
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    gestao.Mostrar_Condominios();
    do {
        cout << "\nCondominio da Habitacao a eliminar: ";
        cin >> cond_id;
        cin.ignore(1000, '\n');
    } while (cond_id < 1 || cond_id > gestao.numeroCondominios());
    while (!ita.isAtEnd()) {
        if (contador_cond == cond_id) {
            Condominio cond = ita.retrieve();
            vector <Condomino *>::const_iterator it;
            vector<Condomino *> vetor = cond.getCondominos();
            cout << endl;
            cond.Mostrar_Condominos();
            cout << "\n Condomino a eliminar: ";
            do{
                cin.clear();
                cin >> id;
                cin.ignore(1000, '\n');
            }while (id < 1 || id > cond.numeroCondominos());
            cout << "\n A eliminar condomino numero " << id << "... " << endl;
            for (it = vetor.begin() ; it != vetor.end() ; it++)
            {
                if (contador == id)
                {
                    vetor.erase(it);
                    it--;
                    break;
                }
                contador++;
            }
            cond.setCondominos(vetor);
            gestao.removeCondominioPorDesignacao(cond.getDesignacao());
            gestao.adicionaCondominio(cond);
            break;
        }
        contador_cond++;
        ita.advance();
    }
    cout << "\n\nCondomino Eliminado!\n\n";
}

void Adicionar_Condominio(CondomiX &gestao){
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    cin.ignore(1000,'\n');
    string designacao, localizacao;
    do
    {
        cout << "\nDesignacao do Condominio: ";
        getline(cin, designacao);
        if (designacao.find_first_not_of(alphabet) != string::npos || designacao == "")
            cout << "Invalid input" << endl;
    } while (designacao.find_first_not_of(alphabet) != string::npos || designacao == "");

    do
    {
        cout << "\nLocalizacao do Condominio: ";
        getline(cin, localizacao);
        if (localizacao.find_first_not_of(alphabet) != string::npos || localizacao == "")
            cout << "Invalid input" << endl;
    } while (localizacao.find_first_not_of(alphabet) != string::npos || localizacao == "");

    if(!existeDesignacao(gestao, designacao))
    {
        Condominio condominio(designacao, localizacao);
        gestao.adicionaCondominio(condominio);
        cout << "\n\nCondominio Adicionado!\n\n";
    }
    else
        cout << "\n\nCondominio com essa Designacao Ja Existe!\n\n";


}

void Editar_Condominio(CondomiX &gestao){
    string alphabet = "\n ,.-aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n ,.-aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    string designacao, localizacao;
    int id, contador = 1;
    BST<Condominio> condominios = gestao.getCondominios();
    gestao.Mostrar_Condominios();
    cout << "\n ID do condominio a alterar: ";
    do{
        cin >> id;
        cin.ignore(1000,'\n');
    }while (id < 1 || id > gestao.numeroCondominios());
    cout << "\n A alterar condominio " << id << "... " << endl;
    do
    {
        cout << "\nNova Designacao do Condominio: ";
        getline(cin, designacao);
        if (designacao.find_first_not_of(alphabet) != string::npos || designacao == "")
            cout << "Invalid input" << endl;
    } while (designacao.find_first_not_of(alphabet) != string::npos || designacao == "");
    do{
        cout << "\nNova Localizacao do Condominio: ";
        getline(cin, localizacao);
        if (localizacao.find_first_not_of(alphabet) != string::npos || localizacao == "")
            cout << "Invalid input" << endl;
    } while (localizacao.find_first_not_of(alphabet) != string::npos || localizacao == "");
    BSTItrIn<Condominio> it(condominios);
    while (!it.isAtEnd()) {
        if (contador == id) {
            Condominio cond = it.retrieve();
            gestao.removeCondominioPorDesignacao(cond.getDesignacao());
            cond.setDesignacao(designacao);
            cond.setLocalizacao(localizacao);
            gestao.adicionaCondominio(cond);
            break;
        }
        contador++;
        it.advance();
    }
    cout << "\n\nCondominio Editado!\n\n";
}

void Eliminar_Condominio(CondomiX &gestao){
    int cond_id, contador_cond = 1;
    gestao.Mostrar_Condominios();
    do {
        cout << "\nCondominio a eliminar: ";
        cin >> cond_id;
        cin.ignore(1000, '\n');
    } while (cond_id < 1 || cond_id > gestao.numeroCondominios());
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {

        if (contador_cond == cond_id) {
            gestao.removeCondominio(ita.retrieve());
            break;
        }
        contador_cond++;
        ita.advance();
    }
    cout << "\n\nCondominio Eliminado!\n\n";
}

void Adquirir_Habitacao(CondomiX &gestao)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Adquirir Habitacao \n\n";
    int id, id2, id3, contador = 0, contador2 = 0, contador3 = 0;
    gestao.Mostrar_Condominios();
    cout << "\n Condominio em que deseja adquirir uma habitacao: ";
    do {
        cin.clear();
        cin >> id3;
        cin.ignore(1000, '\n');
    } while (id3 < 1 || id3 > gestao.numeroCondominios());
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        contador3++;
        if (contador3 == id3) {
            Condominio condominio = ita.retrieve();
            gestao.removeCondominio(condominio);
            vector<Condomino *>::const_iterator itc;
            vector<Condomino *> vetor_c = condominio.getCondominos();
            vector<Habitacao *>::const_iterator its;
            vector<Habitacao *> vetor_s = condominio.getHabitacoes();
            cout << endl;
            condominio.Mostrar_Condominos();
            cout << "\n Condomino que deseja adquirir uma habitacao: ";
            do {
                cin.clear();
                cin >> id;
                cin.ignore(1000, '\n');
            } while (id < 1 || id > condominio.numeroCondominos());
            for (itc = vetor_c.begin(); itc != vetor_c.end(); itc++) {
                if (contador == id - 1) {
                    cout << "\n A adquirir habitacao para " << (*itc)->getNome() << "... " << endl << endl;
                    vector<Habitacao *> disponiveis = condominio.Mostrar_Habitacoes_Disponiveis();
                    if (disponiveis.size() == 0) {
                        cout << "\n Nao existem Habitacoes Disponiveis para Compra\n\n";
                        return;
                    }
                    cout << "\n Habitacao a adquirir: ";
                    do {
                        cin.clear();
                        cin >> id2;
                        cin.ignore(1000, '\n');
                    } while (id2 < 1 || id2 > disponiveis.size());
                    for (its = disponiveis.begin(); its != disponiveis.end(); its++) {
                        if (contador2 == id2 - 1) {
                            if ((*itc)->validaHabitacao(*its))
                                throw Habitacao_Ocupada((*its)->getMorada().getCodigoPostal());
                            (*itc)->adicionaHabitacao(*its);
                        }
                        contador2++;
                    }
                    break;
                }
                contador++;
            }
            condominio.setCondominos(vetor_c);
            gestao.removeCondominioPorDesignacao(condominio.getDesignacao());
            gestao.adicionaCondominio(condominio);
            break;
        }
        ita.advance();
    }
    cout << "\n\n Habitacao Adquirida!\n\n";
}

void Remover_Habitacao(CondomiX &gestao) {
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Remover Habitacao \n\n";
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    gestao.Ler_Antigos_Condominos("AntigosCondominos.txt");
    vector <Condomino *>::const_iterator itc;
    vector <Habitacao *>::const_iterator its;
    int id, id2, id3, contador = 0, contador2 = 0, contador3 = 1;
    gestao.Mostrar_Condominios();
    cout << "\n Condominio em que deseja remover uma habitacao: ";
    do{
        cin.clear();
        cin >> id3;
        cin.ignore(1000, '\n');
    }while (id3 < 1 || id3 > gestao.numeroCondominios());
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        if (contador3 == id3) {
            Condominio cond = ita.retrieve();
            vector <Condomino *> vetor_c = cond.getCondominos();
            cout << endl;
            cond.Mostrar_Condominos();
            cout << "\n Condomino que deseja remover uma habitacao: ";
            do{
                cin.clear();
                cin >> id;
                cin.ignore(1000, '\n');
            }while (id < 1 || id > cond.numeroCondominos());
            for (itc = vetor_c.begin() ; itc != vetor_c.end() ; itc++)
            {
                if (contador == id-1)
                {
                    vector <Habitacao *> vetor_h = (*itc)->getHabitacoes();
                    cout << "\n A remover habitacao de " << (*itc)->getNome() << "... " << endl << endl;
                    if (vetor_h.size() == 0) {
                        cout << "Este condomino nao possui habitacoes!\n\n";
                        break;
                    }
                    (*itc)->Mostrar_Habitacoes();
                    cout << "\n Habitacao a remover: ";
                    do{
                        cin.clear();
                        cin >> id2;
                        cin.ignore(1000, '\n');
                    }while (id2 < 1 || id2 > vetor_h.size());
                    for (its = vetor_h.begin() ; its != vetor_h.end() ; its++)
                    {
                        if (contador2 == id2-1)
                        {
                            vetor_h.erase(its);
                            (*itc)->setHabitacoes(vetor_h);
                            cout << "\n\nHabitacao Removida!\n\n";
                            if (vetor_h.empty()) {
                                cout << (*itc)->getNome() << " sem Habitacoes. Novo estatuto: Antigo Condomino\n\n";
                                time_t now = time(NULL);
                                struct tm dataEntrada = (*itc)->getDataEntrada();
                                double seconds = difftime(now,mktime(&dataEntrada));
                                int periodo = (int) (seconds/30000);
                                AntigoCondomino * antigoCondomino = new AntigoCondomino((*itc)->getNome(),(*itc)->getNif(),periodo);
                                cond.adicionaAntigoCondomino(antigoCondomino);
                                vetor_c.erase(itc);
                            }
                            break;
                        }
                        contador2++;
                    }
                    break;
                }
                contador++;
            }
            cond.setCondominos(vetor_c);
            gestao.removeCondominioPorDesignacao(cond.getDesignacao());
            gestao.adicionaCondominio(cond);
            gestao.Escrever_Condominos("Condominos.txt");
            gestao.Escrever_Habitacoes("Habitacoes.txt");
            gestao.Escrever_Antigos_Condominos("AntigosCondominos.txt");
            break;
        }
        contador3++;
        ita.advance();
    }
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Adicionar_Servico(Condominio &condominio, CondomiX &gestao)
{
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    string descricao, custo;
    do
    {
        cout << "\nDescricao do Servico: ";
        getline(cin, descricao);
        if (descricao.find_first_not_of(alphabet) != string::npos || descricao == "")
            cout << "Invalid input" << endl;
    } while (descricao.find_first_not_of(alphabet) != string::npos || descricao == "");

    do
    {
        cout << "\nCusto do Servico: ";
        getline(cin, custo);
        if (custo.find_first_not_of("1234567890.\n") != string::npos || custo == "")
            cout << "Invalid input" << endl;
    } while (custo.find_first_not_of("1234567890.\n") != string::npos || custo == "");

    Servico *service  = new Servico(descricao, stof(custo));
    gestao.adicionaServico(service);
    cout << "\n\nServico Adicionado!\n\n";
}

void Editar_Servico(Condominio &condominio, CondomiX &gestao)
{
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    string descricao;
    int id;
    vector<Servico *>::const_iterator it;
    vector<Servico *> vetor = gestao.getServicos();
    gestao.Mostrar_Servicos();
    cout << "\n ID do servico a alterar: ";
    do{
        cin >> id;
    }while (id < 1 || id > Servico::ultimo_id);
    cin.ignore(1000,'\n');
    cout << "\n A alterar Servico de ID " << id << "... " << endl;
    do
    {
        cout << "\nNova Descricao do Servico: ";
        getline(cin, descricao);
        if (descricao.find_first_not_of(alphabet) != string::npos || descricao == "")
            cout << "Invalid input" << endl;
    } while (descricao.find_first_not_of(alphabet) != string::npos || descricao == "");
    for (it = vetor.begin() ; it != vetor.end() ; it++)
    {
        if ((*it)->getId() == id){
            (*it)->setDescricao(descricao);
            break;
        }
    }
    gestao.setServicos(vetor);
    cout << "\n\nServico Editado!\n\n";
}

void Eliminar_Servico(Condominio &condominio, CondomiX &gestao)
{
    int id;
    vector<Servico *>::const_iterator it;
    vector<Servico *> vetor = gestao.getServicos();
    gestao.Mostrar_Servicos();
    cout << "\n ID do servico a eliminar: ";
    do{
        cin >> id;
    }while (id < 1 || id > Servico::ultimo_id);
    for (it = vetor.begin() ; it != vetor.end() ; it++)
    {
        if ((*it)->getId() == id) {
            vetor.erase(it);
            it--;
        }
        else if ((*it)->getId() > id)
            (*it)->setId((*it)->getId()-1);
    }
    gestao.setServicos(vetor);
    Servico::ultimo_id = vetor.size();
    cout << "\n\nServico Eliminado!\n\n";
}

void Adicionar_Transporte(CondomiX &gestao)
{
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    string tipo, destino, paragem_proxima, distancia;
    int  cond_id, contador = 1;
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    gestao.Mostrar_Condominios();
    cout << "\n ID do condominio onde se vai adcionar um transporte: ";
    do{
        cin >> cond_id;
        cin.ignore(1000,'\n');
    }while (cond_id < 1 || cond_id > gestao.numeroCondominios());
    cout << "\n A adicionar um transporte ao condominio " << cond_id << "... " << endl;
    do{
        cout << "\nTipo: ";
        getline(cin, tipo);
        if(tipo.find_first_not_of(alphabet) != string::npos || tipo == "")
            cout << "Invalid input" << endl;
    }while (tipo.find_first_not_of(alphabet) != string::npos || tipo == "");
    do{
        cout << "\nDestino: ";
        getline(cin, destino);
        if(destino.find_first_not_of(alphabet) != string::npos || destino == "")
            cout << "Invalid input" << endl;
    }while (destino.find_first_not_of(alphabet) != string::npos || destino == "");
    do{
        cout << "\nParagem mais Proxima: ";
        getline(cin, paragem_proxima);
        if(paragem_proxima.find_first_not_of(alphabet) != string::npos || paragem_proxima == "")
            cout << "Invalid input" << endl;
    }while (paragem_proxima.find_first_not_of(alphabet) != string::npos || paragem_proxima == "");
    do
    {
        cout << "\nDistancia: ";
        getline(cin, distancia);
        if (distancia.find_first_not_of("1234567890\n") != string::npos || distancia == "")
            cout << "Invalid input" << endl;
    }while (distancia.find_first_not_of("1234567890\n") != string::npos || distancia == "");

    while (!ita.isAtEnd()) {
        if (contador == cond_id) {
            Condominio cond = ita.retrieve();
            Transporte * transporte = new Transporte(tipo, destino, paragem_proxima, stoi(distancia));
            cond.adicionaTransporte(transporte);
            cout << endl;
            cout << "\n\nTransporte Adicionado!\n\n";
            gestao.removeCondominioPorDesignacao(cond.getDesignacao());
            gestao.adicionaCondominio(cond);
            break;
        }
        contador ++;
        ita.advance();
    }

}

void Editar_Transporte(CondomiX &gestao)
{
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    string destino;
    int id = 0, id_t = 0, contador = 1, contador_t = 1;
    gestao.Mostrar_Condominios();
    cout << "\n ID do condominio onde se vai alterar um transporte: ";
    do{
        cin >> id;
        cin.ignore(1000,'\n');
    }while (id < 1 || id > gestao.numeroCondominios());
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        if(contador == id)
        {
            Condominio cond = ita.retrieve();
            priority_queue<Transporte *, vector<Transporte *>, TransportesCmp> transportes = cond.getTransportes();
            vector<Transporte *> aux;
            while (!transportes.empty()) {
                aux.push_back(transportes.top());
                transportes.pop();
            }
            vector<Transporte *>::const_reverse_iterator it;
            for (it = aux.rbegin(); it != aux.rend(); it++) {
                transportes.push(*it);
            }
            cout << endl;
            cond.Mostrar_Transportes_Edicao();
            cout << "\n Transporte a alterar: ";
            do{
                cin.clear();
                cin >> id_t;
                cin.ignore(1000, '\n');
            }while (id_t < 1 || id_t > cond.numeroTransportes());
            cout << "\n A alterar transporte numero " << id_t << "... " << endl;
            for (unsigned int i = aux.size() - 1 ; i >= 0 ; i--)
            {
                if (contador_t == id_t)
                {
                    do{
                        cout << "\n Novo Destino: ";
                        getline(cin, destino);
                        if (destino.find_first_not_of(alphabet) != string::npos || destino =="")
                            cout << "Invalid input" << endl;
                    } while (destino.find_first_not_of(alphabet) != string::npos || destino =="");
                    aux[i]->setDestino(destino);
                    break;
                }
                contador_t++;
            }
            cond.setTransportes(aux);
            gestao.removeCondominioPorDesignacao(cond.getDesignacao());
            gestao.adicionaCondominio(cond);
            break;
        }
        contador++;
        ita.advance();
    }
    cout << "\n\nTransporte Editado!\n\n";
}

void Eliminar_Transporte(CondomiX &gestao)
{
    int id, id_t, contador = 1, contador_t = 1;
    BST<Condominio> condominios = gestao.getCondominios();
    gestao.Mostrar_Condominios();
    cout << "\n ID do condominio onde se vai eliminar um transporte: ";
    do{
        cin >> id;
        cin.ignore(1000,'\n');
    }while (id < 1 || id > gestao.numeroCondominios());
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        if(contador == id)
        {
            Condominio cond = ita.retrieve();
            priority_queue<Transporte *, vector<Transporte *>, TransportesCmp> transportes = cond.getTransportes();
            vector<Transporte *> aux;
            while (!transportes.empty()) {
                aux.push_back(transportes.top());
                transportes.pop();
            }
            vector<Transporte *>::const_reverse_iterator it;
            vector<Transporte *>::const_iterator itt;
            for (it = aux.rbegin(); it != aux.rend(); it++) {
                transportes.push(*it);
            }
            cout << endl;
            cond.Mostrar_Transportes_Edicao();
            cout << "\n Transporte a Eliminar: ";
            do{
                cin.clear();
                cin >> id_t;
                cin.ignore(1000,'\n');
            }while (id_t < 1 || id_t > cond.numeroTransportes());
            for (itt = aux.begin() ; itt != aux.end() ; itt++) {
                if (contador_t == aux.size() - id_t + 1) {
                    aux.erase(itt);
                    break;
                }
                contador_t++;
            }
            vector<Transporte *> novo_aux;
            for (it = aux.rbegin() ; it != aux.rend() ; it++) {
                novo_aux.push_back(*it);
            }
            cond.setTransportes(novo_aux);
            gestao.removeCondominioPorDesignacao(cond.getDesignacao());
            gestao.adicionaCondominio(cond);
            cout << "\n\nTransporte Eliminado!\n\n";
            break;
        }
        contador++;
        ita.advance();
    }
}

void Requisitar_Servico(CondomiX &gestao)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Requisitar Servico \n\n";
    gestao.Ler_Prestadores("Prestadores.txt");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Servicos("Servicos.txt");
    gestao.Ler_Condominos("Condominos.txt");
    int id, id2, id3, contador = 0, contador2 = 0, contador3 = 1;
    gestao.Mostrar_Condominios();
    cout << "\n Condominio do Condomino que deseja requisitar um servico: ";
    do {
        cin.clear();
        cin >> id3;
        cin.ignore(1000, '\n');
    } while (id3 < 1 || id3 > gestao.numeroCondominios());
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        if (contador3 == id3) {
            Condominio cond = ita.retrieve();
            vector<Condomino *>::const_iterator itc;
            vector<Condomino *> vetor_c = cond.getCondominos();
            vector<Servico *>::const_iterator its;
            vector<Servico *> vetor_s = gestao.getServicos();
            cout << endl;
            cond.Mostrar_Condominos();
            cout << "\n Condomino que deseja requisitar um servico: ";
            do {
                cin.clear();
                cin >> id;
                cin.ignore(1000, '\n');
            } while (id < 1 || id > cond.numeroCondominos());
            for (itc = vetor_c.begin(); itc != vetor_c.end(); itc++) {
                if (contador == id - 1) {
                    cout << "\n A requisitar um servico para " << (*itc)->getNome() << "... " << endl << endl;
                    gestao.Mostrar_Servicos();
                    cout << "\n Servico a Requisitar: ";
                    do {
                        cin.clear();
                        cin >> id2;
                        cin.ignore(1000, '\n');
                    } while (id2 < 1 || id2 > vetor_s.size());
                    for (its = vetor_s.begin(); its != vetor_s.end(); its++) {
                        if (contador2 == id2 - 1) {
                            if ((*its)->getDescricao() == "Servico de Limpeza") {
                                int duracao;
                                cout << "\n Duracao do Servico de Limpeza (em horas): ";
                                cin >> duracao;
                                ServicoLimpeza *servico = new ServicoLimpeza((*its)->getId(),(*its)->getDescricao(),(*its)->getCusto(), duracao);
                                PedidoPrestacaoServico pedido(*itc,servico);
                                PrestadorServicoLimpeza *prestador = gestao.procurarPrestadorServicoLimpeza();
                                prestador->setTotalHoras(prestador->getTotalHoras()+duracao);
                                servico->setPrestador(prestador);
                                (*itc)->adicionaServico(servico);
                            }
                            else {
                                (*itc)->adicionaServico(*its);
                            }
                            break;
                        }
                        contador2++;
                    }
                    break;
                }
                contador++;
            }
            cond.setCondominos(vetor_c);
            gestao.removeCondominioPorDesignacao(cond.getDesignacao());
            gestao.adicionaCondominio(cond);
            break;
        }
        contador3++;
        ita.advance();
    }
    gestao.Escrever_Condominos("Condominos.txt");
    gestao.Escrever_Prestadores("Prestadores.txt");
    cout << "\n\nServico Requisitado!\n\n";
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Terminar_Servico(CondomiX &gestao)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Terminar Servico \n\n";
    gestao.Ler_Prestadores("Prestadores.txt");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Servicos("Servicos.txt");
    gestao.Ler_Servicos_Efetuados("ServicosEfetuados.txt");
    gestao.Ler_Condominos("Condominos.txt");
    vector<Servico*> vetor_e = gestao.getServicosEfetuados();
    int id, id2, id3, contador = 0, contador3 = 1;
    bool invalido = true;
    gestao.Mostrar_Condominios();
    cout << "\n Condominio em que terminar um servico: ";
    do {
        cin.clear();
        cin >> id3;
        cin.ignore(1000, '\n');
    } while (id3 < 1 || id3 > gestao.numeroCondominios());
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {
        if (contador3 == id3) {
            Condominio cond = ita.retrieve();
            vector<Condomino *>::const_iterator itc;
            vector<Condomino *> vetor_c = cond.getCondominos();
            vector<Servico *>::const_iterator its;
            cout << endl;
            cond.Mostrar_Condominos();
            cout << "\n Condomino que deseja terminar um servico: ";
            do {
                cin.clear();
                cin >> id;
                cin.ignore(1000, '\n');
            } while (id < 1 || id > cond.numeroCondominos());
            for (itc = vetor_c.begin(); itc != vetor_c.end(); itc++) {
                if (contador == id - 1) {
                    Condomino * condomino = (*itc);
                    vector<Servico *> vetor_s = condomino->getServicos();
                    if (vetor_s.empty()) {
                        cout << "\n Condomino Sem Servicos! \n\n";
                        char sair = Sair_Programa();
                        if (sair == 'N' || sair == 'n')
                            Menu_Principal();
                        return;
                    }
                    cout << "\n A terminar um servico para " << (*itc)->getNome() << "... " << endl << endl;
                    for (unsigned int i = 0 ; i < vetor_s.size() ; i++) {
                        cout << "[" << vetor_s[i]->getId() << "] " << vetor_s[i]->getDescricao() << endl;
                    }
                    cout << "\n Servico a Terminar: ";
                    do {
                        cin.clear();
                        cin >> id2;
                        cin.ignore(1000, '\n');
                        for (unsigned int j = 0 ; j < vetor_s.size() ; j++) {
                            if (vetor_s[j]->getId() == id2)
                                invalido = false;
                        }
                    } while (id2 < 1 || invalido);
                    for (its = vetor_s.begin(); its != vetor_s.end(); its++) {
                        if ((*its)->getId() == id2) {
                            vetor_e.push_back(*its);
                            vetor_s.erase(its);
                            (*itc)->setServicos(vetor_s);
                            break;
                        }
                    }
                    break;
                }
                contador++;
            }
            cond.setCondominos(vetor_c);
            gestao.setServicosEfetuados(vetor_e);
            gestao.removeCondominioPorDesignacao(cond.getDesignacao());
            gestao.adicionaCondominio(cond);
            break;
        }
        contador3++;
        ita.advance();
    }
    gestao.Escrever_Condominos("Condominos.txt");
    gestao.Escrever_Prestadores("Prestadores.txt");
    gestao.Escrever_Servicos_Efetuados("ServicosEfetuados.txt");
    cout << "\n\nServico Terminado!\n\n";
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

float Calcular_Valor_Mensal(Condominio &condominio)
{
    float valor_mensal = 0;
    vector<Condomino *> vetor = condominio.getCondominos();
    vector <Condomino*>::const_iterator it;
    for(it = vetor.begin(); it != vetor.end(); it++)
    {
        valor_mensal += (*it)->totalCondominio();
    }
    return valor_mensal;
}

void Visualizar_Transportes(CondomiX &gestao)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de Todos os Transportes \n\n";
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    gestao.Ler_Transportes("Transportes.txt");
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while (!ita.isAtEnd()) {

        Condominio condominio = ita.retrieve();
        cout << "Condominio: " << condominio.getDesignacao() << " - " << condominio.getLocalizacao() << " (" << condominio.numeroHabitacoes() << " habitacoes, " << condominio.numeroCondominos() << " condominos)"<< endl << endl;
        condominio.Mostrar_Transportes();
        ita.advance();
    }
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Visualizar_Transporte_Perto_Destino(CondomiX &gestao)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao o Transporte mais Perto \n\n";
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    gestao.Ler_Transportes("Transportes.txt");
    cin.ignore(1000, '\n');

    string destino, designacao, localizacao, nif;
    bool encontrou = false;

    while(!encontrou)
    {
        try {
            cout << "\nNIF do Condomino que esta a procura de um transporte: ";
            getline(cin, nif);
            Condomino* cond = gestao.Procurar_Condomino(nif, designacao, localizacao);
            BST<Condominio> aux = gestao.getCondominios();
            BSTItrIn<Condominio> ita(aux);
            while (!ita.isAtEnd()) {
                if (ita.retrieve().getDesignacao() == designacao) {
                    Condominio condominio = ita.retrieve();
                    try{
                        cout << "\nDestino do Transporte a procurar: ";
                        getline(cin, destino);
                        Transporte * t = condominio.Procurar_Transporte(destino);
                        cout << "\n ---------- \n" << endl;
                        cout << "Condominio: " << designacao << " - " << localizacao << " (" << condominio.numeroHabitacoes() << " habitacoes, " << condominio.numeroCondominos() << " condominos)"<< endl << endl;
                        cout << t->info();
                        cout << "\n ---------- \n" << endl;
                        encontrou = true;
                    }
                    catch (Transporte_Nao_Encontrado(&destino)) {
                        cout << "\nTransporte Nao Encontrado! \n";
                    }
                    break;
                }
                ita.advance();
            }
        }
        catch (Condomino_Nao_Encontrado(&nif)) {
            cout << "\nCondomino Nao Encontrado! \n";
        }
    }
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Visualizar_Transporte_Perto(CondomiX &gestao)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao o Transporte mais Perto \n\n";
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    gestao.Ler_Transportes("Transportes.txt");
    cin.ignore(1000, '\n');

    string designacao, localizacao, nif;
    bool encontrou = false;

    while(!encontrou)
    {
        try {
            cout << "\nNIF do Condomino que esta a procura de um transporte: ";
            getline(cin, nif);
            Condomino* cond = gestao.Procurar_Condomino(nif, designacao, localizacao);
            BST<Condominio> aux = gestao.getCondominios();
            BSTItrIn<Condominio> ita(aux);
            while (!ita.isAtEnd()) {
                if (ita.retrieve().getDesignacao() == designacao) {
                    Condominio condominio = ita.retrieve();
                    Transporte * t = condominio.Procurar_Transporte_Perto();
                    cout << "\n ---------- \n" << endl;
                    cout << "Condominio: " << designacao << " - " << localizacao << " (" << condominio.numeroHabitacoes() << " habitacoes, " << condominio.numeroCondominos() << " condominos)"<< endl << endl;
                    cout << t->info();
                    cout << "\n ---------- \n" << endl;
                    encontrou = true;
                    break;
                }
                ita.advance();
            }
        }
        catch (Condomino_Nao_Encontrado(&nif)) {
            cout << "\nCondomino Nao Encontrado! \n";
        }
    }
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}