#include "tasks.h"

QString to_binary(int n, int bits) {
    QString res;
    for (int i = bits - 1; i >= 0; i--) {
        res += (n & (1 << i)) ? '1' : '0';
    }
    return res;
}
int twoToRandomPower() {
    int value = QRandomGenerator::global()->bounded(2, 4);
    return qPow(2, value);
}

std::vector<bool> randomFunctionValues(int length) {
    std::vector<bool> function_values;
    for (int i=0; i < length+1; i++) {
        function_values.push_back(QRandomGenerator::global()->generateDouble() > 0.5);
    }
    return function_values;
}

QString vectorToString(std::vector<bool> functionValues) {
    QString result;
    for (auto value: functionValues) {
        result += value ? '1' : '0';
    }
    return result;
}

bool isLinear(std::vector<bool> f) {
    int n = std::log2(f.size());
    std::vector<bool> F(f.size(), 0);

    // Преобразование Фурье
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            if ((i & j) == j) {
                F[i] = F[i] ^ f[j];
            }
        }
    }

    // Проверяем, что только два значения отличны от нуля
    int count = 0;
    for (int i = 0; i < (1 << n); ++i) {
        if (F[i]) {
            ++count;
            if (count > 2) {
                return false;
            }
        }
    }

    return count == 2;
}


bool isMonotone(const std::vector<bool>& f) {
    int n = std::log2(f.size());

    for (int i = 0; i < (1 << n); ++i) {
        for (int j = i + 1; j < (1 << n); ++j) {
            // Если i - подмножество j и f(i) > f(j), то функция не монотонна
            if ((i & j) == i && f[i] > f[j]) {
                return false;
            }
        }
    }

    return true;
}

bool isSelfDual(const std::vector<bool>& f) {
    int n = f.size();

    for (int i = 0; i < n / 2; ++i) {
        if (f[i] == f[n - i - 1]) {
            return false;
        }
    }

    return true;
}



QVariantMap Task1() {
    QVariantMap task;
    int length = twoToRandomPower();
        std::vector<bool> functionValues = randomFunctionValues(length);
        qDebug() << functionValues;
        bool answer = isLinear(functionValues);
    task["text"] = QString("Проверить, является ли функция, заданная вектором значений, линейной: %1").arg(vectorToString(functionValues));
    task["answer"] = (answer) ? "1":"0";
    return task;
}


QVariantMap Task2() {
    QVariantMap task;
    int length = twoToRandomPower();
        std::vector<bool> functionValues = randomFunctionValues(length);
        qDebug() << functionValues;
        bool answer = isMonotone(functionValues);
    task["text"] = QString("Проверить, является ли функция, заданная вектором значений, монотонной: %1").arg(vectorToString(functionValues));
    task["answer"] = (answer) ? "1":"0";
    return task;
}

QVariantMap Task3() {
    QVariantMap task;
    int length = twoToRandomPower();
        std::vector<bool> functionValues = randomFunctionValues(length);
        qDebug() << functionValues;
        bool answer = isSelfDual(functionValues);
    task["text"] = QString("Проверить, является ли функция, заданная вектором значений, самодвойственной: %1").arg(vectorToString(functionValues));
    task["answer"] = (answer) ? "1":"0";
    return task;
}

QVariantMap Task4() {
    QVariantMap task;

    task["text"] = QString("Пример задания №4");
    task["answer"] = "answer";
    return task;
}

QVariantMap Task5() {
    QVariantMap task;

    task["text"] = QString("Пример задания №5");
    task["answer"] = "answer";
    return task;
}
