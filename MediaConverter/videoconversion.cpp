#include "videoconversion.h"

using namespace std;

void VideoConversion::convertVideo(QString pathInput, QString pathOutput, QString filename, QString format)
{
    if(format == "MP4")
    {
        this->toMp4(pathInput, pathOutput + "/" + filename + "." + format, filename, format);
    }
    else
    if(format == "3GP")
    {
        this->to3gp(pathInput, pathOutput + "/" + filename + "." + format, filename, format);
    }
}

void VideoConversion::toMp4(QString pathInput, QString pathOutput, QString filename, QString format)
{
    QProcess _FFMPEG;
    QString _process = "/usr/local/bin/ffmpeg";
    QStringList _paramList;
    _paramList  << "-i"
                << pathInput
                << "-acodec"
                <<  "libfaac"
                <<  "-b:a"      //audio bitrate
                <<  "128k"
                <<  "-vcodec"
                <<  "mpeg4"
                <<  "-b:v"      //video frame rate
                <<  "1200k"
                <<  "-flags"
                <<  "+aic+mv4"
                <<  pathOutput;

    _FFMPEG.start(_process,_paramList);

    _FFMPEG.waitForFinished();
}

void VideoConversion::to3gp(QString pathInput, QString pathOutput, QString filename, QString format)
{
    QProcess _FFMPEG;
    QString _process = "/usr/local/bin/ffmpeg";
    QStringList _paramList;
    _paramList  << "-i"
                << pathInput
                <<  "-s"
                <<  "qcif"
                <<  "-vcodec"
                <<  "h263"
                << "-acodec"
                <<  "libfaac"
                <<  "-ac"
                <<  "1"
                <<  "-ar"
                <<  "8000"
                <<  "-r"
                <<  "25"
                <<  "-ab"
                <<  "32"
                <<  "-y"
                <<  pathOutput;

    _FFMPEG.start(_process,_paramList);

    _FFMPEG.waitForFinished();
}

void VideoConversion::toM4v(QString pathInput, QString pathOutput, QString filename, QString format)
{
    QProcess _FFMPEG;
    QString _process = "/usr/local/bin/ffmpeg";
    QStringList _paramList;
    _paramList  << "-i"
                << pathInput
                <<  "-vcodec"
                <<  "libx264"
                << "-acodec"
                <<  "libfaac"
                <<  "-ar"
                <<  "8000"
                <<  "-r"
                <<  "25"
                <<  "-ab"
                <<  "32"
                <<  "-y"
                <<  pathOutput;

    _FFMPEG.start(_process,_paramList);

    _FFMPEG.waitForFinished();
}


