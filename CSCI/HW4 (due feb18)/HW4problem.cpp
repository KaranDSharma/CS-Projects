// Author: Karan Sharma CS1300 Spring 2018
// Recitation: 101 – Akriti Kapur
// Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
// Homework 4 - Problem #1,2,3
#include <stdio.h>
#include <iostream>
#include<string>

using namespace std;

/**
* Algorithm: calculates similarity score given two sequences
*   1. checks to make sure sequence lengths are the same, if not returns -1
*   2. checks to make sure sequence lengths are greater than zero, if not returns -1
*   3. checks like characters in string and adds to float times for each like character
*   4. calculates similarity score by dividing times by the length of the sequence
*   Input parameters: string values for seqOne and seqTwo
*   Output: float value of similarity score, no direct output in consol  
*   Returns: float value of similarity score
*/
float findSimilarityScore(string seqOne, string seqTwo)
{
    float times = 0;
    
    if(seqOne.length()!=seqTwo.length()) //checks to make sure sequence lengths are the same, if not returns -1
    {
        return -1;
    }
    
    else if(seqOne.length()<=0 or seqTwo.length()<=0) //checks to make sure sequence lengths are greater than zero, if not returns -1
    {
        return -1;
    }
    
    else
    {
        for(int i = 0; i < seqOne.length();i++) //for loop to iterate through entire length of sequence
        {

            if (seqOne[i]==seqTwo[i])
            {
                times++; //adding to times for every like character
            }
        }
        float similarityScore = times/seqOne.length(); //dividing times by the length of the sequence, float value since most likely decimal
        return similarityScore;
    }
}

/**
* Algorithm: calculates the best matching genome given a particular sequence
*   1. checks to make sure genome and sequence lengths are greater than zero, if not returns -1
*   2. checks to make sure sequence length is greater than genome length, if not returns -2
*   3. calculates similarity score for a substring of sequence and the genome and stores into float value shift. if shift is greater than max, store into max and repeat through a for loop
*   Input parameters: string values for genome and sequence
*   Output: the best matching similarity score, no direct output in consol 
*   Returns: the best matching similarity score in a float value variable max
*/
float findBestMatch(string genome, string sequence)
{
    
    if(genome.length()<=0 or sequence.length()<=0) //checks to make sure genome and sequence lengths are greater than zero, if not returns -1
    {
        return -1;
    }
    
    else if(sequence.length() > genome.length()) //checks to make sure sequence length is greater than genome length, if not returns -2
    {
        return -2;
    }
    
    else //calculates similarity score for a substring of sequence and the genome and stores into float value shift. if shift is greater than max, store into max and repeat through a for loop
    {
        float max = 0;
        for(int i=0; i<=(genome.length()-sequence.length());i++) //loop iterates through the length of genome-sequence
        {
            float shift = findSimilarityScore(sequence,genome.substr(i, sequence.length())); //calculates similarity score between a substring of sequence and genome using prior function
            if (shift > max)
            {
                max = shift; //stores shift into max if is greater
            }
        }
        return max; //returning matching similarity score
    }

}

int main() //main method
{
                
    string genomeOne;
    string genomeTwo;
    string genomeThree;
    string sequence;
    //string values for user input
    
    cout<<"Please enter genome 1:"<<endl;
    cin>>genomeOne;
    cout<<"Please enter genome 2:"<<endl;
    cin>>genomeTwo;
    cout<<"Please enter genome 3:"<<endl;
    cin>>genomeThree;
    //user input for three genomes 
    
    while(true) //while loop to ask for sequence repeatedly till appropriate length given
    {

        cout<<"Please enter a sequence:"<<endl;
        cin>>sequence;
        
        if(genomeOne.length()<=0 or genomeTwo.length()<=0 or genomeThree.length()<=0 or sequence.length()<=0)
        {
            cout<<"Genome and sequence cannot be empty."<<endl;
            break; //if one of the genomes is left empty or sequence is left empty, will print error and break the loop stopping the program
        }
        
        else if(sequence.length()>genomeOne.length() or sequence.length()>genomeTwo.length() or sequence.length()>genomeThree.length())
        {
            cout<<"Sequence cannot be longer than genomes."<<endl; //if sequence is greater than any genome, prints error and redirects back to please enter a sequence
        }
        
        else
        {
            float bestMatchOne = findBestMatch(genomeOne,sequence); //storing best match value for 1 into float variable
            float bestMatchTwo = findBestMatch(genomeTwo,sequence); //storing best match value for 2 into float variable
            float bestMatchThree= findBestMatch(genomeThree,sequence); //storing best match value for 3 into float variable
            if(bestMatchOne>bestMatchTwo and bestMatchOne>bestMatchThree) //checks if genome 1 is best match
            {
                cout<<"Genome 1 is the best match."<<endl;
                break;
            }
            else if(bestMatchTwo>bestMatchOne and bestMatchTwo>bestMatchThree) //checks if genome 2 is best match
            {
                cout<<"Genome 2 is the best match."<<endl;
                break;
            }
            else if(bestMatchThree>bestMatchOne and bestMatchThree>bestMatchTwo) //checks if genome 3 is best match
            {
                cout<<"Genome 3 is the best match."<<endl;
                break;
            }
            else if(bestMatchTwo==bestMatchOne and bestMatchOne != bestMatchThree) //checks if genome 1 and 2 are best match
            {
                cout<<"Genome 1 is the best match."<<endl;
                cout<<"Genome 2 is the best match."<<endl;
                break;
            }
            else if(bestMatchTwo==bestMatchThree and bestMatchTwo != bestMatchOne) //checks if genome 2 and 3 are best match
            {
                cout<<"Genome 2 is the best match."<<endl;
                cout<<"Genome 3 is the best match."<<endl;
                break;
            }
            else if(bestMatchThree==bestMatchOne and bestMatchThree != bestMatchTwo) //checks if genome 1 and 3 are best match
            {
                cout<<"Genome 1 is the best match."<<endl;
                cout<<"Genome 3 is the best match."<<endl;
                break;
            }
            else if(bestMatchTwo==bestMatchOne and bestMatchTwo==bestMatchThree) //checks if genome 1, 2, and 3 are best match
            {
                cout<<"Genome 1 is the best match."<<endl;
                cout<<"Genome 2 is the best match."<<endl;
                cout<<"Genome 3 is the best match."<<endl;
                break;
            }
        }
        
    }
}