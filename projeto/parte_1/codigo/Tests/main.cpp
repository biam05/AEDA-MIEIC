//#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include "Condominio.h"
#include "utils.h"

using namespace std;

Condominio condominio;
CondomiX gestao;

void Menu_Visualizar_Informacoes();
void Menu_Gestao_Habitacoes();
void Menu_Gestao_Condominos();
void Menu_Gestao_Servicos();
void Menu_Dados_Empresa();

void Menu_Visualizar_Habitacoes();
void Menu_Visualizar_Condominos();

void Menu_Adicionar_Habitacao();
void Menu_Editar_Habitacao();
void Menu_Eliminar_Habitacao();

void Menu_Adicionar_Condomino();
void Menu_Editar_Condomino();
void Menu_Eliminar_Condomino();
void Menu_Adquirir_Habitacao();

void Menu_Adicionar_Servico();
void Menu_Editar_Servico();
void Menu_Eliminar_Servico();
void Menu_Servicos_Efetuados();
void Menu_Visualizar_Servicos_e_Prestadores();


void Menu_Principal()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Menu Principal \n\n";
    cout << "\t Utilizador \n\n";
    cout << "[1] Visualizar Informacoes \n";
    cout << "[2] Adquirir Habitacao \n";
    cout << "[3] Remover Habitacao \n";
    cout << "[4] Requisitar Servico \n";
    cout << "[5] Terminar Servico \n";
    cout << "\n\t Administrador \n\n";
    cout << "[6] Gestao de Habitacoes \n";
    cout << "[7] Gestao de Condominos \n";
    cout << "[8] Gestao de Servicos \n";
    cout << "[9] Dados da Empresa \n\n";
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
            Menu_Visualizar_Informacoes(); break;
        case '2':
            Menu_Adquirir_Habitacao(); break;
        case '3':
            Remover_Habitacao(condominio); break;
        case '4':
            Requisitar_Servico(condominio, gestao); break;
        case '5':
            Terminar_Servico(condominio, gestao); break;
        case '6':
            Menu_Gestao_Habitacoes(); break;
        case '7':
            Menu_Gestao_Condominos(); break;
        case '8':
            Menu_Gestao_Servicos(); break;
        case '9':
            Menu_Dados_Empresa(); break;
        case '0':
            break;
        default:
            Menu_Principal(); break;
    }
}

void Menu_Visualizar_Informacoes()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Menu de Visualizacao \n\n";
    cout << "[1] Visualizar Habitacoes \n";
    cout << "[2] Visualizar Condominos \n";
    cout << "[3] Visualizar Servicos \n";
    cout << "[4] Visualizar Prestadores \n";
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
            Menu_Visualizar_Habitacoes(); break;
        case '2':
            Menu_Visualizar_Condominos(); break;
        case '3':
            Visualizar_Servicos(condominio); break;
        case '4':
            Visualizar_Prestadores(condominio, gestao); break;
        case '5':
            Menu_Principal(); break;
        default:
            Menu_Visualizar_Informacoes(); break;
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
            Visualizar_Todas_Habitacoes(condominio); break;
        case '2':
            Visualizar_Habitacao_Morada(condominio); break;
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
            Visualizar_Todos_Condominos(condominio); break;
        case '2':
            Visualizar_Condominos_NIF(condominio); break;
        case '3':
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

void Menu_Dados_Empresa() // Deixar para ultimo. Vai apresentar as estatisticas, lucros, etc...
{
    gestao.Ler_Prestadores("Prestadores.txt");
    condominio.Ler_Habitacoes("Habitacoes.txt");
    condominio.Ler_Servicos("Servicos.txt");
    condominio.Ler_Condominos("Condominos.txt");
    condominio.Ler_Servicos_Efetuados("ServicosEfetuados.txt");
    system("CLS");
    Logotipo();
    int contador = 0, habitacoes_vendidas = 0;
    vector<Condomino *> vetor = condominio.getCondominos();
    vector<Condomino *>::const_iterator it;
    for (it = vetor.begin() ; it != vetor.end() ; it++) {
        habitacoes_vendidas += (*it)->numeroHabitacoes();
    }
    cout << "\n\n\t\t\t\t           Dados da Empresa \n\n";
    cout << "----------------------------------------------------------------------------------------------------------\n";
    cout << "Numero de Habitacoes: " << condominio.numeroHabitacoes() << "\t\tNumero de Condominos: " << condominio.numeroCondominos() << "\t\t\tNumero de Servicos: " << condominio.numeroServicos();
    cout << "\n\nNumero de Habitacoes Vendidas: " << habitacoes_vendidas << "\tNumero de Servicos Efetuados: " << condominio.numeroServicosEfetuados() << "\t\tValor Mensal Obtido: " << Calcular_Valor_Mensal(condominio);
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
    condominio.Ler_Habitacoes("Habitacoes.txt");
    Logotipo();
    cout << "\n\n\t\t     Adicionar Habitacao \n\n";
    Adicionar_Habitacao(condominio);
    condominio.Escrever_Habitacoes("Habitacoes.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Editar_Habitacao()
{
    system("CLS");
    condominio.Ler_Habitacoes("Habitacoes.txt");
    Logotipo();
    cout << "\n\n\t\t     Editar Habitacao \n\n";
    Editar_Habitacao(condominio);
    condominio.Escrever_Habitacoes("Habitacoes.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Eliminar_Habitacao()
{
    system("CLS");
    condominio.Ler_Habitacoes("Habitacoes.txt");
    Logotipo();
    cout << "\n\n\t\t     Eliminar Habitacao \n\n";
    Eliminar_Habitacao(condominio);
    condominio.Escrever_Habitacoes("Habitacoes.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Adicionar_Condomino()
{
    system("CLS");
    condominio.Ler_Habitacoes("Habitacoes.txt");
    condominio.Ler_Condominos("Condominos.txt");
    Logotipo();
    cout << "\n\n\t\t     Adicionar Condomino \n\n";
    Adicionar_Condomino(condominio);
    condominio.Escrever_Condominos("Condominos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Editar_Condomino()
{
    system("CLS");
    condominio.Ler_Habitacoes("Habitacoes.txt");
    condominio.Ler_Condominos("Condominos.txt");
    Logotipo();
    cout << "\n\n\t\t     Editar Condomino \n\n";
    Editar_Condomino(condominio);
    condominio.Escrever_Condominos("Condominos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Eliminar_Condomino()
{
    system("CLS");
    condominio.Ler_Habitacoes("Habitacoes.txt");
    condominio.Ler_Condominos("Condominos.txt");
    Logotipo();
    cout << "\n\n\t\t     Eliminar Condomino \n\n";
    Eliminar_Condomino(condominio);
    condominio.Escrever_Condominos("Condominos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Adquirir_Habitacao()
{
    system("CLS");
    condominio.Ler_Habitacoes("Habitacoes.txt");
    condominio.Ler_Condominos("Condominos.txt");
    Logotipo();
    cout << "\n\n\t\t     Adquirir Habitacao \n\n";
    Adquirir_Habitacao(condominio);
    condominio.Escrever_Condominos("Condominos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Adicionar_Servico()
{
    system("CLS");
    condominio.Ler_Servicos("Servicos.txt");
    Logotipo();
    cout << "\n\n\t\t     Adicionar Servico \n\n";
    Adicionar_Servico(condominio);
    condominio.Escrever_Servicos("Servicos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Editar_Servico()
{
    system("CLS");
    condominio.Ler_Servicos("Servicos.txt");
    Logotipo();
    cout << "\n\n\t\t     Editar Servico \n\n";
    Editar_Servico(condominio);
    condominio.Escrever_Servicos("Servicos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Eliminar_Servico()
{
    system("CLS");
    condominio.Ler_Servicos("Servicos.txt");
    Logotipo();
    cout << "\n\n\t\t     Eliminar Servico \n\n";
    Eliminar_Servico(condominio);
    condominio.Escrever_Servicos("Servicos.txt");
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

void Menu_Servicos_Efetuados()
{
    system("CLS");
    Logotipo();
    cout << "\n\n\t\t     Servicos Efetuados \n\n";
    condominio.Ler_Servicos_Efetuados("ServicosEfetuados.txt");
    vector <Servico *> vetor = condominio.getServicosEfetuados();
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
    condominio.Ler_Servicos("Servicos.txt");
    gestao.Ler_Prestadores("Prestadores.txt");
    Logotipo();
    cout << "\n\n\t\t     Servicos Existentes e Seus Prestadores \n\n";
    condominio.Mostrar_Servicos_e_Prestadores(gestao);
    cout << endl;
    char sair = Sair_Programa();
    if (sair == 'N' || sair == 'n')
        Menu_Principal();
}

int main(int argc, char* argv[]) {
    Menu_Principal();
    system("pause");
    return 0;
}