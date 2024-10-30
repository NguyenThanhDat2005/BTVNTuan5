#include <iostream>
using namespace std;
struct Node {
    int heso;
    int somu;
    Node* next;

    Node(int c, int e) : heso(c), somu(e), next(nullptr) {}
};
class Polynomial {
private:
    Node* head;

public:
    Polynomial() : head(nullptr) {}
    void addTerm(int heso, int somu) {
        if (heso == 0) return;
        Node* newNode = new Node(heso, somu);
        newNode->next = head;
        head = newNode;
    }


    void print() const {
        Node* current = head;
        while (current) {
            cout << current->heso << "x^" << current->somu;
            if (current->next) {
                cout << " + ";
            }
            current = current->next;
        }
        cout <<endl;
    }

    ~Polynomial() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};
int main() {
    Polynomial poly;
    int heso, somu;

    cout << "Nhap he so va bac (nhap 0 0 de ket thuc):\n";
    while (true) {
        cout << "He so: ";
        cin >> heso;
        cout << "Bac: ";
        cin >> somu;

        if (heso == 0 && somu == 0) break;

        poly.addTerm(heso, somu);
    }

    cout << "Da thuc: ";
    poly.print();

    return 0;
}


