#ifndef PLANET
#define PLANET

#include <string>

using namespace std;
//header for class file declaring private and public variables for planet
class planet {
    private:
        string name;
        float radius;
        
    public:
        planet();
        planet(string, float);
        
        void setName(string);
        string getName();
        
        void setRadius(float);
        float getRadius();
        
        ~planet();
};
#endif
