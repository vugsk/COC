#! /bin/bash

echo "Запуск"
cmake .

echo "Сборка"
make -j4

echo "Установка"
sudo make install

echo "Готова"
