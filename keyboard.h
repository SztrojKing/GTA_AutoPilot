#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <qstring.h>
#include <windows.h>
#include "mytime.h"

class Keyboard
{
public:

    static void press(WORD key);
    static void write(const QString &str);
private:
     Keyboard();
};

#endif // KEYBOARD_H
