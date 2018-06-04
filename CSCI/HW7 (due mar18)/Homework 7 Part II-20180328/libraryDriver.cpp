// Author: Karan Sharma CS1300 Spring 2018
// Recitation: 101 – Akriti Kapur
// Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
// HW7 - Problem #1,2,3
#include <iostream>
#include <tuple>
#include <limits>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

string toLowercase(string str){
	for(int i = 0; i < str.length(); i++){
		str[i] = tolower(str[i]); 
	}
	return str;
}

class Book {
    private:
        string title;
        string author;
    public:
        Book(){
            title = "NONE";
            author = "NONE";
        };
        
        Book(string t, string a){
            title = t;
            author = a;
        }
        
        void setTitle(string t){
            title = t;
        };
        
        string getTitle(){
            return title.substr(0, title.length()-1);  
        };

        void setAuthor(string a){
            author = a;
        };
        
        string getAuthor(){
            return author;
        };
};

class User{
    private:
        string name;
        int ratings[100];
        int numRatings;
    public:
        User(){
            name = "NONE";
            fill_n(ratings, 100, 0);
            numRatings = 0;
        };
        
        User(string n, int arr[], int numR){
            name = n;
            for(int i = 0; i < 100; i++){
                ratings[i] = arr[i];
            }
            numRatings = numR;
        };
        
        void setName(string n){
            name = n;
        };
        
        string getName(){
            return name;
        };
        
        void setNumRatings(int n){
            numRatings = n;
        };
        
        int getNumRatings(){
            return numRatings;
        };
        
        int setRatingAt(int i, int rat){
            if(i >= numRatings){
                return -1000;
            }else{
                if(rat == -5 || rat == -3 || rat == 0 || rat == 1 || rat == 3 || rat == 5){
                    ratings[i] = rat;
                    cout << "Success!" << endl;
                    return 0;
                }else{
                    cout << "Invalid Input!" << endl;
                    return -1;
                }
            }
        };
        
        int getRatingAt(int i){
            if(i >= 0 && i < 100){
                return ratings[i];
            }else{
                return -1000;
            }
        };
};

class Library{
    private:
        int maxBooks = 100;
        int maxUsers = 100;
        Book books[100];
        User users[100];

        int numBooks;
        int numUsers;
        
    public:
        Library(){
            numBooks = 0;
            numUsers = 0;
        }; 
        
        Library(string booksFile, string usersFile){
            
            numBooks = 0;
            numUsers = 0;
            
            ifstream books(booksFile);
        	ifstream users(usersFile);
        	
        	if(books.is_open() && users.is_open()){
        		string line;
        		int breakPoint;
        		
        		while(getline(books, line) && numBooks < maxBooks){
        			string author;
        			string title;
        			for(int i = 0; i < line.length()-1; i++){
        				if(line[i] == ','){
        					author = toLowercase(line.substr(0, i));
            				title = toLowercase(line.substr(i+1, line.length()-i));
        				}
        			}

        			Book newBook(title, author);
        			this->books[numBooks++] = newBook;
        		}
        		
        		while(getline(users, line) && numUsers < maxUsers){
        			line[0] = toupper(line[0]);
        			string name = "";
        			string ratings = "";
        			for(int i = 0; i < line.length()-1; i++){
        				if(line[i] == ','){
        				    name = toLowercase(line.substr(0, i));
        				    ratings = line.substr(i+1, line.length()-i);
        				}
        			}
        			
        			int rateArr[100];
        			int index = 0, numRate = 0;
            		istringstream stringStream(ratings);
                    string rate; 
                    while(getline(stringStream, rate, ' ')){ // loop though splitting on ' '
                        rateArr[index++] = stoi(rate);
                        if(stoi(rate) != 0){
                            numRate++;
                        }
                    }
                    
                    User newUser(name, rateArr, numRate);
                    this->users[numUsers++] = newUser;
        		}
        		cout << "Data Loaded successfully!" << endl;
        	}else{
        		throw invalid_argument("No matching files found");
        	}
        };
        
        tuple<User, bool> loginUser(string name){
            name = toLowercase(name);
            for(int i = 0; i < numUsers; i++){
                if(users[i].getName() == name){
                    return make_tuple(users[i], false);
                }
            }
            User newUser;
            newUser.setName(name);
            this->users[numUsers++] = newUser;
            return make_tuple(users[numUsers-1], true);
        };
        
        void viewRatings(User userG){
            if(userG.getNumRatings() == 0){
                cout << "You have not rated any books as yet:" << endl;
            }else{
                cout << "Here are the books that you have rated:" << endl;
                for(int i = 0; i < 100; i++){
            	    int rate = userG.getRatingAt(i);
            	    if(rate != 0){
                		cout << "Title : " << books[i].getTitle() << endl;
                		cout << "Rating : " << rate << endl;
                		cout << "------------------------------" << endl;
                	}
                }
            }
        };
        
        bool setRating(User nUser, string book, int rating){
            string lowerBook = toLowercase(book);
            for(int i = 0; i < numBooks; i++){
                if(this->books[i].getTitle().compare(lowerBook) == 0){
                    nUser.setRatingAt(i, rating);
                    return true;
                }
            }
            return false;
        };
            
        void getRecs(User nUser){
            if(nUser.getNumRatings() > 0){
                int bestIdex = 0, temp, bestScore = numeric_limits<int>::max(), tempScore = numeric_limits<int>::max();
                

                for(int i = 0; i < numUsers; i++){
                    if(nUser.getName().compare(this->users[i].getName()) == 0){
                        continue;
                    }
                    tempScore = 0;
                    for(int x = 0; x < 100; x++){
                        temp = nUser.getRatingAt(x) - this->users[i].getRatingAt(x);
                        tempScore = tempScore + pow(temp, 2);
                    }
                    if(tempScore < bestScore){
                        bestScore = tempScore;
                        bestIdex = i;
                    }
                }
                
                int count = 0;
                for(int i = 0; i < 100 && count < 10; i++){
                    if(this->users[bestIdex].getRatingAt(i) > 1 && nUser.getRatingAt(i) == 0){
         
                        count++;
                    }
                }
                if(count == 0){
                    cout << "There are no recommendations for you at present" << endl;
                }else{
                    cout << "Here are some of the books that we think you would like" << endl;
                    int count = 0;
                    for(int i = 0; i < 100 && count < 10; i++){
                        if(this->users[bestIdex].getRatingAt(i) > 1 && nUser.getRatingAt(i) == 0){
                            cout << this->books[i].getTitle()  << " by " << this->books[i].getAuthor() << endl;
                            count++;
                        }
                    }
                }
                
            }else{
                cout << "There are no recommendations for you at present" << endl;
            }
        };
        
        void quit(string outFileName){
            ofstream file(outFileName, ios::trunc);
            
            if(file.is_open()){
                for(int i = 0; i < numUsers; i++){
                    file << this->users[i].getName() << ",";
                    for(int x = 0; this->users[i].getRatingAt(x) != -1000 ; x++){
                        file << this->users[i].getRatingAt(x) << " ";
                    }
                    file << endl;
                }
            }
            cout << "Data successfully saved. Goodbye!";
        };
};

tuple<User, string> login(Library lib){
	string userName;
	
	cout << "Welcome to the Library, What is your name?:" << endl;
	getline(cin, userName);
	
	while(userName.length() == 0){
		cout << "You provided an empty user name, Please provide a valid user name to login or register: " << endl;
		cout << "Enter your name again:" << endl;
	    getline(cin, userName);
	}
	auto temp = lib.loginUser(userName);
	User nUser = get<0>(temp);
	bool isNew = get<1>(temp);
	
	if(isNew){
	    cout << "Welcome to the Library, " << userName << endl;
	}else{
	    cout << "Welcome back, " << userName << endl;
	}
	
	return make_tuple(nUser, userName);
}

int menu(Library lib, User nUser, string givenName){
	string userInput;
	
	cout << "Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?:" << endl;
    getline(cin, userInput);
	
	for(;;){
        if(userInput.length() == 1 && (userInput[0] == 'v' || userInput[0] == 'r' || userInput[0] == 'g' || userInput[0] == 'q')){
        	char userInChar = userInput[0];
        	
        	if(userInChar == 'v'){
        		lib.viewRatings(nUser);
        	}else if(userInChar == 'r'){
        	    string title;
        	    int rating;
        	    
        	    cout << "Enter the name of the book that you would like to rate:" << endl;
        	    getline(cin, title);
        	    cout << "Enter your rating of the book:" << endl;
        	    cin >> rating;
        	    
        	    bool test = lib.setRating(nUser, title, rating);
                if(test){
                    cout << "Thank-you. The rating for the book titled " << title << " has been updated to " << rating << endl;
                }else{
                    // cout << "The Book could not be found!" << endl;
                }
        	}else if(userInChar == 'g'){
        		lib.getRecs(nUser);
        	}else{
        	    lib.quit("ratings_new.txt");
        		break; 
        	}
	    }else{
    		cout << "Please input a valid choice" << endl;
	    }
	    cout << "Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?:" << endl;
        cin >> userInput;
	}
}

int main(){
	try{
		Library lib("books.txt", "ratings.txt"); 
		auto templogin = login(lib);
		User nUser = get<0>(templogin);
	    string givenName = get<1>(templogin);
		
		menu(lib, nUser, givenName);
		
		
	}catch (...){
		cout << "No matching files found";
		return -1;
	}
	return 0;
}