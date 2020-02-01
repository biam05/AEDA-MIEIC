#ifndef AEDA1920_FP02_SOL_PEDIDOPRESTACAOSERVICO_H
#define AEDA1920_FP02_SOL_PEDIDOPRESTACAOSERVICO_H
#include "Condomino.h"
#include "PrestadorServicoLimpeza.h"

/// \brief Classe PedidoPrestacaoServico representa um pedido de prestação de serviço através do condomino e serviço.
class PedidoPrestacaoServico {
private:

    /// \brief Apontador para o condómino que pede o serviço.
    Condomino* condomino;

    /// \brief Apontador para o serviço pedido.
    ServicoLimpeza* servico;
public:

    /// \brief Constrói uma instância de pedido de prestação de serviço recebendo o condomino e o serviço.
    /// \param cond: Apontador para o condómino que pede o serviço.
    /// \param serv: Apontador para o serviço pedido.
    PedidoPrestacaoServico(Condomino *cond, ServicoLimpeza *serv);
};


#endif
