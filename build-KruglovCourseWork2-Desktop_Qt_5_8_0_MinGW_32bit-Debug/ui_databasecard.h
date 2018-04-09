/********************************************************************************
** Form generated from reading UI file 'databasecard.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASECARD_H
#define UI_DATABASECARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DataBaseCard
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QPushButton *button_add;
    QPushButton *button_delete;
    QListWidget *listWidget_dbCard;

    void setupUi(QDialog *DataBaseCard)
    {
        if (DataBaseCard->objectName().isEmpty())
            DataBaseCard->setObjectName(QStringLiteral("DataBaseCard"));
        DataBaseCard->resize(278, 290);
        buttonBox = new QDialogButtonBox(DataBaseCard);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 250, 261, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(DataBaseCard);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(220, 10, 51, 111));
        button_add = new QPushButton(groupBox);
        button_add->setObjectName(QStringLiteral("button_add"));
        button_add->setGeometry(QRect(10, 30, 30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_add->setIcon(icon);
        button_delete = new QPushButton(groupBox);
        button_delete->setObjectName(QStringLiteral("button_delete"));
        button_delete->setGeometry(QRect(10, 70, 30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_delete->setIcon(icon1);
        listWidget_dbCard = new QListWidget(DataBaseCard);
        listWidget_dbCard->setObjectName(QStringLiteral("listWidget_dbCard"));
        listWidget_dbCard->setGeometry(QRect(10, 30, 201, 192));

        retranslateUi(DataBaseCard);
        QObject::connect(buttonBox, SIGNAL(accepted()), DataBaseCard, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DataBaseCard, SLOT(reject()));

        QMetaObject::connectSlotsByName(DataBaseCard);
    } // setupUi

    void retranslateUi(QDialog *DataBaseCard)
    {
        DataBaseCard->setWindowTitle(QApplication::translate("DataBaseCard", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QString());
        button_add->setText(QString());
        button_delete->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DataBaseCard: public Ui_DataBaseCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASECARD_H
