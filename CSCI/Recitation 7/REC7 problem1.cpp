// Author: Karan Sharma CS1300 Spring 2018
// Recitation: 101 – Akriti Kapur
// Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
// Rec 7 - Problem #1,2,3,4
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int Split(string line, char sep, string fillArray[], int max )
{
    //counting variables to maintain spots    
    int tab=0;
    int start=0;
    int count=1;
    max=line.length();
    
    if(max==0)
    {
        count=count-1;
    }
    else
    {
        for(int i=0;i<line.length(); i++)
        {
    
            if(line[i]==sep)
            {
                fillArray[tab]=line.substr(start,i-start);
                count++;
                tab=tab+1;
                start=i+1;
            }
            if(i==(max-1))
            {
                fillArray[tab]=line.substr(start,i+1);
            }
        }
    }
    
    return count;
    cout<<count;

}

int GetScores(string str, int arr[], int size)
{
    //counting variables to maintain spots
    int start = 0;
    int count = 0;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ')
        {
            arr[count++] = stoi(str.substr(start, i-start));
            start = i+1;
        }
        
    }
    
    if(start != 0)
    {
        arr[count++] = stoi(str.substr(start, str.length()-start+1));
    }
    
    else if(str.length() > 0)
    {
        arr[count++] = stoi(str.substr(start, str.length()-start+1));
    }
    
    return count;
}


void floodMap(double mat[][4], int rows, double waterLevel)
{
    for(int i = 0; i < rows; i++)
    {
        
        for(int x = 0; x < 4; x++)
        {
            //compares 2D matrix to double val given
            if(mat[i][x] > waterLevel)
            {
                cout << '_';
            }
            
            else
            {
                cout << '*';
            }
            
        }
        
        cout << '\n';
    }
}

void fillMatrix(int matrix[][4], int n)
{
    for(int i = 0; i < n; i++)
    {
        //nested for loop to iterate rows and columns
        for(int x = 0; x < 4; x++)
        {
            matrix[i][x] = i + x;
        }
        
    }
}


int main() 
{
    string words[10];
    int values[3];
    int values2[4];
    double examp[10][4];
    int matrix[10][4];
    int test[13][4];

    Split("cow/chicken/fish", '/', words, 10 );
    Split("chicken/orange/cat", '/', words, 10 );
    GetScores("123 456 789", values, 3 );
    GetScores("123 456 789", values2, 4 );
    fillMatrix(matrix, 10);
    fillMatrix(test, 13);
    floodMap(examp, 10, 5);
    floodMap(examp, 10, 4);
}
