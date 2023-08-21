#include <iostream>
#include <queue>
using namespace std;

int N, M;                       
int maze[101][101];
int visited[101][101];
int dist[101][101];

int x_dir[4] = { -1, 1, 0, 0 };   
int y_dir[4] = { 0, 0, -1, 1 };   

queue<pair<int, int> > q;        


void bfs(int start_x, int start_y) {

    visited[start_x][start_y] = 1;          
    q.push(make_pair(start_x, start_y));    
    dist[start_x][start_y]++;               

    
    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;

       
        q.pop();

        
        for (int i = 0; i < 4; ++i) {

         
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

           if ((0 <= x_new && x_new < N) && (0 <= y_new && y_new < M)
                && !visited[x_new][y_new] && maze[x_new][y_new] == 1) {

                visited[x_new][y_new] = 1;              // 인접 좌표는 방문한 것으로 저장
                q.push(make_pair(x_new, y_new));        // 인접 좌표를 queue 에 삽입
                dist[x_new][y_new] = dist[x][y] + 1;    // 인접 좌표까지 이동한 거리 저장
            }
        }
    }
}

int main() {

    cin >> N >> M;                      

    for (int i = 0; i < N; ++i) {            

        string row;                     
        cin >> row;

        for (int j = 0; j < M; ++j) {        
            maze[i][j] = row[j] - '0';    
        }
    }

    bfs(0, 0);                          

 printf("%d", dist[N-1][M-1]);             
}