// Copyright 2020 GHA Test Team

#include <clocale>
#include <iostream>

#include "../include/Automata.h"

int main() {
    Automata a;
    setlocale(LC_ALL, "Russian");
    a.on();
    a.getMenu();

    std::cout << "\nnot enought\n";
    a.coin(50);
    a.choice(1);  // Coffee = 70

    if (a.check()) {
        a.cook();
        a.finish();
    } else {
        a.cancel();
    }

    std::cout << "\n---scs---\n";
    a.coin(50);
    a.coin(20);
    a.choice(2);

    if (a.check()) {
        a.cook();
        a.finish();
    } else {
        a.cancel();
    }

    std::cout << "\n---decline---\n";
    a.coin(60);
    a.cancel();

    std::cout << "\n---off---\n";
    a.off();

    return 0;
}
