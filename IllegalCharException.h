#pragma once
class IllegalCharException{
public:
    char c;
    IllegalCharException(char);
    char theChar() const;
};