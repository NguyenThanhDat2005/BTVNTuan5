#include <iostream>
using namespace std;

// Cấu trúc Node cho cây
struct Node {
    char title[50]; // Tiêu đề của chương/mục
    int pageCount; // Số trang trong mục này
    Node* children[10]; // Mảng các nút con (tối đa 10 nút con)
    int childCount; // Số lượng nút con

    Node(const char* t, int p) {
        for (int i = 0; i < 50; ++i) {
            title[i] = t[i];
            if (t[i] == '\0') break;
        }
        pageCount = p;
        childCount = 0;
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
};

// Hàm đếm số chương
int countChapters(Node* root) {
    if (!root) return 0;
    return root->childCount;
}

// Hàm tìm chương dài nhất
Node* findLongestChapter(Node* root) {
    if (!root || root->childCount == 0) return nullptr;

    Node* longestChapter = nullptr;
    int maxPages = 0;

    for (int i = 0; i < root->childCount; ++i) {
        if (root->children[i]->pageCount > maxPages) {
            maxPages = root->children[i]->pageCount;
            longestChapter = root->children[i];
        }
    }
    return longestChapter;
}

// Hàm tìm và xóa một nút theo tiêu đề
bool findAndDelete(Node* root, const char* title, int& deletedPages) {
    if (!root) return false;

    for (int i = 0; i < root->childCount; ++i) {
        bool match = true;
        for (int j = 0; title[j] != '\0' && root->children[i]->title[j] != '\0'; ++j) {
            if (title[j] != root->children[i]->title[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            deletedPages = root->children[i]->pageCount;
            delete root->children[i];
            for (int k = i; k < root->childCount - 1; ++k) {
                root->children[k] = root->children[k + 1];
            }
            root->children[root->childCount - 1] = nullptr;
            root->childCount--;
            return true;
        } else {
            if (findAndDelete(root->children[i], title, deletedPages)) {
                root->pageCount -= deletedPages;
                return true;
            }
        }
    }
    return false;
}

// Hàm tiện ích để xóa cây
void deleteTree(Node* root) {
    if (!root) return;
    for (int i = 0; i < root->childCount; ++i) {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main() {
    // Ví dụ về cây sách
    Node* book = new Node("Tieu de sach", 0);

    Node* chapter1 = new Node("Chuong 1", 50);
    Node* chapter2 = new Node("Chuong 2", 30);
    Node* chapter3 = new Node("Chuong 3", 70);

    book->children[book->childCount++] = chapter1;
    book->children[book->childCount++] = chapter2;
    book->children[book->childCount++] = chapter3;

    Node* section1 = new Node("Muc 1.1", 20);
    Node* section2 = new Node("Muc 1.2", 30);
    chapter1->children[chapter1->childCount++] = section1;
    chapter1->children[chapter1->childCount++] = section2;

    // Đếm số chương
    cout << "So luong chuong: " << countChapters(book) << endl;

    // Tìm chương dài nhất
    Node* longest = findLongestChapter(book);
    if (longest) {
        cout << "Chuong dai nhat: " << longest->title << " voi " << longest->pageCount << " trang." << endl;
    }

    // Tìm và xóa một mục
    int deletedPages = 0;
    if (findAndDelete(book, "Muc 1.1", deletedPages)) {
        cout << "Da xoa muc thanh cong. So trang da xoa: " << deletedPages << endl;
        cout << "So trang da cap nhat cua chuong 1: " << chapter1->pageCount << endl;
    } else {
        cout << "Khong tim thay muc." << endl;
    }

    // Dọn dẹp bộ nhớ
    deleteTree(book);

    return 0;
}
