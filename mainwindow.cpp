#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief Конструирует объект класса MainWindow.
 * @param parent Родительское окно.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_auth = new AuthForm;
    connect(ui_auth, &AuthForm::closed, this, &MainWindow::slot_show);
    ui_auth->show();
}

/**
 * @brief Отображает главное окно после закрытия окна авторизации.
 * @param auth Информация об авторизации.
 */
void MainWindow::slot_show(QString auth)
{
    this->show();
}

/**
 * @brief Деструктор класса MainWindow.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Обрабатывает событие нажатия кнопки "Выход".
 */
void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}

/*
void MainWindow::on_pushButton_task1_triggered()
{
    on_pushButton_task1_clicked();
}


void MainWindow::on_pushButton_task2_clicked()
{
    on_pushButton_task2_clicked();
}


void MainWindow::on_pushButton_task3_clicked()
{
    on_pushButton_task3_clicked();
}
*/
