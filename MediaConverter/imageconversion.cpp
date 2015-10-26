#include "imageconversion.h"

void ImageConversion::convertImage(QString pathInput, QString pathOutput, QString filename, QString format)
{
    QImage image(pathInput);
    image.save(pathOutput + "/" + filename + "." + format.toLower(), format.toLower().toStdString().c_str(), -1);
}
