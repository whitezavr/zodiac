#ifndef ASTROLOGY_H
#define ASTROLOGY_H
#include "declarations.h"

#define NUM_MONTH 12

const quint8 numDaysInMonth[NUM_MONTH] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const quint8 numDaysInMonthLeap[NUM_MONTH] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const quint16 beginDayZodiacInYear[NUM_MONTH] = {80, 110, 142, 172, 204, 236, 266, 297, 326, 357, 21, 48};
const quint16 endDayZodiacInYear[NUM_MONTH] = {109, 141, 171, 203, 235, 265, 296, 325, 356, 20, 47, 79};

const QString zodiacNames[NUM_MONTH] = {"овен", "телец", "близнецы", "рак", "лев", "дева", "весы", "скорпион",
                                  "стрелец", "козерог", "водолей", "рыбы"};

typedef struct
{
    quint8 month;
    quint8 nDays;
    quint16 nDaysSumInPrev;
} monthInfo_t;

typedef struct
{
    quint16 beginDayInYear;
    quint16 endDayInYear;
    QString name;
} zodiacDays_t;

typedef enum
{
    yearNotDefined,
    yearNotLeap,
    yearLeap
} yearLeap_enum;

typedef struct
{
    quint8 day;
    quint8 month;
    quint16 year;
    yearLeap_enum leapYearFlag;
    QString zodiacName;
    QString zodiacCharacter;
} userData_t;

class Astrology
{
public:
    Astrology();
    /* опеределение имя знака зодиака по числу и месяцу рождения */
    QString defineZodiacName();
    /* возвращает имя определенного раннее знака зодиака */
    QString getZodiacName();

    QString getZodiacCharacter();
    /* определение високосного года
     * return: false - невисокосный год, true - високосный год */
    yearLeap_enum defineLeapYear(quint16 year);

    void setDayBirth(quint8 day);
    void setMonthBirth(quint8 month);
    void setYearBirth(quint8 year);
    void setUserBirthInfo(userData_t itsUserData);

    monthInfo_t monthInfo[NUM_MONTH][2];

private:
    /* определение служебных массивов для дальнейшей работы */
    void initArrays();

private:
    /*hash, где ключ - имя знака зодиака, значение - его характеристика */
    QHash <QString, QString> zodiacCharacter;
    /* данные пользвателя */
    userData_t userData;
    /* служебные символы для определения знака зодиака */
    zodiacDays_t zodiac[NUM_MONTH][2];
};

#endif // ASTROLOGY_H
