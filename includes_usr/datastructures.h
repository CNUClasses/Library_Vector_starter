#pragma once
#include <string>
#include "constants.h"

enum book_checkout_state{UNKNOWN=0,IN,OUT};

struct book{
	int book_id;
	std::string title;
	std::string author;
	book_checkout_state state;
	int loaned_to_patron_id;

	//a little magic, default struct constructor to initialize stuff to known state
	book():book_id(UNINITIALIZED),state(UNKNOWN), loaned_to_patron_id(NO_ONE){};
};

struct patron{
	int patron_id;
	std::string name;
	int number_books_checked_out;

	//a little magic, default struct constructor to initialize stuff to known state
	patron():patron_id(UNINITIALIZED), number_books_checked_out(NONE){};
};
