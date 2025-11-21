#include <iostream>
using namespace std;

/*------------------------------------------------
Клас, що представляє сутність Двигуна
------------------------------------------------*/
class Engine {
private:
    int power; 
    int rpm;   
public:
    Engine(int power = 0, int rpm = 0); 
    ~Engine();


    int getPower();
    void setPower(int power);

    int getRPM();
    void setRPM(int rpm);

    void show();
};

Engine::Engine(int power, int rpm) : power(power), rpm(rpm) {}

Engine::~Engine() {
    cout << "Двигун знищений" << endl;
}

int Engine::getPower() { return power; }

void Engine::setPower(int power) { this->power = power; }

int Engine::getRPM() { return rpm; }

void Engine::setRPM(int rpm) { this->rpm = rpm; }

void Engine::show() {
    cout << "Двигун: Потужність = " << power << " Вт, Оберти = " << rpm << " об/хв" << endl;
}
