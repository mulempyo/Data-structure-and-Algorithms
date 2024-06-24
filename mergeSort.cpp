#include <iostream>
#include <vector>
//분할 정복: 위에서 아래로 쪼개 나감, 동적 계획법: 작은 부분에서 상위 문제로 나아감.
void merge(std::vector<int>& arr, int l, int m, int r) {
    std::vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    std::vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0;
    int j = 0;
    int k = l;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        arr[k++] = left[i++];
    }

    while (j < right.size()) {
        arr[k++] = right[j++];
    }
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    std::vector<int> data = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(data, 0, data.size() - 1);

    std::cout << "Sorted array: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}