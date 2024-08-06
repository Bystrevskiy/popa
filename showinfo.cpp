#include "showinfo.h"
#include "ui_showinfo.h"
#include <QDebug>
#include "mainapp.h"
#include <QCloseEvent>
#include <QTime>
ShowInfo::ShowInfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ShowInfo)
{
    ui->setupUi(this);
}

ShowInfo::~ShowInfo()
{
    delete ui;
}

void ShowInfo::slot(QPixmap a)
{
    qDebug() << "Слот slot вызывается";

    if (!a.isNull()) {
        ui->photo->setPixmap(a);
        ui->photo->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    } else {
        qDebug() << "Получен пустой QPixmap";
    }
}

void ShowInfo::slotname(QString name, QString mobilephone, QString mail, QString department, QString car, QString tablenomer, QString doljnost, QString lasttime, QString lastdate)
{
    qDebug() << "Слот slotname вызывается";
    ui->label->setText(name);
    ui->label_7->setText(mobilephone);
    ui->label_12->setText(mail);
    ui->label_9->setText(department);
    ui->label_15->setText(car);
    ui->label_6->setText(tablenomer);
    ui->label_11->setText(doljnost);
    ui->label_16->setText(lasttime);
    ui->label_18->setText(lastdate);
    QTime time = QTime::currentTime();
    // ui->timeEdit->NoEditTriggers
    ui->timeEdit->setTime(time);
}
void ShowInfo::closeEvent(QCloseEvent *event)
{
    this->hide();
    event->ignore();
}

