#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"
#include "databasecard.h"

#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    console = new Console;
    console->setEnabled(false);
    setCentralWidget(console);

    serial = new QSerialPort(this);
    settings = new SettingsDialog;
    dbCard = new DataBaseCard;

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    status = new QLabel;
    ui->statusBar->addWidget(status);

    vector_bdOfCard.push_back("50DB01A8");

    initActionsConnections();

    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &MainWindow::handleError);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    connect(console, &Console::getData, this, &MainWindow::writeData);
}


MainWindow::~MainWindow()
{
    delete settings;
    delete dbCard;
    delete ui;
}


void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        console->setEnabled(true);
        console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("Open error"));
    }
}


void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
    console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));
}


void MainWindow::about()
{
    QMessageBox::about(this, tr("About RFID Reader"),
                       tr("The <b>RFID Reader</b> is a course work on discipline of OOP"
                          "and microprocessors. In this program using Qt and Arduino"
                          "Uno with readout module RFIO-RC522."));
}


void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}


void MainWindow::readData()
{
    QByteArray data = serial->readAll();
    //console->putData(data);

    checkAccess(data);
}


void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}


void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionConfigure, &QAction::triggered, settings, &MainWindow::show);
    connect(ui->actionData_Base_of_card, &QAction::triggered, dbCard, &MainWindow::show);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}
////////////////////////////////////////////////////////////////////////
void MainWindow::checkAccess(const QByteArray &data)
{
    str.push_back(QString(data));
    //vector_bdOfCard.push_back("50DB01A8");
    if (str[8] == '\n')
    {
        if(str.contains(vector_bdOfCard[0]))
        {
            QPalette p = palette();
            p.setColor(QPalette::Base, Qt::green);
            p.setColor(QPalette::Text, Qt::black);
            console->setPalette(p);
        }
        else
        {
            QPalette p = palette();
            p.setColor(QPalette::Base, Qt::red);
            p.setColor(QPalette::Text, Qt::black);
            console->setPalette(p);
        }
        str.clear();
    }
}
