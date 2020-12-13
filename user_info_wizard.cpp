#include "user_info_wizard.h"


IntroPage::IntroPage(QWidget *parent)
    :QWizardPage(parent)
{
    setWindowTitle(tr("Введение"));

    label = new QLabel(tr("Этот wizard поможет тебе узнать твою судьбу по дате рождения"));
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}

FinishPage::FinishPage(QWidget *parent)
    :QWizardPage(parent)
{
    setWindowTitle(tr("Финиш"));

    label = new QLabel(tr("Теперь вы знаете о себе больше!"));
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}

SetDayMonthBirth::SetDayMonthBirth(QWidget *parent)
    :QWizardPage(parent)
{
    setTitle(tr("введите число и месяц своего рождения:"));

    astrology = new Astrology;
    dayLabel = new QLabel(tr("день:"));
    dayLineEdit = new QLineEdit;
    dayLabel->setBuddy(dayLineEdit);

    monthLabel = new QLabel(tr("месяц:"));
    monthLineEdit = new QLineEdit;
    monthLabel->setBuddy(monthLineEdit);

    characterZodiacOut = new QRadioButton(tr("вывести краткую характеристику своего знака"));

    registerField("dayBirth", dayLineEdit);
    registerField("monthBirth", monthLineEdit);
    registerField("characterZodiacOut", characterZodiacOut);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(dayLabel, 0, 0);
    layout->addWidget(dayLineEdit, 0, 1);
    layout->addWidget(monthLabel, 1, 0);
    layout->addWidget(monthLineEdit, 1, 1);

    QVBoxLayout *layoutVertical = new QVBoxLayout;

    layoutVertical->addLayout(layout);
    layoutVertical->addWidget(characterZodiacOut);
    setLayout(layoutVertical);
}

bool SetDayMonthBirth::validatePage()
{
    bool ok;
    bool correctFlag = true;
    bool dayTrue = true;
    quint8 day = field("dayBirth").toInt(&ok);
    quint8 month = field("monthBirth").toInt(&ok);

        if ((month <= 0) || (month > 12))
        { QMessageBox::information(NULL, "ошибка ввода!", "етить ты Вася конкретный! ввести нужно число для месяца и в году 12 месяцев!"); correctFlag = false; }

        if (correctFlag == true)
        {
            if ((day <= 0) || (day > astrology->monthInfo[month-1][1].nDays)) { dayTrue = false; }
        }

        if (!dayTrue)
        { QMessageBox::information(NULL, "ошибка ввода!", "день должен быть введен числом больше 0 и не превышать допустимое количество дней в каждом месяце!"); }

        /* если данные введены корректно, то идет дальнейшая обработка, если нет - ничего не происходит */
        if ((correctFlag) && (dayTrue))
        { return true; }
        else { return false; }
}

DispZodiacInfo::DispZodiacInfo(QWidget *parent)
    :QWizardPage(parent)
{
    setTitle(tr("определение вашего гороскопа"));
    astrology = new Astrology;

    zodiacName = new QLabel;
    zodiacName->setWordWrap(true);
    zodiacCharacter = new QTextEdit;
    zodiacCharacter->setVisible(false);
    zodiacCharacter->setReadOnly(true);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(zodiacName);
    layout->addWidget(zodiacCharacter);
    setLayout(layout);
}

void DispZodiacInfo::initializePage()
{
    bool ok;
    bool characterZodiacOutFlag = field("characterZodiacOut").toBool();

    userData.day = field("dayBirth").toInt(&ok);
    userData.month = field("monthBirth").toInt(&ok);
    astrology->setDayBirth(userData.day);
    astrology->setMonthBirth(userData.month);
    userData.zodiacName = astrology->defineZodiacName();
    userData.zodiacCharacter = astrology->getZodiacCharacter();

    zodiacName->setText("вы по гороскопу: " + userData.zodiacName);
    zodiacCharacter->setText(userData.zodiacCharacter);

    if (characterZodiacOutFlag)
    { zodiacCharacter->setVisible(true); }
    else
    { zodiacCharacter->setVisible(false); }
}

UserInfoWizard::UserInfoWizard()
{
    astrologyForUser = new Astrology;

    QRect rect(10, 20, 100, 300);
    QPixmap originalPixmap(":/pictures/zodiacBackgroundLeft.jpg");
    QPixmap pixmap = originalPixmap.copy(rect);

    setWizardStyle(QWizard::ClassicStyle);
    setPixmap(QWizard::WatermarkPixmap,pixmap);
    setOption(QWizard::NoBackButtonOnLastPage, true);
//    setOption(QWizard::HaveHelpButton, true);

    addPage(new IntroPage);
    addPage(new SetDayMonthBirth);
    addPage(new DispZodiacInfo);
    addPage(new FinishPage());

    setWindowTitle("Узнай тайну своего рождения прямо сейчас!");
    show();
}

void UserInfoWizard::accept()
{
    QDialog::accept();
}

