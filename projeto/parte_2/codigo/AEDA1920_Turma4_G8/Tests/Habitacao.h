#ifndef HABITACAO_H_
#define HABITACAO_H_
#include <string>
#include <sstream>
using namespace std;

///\brief Classe Morada representa uma morada através do endereço, cidade e código postal.
class Morada {
private:

    ///\brief O endereço da Morada.
    string endereco;

    ///\brief A cidade da Morada.
    string cidade;

    ///\brief O código postal da Morada.
    string codigoPostal;

public:

    /// \brief Constrói uma instância de Morada recebendo o endereço, a cidade e o código postal.
    /// \param e: O endereço da Morada.
    /// \param c: A cidade da Morada.
    ///\param cp: O código postal da Morada.
    Morada(string e, string c, string cp);

    /// \brief Devolve o endereço da Morada.
    /// \return O endereço da Morada.
    string getEndereco() const;

    /// \brief Devolve a cidade da Morada.
    /// \return A cidade da Morada.
    string getCidade() const;

    /// \brief Devolve o código postal da Morada.
    /// \return O código postal da Morada.
    string getCodigoPostal() const;

    /// \brief Modifica o endereço da Morada.
    /// \param e: O novo endereço da Morada.
    void setEndereco(const string &e);

    /// \brief Modifica a cidade da Morada.
    /// \param c: A nova cidade da Morada.
    void setCidade(const string &c);

    /// \brief Modifica o código postal da Morada.
    /// \param cp: O novo código postal da Morada.
    void setCodigoPostal(const string &cp);

    /// \brief Devolve o endereço, a cidade e o código postal da morada.
    /// \return Características da Morada.
    string info() const;

    /// \brief Compara se duas Moradas são iguais.
    /// \param m1: Morada a comparar.
    /// \return true se a morada recebida representar uma morada com o mesmo código postal. Caso contrário, retorna false.
    bool operator == (const Morada &m1) const;
};

///\brief Classe Habitação permite a construção de uma hierarquia de classes para representar diferentes tipos de
/// habitações. Especifíca membros comuns a todas as classes da hierarquia.
class Habitacao {
protected:

    ///\brief A morada da habitação.
   Morada morada;

    ///\brief A área habitacional da habitação.
   float areaHabitacional;

public:

    /// \brief Constrói uma instância de Habitação recebendo a área habitacional e a morada.
    /// \param ah: A área habitacional da Habitação.
    /// \param m: A morada da Habitação.
   Habitacao(float ah, Morada m);

    /// \brief Devolve a área habitacional da Habitação.
    /// \return A área habitacional da Habitação.
   float getAreaHabitacional() const;

    /// \brief Devolve a morada da Habitação.
    /// \return A morada da Habitação.
   Morada getMorada() const;

    /// \brief Modifica a morada da Habitação.
    /// \param m: A nova morada da Habitação.
   void setMorada(const Morada &m);

    /// \brief Modifica a área habitacional da Habitação.
    /// \param ah: A nova área habitacional da Habitação.
   void setAreaHabitacional(const float ah);

    /// \brief Devolve a morada e área habitacional da Habitação.
    /// \return Características da Habitação
   virtual string info() const;

    /// \brief Compara se duas habitações são iguais.
    /// \param v: A Habitaçao a comparar.
    /// \return true se a habitação recebida representar uma habitação com a mesmo morada. Caso contrário, retorna false.
    bool operator == (const Habitacao & v) const;

    /// \brief Compara se uma Habitação é menor que outra recebida.
    /// \param v: A Habitação a comparar.
    /// \return true se a habitação recebida representar uma habitação com maior área habitacional. Caso contrário, retorna false.
   bool operator < (const Habitacao & v) const;

   ///\brief Permite o cálculo do valor mensal do condomínio da Habitação através do polimorfismo.
   /// \return O valor mensal do condomínio  da Habitação.
   virtual float calculaCondominio() const = 0;

    ///\brief Permite identificar se uma habitação é uma vivenda ou apartamento através do polimorfismo.
    /// \return O tipo de habitação.
    virtual string tipoHabitacao() const = 0;

   ///\brief Escreve as características da Habitação.
   virtual void escrever_habitacao(ostream &o) const;

   /// \brief Mostra o código postal da Habitação.
   void mostrar() const;

};

///\brief Classe Vivenda representa uma vivenda através da sua área habitacional, morada, área exterior e existência de piscina.
class Vivenda: public Habitacao {

    ///\brief A área exterior da vivenda.
   float areaExterior;

    ///\brief Existência de piscina na Vivenda.
   bool comPiscina;

   ///\brief O valor base mensal de condomínio da vivenda.
   static float valorBaseCondominioVivenda;
public:

    /// \brief Constrói uma instância de Vivenda recebendo a área habitacional, a morada, a área exterior e existência de piscina.
    /// \param ah: A área habitacional da Vivenda.
    /// \param m: A morada da Vivenda.
    /// \param ae: A área exterior da Vivenda.
    /// \param cp: Existência de piscina na Vivenda.
   Vivenda(float ah, Morada m, float ae, bool cp);

    /// \brief Devolve a área exterior da Vivenda.
    /// \return A área exterior da Vivenda.
   float getAreaExterior() const;

    /// \brief Devolve se existe ou não piscina na Vivenda.
    /// \return true se existir piscina na Vivenda. Caso contrário devolve false.
   bool getComPiscina() const;

    /// \brief Modifica a área exterior da Vivenda.
    /// \param ae: A nova área exterior da Vivenda.
   void setAreaExterior( const float ae);

    /// \brief Modifica a existência de piscina na Vivenda.
    /// \param cp: A nova existência de piscina na Vivenda.
   void setComPiscina(const bool cp);

    /// \brief Devolve a morada, a área habitacional, a área exterior e existência de piscina da Vivenda.
    /// \return Características da Vivenda.
   string info() const;

    ///\brief Calcula o valor mensal do condomínio da Vivenda.
    /// \return O valor mensal do condomínio da Vivenda.
   float calculaCondominio() const;

    ///\brief Identifica o tipo de habitação.
    /// \return O tipo de habitação.
    string tipoHabitacao() const;

    ///\brief Escreve as características da Vivenda.
   void escrever_habitacao(ostream &o) const;
};

///\brief Classe Apartamento representa um apartamento através da sua área habitacional, morada, tipologia e piso.
class Apartamento: public Habitacao {

    /// \brief A tipologia do Apartamento.
  string tipologia;

  /// \brief O piso do Apartamento.
  int piso;

    ///\brief O valor base mensal de condomínio do Apartamento.
  static float valorBaseCondominioApartamento;
public:

    /// \brief Constrói uma instância de Apartamento recebendo a área habitacional, a morada, a tipologia e o piso.
    /// \param ah: A área habitacional do Apartamento.
    /// \param m: A morada do Apartamento.
    /// \param tipologia: A tipologia do Apartamento.
    /// \param piso: O piso do Apartamento.
   Apartamento(float ah, Morada m, string tipologia, int piso);

    /// \brief Devolve a tipologia do Apartamento.
    /// \return A tipologia do Apartamento.
   string getTipologia() const;

    /// \brief Devolve o piso do Apartamento.
    /// \return O piso do Apartamento.
   int getPiso() const;

    /// \brief Modifica a tipologia do Apartamento.
    /// \param tp: A nova tipologia do Apartamento.
   void setTipologia(const string tp);

    /// \brief Modifica o piso do Apartamento.
    /// \param p: O novo piso do Apartamento.
   void setPiso(const int p);

    /// \brief Devolve a morada, a área habitacional, a tipologia e o piso do Apartamento.
    /// \return Características do Apartamento.
   string info() const;

    ///\brief Calcula o valor mensal do condomínio  do Apartamento.
    /// \return O valor mensal do condomínio  do Apartamento.
   float calculaCondominio() const;

    ///\brief Identifica o tipo de habitação.
    /// \return O tipo de habitação.
    string tipoHabitacao() const;

    ///\brief Escreve as características do Apartamento..
   void escrever_habitacao(ostream &o) const;
};

#endif
