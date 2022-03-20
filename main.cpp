#include <iostream>
#include <algorithm>
#include "PlayableCharacter.h"
#include "Knight.h"

void display(vector<PlayableCharacter*> party, vector<PlayableCharacter*> enemyParty) {
    system("cls");
    for (PlayableCharacter* pc : party) {
        cout << pc->getName() << " ";
        cout << pc->getHealth() << endl;
    }
    for (PlayableCharacter* pc : enemyParty) {
        cout << pc->getName() << " ";
        cout << pc->getHealth() << endl;
    }
}

int main() {
    vector<PlayableCharacter*> party;
    vector<PlayableCharacter*> enemyParty;
    PlayableCharacter* player = new Knight("Hello", 100, 10, 6);
    PlayableCharacter* enemy = new PlayableCharacter("Animal", 50, 8, 5);

    party.push_back(player);
    enemyParty.push_back(enemy);

    while (party.size() != 0 && enemyParty.size() != 0) {
        for (PlayableCharacter* pc : party) {
            pc->setInitiative(pc->getSpeed());
            if (pc->getInitiative() == 100) {
                display(party, enemyParty);
                pc->setInitiative(-1);
                pc->makeDecision(party, enemyParty);
            }
        }
        for (PlayableCharacter* pc : enemyParty) {
            pc->setInitiative(pc->getSpeed());
            if (pc->getInitiative() == 100) {
                pc->setInitiative(-1);
                pc->makeDecision(enemyParty, party);
            }
        }
    }

    cout << player->getHealth() << endl;

    return 0;
}