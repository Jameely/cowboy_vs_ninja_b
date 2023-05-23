#pragma once 
#include"Point.hpp"
#include"Cowboy.hpp"
#include"OldNinja.hpp"
#include"YoungNinja.hpp"
#include"TrainedNinja.hpp"
#include "Ninja.hpp"
#include <vector>
#include <limits> // Include the <limits> header for using a sentinel value

using namespace std;
namespace ariel {
    class Team{
        private:
        vector<Character*> Warriors;
        Character *Boss ;
        int num_w;
        public:
            Team(Character * character);
            ~Team();
            void add(Character* character);
            int stillAlive();
            void sortCowboysFirst(vector<Character*>& characters);
            void print();
            virtual void attack(Team* team);
            int getNumofworriors();
            Character* getBoss();
            void setBoss(Character *Boss);
            vector<Character*> &getWarriors();
            int getnumofworriors();

    };

}

