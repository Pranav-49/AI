#include <iostream>
using namespace std;

const int MAX = 100;
int graph[MAX][MAX]; // Adjacency matrix
bool visited[MAX];   // Visited array

// Stack for DFS
int stack[MAX];
int top = -1;

// Queue for BFS
int queue[MAX];
int front = 0, rear = 0;

// Function to push to stack
void push(int value) {
    stack[++top] = value;
}

// Function to pop from stack
int pop() {
    return stack[top--];
}

// Check if stack is empty
bool isStackEmpty() {
    return top == -1;
}

// Function to enqueue in BFS
void enqueue(int value) {
    queue[rear++] = value;
}

// Function to dequeue in BFS
int dequeue() {
    return queue[front++];
}

// Check if queue is empty
bool isQueueEmpty() {
    return front == rear;
}

// 🔹 DFS using Stack (Non-Recursive)
void DFS(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = false; // Reset visited

    int count = 0;      // Counter for visited nodes
    int last_node = start; // Track last node visited

    push(start);             // Push starting node
    visited[start] = true;   // Mark as visited

    while (!isStackEmpty()) {
        int node = pop();    // Pop node from stack
        cout << node << " "; // Print it
        count++;             // Increment counter
        last_node = node;    // Update last node

        // Check all adjacent nodes (descending order)
        for (int i = n - 1; i >= 0; i--) {
            if (graph[node][i] == 1 && !visited[i]) {
                push(i);            // Push unvisited neighbor
                visited[i] = true;  // Mark as visited
            }
        }
    }
    cout << "\nNodes visited in DFS: " << count << ", Last node: " << last_node;
}

// 🔹 BFS using Queue
void BFS(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = false; // Reset visited
    front = rear = 0; // Reset queue

    int count = 0;      // Counter for visited nodes
    int last_node = start; // Track last node visited

    enqueue(start);           // Enqueue starting node
    visited[start] = true;    // Mark as visited

    while (!isQueueEmpty()) {
        int node = dequeue();  // Dequeue a node
        cout << node << " ";   // Print it
        count++;               // Increment counter
        last_node = node;      // Update last node

        // Check all adjacent nodes
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(i);         // Enqueue unvisited neighbor
                visited[i] = true;  // Mark as visited
            }
        }
    }
    cout << "\nNodes visited in BFS: " << count << ", Last node: " << last_node;
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    if (vertices <= 0 || vertices > MAX) {
        cout << "Invalid number of vertices!" << endl;
        return 1;
    }

    // Initialize adjacency matrix to 0
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;

    // Input edges
    cout << "Enter edges (e.g., 0 1, vertices 0 to " << vertices-1 << "):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            graph[u][v] = 1;
            graph[v][u] = 1; // Undirected
        } else {
            cout << "Invalid edge (" << u << ", " << v << ") ignored!" << endl;
            i--; // Retry this edge input
        }
    }

    int start;
    cout << "Enter starting node (0 to " << vertices-1 << "): ";
    cin >> start;
    if (start < 0 || start >= vertices) {
        cout << "Invalid starting node!" << endl;
        return 1;
    }

    cout << "\nDFS Traversal (using stack): ";
    DFS(start, vertices);

    cout << "\n\nBFS Traversal (using queue): ";
    BFS(start, vertices);

    return 0;
}