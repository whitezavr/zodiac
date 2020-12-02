/* данный класс предназначен для управления дочерними окнами и перераспределением потоков данных между окнами */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "declarations.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Узнай тайну своего рождения прямо сейччас!");

    pDataEntryWind = new DataEntryWind;
    /* создаем соединение для того чтобы обект окна data_entry_wind смог отправлять
     * введенные данные пользователя в объект главного окна mainwindow*/
    connect(pDataEntryWind,
            SIGNAL(senduserData(userData_t)),
            this,
            SLOT(receiveuserData(userData_t)));

    pDataDisplayWind = new DataDisplayWind;
    /* создаем соединение для того, чтобы сообщить в объект главного окна
     * (из объекта отображения инфы о пользователя) о том, что нужно снова
     * вызвать окно ввода данных пользователя */
    connect(pDataDisplayWind,
            SIGNAL(sendStartEntryWind()),
            this,
            SLOT(receiveStartEndryWind()));
}

void MainWindow::receiveuserData(userData_t data)
{
    userData = data;

    /* вызов окна для отображения данных (характеристики) пользователя */
    pDataDisplayWind->show();
    /* передаем информацию о пользователе в объект окна вывода данных о пользователе */
    pDataDisplayWind->setUserData(userData);
}

void MainWindow::receiveStartEndryWind()
{
    /* вызов окна для ввода данных пользователя */
    pDataEntryWind->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startDataEntryWind_clicked()
{
    pDataEntryWind->show();
}
