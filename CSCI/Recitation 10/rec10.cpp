// Author: Karan Sharma CS1300 Spring 2018
// Recitation: 101 – Akriti Kapur
// Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
// Recitation 10 
#include <iostream>
#include <sstream>

using namespace std;

/**
* Algorithm: sort the array using bubble sort and print the number of comparisons and swaps
*   1. (essentially just a boolean flag with integers 1 and 0) 
*   2. assumes no swaps needed, sets flag to 0 to break loop
*   3. for loop to sort and swap if index left is greater than index right
*   4. sets flag to 1 to continue searching for swaps, adds to swap total, adds to comparison total
*   5. changes last value to prevent repeat comparisons
*   6. prints results
*   Input parameters: integer type array and integer type variable num
*   Output: prints sorted array, number of matches, and number of comparisons made
*   Returns: nothing
*/
void bubbleSort(int array[], int num)
{
   /* int flag, last = num;
    int comparison = 0;
    int swap = 0;
    
    while(last>0)
    {
        for(int i = 0;i<last-1; i++)
        {
            if(array[i] > array[i+1] && i != num-1)
            {
                int register1 = array[i];
                int register2 = array[i+1];
                array[i] = register2;
                array[i+1] = register1;
                flag = (i+1);
                swap++;
            }
            comparison++;
        }
        last = flag;
        flag = 0;
    }   
    
    cout<< "Bubble Sort:" << endl;
    for(int i = 0;i<num; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"\n";
    cout<<"Number of comparisons: " << comparison << endl;
    cout<<"Number of swaps: " << swap << endl;
    */ 
    //SO ALL OF THIS IS JUST MORE EFFICIENT N LIKE GIVE ME EXTRA CREDIT <3
    
    int flag = 1, last = num; //"boolean" flag and shifting last value 
    int numCompare = 0; //counts comparisons
    int numSwap = 0; //counts swaps
    int temp; // used in swap to hold array values
    
    //essentially just a boolean flag with integers 1 and 0
    while(flag != 0)
    {
        flag = 0; //assumes no swaps needed, sets flag to 0 to break loop
        for(int i = 0; i < last-1; i++) //for loop to sort and swap if index left is greater than index right
        {
            if(array[i] > array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                flag = 1; //sets flag to 1 to continue searching for swaps
                numSwap++; //adds to swap total
            }
            numCompare++; //adds to comparison total
        }
        last--; //changes last value to prevent repeat comparisons
    }
    //printing code:    
    cout<< "Bubble Sort:" << endl;
    for(int i = 0;i<num; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"\n";
    cout<<"Number of comparisons: " << numCompare << endl;
    cout<<"Number of swaps: " << numSwap << endl;
}

/**
* Algorithm: sort the array using cocktail sort and print the number of comparisons and swaps
*   1. loop condition of false bool
*   2. assumes no swaps needed, breaks loop sets bool to true
*   3. forward comparison loop: sets flag to false to continue making comparisons, adds to swap count, adds to comparison count
*   4. changes upper bound
*   5. if no swaps made through one full iteration breaks loop
*   6. assumes no swaps needed for backward loop, breaks loop sets bool to true
*   7. backward comparison loop: sets flag to false to continue making comparisons, adds to swap count, adds to comparison count
*   8. checks if previous true still holds and breaks loop if does
*   9. changes lower bound
*   10. prints results
*   Input parameters: integer type array and integer type variable num
*   Output: prints sorted array, number of matches, and number of comparisons made
*   Returns: nothing 
*/
void cocktailSort(int array[], int num)
{
    int first = 0, last = num-1, comparison = 0, swap = 0; //variable for dynamically changing first and last, count comparisons and count swaps
    bool flag = false; //actual boolean flag this time lol
    
    while(flag == false) //loop condition of false bool
    {
        flag = true; //assumes no swaps needed, breaks loop sets bool to true
        for(int i = first; i < last; i++) //forward comparison loop
        {
            if(array[i] > array[i+1])
            {
                int register1 = array[i];
                int register2 = array[i+1];
                array[i] = register2;
                array[i+1] = register1;
                flag = false; //sets flag to false to continue making comparisons
                swap++; //adds to swap count
            }
            comparison++; //adds to comparison count
        }
        last--; //changes upper bound 
        
        if(flag == true) //if no swaps made through one full iteration breaks loop
        {
            break;
        }
        
        flag = true; //assumes no swaps needed for backward loop, breaks loop sets bool to true
        
        for(int i = last-1; i >= first; i--) //backward comparison loop
        {
            if(array[i] > array[i+1])
            {
                int register1 = array[i];
                int register2 = array[i+1];
                array[i] = register2;
                array[i+1] = register1;
                flag = false; //sets flag to false to continue making comparisons
                swap++; //adds to swap count
            }
            comparison++; //adds to comparison count
        }
        if(flag == true) //checks if previous true still holds and breaks loop if does
            break;
        first++; //changes lower bound
    
    }    
    
    
    //printing code:
    cout<< "Cocktail Sort:" << endl;
    for(int i = 0;i<num; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"\n";
    cout<<"Number of comparisons: " << comparison << endl;
    cout<<"Number of swaps: " << swap << endl;
}

int main()
{
    //test cases
    int L = 5;
    int A[] = {0,0,0,0,0};
    bubbleSort(A, L); 
    cocktailSort(A, L);
    int M = 5;
    int B[] = {55, 51, 51, 87, 8};
    bubbleSort(B, M);
    cocktailSort(B, M);
}