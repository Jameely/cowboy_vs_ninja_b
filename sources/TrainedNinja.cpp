
#include"TrainedNinja.hpp"
namespace ariel{
   
    TrainedNinja::TrainedNinja(string name , const Point & location ):Ninja(name,location){
        this->setHitPoints(120);
        this->setSpeed(12);
    }
    
}
