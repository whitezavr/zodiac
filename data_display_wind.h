#ifndef DATA_DISPLAY_WIND_H
#define DATA_DISPLAY_WIND_H

#include <QDialog>
#include <declarations.h>

namespace Ui {
class DataDisplayWind;
}

class DataDisplayWind : public QDialog
{
    Q_OBJECT

public:
    explicit DataDisplayWind(QWidget *parent = 0);
    ~DataDisplayWind();

signals:
    void sendStartEntryWind();

private slots:
    void on_startDataEntryWind_clicked();

private:
    Ui::DataDisplayWind *ui;


public:
    /* устанавливает характеристики пользователя в окне вывода данных */
    //void setUserData(userData_t data);
};

#endif // DATA_DISPLAY_WIND_H
