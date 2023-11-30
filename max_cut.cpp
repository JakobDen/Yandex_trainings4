#include <iostream>
#include <vector>

using namespace std;
vector<int> is_dizzying_corridor(vector<vector<int>> corridor) {
    int n = 0;
    int i = 0;
    int j = 0;
    vector<int> way;
    while (n != ((corridor.size() - 1) * 2 - 2)) {
        int flag1 = 0;
        int flag2 = 0;
        while (corridor[i][j + 1] != 1) {
            n += 1;
            flag1 = 1;
            j += 1;
        }
        while (corridor[i + 1][j] != 1) {
            n += 1;
            flag2 = 1;
            i += 1;
        }
        if (flag1) {
            way.push_back(-1);
        }
        if (flag2) {
            way.push_back(1);
        }
    }
    return way;
}

int main() {

    int N;
    cin >> N;
    vector<vector<int>> corridor;
    // Считываем карту окружения
    for (int i = 0; i < N; i++) {
        vector<int> row(N + 1);
        for (int j = 0; j < N; j++) {
            cin >> row[j];
        }
        row[N] = 1;
        corridor.push_back(row);
    }
    vector<int> last_row(N + 1);
    for (int i = 0; i < N + 1; i++) {
        last_row[i] = 1;
    }
    corridor.push_back(last_row);
    vector<int> way;
    // Проверяем коридор на головокружительность
    way = is_dizzying_corridor(corridor);
    int answer = 0;
    for (int i = 0; i < way.size() - 1; i++) {
        answer += way[i];
    }
    if (answer == 0) {
        std::cout << "NO" << endl;
    } else {
        std::cout << "YES" << endl;
    }
    return 0;
}