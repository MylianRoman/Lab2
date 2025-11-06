#include <iostream>
#include <thread>
#include <chrono> 
using namespace std;

/*------------------------------------------------
Клас, що представляє сутність Пульта Керування
------------------------------------------------*/
class RemoteControl {
private:
    int speed; 
    int turnOffTime;
public:
    RemoteControl(int speed = 0, int turnOffTime = 0);
    ~RemoteControl();

    int getSpeed();
    void setSpeed(int speed);

    int getTurnOffTime();
    void setTurnOffTime(int turnOffTime);

    void show();

    void adjustRPM(Engine& engine);

    void autoTurnOff(Controller& controller);
};

RemoteControl::RemoteControl(int speed, int turnOffTime) : speed(speed), turnOffTime(turnOffTime) {}

int RemoteControl::getSpeed() { return speed; }

void RemoteControl::setSpeed(int speed) { this->speed = speed; }

int RemoteControl::getTurnOffTime() { return turnOffTime; }

void RemoteControl::setTurnOffTime(int turnOffTime) { this->turnOffTime = turnOffTime; }

RemoteControl::~RemoteControl() {
    cout << "Пульт Керування знищений" << endl;
}
void RemoteControl::show() {
    cout << "Пульт Керування: Швидкість = " << speed << ", Час до вимкнення = " << turnOffTime << " сек" << endl;
}

void RemoteControl::adjustRPM(Engine& engine) {
    int newRPM = speed * 500; 
    engine.setRPM(newRPM);    
    cout << "Оберти двигуна встановлені на " << newRPM << " об/хв" << endl;
}


void RemoteControl::autoTurnOff(Controller& controller) {
    cout << "Вентилятор вимкнеться через " << turnOffTime << " сек..." << endl;
    this_thread::sleep_for(chrono::seconds(turnOffTime)); 
    controller.setIsOn(false); 
    cout << "Вентилятор вимкнено" << endl;
}
