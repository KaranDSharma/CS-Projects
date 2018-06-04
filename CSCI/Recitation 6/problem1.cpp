// Author: Karan Sharma CS1300 Spring 2018
// Recitation: 101 – Akriti Kapur
// Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
// Recitation 6
#include <iostream>
using namespace std;

/**
* Algorithm: prints each value in the array
*   1. for loop from value zero to value of length
*   2. prints myArray index i
*   Input parameters: integer value array and integer value for length
*   Output: each value in the array printed on a separate line 
*   Returns: nothing
*/
void printValues(int myArray[], int length) //takes integer value array and integer value for length
{
    for (int i=0; i<length; i++)
    {
        cout<<myArray[i]<<endl; //prints each value in array myArray from 0 to value of length
    }
}

/**
* Algorithm: calculates the sum of all indices in the array
*   1. variable for sum starting value is 0
*   2. add i value in the array to sum along with existing sum value, and restore into sum
*   Input parameters: integer value array and integer value for length
*   Output: no output 
*   Returns: integer value sum
*/
int getArraySum(int a[], int length) //takes integer value array and integer value for length
{
    int sum = 0; //variable for sum starting value is 0
    
    for (int i=0; i<length; i++)
    {
        sum = sum + a[i]; //add i value in the array to sum along with existing sum value, and restore into sum
    }
    //cout<<sum;
    return sum;
}

/**
* Algorithm: calculates Carnot efficiency given absolute temperatures
*   1. initialize new array to hold changed values of replaceArray
*   2. if right value greater than center and left, store into newArray's i value
*   3. if left value greater than center and right, store into newArray's i value
*   4. if center value greater than right and left, store into newArray's i value
*   5. center val bigger than both, so compare only right and left. if right greater than left store into newArray's i value
*   6. center val bigger than both, so compare only right and left. if left greater than right store into newArray's i value
*   7. for loop to parse newArray back into replaceArray
*   Input parameters: integer value array and integer value for length
*   Output: nothing 
*   Returns: nothing
*/
void replaceNums(int replaceArray[], int length) //takes integer value array and integer value for length
{
    int newArray[length]; //new array to hold changed values of replaceArray
    for (int i=1; i<(length-1); i++)
    {
        if(replaceArray[i+1]>replaceArray[i] and replaceArray[i+1]>replaceArray[i-1]) //if right value greater than center and left, store into newArray's i value
        {
            newArray[i]=replaceArray[i+1];
        }
        else if(replaceArray[i-1]>replaceArray[i] and replaceArray[i-1]>replaceArray[i+1]) //if left value greater than center and right, store into newArray's i value
        {
            newArray[i]=replaceArray[i-1];
        }
        else if(replaceArray[i]>replaceArray[i+1] and replaceArray[i]>replaceArray[i-1]) //if center value greater than right and left, store into newArray's i value
        {
            if(replaceArray[i+1]>replaceArray[i-1]) //center val bigger than both, so compare only right and left. if right greater than left store into newArray's i value
            {
                newArray[i]=replaceArray[i+1];
            }
            else if(replaceArray[i-1]>replaceArray[i+1]) //center val bigger than both, so compare only right and left. if left greater than right store into newArray's i value
            {
                newArray[i]=replaceArray[i-1];
            }
        }
    }
    
    for (int i=1; i<(length-1); i++) //for loop to parse newArray back into replaceArray
    {
        replaceArray[i] = newArray[i];
        //cout<<replaceArray[i]<<endl;
    }
}

int main() 
{
    //create arrays
    int arrayOne[49];
    float arrayTwo[4];
    bool arrayTri[14];
    string arrayFor[12];
    
    //arrays for test cases
    int myArray[3]={2,5,24};
    int a[11]={-194, -16, 124, 728, 380, 374, 933, 517, 467, -181, 937};
    
    //two test cases per function    
    printValues(myArray,3);
    printValues(a,11);
    
    getArraySum(myArray,3);
    getArraySum(a,11);
    
    replaceNums(myArray,3);
    replaceNums(a,11);
}
