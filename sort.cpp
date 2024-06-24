#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        bool swapped = false;
        for (int j = 1; j < vec.size() - i; j++) {
            if (vec[j - 1] > vec[j]) {
                swap(vec[j - 1], vec[j]);
                swapped = true;
            }
        }
        if (!swapped) break; // 최적화: 교환이 이루어지지 않았다면 정렬 완료
    }
}

void insertionSort(vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

int main() {
    vector<int> numbers = { 64, 34, 25, 12, 22, 11, 90 };
    insertionSort(numbers); // or bubbleSort
    for (int num : numbers) {
        cout << num << " ";
    }

    return 0;
}