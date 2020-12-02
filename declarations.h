#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QDebug>
#include <QString>
#include <QHash>
#include <QMessageBox>

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

typedef struct
{
    quint8 day;
    quint8 month;
    quint16 year;
    bool leapYearFlag;
    QString zodiacName;
} userData_t;

#endif // DECLARATIONS_H
