#include"Team.hpp"
#include <algorithm>
using namespace std;
namespace ariel{
        Team::Team(Character* character) : Boss(character) {
            num_w = 0;
            bool isinteam =0;
            for (const Character* warrior : getWarriors()) {
                if(&character == &warrior){
                    isinteam =1;
                }
            }
            if (character->getplay() && !isinteam) {
                throw runtime_error("The player you try to put as a boss is already in a game with another team");
            }
            else{
            add(character);
            }
        }


        Team::~Team() {
            // Delete all the dynamically allocated Character objects in the Warriors vector
            for (Character* warrior : Warriors) {
                delete warrior;
            }
            
            // Clear the vector to release the memory
            Warriors.clear();

        }

    void Team::sortCowboysFirst(vector<Character*>& characters) {
        sort(characters.begin(), characters.end(), [](Character* character1, Character* character2) {
            Cowboy* cowboy1 = dynamic_cast<Cowboy*>(character1);
            Cowboy* cowboy2 = dynamic_cast<Cowboy*>(character2);
            Ninja* ninja1 = dynamic_cast<Ninja*>(character1);
            Ninja* ninja2 = dynamic_cast<Ninja*>(character2);

            // Sort Cowboys before Ninjas
            if (cowboy1 && !cowboy2) {
                return true;
            } else if (!cowboy1 && cowboy2) {
                return false;
            } else {
                return false;
            }
        });
    }
        int Team::getNumofworriors(){
            return this->num_w;
        }
        void Team::add(Character* character) {
            if (character == nullptr) {
                throw std::runtime_error("NULL POINTER");
            }            
            
            if (getNumofworriors() == 10) {
                throw runtime_error("Maximum number of warriors reached");
            }
            else if(character->getplay()) {
                throw runtime_error("The player You try to add is already in a game");
            }
            
            this->Warriors.push_back(character);
            num_w += 1;
            character->setplay();
            sortCowboysFirst(Warriors);

        }


        void Team::print() {
            for (const Character* warrior : getWarriors()) {
                cout << "Warrior name: " << warrior->getName()
                    << ", Location: " << warrior->getLocation().Print()
                    << ", Hit Point: " << warrior->getHitPoint() << endl;
            }
        }

        vector<Character*> &Team::getWarriors() {
            return Warriors;
        }


        int Team::stillAlive() {
            int size = 0;
            for (const Character* warrior : getWarriors()) {
                if (warrior->isAlive()) {
                    size++;
                }
            }
            return size;
        }



void Team::attack(Team* enemyTeam) {
    if (enemyTeam == nullptr) {
        throw std::invalid_argument("Null pointer to enemy team");
    }
    if (this == enemyTeam) {
        throw std::runtime_error("Cannot attack yourself");
    }
    if (stillAlive() == 0) {
        throw std::runtime_error("The team is dead.");
    }
    if (enemyTeam->stillAlive() == 0) {
        throw std::runtime_error("The enemy team is dead.");
    }
    
    Character* closestEnemy = nullptr;
    Character* closestTeammate = nullptr;


    if (!this->getBoss()->isAlive()) {
        // Find the closest alive teammate and appoint them as the new captain
        double minTeammateDistance = std::numeric_limits<double>::max();
        closestTeammate = nullptr;
        for (Character* teammate : getWarriors()) {
            if (teammate->isAlive()) {
                double distance = getBoss()->distance(teammate);
                if (distance < minTeammateDistance) {
                    minTeammateDistance = distance;
                    closestTeammate = teammate;
                }
            }
        }
        if (closestTeammate != nullptr) {
            setBoss(closestTeammate);
        } 
    }


    if (closestEnemy == nullptr || !closestEnemy->isAlive()) {
        // Find the closest alive enemy to the attacking captain
        double minDistance = std::numeric_limits<double>::max();
        for (Character* enemy : enemyTeam->getWarriors()) {
            if (enemy->isAlive() && enemy!=nullptr ) {
                double distance = (this->getBoss())->distance(enemy);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestEnemy = enemy;
                }
            } 
        }
    }


    // Attack the closest alive enemy
    for (Character* attacker : getWarriors()) { 
        // If there are no alive enemies or no alive members in the attacking team, the attack ends
        if (closestEnemy == nullptr) {
            return;
        }

        if (attacker->isAlive() && closestEnemy->isAlive() && attacker!=nullptr && closestEnemy != nullptr) {
            // if the temmate is cowboy :
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker)) {
                if (cowboy->hasboolets()) {
                    // Shoot the enemy
                    cowboy->shoot(closestEnemy);

                        if (!enemyTeam->getBoss()->isAlive()) {
                            // Find the closest alive teammate and appoint them as the new captain
                            double minTeammateDistance = std::numeric_limits<double>::max();
                            Character* closestTeammate = nullptr;
                            for (Character* teammate : enemyTeam->getWarriors()) {
                                if (teammate->isAlive()) {
                                    double distance = enemyTeam->getBoss()->distance(teammate);
                                    if (distance < minTeammateDistance) {
                                        minTeammateDistance = distance;
                                        closestTeammate = teammate;
                }
            }
        }
                        }
        if (closestTeammate != nullptr) {
            enemyTeam->setBoss(closestTeammate);
        }   
                } else if (!cowboy->hasboolets()) {
                    // Reload weapon
                    cowboy->reload();
                }
            }
            else if (Ninja* ninja = dynamic_cast<Ninja*>(attacker)) {
                if (ninja->distance(closestEnemy) < 1 && closestEnemy->isAlive()) {
                    ninja->slash(closestEnemy);
                }
                else {
                    ninja->move(closestEnemy);
                }
            }

        if (closestEnemy != nullptr && !enemyTeam->getBoss()->isAlive()) {
            Character* closest = nullptr;
            double minDistance = std::numeric_limits<double>::max();
            for (Character* enemy : enemyTeam->getWarriors()) {
                if (closestEnemy != enemy && enemy->isAlive()) {
                    double distance = closestEnemy->distance(enemy);
                    if (distance < minDistance) {
                        minDistance = distance;
                        closest = enemy;
                        enemyTeam->setBoss(closest);
                    }
                }
            }
            if(enemyTeam->stillAlive()==0){
                return ;
            }
        }

        if (!this->getBoss()->isAlive()) {
            Character* closest = nullptr;
            double minDistance = std::numeric_limits<double>::max();
            for (Character* member : getWarriors()) {
                if (member != getBoss()) {
                    double distance = getBoss()->distance(member);
                    if (distance < minDistance) {
                        minDistance = distance;
                        closest = member;
                        this->setBoss(closest);
                        
                    }
                }
            }
            if(stillAlive()==0){
                return ;
            }
        }
            if (closestEnemy == nullptr || !closestEnemy->isAlive()) {
            // Find the closest alive enemy to the attacking captain
            double minDistance = std::numeric_limits<double>::max();
            for (Character* enemy : enemyTeam->getWarriors()) {
                if (enemy->isAlive()) {
                    double distance = this->getBoss()->distance(enemy);
                    if (distance < minDistance) {
                        minDistance = distance;
                        closestEnemy = enemy;
                    }
                } 
            }
            }
    }
    }
}

        
        Character* Team::getBoss() {
            return Boss;
        }
        
        
        void Team::setBoss(Character *Boss){
            this->Boss = Boss;        
            }
}
