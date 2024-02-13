#include <iostream>

// Computes the sum of integers in the array
int calculateSum(int array[], int size) {
  int total = 0;
  for (int i = 0; i < size; i++) {
    total += array[i];
  }
  return total;
}

// Finds the largest integer in the array
int findMaximum(int array[], int size) {
  int maximum = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > maximum) {
      maximum = array[i];
    }
  }
  return maximum;
}

int main() {
  int size;
  std::cout << "Enter the length of the array: ";
  std::cin >> size;

  int array[size];
  for (int i = 0; i < size; i++) {
    std::cout << "Enter a number: ";
    std::cin >> array[i];
  }

  int sum = calculateSum(array, size);
  std::cout << "Summation: " << sum << "\n";

  int maximum = findMaximum(array, size);
  std::cout << "Maximum: " << maximum;

  return 0;
}
