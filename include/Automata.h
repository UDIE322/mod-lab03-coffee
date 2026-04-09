// Copyright 2020 GHA Test Team
#pragma once 
#include <string>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
private:
    int cash;
    std::string menu[3];
    int prices[3];
    int selected;
    STATES state;

public:
    Automata();

    void on();
    void off();
    void coin(int value);
    void getMenu();
    STATES getState();
    void choice(int index);
    bool check();
    void cook();
    void cancel();
    void finish();
};
