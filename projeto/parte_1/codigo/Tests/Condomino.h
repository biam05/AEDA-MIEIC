#ifndef CONDOMINO_H_
#define CONDOMINO_H_

#include <vector>
#include "Habitacao.h"
#include "Servico.h"
#include <sstream>

using namespace std;

class Servico;

///\brief Classe Condomino representa um condómino através do seu nome, NIF e contentores de objetos para armazenar
/// as suas habitações e serviços.
class Condomino {

    /// \brief O nome do Condómino.
    string nome;

    /// \brief O NIF do Condómino.
    string nif;

    /// \brief Contentor onde estão armazenadas as habitações do Condómino.
	vector<Habitacao *> habitacoes;

    /// \brief Contentor onde estão armazenadas os serviços do Condómino.
	vector<Servico *> servicos;
public:

    /// \brief Constrói uma instância de Condomino recebendo o nome e o NIF.
    /// \param nm: O nome do Condomino.
    /// \param ni: O NIF do Condomino.
    Condomino(const string &nm, const string &ni);

    /// \brief Constrói uma instância de Condomino sem parâmetros.
    Condomino();

    /// \brief Devolve o nome do Condómino.
    /// \return O nome do Condómino.
    string getNome() const;

    /// \brief Modifica o nome do Condómino.
    /// \param nm: O novo nome do Condómino.
    void setNome(const string &nm);

    /// \brief Devolve o NIF do Condómino
    /// \return O NIF do Condómino.
    string getNif() const;

    /// \brief Modifica o NIF do Condómino.
    /// \param ni: O novo NIF do Condómino.
    void setNif(const string &ni);

    /// \brief Devolve o contentor onde estão armazenadas as habitações do Condomino.
    /// \return O contentor onde estão armazenadas as habitações do Condomino.
    vector<Habitacao *> getHabitacoes() const;

    /// \brief Modifica o contentor onde estão armazenadas as habitações do Condomino.
    /// \param v: O novo contentor onde estão armazenadas as habitações do Condomino.
    void setHabitacoes(const vector<Habitacao *> &v);

    /// \brief Devolve o contentor onde estão armazenadas os serviços do Condomino.
    /// \return O contentor onde estão armazenadas os serviços do Condomino.
    vector<Servico *> getServicos() const;

    /// \brief Modifica o contentor onde estão armazenadas os serviços do Condomino.
    /// \param v: O novo contentor onde estão armazenadas os serviços do Condomino.
    void setServicos(const vector<Servico *> &v);

    /// \brief Devolve o número de habitações adquiridas pelo Condómino.
    /// \return O número de habitações adquiridas pelo Condómino.
	int numeroHabitacoes() const;

    /// \brief Adiciona uma nova habitação ao contentor do Condomino.
    /// \param v1: Habitação que se pretende adicionar ao contentor do Condomino.
	void adicionaHabitacao(Habitacao *v1);

    /// \brief Valida se uma habitação já foi comprada pelo Condomino.
    /// \param h1: Habitação a ser validada.
    /// \return true se a habitação recebida representar uma habitação que já foi comprada pelo Condomino.
    /// Caso contrário, retorna false.
    bool validaHabitacao(Habitacao *h1) const;

    /// \brief Adiciona um novo serviço ao contentor do Condomino.
    /// \param s: Serviço que se pretende adicionar ao contentor do Condomino.
	void adicionaServico(Servico *s);

    ///\brief Calcula o valor mensal do condomínio das suas habitações.
    /// \return O valor mensal do condomínio das suas habitações.
	float totalCondominio() const;

    /// \brief Função que mostra todos os serviços que o Condómino tem
	void Mostrar_Servicos() const;

	/// \brief Função que mostra todas as habitações que o Condómino tem
	void Mostrar_Habitacoes() const;

    /// \brief Funcão que imprime a informação do Condómino
    /// \return informação do Condómino
    string info() const;

    /// \brief Funcão que escreve as habitações que o Condómino tem
    /// \return habitações que o Condómino tem
	string escreveHabitacoes()const;

    /// \brief Função que retorna as habitações com a área passada por parâmetro
    /// \param areaHabitacional: área habitacional da habitação
    /// \return habitações com a área passada por parâmetro
	vector<Habitacao *> operator() (float areaHabitacional) const;

    /// \brief Compara se dois condóminos são iguais.
    /// \param c1: O condomino a comparar.
    /// \return true se o condomino recebido representar um condomino com a mesmo NIF. Caso contrário, retorna false.
    bool operator == (const Condomino &c1) const;
};

#endif