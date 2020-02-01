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

/// \brief Função que inicia um menu onde se visualizam todas as habitações do condominio
/// \param condominio : condominio ao qual pertencem as habitações
void Visualizar_Todas_Habitacoes(Condominio &condominio);

/// \brief Função que inicia um menu onde se pesquisa uma habitação pela morada, visualizando-a
/// \param condominio : condominio ao qual pertence a habitação pesquisada
void Visualizar_Habitacao_Morada(Condominio &condominio);

/// \brief Função que inicia um menu onde se visualizam todos os condóminos do condominio
/// \param condominio : condominio ao qual pertencem os condóminos
void Visualizar_Todos_Condominos (Condominio &condominio);

/// \brief Função que inicia um menu onde se pesquisa um condómino pelo NIF, visualizando-o
/// \param condominio : condominio ao qual pertence o condómino pesquisado
void Visualizar_Condominos_NIF(Condominio &condominio);

/// \brief Função que inicia um menu onde se visualizam todos os serviços do condominio
/// \param condominio : condominio ao qual pertencem os serviços
void Visualizar_Servicos(Condominio &condominio);

/// \brief Função que inicia um menu onde se visualizam todos os prestadores de um serviço do condominio
/// \param condominio : condominio ao qual pertence o serviço
/// \param gestao : gerência à qual pertencem os prestadores
void Visualizar_Prestadores(Condominio &condominio, CondomiX &gestao);

/// \brief Função que permite adicionar uma habitação ao condominio
/// \param condominio : condominio da habitação é adicionada
void Adicionar_Habitacao(Condominio &condominio);

/// \brief Função que permite editar uma habitação do condomínio
/// \param condominio : condominio da habitação é editada
void Editar_Habitacao(Condominio &condominio);

/// \brief Função que permite eliminar uma habitação do condominio
/// \param condominio : condominio da habitação eliminada
void Eliminar_Habitacao(Condominio &condominio);

/// \brief Função que permite adicionar um condómino ao condominio
/// \param condominio : condominio do condómino adicionado
void Adicionar_Condomino(Condominio &condominio);

/// \brief Função que permite editar um condómino do condominio
/// \param condominio : condominio do condómino editado
void Editar_Condomino(Condominio &condominio);

/// \brief Função que permite eliminar um condómino do condominio
/// \param condominio : condominio do condómino eliminado
void Eliminar_Condomino(Condominio &condominio);

/// \brief Função que permite que um condómino do condomínio adquira uma habitação do condomínio
/// \param condominio : condominio do condómino e da habitação
void Adquirir_Habitacao(Condominio &condominio);

/// \brief Função que permite remover uma habitação do condominio a um condómino do condomínio
/// \param condominio : condominio do condómino e da habitação
void Remover_Habitacao(Condominio &condominio);

/// \brief Função que permite adicionar um serviço ao condominio
/// \param condominio : condominio do serviço adicionado
void Adicionar_Servico(Condominio &condominio);

/// \brief Função que permite editar um serviço do condominio
/// \param condominio : condominio do serviço editado
void Editar_Servico(Condominio &condominio);

/// \brief Função que permite eliminar um serviço do condominio
/// \param condominio : condominio do serviço eliminado
void Eliminar_Servico(Condominio &condominio);

/// \brief Função que permite que um condómino do condominio requisite um serviço do condominio
/// \param condominio : condominio do condómino e do serviço
/// \param gestao : gerência do prestador do serviço requisitado pelo condómino
void Requisitar_Servico(Condominio &condominio,CondomiX &gestao);

/// \brief Funcão que regista um serviço que foi efetuado
/// \param condominio : condominio do condómino e do serviço
/// \param gestao : gerência do prestador do serviço que efetuou o serviço
void Terminar_Servico(Condominio &condominio, CondomiX &gestao);

/// \brief Função que permite calcular o valor mensal do condominio
/// \param condominio : condominio que queremos saber o valor mensal
/// \return valor mensal (rendas, serviços, etc. de todos os condóminos)
float Calcular_Valor_Mensal(Condominio &condominio);

#endif //AEDA1920_FP02_SOL_UTILS_H
