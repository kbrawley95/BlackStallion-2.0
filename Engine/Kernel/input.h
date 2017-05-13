#ifndef _INPUT_H
#define _INPUT_H

class Input
{
    public:

    private:
        void updateValues();
        static map<int, bool> keyboardKeys;
}

map<int, bool> keyboardKeys;

#include "input.cpp"

#endif