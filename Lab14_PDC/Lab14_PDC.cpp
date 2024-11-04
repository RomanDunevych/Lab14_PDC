#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

// ��������� ��� ��������� ����� �����
struct Edge {
    int from, to;
};

// ������� ��� �������� ������������� �����
bool isAsymmetric(const vector<Edge>& edges) {
    set<pair<int, int>> edgeSet;

    for (const auto& edge : edges) {
        if (edgeSet.count({ edge.to, edge.from }) > 0) {
            return false; // �������� ������� �����, ���� �� ������������
        }
        edgeSet.insert({ edge.from, edge.to });
    }
    return true;
}

// ������� ��� �������� ������������� �����
bool isTransitive(const vector<Edge>& edges, int n) {
    vector<vector<bool>> adjMatrix(n + 1, vector<bool>(n + 1, false));

    // ���������� ������� ��������
    for (const auto& edge : edges) {
        adjMatrix[edge.from][edge.to] = true;
    }

    // �������� �������������
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (adjMatrix[i][j]) {
                for (int k = 1; k <= n; ++k) {
                    if (adjMatrix[j][k] && !adjMatrix[i][k]) {
                        return false; // ������������� �� ����������
                    }
                }
            }
        }
    }
    return true;
}

// ������� �������
int main() {
    setlocale(LC_ALL, "UKR");
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "�� ������� �i������ ����!" << endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m;

    vector<Edge> edges(m);
    cout << "��i�� ����� input.txt:" << endl;
    cout << "�i���i��� ������: " << n << endl;
    cout << "�i���i��� �����: " << m << endl;

    for (int i = 0; i < m; ++i) {
        inputFile >> edges[i].from >> edges[i].to;
        cout << "����� " << i + 1 << ": " << edges[i].from << " -> " << edges[i].to << endl;
    }
    inputFile.close();

    bool asymmetric = isAsymmetric(edges);
    bool transitive = isTransitive(edges, n);

    cout << "\n���� � " << (asymmetric ? "" : "�� ") << "������������." << endl;
    cout << "���� � " << (transitive ? "" : "�� ") << "������������." << endl;

    return 0;
}
