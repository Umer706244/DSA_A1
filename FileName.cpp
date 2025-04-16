//#include <iostream>
//using namespace std;
//
//const int Max = 100;
//
//class PrioritydroneStack {
//private:
//    int ids[Max];
//    int priorities[Max];
//    int top;
//
//public:
//    PrioritydroneStack() : top(-1) {
//        for (int i = 0; i < Max; ++i) {
//            ids[i] = 0;
//            priorities[i] = 0;
//        }
//    }
//
//    bool isEmpty() {
//        return top == -1;
//    }
//
//    bool isFull() {
//        return top == Max - 1;
//    }
//
//    void push(int id, int priority) {
//        if (!isFull()) {
//            ids[++top] = id;
//            priorities[top] = priority;
//        }
//        else {
//            cout << "Stack is full.\n";
//        }
//    }
//
//    void dispatchHighestPriority(int& id, int& priority) {
//        if (isEmpty()) {
//            id = -1;
//            priority = -1;
//            cout << "No drones is dispatch.\n";
//            return;
//        }
//
//        
//        int maxIndex = 0;
//        for (int i = 1; i <= top; ++i) {
//            if (priorities[i] > priorities[maxIndex]) {
//                maxIndex = i;
//            }
//        }
//
//        
//        id = ids[maxIndex];
//        priority = priorities[maxIndex];
//
//        
//       for (int i = maxIndex; i < top; ++i) {
//            ids[i] = ids[i + 1];
//            priorities[i] = priorities[i + 1];
//        }
//
//       
//        top--;
//    }
//
//    void displayStack() {
//        if (isEmpty()) {
//            cout << "Stack is empty.\n";
//            return;
//        }
//
//        cout << "Current Drones in Stack:\n";
//        for (int i = top; i >= 0; --i) {
//            cout << "Drone ID: " << ids[i] << ", Priority: " << priorities[i] << "\n";
//        }
//    }
//};
//int main() {
//    PrioritydroneStack stack;
//
//    stack.push(101, 2);
//    stack.push(102, 5);
//    stack.push(103, 3);
//
//    stack.displayStack();
//
//    int id, priority;
//    stack.dispatchHighestPriority(id, priority);
//    cout << "Dispatched Drone -> ID: " << id << ", Priority: " << priority << "\n";
//
//    stack.displayStack();
//
//    return 0;
//}
