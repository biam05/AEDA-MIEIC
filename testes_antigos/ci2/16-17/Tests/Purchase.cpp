/*
 * Purchase.cpp
 *
 *  Created on: Nov 16, 2016
 *      Author: hlc
 */

#include "Purchase.h"

using namespace std;

Purchase::Purchase(long cli) : client (cli) {
}

long Purchase::getClient() const {
	return client;
}

list< stack<Article*> > Purchase::getBags() const {
	return bags;
}

/**
 * Create an Article associated with the client of this purchase.
 */
Article* Purchase::createArticle(long barCode, bool present, bool deliverHome) {

	// TODO
	Article* artigo = new Article(client, barCode);
	artigo->setDeliverHome(deliverHome);
	artigo->setPresent(present);
	return artigo;

}

/**
 * Add an Article to the bags of this purchase. A new bag is added when the last bag is full.
 */
void Purchase::putInBag(Article* article) {

	// TODO
    if(bags.back().size() >= 5)
    {
        stack<Article*> newbag;
        newbag.push(article);
        bags.push_back(newbag);
    }
    else
    {
        bags.back().push(article);
    }
}

/**
 * Pop from the bags all articles that are presents.
 * All other articles are pushed back into the bags where they were, maintaining order.
 */
vector<Article*> Purchase::popPresents() {

	// TODO
    vector<Article*> presents;
    for(auto &bag: bags)
    {
        vector<Article*> aux;
        while(!bag.empty())
        {
            if(bag.top()->getPresent()) presents.push_back(bag.top());
            else aux.push_back(bag.top());
            bag.pop();
        }
        for(int i = (aux.size()-1); i >= 0; i--) bag.push(aux[i]);
    }
	return presents;

}

