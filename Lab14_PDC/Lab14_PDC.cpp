#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

// Структура для зберігання ребер графа
struct Edge {
    int from, to;
};

// Функція для перевірки асиметричності графа
bool isAsymmetric(const vector<Edge>& edges) {
    set<pair<int, int>> edgeSet;

    for (const auto& edge : edges) {
        if (edgeSet.count({ edge.to, edge.from }) > 0) {
            return false; // Знайдено зворотнє ребро, граф не асиметричний
        }
        edgeSet.insert({ edge.from, edge.to });
    }
    return true;
}

// Функція для перевірки транзитивності графа
bool isTransitive(const vector<Edge>& edges, int n) {
    vector<vector<bool>> adjMatrix(n + 1, vector<bool>(n + 1, false));

    // Заповнення матриці суміжності
    for (const auto& edge : edges) {
        adjMatrix[edge.from][edge.to] = true;
    }

    // Перевірка транзитивності
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (adjMatrix[i][j]) {
                for (int k = 1; k <= n; ++k) {
                    if (adjMatrix[j][k] && !adjMatrix[i][k]) {
                        return false; // Транзитивність не виконується
                    }
                }
            }
        }
    }
    return true;
}

// Основна функція
int main() {
    setlocale(LC_ALL, "UKR");
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Не вдалося вiдкрити файл!" << endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m;

    vector<Edge> edges(m);
    cout << "Вмiст файлу input.txt:" << endl;
    cout << "Кiлькiсть вершин: " << n << endl;
    cout << "Кiлькiсть ребер: " << m << endl;

    for (int i = 0; i < m; ++i) {
        inputFile >> edges[i].from >> edges[i].to;
        cout << "Ребро " << i + 1 << ": " << edges[i].from << " -> " << edges[i].to << endl;
    }
    inputFile.close();

    bool asymmetric = isAsymmetric(edges);
    bool transitive = isTransitive(edges, n);

    cout << "\nГраф є " << (asymmetric ? "" : "не ") << "асиметричним." << endl;
    cout << "Граф є " << (transitive ? "" : "не ") << "транзитивним." << endl;

    return 0;
}
