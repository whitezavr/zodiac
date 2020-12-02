/********************************************************************************
** Form generated from reading UI file 'data_entry_wind.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_ENTRY_WIND_H
#define UI_DATA_ENTRY_WIND_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DataEntryWind
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *day;
    QLineEdit *month;
    QLineEdit *year;
    QPushButton *startDisplayInfo;

    void setupUi(QDialog *DataEntryWind)
    {
        if (DataEntryWind->objectName().isEmpty())
            DataEntryWind->setObjectName(QStringLiteral("DataEntryWind"));
        DataEntryWind->resize(424, 90);
        gridLayout = new QGridLayout(DataEntryWind);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DataEntryWind);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        day = new QLineEdit(DataEntryWind);
        day->setObjectName(QStringLiteral("day"));

        horizontalLayout->addWidget(day);

        month = new QLineEdit(DataEntryWind);
        month->setObjectName(QStringLiteral("month"));

        horizontalLayout->addWidget(month);

        year = new QLineEdit(DataEntryWind);
        year->setObjectName(QStringLiteral("year"));

        horizontalLayout->addWidget(year);


        verticalLayout->addLayout(horizontalLayout);

        startDisplayInfo = new QPushButton(DataEntryWind);
        startDisplayInfo->setObjectName(QStringLiteral("startDisplayInfo"));

        verticalLayout->addWidget(startDisplayInfo);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(DataEntryWind);

        QMetaObject::connectSlotsByName(DataEntryWind);
    } // setupUi

    void retranslateUi(QDialog *DataEntryWind)
    {
        DataEntryWind->setWindowTitle(QApplication::translate("DataEntryWind", "Dialog", 0));
        label->setText(QApplication::translate("DataEntryWind", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\262\320\276\321\216 \320\264\320\260\321\202\321\203 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217:", 0));
        day->setText(QApplication::translate("DataEntryWind", "\321\207\320\270\321\201\320\273\320\276", 0));
        month->setText(QApplication::translate("DataEntryWind", "\320\274\320\265\321\201\321\217\321\206", 0));
        year->setText(QApplication::translate("DataEntryWind", "\320\263\320\276\320\264", 0));
        startDisplayInfo->setText(QApplication::translate("DataEntryWind", "\321\203\320\267\320\275\320\260\321\202\321\214 \321\201\320\262\320\276\321\216 \321\201\321\203\320\264\321\214\320\261\321\203 >>", 0));
    } // retranslateUi

};

namespace Ui {
    class DataEntryWind: public Ui_DataEntryWind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_ENTRY_WIND_H
