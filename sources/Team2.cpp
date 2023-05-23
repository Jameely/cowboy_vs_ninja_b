#include "Team2.hpp"

using namespace std;
namespace ariel {
Team2::Team2(Character* character) : Team(character) {}

 void Team2::attack(Team* enemyTeam) {
   
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

    if (!this->getBoss()->isAlive()) {
        // Find the closest alive teammate and appoint them as the new captain
        double minTeammateDistance = std::numeric_limits<double>::max();
        Character* closestTeammate = nullptr;
        for (Character* teammate : getWarriors()) {
            if (teammate != getBoss() && teammate->isAlive()) {
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
            if (enemy->isAlive()) {
                double distance = this->getBoss()->distance(enemy);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestEnemy = enemy;
                }
            } 
        }
    }

    // If there are no alive enemies or no alive members in the attacking team, the attack ends
    if (closestEnemy == nullptr) {
        return;
    }

    // Attack the closest alive enemy
    for (Character* attacker : getWarriors()) {
       
        if (attacker->isAlive() && closestEnemy->isAlive()) {
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker)) {
                if (cowboy->hasboolets()) {
                    // Shoot the enemy
                    cowboy->shoot(closestEnemy);
                } else if (!cowboy->hasboolets()) {
                    // Reload weapon
                    cowboy->reload();
                }
            }
            if (Ninja* ninja = dynamic_cast<Ninja*>(attacker)) {
                if (ninja->distance(closestEnemy) < 1 && closestEnemy->isAlive()) {
                    ninja->slash(closestEnemy);
                } else {
                    ninja->move(closestEnemy);
                }
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



            
};
