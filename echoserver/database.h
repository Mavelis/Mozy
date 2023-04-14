#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

class DataBase : public QObject
{

private:
    // Сам объект базы данных, с которым будет производиться работа
    QSqlDatabase    db;

public:
    /* Внутренние методы для работы с базой данных
     * */
    explicit DataBase(QObject *parent = 0);
    ~DataBase();
    void openDataBase();
    void closeDataBase();
    QString bdquery(QString temp); //запрос В БД для сравнения логина и пароля
};

#endif // DATABASE_H
