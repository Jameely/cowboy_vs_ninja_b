#pragma once
#include "Ninja.hpp"

namespace ariel {
    class YoungNinja : public Ninja {
    public:
        YoungNinja(std::string name, const Point& location);
        //virtual ~YoungNinja(); // Public and virtual destructor
    };
}
