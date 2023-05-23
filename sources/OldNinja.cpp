#include "OldNinja.hpp"

namespace ariel{
    OldNinja::OldNinja(string name ,const Point& location):Ninja(name,location){
        this->setHitPoints(150);
        this->setSpeed(8);
    }
}