/*
 * Supermercado.cpp
 *
 * Created on: Dec 3, 2014
 *
 */

#include "Supermercado.h"

//A ser implementado pelo estudante!
int Cliente::numeroItens() const {
    int total = 0;
    if(cestos.size() == 0) return 0;
    list<Cesto>::const_iterator it;
    for(it = cestos.begin(); it != cestos.end(); it++)
    {
        stack<Item> items = (*it).getItens();
        while(!items.empty())
        {
            total++;
            items.pop();
        }
    }
    return total;
}

int Cliente::valorItens() const {
    int total = 0;
    if(cestos.size() == 0) return 0;
    list<Cesto>::const_iterator it;
    for(it = cestos.begin(); it != cestos.end(); it++)
    {
        stack<Item> items = (*it).getItens();
        while(!items.empty())
        {
            total+= items.top().preco;
            items.pop();
        }
    }
    return total;
}

int Cliente::trocarItem(Item &novoItem) {
    int counter = 0;
    list<Cesto>::iterator it;
    for(it = cestos.begin(); it != cestos.end(); it++){
        vector<Item> newItens;
        int size = it->getItens().size();
        while(size > 0){
            if(it->getItens().top().preco > novoItem.preco || it->getItens().top().produto == novoItem.produto){
                newItens.push_back(novoItem);
                counter++;
            }
            else
                newItens.push_back(it->getItens().top());
            it->popItem();
            size--;
        }
        for(unsigned int i = 0; i < newItens.size(); i++)
            it->pushItem(newItens.at(newItens.size()-1-i));
    }
    return counter;
}

bool cmpItems(Item& i1, Item&i2)
{
    return i1.peso > i2.peso;
}

void Cliente::organizarCestos() {
    list<Cesto>::iterator it;
    for(it = cestos.begin(); it != cestos.end(); it++){
        vector<Item> items;
        int size = (*it).getItens().size();
        while(!(*it).getItens().empty())
        {
            items.push_back((*it).getItens().top());
            (*it).popItem();
        }
        sort(items.begin(), items.end(), cmpItems);
       for(int i = 0; i < items.size(); i++)
       {
           (*it).pushItem(items[i]);
       }
    }
}

vector<string> Cliente::contarItensPorTipo() {
    vector<pair<string,int>> pares;
    list<Cesto>::iterator it;
    for(it = cestos.begin(); it != cestos.end(); it++){
        stack<Item> itens = it->getItens();
        while(!itens.empty())
        {
            Item currentItem = itens.top();
            bool found = false;
            unsigned int i;
            for(i = 0; i < pares.size(); i++){
                if(pares.at(i).first == currentItem.tipo){
                    found = true;
                    break;
                }
            }
            if(found)
                pares.at(i).second++;
            else
                pares.push_back(pair<string,int>(currentItem.tipo,1));
            itens.pop();
        }
    }
    vector<string> result;
    for(int i = 0; i < pares.size(); i++)
        result.push_back(pares[i].first + " " + to_string(pares[i].second));
    return result;
}

int Cliente::novoItem(const Item &umItem) {
    list<Cesto>::iterator it;
    for(it = cestos.begin(); it != cestos.end(); it++){
        if( it->novoItem(umItem) == 0)
        {
            Cesto novoCesto;
            novoCesto.getItens().push(umItem);
            cestos.push_back(novoCesto);
        }
    }
    return cestos.size();
}

int Cesto::novoItem(const Item &umItem) {
    int Tpeso = 0, Tvolume = 0;
    stack<Item> items = getItens();
    while(!items.empty())
    {
        Tpeso += items.top().peso;
        Tvolume += items.top().volume;
        items.pop();
    }
    if((Tpeso + umItem.peso <= max_peso) && (Tvolume + umItem.volume <= max_volume))
    {
        itens.push(umItem);
        return itens.size();
    }
    return 0;
}

int Supermercado::novoCliente(Cliente &umCliente) {
    if(umCliente.getIdade() >= 65)
    {
        if(filaNormal.size() < filaPrioritaria.size())
            filaNormal.push(umCliente);
        else
            filaPrioritaria.push(umCliente);
    }
    else
        filaNormal.push(umCliente);
    return filaNormal.size() + filaPrioritaria.size();
}

Cliente Supermercado::sairDaFila(string umNomeDeCliente) {
    queue<Cliente> filaNormal = getFilaNormal();
    queue<Cliente> filaPrioritaria = getFilaPrioritaria();
    unsigned int size = filaNormal.size();
    vector<Cliente> vn;
    vector<Cliente> vp;
    while(size > 0){
        if(filaNormal.front().getNome() == umNomeDeCliente){
            Cliente returnValue = filaNormal.front();
            filaNormal.pop();
            size--;
            while(size > 0){
                vn.push_back(filaNormal.front());
                filaNormal.pop();
                size--;
            }
            queue<Cliente> fn;
            for(unsigned int i = 0; i < vn.size(); i++)
                fn.push(vn.at(i));
            setFilaNormal(fn);
            return returnValue;
        }
        vn.push_back(filaNormal.front());
        filaNormal.pop();
        size--;
    }
    size = filaPrioritaria.size();
    while(size > 0){
        if(filaPrioritaria.front().getNome() == umNomeDeCliente){
            Cliente returnValue = filaPrioritaria.front();
            filaPrioritaria.pop();
            size--;
            while(size > 0){
                vp.push_back(filaPrioritaria.front());
                filaPrioritaria.pop();
                size--;
            }
            queue<Cliente> fp;
            for(unsigned int i = 0; i < vp.size(); i++)
                fp.push(vp.at(i));
            setFilaPrioritaria(fp);
            return returnValue;
        }
        vp.push_back(filaPrioritaria.front());
        filaPrioritaria.pop();
        size--;
    }
    throw Supermercado::ClienteInexistente(umNomeDeCliente);
}
