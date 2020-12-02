#ifndef DATA_ENTRY_WIND_H
#define DATA_ENTRY_WIND_H

#include <QDialog>
#include <declarations.h>

namespace Ui {
class DataEntryWind;
}

class DataEntryWind : public QDialog
{
    Q_OBJECT

public:
    explicit DataEntryWind(QWidget *parent = 0);
    ~DataEntryWind();

signals:
    void senduserData(userData_t data);

private slots:
    void on_startDisplayInfo_clicked();

private:
    Ui::DataEntryWind *ui;
    /* данные пользвателя */
    userData_t userData;

    /* служебные символы для определения знака зодиака */
    monthInfo_t monthInfo[NUM_MONTH][2];
    zodiacDays_t zodiac[NUM_MONTH][2];

private:
    /* опеределение имя знака зодиака по числу и месяцу рождения */
    QString defineZodiacName();
    /* определение високосного года
     * return: false - невисокосный год, true - високосный год */
    bool defineLeapYear(quint16 year);
    /* определение служебных массивов для дальнейшей работы */
    void initArrays();
};

#endif // DATA_ENTRY_WIND_H
