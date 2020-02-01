#ifndef AEDA1920_FP02_SOL_CONDOMIX_H
#define AEDA1920_FP02_SOL_CONDOMIX_H
#include <vector>
#include <set>
#include "Condominio.h"
#include "PrestadorServicoLimpeza.h"
#include "bst.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Servico.h"
#include "Habitacao.h"
#include "Condomino.h"

class Condominio;

using namespace std;

/// \brief Classe CondomiX representa a Condomix, a empresa especialista na gestão de condomínios, através de um
/// contentor de objetos para armazenar os prestadores de serviço de limpeza e através de uma árvore binária de pesquisa,
/// onde é guardada a informação dos condomínios que administra.
class CondomiX {

    ///\brief Árvore binária de pesquisa onde é guardada a informação dos condomínios.
    BST<Condominio> condominios;

    /// \brief Contentor onde estão armazenados os serviços da CondomiX.
    vector<Servico *> servicos;

    /// \brief Contentor onde estão armazenados os serviços efetuados da CondomiX.
    vector<Servico *> servicos_efetuados;

public:

    /// \brief Constrói uma instância de CondomiX sem parâmetros.
    CondomiX();

    ///\brief Devolve a árvore binária de pesquisa onde é guardada a informação dos condomínios.
    ///\return A árvore binária de pesquisa onde é guardada a informação dos condomínios.
    BST<Condominio> getCondominios() const;

    /// \brief Adiciona um novo condomínio à árvore binária de pesquisa.
    /// \param c1: Condomínio que se pretende adicionar à árvore binária de pesquisa.
    void adicionaCondominio(const Condominio &c1);

    ///\brief Insere na BST os condomínios existentes no contentor de condomínios passado por parâmetro.
    ///\param condominios1: O contentor onde estão armazenados os condomínios que se pretende inserir na BST.
    void adicionaCondominios(const vector<Condominio> &condominios1);

    /// \brief Remove um condomínio da árvore binária de pesquisa.
    /// \param c1: Condomínio que se pretende remover da árvore binária de pesquisa.
    void removeCondominio(const Condominio &c1);

    ///\brief Imprime no monitor a informação dos condomínios da CondomiX ordenados por número de habitações e,
    /// em caso de empate, por número de vivendas.
    void imprime() const;

    ///\brief Devolve as designações dos condomínios que estão na localização indicada como argumento.
    /// \param localizacao: A localização que se pretende consultar.
    /// \return As designações dos condomínios que estão na localização indicada como argumento.
    vector<string> getDesignacoesPorLocalizacao(string localizacao) ;

    ///\brief Devolve os condomínios que possuem um número de habitações igual ou inferior ao número indicado como argumento.
    ///\param numeroHabitacoes: O número máximo de habitações que o condomínio possui.
    /// \return Os condomínios que possuem um número de habitações igual ou inferior ao número indicado como argumento.
    vector<Condominio> getCondominiosPorHabitacoes(int numeroHabitacoes);

    /// \brief Remove o condomínio que possui a designação indicada como argumento.
    ///\param designacao: A designação do condomínio que se pretende remover da árvore binária de pesquisa.
    ///\return Se a condomínio se pretende remover existir, o método retorna true, senão retorna false.
    bool removeCondominioPorDesignacao(string designacao);

    /// \brief Devolve o condominio com a designacao dada
    /// \param designacao: designacao a procurar
    /// \return condominio com a designacao
    Condominio getCondominioPorDesignacao(string designacao);

    /// \brief Contentor onde estão armazenados os prestadores de serviço de limpeza da Condomix.
    vector<PrestadorServicoLimpeza *> prestadoresServicoLimpeza;

    /// \brief Devolve o número de condominios da CondomiX.
    /// \return O número de condominios da CondomiX.
    int numeroCondominios() const;

    /// \brief Devolve o número de serviços da CondomiX.
    /// \return O número de serviços da CondomiX.
    int numeroServicos() const;

    /// \brief Devolve o número de serviços efetuados da CondomiX.
    /// \return O número de serviços efetuados da CondomiX.
    int numeroServicosEfetuados() const;

    /// \brief Adiciona um novo serviço ao contentor da CondomiX.
    /// \param s1: Serviço que se pretende adicionar ao contentor da CondomiX.
    void adicionaServico(Servico *s1);

    /// \brief Adiciona um novo serviço efetuado ao contentor da CondomiX.
    /// \param s1: Serviço efetuado que se pretende adicionar ao contentor da CondomiX.
    void adicionaServicoEfetuado(Servico *s1);

    /// \brief Devolve o contentor onde estão armazenados os serviços da CondomiX.
    /// \return O contentor onde estão armazenados os serviços da CondomiX.
    vector<Servico *> getServicos() const;

    /// \brief Devolve os prestadores de serviço de limpeza da Condomix.
    /// \return O contentor onde estão armazenados os prestadores da CondomiX.
    vector<PrestadorServicoLimpeza *> getPrestadores() const;

    /// \brief Devolve o contentor onde estão armazenados os serviços efetuados da CondomiX.
    /// \return O contentor onde estão armazenados os serviços efetuados da CondomiX.
    vector<Servico *> getServicosEfetuados() const;

    /// \brief Modifica o contentor onde estão armazenadas os serviços da CondomiX.
    /// \param v: O novo contentor onde estão armazenadas os serviços da CondomiX.
    void setServicos(const vector<Servico *> &v);

    /// \brief Modifica o contentor onde estão armazenadas os serviços efetuados da CondomiX.
    /// \param v: O novo contentor onde estão armazenadas os serviços efetuados da CondomiX.
    void setServicosEfetuados(const vector<Servico *> &v);

    /// \brief Escreve as características de todos os servios da CondomiX.
    /// \return As características de todos os serviços da CondomiX.
    string escreveTotalServicos()const;

    /// \brief Devolve as características dos prestadores de serviço de limpeza da CondomiX.
    /// \return As características dos prestadores de serviço de limpeza da CondomiX.
    string escreverTotalPrestadoresServicoLimpeza()const;

    /// \brief Escreve as características de todos os Antigos Condóminos da CondomiX.
    /// \return As características de todos os Antigos Condóminos da CondomiX.
    string escreveTotalAntigosCondominos()const;

    /// \brief Devolve o prestador de serviço de limpeza da CondomiX com menos horas de trabalho.
    /// \return O prestador de serviço de limpeza da CondomiX com menos horas de trabalho.
    PrestadorServicoLimpeza * procurarPrestadorServicoLimpeza () const;

    /// \brief Procura a habitação da CondomiX que tem o código postal recebido.
    /// \param cp: O código postal da habitação a ser procurada.
    /// \param designacao: A designação do Condomínio em que está a Habitação Procurada.
    /// \param localizacao: A localização do Condomínio em que está a Habitação Procurada.
    /// \return A Habitação com o código de postal recebido.
    Habitacao*  Procurar_Habitacao(string cp, string &designacao, string &localizacao) const;

    /// \brief Procura o condómino na CondomiX com o NIF recebido.
    /// \param nif: O NIF do condómino a ser procurado.
    /// \param designacao: A designacao do Condominio a que pertence o Condómino Procurado.
    /// \param localizacao: A localização do Condomínio a que pertence o Condómino Procurado.
    /// \return O Condomino com o NIF dado.
    Condomino* Procurar_Condomino(string nif, string &designacao, string &localizacao) const;

    /// \brief Procura o Antigo Condómino na CondomiX com o NIF recebido.
    /// \param nif: O NIF do Antigo Condómino a ser procurado.
    /// \param designacao: A designacao do Condominio a que pertence o Antigo Condómino Procurado.
    /// \param localizacao: A localização do Condomínio a que pertence o Antigo Condómino Procurado.
    /// \return O Antigo Condomino com o NIF dado.
    AntigoCondomino* Procurar_Antigo_Condomino(string nif, string &designacao, string &localizacao) const;

    /// \brief Lê os serviços de um ficheiro.
    /// \param ficheiro: Ficheiro que contém a informaçõo dos serviços.
    void Ler_Servicos(const string &ficheiro);

    /// \brief Lê os prestadores de serviço de limpeza de um ficheiro.
    /// \param ficheiro: Ficheiro que contem a informaçõo dos prestadores de serviço de limpeza da CondomiX.
    void Ler_Prestadores(const string &ficheiro);

    /// \brief Lê os serviços efetuados de um ficheiro.
    /// \param ficheiro: Ficheiro que contém a informaçõo dos serviços efetuados.
    void Ler_Servicos_Efetuados(const string &ficheiro);

    /// \brief Lê as habitações de um ficheiro.
    /// \param ficheiro: Ficheiro que contém a informaçõo das habitações.
    void Ler_Habitacoes(const string &ficheiro);

    /// \brief Lê os condominos de um ficheiro.
    /// \param ficheiro: Ficheiro que contém a informaçõo dos condominos.
    void Ler_Condominos(const string &ficheiro);

    /// \brief Lê os Antigos Condóminos de um ficheiro.
    /// \param ficheiro: Ficheiro que contém a informaçõo dos Antigos Condóminos.
    void Ler_Antigos_Condominos(const string &ficheiro);

    /// \brief Lê os transportes de um ficheiro.
    /// \param ficheiro: Ficheiro que contém a informaçõo dos transportes.
    void Ler_Transportes(const string &ficheiro);

    /// \brief Guarda a informação dos serviços num ficheiro para uso futuro.
    /// \param ficheiro: Ficheiro onde é guardada a informação dos serviços.
    void Escrever_Servicos(const string &ficheiro);

    /// \brief Guarda a informação das características dos prestadores de serviço de limpeza num ficheiro para uso futuro.
    /// \param ficheiro: Ficheiro onde é guardada a informção dos prestadores de serviço de limpeza.
    void Escrever_Prestadores(const string &ficheiro);

    /// \brief Guarda a informação dos serviços efetuados num ficheiro para uso futuro.
    /// \param ficheiro: Ficheiro onde é guardada a informação dos serviços efetuados.
    void Escrever_Servicos_Efetuados(const string &ficheiro);

    /// \brief Guarda a informação das habitações num ficheiro para uso futuro.
    /// \param ficheiro: Ficheiro onde é guardada a informação das habitações.
    void Escrever_Habitacoes(const string &ficheiro);

    /// \brief Guarda a informação dos condóminos num ficheiro para uso futuro.
    /// \param ficheiro: Ficheiro onde é guardada a informação dos condóminos.
    void Escrever_Condominos(const string &ficheiro);

    /// \brief Guarda a informação dos Antigos Condóminos num ficheiro para uso futuro.
    /// \param ficheiro: Ficheiro onde é guardada a informação dos Antigos Condóminos.
    void Escrever_Antigos_Condominos(const string &ficheiro);

    /// \brief Guarda a informação dos transportes num ficheiro para uso futuro.
    /// \param ficheiro: Ficheiro onde é guardada a informação dos transportes.
    void Escrever_Transportes(const string &ficheiro);

    /// \brief Mostra as características dos serviços da CondomiX.
    void Mostrar_Servicos() const;

    /// \brief Mostra as características de todos os prestadores de serviço de limpeza da CondomiX.
    void Mostrar_Prestadores() const;

    /// \brief Mostra as características dos serviços do Condominio e dos prestadores de serviço de limpeza da CondomiX.
    void Mostrar_Servicos_e_Prestadores() const;

    /// \brief Mostra as características dos condominios da CondomiX.
    void Mostrar_Condominios() const;
};


#endif
