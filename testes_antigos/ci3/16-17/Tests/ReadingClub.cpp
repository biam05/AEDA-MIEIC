/*
 * ReadingClub.cpp
 *
 *  Created on: 11/12/2016
 *      Author: RRossetti
 */

#include "ReadingClub.h"

ReadingClub::ReadingClub(): catalogItems(BookCatalogItem("", "", 0)) {
	//do nothing!
}

ReadingClub::ReadingClub(vector<Book*> books): catalogItems(BookCatalogItem("", "", 0)) {
	this->books = books;
}

void ReadingClub::addBook(Book* book) {
	this->books.push_back(book);
}

void ReadingClub::addBooks(vector<Book*> books) {
	this->books = books;
}

vector<Book*> ReadingClub::getBooks() const{
	return this->books;
}

BookCatalogItem ReadingClub::getCatalogItem(string title, string author) {
	BookCatalogItem itemNotFound("", "", 0);
	BSTItrIn<BookCatalogItem> it(catalogItems);
	while (!it.isAtEnd())
	{
		if( it.retrieve().getTitle() == title && it.retrieve().getAuthor() == author) {
			BookCatalogItem bci(it.retrieve().getTitle(), it.retrieve().getAuthor(), 0);
			bci.setItems(it.retrieve().getItems());
			return bci;
		}
		it.advance();
	}
	return itemNotFound;
}

void ReadingClub::addCatalogItem(Book* book) {
	BookCatalogItem itemNotFound("", "", 0);
	BookCatalogItem bci(book->getTitle(), book->getAuthor(), book->getYear());
	BookCatalogItem bciX = catalogItems.find(bci);
	if(bciX == itemNotFound) {
		bci.addItems(book);
		this->catalogItems.insert(bci);
	}
	else {
		this->catalogItems.remove(bciX);
		bciX.addItems(book);
		this->catalogItems.insert(bciX);
	}
	books.push_back(book);
}

BST<BookCatalogItem> ReadingClub::getCatalogItems() const {
	return this->catalogItems;
}

vector<UserRecord> ReadingClub::getUserRecords() const {
	vector<UserRecord> records;
	HashTabUserRecord::const_iterator it1 = this->userRecords.begin();
	HashTabUserRecord::const_iterator it2 = this->userRecords.end();
	for(; it1 != it2; it1++) {
			records.push_back(*it1);
	}
	return records;
}

void ReadingClub::setUserRecords(vector<UserRecord>& urs) {
	for(int i = 0; i < urs.size(); i++) userRecords.insert(urs[i]);
}

priority_queue<User> ReadingClub::getBestReaderCandidates() const {
	return readerCandidates;
}
void ReadingClub::setBestReaderCandidates(priority_queue<User>& candidates) {
	readerCandidates = candidates;
}



//
// TODO: Part I   - BST
//

bool sortBooks(Book* b1, Book* b2) {
    if (b1->getTitle() == b2->getTitle()) {
        if (b1->getAuthor() == b2->getAuthor()) {
            return b1->getYear() < b2->getYear();
        }
        return b1->getAuthor() < b2->getAuthor();
    }
    return b1->getTitle() < b2->getTitle();
}

#include <algorithm>
void ReadingClub::generateCatalog() {
    vector<Book *> aux = {books.begin(), books.end()};
    sort(aux.begin(), aux.end(), sortBooks);

    Book *b1 = aux[0];
    BookCatalogItem bci1(b1->getTitle(), b1->getAuthor(), b1->getYear());
    bci1.addItems(b1);

    for (int i = 1; i < aux.size(); i++) {
        if (aux[i]->getTitle() != b1->getTitle() || aux[i]->getAuthor() != b1->getAuthor())
        {
            catalogItems.insert(bci1);
            bci1 = BookCatalogItem(aux[i]->getTitle(), aux[i]->getAuthor(), aux[i]->getYear());
        }
        bci1.addItems(aux[i]);
        b1 = aux[i];
    }
}

vector<Book*> ReadingClub::getAvailableItems(Book* book) const {
	vector<Book*> temp;
	//TODO:
	BSTItrIn<BookCatalogItem> it(catalogItems);
	while(!it.isAtEnd())
    {
	    vector<Book*> aux = it.retrieve().getItems();
	    for(int i = 0; i < aux.size(); i++)
        {
	        if(aux[i]->getAuthor() == book->getAuthor() &&
               aux[i]->getTitle() == book->getTitle() &&
               aux[i]->getReader() == nullptr)
            {
	            temp.push_back(aux[i]);
            }
        }
	    it.advance();
    }

	return temp;
}

bool ReadingClub::borrowBookFromCatalog(Book* book, User* reader) {
	//TODO:
    vector<Book*> availableBooks = getAvailableItems(book);
    if(availableBooks.size() == 0) return false;
    reader->addReading(availableBooks[0]->getTitle(), availableBooks[0]->getAuthor());
    book->setReader(reader);

	return true;
}


//
// TODO: Part II  - Hash Table
//

void ReadingClub::addUserRecord(User* user) {
	//TODO:
    userRecords.insert(user);
}

void ReadingClub::changeUserEMail(User* user, string newEMail) {
	//TODO:
	user->setEMail(newEMail);
}


//
// TODO: Part III - Priority Queue
//

void ReadingClub::addBestReaderCandidates(const vector<User>& candidates, int min) {
	//TODO:
	for(int i = 0; i < candidates.size(); i++)
    {
	    if(candidates[i].getReadings().size() >= min-1)
	        readerCandidates.push(candidates[i]);
    }

}

int ReadingClub::awardReaderChampion(User& champion) {
	//TODO:
    if (readerCandidates.empty())
        return 0;
    User best = readerCandidates.top();
    readerCandidates.pop();
    if (readerCandidates.empty())
    {
        champion = best;
        readerCandidates.push(best);
        return 1;
    }
    User aux = readerCandidates.top();
    readerCandidates.push(best);
    if (best.getReadings().size() != aux.getReadings().size())
    {
        champion = best;
        return readerCandidates.size();
    }
    return 0;
}
























