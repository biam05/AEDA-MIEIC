#ifndef AEDA1920_FP02_SOL_CONDOMINIO_H
#define AEDA1920_FP02_SOL_CONDOMINIO_H

#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include "Servico.h"
#include "Habitacao.h"
#include "Condomino.h"
#include "Condominio.h"
#include "PrestadorServicoLimpeza.h"
#include <fstream>
#include "AntigosCondominos.h"
#include "Transportes.h"
//#include "CondomiX.h"

using namespace std;

class Servico;
class Condomino;
class CondomiX;

///\brief Classe Condominio representa uma condomínio através da sua designação, localização e de contentores de
/// objetos para armazenar as habitações e os condóminos.
class Condominio {

    /// \brief A designação do Condomínio.
    string designacao;

    /// \brief A localização do Condomínio.
    string localizacao;

    /// \brief Contentor onde estão armazenadas as habitações do Condominio.
    vector<Habitacao *> habitacoes;

    /// \brief Contentor onde estão armazenados os condóminos do Condominio.
    vector<Condomino *> condominos;

    /// \brief Contentor onde estão armazenados os Antigos Condóminos do Condominio.
    HashTabAntigoClienteRecord antigos_condominos;

    /// \brief Fila de Prioridade com todos os transportes
    priority_queue<Transporte *, vector<Transporte*>, TransportesCmp> transportes;

public:

    /// \brief Constrói uma instância de Condominio recebendo o designacao e a localização como parâmetros.
    /// \param desi: A designacao do Condominio.
    /// \param loc: A localização do Condominio.
    Condominio(const string &desi, const string &loc);

    /// \brief Constrói uma instância de Condominio sem parâmetros.
    Condominio();

    /// \brief Compara se um Condominio é menor que outro recebido.
    /// \param c1: O Condominio a comparar.
    /// \return true se a condomínio recebido representar uma habitação com maior número de habitações e,
    /// em caso de empate, maior número de vivendas. Caso contrário, retorna false.
    bool operator < (const Condominio &c1) const;

    /// \brief Compara se dois Condominio são iguais.
    /// \param c1: Condominio a comparar.
    /// \return true se o Condominio recebida representar um condominio com a mesma designação.
    /// Caso contrário, retorna false.
    bool operator == (const Condominio &c1) const;

    /// \brief Devolve o número de habitações do Condominio.
    /// \return O número de habitações do Condominio.
    int numeroHabitacoes() const;

    /// \brief Devolve o número de vivendas do Condominio.
    /// \return O número de vivendas do Condominio.
    int numeroVivendas() const;

    /// \brief Devolve o vetor de habitações disponiveis do Condominio.
    /// \return O vetor de habitações disponiveis do Condominio.
    vector<Habitacao *> getHabitacoesDisponiveis() const;

    /// \brief Devolve o número de condominos do Condominio.
    /// \return O número de condominos do Condominio.
    int numeroCondominos() const;

    /// \brief Devolve o número de antigos condóminos do Condomínio.
    /// \return O número de antigos condóminos do Condomínio.
    int numeroAntigosCondominos() const;

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

    /// \brief Adiciona um novo transporte ao contentor do Condominio.
    /// \param t: transporte que se pretende adicionar ao contentor do Condominio.
    void adicionaTransporte(Transporte * t);

    /// \brief Adiciona um Antigo Condomino ao contentor do Condominio.
    /// \param a1: Antigo Condomino que se pretende adicionar ao contentor do Condominio.
    void adicionaAntigoCondomino(AntigoCondomino *a1);

    /// \brief Devolve o designacao do Condominio.
    /// \return A designacao do Condominio.
    string getDesignacao() const;

    /// \brief Modifica a designacao do Condominio.
    /// \param desi: A nova designacao do Condominio.
    void setDesignacao(const string &desi);

    /// \brief Devolve o designacao do Condominio.
    /// \return A designacao do Condominio.
    string getLocalizacao() const;

    /// \brief Modifica a localização do Condominio.
    /// \param loc: A nova localização do Condominio.
    void setLocalizacao(const string &loc);

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

    /// \brief Devolve o contentor onde estão armazenados os Antigos Condóminos do Condominio.
    /// \return O contentor onde estão armazenados os Antigos Condóminos do Condominio.
    HashTabAntigoClienteRecord getAntigosCondominos() const;

    /// \brief Mostra as características das habitações do Condominio.
    void Mostrar_Habitacoes() const;

    /// \brief Mostra as características dos condóminos do Condominio.
    void Mostrar_Condominos() const;

    /// \brief Mostra as características dos transportes do Condominio.
    void Mostrar_Transportes_Edicao();

    /// \brief Ordena os condominos do Condominio por nome.
    void ordenaCondominosPorNome();

    /// \brief Ordena as habitações do Condominio por área habitacional.
    void ordenaHabitacoesPorAreaHabitacional();

    /// \brief Escreve as características de todas as habitações do Condominio.
    /// \return As características de todas as habitações do Condominio.
    string escreveTotalHabitacoes()const;

    /// \brief Escreve as características de todos os condóminos do Condominio.
    /// \return As características de todos os condóminos do Condominio.
    string escreveTotalCondominos()const;

    /// \brief Escreve as informações do Condomínio.
    /// \return As informações do Condomínio.
    string escreveInformacoes() const;

    /// \brief Mostra as características das habitações do Condominio que ainda não foram compradas.
    /// \return As características das habitações do Condominio que ainda não foram compradas.
    vector <Habitacao *> Mostrar_Habitacoes_Disponiveis()const;

    /// \brief Mostra os transportes do Condominio.
    void Mostrar_Transportes();

    /// \brief Procura o Transporte no Condominio com o destino recebido.
    /// \param destino: O destino do transporte a ser procurado.
    /// \return O transporte mais próximo com o destino dado.
    Transporte* Procurar_Transporte(string destino);

    /// \brief Procura o Transporte mais próximo do Condominio.
    /// \return O transporte mais próximo.
    Transporte* Procurar_Transporte_Perto();

    /// \brief Devolve o número de transportes do Condominio.
    /// \return O número de transportes do Condominio.
    int numeroTransportes() const;

    /// \brief Devolve os transportes do Condominio.
    /// \return transportes do Condominio.
    priority_queue<Transporte *, vector<Transporte*>, TransportesCmp> getTransportes() const;

    /// \brief Devolve os transportes do Condominio num vetor.
    /// \return transportes do Condominio.
    vector<Transporte*> getTransportesVector();

    /// \brief Modifica os transportes do Condominio.
    /// \param t: novos transportes do Condominio.
    void setTransportes(const vector <Transporte*> &t);

    Condominio &operator=(const Condominio &outro);
};

#endif
