#ifndef SCREEN_H
#define SCREEN_H
#include <windows.h>
#include <QImage>
class Screen
{
public:
    Screen(const QString &windowTitle);
    ~Screen();
    QImage screenshot();
private:
    HDC dc;
    int width;
    int height;
    BYTE* screenData;
    HDC hdcMem;
    HBITMAP hBitmap;
    HGDIOBJ hOld;
    BITMAPINFOHEADER bmi = {};
};

#endif // SCREEN_H
