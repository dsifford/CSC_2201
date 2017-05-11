
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Text.h"

Text::Text ( const char *charSeq ) {
    bufferSize = strlen(charSeq) + 1;
    buffer = new char[bufferSize];
    strcpy(buffer, charSeq);
}

Text::Text ( const Text &other ) : bufferSize(other.bufferSize) {
    buffer = new char[bufferSize];
    strcpy(buffer, other.buffer);
}

void Text::operator = ( const Text &other ) {
    if (other.bufferSize > bufferSize) {
        delete [] buffer;
        buffer = new char[other.bufferSize];
    }
    bufferSize = other.bufferSize;
    strcpy(buffer, other.buffer);
}

Text::~Text () {
    delete [] buffer;
}

int Text::getLength () const {
    return bufferSize - 1;
}

char Text::operator [] ( int n ) const {
    if (n > bufferSize - 1 || n < 0) {
        throw std::range_error("Out of range");
    }
    return buffer[n];
}

void Text::clear () {
    buffer[0] = '\0';
}

void Text:: showStructure () const {
// Outputs the characters in a string. This operation is intended for// testing/debugging purposes only.
    int j;   // Loop counter
    for ( j = 0; j < bufferSize; j++ )
        cout << j << "\t";
    cout << endl;
    for ( j = 0; buffer[j] != '\0'; j++ )
        cout << buffer[j] << "\t";
    cout << "\\0" << endl;
}

Text Text::toUpper( ) const {
    Text temp;
    return temp;
}

Text Text::toLower( ) const {
    Text temp;
    return temp;
}

bool Text::operator == ( const Text &other ) const {
    return false;
}

bool Text::operator <  ( const Text &other ) const {
    return false;
}

bool Text::operator >  ( const Text &other ) const {
    return false;
}
