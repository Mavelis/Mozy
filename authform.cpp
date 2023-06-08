#include "authform.h"
#include "ui_authform.h"

/**
 * @brief Конструирует объект класса AuthForm.
 * @param parent Родительское окно.
 */
AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    ui->setupUi(this);
    this->change_mode(true);

    // Изначально кнопки неактивны
    ui->pushButton_auth->setEnabled(false);
    ui->pushButton_reg->setEnabled(false);

    // Связываем сигналы изменения текста в полях с проверкой активности кнопок
    connect(ui->lineEdit_log, &QLineEdit::textChanged, this, &AuthForm::check_buttons_enabled);
    connect(ui->lineEdit_pass, &QLineEdit::textChanged, this, &AuthForm::check_buttons_enabled);
    connect(ui->lineEdit_mail, &QLineEdit::textChanged, this, &AuthForm::check_buttons_enabled);
}

/**
 * @brief Изменяет режим отображения элементов формы.
 * @param mode Режим (true - режим регистрации, false - режим входа).
 */
void AuthForm::change_mode(bool mode)
{
    ui->label_mail->setVisible(!mode);
    ui->lineEdit_mail->setVisible(!mode);
    ui->pushButton_auth->setVisible(mode);
    ui->pushButton_reg->setVisible(!mode);

    if (mode)
        ui->pushButton_change->setText("Регистрация");
    else
        ui->pushButton_change->setText("Вход");
}

/**
 * @brief Проверяет активность кнопок в зависимости от заполненности полей ввода.
 */
void AuthForm::check_buttons_enabled()
{
    bool enable = !ui->lineEdit_log->text().isEmpty() && !ui->lineEdit_pass->text().isEmpty();
    ui->pushButton_auth->setEnabled(enable);
    ui->pushButton_reg->setEnabled(enable);
}

/**
 * @brief Обрабатывает событие нажатия кнопки смены режима.
 */
void AuthForm::on_pushButton_change_clicked()
{
    this->change_mode(ui->pushButton_reg->isVisible());
    check_buttons_enabled(); // Проверяем активность кнопок после смены режима
}

/**
 * @brief Обрабатывает событие нажатия кнопки "Выход".
 */
void AuthForm::on_pushButton_exit_clicked()
{
    this->close();
}

/**
 * @brief Обрабатывает событие нажатия кнопки "Регистрация".
 */
void AuthForm::on_pushButton_reg_clicked()
{
    qDebug() << "reg " << ui->lineEdit_log->text() <<
                " " << ui->lineEdit_pass->text() <<
                " " << ui->lineEdit_mail->text();
    this->on_pushButton_change_clicked();
}

/**
 * @brief Обрабатывает событие нажатия кнопки "Вход".
 */
void AuthForm::on_pushButton_auth_clicked()
{
    qDebug() << "auth " << ui->lineEdit_log->text() <<
                " " << ui->lineEdit_pass->text();
    emit closed(ui->lineEdit_log->text());
    this->close();
}

/**
 * @brief Деструктор класса AuthForm.
 */
AuthForm::~AuthForm()
{
    delete ui;
}
