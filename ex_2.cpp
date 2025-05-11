#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
using namespace std;

template <typename T>
class Vector10 {
private:
    vector<T> data;

public:
    // Конструктор за замовчуванням
    Vector10() : data(10, T()) {}
    // Параметризований конструктор
    Vector10(const vector<T>& vec) {
        if (vec.size() == 10) {
            data = vec;
        } else {
            throw invalid_argument("eror.");
        }
    }
    // Метод для введення інформації з клавіатури
    void inputFromKeyboard() {
        cout << "Enter 10 elements: ";
        for (int i = 0; i < 10; ++i) {
            cin >> data[i];
        }
    }
    //rand
    void inputRandom(T minValue, T maxValue) {
        srand(static_cast<unsigned>(time(0)));
        for (auto& elem : data) {
            elem = minValue + rand() % (maxValue - minValue + 1);
        }
    }
    // print
    void print() const {
        for (const auto& elem : data) {
            cout << elem << " ";
        }
        cout << endl;
    }
    // розміщення
    void placing() {
        vector<T> even, odd;
        for (size_t i = 0; i < data.size(); ++i) {
            if (i % 2 == 0) {
                even.push_back(data[i]);
            } else {
                odd.push_back(data[i]);
            }
        }
        copy(even.begin(), even.end(), data.begin());
        copy(odd.begin(), odd.end(), data.begin() + even.size());
    }
    // Метод для видалення елементів масиву із вказаним значенням
    void del_elem(T value) {
        data.erase(remove(data.begin(), data.end(), value), data.end());
        while (data.size() < 10) {
            data.push_back(T()); 
        }
    }
    // Перевантаження операції +
    Vector10 operator+(const Vector10& other) const {
        Vector10 result;
        for (size_t i = 0; i < 10; ++i) {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }
    // Перевантаження операції ++ 
    Vector10& operator++() {
        for (auto& elem : data) {
            elem += 10;
        }
        return *this;
    }
    // Перевантаження операції >, <, <=, ==
    bool operator>(const Vector10& other) const {
        return accumulate(data.begin(), data.end(), T()) >
               accumulate(other.data.begin(), other.data.end(), T());
    }
    bool operator<(const Vector10& other) const {
        return accumulate(data.begin(), data.end(), T()) <
               accumulate(other.data.begin(), other.data.end(), T());
    }
    bool operator<=(const Vector10& other) const {
        return !(*this > other);
    }
    bool operator==(const Vector10& other) const {
        return accumulate(data.begin(), data.end(), T()) ==
               accumulate(other.data.begin(), other.data.end(), T());
    }
};

int main() {
    Vector10<int> vec1;
    vec1.inputRandom(1, 100);
    cout << "Random vector: ";
    vec1.print();

    Vector10<int> vec2;
    vec2.inputFromKeyboard();
    cout << "Keyboard input vector: ";
    vec2.print();

    Vector10<int> sumVec = vec1 + vec2;
    cout << "Sum of vectors: ";
    sumVec.print();

    ++vec1;
    cout << "Vector1 after increment: ";
    vec1.print();

    vec1.placing();
    cout << "Vector1 after rearrange: ";
    vec1.print();

    vec1.del_elem(50);
    cout << "del 50: ";
    vec1.print();

    cout << "Comparison (vec1 > vec2): " << (vec1 > vec2) << endl;

    return 0;
}