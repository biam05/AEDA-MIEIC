#ifndef AEDA1920_FP02_SOL_CONDOMINIO_H
#define AEDA1920_FP02_SOL_CONDOMINIO_H

#include <vector>
#include <iostream>
#include <string>
#include "Servico.h"
#include "Habitacao.h"
#include "Condomino.h"
#include "CondomiX.h"

using namespace std;

class Servico;
class Condomino;
class CondomiX;

///\brief Classe Condominio representa uma condomínio através do seu nome e de contentores de objetos para armazenar
/// as habitações, os condóminos, os serviços e os serviços efetuados.
class Condominio {
private:

    /// \brief O nome do Condominio.
    string nome;

    /// \brief Contentor onde estão armazenadas as habitações do Condominio.
    vector<Habitacao *> habitacoes;

    /// \brief Contentor onde estão armazenados os condóminos do Condominio.
    vector<Condomino *> condominos;

    /// \brief Contentor onde estão armazenados os serviços do Condominio.
    vector<Servico *> servicos;

    /// \brief Contentor onde estão armazenados os serviços efetuados do Condominio.
    vector<Servico *> servicos_efetuados;
public:

    /// \brief Devolve o número de habitações do Condominio.
    /// \return O número de habitações do Condominio.
    int numeroHabitacoes() const;

    /// \brief Devolve o número de condominos do Condominio.
    /// \return O número de condominos do Condominio.
    int numeroCondominos() const;

    /// \brief Devolve o número de serviços do Condominio.
    /// \return O número de serviços do Condominio.
    int numeroServicos() const;

    /// \brief Devolve o número de serviços efetuados do Condomínio.
    /// \return O número de serviços efetuados do Condomínio.
    int numeroServicosEfetuados() const;

    /// \brief Adiciona uma nova habitação ao contentor do Condominio.
    /// \param h1: Habitação que se pretende adicionar ao contentor do Condominio.
    void adicionaHabitacao(Habitacao *h1);

    /// \brief Valida se uma habitação já foi comprada.
    /// \param h1: Habitação a ser validada.
    /// \return true se a habitação recebida representar uma habitação que já foi comprada. Caso contrário, retorna false.
    bool validaHabitacao(Habitacao *h1) const;

    /// \brief Adiciona um novo condomino ao contentor do Condominio.
    /// \param c1: Condomino que se pretende adicionar ao contentor do Condominio.
    void adicionaCondomino(Condomino *c1);

    /// \brief Adiciona um novo serviço ao contentor do Condominio.
    /// \param s1: Serviço que se pretende adicionar ao contentor do Condominio.
    void adicionaServico(Servico *s1);

    /// \brief Adiciona um novo serviço efetuado ao contentor do Condominio.
    /// \param s1: Serviço efetuado que se pretende adicionar ao contentor do Condominio.
    void adicionaServicoEfetuado(Servico *s1);

    /// \brief Devolve o contentor onde estão armazenadas as habitações do Condominio.
    /// \return O contentor onde estão armazenadas as habitações do Condominio.
    vector<Habitacao *> getHabitacoes()const;

    /// \brief Modifica o contentor onde estão armazenadas as habitações do Condominio.
    /// \param h: O novo contentor onde estão armazenadas as habitações do Condominio.
    void setHabitacoes(const vector<Habitacao *> &h);

    /// \brief Devolve o contentor onde estão armazenados os condominos do Condominio.
    /// \return O contentor onde estão armazenados os condominos do Condominio.
    vector<Condomino *> getCondominos() const;

    /// \brief Modifica o contentor onde estão armazenadas os condominos do Condominio.
    /// \param c: O novo contentor onde estão armazenadas os condominos do Condominio.
    void setCondominos(const vector<Condomino *> &c);

    /// \brief Devolve o contentor onde estão armazenados os serviços do Condominio.
    /// \return O contentor onde estão armazenados os serviços do Condominio.
    vector<Servico *> getServicos() const;

    /// \brief Modifica o contentor onde estão armazenadas os serviços do Condominio.
    /// \param v: O novo contentor onde estão armazenadas os serviços do Condominio.
    void setServicos(const vector<Servico *> &v);

    /// \brief Devolve o contentor onde estão armazenados os serviços efetuados do Condominio.
    /// \return O contentor onde estão armazenados os serviços efetuados do Condominio.
    vector<Servico *> getServicosEfetuados() const;

    /// \brief Modifica o contentor onde estão armazenadas os serviços efetuados do Condominio.
    /// \param v: O novo contentor onde estão armazenadas os serviços efetuados do Condominio.
    void setServicosEfetuados(const vector<Servico *> &v);

    /// \brief Lê as habitações de um ficheiro.
    /// \param ficheiro: Ficheiro que contém a informaçõo das habitações.
    void Ler_Habitacoes(const string &ficheiro);

    /// \brief Guarda a informação das habitações num ficheiro para uso futuro.
    /// \param ficheiro: Ficheiro onde é guardada a informção das habitações.
    void Escrever_Habitacoes(const string &ficheiro);

    /// \brief Lê os condominos de um ficheiro.
    /// \param ficheiro: Ficheiro que contém a informaçõo dos condominos.
    void Ler_Condominos(const string &ficheiro);

    /// \brief Guarda a informação dos condóminos num ficheiro para uso futuro.
    /// \param ficheiro: Ficheiro onde é guardada a informção dos condóminos.
    void Escrever_Condominos(const string &ficheiro);

    /// \brief Lê os serviços de um ficheiro.
    /// \param ficheiro: Ficheiro que contém a informaçõo dos serviços.
    void Ler_Servicos(const string &ficheiro);

    /// \brief Guarda a informação dos serviços num ficheiro para uso futuro.
    /// \param ficheiro: Ficheiro onde é guardada a informção dos serviços.
    void Escrever_Servicos(const string &ficheiro);

    /// \brief Lê os serviços efetuados de um ficheiro.
    /// \param ficheiro: Ficheiro que contém a informaçõo dos serviços efetuados.
    void Ler_Servicos_Efetuados(const string &ficheiro);

    /// \brief Guarda a informação dos serviços efetuados num ficheiro para uso futuro.
    /// \param ficheiro: Ficheiro onde é guardada a informção dos serviços efetuados.
    void Escrever_Servicos_Efetuados(const string &ficheiro);

    /// \brief Mostra as características das habitações do Condominio.
    void Mostrar_Habitacoes() const;

    /// \brief Mostra as características dos condóminos do Condominio.
    void Mostrar_Condominos() const;

    /// \brief Mostra as características dos serviços do Condominio.
    void Mostrar_Servicos() const;

    /// \brief Mostra as características dos serviços do Condominio e dos prestadores de serviço de limpeza da CondomiX.
    void Mostrar_Servicos_e_Prestadores(CondomiX &gestao);

    /// \brief Procura a habitação do Condominio que tem o código postal recebido.
    /// \param cp: O código postal da habitação a ser procurada.
    /// \return A Habitação com o código de postal recebido.
    Habitacao*  Procurar_Habitacao(string cp) const;

    /// \brief Procura o condómino no Condominio com o NIF recebido.
    /// \param nif: O NIF do condómino a ser procurado.
    /// \return O Condomino com o NIF dado.
    Condomino* Procurar_Condomino(string nif) const;

    /// \brief Ordena os condominos do Condominio por nome.
    void ordenaCondominosPorNome();

    /// \brief Ordena as habitações do Condominio por área habitacional.
    void ordenaHabitacoesPorAreaHabitacional();

    /// \brief Escreve as características de todas as habitações do Condominio.
    /// \return As características de todas as habitações do Condominio.
    string escreveTotalHabitacoes()const;

    /// \brief Escreve as características de todos os condóminos do Condominio.
    /// \return As características de todas os condóminos do Condominio.
    string escreveTotalCondominos()const;

    /// \brief Escreve as características de todos os servios do Condominio.
    /// \return As características de todas os serviços do Condominio.
    string escreveTotalServicos()const;

    /// \brief Mostra as características das habitações do Condominio que ainda não foram compradas.
    /// \return As características das habitações do Condominio que ainda não foram compradas.
    vector <Habitacao *> Mostrar_Habitacoes_Disponiveis()const;
};

#endif
