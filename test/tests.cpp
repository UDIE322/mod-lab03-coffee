// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "../include/Automata.h"

TEST(AutomataTest, InitialStateIsOff) {
    Automata a;
    EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, OnChangesStateToWait) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, OffFromWaitChangesStateToOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, CoinFromWaitChangesStateToAccept) {
    Automata a;
    a.on();
    a.coin(50);
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(AutomataTest, MultipleCoinsKeepStateAccept) {
    Automata a;
    a.on();
    a.coin(50);
    a.coin(20);
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(AutomataTest, ChoiceAfterCoinChangesStateToCheck) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);   // Tea
    EXPECT_EQ(a.getState(), CHECK);
}

TEST(AutomataTest, CheckReturnsFalseIfNotEnoughMoneyForCoffee) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);   // Coffee
    EXPECT_FALSE(a.check());
}

TEST(AutomataTest, CheckReturnsTrueIfEnoughMoneyForCoffee) {
    Automata a;
    a.on();
    a.coin(50);
    a.coin(20);
    a.choice(1);   // Coffee
    EXPECT_TRUE(a.check());
}

TEST(AutomataTest, SuccessfulCookChangesStateToCook) {
    Automata a;
    a.on();
    a.coin(50);
    a.coin(20);
    a.choice(1);   // Coffee
    ASSERT_TRUE(a.check());
    a.cook();
    EXPECT_EQ(a.getState(), COOK);
}

TEST(AutomataTest, FinishAfterCookChangesStateToWait) {
    Automata a;
    a.on();
    a.coin(50);
    a.coin(20);
    a.choice(2);   // Milk
    ASSERT_TRUE(a.check());
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, CancelFromAcceptChangesStateToWait) {
    Automata a;
    a.on();
    a.coin(50);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, CancelFromCheckChangesStateToWait) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);   // Tea
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, ChoiceWithoutCoinDoesNothing) {
    Automata a;
    a.on();
    a.choice(0);
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, CookWithoutCheckDoesNothing) {
    Automata a;
    a.on();
    a.coin(50);
    a.cook();
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(AutomataTest, FinishWithoutCookDoesNothing) {
    Automata a;
    a.on();
    a.finish();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, CoinWhenOffDoesNothing) {
    Automata a;
    a.coin(50);
    EXPECT_EQ(a.getState(), OFF);
}
