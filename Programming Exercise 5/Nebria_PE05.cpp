#include <iostream>

using namespace std;

const int MAX_SIZE = 10; //Define the maximum size of the array

// Function to calculate the square root using the Newton-Raphson method
double sqroot(double x) {
    double epsilon = 0.00001;//precision
    double guess = x / 2.0;//initial guess
    while (abs(guess * guess - x) >= epsilon) { //Loop until the guess is close enough to the square root
        guess = (guess + x / guess) / 2.0;//update guess
    }
    return guess;//Return the calculated square root
}

// Function to get user input and store in array
void data(int num[], int& size) {
    size = 0;//Initialize the size of the array

    // Display program information
    cout << "Programming Exercise 05" << endl;
    cout << "Submitted by: Quennie A. Nebria" << endl;
    cout << "================================================================================================================================" << endl;
    cout << "This program will ask the user to input various numbers (positive or negative but not zero) and perform basic statistics on these numbers." << endl;
    while (size < MAX_SIZE) {
        cout << "Input an integer: ";
        cin >> num[size];
        if (num[size] == 0) break;
        size++;
    }
}

// Function to find the largest number in the array
int largestNum(const int num[], int size) {
    int largest = num[0];//Initialize the largest number
    //Loop through the array to find the largest number
    for (int i = 1; i < size; i++) {
        if (num[i] > largest) largest = num[i];//Update the largest number if a larger one is found
    }
    return largest; //Return the largest number
}

// Function to find the smallest number in the array
int smallestNum(const int num[], int size) {
    int smallest = num[0];//Initialize the smallest number
    //Loop through the array to find the smallest number
    for (int i = 1; i < size; i++) {
        if (num[i] < smallest) smallest = num[i];//Update the smallest number if a smaller one is found
    }
    return smallest;//Return the smallest number
}

// Function to calculate the average of the numbers in the array
double getAverage(const int num[], int size) {
    double sum = 0.0;//Initialize sum
    //Loop through the array to calculate the sum of the numbers
    for (int i = 0; i < size; i++) {
        sum += num[i];//Add each number to the sum
    }
    return sum / size;//Return the average by dividing the sum by the size of the array
}

// Function to calculate the variance of the numbers in the array
double getVariance(const int num[], int size, double average) {
    double sum = 0.0;//Initialize the sum
    //Loop through the array to calculate the sum of the squared differences from the average
    for (int i = 0; i < size; i++) {
        sum += (num[i] - average) * (num[i] - average);//Add the squared difference to the sum
    }
    return sum / size;//Return the variance by dividing the sum by the size of the array
}

// Function to calculate the standard deviation of the numbers in the array
double getStandardDeviation(double variance) {
    return sqroot(variance);//Return the square root of the variance
}

// Function to display the results
void displayResults(int largest, int smallest, double average, double standardDeviation, double variance) {
    //Display the results
    cout << "Largest = " << largest << endl;
    cout << "Smallest = " << smallest << endl;
    cout << "Average = " << average << endl;
    cout << "Standard deviation = " << standardDeviation << endl;
    cout << "Variance = " << variance << endl;
}

int main() {
    int num[MAX_SIZE];
    int size;
    data(num, size);

    //Calculate the largest, smallest, average, variance, and standard deviation of the numbers
    int largest = largestNum(num, size);
    int smallest = smallestNum(num, size);
    double average = getAverage(num, size);
    double variance = getVariance(num, size, average);
    double standardDeviation = getStandardDeviation(variance);

    //Display the results
    displayResults(largest, smallest, average, standardDeviation, variance);

    return 0;
}
