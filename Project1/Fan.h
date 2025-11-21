#include "Engine.h"
#include "Controller.h"
#include "RemoteControl.h"

/*------------------------------------------------
Клас, що представляє сутність Вентилятора
------------------------------------------------*/
class Fan {
private:
    Engine& engine;          
    Controller& controller;   
    RemoteControl& remote;    
public:
    Fan(Engine& engine, Controller& controller, RemoteControl& remote); 
    ~Fan(); 

    void adjustFanSpeed();
    void turnOffAfterTime();
    void show();
};

Fan::Fan(Engine& engine, Controller& controller, RemoteControl& remote)
    : engine(engine), controller(controller), remote(remote) {}

Fan::~Fan() {
    cout << "Вентилятор знищений" << endl;
}

void Fan::adjustFanSpeed() {
    if (controller.getIsOn()) {
        remote.adjustRPM(engine);
    }
    else {
        cout << "Вентилятор вимкнено, неможливо налаштувати швидкість." << endl;
    }
}

void Fan::turnOffAfterTime() {
    if (controller.getIsOn()) {
        remote.autoTurnOff(controller);
    }
    else {
        cout << "Вентилятор вже вимкнено." << endl;
    }
}

void Fan::show() {
    cout << "Стан Вентилятора:" << endl;
    engine.show();
    controller.show();
    remote.show();
}
