#ifndef IMAGECONVERSION_H
#define IMAGECONVERSION_H

#include <QString>
#include <QImage>
#define cimg_use_jpeg
#define cimg_use_tiff
#define cimg_use_png
#include <CImg.h>

class ImageConversion
{
    public :
        void convertImage(QString, QString, QString, QString);

    private :
        void toJpeg(QString, QString, QString, QString);
        void toTiff(QString, QString, QString, QString);
        void toPng(QString, QString, QString, QString);
};


#endif // IMAGECONVERSION_H
