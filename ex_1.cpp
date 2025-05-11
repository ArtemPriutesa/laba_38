#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

// Функція для генерації випадкового масиву
template <typename T>
vector<T> imp_rand_arr(int size, T minValue, T maxValue) {
    vector<T> array(size);
    srand(static_cast<unsigned>(time(0))); // Ініціалізація генератора випадкових чисел
    for (auto& elem : array) {
        elem = minValue + rand() % (maxValue - minValue + 1); // Генерація числа в діапазоні
    }
    return array;
}

// Визначення кількості елементів рівних першому
template <typename T>
int elem(const vector<T>& array) {
    if (array.empty()) return 0;
    return count(array.begin(), array.end(), array[0]);
}

// Обмін значеннями двох елементів за індексами
template <typename T>
void swap_el(vector<T>& array, int index1, int index2) {
    if (index1 >= 0 && index1 < array.size() && index2 >= 0 && index2 < array.size()) {
        swap(array[index1], array[index2]);
    }
}

// Вставка заданого елемента у вказану позицію
template <typename T>
void insert_element(vector<T>& array, int position, T value) {
    if (position >= 0 && position <= array.size()) {
        array.insert(array.begin() + position, value);
    }
}

// Визначення найдовшої ділянки однакових елементів
template <typename T>
int longestEqualSegment(const vector<T>& array) {
    if (array.empty()) return 0;
    int maxLength = 1, currentLength = 1;
    for (size_t i = 1; i < array.size(); ++i) {
        if (array[i] == array[i - 1]) {
            ++currentLength;
            maxLength = max(maxLength, currentLength);
        } else {
            currentLength = 1;
        }
    }
    return maxLength;
}

// Сортування елементів між мінімальним і максимальним
template <typename T>
void sort_min_max(vector<T>& array) {
    if (array.size() < 2) return;
    auto minMax = minmax_element(array.begin(), array.end());
    int minIndex = distance(array.begin(), minMax.first);
    int maxIndex = distance(array.begin(), minMax.second);
    if (minIndex > maxIndex) swap(minIndex, maxIndex);
    sort(array.begin() + minIndex + 1, array.begin() + maxIndex);
}

int main() {
    // Приклад використання
    vector<int> array = imp_rand_arr<int>(10, 1, 100);

    cout << "Generated array: ";
    for (const auto& elem : array) cout << elem << " ";
    cout << endl;

    cout << "count first elem: " << elem(array) << endl;

    swap_el(array, 2, 5);
    cout << "swap 2 ,5: ";
    for (const auto& elem : array) cout << elem << " ";
    cout << endl;

    insert_element(array, 4, 26);
    cout << "26 na pos 4: ";
    for (const auto& elem : array) cout << elem << " ";
    cout << endl;

    cout << "Long segm: " << longestEqualSegment(array) << endl;

    sort_min_max(array);
    cout << "sort_min_max: ";
    for (const auto& elem : array) cout << elem << " ";
    cout << endl;

    return 0;
}