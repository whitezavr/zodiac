#include "data_display_wind.h"
#include "ui_data_display_wind.h"

DataDisplayWind::DataDisplayWind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataDisplayWind)
{
    ui->setupUi(this);

    this->setWindowTitle("Узнай тайну своего рождения прямо сейччас!");

}

//void DataDisplayWind::setUserData(userData_t data)
//{
//    userData = data;
//    ui->zodiacName->setText(userData.zodiacName);
//    ui->dispZodiacCharacter->setText(zodiacCharacter.value(userData.zodiacName));
//}

DataDisplayWind::~DataDisplayWind()
{
    delete ui;
}

void DataDisplayWind::on_startDataEntryWind_clicked()
{
    emit sendStartEntryWind();
}
