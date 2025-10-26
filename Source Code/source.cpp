#include <iostream>
#include <ctime>
#include <cstdlib>

inline void startingmsg();
inline int weathergen();
inline bool isobstacle();
inline bool malfunction();
inline void addminutes(int& hours, int& minutes , int add);
inline void rechargebattery(float& battery, int& hours, int& minutes);

void taketime(int& hours, int& minutes);
void takeloc(std::string& deliveryloc);
void delivery(float &battery, int &hours,int &minutes , std::string loc );

void main() {
    std::string  deliveryloc;
    float battery = 100;
    int weather , hours=0 , minutes=0;
    srand(time(0));

    startingmsg();

    taketime( hours , minutes );

    while( hours < 18 ) {
        
        takeloc(deliveryloc);
        if (deliveryloc == "null") {
            std::cout << "Shutting down all operations for the day.....\n";
            break;
        }

        delivery(battery, hours, minutes, deliveryloc);
        rechargebattery(battery, hours, minutes);
    }

    if (hours >= 18 ) {
        std::cout << "Drone charging time approaching......." << std::endl;
        std::cout << "Terminating all operations. " << std::endl;
    }

    std::cout << "Thanks for using. See you tomorrow - or not.";
}

inline void startingmsg() {
    std::cout << "---------------Delivery Drone---------------" << std::endl;
    std::cout << "-----An Initiative by IESE to deliver environmentally friendly utensils to the cafes.-----" << std::endl;
    std::cout << "Good Morning!" << std::endl;
    std::cout << "Let's start the day. \n\n" << std::endl;
}

inline int weathergen() {
    return rand() % 3 + 1;
}

inline bool isobstacle() {
    return rand() % 2;
}

inline bool malfunction() {
    if (rand() % 10 == 7) {
        return 1;
    }
    return 0;
}

inline void addminutes(int& hours, int& minutes , int add) {
    minutes = minutes + add;
    if (minutes >= 60) {
        minutes = minutes % 60;
        hours++;
    }
}

inline void rechargebattery(float& battery, int& hours, int& minutes) {
    while (battery < 30) {
        std::cout << "Low Battery.Recharging.....\n";
        battery += 5;
        addminutes(hours, minutes, 15);
        std::cout << "Battery: " << battery << "%" << std::endl;
        std::cout << "Time: " << hours << ":" << minutes << std::endl;
        if (hours >= 18 && minutes >= 0) {
            return;
        }
    }
}

void taketime(int& hours, int& minutes) {
    do {
        std::cout << "Enter the time in 24 hours format.\n" << std::endl;

        std::cout << "Hours:";
        std::cin >> hours;

        std::cout << "Minutes:";
        std::cin >> minutes;

    } while (hours < 0 || hours > 24 || minutes < 0 || minutes >= 60);
}

void takeloc(std::string& deliveryloc) {
    do {
        std::cout << "Enter the delivery location (C1,C2,C3): ";
        std::cin >> deliveryloc;

        if (deliveryloc != "C1" && deliveryloc != "C2" && deliveryloc != "C3" && deliveryloc != "null") {
            std::cout << "Invalid location. Enter again....\n";
        }

    } while (deliveryloc != "C1" && deliveryloc != "C2" && deliveryloc != "C3" && deliveryloc != "null");
}

void delivery(float& battery, int& hours, int& minutes , std::string loc) {
    bool obstacle= isobstacle();
    int weather = weathergen(); // 1 = sunny , 2 = windy , 3 = rainy

    if (weather == 1) {
        std::cout << "Weather: Sunny" << std::endl;
    }
    else if (weather == 2) {
        std::cout << "Weather: Windy\n";
        if (battery < 40) {
            do {
                if (hours >= 18 && minutes >= 0) {
                    return;
                }
                std::cout << "Battery Low.\nCurrent Battery:" << battery << "\nReacharging.....\n";
                addminutes(hours, minutes, 30);
                if (battery + 10 >= 100) {
                    battery = 100;
                }
                else {
                    battery += 10;
                }
            } while (battery < 40);
            std::cout << "Battery charged to sufficent level.\n";
            std::cout << "Battery: " << battery << "%\n";
            std::cout << "Delivering......\n";
        }
        battery -= 5;
        addminutes(hours, minutes, 10);
    }
    else if (weather == 3) {
        do {
            if (hours >= 18 && minutes >= 0) {
                return;
            }
            std::cout << "Weather:Rainy\nDelivery Delayed.\nWaiting for 1 hour and recharging.....\n";
            addminutes(hours, minutes, 60);
            if (battery + 20 >= 100) {
                battery = 100;
            }
            else {
                battery += 20;
            }
            weather = weathergen();
        } while (weather == 3);
        std::cout << "Weather clear. Taking off and delivering........\n";
    }
    std::cout << "Battery: " << battery << "%" << std::endl;
    std::cout << "Time: " << hours << ":" << minutes << "\n" << std::endl;

    if (obstacle) {
        std::cout << "Obstacle Detected. Rerouting.....\n";
        battery -= 10;
        addminutes(hours, minutes, 5);
    }
    std::cout << "Battery: " << battery << "%" << std::endl;
    std::cout << "Time: " << hours << ":" << minutes << "\n" << std::endl;

    if (loc == "C1") {
        battery -= 10;
        addminutes(hours, minutes, 15);
    }
    else if (loc == "C2") {
        battery -= 20;
        addminutes(hours, minutes, 25);
    }
    else if (loc == "C3") {
        battery -= 25;
        addminutes(hours, minutes, 45);
    }

    std::cout << "Delivery Successfull.\n";
    std::cout << "Battery: " << battery << "%" << std::endl;
    std::cout << "Time: " << hours << ":" << minutes << "\n" << std::endl;
}