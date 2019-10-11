#include "../includes_usr/fileIO.h"
#include <fstream>
#include <sstream>
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char* filename) {
	ifstream myfile(filename);
	//TODO complete return cases
	if (myfile.is_open()) {
		string line;
		while (getline(myfile, line)) {
			book b;
			stringstream a;
			string bookid, title, author, state, patronid;

			getline(a, bookid, ',');

			getline(a, title, ',');
			getline(a, author, ',');
			getline(a, state, ',');
			getline(a, patronid, ',');

			stringstream q(bookid);
			int x = 0;
			q >> x;
			b.book_id = x;

			b.author = author;

			stringstream w(patronid);
			int y = 0;
			w >> y;
			b.loaned_to_patron_id = y;

			b.title = title;

			//b.state = state; convert state to enum?


		}
		myfile.close();
	}
	return COULD_NOT_OPEN_FILE;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	ofstream myfile(filename);
	if(myfile.is_open()){
		return SUCCESS;
	}
	return COULD_NOT_OPEN_FILE;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	fstream myfile(filename);
	if(myfile.is_open()){
		return SUCCESS;
	}

	return COULD_NOT_OPEN_FILE;
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	ofstream myfile(filename);
	if(myfile.is_open()){
		return SUCCESS;
	}
	return COULD_NOT_OPEN_FILE;
}
