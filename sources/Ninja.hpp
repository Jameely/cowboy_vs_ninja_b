#pragma once
#include "Character.hpp"
#include "math.h"
#include "iostream"
namespace ariel{
    class Ninja : public Character{
        private:
            int speed;
        public:
            Ninja();
            Ninja(string name, const Point & location);
            void move(Character * character);
            void slash(Character * character);
            int getspeed();
            void setSpeed(int spped);
            double distance(const Character* Other) const ;

            
    };
}