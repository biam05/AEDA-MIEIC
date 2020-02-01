/*
 * Restaurant.cpp
 *
 *  Created on: 17/11/2015
 *      Author: hlc
 */

#include "Restaurant.h"

using namespace std;

Restaurant::Restaurant() { }

Restaurant::Restaurant(vector< stack<Dish*> >* cl, queue<Dish*>* di, list<Dish*>* dr) {
	if(cl != NULL) clean = *cl;
	if(di != NULL) dirty = *di;
	if(dr != NULL) drying = *dr;
}

void Restaurant::addTable(unsigned int n_places) {
	tables.push_back(Table(n_places));
}

void Restaurant::addTable(Table& t) {
	tables.push_back(t);
}

const Table& Restaurant::getTable(vector<Table>::size_type idx) const {
	return tables[idx];
}

/**
 * Gets the clean dishes stack for a given collection and type.
 * If there is none, adds and returns an empty stack.
 */
stack<Dish*>& Restaurant::getCleanDishStack(string collection, TypeOfDish type) {

	for(vector< stack<Dish*> >::iterator it = clean.begin(); it != clean.end(); ++it) {
		if((*it).empty() || ((*it).top()->getCollection() == collection && (*it).top()->getType() == type)) {
			return *it;
		}
	}

	stack<Dish*> st;
	clean.push_back(st);
	return clean.back();
}

const queue<Dish*>& Restaurant::getDirty() const {
	return dirty;
}

const list<Dish*>& Restaurant::getDrying() const {
	return drying;
}

/**
 * Adds a number of dishes of a collection/type to the respective clean stack.
 */
void Restaurant::addDishes(unsigned int n, string collection, TypeOfDish type) {

	// TODO
	Dish *dish = new Dish(collection, type);
	for(int i = 0; i < n; i++)
    {
	    getCleanDishStack(collection, type).push(dish);
    }
}

/**
 * Washes a dish, getting if from the dirty queue and putting it in the wet list.
 * Returns the washed dish.
 */
Dish* Restaurant::washDish() {

	// TODO
    Dish* d = dirty.front();
    dirty.pop();
    drying.push_back(d);
	return d;
}

/**
 * Clears a table, placing all dishes that are on it in the dirty queue.
 */
void Restaurant::clearTable(vector<Table>::size_type idx) {

	// TODO
    if(idx < tables.size())
    {
        vector<Dish*> toclean = tables[idx].clear();
        for(int i = 0; i < toclean.size(); i++)
        {
            dirty.push(toclean[i]);
        }
    }
}

/**
 * Stores in the respective clean stack all drying dishes of a given collection and type.
 */
void Restaurant::storeDryDishes(string collection, TypeOfDish type) {

	// TODO
    vector<Dish*> dishesToBeStored;
    for(auto it = drying.begin(); it != drying.end(); it++){
        if((*it)->getCollection() == collection && (*it)->getType() == type){
            dishesToBeStored.push_back(*it);
            it = drying.erase(it);
            if(it == drying.end())
                it--;
        }
    }
    addDishes(dishesToBeStored.size(),collection,type);

}

/**
 * Puts Plates of a given collection in a table.
 * Throws TableNotReadyException when the table is not empty.
 * Throws NotEnoughDishesException when there are not enough clean plates of the collection.
 */
void Restaurant::setupTable(vector<Table>::size_type idx, string collection) {

	// TODO
	if(idx < tables.size())
    {
	    int table_size = tables[idx].getPlaces().size();
	    int no_plates = getCleanDishStack(collection,Plate).size();
	    vector<Dish*> dishesForTable;
        for(int i = 0; i < table_size; i++){
            if(tables[idx].getPlaces()[i].size() > 0)
                throw Restaurant::TableNotReadyException();
        }
	    if(no_plates < table_size) throw NotEnoughDishesException();
	    for(int i = 0; i < table_size; i++)
        {
	        dishesForTable.push_back(getCleanDishStack(collection,Plate).top());
	        getCleanDishStack(collection,Plate).pop();
        }
        tables[idx].putOn(dishesForTable);
    }
}

/**
 * Picks the dry dishes and groups them.
 * Returns the grouped dishes.
 */
list<Dish*> Restaurant::pickupAndGroupDryDishes() {
    list<Dish*> dry_grouped = drying;
    dry_grouped.sort(compareDishPointer);
    drying.clear();
    return dry_grouped;
}

/**
 * Stores grouped dishes in the respective clean stacks.
 * Returns the number of stacks that have been updated.
 */
int Restaurant::storeGroupedDishes(list<Dish*> grouped_dishes) {

    int counter = 0;
    list<Dish*> temp = grouped_dishes;
    for(list<Dish*>::iterator it = temp.begin(); it != temp.end(); it++){
        int numberOfCurrentDishes = 1;
        Dish currentDish = **it;
        it++;
        if(it != temp.end()){
            while(**it == currentDish){
                numberOfCurrentDishes++;
                it++;
            }
        }
        it--;
        addDishes(numberOfCurrentDishes, currentDish.getCollection(), currentDish.getType());
        counter++;

    }
	return counter;
}

