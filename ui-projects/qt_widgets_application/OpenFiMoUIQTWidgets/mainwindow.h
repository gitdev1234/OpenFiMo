#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "OpenFinanceMonitor.h"
#include "Types.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_2_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_3_clicked();

    void on_comboBox_4_currentTextChanged(const QString &arg1);

    void on_listWidget_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::MainWindow *ui;
    OpenFinanceMonitor openFiMo;

    void updateTransactionComboBoxes();
};

#endif // MAINWINDOW_H
