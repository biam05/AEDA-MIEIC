#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <string>
#include "Kart.h"

using namespace std;

//To help build better array
string itos(int i){
    stringstream s;
    s << i;
    return s.str();
}

void CGrupo::criaGrupo()
{
    float cilindradas[4]  = {134,250,450,600};
    bool avariados[3]  = {true,false,false};

    srand (1);   //Criar Pistas e Karts de Teste
    for(int i=1;i<=50;i++){
        vector<CKart> frota;
        for(int j=1;j<=50;j++){
            frota.push_back(CKart(avariados[rand()% 3],
                                  ("KART - "+itos(i))+itos(j),(i-1)*50+j,cilindradas[(rand() % 4)]));
        }
        adicionaPista(CPista("Pista - "+itos(i),frota));
    }
}


vector <CKart> CPista::getKartsAvariados()
{
    vector<CKart> aux;
    for (vector<CKart>::iterator it = frotaKartsPista.begin() ; it != frotaKartsPista.end(); ++it) {
        if ((it)->getAvariado()) aux.push_back((*it));
    }
    return aux;
}
 
//Exercicio 1 a)
bool cmpKarts(CKart& c1, CKart& c2)
{
    return c1.getNumero() < c2.getNumero();
}

vector<CKart> CGrupo::ordenaKarts()
{
    vector<CKart> vord;
    vector<CPista>::iterator it;
    for(auto & pista : pistasG)
    {
        for(int i = 0; i < pista.getFrotaActual().size(); i++)
        {
            vord.push_back(pista.getFrotaActual()[i]);
        }
    }
    sort(vord.begin(), vord.end(), cmpKarts);
	return vord;
}

//Exercicio 1 b)  
int CGrupo::numAvariados(int cilind)
{
    int count = 0;
    vector<CKart> totalKarts = ordenaKarts();
    for(auto & kart : totalKarts)
    {
        if(kart.getAvariado() && (kart.getCilindrada() == cilind)) count++;
    }
    return count;
}

//Exercicio 1 c)   
bool CPista::prepararCorrida(int numeroKarts, int cilind)
{
    vector<CKart> karts;
    for(auto & kart : frotaKartsPista)
    {
        if((kart.getCilindrada() == cilind) && !kart.getAvariado())
            karts.push_back(kart);
    }

    if(numeroKarts > karts.size())
    {
        for(int i = 0; i < karts.size(); i++)
        {
            kartsLinhaPartida.push(karts[i]);
        }
        return false;
    }
    for(int i = 0; i < numeroKarts; i++)
    {
        kartsLinhaPartida.push(karts[i]);
    }
    return true;
}

//Exercicio 1 d) 
int CPista::inicioCorrida()
{
    int count = 0;
    while(!kartsLinhaPartida.empty())
    {
        kartsEmProva.push_back(kartsLinhaPartida.front());
        kartsLinhaPartida.pop();
        count++;
    }
    return count;
}

