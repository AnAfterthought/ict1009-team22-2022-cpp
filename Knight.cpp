#include "Knight.h"

Knight::Knight() {
}

Knight::Knight(string name, int maxHealth, int damage, int speed) : PlayableCharacter(name, maxHealth, damage, speed){
}

void Knight::ability_one(vector<PlayableCharacter*> &characters, int index) {
    characters[index]->setHealth(characters[index]->getHealth() + 20);
}

void Knight::makeDecision(vector<PlayableCharacter*>& ownParty, vector<PlayableCharacter*>& enemyParty) {
    int choice = 0;

    while (choice < 1 || choice > 2) {
        int target;
        cout << "Choose" << endl << "1. Attack" << endl << "2. Use item" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "Choose target. 0 to go back" << endl;
            cin >> target;
            if (target == 0) {
                choice = 0;
            } else {
                this->attack(enemyParty[target - 1]);
                if(enemyParty[target - 1]->getHealth() <= 0) {
                    enemyParty.erase(enemyParty.begin() + target - 1);
                }
            }
        } else if (choice == 2) {
            
        }
    }
}