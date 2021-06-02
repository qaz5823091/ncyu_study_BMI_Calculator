#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDoubleValidator *double_validator = new QDoubleValidator();
    ui->textEdit_height->
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    result = "";
    bool check;
    height = ui->textEdit_height->toPlainText().toDouble(&check);
    if (!check) {
        result = "輸入錯誤";
        ui->label_result->setText(result);
        return ;
    }

    weight = ui->textEdit_weight->toPlainText().toDouble(&check);
    if (!check) {
        result = "輸入錯誤";
        ui->label_result->setText(result);
        return ;
    }

    double bmi_value = weight / ( (height / 100) * (height / 100) );

    result += "結果：" + QString::number(bmi_value);

    if (bmi_value > 20) {
        result += " 健康體位";
    }
    else {
        result += " 不健康體位";
    }

    ui->label_result->setText(result);

    return ;
}
