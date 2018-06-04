# Author: Karan Sharma CS1300 Spring 2018
# Recitation: 101 – Akriti Kapur
# Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
# HW10
class Library:
    #constructor
    def __init__(self, books_filename, ratings_filename):
        self.name = ""
        self.book_list = []
        self.user_dictionary = {}
        self.read_books(books_filename)
        self.read_users(ratings_filename)
        print("Data Loaded successfully!")
        #self.login()
        #self.menu()
        
    # Algorithm: reads file name, checks if valid file, and writes each line in lowercase to file
    #   1. checks if any filename entered
    #   2. exceptions for file not found when file cant be opened
    #   3. reads each line and appends booklist with lowercase lines
    #   Input parameters: string file_name
    #   Output: exception strings
    #   Returns: exception strings
    def read_books(self, file_name):
        if(file_name == ''):
            return ("File not found")
        try:
            f = open(file_name, 'r')
        except IOError:
            return ("File not found")
        contents = f.readlines()
        for line in contents:
            self.book_list.append(line.lower())
    
    # Algorithm: add entries to a member dictionary variable for ratings from the file 
    #   1. attempts to open file with handles for exceptions
    #   2. reads each line of file, strips line of \n, splits on the comma, and splits split2 on spaces
    #   3. appends user dictionary if t[0] does not already exist with ratings
    #   Input parameters: string user_file_name
    #   Output: exception strings
    #   Returns: exception strings
    def read_users(self, user_file_name):
        if(user_file_name == ''):
            return ("File not found")
        try:
            f = open(user_file_name, 'r')
        except IOError:
            return ("File not found")
        contents = f.readlines()
        for line in contents:
            temp = line.strip(' \n')
            t = temp.split(',')
            t2 = t[1].split(" ")
            n = len(t2)
            for i in range(0,n):
                if (t[0] in self.user_dictionary) == False:
                    self.user_dictionary[t[0]] = []
                self.user_dictionary[t[0]].append(t2[i])
    
    # Algorithm: After the data is loaded, welcome the user to the library and ask them to enter their name
    #   1. prompts user for name with handling for empty username
    #   2. puts name in lowercase and checks if in the user dictionary
    #   3. if in the user dictionary rewelcomes else new welcome and creates a new list for name
    #   Input parameters: ø
    #   Output: string prompts and responses
    #   Returns: ø
    def login(self):
        inputed = input("Welcome to the Library, What is your name?: \n")
        while (inputed == ""):
            print("You provided an empty username, Please provide a valid user name to login or register")
            inputed = input("Enter your name again: \n")
        self.name = inputed.lower()
        if(self.name in self.user_dictionary) == True:
            print("Welcome back, " + self.name)
        else:
            print("Welcome to the Library, " + self.name)
            self.user_dictionary[self.name] = []
    
    # Algorithm: provides the user a menu of options
    #   1. prompt in a while loop, prompts to view, rate, get, or quit
    #   2. view- calls view ratings function
    #   3. rate- all under flag loop to check and reprompt if book does not exist in the database
    #   4. calls rate book function
    #   4. get- calls recommend book function
    #   5. quit- gives the user a goodbye and breaks the loop
    #   Input parameters: ø
    #   Output: string prompts and responses
    #   Returns: ø
    def menu(self):
        while(True):
            inputed = input("Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?:\n")
            if(inputed == 'v'):
                self.view_ratings(self.name)
            elif(inputed == 'r'):
                flag = False
                while(flag == False):
                    book = input("Enter the name of the book that you would like to rate:\n")
                    book = book.lower()
                    rate = input("Enter your rating of the book:\n")
                    if(book == ""):
                        print("The book you requested does not exist in the database")
                        continue
                    for i in range(0,len(self.book_list)):
                        temp = self.book_list[i].strip('\n')
                        t = temp.split(',')
                        if(t[1] == book):
                            flag = True
                    if(flag == False):
                        print("The book you requested does not exist in the database")
                self.rate_book(self.name, book, rate)
            elif(inputed == 'g'):
                self.recommend_books(self.name)
            elif(inputed == 'q'):
                print("Goodbye!")
                break
            else:
                print("Please input a valid choice")
    
    # Algorithm: takes in the logged in user name and prints all the books and their ratings which have been read by the user
    #   1. checks if name exists in dictionary, returns to break if name does not exist
    #   2. travels along the length of the dictionary stripping strings of \n and splitting at the ,
    #   3. prints title t[1] and rating[i] for any entry that has a nonzero rating
    #   Input parameters: string current_user_name
    #   Output: string prompts and responses
    #   Returns: null at edge case     
    def view_ratings(self, current_user_name):
        print("Here are the books that you have rated:")
        if(self.name in self.user_dictionary) == False:
            print("...")
            return
        rating = self.user_dictionary[current_user_name]
        for i in range(0,len(rating)):
            if(rating[i] != '0'):
                temp = self.book_list[i].strip('\n')
                t = temp.split(',')
                print("Title : " + t[1])
                print("Rating : " + rating[i])
                print("------------------------------")
    
    # Algorithm: takes in the logged in user name, the book name that user wants to rate and the rating of that book 
    #   1. bool flag to handle case where book is not in database
    #   2. edits booklist entry i by stripping \n and splitting at the ,
    #   3. if book names match, assigns entered rating and prints success string
    #   Input parameters: string value: current_user_name, book_name, rating
    #   Output: string prompts and responses
    #   Returns: ø  
    def rate_book(self, current_user_name, book_name, rating):
        flag = False
        for i in range(0,len(self.book_list)):
            temp = self.book_list[i].strip('\n')
            t = temp.split(',')
            if(t[1] == book_name):
                r = self.user_dictionary[current_user_name]
                r[i] = rating
                print("Success!")
                print("Thank-you. The rating for the book titled \""+book_name+"\" has been updated to "+r[i])
                flag = True
        if(flag == False):
            print("The book you requested does not exist in the database")
    
    # Algorithm: takes 2 user ids to find and return the similarity between all of the ratings of the two given users
    #   1. handles edge case of either user not being in user dictionary by returning 0
    #   2. calculates similarity by summing total with index i_1 - index i_2 whole squared
    #   Input parameters: string user1 and user2
    #   Output: ø
    #   Returns: integer total (similarity score)
    def calc_similarity(self, user1, user2):
        total = 0
        if((user1 in self.user_dictionary) == False) or ((user2 in self.user_dictionary) == False):
            return total
        r1 = self.user_dictionary[user1]
        r2 = self.user_dictionary[user2]
        for i in range(0,len(r1)):
            total = total + ((int(r1[i]) - int(r2[i]))**2)
        return total
    
    # Algorithm: takes a current_user_nme  and returns the user_name of user whose similarity score with the current_user_name  is the lowest
    #   1. handles situation where compares to same user by continuing when crosses identical string
    #   2. calculates similarity for each user and checks if temp similarity is less than current user similarity
    #   3. if less, is more similar and redefines username
    #   Input parameters: string current_user_name
    #   Output: ø
    #   Returns: string username (most similar user)
    def get_most_similar_user(self, current_user_name):
        similarity = 100000
        username = ""
        for user in self.user_dictionary:
            if(user == current_user_name):
                continue
            temp = self.calc_similarity(current_user_name,user)
            if(temp<similarity):
                similarity = temp
                username = user
        return username
    
    # Algorithm: find a set of recommendations of new books to read for a given user name
    #   1. bool flag to check if recommendations exist for a given individual
    #   2. for loop checking for empty rating for user1 and rating of 3 or 5 for user 2
    #   3. if passes if check, edits booklist[i] to append to list of recommendations recomms
    #   4. boolean flag goes true, checks for count == 10 to make sure maximum number of recommendations isnt exceeded
    #   5. if flag is true, prints each index in the recomms list to user
    #   Input parameters: string current_user_name
    #   Output: string prompts and responses
    #   Returns: ø
    def recommend_books(self, current_user_name):
        user2 = self.get_most_similar_user(current_user_name)
        l1 = self.user_dictionary[current_user_name]
        l2 = self.user_dictionary[user2]
        flag = False
        recomms = []
        count = 0
        for i in range(0,len(l1)):
            if(int(l1[i]) == 0) and ((int(l2[i]) == 3) or (int(l2[i]) == 5)):
                temp = self.book_list[i].strip('\n')
                t = temp.split(',')
                s = (t[1] + " by " + t[0])
                recomms.append(s)
                count = count+1
                flag = True
                if(count == 10):
                    break
        if(flag == True):
            print("Here are some of the books that we think you would like")
            for i in recomms:
                print(i)
        else:
            print("There are no recommendations for you at present")
    
def main():
    L = Library("books.txt","ratings.txt")
    name1 = "ben"
    name2 = "leah"
    bookname = "speak"
    rating = "3"
    #test functions
    L.read_books("books.txt")
    L.read_users("ratings.txt")
    L.view_ratings(name1)
    L.rate_book(name1, bookname, rating)
    L.calc_similarity(name1, name2)
    L.get_most_similar_user(name1)
    L.recommend_books(name1)
    L.login()
    L.menu()
    
    
    
if __name__ == "__main__":
    main()
    