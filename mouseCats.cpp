#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e3, M = 1e3, OO = 0x3f3f3f3f;

int n, m;
char grid[N][M];
int mR,mC;
int dR[] = {0 , 0, 1, -1};
int dC[] = {1, -1, 0, 0}; 
int catDis[N][M];
int mouseDis[N][M];

bool correctDir(int nR, int nC){
    return (nR < n && nR >= 0 && nC < m && nC >= 0);
}

void catBFS(){
    memset(catDis, OO, sizeof catDis);
    queue <pair <int, int> > q;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(grid[i][j] == 'C'){
                q.push({i , j});
                catDis[i][j] = 0;
            }
        }
    }

    while(!q.empty){
        pair<int, int> u = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            int nR = u.first + dR[k];
            int nC = u.second + dC[k];
            if(correctDir(nR, nC) && catDis[nR][nC] == OO && grid[nR][nC] != '#'){
                catDis[nR][nC] = catDis[u.first][u.second] + 1;
                q.push({nR, nC});
            }
        }
    }

}

bool mouseBFS(int mR, int mC){
    memset(mouseDis, OO, sizeof mouseDis);
    queue <pair <int, int> > q;
    mouseDis[mR][mC] = 0;
    q.push({mR, mC});

    while(!q.empty){
        pair<int, int> u = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            int nR = u.first + dR[k];
            int nC = u.second + dC[k];
            if(correctDir(nR, nC) && mouseDis[nR][nC] == OO && grid[nR][nC] != '#' && catDis[nR][nC] < mouseDis[u.first][u.second]){
                if(grid[nR][nC] == 'E') return true;
                mouseDis[nR][nC] = mouseDis[u.first][u.second] + 1;
                q.push({nR, nC});
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> grid[i];
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 'M'){
                mR = i;
                mC = j;
            }
        }
    }
    catBFS();
    cout << (mouseBFS(mR, mC) ? "YES" : "NO");
}