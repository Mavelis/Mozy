#include <stdio.h>
#include "Pars.h""
#include <QDebug>
#include <QCoreApplication>



QByteArray parse(QString request) {
    request.chop(2);
    QString data = QString::fromStdString(request.toStdString());
    QStringList list = data.split(" ");
    QString response;
    if (list[0] == QString("auth")) {
        response = auth(list[1], list[2]);
    }
    else if (list[0] == QString("regist")) {
        response = regist(list[1], list[2]);
    }
    else if (list[0] == QString("gettask")) {
        response = getTask(list[1].toInt());
    }
    else if (list[0] == QString("checktask")) {
        response = checkTask(list[1].toInt(), list[1].toInt());
    }
    else if (list[0] == QString("getstart")) {
        response = getStart();
    }
    else response = "Неверный синтаксис, попробуйте ещё раз";
    return QByteArray((response + "\r\n").toUtf8());
}

QString auth(QString login,QString password){
    return QString("Авторизация с помощью логина% 1 и пароля% 2").arg(login).arg(password);
}
QString regist(QString login,QString password){
    return QString("Регистрация с использованием логина% 1 и пароля% 2").arg(login).arg(password);
}
QString getStart(){
    return QString("Statictins");
}
QString getTask(int type){
    return QString("type %1").arg(type);
}
QString checkTask(int id, int answer){
    return QString("Проверьте номер задания% 1 с ответом% 2").arg(id).arg(answer);
}
