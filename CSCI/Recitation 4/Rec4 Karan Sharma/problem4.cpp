#include <stdio.h>
#include <iostream>

using namespace std;


void printMultiples(int x, int max)
{
    for(int i = x; i <= max; i = i+x)
    {
        cout<<i<<endl;
    }

}

int main() 
{
	printMultiples(5,15);
	printMultiples(10,30);
    return 0;
}


