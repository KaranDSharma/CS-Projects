// Author: Karan Sharma CS1300 Spring 2018
// Recitation: 101 – Akriti Kapur
// Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
// Rec8 - Problem #1,2,3,4,5
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
* Algorithm: checks if file can be opened
*   1. checks if file can be opened, if yes returns true
*   2. if unable to open returns false
*   Input parameters: string filename
*   Output: no direct output
*   Returns: boolean (true or false)
*/
bool checkFile(string filename)
{
    ifstream myfilestream; //Y read N write
    myfilestream.open(filename);
    
    if (myfilestream.is_open()) //checks if file can be opened, if yes returns true
    {
        return true;
    } 
    else //if unable to open returns false
    {
        return false; 
    }
}

/**
* Algorithm: opens file and writes the square of the numbers 1-10 each on its own line
*   1. checks if file can be opened, if yes runs for loop and returns 0
*   2. puts the square of numbers 1-10 into filestream, separated my an enter
*   3. returns -1 if unable to open
*   Input parameters: string filename
*   Output: no direct output
*   Returns: integer value
*/
int fileLoadWrite(string filename)
{
    
    ofstream myfilestream; //N read Y write
    myfilestream.open(filename);
    
    if (myfilestream.is_open()) //checks if file can be opened, if yes runs for loop and returns 0
    {
        
        for(int i = 1; i<11; i++) //puts the square of numbers 1-10 into filestream, separated my an enter
        {
            myfilestream << i*i << "\n";
        }
        return 0;
    } 
    else //returns -1 if unable to open
    {
        return -1; 
    }
    myfilestream.close(); //closes file
}

/**
* Algorithm: reads a file, returns number of lines in the file
*   1. if fails to open file returns -1
*   2. else counts the individual linesusing register variable count
*   Input parameters: string filename
*   Output: no direct output
*   Returns: integer value count
*/
int fileLoadRead(string filename)
{
    
    ifstream myfilestream; //Y read N write
    myfilestream.open(filename);
    
    string line; //variable for getline function
    int count = 0;
    
    if (myfilestream.fail()) //if fails to open file returns -1
    {
        return -1;
    } 
    
    else //else counts the individual linesusing register variable count
    {
        while(getline(myfilestream,line))
        {
            count++;
        }
        return count; //returns number of lines
    }
}

/**
* Algorithm: reads file and stores contents in an array
*   1. if fails to open file returns -1
*   2. while there are items in the file, if the length is not zero store the line in the array and increase register variable
*   Input parameters: string fileName, string wordArray[], int sizeArray
*   Output: no direct output
*   Returns: return register variable for number of lines
*/
int getLinesFromFile(string fileName, string wordArray[], int sizeArray)
{
    ifstream myfilestream; //Y read N write
    myfilestream.open(fileName);
    
    string line; //variable for getline function
    int count = 0;
    
    if (myfilestream.fail()) //if fails to open file returns -1
    {
        return -1;
    } 
    
    else
    {
        while(getline(myfilestream,line)) //while there are items in the file
        {
            if(line.length()!=0) //if the length is not zero
            {
                wordArray[count] = line; //store the line in the array
                count++; //increase register variable
            }
        }
        return count; //return register variable for number of lines
    }
}

/**
* Algorithm: function that converts first n vals of array into double and computes the average, then writes the n'th item and the average to the file
*   1. sums up the numbers till n
*   2. if array is empty doesnt do anything
*   3. if able to open print nth index in the array and the average (avg/n)
*   4. else report failure to open
*   Input parameters: string fileName, string data[], int n, int size
*   Output: no direct output but writes name and average to file
*   Returns: nothing
*/
void saveData(string fileName, string data[], int n, int size) 
{
    ofstream myfilestream; 
    myfilestream.open(fileName);
    
    double avg = 0;
    
    for(int i = 0; i<n; i++)
    {
       avg = stod(data[i]) + avg; //sums up the numbers till n
    }
    
    if(data[0]=="")
    {
        //if empty doesnt really do anything! :D
    }
    else
    {
        if (myfilestream.is_open()) //if able to open print nth index in the array and the average (avg/n)
        {
            myfilestream << "Name: " << data[n] << "\n";
            myfilestream << "Avg: " << avg/n;
        }
        
        else //else report failure to open
        {
            cout << "file open failed" << endl;
        }
    }
}

int main() 
{
    //test cases problem 1
    string filename1 = "doesntexist.txt";
    cout << checkFile(filename1);
    string filename2 = "myfile.txt";
    cout << checkFile(filename2);
    //test cases problem 2
    int x = fileLoadWrite("file1.txt");
    int y = fileLoadWrite("testFile.txt");
    //test cases problem 3
    string filenameA = "DNEFile.txt";
    int A = fileLoadRead(filenameA);
    string filenameB = "testFile2.txt";
    int B = fileLoadRead(filenameB);
    //test cases problem 4
    string wordArray1[4];
    int C = getLinesFromFile("zeroFile.txt", wordArray1, 4);
    string wordArray2[12];
    int D = getLinesFromFile("emptyLines.txt", wordArray2, 12);
    //test cases problem 5
    string data1[5] = {"0", "0", "0", "0", "G"};
    string filenameX = "my_data.txt";
    saveData(filenameX, data1, 4, 5);
    string data2[4] = {"3.2", "-1.1", "0.4", "Manzoni"};
    string filenameY = "my_data2.txt";
    saveData(filenameY, data2, 3, 4);
}