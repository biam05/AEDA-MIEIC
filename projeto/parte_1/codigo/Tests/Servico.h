#ifndef AEDA1920_FP02_SOL_SERVICO_H
#define AEDA1920_FP02_SOL_SERVICO_H

#include <string>
#include "Condominio.h"
#include "PrestadorServicoLimpeza.h"

using namespace std;

///\brief Classe Servico permite a construção de uma hierarquia de classes para representar diferentes tipos de
/// serviços. Especifíca membros comuns a todas as classes da hierarquia.
class Servico {
protected:

    /// \brief id do Servico
    int id;

    /// \brief descrição do Servico
    string descricao;

    /// \brief custo do Servico
    float custo;
public:

    /// \brief Construtor de um Servico com a seguinte informação:
    /// \param desc : descrição do Servico
    /// \param c : custo do Servico
    Servico(const string &desc, const float &c);

    /// \brief Construtor de um Servico com a seguinte informação:
    /// \param i : id do Servico
    /// \param desc : descrição do Servico
    /// \param c : custo do Servico
    Servico(int i,const string &desc, const float &c);

    /// \brief Função que obtém o ID do Servico
    /// \return ID do Servico
    int getId() const;

    /// \brief Função que altera o ID do Servico
    /// \param i : novo ID do Servico
    void setId(const int &i);

    /// \brief Função que obtém a descrição do Servico
    /// \return descrição do Servico
    string getDescricao() const;

    /// \brief Função que altera a descrição do Servico
    /// \param desc : nova descrição do Servico
    void setDescricao(const string &desc);

    /// \brief Função que obtém o custo do Servico
    /// \return custo do Servico
    float getCusto() const;

    /// \brief Função que obtém o custo Mensal do Servico
    /// \return custo mensal do Servico
    virtual float getCustoMensal() const;

    /// \brief Função que altera o custo do Servico
    /// \param c : novo custo do Servico
    void setCusto(const float &c);

    /// \brief Função virtual que mostra a descrição do Servico
    virtual void mostrar() const;

    /// \brief Função virtual que imprime a informação do Servico
    /// \return informação do Servico
    virtual string info() const;

    /// \brief Último ID criado
    static int ultimo_id;
};

///\brief Classe ServicoLimpeza representa um serviço de limpeza através da seu id, descrição, custo, duração e
/// prestador de serviço de limpeza atribuído.
class ServicoLimpeza: public Servico {

    /// \brief duração do Servico de Limpeza
    float duracao;

    /// \brief prestador do Servico de Limpeza
    PrestadorServicoLimpeza prestadorServicoLimpeza;
public:

    /// \brief Construtor de um Servico de Limpeza com a seguinte informação:
    /// \param id : ID do Servico
    /// \param desc : descrição do Servico
    /// \param c : custo do Servico
    /// \param d : duração do Servico
    ServicoLimpeza(int id, const string &desc, const float &c, float d);

    /// \brief Função que obtem a duração do Servico de Limpeza
    /// \return duração do Servico de Limpeza
    float getDuracao() const;

    /// \brief Função que calcula o custo do Serviço de Limpeza
    /// \return custo do Serviço de Limpeza
    virtual float getCustoMensal() const;

    /// \brief Função que obtem o prestador do Serviço de Limpeza
    /// \return prestador do Serviço de Limpeza
    PrestadorServicoLimpeza getPrestador() const;

    /// \brief Função que altera o prestador do Serviço de Limpeza
    /// \param prestador : novo prestador do Serviço de Limpeza
    void setPrestador(PrestadorServicoLimpeza *prestador);

    /// \brief Função que mostra a descrição do Servico de Limpeza
    void mostrar() const;

    /// \brief Função que imprime a informação do Servico de Limpeza
    /// \return informação do Servico de Limpeza
    string info() const;

};

#endif
