#include "Fan.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Engine engine(100, 1500);      // Двигун з потужністю 100 Вт і 1500 об/хв
    Controller controller(true);   // Контролер ввімкнено
    RemoteControl remote(3, 5);    // Швидкість 3 і вимкнення через 5 секунд

    Fan fan(engine, controller, remote);

    // Виводимо стан вентилятора
    fan.show();

    // Налаштовуємо оберти двигуна через пульт
    fan.adjustFanSpeed();

    // Встановлюємо час до вимкнення вентилятора
    fan.turnOffAfterTime();

    // Виводимо фінальний стан вентилятора
    fan.show();

    return 0;
}
