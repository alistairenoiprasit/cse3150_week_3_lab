#include "../include/logger.h"
#include <string>
#include <iostream>

// ======================= TODOs =======================

void addReading(const std::string& label, double value,
                std::string labels[], double values[],
                int& size, int capacity) {
    if (size==capacity) {
        throw std::string("Full");
    }

    labels[size] = label;
    values[size] = value;
    size++;
}

void updateValue(double* valuePtr, double newValue) {
    *valuePtr = newValue;
}

void printReading(const std::string& label, const double& value) {
    std::cout << label << ": " << value << std::endl;
}

void checkEmpty(int size) {
    if (size==0) {
        throw std::string("Empty");
    }
}

double average(const double values[], int size) {
    checkEmpty(size);
    double sum = 0.0;
    for (int i=0; i<size; i++) {
        sum += values[i];
    }
    return sum / static_cast<double>(size);
}

double minValue(const double values[], int size) {
    checkEmpty(size);

    double min = values[0];
    for (int i=1; i<size; i++) {
        if (values[i] < min) {
            min = values[i];
        }
    }
    return min;
}

double maxValue(const double values[], int size) {
    checkEmpty(size);
    double max = values[0];
    for (int i=1; i<size; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    return max;
}
