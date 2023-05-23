#pragma once
#include <string>
#include "math.h"
#include "Point.hpp"
#include <stdexcept>
#include "iostream"
using namespace std;
namespace ariel{

    class Point{

        private:
            double x_coo;
            double y_coo;
        
        public:
            Point(double x_coo,double y_coo);
            static Point moveTowards(Point &p1,Point &p2,double half_p);
            virtual double distance(const Point & Other) const;
            double getX() const;
            double getY() const;
            string Print() const;

    };

}
