/********************************************************************************
** Form generated from reading UI file 'data_display_wind.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_DISPLAY_WIND_H
#define UI_DATA_DISPLAY_WIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DataDisplayWind
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *zodiacName;
    QLabel *label_2;
    QTextEdit *dispZodiacCharacter;
    QPushButton *startDataEntryWind;

    void setupUi(QDialog *DataDisplayWind)
    {
        if (DataDisplayWind->objectName().isEmpty())
            DataDisplayWind->setObjectName(QStringLiteral("DataDisplayWind"));
        DataDisplayWind->resize(428, 249);
        gridLayout = new QGridLayout(DataDisplayWind);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DataDisplayWind);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        zodiacName = new QLineEdit(DataDisplayWind);
        zodiacName->setObjectName(QStringLiteral("zodiacName"));

        horizontalLayout->addWidget(zodiacName);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(DataDisplayWind);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        dispZodiacCharacter = new QTextEdit(DataDisplayWind);
        dispZodiacCharacter->setObjectName(QStringLiteral("dispZodiacCharacter"));

        verticalLayout->addWidget(dispZodiacCharacter);

        startDataEntryWind = new QPushButton(DataDisplayWind);
        startDataEntryWind->setObjectName(QStringLiteral("startDataEntryWind"));

        verticalLayout->addWidget(startDataEntryWind);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(DataDisplayWind);

        QMetaObject::connectSlotsByName(DataDisplayWind);
    } // setupUi

    void retranslateUi(QDialog *DataDisplayWind)
    {
        DataDisplayWind->setWindowTitle(QApplication::translate("DataDisplayWind", "Dialog", 0));
        label->setText(QApplication::translate("DataDisplayWind", "\320\227\320\275\320\260\320\272 \320\267\320\276\320\264\320\270\320\260\320\272\320\260:", 0));
        label_2->setText(QApplication::translate("DataDisplayWind", "\320\272\321\200\320\260\321\202\320\272\320\260\321\217 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272\320\260 \320\267\320\275\320\260\320\272\320\260:", 0));
        startDataEntryWind->setText(QApplication::translate("DataDisplayWind", "<< \321\205\320\276\321\207\321\203 \321\203\320\267\320\275\320\260\321\202\321\214 \320\276 \320\264\321\200\321\203\320\263\320\270\321\205", 0));
    } // retranslateUi

};

namespace Ui {
    class DataDisplayWind: public Ui_DataDisplayWind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_DISPLAY_WIND_H
