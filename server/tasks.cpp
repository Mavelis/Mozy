#include "tasks.h"

QString to_binary(int n, int bits) {

    int roundedBits = bits;
        if (bits % (1 << n) != 0) {
            roundedBits = ((bits >> n) + 1) << n;
        }

    QString res;
    for (int i = bits - 1; i >= 0; i--) {
        res += (n & (1 << i)) ? '1' : '0';
    }
    return res;
}
int twoToRandomPower() {
    int value = QRandomGenerator::global()->bounded(2, 5);
    return qPow(1, value);
    if (value < 10)
            return 4; // Возвращаем 4, если значение меньше 10
        else if (value < 100)
            return 8; // Возвращаем 8, если значение между 10 и 100
        else
            return 16; // Возвращаем 16 для остальных значений
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
    int roundedSize = (1 << n);

        if (f.size() != roundedSize) {
            f.resize(roundedSize, false);
        }
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
    int roundedSize = (1 << n);

        if (f.size() != roundedSize) {
            return false; // Размер вектора не является кратным 2^n, функция не может быть монотонной
        }

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
    int roundedSize = 1 << static_cast<int>(std::ceil(std::log2(n)));

        if (n != roundedSize) {
            return false; // Размер вектора не является кратным 2^n, функция не может быть самодвойственной
        }

    for (int i = 0; i < n / 2; ++i) {
        if (f[i] == f[n - i - 1]) {
            return false;
        }
    }

    return true;
}

QString generateTuringSequence() {
    // Генерация случайного числа от 1 до 5
    int length = QRandomGenerator::global()->bounded(1, 6);

    // Создание строковой последовательности '1' заданной длины
    QString sequence = QString("1").repeated(length);

    // Выбор случайного состояния машины и символа для обозначения пустого места
    QString state = QRandomGenerator::global()->bounded(2) ? "q1" : "q0";
    QString emptySymbol = QRandomGenerator::global()->bounded(2) ? "E" : "1";

    // Добавление состояния машины и символа для обозначения пустого места к последовательности
    sequence.append(state);
    sequence.append(emptySymbol);

    return sequence;
}


QString TuringMachineA(QString sequence) {
    QString state;
    int position = 0;

    // Находим начальное состояние 'q1' во входной последовательности
    position = sequence.indexOf('q');
    if (position == -1) return sequence; // Если 'q' не найден, возвращаем исходную последовательность
    state = sequence.mid(position, 2); // Считываем состояние ('q0' или 'q1')

    while(position < sequence.length()) {
        if(state == "q1") {
            if(sequence.at(position+2) == '1') { // Смещаемся на две позиции вправо от состояния 'q1'
                state = "q0";
                sequence.replace(position, 2, state); // Заменяем состояние 'q1' на 'q0'
                position++;
            } else {
                break;
            }
        } else if(state == "q0") {
            break;
        }
    }

    return sequence;
}


QString TuringMachineB(QString sequence) {
    QString state;
    int position = 0;

    // Находим начальное состояние 'q1' во входной последовательности
    position = sequence.indexOf('q');
    if (position == -1) return sequence; // Если 'q' не найден, возвращаем исходную последовательность
    state = sequence.mid(position, 2); // Считываем состояние ('q0' или 'q1')

    while(position >= 0) {
        if(state == "q1") {
            if(sequence.at(position+2) == '1') { // Смещаемся на две позиции влево от состояния 'q1'
                sequence.replace(position+2, 1, "E"); // Заменяем '1' на 'E'
                state = "q0";
                sequence.replace(position, 2, state); // Заменяем состояние 'q1' на 'q0'
                position--;
            } else {
                break;
            }
        } else if(state == "q0") {
            break;
        }
    }

    return sequence;
}

QVariantMap Task1() {
    QVariantMap task;
    int length = twoToRandomPower();
    std::vector<bool> functionValues = randomFunctionValues(length);
    bool answer = isLinear(functionValues);
    task["text"] = QString("Проверить, является ли функция, заданная вектором значений, линейной: %1").arg(vectorToString(functionValues));
    task["answer"] = (answer) ? "1" : "0";
    return task;
}

QVariantMap Task2() {
    QVariantMap task;
    int length = twoToRandomPower();
    std::vector<bool> functionValues = randomFunctionValues(length);
    bool answer = isMonotone(functionValues);
    task["text"] = QString("Проверить, является ли функция, заданная вектором значений, монотонной: %1").arg(vectorToString(functionValues));
    task["answer"] = (answer) ? "1" : "0";
    return task;
}

QVariantMap Task3() {
    QVariantMap task;
    int length = twoToRandomPower();
    std::vector<bool> functionValues = randomFunctionValues(length);
    bool answer = isSelfDual(functionValues);
    task["text"] = QString("Проверить, является ли функция, заданная вектором значений, самодвойственной: %1").arg(vectorToString(functionValues));
    task["answer"] = (answer) ? "1" : "0";
    return task;
}

QVariantMap Task4() {
    QVariantMap task;
    QString sequence = generateTuringSequence();
    task["text"] = QString("Дана последовательность %1. Программа для машины Тьюринга: (1, q1) -> (1, П, q0), вычислить результат применения").arg(sequence);
    task["answer"] = TuringMachineA(sequence);
    return task;
}

QVariantMap Task5() {
    QVariantMap task;
    QString sequence = generateTuringSequence();
    task["text"] = QString("Дана последовательность %1. Программа для машины Тьюринга: (1, q1) -> (E, Л, q0), вычислить результат применения").arg(sequence);
    task["answer"] = TuringMachineB(sequence);
    return task;
}
