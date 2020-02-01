#ifndef AEDA1920_FP02_SOL_PRESTADORSERVICOLIMPEZA_H
#define AEDA1920_FP02_SOL_PRESTADORSERVICOLIMPEZA_H
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/// \brief Classe PrestadorServicoLimpeza representa um prestador de servico de limpeza através do seu nome e total de horas de trabalho.
class PrestadorServicoLimpeza {
private:

    /// \brief O nome do prestador de serviço de limpeza.
    string nome;

    /// \brief O total de horas de trabalho do prestador de serviço de limpeza.
    float totalHoras;
public:

    /// \brief Construtor de um prestador de serviços de limpeza com a seguinte informação:
    /// \param n: nome do prestador de serviços de limpeza
    /// \param th: total de horas de trabalho do prestador de serviços de limpeza
    PrestadorServicoLimpeza(const string &n, float th);

    /// \brief Construtor de um prestador de serviços de limpeza sem qualquer informação
    PrestadorServicoLimpeza();

    /// \brief Função para obter o nome do prestador de serviços de limpeza
    /// \return nome do prestador de serviços de limpeza
    string getNome() const;

    /// \brief Função para obter o total de horas do prestador de serviços de limpeza
    /// \return total de horas de trabalho do prestador de serviços de limpeza
    float getTotalHoras() const;

    /// \brief Função para alterar o nome do prestador de serviços de limpeza
    /// \param nm: novo nome do prestador de serviços de limpeza
    void setNome(const string &nm);

    /// \brief Função para alterar o total de horas do prestador de serviços de limpeza
    /// \param horas: novo total de horas de trabalho do prestador de serviços de limpeza
    void setTotalHoras(float horas);

    /// \brief Função que escreve toda a informação do prestador de serviços de limpeza
    /// \return informação do prestador de serviços de limpeza
    string info() const;

    /// \brief Compara se um prestador de servico de limpeza é menor que outro recebido.
    /// \param v: O prestador de servico de limpeza  a comparar.
    /// \return true se o prestador de servico de limpeza recebido representar um prestador de servico de limpeza
    /// com mais horas de trabalho. Caso contrário, retorna false.
    bool operator < (const PrestadorServicoLimpeza & v) const;
};

#endif
