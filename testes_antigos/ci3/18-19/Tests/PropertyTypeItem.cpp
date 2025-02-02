#include "PropertyTypeItem.h"

PropertyTypeItem::PropertyTypeItem(string address, string postalCode, string typology, int maxPrice) {
	this->address = address;
	this->postalCode = postalCode;
	this->typology = typology;
	this->maxPrice = maxPrice;
}

string PropertyTypeItem::getAddress() const {
	return this->address;
}

string PropertyTypeItem::getPostalCode() const {
	return this->postalCode;
}

string PropertyTypeItem::getTypology() const {
	return this->typology;
}

int PropertyTypeItem::getMaxPrice() const {
	return this->maxPrice;
}

vector<Property*> PropertyTypeItem::getItems() const {
	return this->items;
}

void PropertyTypeItem::setItems(vector<Property*> properties) {
	items = properties;
}

void PropertyTypeItem::addItems(Property* property) {
	this->items.push_back(property);
}

//
// TODO
//

bool PropertyTypeItem::operator<(const PropertyTypeItem &pti1) const {
    if (address == pti1.address) {
        if (postalCode == pti1.postalCode) {
            if (typology == pti1.typology) {
                return maxPrice < pti1.maxPrice;
            }
            else
                return typology < pti1.typology;
        }
        else
            return postalCode < pti1.postalCode;
    }
    return address < pti1.address;
}

bool PropertyTypeItem::operator==(const PropertyTypeItem &pti1) const {
	return (address == pti1.getAddress() && postalCode == pti1.getPostalCode()
	&& typology == pti1.getTypology());
}
