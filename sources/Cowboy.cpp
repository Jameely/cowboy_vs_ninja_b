#include "Cowboy.hpp"

namespace ariel{
    
     Cowboy::Cowboy(string name ,const Point&location):Character(name,location),stockpile(6){
            this->setHitPoints(110);
     }
     Cowboy::Cowboy():Character("name",Point(0,0)),stockpile(0){

     }
            void Cowboy::shoot(Character * enemy){
                if(!enemy->isAlive()){
                    throw runtime_error("Can't Heat a dead character!");
                }
                if(!this->isAlive()){
                    throw runtime_error("Dead character can't heat!");
                }
                if(this == enemy){
               throw runtime_error("Can't Shoot your self!");
                }         

                if(this->isAlive() && this->hasboolets()){
                    enemy->hit(10);
                    this->stockpile--;
                }
                else{
                    this->reload();
                }
            }
            bool Cowboy::hasboolets(){
                return this->getStockpile()>0;
            }
            int Cowboy::getStockpile(){
                return this->stockpile;
            }
            void Cowboy::reload(){
                if(!this->isAlive()){
                    throw runtime_error("CowBoy is Dead can't reload");
                }
                this->stockpile = 6;
            }

}