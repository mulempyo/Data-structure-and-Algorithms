#include <iostream>
#include <cstdlib> // for qsort
//qsort()는 분할 정복 방법을 씁니다.
/* 
void qsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*));
base는 정렬할 배열의 시작 주소입니다.
num은 배열의 원소 수입니다.
size는 배열의 각 원소의 크기를 바이트 단위로 나타냅니다.
compar는 비교 함수의 포인터로, 정렬 순서를 결정하는 데 사용됩니다
 */

// 비교 함수
int compare(const void* a, const void* b) {
    const int* x = (const int*)a;
    const int* y = (const int*)b;
    if (*x < *y) {
        return -1;
    }
    else if (*x > *y) {
        return 1;
    }
    return 0;
}

int main() {
    int numbers[] = { 10, 80, 30, 90, 40, 50, 70 };
    int n = sizeof(numbers) / sizeof(numbers[0]);

    qsort(numbers, n, sizeof(int), compare);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}