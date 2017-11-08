#include "mytime.h"
#include <QTime>
#include <qcoreapplication.h>
void MyTime::sleep(int ms){
    QTime dieTime = QTime::currentTime().addMSecs( ms );
      while( QTime::currentTime() < dieTime )
      {
          QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
      }
}
