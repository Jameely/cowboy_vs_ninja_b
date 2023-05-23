#include "math.h"
#include "Point.hpp"
#include <stdexcept>
#include "iostream"
#include <string>
using namespace std;
namespace ariel
{
    Point::Point(double x_coo,double y_coo):x_coo(x_coo),y_coo(y_coo){} //parametric constructor 
/**
 *  function that returns the closest point to the target point, within a given distance, based on a source point and a destination point,
*/
    Point Point:: moveTowards(Point &source,Point &destination,double distance){ 
        if (distance < 0) {
            throw std::invalid_argument("Invalid distance: negative value");
        }

     // Get the current character's location
     Point currentLocation = source;

     // Get the enemy's location
     Point enemyLocation = destination;

     // Calculate the direction vector towards the enemy
     double dx = enemyLocation.getX() - currentLocation.getX();
     double dy = enemyLocation.getY() - currentLocation.getY();

     // Calculate the magnitude of the direction vector
     double magnitude = std::sqrt(dx * dx + dy * dy);

     // Normalize the direction vector
     double normalizedDx = dx / magnitude;
     double normalizedDy = dy / magnitude;

     // Calculate the distance to move based on the speed
     double distanceToMove = distance;

     // Calculate the new position by moving towards the enemy
     double newX = currentLocation.getX() + normalizedDx * distanceToMove;
     double newY = currentLocation.getY() + normalizedDy * distanceToMove;

     // Update the character's location with the new position
     Point p(newX,newY);
     return p;
    }
/**
 * Distance between two points
*/
    double Point::distance(const Point & Other) const{ 
        double dx = this->getX() - Other.getX();
        double dy = this->getY() -Other.getY();
        try
        {
        return std::sqrt(dx * dx + dy * dy);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return 0;
    }

    double Point::getX() const{ //getter
        return this->x_coo;;
    }

    double Point::getY() const{ //getter
        return this->y_coo;
    }
    string Point:: Print() const{
        return "(" + to_string(this->getX()) + "," + to_string(this->getY()) + ")";
    }

}
