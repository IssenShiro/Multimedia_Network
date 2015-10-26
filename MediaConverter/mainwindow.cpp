#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "audioconversion.h"
#include "imageconversion.h"
#include "videoconversion.h"

QString VideoList[6] = {"MP4", "3GP", "MKV"};
QString ImageList[6] = {"JPEG", "TIFF", "PNG"};
QString AudioList[6] = {"MP3", "AAC", "FLAC"};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->Home);
    ui->inputPath->setReadOnly(true);
    ui->outputPath->setReadOnly(true);
    this->connect_slots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connect_slots()
{
    //system function connection
    connect(ui->videoConvButton, SIGNAL(clicked()), this, SLOT(goToVideoConv()));
    connect(ui->imageConvButton, SIGNAL(clicked()), this, SLOT(goToImageConv()));
    connect(ui->audioConvButton, SIGNAL(clicked()), this, SLOT(goToAudioConv()));
    connect(ui->inputNextButton, SIGNAL(clicked()), this, SLOT(goToOutput()));
    connect(ui->outputStartButton, SIGNAL(clicked()), this, SLOT(goToLoadingPage()));
    connect(this, SIGNAL(doneConversion()), this, SLOT(goToResultPage()));
    connect(ui->aboutButton, SIGNAL(clicked()), this, SLOT(goToAbout()));
    connect(ui->inputBrowseFile, SIGNAL(clicked()), this, SLOT(chooseInputPath()));
    connect(ui->outputBrowseFile, SIGNAL(clicked()), this, SLOT(chooseOutputPath()));
    connect(ui->inputClear, SIGNAL(clicked()), this, SLOT(clearInputPath()));
    connect(ui->outputClear, SIGNAL(clicked()), this, SLOT(clearOutputPath()));
    connect(ui->inputBackButton, SIGNAL(clicked()), this, SLOT(backToHome()));
    connect(ui->aboutBackButton, SIGNAL(clicked()), this, SLOT(backToHome()));
    connect(ui->resultBackButton, SIGNAL(clicked()), this, SLOT(backToHome()));
    connect(ui->outputBackButton, SIGNAL(clicked()), this, SLOT(backToInput()));
    this->addRadioGroup();
}

void MainWindow::goToVideoConv()
{
    ui->inputConverterTypeLabel->setText("Video Converter");
    ui->inputLabel->setText("Pilih file dengan format .avi untuk di konversi");
    ui->inputRadioButton1->setText("MP4");
    ui->inputRadioButton2->setText("3GP");
    ui->inputRadioButton3->setText("MKV");
    ui->inputNextButton->setEnabled(false);
    this->setConversionType("Video");
    ui->inputRadioButton1->setChecked(true);
    this->setConversionMethod(VideoList[0]);
    ui->stackedWidget->setCurrentWidget(ui->InputConverter);
}

void MainWindow::goToImageConv()
{
    ui->inputConverterTypeLabel->setText("Image Converter");
    ui->inputLabel->setText("Pilih file dengan format .bmp untuk di konversi");
    ui->inputRadioButton1->setText("JPEG");
    ui->inputRadioButton2->setText("TIFF");
    ui->inputRadioButton3->setText("PNG");
    ui->inputNextButton->setEnabled(false);
    this->setConversionType("Image");
    ui->inputRadioButton1->setChecked(true);
    this->setConversionMethod(ImageList[0]);
    ui->stackedWidget->setCurrentWidget(ui->InputConverter);
}

void MainWindow::goToAudioConv()
{
    ui->inputConverterTypeLabel->setText("Audio Converter");
    ui->inputLabel->setText("Pilih file dengan format .wav untuk di konversi");
    ui->inputRadioButton1->setText("MP3");
    ui->inputRadioButton2->setText("AAC");
    ui->inputRadioButton3->setText("FLAC");
    ui->inputNextButton->setEnabled(false);
    this->setConversionType("Audio");
    ui->inputRadioButton1->setChecked(true);
    this->setConversionMethod(AudioList[0]);
    ui->stackedWidget->setCurrentWidget(ui->InputConverter);
}

void MainWindow::goToAbout()
{
    ui->stackedWidget->setCurrentWidget(ui->About);
}

void MainWindow::goToOutput()
{
    //this->conversionMethod
    qDebug("conversion method : %s", this->getConversionMethod().toStdString().c_str());
    ui->outputStartButton->setEnabled(false);
    ui->outputFilename->setText(this->getFilename());
    ui->stackedWidget->setCurrentWidget(ui->OutputConverter);
}

void MainWindow::goToLoadingPage()
{
    ui->stackedWidget->setCurrentWidget(ui->LoadingPage);
    this->startConversion();
}

void MainWindow::goToResultPage()
{
    ui->resultPath->setText(this->getPathOutput());
    ui->stackedWidget->setCurrentWidget(ui->ResultPage);
}

void MainWindow::chooseInputPath()
{
    QString path;

    QString filename;

    path = QFileDialog::getOpenFileName(
           this,
           "Choose a file to open",
           QString::null,
           QString::null);

    filename = QFileInfo(path).fileName();
    QStringList list = filename.split(".");
    QString format = list[list.size() - 1];
    if(list.size() > 1 && (format.toLower() == "bmp" || format.toLower() == "wav" || format.toLower() == "avi"))
    {
        QString splittedName = "";

        for(int i = 0; i < list.size() -1 ; i++)
        {
            splittedName += list[i];
        }
        this->setFilename(splittedName);
        ui->inputPath->setText(path);
        this->setPathInput(path);
        ui->inputNextButton->setEnabled(true);
    }
}

void MainWindow::chooseOutputPath()
{
    QString path;
    QString filename;

    path = QFileDialog::getExistingDirectory(
           this, tr("Open Directory"),
           "/home",
           QFileDialog::ShowDirsOnly
           | QFileDialog::DontResolveSymlinks);

    ui->outputPath->setText(path);
    this->setPathOutput(path);
    ui->outputStartButton->setEnabled(true);
}

void MainWindow::clearInputPath()
{
    ui->inputPath->clear();
    this->setPathInput("");
    ui->inputNextButton->setEnabled(false);
}

void MainWindow::clearOutputPath()
{
    ui->outputPath->clear();
    this->setPathOutput("");
    ui->outputStartButton->setEnabled(false);
}

void MainWindow::backToHome()
{
    this->clearVars();
    this->clearUi();
    ui->stackedWidget->setCurrentWidget(ui->Home);
}

void MainWindow::backToInput()
{
    ui->stackedWidget->setCurrentWidget(ui->InputConverter);
}

void MainWindow::setPathInput(QString path)
{
    this->pathInput = path;
}

void MainWindow::setPathOutput(QString path)
{
    this->pathOutput = path;
}

void MainWindow::setConversionType(QString type)
{
    this->conversionType = type;
}

void MainWindow::setConversionMethod(QString method)
{
    this->conversionMethod = method;
}

void MainWindow::setFilename(QString name)
{
    this->filename = name;
}

QString MainWindow::getPathInput()
{
    return this->pathInput;
}

QString MainWindow::getPathOutput()
{
    return this->pathOutput;
}

QString MainWindow::getConversionType()
{
    return this->conversionType;
}

QString MainWindow::getConversionMethod()
{
    return this->conversionMethod;
}

QString MainWindow::getFilename()
{
    return this->filename;
}

void MainWindow::clearVars()
{
    this->setPathInput("");
    this->setPathOutput("");
    this->setFilename("");
    this->setConversionMethod("");
    this->setConversionType("");
}

void MainWindow::clearUi()
{
    ui->inputPath->clear();
    ui->outputPath->clear();
    ui->inputRadioButton1->setChecked(true);
}

void MainWindow::addRadioGroup()
{
    QButtonGroup* group = new QButtonGroup(this);
    group->addButton(ui->inputRadioButton3);
    group->addButton(ui->inputRadioButton2);
    group->addButton(ui->inputRadioButton1);

    connect(group, SIGNAL(buttonPressed(int)), this, SLOT(onGroupButtonPressed(int)));
}

void MainWindow::onGroupButtonPressed(int number)
{
    QString type = this->getConversionType();
    int total = 4;
    qDebug("conversion type : %s, number : %d", this->getConversionType().toStdString().c_str(), number+total);

    if(type == "Video")
    {
        this->setConversionMethod(VideoList[number+total]);
    }
    else
    if(type == "Image")
    {
        this->setConversionMethod(ImageList[number+total]);
    }
    else
    if(type == "Audio")
    {
        this->setConversionMethod(AudioList[number+total]);
    }
}

void MainWindow::startConversion()
{
    if(this->getConversionType() == "Audio")
    {
        AudioConversion myObject;
        myObject.convertAudio(this->getPathInput(), this->getPathOutput(), this->getFilename(), this->getConversionMethod());
    }
    else
    if(this->getConversionType() == "Image")
    {
        ImageConversion myObject;
        myObject.convertImage(this->getPathInput(), this->getPathOutput(), this->getFilename(), this->getConversionMethod());
    }
    else
    if(this->getConversionType() == "Video")
    {
        VideoConversion myObject;
        myObject.convertVideo(this->getPathInput(), this->getPathOutput(), this->getFilename(), this->getConversionMethod());
    }
    //QFile::copy(this->getPathInput(), this->getPathOutput() + "/" + this->getFilename() + ".jpeg");
    emit this->doneConversion();
}
