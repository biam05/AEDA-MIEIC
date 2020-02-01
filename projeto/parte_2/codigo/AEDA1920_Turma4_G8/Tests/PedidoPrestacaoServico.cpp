#include "PedidoPrestacaoServico.h"
#include <iostream>

using namespace std;

PedidoPrestacaoServico::PedidoPrestacaoServico(Condomino *cond, ServicoLimpeza *serv) : servico(serv), condomino(cond)
{}
