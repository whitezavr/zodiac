#ifndef DATA_ENTRY_WIND_H
#define DATA_ENTRY_WIND_H

#include <QDialog>
#include <declarations.h>

namespace Ui {
class DataEntryWind;
}

class DataEntryWind : public QDialog
{
    Q_OBJECT

public:
    explicit DataEntryWind(QWidget *parent = 0);
    ~DataEntryWind();

signals:
    //void senduserData(userData_t data);

private slots:
    void on_startDisplayInfo_clicked();

private:
    Ui::DataEntryWind *ui;

};

#endif // DATA_ENTRY_WIND_H
