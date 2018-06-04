// Author: Karan Sharma CS1300 Spring 2018
// Recitation: 101 – Akriti Kapur
// Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
// Homework 5 - Problem #1,2,3
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

/*
   This program processes a 16 bit uncompressed mono .WAV file.
   Courtesy of Cay Horstman (Wiley Publisher)
*/

/**
   Processes the sound samples. Modify this function to change
   the way the sound is processed.
   @param samples the sound samples in the sound file
   @param size the number of samples
*/
void process(int samples[], int size)
{
   // Here, we make the sound three times as loud

   for (int i = 0; i < size; i++)
   {
      samples[i] = 3 * samples[i];
   }
}


// your function reverse() goes here
/**
   Processes the sound samples. Reverses the values in the samples array.
   @param samples the sound samples in the sound file
   @param size the number of samples
*/
/**
* Algorithm: Reverses the values in the samples array.
*   1. works on half the array at a time, for loop iterating for half of size
*   2. first index = last index, stores value into temp
*   Input parameters: integer type array and integer for size
*   Output: no direct output but modifies array  
*   Returns: nothing
*/
void reverse(int samples[], int size)
{

    for (int i = 0; i < (size / 2); i++) //works on half the array at a time, for loop iterating for half of size
    {
        int temporary = samples[i];
        
        samples[i] = samples[(size - 1) - i]; //first index = last index, stores value into temp
        samples[(size - 1) - i] = temporary;
    }

}





// your function add_echo() goes here
/**
   Processes the sound samples. Adds an echo to the samples array: 
   Take a sample and replace it by the sum of its original value and 
   another value, from "delay" seconds earlier.  
   @param samples the sound samples in the sound file
   @param size the number of samples
   @param sample_rate the number of samples per second
   @param delay the number of seconds echo delay
*/

/**
* Algorithm: Adds an echo to the samples array: 
   Take a sample and replace it by the sum of its original value and 
   another value, from "delay" seconds earlier.  
*   1. Creates a buffer array called newArray and starting position defined as rate*delay
*   2. for loop iterating to add beginning of array to index number position. stores all values in buffer array
*   3. else statement to store the values before the position number
*   4. for loop to put values in buffer array back into samples[]
*   Input parameters: integer type array, integer for size, integer for rate, double for delay
*   Output: no direct output but modifies array by adding echo to particular indexes  
*   Returns: nothing
*/

void add_echo(int samples[], int size, int rate, double delay)
{
   int newArray[size];
   int position = rate*delay;
   //Creates a buffer array called newArray and starting position defined as rate*delay
   for (int i = 0; i < size; i++)
   {
      if(position<size)
      {
         int add = samples[i];
         newArray[position] = (samples[position] + add); //for loop iterating to add beginning of array to index number position. stores all values in buffer array
         position++;
      } 
      else
      {
         newArray[size-i-1] = samples[size-i-1]; //else statement to store the values before the position number
      }
   }
   for (int i = 0; i < size; i++)
   {
        samples[i] = newArray[i]; //for loop to put values in buffer array back into samples[]
   }
   
}






// your function normalize() goes here
/**
   Processes the sound samples. Normalize the values in the samples array:
   Find the maximum value. Multiply all samples by 36773 and divide by the maximum value.
   @param samples the sound samples in the sound file
   @param size the number of samples
*/

/**
* Algorithm: Normalize the values in the samples array:
   Find the maximum value. Multiply all samples by 36773 and divide by the maximum value.
*   1. integer type reference point defined as first index in array
*   2. identifies max and reassigns into reference variable
*   3. for loop to store back into samples new values of index *36773/[max]
*   Input parameters: integer type array and integer for size
*   Output: no direct output but normalizes array by multiplying by 36773/[max]  
*   Returns: nothing
*/
void normalize(int samples[], int size)
{
   int ref = samples[0]; //integer type reference point defined as first index in array
   for (int i = 0; i < size; i++)
   {
      if(samples[i]>ref)
      {
         ref = samples[i]; //identifies max and reassigns into reference variable
      }
   }
   for (int i = 0; i < size; i++)
   {
      samples[i]=((samples[i]*36773)/ref); //for loop to store back into samples new values of index *36773/[max]
   }
}






// -------------------------------------------------------------------

/*
  The code below processes a file in the WAV format.
  You can use this program to manipulate sound files without 
  reading or understanding the code below. 

  The code uses C++ features that are introduced in chapters 7 and 8, 
  as well as the internals of the WAV format 
  (https://ccrma.stanford.edu/courses/422/projects/WaveFormat/)
*/

/**
   Gets an unsigned 4-byte integer from a binary stream.
   @param stream the stream
   @return the integer 
*/
int get_unsigned_int4(fstream& stream)
{
   int result = 0;
   int base = 1;
   for (int i = 0; i < 4; i++)
   {
      result = result + stream.get() * base;
      base = base * 256;
   }
   return result;
}

/**
   Gets an unsigned 2-byte integer from a binary stream.
   @param stream the stream
   @return the integer
*/
int get_unsigned_int2(fstream& stream)
{
   int lo = stream.get();
   int hi = stream.get();
   return lo + 256 * hi;
}

/**
   Gets a signed 2-byte integer from a binary stream.
   @param stream the stream
   @return the integer
*/
int get_signed_int2(fstream& stream)
{
   int lo = stream.get();
   int hi = stream.get();
   int result = lo + 256 * hi;
   if (result >= 32768) { result = result - 65536; }
   return result;
}

/**
   Puts a signed 2-byte integer to a binary stream.
   @param stream the stream
   @param value the integer to put
*/
void put_signed_int2(fstream& stream, int value)
{
   if (value < 0) { value = value + 65536; }
   stream.put(value % 256);
   stream.put(value / 256);
}

int main()
{
   cout << "Please enter the file name: ";
   string filename;
   cin >> filename;

   fstream stream;

   // Open as a binary file
   stream.open(filename.c_str(), ios::in | ios::out | ios::binary);

   // Check that we can handle this file
   stream.seekg(20);
   int format_type = get_unsigned_int2(stream);
   if (format_type != 1)
   {
      cout << "Not an uncompressed sound file." << endl;
      return 1;
   }
   int num_channels = get_unsigned_int2(stream);
   if (num_channels != 1)
   {
      cout << "Not a mono sound file." << endl;
      return 1;
   }

   int sample_rate = get_unsigned_int2(stream);

   stream.seekg(34);
   int bits_per_sample = get_unsigned_int2(stream);
   if (bits_per_sample != 16)
   {
      cout << "Not a 16 bit sound file." << endl;
      return 1;
   }

   // Read data size and allocate data array
   stream.seekg(40);
   int data_size = get_unsigned_int4(stream) / 2; // 2 bytes per data
   int* samples = new int[data_size];

   // Read sound data
   for (int i = 0; i < data_size; i++) 
   {
      samples[i] = get_signed_int2(stream);
   }

   // Process sound data
   process(samples, data_size);

   // Replace "Process sound data" and the call to the process 
   // function with option A or option B below

   // A. Reverse
   // 1. Call the reverse function

   // B. Add echo
   // 1. Declare and initialize variable for echo delay
   // 2. Call the add_echo function
   // 3. Call the normalize function

   // Write sound data
   stream.seekp(44);
   for (int i = 0; i < data_size; i++)
   {
      put_signed_int2(stream, samples[i]);
   }

   stream.close();

   delete[] samples;
     
   return 0;
}