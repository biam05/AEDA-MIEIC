#ifndef AEDA1920_FP02_SOL_ANTIGOSCONDOMINOS_H
#define AEDA1920_FP02_SOL_ANTIGOSCONDOMINOS_H

#include <sstream>
#include <unordered_set>

using namespace std;

///\brief Classe Antigo Condomino representa um condómino que não pertence a nenhum condomínio, através do seu nome, NIF e contentores de objetos para armazenar
class AntigoCondomino {

    /// \brief O nome do Antigo Condómino.
    string nome;

    /// \brief O NIF do Antigo Condómino.
    string nif;

    /// \brief O periodo que o Antigo Condómino permaneceu em qualquer condominio.
    int periodo;

public:

    /// \brief Constrói uma instância de Antigo Condomino recebendo o nome, o NIF e o periodo.
    /// \param nm: O nome do Antigo Condómino.
    /// \param ni: O NIF do Antigo Condómino.
    /// \param pr: O periodo que o Antigo Condómino permaneceu em qualquer condominio.
    AntigoCondomino(const string &nm, const string &ni, const int &pr);

    /// \brief Constrói uma instância de Antigo Condómino sem parâmetros.
    AntigoCondomino();

    /// \brief Devolve o nome do Antigo Condómino.
    /// \return O nome do Antigo Condómino.
    string getNome() const;

    /// \brief Modifica o nome do Antigo Condómino.
    /// \param nm: O novo nome do Antigo Condómino.
    void setNome(const string &nm);

    /// \brief Devolve o NIF do Antigo Condómino
    /// \return O NIF do Antigo Condómino.
    string getNif() const;

    /// \brief Modifica o NIF do Antigo Condómino.
    /// \param ni: O novo NIF do Antigo Condómino.
    void setNif(const string &ni);

    /// \brief Devolve o periodo que o Antigo Condómino permaneceu em qualquer condominio.
    /// \return O periodo do Antigo Condómino.
    int getPeriodo() const;

    /// \brief Modifica o periodo que o Antigo Condómino permaneceu em qualquer condominio.
    /// \param pr: O novo periodo do Antigo Condómino.
    void setPeriodo(const int &pr);

    /// \brief Funcão que imprime a informação do Antigo Condómino
    /// \return informação do Antigo Condómino
    string info() const;

    /// \brief Compara se dois Antigos Condóminos são iguais.
    /// \param c1: O Antigo Condómino a comparar.
    /// \return true se o Antigo Condómino recebido representar um Antigo Condómino com o mesmo NIF. Caso contrário, retorna false.
    bool operator == (const AntigoCondomino &c1) const;
};

///\brief Classe Antigo Condomino Record representa um pointer para um condómino que não pertence a nenhum condomínio, usado na tabela de dispersão
class AntigoCondominoRecord {
    /// \brief O pointer para o Antigo Condomino.
    AntigoCondomino* AntigoCondominoPtr;
public:
    /// \brief Constrói uma instância de Antigo Condomino Record recebendo o pointer para o antigo condómino.
    /// \param antigoCondomino: O pointer para o Antigo Condómino.
    AntigoCondominoRecord(AntigoCondomino *antigoCondomino);

    /// \brief Devolve o pointer para o Antigo Condómino.
    AntigoCondomino* getAntigoCondominoPointer() const;

    /// \brief Devolve o nome do Antigo Condómino.
    string getName() const;

    /// \brief Devolve o nif do Antigo Condómino.
    string getNIF() const;

    /// \brief Modifica o NIF do Antigo Condómino.
    /// \param nif: O novo NIF do Antigo Condómino.
    void setNIF(const string &nif);
};

/// \brief Struct AntigoCondominoRecordHash representa um hash para um condómino que não pertence a nenhum condomínio, usado na tabela de dispersão
struct AntigoCondominoRecordHash
{
    /// \brief Função Hash
    /// \param cr: AntigoCondominoRecord a inserir na tabela de dispersão
    int operator() (const AntigoCondominoRecord &cr) const
    {
        int v = 0;
        for ( unsigned int i=0; i < cr.getAntigoCondominoPointer()->getNif().size() ; i++ )
            v = 37*v + cr.getAntigoCondominoPointer()->getNif()[i];
        return v;
    }

    /// \brief Operador de Igualdade da Hash
    /// \param cr1: Primeiro AntigoCondominoRecord a comparar
    /// \param cr2: Segundo AntigoCondominoRecord a comparar
    bool operator() (const AntigoCondominoRecord &cr1, const AntigoCondominoRecord &cr2) const
    {
        return cr1.getNIF() == cr2.getNIF();
    }
};

typedef unordered_set<AntigoCondominoRecord, AntigoCondominoRecordHash, AntigoCondominoRecordHash> HashTabAntigoClienteRecord;

#endif //AEDA1920_FP02_SOL_ANTIGOSCONDOMINOS_H
