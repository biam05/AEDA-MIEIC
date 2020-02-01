#include <iostream>

#include "utils.h"
#include "Excecoes.h"
#include "CondomiX.h"
#include "PedidoPrestacaoServico.h"

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

bool existe_nif(Condominio &condominio, const string &nif)
{
    vector<Condomino *> condominos = condominio.getCondominos();
    vector<Condomino *>::const_iterator it;
    for (it = condominos.begin() ; it != condominos.end() ; it++) {
        if ((*it)->getNif() == nif)
            return true;
    }
    return false;
}

// Funcoes Principais

void Visualizar_Todas_Habitacoes (Condominio &condominio)
{
    condominio.Ler_Habitacoes("Habitacoes.txt");
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de Todas as Habitacoes (Ordem Decrescente de Area Habitacional) \n\n";
    condominio.ordenaHabitacoesPorAreaHabitacional();
    cout << condominio.escreveTotalHabitacoes();
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Visualizar_Habitacao_Morada(Condominio &condominio)
{
    condominio.Ler_Habitacoes("Habitacoes.txt");
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de uma Habitacao pela Morada \n\n";
    string cp;
    bool encontrou = false;
    cin.ignore(1000,'\n');
    while (!encontrou)
    {
        try {
            cout << "\nCodigo-postal da Habitacao a procurar: ";
            getline(cin, cp);
            Habitacao *habit = condominio.Procurar_Habitacao(cp);
            cout << "\n ---------- \n" << endl;
            cout << habit->info();
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

void Visualizar_Todos_Condominos (Condominio &condominio)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de Todos os Condominos (Ordem Crescente do Nome) \n\n";
    condominio.Ler_Habitacoes("Habitacoes.txt");
    condominio.Ler_Servicos("Servicos.txt");
    condominio.Ler_Condominos("Condominos.txt");
    condominio.ordenaCondominosPorNome();
    cout << condominio.escreveTotalCondominos();
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Visualizar_Condominos_NIF(Condominio &condominio)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de um Condomino pelo NIF \n\n";
    condominio.Ler_Habitacoes("Habitacoes.txt");
    condominio.Ler_Servicos("Servicos.txt");
    condominio.Ler_Condominos("Condominos.txt");
    string nif;
    bool encontrou = false;
    while (!encontrou)
    {
        try {
            cout << "\nNIF do Condomino a procurar: ";
            getline(cin, nif);
            Condomino* cond = condominio.Procurar_Condomino(nif);
            cout << "\n ---------- \n" << endl;
            cout << cond->info() << endl;
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

void Visualizar_Servicos(Condominio &condominio)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Visualizacao de Servicos \n\n";
    condominio.Ler_Servicos("Servicos.txt");
    cout << condominio.escreveTotalServicos();
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

void Adicionar_Habitacao(Condominio &condominio)
{
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    char opcao;
    string area_habitacional,e ,c ,cp, tipologia, area_ext, piscina, piso_s, tipo;
    float areaExterior, ah;
    bool comPiscina;
    int piso;
    cout << "\t\t     Tipo de Habitacao \n\n";
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
            if (existe_cp(condominio, cp))
                throw CP_Ja_Existente(cp);
        }
        catch (CP_Ja_Existente(&cp)) {
            cout << "\nCodigo-Postal Ja Existente!\n";
        }
    } while (cp.find_first_not_of("1234567890-\n") != string::npos || cp == "" || existe_cp(condominio,cp));

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
            Habitacao *vivenda = new Vivenda(ah,*morada, areaExterior,comPiscina); // substituido vivenda por habitacao no inicio
            condominio.adicionaHabitacao(vivenda);
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
            Habitacao *apartamento = new Apartamento(ah, *morada, tipologia, piso); // mesma coisa que em cima
            condominio.adicionaHabitacao(apartamento);
            cout << "\n\nApartamento Adicionado!\n\n";
            break;
        }
        default:
            Menu_Adicionar_Habitacao(); break;
    }
}

void Editar_Habitacao(Condominio &condominio)
{
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    string tipo;
    int id, tp;
    vector<Habitacao *>::const_iterator it;
    vector<Habitacao *> vetor = condominio.getHabitacoes();
    condominio.Mostrar_Habitacoes();
    cout << "\nHabitacao a alterar:  ";
    do{
        cin.clear();
        cin >> id;
        cin.ignore(1000, '\n');
    }while(id < 1 || id >condominio.numeroHabitacoes());
    cout << "\n A alterar habitacao numero " << id << "... " << endl << endl;

    for(int i = 0; i < condominio.numeroHabitacoes(); i++)
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
    condominio.setHabitacoes(vetor);
    cout << "\n\nHabitacao Editada!\n\n";

}

void Eliminar_Habitacao(Condominio &condominio)
{
    int id, contador = 1;
    bool ocupada = true;
    vector <Habitacao *>::const_iterator it;
    vector<Habitacao *> vetor = condominio.getHabitacoes();
    condominio.Mostrar_Habitacoes();
    cout << "\n Habitacao a eliminar: ";
    do{
        cin.clear();
        cin >> id;
        cin.ignore(1000, '\n');
    }while (id < 1 || id > condominio.numeroHabitacoes());
    cout << "\n A eliminar habitacao numero " << id << "... " << endl;
    for (it = vetor.begin() ; it != vetor.end() ; it++)
    {
        if (contador == id)
        {
            while (ocupada) {
                try {
                    string cp = (*it)->getMorada().getCodigoPostal();
                    if (condominio.validaHabitacao(*it))
                        throw Habitacao_Ocupada(cp);
                    else {
                        vetor.erase(it);
                        it--;
                        ocupada = false;
                    }
                }
                catch(Habitacao_Ocupada(&cp)) {
                    cout << "\nHabitacao Ocupada! Nao pode ser eliminada \n";
                }
            }
            break;
        }
        contador++;
    }
    condominio.setHabitacoes(vetor);
    cout << "\n\nHabitacao Eliminada!\n\n";
}

void Adicionar_Condomino(Condominio &condominio)
{
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    string nome, nif;
    cin.ignore(1000,'\n');
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
            if (existe_nif(condominio, nif))
                throw NIF_Ja_Existente(nif);
        }
        catch(NIF_Ja_Existente(&nif)) {
            cout << "\nNIF Ja Existente!\n";
        }
    } while (nif.find_first_not_of("1234567890\n") != string::npos || nif == "" || existe_nif(condominio,nif));
    Condomino *condomino = new Condomino(nome,nif);
    condominio.adicionaCondomino(condomino);
    cout << "\n\nCondomino Adicionado!\n\n";
}

void Editar_Condomino(Condominio &condominio)
{
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";

    string nome, nif;
    int id;
    vector<Condomino *> vetor = condominio.getCondominos();
    condominio.Mostrar_Condominos();
    cout << "\n Condomino a alterar: ";
    do{
        cin.clear();
        cin >> id;
        cin.ignore(1000, '\n');
    }while (id < 1 || id > condominio.numeroCondominos());
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
                    cout << "Invalid input" << endl;
            } while (nome.find_first_not_of(alphabet) != string::npos || nome =="");
            do
            {
                cout << "\n Novo NIF: ";
                getline(cin, nif);
                if (nif.find_first_not_of("1234567890\n") != string::npos || nif == "")
                    cout << "Invalid input" << endl;
            } while (nif.find_first_not_of("1234567890\n") != string::npos || nif == "");
            vetor[i]->setNome(nome);
            vetor[i]->setNif(nif);
        }
    }
    condominio.setCondominos(vetor);
    cout << "\n\nCondomino Editado!\n\n";
}

void Eliminar_Condomino(Condominio &condominio)
{
    int id, contador = 1;
    vector <Condomino *>::const_iterator it;
    vector<Condomino *> vetor = condominio.getCondominos();
    condominio.Mostrar_Condominos();
    cout << "\n Condomino a eliminar: ";
    do{
        cin.clear();
        cin >> id;
        cin.ignore(1000, '\n');
    }while (id < 1 || id > condominio.numeroCondominos());
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
    condominio.setCondominos(vetor);
    cout << "\n\nCondomino Eliminado!\n\n";
}

void Adquirir_Habitacao(Condominio &condominio)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Adquirir Habitacao \n\n";
    condominio.Ler_Habitacoes("Habitacoes.txt");
    condominio.Ler_Condominos("Condominos.txt");
    int id, id2, contador = 0, contador2 = 0;
    vector <Condomino *>::const_iterator itc;
    vector<Condomino *> vetor_c = condominio.getCondominos();
    vector<Habitacao *>::const_iterator its;
    vector<Habitacao *> vetor_s = condominio.getHabitacoes();
    condominio.Mostrar_Condominos();
    cout << "\n Condomino que deseja adquirir uma habitacao: ";
    do{
        cin.clear();
        cin >> id;
        cin.ignore(1000, '\n');
    }while (id < 1 || id > condominio.numeroCondominos());
    for (itc = vetor_c.begin() ; itc != vetor_c.end() ; itc++)
    {
        if (contador == id-1)
        {
            cout << "\n A adquirir habitacao para " << (*itc)->getNome() << "... " << endl << endl;
            vector <Habitacao *> disponiveis = condominio.Mostrar_Habitacoes_Disponiveis();
            if(disponiveis.size() == 0)
            {
                cout << "\n Nao existem Habitacoes Disponiveis para Compra\n\n";
                return;
            }
                cout << "\n Habitacao a adquirir: ";
            do{
                cin.clear();
                cin >> id2;
                cin.ignore(1000, '\n');
            }while (id2 < 1 || id2 > disponiveis.size());
            for (its = disponiveis.begin() ; its != disponiveis.end() ; its++)
            {
                if (contador2 == id2-1)
                {
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
    condominio.Escrever_Condominos("Condominos.txt");
    cout << "\n\n Habitacao Adquirida!\n\n";
}

void Remover_Habitacao(Condominio &condominio){
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Remover Habitacao \n\n";
    condominio.Ler_Habitacoes("Habitacoes.txt");
    condominio.Ler_Condominos("Condominos.txt");
    vector <Condomino *>::const_iterator itc;
    vector <Condomino *> vetor_c = condominio.getCondominos();
    vector <Habitacao *>::const_iterator its;
    int id, id2, contador = 0, contador2 = 0;
    condominio.Mostrar_Condominos();
    cout << "\n Condomino que deseja remover uma habitacao: ";
    do{
        cin.clear();
        cin >> id;
        cin.ignore(1000, '\n');
    }while (id < 1 || id > condominio.numeroCondominos());
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
                    break;
                }
                contador2++;
            }
            break;
        }
        contador++;
    }
    condominio.setCondominos(vetor_c);
    condominio.Escrever_Condominos("Condominos.txt");
    condominio.Escrever_Habitacoes("Habitacoes.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Adicionar_Servico(Condominio &condominio)
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
    condominio.adicionaServico(service);
    cout << "\n\nServico Adicionado!\n\n";
}

void Editar_Servico(Condominio &condominio)
{
    string alphabet = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ";
    string alphabetplusnum = "\n aáàãâbcçdeéèêfghiíìjklmnñoõòóôpqrstuúvwxyzAÁÀÃÂBCÇDEÉÈÊFGHIÍÌJKLMNÑOÓÒÕÔPQRSTUÚVWXYZ1234567890";
    string descricao;
    int id;
    vector<Servico *>::const_iterator it;
    vector<Servico *> vetor = condominio.getServicos();
    condominio.Mostrar_Servicos();
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
    condominio.setServicos(vetor);
    cout << "\n\nServico Editado!\n\n";
}

void Eliminar_Servico(Condominio &condominio)
{
    int id;
    vector<Servico *>::const_iterator it;
    vector<Servico *> vetor = condominio.getServicos();
    condominio.Mostrar_Servicos();
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
    condominio.setServicos(vetor);
    Servico::ultimo_id = vetor.size();
    cout << "\n\nServico Eliminado!\n\n";
}

void Requisitar_Servico(Condominio &condominio, CondomiX &gestao)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Requisitar Servico \n\n";
    gestao.Ler_Prestadores("Prestadores.txt");
    condominio.Ler_Habitacoes("Habitacoes.txt");
    condominio.Ler_Servicos("Servicos.txt");
    condominio.Ler_Condominos("Condominos.txt");
    int id, id2, contador = 0;
    vector <Condomino *>::const_iterator itc;
    vector<Condomino *> vetor_c = condominio.getCondominos();
    vector<Servico *>::const_iterator its;
    vector<Servico *> vetor_s = condominio.getServicos();
    condominio.Mostrar_Condominos();
    cout << "\n Condomino que deseja requisitar um servico: ";
    do{
        cin.clear();
        cin >> id;
        cin.ignore(1000, '\n');
    }while (id < 1 || id > condominio.numeroCondominos());
    for (itc = vetor_c.begin() ; itc != vetor_c.end() ; itc++)
    {
        if (contador == id-1)
        {
            cout << "\n A requisitar servico para " << (*itc)->getNome() << "... " << endl << endl;
            condominio.Mostrar_Servicos();
            cout << "\n Servico a requisitar: ";
            do{
                cin.clear();
                cin >> id2;
                cin.ignore(1000, '\n');
            }while (id2 < 1 || id2 > condominio.numeroCondominos());
            for (its = vetor_s.begin() ; its != vetor_s.end() ; its++)
            {
                if ((*its)->getId() == id2){
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
            }
            break;
        }
        contador++;
    }
    condominio.setCondominos(vetor_c);
    condominio.Escrever_Condominos("Condominos.txt");
    gestao.Escrever_Prestadores("Prestadores.txt");
    cout << "\n\nServico Requisitado!\n\n";
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Terminar_Servico(Condominio &condominio, CondomiX &gestao)
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Cancelar Servico \n\n";
    gestao.Ler_Prestadores("Prestadores.txt");
    condominio.Ler_Habitacoes("Habitacoes.txt");
    condominio.Ler_Servicos("Servicos.txt");
    condominio.Ler_Servicos_Efetuados("ServicosEfetuados.txt");
    condominio.Ler_Condominos("Condominos.txt");
    vector <Condomino *>::const_iterator itc;
    vector <Condomino *> vetor_c = condominio.getCondominos();
    vector <Servico *>::const_iterator its;
    vector <Servico *> vetor_e = condominio.getServicosEfetuados();
    int id, id2, contador = 0, contador2 = 0;
    condominio.Mostrar_Condominos();
    cout << "\n Condomino que deseja cancelar um servico: ";
    do{
        cin.clear();
        cin >> id;
        cin.ignore(1000, '\n');
    }while (id < 1 || id > condominio.numeroCondominos());
    for (itc = vetor_c.begin() ; itc != vetor_c.end() ; itc++)
    {
        if (contador == id-1)
        {
            vector<Servico *> vetor_s = (*itc)->getServicos();
            cout << "\n A cancelar servico de " << (*itc)->getNome() << "... " << endl << endl;
            (*itc)->Mostrar_Servicos();
            cout << "\n Servico a cancelar: ";
            do{
                cin.clear();
                cin >> id2;
                cin.ignore(1000, '\n');
            }while (id2 < 1 || id2 > vetor_s.size());
            for (its = vetor_s.begin() ; its != vetor_s.end() ; its++)
            {
                if (contador2 == id2-1)
                {
                    vetor_e.push_back(*its);
                    vetor_s.erase(its);
                    (*itc)->setServicos(vetor_s);
                    break;
                }
                contador2++;
            }
            break;
        }
        contador++;
    }
    condominio.setCondominos(vetor_c);
    condominio.setServicosEfetuados(vetor_e);
    condominio.Escrever_Condominos("Condominos.txt");
    condominio.Escrever_Servicos_Efetuados("ServicosEfetuados.txt");
    cout << "\n\nServico Cancelado!\n\n";
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
