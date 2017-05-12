// Author: Derek P Sifford
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Text.h"

Text::Text(const char *charSeq) {
    bufferSize = strlen(charSeq) + 1;
    buffer = new char[bufferSize];
    strcpy(buffer, charSeq);
}

Text::Text(const Text &other): bufferSize(other.bufferSize) {
    buffer = new char[bufferSize];
    strcpy(buffer, other.buffer);
}

void Text::operator=(const Text &other) {
    if (other.bufferSize > bufferSize) {
        delete [] buffer;
        buffer = new char[other.bufferSize];
    }
    bufferSize = other.bufferSize;
    strcpy(buffer, other.buffer);
}

Text::~Text() {
    delete [] buffer;
}

int Text::getLength() const {
    return bufferSize - 1;
}

char Text::operator[](int n) const {
    if (n > bufferSize - 1 || n < 0) {
        throw std::range_error("Out of range");
    }
    return buffer[n];
}

void Text::clear() {
    buffer[0] = '\0';
}

void Text::showStructure() const {
    // Outputs the characters in a string. This operation is intended for
    // testing/debugging purposes only.
    int j;
    for ( j = 0; j < bufferSize; j++ ) {
        cout << j << "\t";
    }
    cout << endl;
    for ( j = 0; buffer[j] != '\0'; j++ ) {
        cout << buffer[j] << "\t";
    }
    cout << "\\0" << endl;
}

Text Text::toUpper() const {
    char *temp = new char[bufferSize];
    strcpy(temp, buffer);

    for (int i = 0; i < bufferSize; i++) {
        temp[i] = std::toupper(temp[i]);
    }

    Text upper(temp);
    return upper;
}

Text Text::toLower() const {
    char *temp = new char[bufferSize];
    strcpy(temp, buffer);

    for (int i = 0; i < bufferSize; i++) {
        temp[i] = std::tolower(temp[i]);
    }

    Text lower(temp);
    return lower;
}

bool Text::operator==(const Text &other) const {
    for (int i = 0; i < bufferSize; i++) {
        if (strcmp(&buffer[i], &other.buffer[i]) != 0) {
            return false;
        }
    }
    return true;
}

bool Text::operator<(const Text &other) const {
    for (int i = 0; i < bufferSize; i++) {
        if (strcmp(&buffer[i], &other.buffer[i]) > -1) {
            return false;
        }
    }
    return true;
}

bool Text::operator>(const Text &other) const {
    for (int i = 0; i < other.bufferSize; i++) {
        if (strcmp(&other.buffer[i], &buffer[i]) > -1) {
            return false;
        }
    }
    return true;
}
