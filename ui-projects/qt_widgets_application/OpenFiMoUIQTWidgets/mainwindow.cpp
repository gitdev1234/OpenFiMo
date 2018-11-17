#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString tempQString(ui->lineEdit->text());
    if (ui->comboBox->currentText() == "Money Giver") {
        openFiMo.addMoneyGiver(tempQString.toStdString(),ui->doubleSpinBox->value());
    } else if (ui->comboBox->currentText() == "Me") {
        openFiMo.addYou(tempQString.toStdString(),ui->doubleSpinBox->value());
    } else if (ui->comboBox->currentText() == "Money Receiver") {
        openFiMo.addMoneyReceiver(tempQString.toStdString(),ui->doubleSpinBox->value());
    } else if (ui->comboBox->currentText() == "Piggy Bank") {
        openFiMo.addPiggyBank(tempQString.toStdString(),ui->doubleSpinBox->value());
    }

    ui->listWidget->addItem(ui->lineEdit->text());
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString tempQString(item->text());
    AmountOwner ao = openFiMo.getAmoutOwnerByName(tempQString.toStdString());
    tempQString.fromStdString(ao.getName());
    ui->lineEdit->setText(tempQString);
    ui->doubleSpinBox->setValue(ao.getBalance());
}
