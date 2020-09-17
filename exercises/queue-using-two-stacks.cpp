// https://www.hackerrank.com/challenges/queue-using-two-stacks/submissions/code/151095592

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class MyQueue {
    public: 
        void enqueue(T item) {
            // transfer(popStack, pushStack);
            pushStack.push_back(item);
        }

        T dequeue() {
            if(popStack.empty()) {
                transfer(pushStack, popStack);
            }
            T item = popStack.back();
            popStack.pop_back();
            return item;
        }

        T front() {
            if(popStack.empty()) {
                transfer(pushStack, popStack);
            }
            return popStack.back();
        }

    private:
        void transfer(vector<T> &sourceStack, vector<T> &destStack) {
            for (; !sourceStack.empty(); sourceStack.pop_back()) {
                T item = sourceStack.back();
                destStack.push_back(item);
            }
        }

        vector<T> pushStack;
        vector<T> popStack;

};

class Processor{
    private:
        MyQueue<int> queue;

    public:
        void enqueue(int item) { queue.enqueue(item); }
        void dequeue() { queue.dequeue(); }
        void print() { cout << queue.front() << endl; }
};

int main() {
    Processor processor;
    int command;
    while(cin >> command) {
        switch(command) {
            case 1:
                int item;
                cin >> item;
                processor.enqueue(item);
                break;

            case 2:
                processor.dequeue();
                break;

            case 3:
                processor.print();
        }
    }
    
    return 0;
}
