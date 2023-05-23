#pragma once 
#include"Point.hpp"
#include"Cowboy.hpp"
#include"OldNinja.hpp"
#include"YoungNinja.hpp"
#include"TrainedNinja.hpp"
#include "Ninja.hpp"
#include <vector>
#include "Team.hpp"
using namespace std;
namespace ariel {
    class Team2 :public Team{
        public:
            Team2(Character *character);
            void attack(Team* team);

    };

}

