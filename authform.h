#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>
#include <QDebug>
#include <QLineEdit>

namespace Ui {
    class AuthForm;
}

/**
 * @brief Класс AuthForm представляет форму для аутентификации и регистрации пользователя.
 */
class AuthForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструирует объект класса AuthForm.
     * @param parent Родительское окно.
     */
    explicit AuthForm(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса AuthForm.
     */
    ~AuthForm();

private slots:
    /**
     * @brief Обрабатывает событие нажатия кнопки "Выход".
     */
    void on_pushButton_exit_clicked();

    /**
     * @brief Обрабатывает событие нажатия кнопки "Изменить".
     */
    void on_pushButton_change_clicked();

    /**
     * @brief Обрабатывает событие нажатия кнопки "Регистрация".
     */
    void on_pushButton_reg_clicked();

    /**
     * @brief Обрабатывает событие нажатия кнопки "Вход".
     */
    void on_pushButton_auth_clicked();

    /**
     * @brief Проверяет доступность кнопок на основе заполненности полей.
     */
    void check_buttons_enabled();

private:
    Ui::AuthForm *ui; /**< Объект пользовательского интерфейса. */

    /**
     * @brief Изменяет режим формы (аутентификация или регистрация).
     * @param mode Режим (true для регистрации, false для аутентификации).
     */
    void change_mode(bool mode);

signals:
    /**
     * @brief Сигнал, испускаемый при закрытии формы.
     * @param log Информация о логине.
     */
    void closed(const QString& log);
};

#endif // AUTHFORM_H
