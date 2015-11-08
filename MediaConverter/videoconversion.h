#ifndef VIDEOCONVERSION_H
#define VIDEOCONVERSION_H

#include <QString>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/mathematics.h>
#include <QProcess>

class VideoConversion
{
    public :
        void convertVideo(QString, QString, QString, QString);

    private :
        void toMp4(QString, QString, QString, QString);
        void to3gp(QString, QString, QString, QString);
        void toM4v(QString, QString, QString, QString);
};

#endif // VIDEOCONVERSION_H
