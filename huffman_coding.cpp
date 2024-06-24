#include <iostream>
#include <queue>
#include <vector>
#include <map>

// 허프만 트리 노드 구조체
struct HuffmanNode {
    char data;
    unsigned freq;
    HuffmanNode *left, *right;

    HuffmanNode(char data, unsigned freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// 비교 클래스 정의
struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return (l->freq > r->freq);
    }
};

// 허프만 코드를 저장하고 출력하는 함수
void printCodes(HuffmanNode* root, std::string str) {
    if (!root)
        return;
    if (root->data != '$')
        std::cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// 허프만 코드 트리를 구축하고 코드를 생성하는 함수
void HuffmanCoding(std::vector<char>& data, std::vector<int>& freq, int size) {
    struct HuffmanNode *left, *right, *top;

    // 우선순위 큐 생성
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> minHeap;

    // 모든 문자에 대한 노드를 생성하고 큐에 삽입
    for (int i = 0; i < size; ++i) {
        minHeap.push(new HuffmanNode(data[i], freq[i]));
    }

    // 트리를 생성하기 전까지 반복
    while (minHeap.size() != 1) {
        // 가장 작은 두 요소 추출
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        // 새 노드 생성, '$'는 내부 노드를 의미함
        top = new HuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // 재귀적으로 코드 생성
    printCodes(minHeap.top(), "");
}

int main() {
    std::vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::vector<int> freq = {5, 9, 12, 13, 16, 45};

    int size = data.size();
    HuffmanCoding(data, freq, size);

    return 0;
}
