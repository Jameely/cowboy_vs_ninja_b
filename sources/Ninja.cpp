#include "Ninja.hpp"
using namespace std;
namespace ariel{
     Ninja::Ninja(string name, const Point & location):Character(name,location){
          
     }
          void Ninja::slash(Character * character){
          if(!character->isAlive()){
               throw runtime_error("Can't Heat a dead character!");
          }
          if(!this->isAlive()){
               throw runtime_error("Dead Character can't heat!");
          }
          if(character==this){
               throw runtime_error("Can't slash your self!");
          }
     // Get the current character's location
     Point currentLocation = this->getLocation();
     // Get the enemy's location
     Point enemyLocation = character->getLocation();

     double Dist = currentLocation.distance(enemyLocation);
     if(character->isAlive() && Dist <1){
               character->hit(40);
          }       
     }
     Ninja::Ninja():Character("name",Point(0,0)),speed(0){}
     int Ninja:: getspeed(){
          return this->speed;
     }

    void Ninja::move(Character* enemy){
        Point newLocation = Point::moveTowards(getLocation(),enemy->getLocation(),speed);
        this->setLocation(newLocation);
       
    }

double Ninja::distance(const Character* Other) const {
    const Point& a1 = this->getLocation();
    const Point& a2 = Other->getLocation();
    return a1.distance(a2);
}
   
     void Ninja ::setSpeed(int speed){
          this->speed =speed;
     }
}