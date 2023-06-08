#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

class Database;

class DatabaseDestroyer
{
private:
    Database *pInstance;

public:
    ~DatabaseDestroyer();
    void initialize(Database *p);
};

/*!
 * \brief Синглтон-класс для работы с базой данных
 */
class Database
{
private:
    static Database *pInstance;
    static DatabaseDestroyer destroyer;
    QSqlDatabase dbInstance;

protected:
    /*!
     * \brief Конструктор класса
     */
    Database();

public:
    Database(const Database &) = delete;
    Database &operator=(const Database &) = delete;

    ~Database();

    static Database *getInstance();

    /*!
     * \brief Инициализация базы данных
     */
    void initDB();

    /*!
     * \brief Функция осуществления SQL-запроса
     * \param[in] stringQuery SQL-запрос строкой
     * \return Объект типа QSqlQuery
     */
    QSqlQuery doSQLQuery(const QString &stringQuery);

    /*!
     * \brief Добавление нового пользователя в базу данных
     * \param[in] username Имя пользователя
     * \param[in] password Пароль пользователя
     * \return true, если добавление успешно; false в противном случае
     */
    bool addUser(const QString &username, const QString &password);

    /*!
     * \brief Проверка наличия пользователя в базе данных
     * \param[in] username Имя пользователя
     * \param[in] password Пароль пользователя
     * \return true, если пользователь найден; false в противном случае
     */
    bool checkUser(const QString &username, const QString &password);

    /*!
     * \brief Проверка, является ли пользователь администратором
     * \param[in] username Имя пользователя
     * \return true, если пользователь является администратором; false в противном случае
     */
    bool isAdmin(const QString &username);
};

#endif // DATABASE_H
