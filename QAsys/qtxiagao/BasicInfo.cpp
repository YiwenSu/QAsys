#include "BasicInfo.h"

void BasicInfo::Writetime()
{
    time_t timer=time(NULL);
    struct tm *tblock;

    tblock = localtime(&timer);
    this->Time= asctime (tblock);

}
