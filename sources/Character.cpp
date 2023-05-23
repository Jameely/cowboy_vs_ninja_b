#include "Character.hpp"

using namespace std;
namespace ariel {
    Character::Character(string name, const Point& location) : Name(name), location(location) {}
    
    Character::~Character() {
    }
    void Character::setplay(){
        this->isplay=true;
    }
    bool Character::getplay(){
        return this->isplay;
    }
    double Character::distance(const Character& Other) const {
        const Point& a1 = this->getLocation();
        const Point& a2 = Other.getLocation();
        return a1.distance(a2);
    }
    double Character::distance(Character& Other) const{
        const Point& a1 = this->getLocation();
        const Point& a2 = Other.getLocation();
        return a1.distance(a2);
    }
    double Character::distance(Character* Other) const{
        const Point& a1 = this->getLocation();
        const Point& a2 = Other->getLocation();
        return a1.distance(a2);
    }

    bool Character::isAlive() const {
        return getHitPoint() > 0;
    }
    void Character:: hit(int Hit_p){
        if(Hit_p<0){
            throw invalid_argument("Invalid Argument");
        }
        this->Hit_point = this->Hit_point - Hit_p;
    }

    string Character::print() const{
        return this->getName() + "," + "Hit Points :" + to_string(this->getHitPoint()) + ", Location :" 
        +this->getLocation().Print();
    }

    const Point& Character::getLocation() const {
        return this->location;
    }

    string Character::getName() const {
        return Name;
    }
    int Character:: getHitPoint() const{
        return this->Hit_point;
    }
    void Character::setHitPoints(int num){
        this->Hit_point =num;
    }
    void Character::setLocation(Point &NewL){
        this->location=NewL;
    }
    
    std::ostream& operator<<(std::ostream& os, const Character& character) {
    os << character.print();
    return os;
}

}
