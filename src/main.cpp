// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char* str1 = "apple 123abc banana 456 cherry";
    std::cout << "Слова без цифр: " << faStr1(str1) << std::endl;

    const char* str2 = "Hello world Nice Day bad";
    std::cout << "Слова с заглавной: " << faStr2(str2) << std::endl;

    const char* str3 = "the quick brown car";
    std::cout << "Средняя длина слова: " << faStr3(str3) << std::endl;

    return 0;
}
