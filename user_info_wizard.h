#ifndef USER_INFO_WIZARD_H
#define USER_INFO_WIZARD_H

#include <QObject>
#include <declarations.h>
#include <astrology.h>

class IntroPage : public QWizardPage
{
    Q_OBJECT

public:
    IntroPage(QWidget *parent = 0);

private:
    QLabel *label;
};

class FinishPage : public QWizardPage
{
    Q_OBJECT

public:
    FinishPage(QWidget *parent = 0);

private:
    QLabel *label;
};

class SetDayMonthBirth: public QWizardPage
{
    Q_OBJECT

public:
    SetDayMonthBirth(QWidget *parent = 0);

protected:
    bool validatePage() Q_DECL_OVERRIDE;
private:
    Astrology *astrology;
    QLabel *dayLabel;
    QLineEdit *dayLineEdit;
    QLabel *monthLabel;
    QLineEdit *monthLineEdit;
    QRadioButton * characterZodiacOut;
};

class DispZodiacInfo: public QWizardPage
{
    Q_OBJECT

public:
    DispZodiacInfo(QWidget *parent = 0);

protected:
    void initializePage() Q_DECL_OVERRIDE;

private:
    Astrology *astrology;
    QLabel *zodiacName;
    QTextEdit *zodiacCharacter;
    userData_t userData;
};


class UserInfoWizard: public QWizard
{
public:
    UserInfoWizard();
    void accept() Q_DECL_OVERRIDE;
private:
    Astrology *astrologyForUser;
};

#endif // USER_INFO_WIZARD_H
