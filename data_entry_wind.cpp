#include "data_entry_wind.h"
#include "ui_data_entry_wind.h"

DataEntryWind::DataEntryWind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataEntryWind)
{
    ui->setupUi(this);
    this->setWindowTitle("Узнай тайну своего рождения прямо сейччас!");

    initArrays();

    userData.day = 1;
    userData.month = 1;
    userData.year = 0;
    userData.leapYearFlag = false;
    userData.zodiacName = "";
}

DataEntryWind::~DataEntryWind()
{
    delete ui;
}

void DataEntryWind::on_startDisplayInfo_clicked()
{
    bool ok;
    bool correctFlag = true;
    bool dayTrue = true;

    /* сбор информации о пользователе из интерфейса окна ввода данных */
    quint64 day = ui->day->text().toInt(&ok);
    quint64 month = ui->month->text().toInt(&ok);
    quint64 year = ui->year->text().toInt(&ok);

    /* проверка введенных пользователем данных на корректность */
    if (year > 65535)
    { QMessageBox::information(NULL, "неплохо, неплохо!", "это вы замахнулись! эта программа вряд ли доживет до этого года, введите год меньше 65535"); correctFlag = false; }
    else if (year <= 0)
    { QMessageBox::information(NULL, "ошибка ввода!", "год должен быть введен числом и больше 0!"); correctFlag = false; }
    else
    { userData.leapYearFlag = defineLeapYear(year); }

    if ((month <= 0) || (month > 12))
    { QMessageBox::information(NULL, "ошибка ввода!", "етить ты Вася конкретный! ввести нужно число для месяца и в году 12 месяцев!"); correctFlag = false; }

    if (correctFlag == true)
    {
        if ((day <= 0) || (day > monthInfo[month-1][userData.leapYearFlag].nDays)) { dayTrue = false; }
    }

    if (!dayTrue)
    { QMessageBox::information(NULL, "ошибка ввода!", "день должен быть введен числом больше 0 и не превышать допустимое количество дней в каждом месяце!"); }

    /* если данные введены корректно, то идет дальнейшая обработка, если нет - ничего не происходит */
    if ((correctFlag) && (dayTrue))
    {
        userData.day = day;
        userData.month = month;
        userData.year = year;
        userData.zodiacName = defineZodiacName();

        /* посылаем введенные (и определенные) данные пользователя в объект главного окна mainWindow */
        emit senduserData(userData);

        /* закрываем данное окно ввода данных пользователя */
        this->close();
    }
}

QString DataEntryWind::defineZodiacName()
{
    quint8 day = userData.day;
    quint8 month = userData.month;
    month -= 1;
    bool leapFlag = userData.leapYearFlag;

    quint16 dayInYears = monthInfo[month][0].nDaysSumInPrev + day;
    if (leapFlag && dayInYears > 59)
    { dayInYears += 1; }

    for (int i = 0; i < NUM_MONTH; i++)
    {
        if ((dayInYears > 357) || (dayInYears < 21) )
        { return ("козерог"); }
        else
        {
            if ((dayInYears >= zodiac[i][leapFlag].beginDayInYear) &&
                    (dayInYears <= zodiac[i][leapFlag].endDayInYear))
            { return (zodiac[i][leapFlag].name); }
        }
    }
}

void DataEntryWind::initArrays()
{
    quint16 sum = 0;
    quint16 sumLeap = 0;

    for (int i = 0; i < NUM_MONTH; i++)
    {
        monthInfo[i][0].month = i;
        monthInfo[i][1].month = i;

        monthInfo[i][0].nDays = numDaysInMonth[i];
        monthInfo[i][1].nDays = numDaysInMonthLeap[i];

        if (i > 0)
        {
            sum += numDaysInMonth[i - 1];
            sumLeap += numDaysInMonthLeap[i - 1];
        }

        monthInfo[i][0].nDaysSumInPrev = sum;
        monthInfo[i][1].nDaysSumInPrev = sumLeap;

        zodiac[i][0].name = zodiacNames[i];
        zodiac[i][1].name = zodiacNames[i];
        zodiac[i][0].beginDayInYear = beginDayZodiacInYear[i];
        zodiac[i][0].endDayInYear = endDayZodiacInYear[i];

        if (i < 9)
        {
            zodiac[i][1].beginDayInYear = zodiac[i][0].beginDayInYear + 1;
            zodiac[i][1].endDayInYear = zodiac[i][0].endDayInYear + 1;
        }
        else
        {
            zodiac[i][1].beginDayInYear = zodiac[i][0].beginDayInYear;
            zodiac[i][1].endDayInYear = zodiac[i][0].endDayInYear;
        }
    }

    zodiac[9][1].beginDayInYear = zodiac[9][0].beginDayInYear + 1;
    zodiac[11][1].endDayInYear = zodiac[11][0].endDayInYear + 1;
}

bool DataEntryWind::defineLeapYear(quint16 year)
{
    bool leapFlag = false;

    if ((year % 400 == 0))
    { leapFlag = true; }
    else if ((year % 100) == 0)
    { leapFlag = false; }
    else if ((year % 4) == 0)
    { leapFlag = true; }
    else
    { leapFlag = false; }

    return leapFlag;
}
