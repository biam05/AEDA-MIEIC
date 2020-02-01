#ifndef EXCECOES_H
#define EXCECOES_H

#include <iostream>

using namespace std;

/// \brief Exceção: Quando não é possível escrever num ficheiro
class Erro_Escrita{
    /// \brief ficheiro no qual não é possível escrever
    string ficheiro;
public:
    /// \brief construtor da exceção com a seguinte informação
    /// \param f : ficheiro que não consegue ser escrito
    Erro_Escrita(string f){ ficheiro = f;}
};

/// \brief Exceção: Quando não é possível ler um ficheiro
class Erro_Ler{
    /// \brief ficheiro do qual não é possível ler
    string ficheiro;
public:
    /// \brief Construtor da exceção com a seguinte informação
    /// \param f : ficheiro que não consegue ser lido
    Erro_Ler(string f){ ficheiro = f;}
};

/// \brief Exceção: Quando a habitação não é encontrada
class Habitacao_Nao_Encontrada{
    /// \brief Código Postal da habitação não encontrada
    string cp;
public:
    /// \brief Construtor da exceção com a seguinte informação
    /// \param c : código postal da habitação não encontrada
    Habitacao_Nao_Encontrada(string c) {cp = c;}
};

/// \brief Exceção: Quando a habitação já foi adquirida por um condómino
class Habitacao_Ocupada{
    /// \brief Código Postal da habitação já adquirida
    string cp;
public:
    /// Construtor da exceção com a seguinte informação
    /// \param c : código postal da habitação já adquirida
    Habitacao_Ocupada(string c) { cp = c;}
};

/// \brief Exceção: Quando o condómino não é encontrado
class Condomino_Nao_Encontrado{
    /// \brief NIF do condomino não encontrado
    string nif;
public:
    /// \brief Construtor da exceção com a seguinte informação
    /// \param n : NIF do condomino não encontrado
    Condomino_Nao_Encontrado(string n) {nif = n;}
};

/// \brief Exceção: Quando se tenta adicionar uma habitacao com um Código-Postal que já existe
class CP_Ja_Existente{
    /// \brief Código-Postal que se tentou adicionar mas que já existe
    string cp;
public:
    ///brief Construtor da exceção com a seguinte informação
    /// \param c : Código-Postal que se tentou adicionar mas que já existe
    CP_Ja_Existente(string c) {cp = c;}
};

/// \brief Exceção: Quando se tenta adicionar um condómino com um NIF que já existe
class NIF_Ja_Existente{
    /// \brief NIF que se tentou adicionar mas que já existe
    string nif;
public:
    ///brief Construtor da exceção com a seguinte informação
    /// \param n : NIF que se tentou adicionar mas que já existe
    NIF_Ja_Existente(string n) {nif = n;}
};

#endif //EXCECOES_H
