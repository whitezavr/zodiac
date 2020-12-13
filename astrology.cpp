#include "astrology.h"

Astrology::Astrology()
{
    initArrays();

    userData.day = 1;
    userData.month = 1;
    userData.year = 0;
    userData.leapYearFlag = yearNotDefined;
    userData.zodiacName = "не определено";

    /* заполнение hash данными о знаке зодиака и его характеристике */
    zodiacCharacter.clear();
    zodiacCharacter.insert(zodiacNames[0], "Овен – первый знак в гороскопе. Отличается особым упрямством и непростым характером, и неспроста, ведь он является представителем стихии огня. Овен упорный и всегда идет к цели, не обращая внимание на сопутствующие проблемы и возможные последствия своих действий. Для этого знака характерны сила характера и целеустремленность, что помогает ему преодолевать сложности и добиваться нужного результата.");
    zodiacCharacter.insert(zodiacNames[1], "Телец поражает своим трудолюбием и упорством. В нем нет переменчивости представителей других знаков Зодиака. Телец стремится к самостоятельности, любит добиваться всего своими силами, не ждет везения и подарков судьбы. Ему присущи благородство и внушительная сила характера, которые помогают ему решать возникающие на жизненном пути проблемы и сложности.");
    zodiacCharacter.insert(zodiacNames[2], "Близнецы – знак Зодиака, характеристика которого отличается неоднозначностью и двойственностью. Они быстро меняют круг своих интересов и настрой. Близнецы довольно чувствительны и частенько делают из мухи слона, переживая из-за несуществующих проблем.");
    zodiacCharacter.insert(zodiacNames[3], "Рак – представитель водной стихии, находится под покровительством Луны, и ее влияние очень заметно. Рак – знак Зодиака, характеристика которого связана с постоянным самосовершенствованием. Они довольно непостоянны, нуждаются в частых переменах в жизни. Рожденные под знаком Рака – люди ранимые, однако не все видят эту их черту. Зачастую они пытаются скрыть это от окружающих, стараются казаться сильными и даже несколько холодными.");
    zodiacCharacter.insert(zodiacNames[4], "Лев не может быть простым и незаметным. Как царственное животное обладает особой силой и величественностью, так и люди, рожденные под этим огненным знаком, отличаются необычайной энергией, волей к победе, уверенностью в себе. При этом амбициозность Львов зачастую заключается в уверенности, что все, о чем они мечтают, должно достаться им просто по праву рождения.");
    zodiacCharacter.insert(zodiacNames[5], "Дева – знак Зодиака, характеристика которого заключается в одном слове – материализм. Это знак земной стихии, поэтому люди, рожденные под ним, больше думают о простых повседневных вещах, а не витают в облаках. Недостатки окружающих и проблемы вокруг часто вызывают у них недовольство или раздражение. Девы очень хозяйственны и педантичны, стараются организовать порядок вокруг себя.");
    zodiacCharacter.insert(zodiacNames[6], "Весы – воздушный знак Зодиака, в нем сильно влияние Венеры. Благодаря ему представители этого знака зачастую привлекательны и обладают неповторимым шармом. В жизни им важнее их индивидуальные качества и статус, гнаться за похвалой публики они не станут. Для Весов крайне важно создать семью, однако им нужно чувствовать личную свободу и возможность проявить индивидуальность.");
    zodiacCharacter.insert(zodiacNames[7], "Скорпион – знак Зодиака, характеристика которого основана на его противоречивости и неоднозначности. Люди, рожденные под этим знаком, сочетают в себе диаметрально противоположные качества. Сегодня Скорпион мягкий, нежный, спокойный и молчаливый, а завтра – суровый, язвительный, агрессивный. На него влияют такие планеты, как Плутон и Марс.");
    zodiacCharacter.insert(zodiacNames[8], "Стрелец – знак Зодиака, характеристика которого наглядно демонстрирует его принадлежность стихии огня. Представители этого знака весьма темпераментны, однако они отлично умеют управлять своими энергиями. Стрелец любит общаться с людьми, открыт и приветлив. Однако не стоит посягать на его свободу, это будет воспринято в штыки.");
    zodiacCharacter.insert(zodiacNames[9], "Козероги отличаются упорством и стойкостью. Невзирая на жизненные неурядицы, они всегда двигаются вперед, стремясь достичь своих целей. Это люди с сильным характером – настоящие представители знаков земной стихии.");
    zodiacCharacter.insert(zodiacNames[10], "Водолей – представитель воздушной стихии и один из самых неоднозначных знаков Зодиака. Разумеется, среди Водолеев можно встретить очень разных людей: есть довольно простые, но есть и те, кто способен шокировать близких и друзей своим неординарным поведением. Однако при этом Водолеи не склонны к излишней театральности.");
    zodiacCharacter.insert(zodiacNames[11], "Рыбы – знак Зодиака, характеристика которого основана на их эмоциональности, чувствительности и даже капризности. Люди, рожденные под этим знаком – мечтатели, витающие в облаках. Они – представители водной стихии, а значит, часто плывут по течению.");

}

void Astrology::initArrays()
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

void Astrology::setDayBirth(quint8 day)
{ userData.day = day; }

void Astrology::setMonthBirth(quint8 month)
{ userData.month = month; }

void Astrology::setYearBirth(quint8 year)
{ userData.year = year; }

void Astrology::setUserBirthInfo(userData_t itsUserData)
{ userData = itsUserData; }

QString Astrology::defineZodiacName()
{
    QString zodiacName;
    quint8 day = userData.day;
    quint8 month = userData.month;
    month -= 1;
    yearLeap_enum leapFlag = userData.leapYearFlag;
    int indLeap = 0;

    if (leapFlag == yearLeap)
    { indLeap = 1; }
    else if (leapFlag == yearNotLeap)
    { indLeap = 0; }
    else
    {
        if (month == 2 && day == 29)
        { indLeap = 1; }
    }

    quint16 dayInYears = monthInfo[month][0].nDaysSumInPrev + day;
    if (indLeap && dayInYears > 59)
    { dayInYears += 1; }

    for (int i = 0; i < NUM_MONTH; i++)
    {
        if ((dayInYears > 357) || (dayInYears < 21) )
        { zodiacName = "козерог"; break; }
        else
        {
            if ((dayInYears >= zodiac[i][indLeap].beginDayInYear) &&
                    (dayInYears <= zodiac[i][indLeap].endDayInYear))
            { zodiacName = zodiac[i][indLeap].name; break; }
        }
    }
    userData.zodiacName = zodiacName;
    return (zodiacName);
}

QString Astrology::getZodiacName()
{ return userData.zodiacName; }

QString Astrology::getZodiacCharacter()
{ return zodiacCharacter.value(userData.zodiacName); }

yearLeap_enum Astrology::defineLeapYear(quint16 year)
{
    yearLeap_enum leapFlag = yearNotDefined;

    if ((year % 400 == 0))
    { leapFlag = yearLeap; }
    else if ((year % 100) == 0)
    { leapFlag = yearNotLeap; }
    else if ((year % 4) == 0)
    { leapFlag = yearLeap; }
    else
    { leapFlag = yearNotLeap; }

    return leapFlag;
}
