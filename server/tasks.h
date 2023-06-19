#pragma once
#ifndef TASKS_H
#define TASKS_H
#include <QVariant>
#include <QRandomGenerator>
#include <QtMath>
/*!
 * \brief Класс заданий
*/

/*!
 * \brief Функция, генерирующее задание на проверку, является ли функция, заданная вектором значений, линейной
 * \return Структуру задания, содержащую поля text и answer
 */
QVariantMap Task1();
/*!
 * \brief Функция, генерирующее задание на проверку, является ли функция, заданная вектором значений, монотонной
 * \return Структуру задания, содержащую поля text и answer
 */
QVariantMap Task2();
/*!
 * \brief Функция, генерирующее задание на проверку, является ли функция, заданная вектором значений, самодвойственной
 * \return Структуру задания, содержащую поля text и answer
 */
QVariantMap Task3();
/*!
 * \brief Функция, генерирующее задание 4
 * \return Структуру задания, содержащую поля text и answer
 */
QVariantMap Task4();
/*!
 * \brief Функция, генерирующее задание 5
 * \return Структуру задания, содержащую поля text и answer
 */
QVariantMap Task5();

#endif // TASKS_H
