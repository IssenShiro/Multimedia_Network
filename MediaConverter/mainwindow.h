#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setPathInput(QString);
    void setPathOutput(QString);
    void setFilename(QString);
    void setConversionType(QString);
    void setConversionMethod(QString);
    void setBitRate(QString);
    void setFrameRate(QString);
    void setCompressionRatio(QString);

    QString getPathInput();
    QString getPathOutput();
    QString getFilename();
    QString getConversionType();
    QString getConversionMethod();
    QString getBitRate();
    QString getFrameRate();
    QString getCompressionRatio();

    //QString getPathInput();
    //QString getPathOutput();
    //QString getConversionType();
    //QString getconversionMethod();

signals:
    void doneConversion();

public slots:
    void connect_slots();

private slots:
    void goToVideoConv();
    void goToImageConv();
    void goToAudioConv();
    void goToAbout();
    void goToOutput();
    void goToLoadingPage();
    void goToResultPage();
    void startConversion();
    void chooseInputPath();
    void chooseOutputPath();
    void clearInputPath();
    void clearOutputPath();
    void nameChanged(QString);
    //void goToVideoOpt();
    //void goToImageOpt();
    //void goToAudioOpt();
    void backToHome();
    void backToInput();
    void clearVars();
    void clearUi();

    void addRadioGroup();
    void onGroupButtonPressed(int);

private:
    Ui::MainWindow *ui;
    QString pathInput;
    QString pathOutput;
    QString filename;
    QString conversionType;
    QString conversionMethod;
    QString bitRate;
    QString framerate;
    QString compressionRatio;

};

#endif // MAINWINDOW_H
