#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pixmap;
    if (!pixmap.load( "/home/anon/Desktop/Archive/Archived/Hobbys & Projekte/IT/Programmieren/C++/OpenFiMo/OpenFiMo/ui-projects/qt_widgets_application/OpenFiMoUIQTWidgets/images/giver.png" )) {
        qWarning("Failed to load images/target.png");
    }
    ui->label_8->setPixmap( pixmap );
    if (!pixmap.load( "/home/anon/Desktop/Archive/Archived/Hobbys & Projekte/IT/Programmieren/C++/OpenFiMo/OpenFiMo/ui-projects/qt_widgets_application/OpenFiMoUIQTWidgets/images/money.png" )) {
        qWarning("Failed to load images/target.png");
    }
    ui->label_9->setPixmap( pixmap );
    if (!pixmap.load( "/home/anon/Desktop/Archive/Archived/Hobbys & Projekte/IT/Programmieren/C++/OpenFiMo/OpenFiMo/ui-projects/qt_widgets_application/OpenFiMoUIQTWidgets/images/receiver.png" )) {
        qWarning("Failed to load images/target.png");
    }
    ui->label_10->setPixmap( pixmap );
    if (!pixmap.load( "/home/anon/Desktop/Archive/Archived/Hobbys & Projekte/IT/Programmieren/C++/OpenFiMo/OpenFiMo/ui-projects/qt_widgets_application/OpenFiMoUIQTWidgets/images/piggy.png" )) {
        qWarning("Failed to load images/target.png");
    }
    ui->label_13->setPixmap( pixmap );
    if (!pixmap.load( "/home/anon/Desktop/Archive/Archived/Hobbys & Projekte/IT/Programmieren/C++/OpenFiMo/OpenFiMo/ui-projects/qt_widgets_application/OpenFiMoUIQTWidgets/images/long-arrow-right.png" )) {
        qWarning("Failed to load images/target.png");
    }
    ui->label_11->setPixmap( pixmap );
    ui->label_12->setPixmap( pixmap );
    ui->label_14->setPixmap( pixmap );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString tempQString(ui->lineEdit->text());

    for (int i=0; i < ui->listWidget->count(); i++) {
        if (ui->listWidget->item(i)->text() == tempQString) {
            QMessageBox msgBox;
            msgBox.setText("Error, it's not possible to use the same name twice!");
            msgBox.exec();
            return;
        }
    }

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
    AmountOwnerType aot = ao.getAmountOwnerType();
    if (aot == AmountOwnerType::moneyGiver) {
        ui->comboBox->setCurrentIndex(0);
    } else if (aot == AmountOwnerType::you) {
        ui->comboBox->setCurrentIndex(1);
    } else if (aot == AmountOwnerType::moneyReceiver) {
        ui->comboBox->setCurrentIndex(2);
    } else if (aot == AmountOwnerType::piggyBank) {
        ui->comboBox->setCurrentIndex(3);
    }


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
    QString tempString = ui->comboBox_4->itemText(ui->comboBox_4->currentIndex());
    QString tempString2 = ui->comboBox_2->itemText(ui->comboBox_2->currentIndex());
    QString tempString3 = ui->comboBox_3->itemText(ui->comboBox_3->currentIndex());
    QString tempString4 = ui->lineEdit_2->text();

    for (int i=0; i < ui->listWidget_2->count(); i++) {
        if (ui->listWidget_2->item(i)->text() == tempString4) {
            QMessageBox msgBox;
            msgBox.setText("Error, it's not possible to use the same name twice!");
            msgBox.exec();
            return;
        }
    }

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

void MainWindow::on_listWidget_2_currentTextChanged(const QString &currentText)
{

}

void MainWindow::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    QString temp = item->text();
    Transaction t = openFiMo.getTransactionByName(temp.toStdString());
    temp.fromStdString(t.getName());
    ui->lineEdit_2->setText(temp);
    if (t.getTransactionType() == TransactionType::incoming) {
        ui->comboBox_4->setCurrentIndex(0);
    } else if (t.getTransactionType() == TransactionType::outgoingExpense) {
        ui->comboBox_4->setCurrentIndex(1);
    } else if (t.getTransactionType() == TransactionType::outgoingSavings) {
        ui->comboBox_4->setCurrentIndex(2);
    }
    temp.fromStdString(t.getSender()->getName());
    ui->comboBox_2->setCurrentText(temp);
    temp.fromStdString(t.getReceiver()->getName());
    ui->comboBox_3->setCurrentText(temp);
    ui->doubleSpinBox_2->setValue(t.getAmountPerMonth());

}

void MainWindow::on_pushButton_5_clicked()
{
    openFiMo.calculateCurrentTransactions();
    ui->doubleSpinBox_3->setValue(openFiMo.getBalanceByAmountOwnerType(AmountOwnerType::moneyGiver));
    ui->doubleSpinBox_4->setValue(openFiMo.getBalanceByAmountOwnerType(AmountOwnerType::you));
    ui->doubleSpinBox_5->setValue(openFiMo.getBalanceByAmountOwnerType(AmountOwnerType::moneyReceiver));
    ui->doubleSpinBox_6->setValue(openFiMo.getBalanceByAmountOwnerType(AmountOwnerType::piggyBank));

}
