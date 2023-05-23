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
    Point Point::moveTowards( const Point& source,   const Point& destination, double distance) {

        if(distance < 0){
            std::__throw_invalid_argument("distance can not be negative ");
        }
        double currentDistance =source.distance(destination);

        if (currentDistance <= distance) {
            // The destination point is already within or at the given distance
            return destination;
        }
        double ratio = distance / currentDistance;
        double newX = source.getX() + (destination.getX() - source.getX()) * ratio;
        double newY = source.getY() + (destination.getY() - source.getY()) * ratio;
        return Point(newX, newY);
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
