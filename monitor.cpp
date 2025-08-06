#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void DisplayAlert(const char* message) {
    cout << message << "\n";
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

bool isTemperatureOk(float temperature) {
    return (temperature >= 95 && temperature <= 102);
}

bool isPulseRateOk(float pulseRate) {
    return (pulseRate >= 60 && pulseRate <= 100);
}

bool isSpo2Ok(float spo2) {
    return (spo2 >= 90);
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    if (!isTemperatureOk(temperature)) {
        DisplayAlert("Temperature is critical!");
        return 0;
    }
    if (!isPulseRateOk(pulseRate)) {
        DisplayAlert("Pulse Rate is out of range!");
        return 0;
    }
    if (!isSpo2Ok(spo2)) {
        DisplayAlert("Oxygen Saturation out of range!");
        return 0;
    }
    return 1;
}