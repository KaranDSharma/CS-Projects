// Author: Karan Sharma CS1300 Spring 2018
// Recitation: 101 – Akriti Kapur
// Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
// Rec11 
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

/**
* Algorithm: tests numbers to see if is exception 
*   1. for loop iterating to str length
*   2. if statement that character in array casted to integer matches 48 and 57, returns false
*   Input parameters: string str
*   Output: nothing
*   Returns: bool true or false
*/
bool testNum(string str){
    for(int i = 0; i < str.length(); i++){
        if(!(int(str[i]) >= 48 && int(str[i]) <= 57)){
            return false;
        }
    }
    return true;
}

int main(){
    string temp;
    int num;
    vector<int> vec; //vector declaration
    
    for(;;){
        cout << "Please enter a positive integer: " << endl;
        cin >> temp;
        
        if(temp.length() == 1 && tolower(temp[0]) == 'q'){
            for(int i = 0; i < vec.size(); ++i){ //for loop testing with vector size
                cout << vec[i] << ' ';
            }
            return 0;
        }
    
        while(!(testNum(temp))){
            cout << "I that is NOT a valid input." << endl; //checking validity of input
            cout << "Please enter a positive integer: " << endl;
            cin >> temp;
        }
        num = stoi(temp);
        
        if(vec.size() == 0){
            vec.push_back(num);   //pushback
        }else if(num % 5 == 0){
            vec.erase(vec.begin()); //erase
        }else if(num % 3 == 0){
            vec.pop_back(); //popback
        }else{
            vec.push_back(num); //pushback to num
        }
    }
}