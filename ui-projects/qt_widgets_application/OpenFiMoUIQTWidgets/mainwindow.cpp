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

void MainWindow::on_pushButton_2_clicked()
{
    qDeleteAll(ui->listWidget->selectedItems());

}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (index == 2) {
       updateTransactionComboBoxes();
    }
}

void MainWindow::updateTransactionComboBoxes()
{
    ui->comboBox_2->clear();
    for(int i = 0; i < ui->listWidget->count(); ++i)
    {
        QListWidgetItem* item = ui->listWidget->item(i);
        QString tempQString(item->text());
        AmountOwner ao = openFiMo.getAmoutOwnerByName(tempQString.toStdString());
        tempQString.fromStdString(ao.getName());
        ui->comboBox_2->addItem(tempQString);
        ui->comboBox_3->addItem(tempQString);
    }

}

void MainWindow::on_pushButton_3_clicked()
{

    QString tempString = ui->comboBox_4->itemData(ui->comboBox_4->currentIndex()).toString();
    QString tempString2 = ui->comboBox_2->itemData(ui->comboBox_2->currentIndex()).toString();
    QString tempString3 = ui->comboBox_3->itemData(ui->comboBox_3->currentIndex()).toString();
    QString tempString4 = ui->lineEdit_2->text();

    if (tempString == "incoming") {    
        openFiMo.addIncomingTransaction(tempString4.toStdString(),openFiMo.getAmoutOwnerByName(tempString2.toStdString()),ui->doubleSpinBox_2->value());
    } else if (tempString == "outgoing expense") {
        openFiMo.addOutgoingExpenseTransaction(tempString4.toStdString(),openFiMo.getAmoutOwnerByName(tempString3.toStdString()),ui->doubleSpinBox_2->value());
    } else if (tempString == "outgoing savings") {
        openFiMo.addOutgoingExpenseTransaction(tempString4.toStdString(),openFiMo.getAmoutOwnerByName(tempString3.toStdString()),ui->doubleSpinBox_2->value());
    }

    ui->listWidget_2->addItem(tempString4);

}

void MainWindow::on_comboBox_4_currentTextChanged(const QString &arg1)
{
    QString tempString(arg1);
    if (tempString == "incoming") {
        updateTransactionComboBoxes();
        ui->comboBox_2->setEditable(true);
        ui->comboBox_3->clear();
        ui->comboBox_3->addItem("Me");
        ui->comboBox_3->setEditable(false);
    } else if (tempString == "outgoing expense") {
        ui->comboBox_3->setEditable(true);
        ui->comboBox_2->clear();
        ui->comboBox_2->addItem("Me");
        ui->comboBox_2->setEditable(false);
    } else if (tempString == "outgoing savings") {
        ui->comboBox_3->setEditable(true);
        ui->comboBox_2->clear();
        ui->comboBox_2->addItem("Me");
        ui->comboBox_2->setEditable(false);
    }
}

void MainWindow::on_listWidget_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{


}
