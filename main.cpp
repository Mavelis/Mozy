#include "mainwindow.h"
#include "authform.h"

#include <QApplication>

/**
 * @brief Точка входа в приложение.
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return Код возврата приложения.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Запуск основного цикла обработки событий приложения
    return a.exec();
}
