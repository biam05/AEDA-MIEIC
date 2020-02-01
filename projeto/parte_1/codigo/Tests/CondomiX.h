#ifndef AEDA1920_FP02_SOL_CONDOMIX_H
#define AEDA1920_FP02_SOL_CONDOMIX_H
#include <vector>
#include "Condominio.h"
#include "PrestadorServicoLimpeza.h"
using namespace std;

/// \brief Classe CondomiX representa a Condomix, a empresa especialista na gestão de condomínios, através de dois
/// contentores de objetos para armazenar os condomínios e os prestadores de serviço de limpeza.
class CondomiX {

//    Contentor onde estão armazenados os condomínios da Condomix.
//    vector<Condominio *> condominios;
public:

    /// \brief Contentor onde estão armazenados os prestadores de serviço de limpeza da Condomix.
    vector<PrestadorServicoLimpeza *> prestadoresServicoLimpeza;

    /// \brief Devolve os prestadores de serviço de limpeza da Condomix.
    vector<PrestadorServicoLimpeza *> getPrestadores();

    /// \brief Devolve as características dos prestadores de serviço de limpeza da CondomiX.
    /// \return As características dos prestadores de serviço de limpeza da CondomiX.
    string escreverTotalPrestadoresServicoLimpeza()const;

    /// \brief Devolve o prestador de serviço de limpeza da CondomiX com menos horas de trabalho.
    /// \return O prestador de serviço de limpeza da CondomiX com menos horas de trabalho.
    PrestadorServicoLimpeza * procurarPrestadorServicoLimpeza () const;

    /// \brief Lê os prestadores de serviço de limpeza de um ficheiro.
    /// \param ficheiro: Ficheiro que contem a informaçõo dos prestadores de serviço de limpeza da CondomiX.
    void Ler_Prestadores(const string &ficheiro);

    /// \brief Guarda a informação das características dos prestadores de serviço de limpeza num ficheiro para uso futuro.
    /// \param ficheiro: Ficheiro onde é guardada a informção dos prestadores de serviço de limpeza.
    void Escrever_Prestadores(const string &ficheiro);

    /// \brief Mostra as características de todos os prestadores de serviço de limpeza da CondomiX.
    void Mostrar_Prestadores() const;
};


#endif
