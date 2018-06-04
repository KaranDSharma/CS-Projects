#include <iostream>

using namespace std;

int main()
{
	// Put your algorithms here. We have provided an example below of loading from the external data files.
	//-----------------------------------------------------------------------------------------------------------
	//
	// create new Library object which will have all users in an array and all books in an array 
	// Read the file books.txt 
	// Read the file users.txt 
	// Check if file open fails for either file 
	//		if a file open fails, print "Error. User file or book file could not be found. Please make sure that users.txt and books.txt is in the same directory."
	//		exit program 
	// Create a book object for each book in the book file 
	// Create a user object for each user in the book file 
	//		Prompts user to enter name after successfully loading
	//			if nothing entered, reprompts
	//			elseif
	//				check users file to see if existing user, if existing user load info from users file
	//				greet existing user with welcome back
	//			else new user and write to users file -name-
	//				greet new user to the library
	// present menu to the user
	// the menu should have the following options:
	//		if given valid input present following options (valid input = v, r, g, q)		
	//			(q)uit
	//				write updated data (if any) to users file
	//				alert the user: data successfully saved, goodbye!
	//			(v)iew own ratings
	//				reads user file for current user
	//				references books under user file and any existing ratings
	//				if existing ratings exist
	//					print book title followed by rating listed by user
	//				else print no ratings and return to prompt
	//			(r)ate a book
	//				if given input
	//					prompts user to enter title of book and writes name to books file
	//					prompts user to enter rating of book and ammends book name to include rating in book file
	//					provides confirmation text thanking user for rating -name- -rating-
	//				if given no input
	//					returns user back to menu
	//			(g)et recommended books
	//				use provided metric that determines fitting books 
	//				lists specified books that fit user 
	//				returns user back to menu
	//			
	//		else input is invalid and reprompt the user with the original options	

	return 0;
}