#include <iostream>

#define MAX 100000

using namespace std;

int dp[101][101][2][2], w, h;		// 어디서 왔는지 , 꺾었는지 

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> h >> w;
	
	for(int i = 1; i <= w; i++) {
		dp[i][1][0][0] = 1;		// from north
	}
	
	for(int i = 1; i <= h; i++) {
		dp[1][i][1][0] = 1;		// from east
	}
	
	for(int i = 2; i <= w; i++) {
		for(int j = 2; j <= h; j++) {
			// 북쪽에서 왔는데 꺾이지 않음 
			dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1]) % MAX;
			
			// 북쪽에서 왔는데 꺾임 -> 꺾여서 들어오므로 전에 꺾였으면 안된다.  
			dp[i][j][0][1] = (dp[i - 1][j][1][0]) % MAX;
			
			// 동쪽에서 왔는데 꺾이지 않음 
			dp[i][j][1][0] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1]) % MAX;
			
			// 동쪽에서 왔는데 꺾임 -> 꺾여서 들어오므로 전에 꺾였으면 안된다. 
			dp[i][j][1][1] = (dp[i][j - 1][0][0]) % MAX;
		}
	}
	
	cout << (dp[w][h][0][0] + dp[w][h][0][1] + dp[w][h][1][0] + dp[w][h][1][1]) % MAX << endl; 
	
	return 0;
} 