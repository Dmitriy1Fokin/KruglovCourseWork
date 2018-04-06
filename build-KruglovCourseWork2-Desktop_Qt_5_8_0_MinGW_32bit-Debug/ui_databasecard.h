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
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DataBaseCard
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DataBaseCard)
    {
        if (DataBaseCard->objectName().isEmpty())
            DataBaseCard->setObjectName(QStringLiteral("DataBaseCard"));
        DataBaseCard->resize(400, 300);
        buttonBox = new QDialogButtonBox(DataBaseCard);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DataBaseCard);
        QObject::connect(buttonBox, SIGNAL(accepted()), DataBaseCard, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DataBaseCard, SLOT(reject()));

        QMetaObject::connectSlotsByName(DataBaseCard);
    } // setupUi

    void retranslateUi(QDialog *DataBaseCard)
    {
        DataBaseCard->setWindowTitle(QApplication::translate("DataBaseCard", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DataBaseCard: public Ui_DataBaseCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASECARD_H
