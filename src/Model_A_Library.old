//============================================================================
// Name        : 5_Plan_A_Project_Model_A_Library.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <vector>
#include "../includes_usr/library.h"
#include "../includes_usr/datastructures.h"
#include "../includes_usr/constants.h"
#include "../includes_usr/fileIO.h"
#include <bits/stdc++.h>

using namespace std;

//tracks how many points you will get out of 100
//yeah, yeah its a global
int total_points =0;

//this is a template class, its mostly here as a helper for me
//the T and U are generic params, I can substitute any type for them
//they must be comparable with ==, templates are extremely hard to get right BTW
template<typename T, typename U>
bool EXPECT_EQ(T expectedVal, U actualVal,string testnumb = "", int pts=ONE_POINTS){
	bool bout = (expectedVal == actualVal);
	if (bout){
		total_points+=pts;
		cout<<"SUCCESS "+testnumb<<" points:"<<total_points;
	}
	else
		cout<<"FAIL "+ testnumb;
	cout<<endl;
	return bout;
}

//runs a diff command, I'm using (GNU diffutils) 3.3
//this code cadged from stack overflow
bool diff_files(string testoutput,string correctfile, string testnumb = "" ){
	const int SMALL_BUFFER = 512;
	if (testoutput.length()== 0 || correctfile.length()==0)
		return false;

	//build shell command
	string command ="diff "+  testoutput + " " + correctfile;

	FILE *in;
	char buff[SMALL_BUFFER];

	if(!(in = popen(command.c_str(), "r")))
		return false;

	if (fgets(buff, sizeof(buff), in)==NULL)
		return true;
	else
		cout << buff;

	pclose(in);
	return false;
}
/*
 * empties the patron file
 */
void clear_patrons(){
	string cmd = "cp " + PATRONFILE_EMPTY + " " +PATRONFILE;
	system(cmd.c_str());
}

/*
 * empties the book file
 */
void clear_books(){
	string cmd = "cp " + BOOKFILE_EMPTY + " " +BOOKFILE;
	system(cmd.c_str());
}

/*
 * copy clean files from the dont_alter_these_files directory 
 * to the tmp directory. The dont_alter_these_files directory 
 * holds data that lets you initialize your program to a known state
  */
void reset_books_patrons(){
	string cmd1 = "cp ./dont_alter_these_files/bookfile.txt " +  BOOKFILE;
	system(cmd1.c_str());
	
	string cmd2 = "cp ./dont_alter_these_files/patronfile.txt " +  PATRONFILE;
	system(cmd2.c_str());
	
	string cmd3 = "cp ./dont_alter_these_files/bookfileMT.txt " +  BOOKFILE_EMPTY;
	system(cmd3.c_str());
	
	string cmd4 = "cp ./dont_alter_these_files/patronfileMT.txt " +  PATRONFILE_EMPTY;
	system(cmd4.c_str());
}

bool does_file_exist(const std::string &file_name){
	ifstream fle(file_name);
	return fle.good();
}

/*
 * I'll use the following function to test your fileIO routines
 */
void testfileIO(){
	std::vector<book> books;

	//fail on loading bogus file
	EXPECT_EQ(COULD_NOT_OPEN_FILE, loadBooks(books, NON_EXISTANT.c_str()),"1",THREE_POINTS);

	//return empty for empty file
	EXPECT_EQ(NO_BOOKS_IN_LIBRARY, loadBooks(books, BOOKFILE_EMPTY.c_str()),"2",THREE_POINTS);
	
	//load real data
	EXPECT_EQ(SUCCESS, loadBooks(books, BOOKFILE.c_str()),"3",THREE_POINTS);
	
	//save it
	EXPECT_EQ(SUCCESS, saveBooks(books, TMP_FILE.c_str()),"4",THREE_POINTS);
	
	//compare the 2 files (this could fail if you have an extra linefeed in your file)
	if (does_file_exist(TMP_FILE) && does_file_exist(BOOKFILE))
		EXPECT_EQ(true,diff_files(BOOKFILE, TMP_FILE),"5",FIVE_POINTS);
	
	std::vector<patron> patrons;

	//fail on loading bogus file
	EXPECT_EQ(COULD_NOT_OPEN_FILE, loadPatrons(patrons, NON_EXISTANT.c_str()),"6",THREE_POINTS);

	//return empty for empty file
	EXPECT_EQ(NO_PATRONS_IN_LIBRARY, loadPatrons(patrons, PATRONFILE_EMPTY.c_str()),"7",THREE_POINTS);
	
	//load real data (make sure there are patrons in file)
	EXPECT_EQ(SUCCESS, loadPatrons(patrons, PATRONFILE.c_str()),"8",THREE_POINTS);
	
	//save it
	EXPECT_EQ(SUCCESS, savePatrons(patrons, TMP_FILE.c_str()),"9",THREE_POINTS);
	
	//compare the 2 files (this could fail if you have an extra linefeed in your file)
	//compare the 2 files (this could fail if you have an extra linefeed in your file)
	if (does_file_exist(TMP_FILE) && does_file_exist(PATRONFILE))
		EXPECT_EQ(true,diff_files(PATRONFILE, TMP_FILE),"10",FIVE_POINTS);	
}

/*
 * verify numbBooks and numbPatrons
 */
void testnumbBooksAndnumpPatrons(){
	//TODO 
}
/*
 * verify enrollment 
 */
void testenroll(){	
	//TODO
}

/*
 * verify checkin and checkout
 */
void testcheckoutandin(){
	//TODO
}

int main(){	
	//put the original books and patrons files back
	reset_books_patrons();	
	testfileIO();
	testnumbBooksAndnumpPatrons();
	clear_patrons();
	testenroll();
	testcheckoutandin();
	
    return 0;
}
