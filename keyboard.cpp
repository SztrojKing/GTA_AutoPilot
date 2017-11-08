#include "keyboard.h"


static const unsigned char ascii_to_scan_code_table[] = {
  /* ASCII:   0 */ 0,
  /* ASCII:   1 */ 0,
  /* ASCII:   2 */ 0,
  /* ASCII:   3 */ 0,
  /* ASCII:   4 */ 0,
  /* ASCII:   5 */ 0,
  /* ASCII:   6 */ 0,
  /* ASCII:   7 */ 0,
  /* ASCII:   8 */ 42,
  /* ASCII:   9 */ 43,
  /* ASCII:  10 */ 40,
  /* ASCII:  11 */ 0,
  /* ASCII:  12 */ 0,
  /* ASCII:  13 */ 28,
  /* ASCII:  14 */ 0,
  /* ASCII:  15 */ 0,
  /* ASCII:  16 */ 0,
  /* ASCII:  17 */ 0,
  /* ASCII:  18 */ 0,
  /* ASCII:  19 */ 0,
  /* ASCII:  20 */ 0,
  /* ASCII:  21 */ 0,
  /* ASCII:  22 */ 0,
  /* ASCII:  23 */ 0,
  /* ASCII:  24 */ 0,
  /* ASCII:  25 */ 0,
  /* ASCII:  26 */ 0,
  /* ASCII:  27 */ 41,
  /* ASCII:  28 */ 0,
  /* ASCII:  29 */ 0,
  /* ASCII:  30 */ 0,
  /* ASCII:  31 */ 0,
  /* ASCII:  32 */ 57,
  /* ASCII:  33 */ 158,
  /* ASCII:  34 */ 180,
  /* ASCII:  35 */ 160,
  /* ASCII:  36 */ 161,
  /* ASCII:  37 */ 162,
  /* ASCII:  38 */ 164,
  /* ASCII:  39 */ 52,
  /* ASCII:  40 */ 166,
  /* ASCII:  41 */ 167,
  /* ASCII:  42 */ 165,
  /* ASCII:  43 */ 174,
  /* ASCII:  44 */ 54,
  /* ASCII:  45 */ 45,
  /* ASCII:  46 */ 55,
  /* ASCII:  47 */ 56,
  /* ASCII:  48 */ 39,
  /* ASCII:  49 */ 30,
  /* ASCII:  50 */ 31,
  /* ASCII:  51 */ 32,
  /* ASCII:  52 */ 33,
  /* ASCII:  53 */ 34,
  /* ASCII:  54 */ 35,
  /* ASCII:  55 */ 36,
  /* ASCII:  56 */ 37,
  /* ASCII:  57 */ 38,
  /* ASCII:  58 */ 179,
  /* ASCII:  59 */ 51,
  /* ASCII:  60 */ 182,
  /* ASCII:  61 */ 46,
  /* ASCII:  62 */ 183,
  /* ASCII:  63 */ 184,
  /* ASCII:  64 */ 159,
  /* ASCII:  65 */ 132,
  /* ASCII:  66 */ 133,
  /* ASCII:  67 */ 134,
  /* ASCII:  68 */ 135,
  /* ASCII:  69 */ 136,
  /* ASCII:  70 */ 137,
  /* ASCII:  71 */ 138,
  /* ASCII:  72 */ 139,
  /* ASCII:  73 */ 140,
  /* ASCII:  74 */ 141,
  /* ASCII:  75 */ 142,
  /* ASCII:  76 */ 143,
  /* ASCII:  77 */ 144,
  /* ASCII:  78 */ 145,
  /* ASCII:  79 */ 146,
  /* ASCII:  80 */ 147,
  /* ASCII:  81 */ 148,
  /* ASCII:  82 */ 149,
  /* ASCII:  83 */ 150,
  /* ASCII:  84 */ 151,
  /* ASCII:  85 */ 152,
  /* ASCII:  86 */ 153,
  /* ASCII:  87 */ 154,
  /* ASCII:  88 */ 155,
  /* ASCII:  89 */ 156,
  /* ASCII:  90 */ 157,
  /* ASCII:  91 */ 47,
  /* ASCII:  92 */ 49,
  /* ASCII:  93 */ 48,
  /* ASCII:  94 */ 163,
  /* ASCII:  95 */ 173,
  /* ASCII:  96 */ 53,
  /* ASCII:  97 */ 16,
  /* ASCII:  98 */ 48,
  /* ASCII:  99 */ 46,
  /* ASCII: 100 */ 32,
  /* ASCII: 101 */ 18,
  /* ASCII: 102 */ 33,
  /* ASCII: 103 */ 34,
  /* ASCII: 104 */ 35,
  /* ASCII: 105 */ 23,
  /* ASCII: 106 */ 36,
  /* ASCII: 107 */ 37,
  /* ASCII: 108 */ 38,
  /* ASCII: 109 */ 39,
  /* ASCII: 110 */ 49,
  /* ASCII: 111 */ 24,
  /* ASCII: 112 */ 25,
  /* ASCII: 113 */ 30,
  /* ASCII: 114 */ 19,
  /* ASCII: 115 */ 31,
  /* ASCII: 116 */ 20,
  /* ASCII: 117 */ 22,
  /* ASCII: 118 */ 47,
  /* ASCII: 119 */ 44,
  /* ASCII: 120 */ 45,
  /* ASCII: 121 */ 21,
  /* ASCII: 122 */ 17,
  /* ASCII: 123 */ 175,
  /* ASCII: 124 */ 177,
  /* ASCII: 125 */ 176,
  /* ASCII: 126 */ 181
};

void Keyboard::press(WORD key){
    // This structure will be used to create the keyboard
   // input event.
   INPUT ip;


   // Set up a generic keyboard event.
   ip.type = INPUT_KEYBOARD;
   ip.ki.wScan = key; // hardware scan code for key
   ip.ki.time = 0;
   ip.ki.dwExtraInfo = 0;

   // Press the key
   ip.ki.wVk = 0/*key*/; // virtual-key code for the "a" key

   ip.ki.dwFlags = KEYEVENTF_SCANCODE; // 0 for key press
   SendInput(1, &ip, sizeof(INPUT));
   MyTime::sleep(100);
   // Release the key
   ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
   SendInput(1, &ip, sizeof(INPUT));
}

void Keyboard::write(const QString &str){

    for(int i=0;i<str.length();i++){
        Keyboard::press((char)ascii_to_scan_code_table[str.at(i).toLatin1()]);
        MyTime::sleep(100);
    }
}
