#include <iostream>
int log(int arr[], const int& size, int& input, int& size2);

int main() {
    const int size = 9;
    int size2 = size / 2;
    int input = 0, number = 0;
    int arr[size] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    std::cout << "Введите точку отсчёта: ";
    std::cin >> input;
    number = log(arr, size, input, size2);
    std::cout << "Количество элементов в массиве больших, чем " << input << ": " << number << std::endl;
}

int log(int arr[], const int& size, int& input, int& size2) {
    if (size2 == 0 && arr[size2] > input) {
        return size;
    }
    else if (arr[size2] > input && arr[size2 - 1] <= input) {
        return size - size2;
    }
    else if (size2 == (size - 1) || size2 == size) {
        return 0;
    }
    else if (arr[size2] <= input && arr[size2 + 1] > input) {
        return size - (size2 + 1);
    }
    else if (arr[size2] <= input) {
        size2 = ((size - size2) / 2) + size2;
        log(arr, size, input, size2);
    }
    else {
        size2 = size2 / 2;
        log(arr, size, input, size2);
    }
}