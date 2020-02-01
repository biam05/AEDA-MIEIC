#ifndef AEDA1920_FP02_SOL_TRANSPORTES_H
#define AEDA1920_FP02_SOL_TRANSPORTES_H

#include <sstream>
#include <vector>
#include "Habitacao.h"

using namespace std;

/// \brief Classe Transporte
class Transporte
{
    /// \brief tipo de Transporte (metro, autocarro ou comboio)
    string tipo;
    /// \brief destino do Transporte
    string destino;
    /// \brief paragem mais próxima do condomínio
    string paragem_proxima;
    /// \brief distancia da paragem mais proxima ate ao condominio
    int distancia;

public:
    /// \brief construtor de um Transporte
    /// \param t: tipo de Transporte.
    /// \param d: destino do Transporte
    /// \param pp: paragem mais proxima do condominio
    Transporte(string t, string d, string pp, int dist);

    /// \brief Devolve o tipo do Transporte
    /// \return tipo de Transporte
    string getTipo() const;

    /// \brief Devolve o destino do Transporte
    /// \return destino Transporte
    string getDestino() const;

    /// \brief Devolve a paragem mais proxima do condominio
    /// \return paragem mais proxima do condominio
    string getParagemProxima() const;

    /// \brief Devolve a distancia da paragem mais proxima ate ao condominio
    /// \return distancia da paragem mais proxima ate ao condominio;
    int getDistancia() const;

    /// \brief Modifica o tipo do Transporte
    /// \param t: novo tipo de Transporte
    void setTipo(string &t);

    /// \brief Modifica o tipo do Transporte
    /// \param d: novo destino do Transporte
    void setDestino(string &d);

    /// \brief Modifica a paragem mais proxima do condominio
    /// \param pp: nova paragem mais proxima do condominio
    void setParagemProxima(string &pp);

    /// \brief Modifica a distancia da paragem mais proxima ate ao condominio
    /// \param metros: nova distancia da paragem mais proxima ate ao condominio
    void setDistancia(int &metros);

    /// \brief Compara se um Transporte esta mais próximo do condomínio que outro.
    /// \param transporte: transporte a comparar.
    /// \return true se a o transporte fonecido for mais longe. Caso contrário retorna false
    bool operator < (Transporte &transporte);

    string info() const;

};

/// \brief Classe para comaprar os pointers dos transportes de um condomínio
struct TransportesCmp {
    /// \brieg operador para comparar os transportes
    /// \return true se o primeiro transporte for mais proximo que o segundo
    bool operator() (Transporte *c1, Transporte *c2) const { return *c1 < *c2; }
};

#endif //AEDA1920_FP02_SOL_TRANSPORTES_H
