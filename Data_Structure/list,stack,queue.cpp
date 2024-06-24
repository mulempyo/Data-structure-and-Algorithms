#include <iostream>
#include <list>
#include <stack>
#include <queue>

int main() {
    std::list<int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    for (const int& element : myList) {
        std::cout << element << " " << std::endl;
    }
    std::cout << "list end" << std::endl;

    std::stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    while (!myStack.empty()) {
        std::cout << myStack.top() << " " << std::endl;
        myStack.pop();
    }
    std::cout << "stack end" << std::endl;
    std::queue<int> myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " " << std::endl;
        myQueue.pop();
    }
    std::cout << "queue end" << std::endl;

    return 0;
}