//#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "Condominio.h"
#include "utils.h"

using namespace std;

Condominio condominio;
CondomiX gestao;

void Menu_Utilizador();
void Menu_Administrador();

void Menu_Visualizar_Informacoes();
void Menu_Gestao_Habitacoes();
void Menu_Gestao_Condominos();
void Menu_Gestao_Servicos();
void Menu_Gestao_Transportes();
void Menu_Gestao_Condominios();
void Menu_Dados_Empresa();

void Menu_Visualizar_Condominios();
void Menu_Visualizar_Habitacoes();
void Menu_Visualizar_Condominos();
void Menu_Visualizar_Transportes();

void Menu_Adicionar_Habitacao();
void Menu_Editar_Habitacao();
void Menu_Eliminar_Habitacao();

void Menu_Adicionar_Condomino();
void Menu_Editar_Condomino();
void Menu_Eliminar_Condomino();
void Menu_Adquirir_Habitacao();

void Menu_Adicionar_Condominio();
void Menu_Editar_Condominio();
void Menu_Eliminar_Condominio();

void Menu_Adicionar_Servico();
void Menu_Editar_Servico();
void Menu_Eliminar_Servico();
void Menu_Adicionar_Transporte();
void Menu_Editar_Transporte();
void Menu_Eliminar_Transporte();
void Menu_Servicos_Efetuados();
void Menu_Visualizar_Servicos_e_Prestadores();


void Menu_Principal()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Menu Principal \n\n";
    cout << "[1] Utilizador \n";
    cout << "[2] Administrador \n";
    cout << "[0] Sair do Programa \n";
    cout << "\nOpcao: ";

    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';

    switch(opcao)
    {
        case '1':
            Menu_Utilizador(); break;
        case '2':
            Menu_Administrador(); break;
        case '0':
            break;
        default:
            Menu_Principal(); break;
    }
}

void Menu_Utilizador()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Menu do Utilizador \n\n";
    cout << "[1] Visualizar Informacoes \n";
    cout << "[2] Adquirir Habitacao \n";
    cout << "[3] Remover Habitacao \n";
    cout << "[4] Requisitar Servico \n";
    cout << "[5] Terminar Servico \n";
    cout << "[6] Cancelar \n\n";
    cout << "\nOpcao: ";

    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';

    switch(opcao)
    {
        case '1':
            Menu_Visualizar_Informacoes(); break;
        case '2':
            Menu_Adquirir_Habitacao(); break;
        case '3':
            Remover_Habitacao(gestao); break;
        case '4':
            Requisitar_Servico(gestao); break;
        case '5':
            Terminar_Servico(gestao); break;
        case '6':
            Menu_Principal(); break;
        default:
            Menu_Utilizador(); break;
    }
}

void Menu_Administrador()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Menu do Administrador \n\n";
    cout << "[1] Gestao de Habitacoes \n";
    cout << "[2] Gestao de Condominos \n";
    cout << "[3] Gestao de Servicos \n";
    cout << "[4] Gestao de Transportes \n";
    cout << "[5] Gestao de Condominios \n";
    cout << "[6] Dados da Empresa \n";
    cout << "[7] Cancelar \n\n";
;    cout << "\nOpcao: ";

    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';

    switch(opcao)
    {
        case '1':
            Menu_Gestao_Habitacoes(); break;
        case '2':
            Menu_Gestao_Condominos(); break;
        case '3':
            Menu_Gestao_Servicos(); break;
        case '4':
            Menu_Gestao_Transportes(); break;
        case '5':
            Menu_Gestao_Condominios(); break;
        case '6':
            Menu_Dados_Empresa(); break;
        case '7':
            Menu_Principal(); break;
        default:
            Menu_Administrador(); break;
    }
}

void Menu_Visualizar_Informacoes()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Menu de Visualizacao \n\n";
    cout << "[1] Visualizar Condominios \n";
    cout << "[2] Visualizar Habitacoes \n";
    cout << "[3] Visualizar Condominos \n";
    cout << "[4] Visualizar Servicos \n";
    cout << "[5] Visualizar Prestadores \n";
    cout << "[6] Visualizar Transportes \n";
    cout << "[7] Cancelar \n";
    cout << "\nOpcao: ";

    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';
    switch(opcao)
    {
        case '1':
            Menu_Visualizar_Condominios(); break;
        case '2':
            Menu_Visualizar_Habitacoes(); break;
        case '3':
            Menu_Visualizar_Condominos(); break;
        case '4':
            Visualizar_Servicos(condominio,gestao); break;
        case '5':
            Visualizar_Prestadores(condominio, gestao); break;
        case '6':
            Menu_Visualizar_Transportes(); break;
        case '7':
            Menu_Principal(); break;
        default:
            Menu_Visualizar_Informacoes(); break;
    }
}

void Menu_Visualizar_Condominios() {
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Menu de Visualizacao de Condominios \n\n";
    cout << "[1] Visualizar Todos os Condominios \n";
    cout << "[2] Visualizar Condominio com um dado numero maximo de Habitacoes \n";
    cout << "[3] Cancelar \n";
    cout << "\nOpcao: ";
    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';
    switch(opcao)
    {
        case '1':
            Visualizar_Todos_Condominios(gestao); break;
        case '2':
            Visualizar_Condominio_Numero_Habitacoes(gestao); break;
        case '3':
            Menu_Principal(); break;
        default:
            Menu_Visualizar_Habitacoes(); break;
    }
}

void Menu_Visualizar_Habitacoes()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Menu de Visualizacao de Habitacoes \n\n";
    cout << "[1] Visualizar Todas as Habitacoes (Ordem Decrescente de Area Habitacional) \n";
    cout << "[2] Visualizar Habitacao pela Morada \n";
    cout << "[3] Cancelar \n";
    cout << "\nOpcao: ";
    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';
    switch(opcao)
    {
        case '1':
            Visualizar_Todas_Habitacoes(gestao); break;
        case '2':
            Visualizar_Habitacao_Morada(gestao); break;
        case '3':
            Menu_Principal(); break;
        default:
            Menu_Visualizar_Habitacoes(); break;
    }
}

void Menu_Visualizar_Condominos()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Menu de Visualizacao de Condominos \n\n";
    cout << "[1] Visualizar Todos os Condominos (Ordem Crescente do Nome) \n";
    cout << "[2] Visualizar Condomino pelo NIF \n";
    cout << "[3] Visualizar Todos os Antigos Condominos \n";
    cout << "[4] Visualizar Antigo Condomino pelo NIF \n";
    cout << "[5] Cancelar \n";
    cout << "\nOpcao: ";
    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';
    switch(opcao)
    {
        case '1':
            Visualizar_Todos_Condominos(gestao); break;
        case '2':
            Visualizar_Condominos_NIF(gestao); break;
        case '3':
            Visualizar_Todos_Antigos_Condominos(gestao); break;
        case '4':
            Visualizar_Antigos_Condominos_NIF(gestao); break;
        case '5':
            Menu_Principal(); break;
        default:
            Menu_Visualizar_Condominos(); break;
    }
}

void Menu_Gestao_Habitacoes()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Gestao de Habitacoes \n\n";
    cout << "[1] Adicionar Habitacao \n";
    cout << "[2] Editar Habitacao \n";
    cout << "[3] Eliminar Habitacao \n";
    cout << "[4] Cancelar \n";
    cout << "\nOpcao: ";

    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';
    switch(opcao)
    {
        case '1':
            Menu_Adicionar_Habitacao(); break;
        case '2':
            Menu_Editar_Habitacao(); break;
        case '3':
            Menu_Eliminar_Habitacao(); break;
        case '4':
            Menu_Principal(); break;
        default:
            Menu_Gestao_Habitacoes(); break;
    }
}

void Menu_Gestao_Condominos()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Gestao de Condominos \n\n";
    cout << "[1] Adicionar Condomino \n";
    cout << "[2] Editar Condomino \n";
    cout << "[3] Eliminar Condomino \n";
    cout << "[4] Cancelar \n";
    cout << "\nOpcao: ";

    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';
    switch(opcao)
    {
        case '1':
            Menu_Adicionar_Condomino(); break;
        case '2':
            Menu_Editar_Condomino(); break;
        case '3':
            Menu_Eliminar_Condomino(); break;
        case '4':
            Menu_Principal(); break;
        default:
            Menu_Gestao_Condominos(); break;
    }
}

void Menu_Gestao_Servicos() // funcoes a ser alteradas, pq os serviços sao geridos de maneira diferente
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Gestao de Servicos \n\n";
    cout << "[1] Adicionar Servico \n";
    cout << "[2] Editar Servico \n";
    cout << "[3] Eliminar Servico \n";
    cout << "[4] Cancelar \n";
    cout << "\nOpcao: ";

    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';
    switch(opcao)
    {
        case '1':
            Menu_Adicionar_Servico(); break;
        case '2':
            Menu_Editar_Servico(); break;
        case '3':
            Menu_Eliminar_Servico(); break;
        case '4':
            Menu_Principal(); break;
        default:
            Menu_Gestao_Servicos(); break;
    }
}

void Menu_Gestao_Transportes() // funcoes a ser alteradas, pq os serviços sao geridos de maneira diferente
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Gestao de Transportes \n\n";
    cout << "[1] Adicionar Transporte \n";
    cout << "[2] Editar Transporte\n";
    cout << "[3] Eliminar Transporte \n";
    cout << "[4] Cancelar \n";
    cout << "\nOpcao: ";

    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';
    switch(opcao)
    {
        case '1':
            Menu_Adicionar_Transporte(); break;
        case '2':
            Menu_Editar_Transporte(); break;
        case '3':
            Menu_Eliminar_Transporte(); break;
        case '4':
            Menu_Principal(); break;
        default:
            Menu_Gestao_Transportes(); break;
    }
}

void Menu_Gestao_Condominios()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Gestao de Condominios \n\n";
    cout << "[1] Adicionar Condominio \n";
    cout << "[2] Editar Condominio\n";
    cout << "[3] Eliminar Condominio \n";
    cout << "[4] Cancelar \n";
    cout << "\nOpcao: ";

    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';
    switch(opcao)
    {
        case '1':
            Menu_Adicionar_Condominio(); break;
        case '2':
            Menu_Editar_Condominio();break;
        case '3':
            Menu_Eliminar_Condominio();break;
        case '4':
            Menu_Principal(); break;
        default:
            Menu_Gestao_Transportes(); break;
    }
}

void Menu_Dados_Empresa() // Deixar para ultimo. Vai apresentar as estatisticas, lucros, etc...
{
    gestao.Ler_Prestadores("Prestadores.txt");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Servicos("Servicos.txt");
    gestao.Ler_Condominos("Condominos.txt");
    gestao.Ler_Servicos_Efetuados("ServicosEfetuados.txt");
    system("CLS");
    Logotipo();
    int habitacoes_vendidas = 0, habitacoes_totais = 0, condominos_totais = 0, valor_mensal_total = 0;
    BST<Condominio> condominios = gestao.getCondominios();
    BSTItrIn<Condominio> ita(condominios);
    while(!ita.isAtEnd())
    {
        Condominio cond = ita.retrieve();
        vector<Condomino*> condominos = ita.retrieve().getCondominos();
        vector<Condomino*>::const_iterator it;
        vector<Habitacao*> habitacoes = ita.retrieve().getHabitacoes();
        habitacoes_totais += habitacoes.size();
        for(it = condominos.begin(); it != condominos.end(); it++){
            habitacoes_vendidas += (*it)->numeroHabitacoes();
            condominos_totais++;
            valor_mensal_total += Calcular_Valor_Mensal(cond);
        }

        ita.advance();
    }

    cout << "\n\n\t\t\t\t           Dados da Empresa \n\n";
    cout << "----------------------------------------------------------------------------------------------------------\n";
    cout << "Numero de Habitacoes: " << habitacoes_totais << "\t\tNumero de Condominos: " << condominos_totais << "\t\t\tNumero de Servicos: " << gestao.numeroServicos();
    cout << "\n\nNumero de Habitacoes Vendidas: " << habitacoes_vendidas << "\tNumero de Servicos Efetuados: " << gestao.numeroServicosEfetuados() << "\t\tValor Mensal Obtido: " << valor_mensal_total;
    cout << "\n----------------------------------------------------------------------------------------------------------\n\n";
    cout << "Visualizar: \n";
    cout << "[1] Servicos Efetuados \n";
    cout << "[2] Servicos Existentes e os Seus Prestadores \n";
    cout << "[3] Cancelar \n";
    cout << "\nOpcao: ";

    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';
    switch(opcao)
    {
        case '1':
            Menu_Servicos_Efetuados(); break;
        case '2':
            Menu_Visualizar_Servicos_e_Prestadores(); break;
        case '3':
            Menu_Principal(); break;
        default:
            Menu_Dados_Empresa(); break;
    }
}

void Menu_Adicionar_Habitacao()
{
    system("CLS");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    Logotipo();
    cout << "\n\n\t\t     Adicionar Habitacao \n\n";
    Adicionar_Habitacao(gestao);
    gestao.Escrever_Habitacoes("Habitacoes.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Editar_Habitacao()
{
    system("CLS");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    Logotipo();
    cout << "\n\n\t\t     Editar Habitacao \n\n";
    Editar_Habitacao(gestao);
    gestao.Escrever_Habitacoes("Habitacoes.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Eliminar_Habitacao()
{
    system("CLS");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    Logotipo();
    cout << "\n\n\t\t     Eliminar Habitacao \n\n";
    Eliminar_Habitacao(gestao);
    gestao.Escrever_Habitacoes("Habitacoes.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Adicionar_Condomino()
{
    system("CLS");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    Logotipo();
    cout << "\n\n\t\t     Adicionar Condomino \n\n";
    Adicionar_Condomino(gestao);
    gestao.Escrever_Condominos("Condominos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Editar_Condomino()
{
    system("CLS");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    Logotipo();
    cout << "\n\n\t\t     Editar Condomino \n\n";
    Editar_Condomino(gestao);
    gestao.Escrever_Condominos("Condominos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Eliminar_Condomino()
{
    system("CLS");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    Logotipo();
    cout << "\n\n\t\t     Eliminar Condomino \n\n";
    Eliminar_Condomino(gestao);
    gestao.Escrever_Condominos("Condominos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Adquirir_Habitacao()
{
    system("CLS");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    Logotipo();
    cout << "\n\n\t\t     Adquirir Habitacao \n\n";
    Adquirir_Habitacao(gestao);
    gestao.Escrever_Condominos("Condominos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Adicionar_Servico()
{
    system("CLS");
    gestao.Ler_Servicos("Servicos.txt");
    Logotipo();
    cout << "\n\n\t\t     Adicionar Servico \n\n";
    Adicionar_Servico(condominio,gestao);
    gestao.Escrever_Servicos("Servicos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Editar_Servico()
{
    system("CLS");
    gestao.Ler_Servicos("Servicos.txt");
    Logotipo();
    cout << "\n\n\t\t     Editar Servico \n\n";
    Editar_Servico(condominio,gestao);
    gestao.Escrever_Servicos("Servicos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Eliminar_Servico()
{
    system("CLS");
    gestao.Ler_Servicos("Servicos.txt");
    Logotipo();
    cout << "\n\n\t\t     Eliminar Servico \n\n";
    Eliminar_Servico(condominio,gestao);
    gestao.Escrever_Servicos("Servicos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Adicionar_Transporte()
{
    system("CLS");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Transportes("Transportes.txt");
    Logotipo();
    cout << "\n\n\t\t     Adicionar Transporte \n\n";
    Adicionar_Transporte(gestao);
    gestao.Escrever_Transportes("Transportes.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Editar_Transporte()
{
    system("CLS");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Transportes("Transportes.txt");
    Logotipo();
    cout << "\n\n\t\t     Editar Transporte \n\n";
    Editar_Transporte(gestao);
    gestao.Escrever_Transportes("Transportes.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Eliminar_Transporte()
{
    system("CLS");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Transportes("Transportes.txt");
    Logotipo();
    cout << "\n\n\t\t     Eliminar Transporte \n\n";
    Eliminar_Transporte(gestao);
    gestao.Escrever_Transportes("Transportes.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Servicos_Efetuados()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Servicos Efetuados \n\n";
    gestao.Ler_Servicos_Efetuados("ServicosEfetuados.txt");
    vector <Servico *> vetor = gestao.getServicosEfetuados();
    vector <Servico *>::const_iterator it;
    for (it = vetor.begin() ; it != vetor.end() ; it++)
    {
        cout << (*it)->info() << endl;
    }
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Visualizar_Servicos_e_Prestadores()
{
    system("CLS");
    gestao.Ler_Servicos("Servicos.txt");
    gestao.Ler_Prestadores("Prestadores.txt");
    Logotipo();
    cout << "\n\n\t\t     Servicos Existentes e Seus Prestadores \n\n";
    gestao.Mostrar_Servicos_e_Prestadores();
    cout << endl;
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Visualizar_Transportes()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Menu de Visualizacao de Transportes \n\n";
    cout << "[1] Visualizar Todos os Transportes \n";
    cout << "[2] Visualizar Transporte pelo Destino \n";
    cout << "[3] Visualizar Transporte mais Proximo \n";
    cout << "[4] Cancelar \n";
    cout << "\nOpcao: ";
    string name;
    cin >> name;
    char opcao;
    if(name.size() == 1) opcao = name[0];
    else opcao = '9';
    switch(opcao)
    {
    case '1':
        Visualizar_Transportes(gestao); break;
    case '2':
        Visualizar_Transporte_Perto_Destino(gestao); break;
    case '3':
        Visualizar_Transporte_Perto(gestao); break;
    case '4':
        Menu_Principal(); break;
    default:
    Menu_Visualizar_Condominos(); break;
    }
}

void Menu_Adicionar_Condominio()
{
    system("CLS");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    gestao.Ler_Transportes("Transportes.txt");
    Logotipo();
    cout << "\n\n\t\t     Adicionar Condominio \n\n";
    Adicionar_Condominio(gestao);                       /* !!!!!!!!!!!!!!!!!!!!!!!*/
    gestao.Escrever_Habitacoes("Habitacoes.txt");
    gestao.Escrever_Condominos("Condominos.txt");
    gestao.Escrever_Transportes("Transportes.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Editar_Condominio()
{
    system("CLS");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    gestao.Ler_Transportes("Transportes.txt");
    Logotipo();
    cout << "\n\n\t\t     Editar Condominio \n\n";
    Editar_Condominio(gestao);
    gestao.Escrever_Habitacoes("Habitacoes.txt");
    gestao.Escrever_Condominos("Condominos.txt");
    gestao.Escrever_Transportes("Transportes.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Eliminar_Condominio()
{
    system("CLS");
    gestao.Ler_Habitacoes("Habitacoes.txt");
    gestao.Ler_Condominos("Condominos.txt");
    Logotipo();
    cout << "\n\n\t\t     Eliminar Condominio \n\n";
    Eliminar_Condominio(gestao);
    gestao.Escrever_Habitacoes("Habitacoes.txt");
    gestao.Escrever_Condominos("Condominos.txt");
    gestao.Escrever_Transportes("Transportes.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

int main(int argc, char* argv[]) {
    Menu_Principal();
    system("pause");
    return 0;
}
