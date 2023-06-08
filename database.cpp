#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseDestroyer::~DatabaseDestroyer()
{
    delete this->pInstance;
}

void DatabaseDestroyer::initialize(Database *p)
{
    this->pInstance = p;
}

Database *Database::pInstance = nullptr;
DatabaseDestroyer Database::destroyer;

Database::Database()
{
    initDB();
}

Database::~Database()
{
    dbInstance.close();
}

Database *Database::getInstance()
{
    if (!pInstance)
    {
        pInstance = new Database();
        destroyer.initialize(pInstance);
    }
    return pInstance;
}

void Database::initDB()
{
    dbInstance = QSqlDatabase::addDatabase("QSQLITE");
    dbInstance.setDatabaseName("database.db");

    if (!dbInstance.open())
    {
        qDebug() << "Error opening database: " << dbInstance.lastError().text();
    }
    else
    {
        qDebug() << "Database opened successfully";
    }

    doSQLQuery("CREATE TABLE IF NOT EXISTS Users (userID INTEGER PRIMARY KEY, username TEXT UNIQUE NOT NULL, password TEXT NOT NULL, isAdmin INTEGER NOT NULL)");
}

QSqlQuery Database::doSQLQuery(const QString &stringQuery)
{
    QSqlQuery query(dbInstance);
    if (!query.exec(stringQuery))
    {
        qDebug() << "Query execution failed: " << query.lastError().text();
    }
    return query;
}

bool Database::addUser(const QString &username, const QString &password)
{
    QSqlQuery query = doSQLQuery(QString("INSERT INTO Users (username, password, isAdmin) VALUES ('%1', '%2', %3)")
                                    .arg(username)
                                    .arg(password)
                                    .arg(0)); // 0 indicates a regular user, not admin

    return query.isActive();
}

bool Database::checkUser(const QString &username, const QString &password)
{
    QSqlQuery query = doSQLQuery(QString("SELECT * FROM Users WHERE username = '%1' AND password = '%2'")
                                    .arg(username)
                                    .arg(password));

    return query.next();
}

bool Database::isAdmin(const QString &username)
{
    QSqlQuery query = doSQLQuery(QString("SELECT isAdmin FROM Users WHERE username = '%1'")
                                    .arg(username));

    if (query.next())
    {
        int isAdmin = query.value("isAdmin").toInt();
        return isAdmin == 1; // If isAdmin = 1, user is an admin
    }

    return false;
}
