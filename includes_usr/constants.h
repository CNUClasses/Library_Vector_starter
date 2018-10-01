#pragma once
#include <string>

const std::string BOOKFILE			= "./tmp/bookfile.txt";
const std::string BOOKFILE_EMPTY	= "./tmp/bookfileMT.txt";
const std::string PATRONFILE		= "./tmp/patronfile.txt";
const std::string PATRONFILE_EMPTY	= "./tmp/patronfileMT.txt";

const std::string NON_EXISTANT = "./tmp/nonexistantfile";
const std::string TMP_FILE = "./tmp/tmp.txt";

const int BOGUS_USER 			= 10000;
const int BOGUS_BOOK 			= 10000;

const int MAX_BOOKS_ALLOWED_OUT = 5;
const int UNINITIALIZED			= -1;
const int NO_ONE				= -2;
const int NONE					=  0;
const int PATRON_0				=  0;

//return codes
const int SUCCESS				= 0;
const int DONT_HAVE				= SUCCESS-1;
const int NOT_AVAILABLE			= SUCCESS-2;
const int TOO_MANY_OUT			= SUCCESS-3;
const int DUPLICATE_NAME		= SUCCESS-4;
const int PATRON_NOT_ENROLLED	= SUCCESS-5;
const int BOOK_NOT_IN_COLLECTION= SUCCESS-6;

const int COULD_NOT_OPEN_FILE	= SUCCESS-7;
const int NO_BOOKS_IN_LIBRARY	= SUCCESS-8;
const int NO_PATRONS_IN_LIBRARY	= SUCCESS-9;

const int ONE_POINTS = 1;
const int TWO_POINTS = 2;
const int THREE_POINTS = 3;
const int FIVE_POINTS = 5;
const int TEN_POINTS = 10;
const int FIFTEEN_POINTS = 15;
