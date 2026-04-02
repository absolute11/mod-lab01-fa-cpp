// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }
            if (str[i] >= '0' && str[i] <= '9')
                hasDigit = true;
        } else {
            if (inWord) {
                if (!hasDigit) count++;
                inWord = false;
            }
        }
    }
    if (inWord && !hasDigit) count++;
    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool valid = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (!inWord) {
                inWord = true;
                valid = (str[i] >= 'A' && str[i] <= 'Z');
            } else {
                if (valid && !(str[i] >= 'a' && str[i] <= 'z'))
                    valid = false;
            }
        } else {
            if (inWord) {
                if (valid) count++;
                inWord = false;
            }
        }
    }
    if (inWord && valid) count++;
    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int totalLen = 0;
    unsigned int wordCount = 0;
    bool inWord = false;
    unsigned int curLen = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (!inWord) {
                inWord = true;
                curLen = 0;
            }
            curLen++;
        } else {
            if (inWord) {
                totalLen += curLen;
                wordCount++;
                inWord = false;
            }
        }
    }
    if (inWord) {
        totalLen += curLen;
        wordCount++;
    }
    if (wordCount == 0) return 0;
    return (totalLen + wordCount / 2) / wordCount;
}
