#include <iostream>
#include <queue>
using namespace std;

struct point
{
    int x; int y;
};

point store[100];   
point festival;     
point home;         
bool visited[100];

int abs(int n) {
    if (n < 0) return -n;
    return n;
}

bool BFS(int n) {
    queue<pair<int, int>> que;
    que.push({ home.x, home.y }); 

    while (!que.empty()) {
        int x = que.front().first; 
        int y = que.front().second;
        que.pop();

        if (abs(festival.x - x) + abs(festival.y - y) <= 1000) return true; 
        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) {
                
                continue;
            }
            if (abs(store[i].x - x) + abs(store[i].y - y) <= 1000) {        
                visited[i] = 1;                                             
                que.push({ store[i].x, store[i].y });                       
            }
        }
    }
    return false; 
}

int main() {

    int t;  
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;

        cin >> home.x >> home.y;                
        for (int i = 0; i < n; i++) 
        {
            cin >> store[i].x >> store[i].y;    
        }
        cin >> festival.x >> festival.y;        
        bool possible = BFS(n);
        if (possible) cout << "happy\n";
        else cout << "sad\n";

        fill(visited, visited + 100, false);
    }

    return 0;
}