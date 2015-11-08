#include "imageconversion.h"

using namespace cimg_library;


void ImageConversion::convertImage(QString pathInput, QString pathOutput, QString filename, QString format)
{
    if(format == "JPEG")
    {
        this->toJpeg(pathInput, pathOutput, filename, format);
    }
    else
    if(format == "TIFF")
    {
        this->toTiff(pathInput, pathOutput, filename, format);
    }
    else
    if(format == "PNG")
    {
        this->toPng(pathInput, pathOutput, filename, format);
    }
}

void ImageConversion::toJpeg(QString pathInput, QString pathOutput, QString filename, QString format)
{
    FILE *fileInput, *fileOutput;
    QString output = pathOutput + "/" + filename + "." + format.toLower();
    //qDebug("output : %s", output.toStdString().c_str());

    fileInput = fopen(pathInput.toStdString().c_str(), "r");
    fileOutput = fopen(output.toStdString().c_str(), "w+");

    CImg<unsigned char> result;
    result.load_bmp(fileInput);
    result.save_jpeg(fileOutput, 100);
}

void ImageConversion::toTiff(QString pathInput, QString pathOutput, QString filename, QString format)
{
    FILE *fileInput;
    QString output = pathOutput + "/" + filename + "." + format.toLower();
    //qDebug("output : %s", output.toStdString().c_str());

    fileInput = fopen(pathInput.toStdString().c_str(), "r");

    CImg<unsigned char> result;
    result.load_bmp(fileInput);
    result.save_tiff(output.toStdString().c_str(), 0);
}

void ImageConversion::toPng(QString pathInput, QString pathOutput, QString filename, QString format)
{
    QImage image(pathInput);
    image.save(pathOutput + "/" + filename + "." + format.toLower(), format.toLower().toStdString().c_str(), -1);
}
