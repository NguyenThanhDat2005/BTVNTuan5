#include <iostream>
#include <string>
using namespace std;
struct Cart {
    string customerName;
    double totalAmount;
    int productAQuantity;
    Cart* next;
};
class Queue {
private:
    Cart* front;
    Cart* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(string name, double amount, int quantityA) {
        Cart* newCart = new Cart();
        newCart->customerName = name;
        newCart->totalAmount = amount;
        newCart->productAQuantity = quantityA;
        newCart->next = nullptr;

        if (rear == nullptr) {
            front = rear = newCart;
            return;
        }

        rear->next = newCart;
        rear = newCart;
    }


    void dequeue() {
        if (front == nullptr) {
            cout << "Hang doi trong!" << endl;
            return;
        }

        Cart* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    double calculateTotalRevenue() {
        double total = 0;
        Cart* current = front;
        while (current != nullptr) {
            total += current->totalAmount;
            current = current->next;
        }
        return total;
    }

    int countProductA() {
        int totalA = 0;
        Cart* current = front;
        while (current != nullptr) {
            totalA += current->productAQuantity;
            current = current->next;
        }
        return totalA;
    }

    void displayQueue() {
        Cart* current = front;
        while (current != nullptr) {
            cout << "Khach hang: " << current->customerName
                 << ", Tong tien: " << current->totalAmount
                 << ", So luong san pham A: " << current->productAQuantity << endl;
            current = current->next;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue("Nguyen Van A", 100.0, 2);
    queue.enqueue("Tran Thi B", 200.0, 1);
    queue.enqueue("Le Van C", 150.0, 3);

    cout << "Hang doi hien tai:" << endl;
    queue.displayQueue();

    double totalRevenue = queue.calculateTotalRevenue();
    cout << "Tong so tien thu duoc: " << totalRevenue << endl;

    int totalProductA = queue.countProductA();
    cout << "Tong so luong san pham A da duoc ban: " << totalProductA << endl;

    cout << "Xoa gio hang dau tien ra khoi hang doi." << endl;
    queue.dequeue();

    cout << "Hang doi sau xoa:" << endl;
    queue.displayQueue();

    return 0;
}
