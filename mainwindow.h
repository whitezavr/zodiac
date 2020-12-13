#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "declarations.h"
#include "data_entry_wind.h"
#include "data_display_wind.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initArrays();
    QString defineZodiacName();

public slots:
    //void receiveuserData(userData_t data);
    /* слот, принимающий сигнал о том, что нужно снова вызвать окно ввода данных пользователя */
    void receiveStartEndryWind();

private slots:
    void on_startDataEntryWind_clicked();

private:
    Ui::MainWindow *ui;
    DataEntryWind *pDataEntryWind;
    DataDisplayWind *pDataDisplayWind;
};

#endif // MAINWINDOW_H
