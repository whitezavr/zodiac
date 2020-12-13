#include "data_entry_wind.h"
#include "ui_data_entry_wind.h"

DataEntryWind::DataEntryWind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataEntryWind)
{
    ui->setupUi(this);
    this->setWindowTitle("Узнай тайну своего рождения прямо сейччас!");
}

DataEntryWind::~DataEntryWind()
{
    delete ui;
}

void DataEntryWind::on_startDisplayInfo_clicked()
{
//    bool ok;
//    bool correctFlag = true;
//    bool dayTrue = true;

//    /* сбор информации о пользователе из интерфейса окна ввода данных */
//    quint64 day = ui->day->text().toInt(&ok);
//    quint64 month = ui->month->text().toInt(&ok);
//    quint64 year = ui->year->text().toInt(&ok);

//    /* проверка введенных пользователем данных на корректность */
//    if (year > 65535)
//    { QMessageBox::information(NULL, "неплохо, неплохо!", "это вы замахнулись! эта программа вряд ли доживет до этого года, введите год меньше 65535"); correctFlag = false; }
//    else if (year <= 0)
//    { QMessageBox::information(NULL, "ошибка ввода!", "год должен быть введен числом и больше 0!"); correctFlag = false; }
//    else
//    { userData.leapYearFlag = defineLeapYear(year); }

//    if ((month <= 0) || (month > 12))
//    { QMessageBox::information(NULL, "ошибка ввода!", "етить ты Вася конкретный! ввести нужно число для месяца и в году 12 месяцев!"); correctFlag = false; }

//    if (correctFlag == true)
//    {
//        if ((day <= 0) || (day > monthInfo[month-1][userData.leapYearFlag].nDays)) { dayTrue = false; }
//    }

//    if (!dayTrue)
//    { QMessageBox::information(NULL, "ошибка ввода!", "день должен быть введен числом больше 0 и не превышать допустимое количество дней в каждом месяце!"); }

//    /* если данные введены корректно, то идет дальнейшая обработка, если нет - ничего не происходит */
//    if ((correctFlag) && (dayTrue))
//    {
//        userData.day = day;
//        userData.month = month;
//        userData.year = year;
//        userData.zodiacName = defineZodiacName();

//        /* посылаем введенные (и определенные) данные пользователя в объект главного окна mainWindow */
//        emit senduserData(userData);

//        /* закрываем данное окно ввода данных пользователя */
//        this->close();
//    }
}
