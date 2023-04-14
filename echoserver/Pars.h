#ifndef pars.h
#define pars.h

#include <QCoreApplication>
#include <QString>

QByteArray parse(QString request);
QString auth(QString login, QString password);
QString regist(QString login, QString password);
QString getStart();
QString getTask(int type);
QString checkTask(int id, int answer);
#endif
