// Copyright 2020 GHA Test Team

#include <iostream>

#include "../include/Automata.h"

Automata::Automata() {
    cash = 0;
    state = OFF;
    selected = -1;

    menu[0] = "Tea";
    menu[1] = "Coffee";
    menu[2] = "Milk";

    prices[0] = 50;
    prices[1] = 70;
    prices[2] = 60;
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "Automata ON\n";
    }
}

void Automata::off() {
    cash = 0;
    selected = -1;
    state = OFF;
    std::cout << "Automata OFF\n";
}

void Automata::coin(int value) {
    if ((state == WAIT || state == ACCEPT) && value > 0) {
        cash += value;
        state = ACCEPT;
        std::cout << "Inserted: " << value << "\n";
    }
}

void Automata::getMenu() {
    std::cout << "Menu:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i << ": " << menu[i] << " - " << prices[i] << "\n";
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int index) {
    if (state == ACCEPT && index >= 0 && index < 3) {
        selected = index;
        state = CHECK;
        std::cout << "Selected: " << menu[index] << "\n";
    }
}

bool Automata::check() {
    if (state == CHECK) {
        if (cash >= prices[selected]) {
            return true;
        } else {
            std::cout << "Not enough money\n";
            return false;
        }
    }
    return false;
}

void Automata::cook() {
    if (state == CHECK && cash >= prices[selected]) {
        state = COOK;
        std::cout << "Cooking " << menu[selected] << "...\n";
    }
}

void Automata::finish() {
    if (state == COOK) {
        cash = 0;
        selected = -1;
        state = WAIT;
        std::cout << "Done!\n";
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        cash = 0;
        selected = -1;
        state = WAIT;
        std::cout << "Canceled\n";
    }
}
