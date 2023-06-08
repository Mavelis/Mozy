#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "authform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Класс MainWindow представляет главное окно приложения.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструирует объект класса MainWindow.
     * @param parent Родительское окно.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса MainWindow.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Обрабатывает событие нажатия кнопки "Выход".
     */
    void on_pushButton_exit_clicked();

    /**
     * @brief Слот для отображения окна аутентификации.
     * @param auth Информация об аутентификации.
     */
    void slot_show(QString auth);

    /*
    void on_pushButton_task1_clicked();

    void on_pushButton_task2_clicked();

    void on_pushButton_task3_clicked();
    */

private:
    Ui::MainWindow *ui; /**< Объект пользовательского интерфейса. */
    AuthForm *ui_auth; /**< Объект окна аутентификации. */
};

#endif // MAINWINDOW_H
