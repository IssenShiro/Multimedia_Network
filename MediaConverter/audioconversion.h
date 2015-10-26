#ifndef AUDIOCONVERSION_H
#define AUDIOCONVERSION_H

#include <QString>
#include <QImage>
#include <stdio.h>
#include <lame/lame.h>

class AudioConversion
{
    public :
        void convertAudio(QString, QString, QString, QString);

    private :
        void toMp3(QString, QString);
};

#endif // AUDIOCONVERSION_H
