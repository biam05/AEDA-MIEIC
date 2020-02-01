#ifndef AEDA1920_FP02_SOL_UTILS_H
#define AEDA1920_FP02_SOL_UTILS_H

#include "Condominio.h"
#include "Servico.h"
#include "CondomiX.h"

/// \brief Função que gera um logótipo para a CondomiX
void Logotipo();

/// \brief Função que pergunta ao utilizador se quer sair do programa
/// \return 's': sair do programa; 'n': não sair do programa
char Sair_Programa();

/// \brief Função que inicia um menu onde se visualizam todos os condominios e os respetivos dados
/// \param gestao : Objeto CondomiX
void Visualizar_Todos_Condominios(CondomiX &gestao);

/// \brief Função que inicia um menu onde se visualiza um condominio com um dado numero de Habitacoes
/// \param gestao : Objeto CondomiX
void Visualizar_Condominio_Numero_Habitacoes(CondomiX &gestao);

/// \brief Função que inicia um menu onde se visualizam todas as habitações do condominio
/// \param gestao : Objeto CondomiX
void Visualizar_Todas_Habitacoes(CondomiX &gestao);

/// \brief Função que inicia um menu onde se pesquisa uma habitação pela morada, visualizando-a
/// \param gestao : Objeto CondomiX
void Visualizar_Habitacao_Morada(CondomiX &gestao);

/// \brief Função que inicia um menu onde se visualizam todos os condóminos do condominio
/// \param gestao : Objeto CondomiX
void Visualizar_Todos_Condominos (CondomiX &gestao);

/// \brief Função que inicia um menu onde se pesquisa um condómino pelo NIF, visualizando-o
/// \param gestao : Objeto CondomiX
void Visualizar_Condominos_NIF(CondomiX &gestao);

/// \brief Função que inicia um menu onde se visualizam todos os Antigos Condóminos do condominio
/// \param condominio : Objeto CondomiX
void Visualizar_Todos_Antigos_Condominos (CondomiX &gestao);

/// \brief Função que inicia um menu onde se pesquisa um Antigo Condómino pelo NIF, visualizando-o
/// \param condominio : Objeto CondomiX
void Visualizar_Antigos_Condominos_NIF(CondomiX &gestao);

/// \brief Função que inicia um menu onde se visualizam todos os serviços do condominio
/// \param condominio : condominio ao qual pertencem os serviços
void Visualizar_Servicos(Condominio &condominio, CondomiX &gestao);

/// \brief Função que inicia um menu onde se visualizam todos os prestadores de um serviço do condominio
/// \param condominio : condominio ao qual pertence o serviço
/// \param gestao : gerência à qual pertencem os prestadores
void Visualizar_Prestadores(Condominio &condominio, CondomiX &gestao);

/// \brief Função que inicia um menu onde visualiza todos os transportes de um condominio
/// \param gestao: CondomiX
void Visualizar_Transportes(CondomiX &gestao);

/// \brief Função que inicia um menu onde se pesquisa um transporte pelo destino, visualizando-o
/// \param gestao: CondomiX
void Visualizar_Transporte_Perto_Destino(CondomiX &gestao);

/// \brief Função que inicia um menu onde se pesquisa o transporte mais próximo, visualizando-o
/// \param condominio : condominio ao qual pertence o transporte pesquisado
void Visualizar_Transporte_Perto(CondomiX &gestao);

/// \brief Função que permite adicionar uma habitação ao condominio
/// \param gestao : Objeto CondomiX
void Adicionar_Habitacao(CondomiX &gestao);

/// \brief Função que permite editar uma habitação do condomínio
/// \param gestao : Objeto CondomiX
void Editar_Habitacao(CondomiX &gestao);

/// \brief Função que permite eliminar uma habitação do condominio
/// \param gestao : Objeto CondomiX
void Eliminar_Habitacao(CondomiX &gestao);

/// \brief Função que permite adicionar um condominio
/// \param gestao : Objeto CondomiX
void Adicionar_Condominio(CondomiX &gestao);

/// \brief Função que permite editar um condominio
/// \param gestao : Objeto CondomiX
void Editar_Condominio(CondomiX &gestao);

/// \brief Função que permite eliminar um condominio
/// \param gestao : Objeto CondomiX
void Eliminar_Condominio(CondomiX &gestao);

/// \brief Função que permite adicionar um condómino ao condominio
/// \param gestao : Objeto CondomiX
void Adicionar_Condomino(CondomiX &gestao);

/// \brief Função que permite editar um condómino do condominio
/// \param gestao : Objeto CondomiX
void Editar_Condomino(CondomiX &gestao);

/// \brief Função que permite eliminar um condómino do condominio
/// \param gestao : Objeto CondomiX
void Eliminar_Condomino(CondomiX &gestao);

/// \brief Função que permite que um condómino do condomínio adquira uma habitação do condomínio
/// \param gestao : Objeto CondomiX
void Adquirir_Habitacao(CondomiX &gestao);

/// \brief Função que permite remover uma habitação do condominio a um condómino do condomínio
/// \param gestao: Objeto CondomiX
void Remover_Habitacao(CondomiX &gestao);

/// \brief Função que permite adicionar um serviço ao condominio
/// \param condominio : condominio do serviço adicionado
void Adicionar_Servico(Condominio &condominio, CondomiX &gestao);

/// \brief Função que permite editar um serviço do condominio
/// \param condominio : condominio do serviço editado
void Editar_Servico(Condominio &condominio, CondomiX &gestao);

/// \brief Função que permite eliminar um serviço do condominio
/// \param condominio : condominio do serviço eliminado
void Eliminar_Servico(Condominio &condominio, CondomiX &gestao);

/// \brief Função que permite adicionar um transporte ao condominio
/// \param gestao: CondomiX
void Adicionar_Transporte(CondomiX &gestao);

/// \brief Função que permite editar um transporte do condominio
/// \param gestao: CondomiX
void Editar_Transporte(CondomiX &gestao);

/// \brief Função que permite eliminar um transporte do condominio
/// \param gestao: CondomiX
void Eliminar_Transporte(CondomiX &gestao);

/// \brief Função que permite que um condómino do condominio requisite um serviço do condominio
/// \param gestao : Objeto CondomiX
void Requisitar_Servico(CondomiX &gestao);

/// \brief Funcão que regista um serviço que foi efetuado
/// \param gestao: Objeto CondomiX
void Terminar_Servico(CondomiX &gestao);

/// \brief Função que permite calcular o valor mensal do condominio
/// \param condominio : condominio que queremos saber o valor mensal
/// \return valor mensal (rendas, serviços, etc. de todos os condóminos)
float Calcular_Valor_Mensal(Condominio &condominio);

/// \brief Funcao que permite saber se já existe um condomínio com a mesma designacao
/// \param gestao: CondomiX
/// \param designacao: designacao a comparar
/// \return false se não existe um condominio já com essa designacao
bool existeDesignacao(CondomiX &gestao, string designacao);

#endif //AEDA1920_FP02_SOL_UTILS_H
