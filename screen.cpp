#include "screen.h"
#include <QDebug>
Screen::Screen(const QString &windowTitle)
{
    HWND window = FindWindowA(NULL, windowTitle.toStdString().c_str());
    this->dc = GetDC(window);
    RECT rect;
    GetWindowRect(window, &rect);

    this->width = rect.right - rect.left;
    this->height = rect.bottom - rect.top;
 this->hdcMem = CreateCompatibleDC (this->dc);

    this->screenData = new BYTE[4 * this->width * this->height];// (BYTE*)malloc(4 * this->width * this->height);

    this->hBitmap = CreateCompatibleBitmap(this->dc, this->width, this->height);


    qDebug()<<"width :"<<this->width;
    qDebug()<<"height: " << this->height;


}

Screen::~Screen(){
 //   delete this->screenData;
    DeleteDC(this->hdcMem);
    DeleteObject(this->hBitmap);
    DeleteDC(this->dc);
}

QImage Screen::screenshot(){



    this->hOld = SelectObject(this->hdcMem, this->hBitmap);
    BitBlt(this->hdcMem, 0, 0, this->width, this->height, this->dc, 0, 0, SRCCOPY);
    SelectObject(this->hdcMem, hOld);

    this->bmi.biSize = sizeof(BITMAPINFOHEADER);
    this->bmi.biPlanes = 1;
    this->bmi.biBitCount = 32;
    this->bmi.biWidth = this->width;
    this->bmi.biHeight = -this->height;
    this->bmi.biCompression = BI_RGB;
    this->bmi.biSizeImage = 0;// 3 * this->width * this->height;

   GetDIBits(this->hdcMem, this->hBitmap, 0, this->height, this->screenData, (BITMAPINFO*)&(this->bmi), DIB_RGB_COLORS);


   /*ReleaseDC(GetDesktopWindow(),dc);*/


   QImage imgRes(this->screenData, this->width, this->height, QImage::Format_RGB32);

  // free(screenData);
   return imgRes;
}
