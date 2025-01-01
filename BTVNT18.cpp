#include <iostream>

using namespace std;

// Cài đặt đồ thị bằng ma trận lân cận
class GraphMatrix {
private:
    int vertices;
    int **matrix;

public:
    GraphMatrix(int v) {
        vertices = v;
        matrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            matrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    ~GraphMatrix() {
        for (int i = 0; i < vertices; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void addEdge(int u, int v) {
        matrix[u][v] = 1;
    }

    void BFS(int start) {
        int visited[vertices] = {0};
        int queue[vertices], front = 0, rear = 0;
        visited[start] = 1;
        queue[rear++] = start;

        cout << "BFS (Matrix): ";
        while (front < rear) {
            int vertex = queue[front++];
            cout << vertex << " ";

            for (int i = 0; i < vertices; i++) {
                if (matrix[vertex][i] == 1 && !visited[i]) {
                    visited[i] = 1;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        int visited[vertices] = {0};
        int stack[vertices], top = -1;
        stack[++top] = start;

        cout << "DFS (Matrix): ";
        while (top >= 0) {
            int vertex = stack[top--];
            if (!visited[vertex]) {
                cout << vertex << " ";
                visited[vertex] = 1;

                for (int i = vertices - 1; i >= 0; i--) {
                    if (matrix[vertex][i] == 1 && !visited[i]) {
                        stack[++top] = i;
                    }
                }
            }
        }
        cout << endl;
    }
};

// Cài đặt đồ thị bằng danh sách lân cận
class GraphList {
private:
    int vertices;
    int **adjList;
    int *sizes;

public:
    GraphList(int v) {
        vertices = v;
        adjList = new int*[vertices];
        sizes = new int[vertices];
        for (int i = 0; i < vertices; i++) {
            adjList[i] = new int[vertices];
            sizes[i] = 0;
        }
    }

    ~GraphList() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjList[i];
        }
        delete[] adjList;
        delete[] sizes;
    }

    void addEdge(int u, int v) {
        adjList[u][sizes[u]++] = v;
    }

    void BFS(int start) {
        int visited[vertices] = {0};
        int queue[vertices], front = 0, rear = 0;
        visited[start] = 1;
        queue[rear++] = start;

        cout << "BFS (List): ";
        while (front < rear) {
            int vertex = queue[front++];
            cout << vertex << " ";

            for (int i = 0; i < sizes[vertex]; i++) {
                int neighbor = adjList[vertex][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    queue[rear++] = neighbor;
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        int visited[vertices] = {0};
        int stack[vertices], top = -1;
        stack[++top] = start;

        cout << "DFS (List): ";
        while (top >= 0) {
            int vertex = stack[top--];
            if (!visited[vertex]) {
                cout << vertex << " ";
                visited[vertex] = 1;

                for (int i = sizes[vertex] - 1; i >= 0; i--) {
                    int neighbor = adjList[vertex][i];
                    if (!visited[neighbor]) {
                        stack[++top] = neighbor;
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Đồ thị có 7 đỉnh (a, b, c, d, e, f, g) tương ứng với 0, 1, 2, 3, 4, 5, 6
    GraphMatrix graphMatrix(7);
    GraphList graphList(7);

    int edges[][2] = {
        {0, 1}, {0, 2}, {0, 3}, {1, 4}, {2, 4}, {3, 5}, {4, 5}, {4, 6}, {5, 6}
    };

    for (int i = 0; i < 9; i++) {
        graphMatrix.addEdge(edges[i][0], edges[i][1]);
        graphList.addEdge(edges[i][0], edges[i][1]);
    }

    // BFS và DFS với ma trận lân cận
    graphMatrix.BFS(0);
    graphMatrix.DFS(0);

    // BFS và DFS với danh sách lân cận
    graphList.BFS(0);
    graphList.DFS(0);

    return 0;
}
