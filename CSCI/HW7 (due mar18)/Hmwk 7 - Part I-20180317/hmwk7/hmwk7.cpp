#include <iostream>
#include <sstream>

using namespace std;

class Book {
    private:
        string title;
        string author;
        
    public:
    Book()
    {
        title = "NONE";
        author = "NONE";
    };
    
    Book(string t, string a)
    {
        title = t;
        author = a;
    }
    
    void setTitle(string t)
    {
        title = t;
    };
    
    string getTitle()
    {
        return title;
    };
    
    void setAuthor(string a)
    {
        author = a;
    };
    
    string getAuthor()
    {
        return author;
    };
    
};

class User
{
    private:
        string name;
        int ratings[100];
        int numRatings;
        
    public:
        User()
        {
            name = "NONE";
            fill_n(ratings, 100, 0);
            numRatings = 0;
        };
        
        User(string n, int arr[], int numR)
        {
            name = n;
            for(int i=0; i<numR; i++)
            {
                ratings[i] = arr[i];
            }
            numRatings = numR;
        };
        
        void setName(string n)
        {
            name = n;
        };
        
        string getName()
        {
            return name;
        };
        
        void setNumRatings(int n)
        {
            numRatings = n;
        }
        
        int getNumRatings()
        {
            return numRatings;
        }
        
        int setRatingAt(int i, int rat)
        {
            if (i >= numRatings)
            {
                return -1000;
            }
            else
            {
                if(rat ==-5 or rat ==-3 or rat ==0 or rat ==1 or rat==3 or rat==5)
                {
                    ratings[i]=rat;
                    cout<<"Success!"<<endl;
                    return 0;
                }
                else
                {
                    cout<<"Invalid Input!"<<endl;
                    return -1;
                }
            }
        };
        
        int getRatingAt(int i)
        {
            if(i<numRatings and i>=0)
            {
                return ratings[i];
            }
            else
            {
                return -1000;
            }
        };
};

int main() 
{

}