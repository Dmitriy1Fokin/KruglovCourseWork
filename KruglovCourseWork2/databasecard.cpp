#include "databasecard.h"
#include "ui_databasecard.h"

DataBaseCard::DataBaseCard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataBaseCard)
{
    ui->setupUi(this);
}

DataBaseCard::~DataBaseCard()
{
    delete ui;
}
