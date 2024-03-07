// Separated from PIDController.cpp to enhance modularity
#include "PIDController.h"
#include <iostream>

int main() {
    PIDController controller(0.5, 0.1, 0.2, 100); // Example gains and target

    for (int i = 0; i < 10; ++i) {
        double measured_value = 90 + i * 5; // Simulated measured value
        double control_signal = controller.calculate(measured_value); // Calculate control signal
        std::cout << "Control Signal: " << control_signal << std::endl; // Output control signal
    }

    return 0;
}
