#include <iostream>
using namespace std;

// Определение базового класса Список
class List {
protected:
    struct Node {
        int data;
        Node* next;

        Node(int data = 0, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

    Node* head;

public:
    List() : head(nullptr) {}

    virtual void insert(int data) = 0;
    virtual int extract() = 0;

    virtual ~List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Определение класса Стек на основе Списка
class Stack : public List {
public:
    void insert(int data) {
        // Вставка элемента в начало списка
        head = new Node(data, head);
    }

    int extract() {
        if (head == nullptr) {
            cout << "Стек пуст!" << endl;
            return -1; // Возвращаем пока что здесь произвольное число
        }

        int data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;

        return data;
    }
};

// Определение класса Очередь на основе Списка
class Queue : public List {
    Node* tail;

public:
    Queue() : List(), tail(nullptr) {}

    void insert(int data) {
        // Вставка элемента в конец списка
        if (head == nullptr) {
            head = tail = new Node(data);
        }
        else {
            tail->next = new Node(data);
            tail = tail->next;
        }
    }

    int extract() {
        if (head == nullptr) {
            cout << "Очередь пуста!" << endl;
            return -1; // Возвращаем пока что здесь произвольное число
        }

        int data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;

        return data;
    }
};

// Пример использования стека и очереди
int main() {
    Stack stack;
    stack.insert(1);
    stack.insert(2);
    stack.insert(3);

    cout << "Popping from the stack in insertion order: ";
    cout << stack.extract() << ", ";
    cout << stack.extract() << ", ";
    cout << stack.extract() << endl;

    Queue queue;
    queue.insert(1);
    queue.insert(2);
    queue.insert(3);

    cout << "Popping from the queue in insertion order: ";
    cout << queue.extract() << ", ";
    cout << queue.extract() << ", ";
    cout << queue.extract() << endl;

    return 0;
}