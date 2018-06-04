// Author: Karan Sharma CS1300 Spring 2018
// Recitation: 101 – Akriti Kapur
// Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
// HW6 - Problem #1,2,3,4,5
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
/**
* Algorithm: function to store all known, correct words for your spellchecker
*   1. if fails to open file returns -1
*   2. while there are items in the file, if the length is not zero line is the "startIndex" value of the array and iterates startIndex
*   Input parameters: a string filename, an array of strings correctWords[], the size of the array, an integer startIndex.
*   Output: no direct output
*   Returns: (int) return the total number of correct words in the array correctWords
*/

int ReadCorrectWords(string filename, string correctWords[], int size, int startIndex)
{
    ifstream myfilestream; //Y read N write
    myfilestream.open(filename);
    
    string line;
    
    if (myfilestream.fail() or startIndex>=size) //if fails to open file returns -1
    {
        return -1;
    } 
    else
    {
        while(getline(myfilestream,line) && startIndex < size) //while there are items in the file
        {
            if(line.length()!=0) //if the length is not zero
            {
                correctWords[startIndex++]=line; //line is the "startIndex" value of the array and iterates startIndex
            }
        }
        return startIndex;
    }
}

/**
* Algorithm: read in pairs of misspellings and correct spellings
*   1. if fails to open file returns -1
*   2. while there are items in the file, checks for tab character
*   3. substring from beginning to i'th value (tab), substring from after tab to remainder and iterates startIndex 
*   Input parameters: a string filename, a 2D array of strings misspelledWords[][2], the number of rows in the array misspelledWord, an integer startIndex.
*   Output: no direct output
*   Returns: (int) return the total number of word pairs in the array misspelledWords
*/
int ReadMisspelledWords(string filename, string misspelledWords[][2], int rows, int startIndex)
{
    ifstream myfilestream; //Y read N write
    myfilestream.open(filename);
    
    string line;
    
    if (myfilestream.fail() or startIndex>=rows) //if fails to open file returns -1
    {
        return -1;
    } 
    else
    {
        while(getline(myfilestream,line) && startIndex < rows) //while there are items in the file
        {
            for(int i = 0; i<line.length(); i++)
            {
                if(line[i]=='\t') //checks for tab character 
                {
                    misspelledWords[startIndex][0] = line.substr(0,i); //substring from beginning to i'th value (tab)
                    misspelledWords[startIndex++][1] = line.substr(i+1, line.length()-i); //substring from after tab to remainder
                }
            }
        }
        return startIndex;
    }
}

/**
* Algorithm: check if a word is spelled correctly
*   1. lowercases all letters in the array with tolower
*   2. iterating for the length of rows
*   3. if index in array is the same as word return word, else if the i,0'th index of the 2D array is equal to word return missed[i][1]
*   4. returns unknown if conditions arent met
*   Input parameters:a string word, an array of strings correctWords, Size of the array correctWords, a 2D array of strings misspelledWords[][2], the number of rows in the misspelledWords array.
*   Output: can output string unknown
*   Returns: lowercase string word or missed[i][1]
*/
string CheckWord(string word, string correctWords[], int size, string missed[][2], int rows)
{
    for(int i = 0; i < word.length(); i++) word[i] = tolower(word[i]); //lowercases all letters in the array with tolower

    for(int i = 0; i < rows || i < size; i++) //iterating for the length of rows
    {
        if(i < size && correctWords[i] == word) //if index in array is the same as word
        {
            return word;
        }
        else if(i < rows && missed[i][0] == word) //if the i,0'th index of the 2D array is equal to word
        {
            return missed[i][1];
        }
    }
    return "unknown"; //returns unknown if conditions arent met
}

/**
* Algorithm: check spelling in a phrase
*   1. checks for edge case of nothing in file
*   2. while character ' ', Extends the string by appending additional characters at the end of its current value
*   3. if can be opened edits file with substring and new line
*   4. else is edge case and outputs error string
*   Input parameters: A string phrase, A string outputFile (the name of the file), An array of strings correctWords, Size of the array correctWords, A 2D array of strings misspelledWords[][2], The number of rows in the misspelledWords array.
*   Output: edge cases output error strings 
*   Returns: does not return anything
*/
void CheckPhrase(string phrase, string outFileName, string correctWords[], int size, string missed[][2], int rows)
{
    if(phrase.length() > 0)  //checks for edge case of nothing in file
    {
        string newPhrase = "";
        string word;
        
        istringstream stringStream(phrase); //<sstream>
        
        while(getline(stringStream, word, ' ')) //while character ' '
        {
            newPhrase.append(CheckWord(word.c_str(), correctWords, size, missed, rows)); //Extends the string by appending additional characters at the end of its current value
            newPhrase.append(" "); //Extends the string by appending additional characters at the end of its current value
        }
        
        ofstream file(outFileName, ios::app); //N read Y write
        if(file.is_open()) //if can be opened 
        {
            file << newPhrase.substr(0, newPhrase.length()-1) << '\n'; //edits file with substring and new line
        }
        else
        {
            cout << "Unable to create/ access output file." << endl; //edge case
        }
        
    }
    else
    {
        cout << "Phrase is empty. Nothing to write in file." << endl; //edge case
    }
}

/**
* Algorithm: check the spelling in an entire file
*   1. if can be opened while a line exists call checkphrase with given parameters if line has a length
*   2. else edge case and output error string
*   Input parameters: a string inputFile, A string outputFile, an array of strings correctWords, the size of the array correctWords, a 2D array of strings misspelledWords[][2], the number of rows in the misspelledWords array.
*   Output: edge cases output error strings
*   Returns: does not return anything
*/
void CheckFile(string inFile, string outFile, string correctWords[], int size, string missed[][2], int rows)
{
    ifstream file(inFile); //Y read N write
    string line;
    
    if(file.is_open()) //if can be opened
    {
        while(getline(file, line)) //while a line exists
        {
            if(line.length() > 0)
            {
                CheckPhrase(line, outFile, correctWords, size, missed, rows); //call checkphrase with given parameters if line has a length
            }
        }
    }
    
    else
    {
        cout << "invalid" << endl; //edge case
    }
}

int main() 
{
    //test cases 1	
    int n_valid = 4000;
    string correctWords[3500];
    n_valid = ReadCorrectWords("VALID_WORDS_3000.txt",correctWords, 3500, n_valid );
    cout << n_valid;
    int n_valid2 = 0;
    string correctWords2[3500];
    n_valid2 = ReadCorrectWords("VALID_WORDS.txt",correctWords2, 3500, n_valid2 );
    cout << n_valid2;
    //test cases 2
    int n_misspelled = 0;
    string misspelledWords[600][2];
    n_misspelled =  ReadMisspelledWords("MISSPELL.txt", misspelledWords, 600, n_misspelled);
    cout << n_misspelled;
    int n_misspelled2 = 700;
    string misspelledWords2[600][2];
    n_misspelled2 =  ReadMisspelledWords("MISSPELLED.txt", misspelledWords2, 600, n_misspelled2);
    cout << n_misspelled2;
    //test cases 3
    n_valid = ReadCorrectWords("VALID_WORDS_3000.txt",correctWords, 3500, n_valid );
    n_misspelled =  ReadMisspelledWords("MISSPELLED.txt", misspelledWords, 600, n_misspelled);
    cout << CheckWord("csci1300", correctWords,n_valid, misspelledWords,  n_misspelled  );
    n_valid = ReadCorrectWords("VALID_WORDS_3000.txt",correctWords, 3500, n_valid );
    n_misspelled =  ReadMisspelledWords("MISSPELLED.txt", misspelledWords, 600, n_misspelled);
    cout << CheckWord("youe", correctWords,n_valid, misspelledWords,  n_misspelled  );
    //test cases 4
    n_valid = ReadCorrectWords("VALID_WORDS_3000.txt",correctWords, 3500, n_valid );
    n_misspelled =  ReadMisspelledWords("MISSPELLED.txt", misspelledWords, 600, n_misspelled);
    CheckPhrase("","output.txt", correctWords,n_valid, misspelledWords,  n_misspelled);
    n_valid = ReadCorrectWords("VALID_WORDS_3000.txt",correctWords, 3500, n_valid );
    n_misspelled =  ReadMisspelledWords("MISSPELLED.txt", misspelledWords, 600, n_misspelled);
    CheckPhrase("","output.txt", correctWords,n_valid, misspelledWords,  n_misspelled);
    //test cases 5
    n_valid = ReadCorrectWords("VALID_WORDS_3000.txt",correctWords, 3500, n_valid );
    n_misspelled =  ReadMisspelledWords("MISSPELLED.txt", misspelledWords, 600, n_misspelled);
    CheckFile("test_input3.txt","test_output.txt", correctWords,n_valid, misspelledWords,  n_misspelled);
    n_valid = ReadCorrectWords("VALID_WORDS_3000.txt",correctWords, 3500, n_valid );
    n_misspelled =  ReadMisspelledWords("MISSPELLED.txt", misspelledWords, 600, n_misspelled);
    CheckFile("test_input2.txt","test_output.txt", correctWords,n_valid, misspelledWords,  n_misspelled);
    
}