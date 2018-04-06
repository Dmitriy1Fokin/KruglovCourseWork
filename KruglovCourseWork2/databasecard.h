#ifndef DATABASECARD_H
#define DATABASECARD_H

#include <QDialog>

namespace Ui {
class DataBaseCard;
}

class DataBaseCard : public QDialog
{
    Q_OBJECT

public:
    explicit DataBaseCard(QWidget *parent = 0);
    ~DataBaseCard();

private:
    Ui::DataBaseCard *ui;
};

#endif // DATABASECARD_H
