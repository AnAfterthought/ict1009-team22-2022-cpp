#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PlayableCharacter {
    private:
        string name;
        int maxHealth;
        int health;
        int damage;
        int defence;
        int speed;
        int initiative;
    public:
        PlayableCharacter();
        PlayableCharacter(string, int, int, int);
        string getName();
        int getMaxHealth();
        int getHealth();
        void setHealth(int);
        int getDamage();
        void setDamage(int);
        int getDefence();
        void setDefence(int);
        int getSpeed();
        void setSpeed(int);
        int getInitiative();
        void setInitiative(int);
        void attack(PlayableCharacter*);
        virtual void makeDecision(vector<PlayableCharacter*>&, vector<PlayableCharacter*>&);
};