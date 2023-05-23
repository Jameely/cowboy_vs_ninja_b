#pragma once
#include "Point.hpp"
#include "iostream"
#include <string>
using namespace std;
namespace ariel {
    class Character {
    private:
        string Name;
        Point location;
        int Hit_point;
        bool isplay = false;
    public:
        Character(string name, const Point& location);
        virtual ~Character();

        // Disable the copy and move operations
/*        Character(const Character&) = delete;
        Character& operator=(const Character&) = delete;
        Character(Character&&) = delete;
        Character& operator=(Character&&) = delete;
*/
        double distance(const Character& Other)const;
        double distance(Character& Other) const;
        double distance(Character* Other) const;
        bool isAlive() const;
        void hit(int Hit_p);
        virtual string print() const;
        const Point& getLocation() const;
        string getName() const;
        int getHitPoint() const;
        void setHitPoints(int num);
        void setLocation(Point &NewL);
        friend std::ostream& operator<<(std::ostream& os, const Character& character);  
        void setplay();
        bool getplay();

        };
}
