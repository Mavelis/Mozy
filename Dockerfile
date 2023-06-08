# Установка базового образа
FROM ubuntu:latest

# Установка зависимостей и пакетов
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git

# Копирование исходного кода в контейнер
COPY . /app

# Переход в рабочую директорию
WORKDIR /app

# Сборка проекта
RUN cmake .
RUN make

# Запуск приложения
CMD ["./echoserver"]
