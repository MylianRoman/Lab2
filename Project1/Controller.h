#pragma once
#include <iostream>
using namespace std;

/*------------------------------------------------
Клас, що представляє сутність Контролера
------------------------------------------------*/
class Controller {
private:
    bool isOn; 
public:
    Controller(bool isOn = false); 
    ~Controller(); 

    bool getIsOn();
    void setIsOn(bool isOn);

    void show();
};

Controller::Controller(bool isOn) : isOn(isOn) {}

Controller::~Controller() {
    cout << "Контролер знищений" << endl;
}

bool Controller::getIsOn() { return isOn; }

void Controller::setIsOn(bool isOn) { this->isOn = isOn; }

void Controller::show() {
    cout << "Контролер: Стан = " << (isOn ? "Ввімкнено" : "Вимкнено") << endl;
}
