
        
          
          #include <iostream>
        
        
          
          #include <vector>
        
        
          
          #include <algorithm>
        
        
          
          using namespace std;
        
        
          
          

        
        
          
          const int MAX = 200000 + 1;
        
        
          
          const int INF = 987654321;
        
        
          
          

        
        
          
          struct SegmentTree
        
        
          
          {
        
        
          
          	vector<int> minTree;
        
        
          
          	vector<int> maxTree;
        
        
          
          

        
        
          
          	SegmentTree(int size)
        
        
          
          	{
        
        
          
          		minTree.assign(size * 4, INF);
        
        
          
          		maxTree.assign(size * 4, -1);
        
        
          
          	}
        
        
          
          

        
        
          
          	int minQuery(int left, int right, int node, int nodeLeft, int nodeRight)
        
        
          
          	{
        
        
          
          		// 기저 사례
        
        
          
          		if (nodeRight < left || right < nodeLeft)
        
        
          
          			return INF; // 항등원
        
        
          
          		if (left <= nodeLeft && nodeRight <= right)
        
        
          
          			return minTree[node];
        
        
          
          

        
        
          
          		int mid = (nodeLeft + nodeRight) / 2;
        
        
          
          		return min(minQuery(left, right, node * 2, nodeLeft, mid), minQuery(left, right, node * 2 + 1, mid + 1, nodeRight));
        
        
          
          	}
        
        
          
          

        
        
          
          	int minUpdate(int idx, int value, int node, int nodeLeft, int nodeRight)
        
        
          
          	{
        
        
          
          		// 기저 사례
        
        
          
          		if (nodeRight < idx || idx < nodeLeft)
        
        
          
          			return minTree[node];
        
        
          
          		if (nodeLeft == nodeRight)
        
        
          
          			return minTree[node] = value;
        
        
          
          

        
        
          
          		int mid = (nodeLeft + nodeRight) / 2;
        
        
          
          		return minTree[node] = min(minUpdate(idx, value, node * 2, nodeLeft, mid), minUpdate(idx, value, node * 2 + 1, mid + 1, nodeRight));
        
        
          
          	}
        
        
          
          

        
        
          
          	int maxQuery(int left, int right, int node, int nodeLeft, int nodeRight)
        
        
          
          	{
        
        
          
          		// 기저 사례
        
        
          
          		if (nodeRight < left || right < nodeLeft)
        
        
          
          			return -1; // 항등원
        
        
          
          		if (left <= nodeLeft && nodeRight <= right)
        
        
          
          			return maxTree[node];
        
        
          
          

        
        
          
          		int mid = (nodeLeft + nodeRight) / 2;
        
        
          
          		return max(maxQuery(left, right, node * 2, nodeLeft, mid), maxQuery(left, right, node * 2 + 1, mid + 1, nodeRight));
        
        
          
          	}
        
        
          
          

        
        
          
          	int maxUpdate(int idx, int value, int node, int nodeLeft, int nodeRight)
        
        
          
          	{
        
        
          
          		// 기저 사례
        
        
          
          		if (nodeRight < idx || idx < nodeLeft)
        
        
          
          			return maxTree[node];
        
        
          
          		if (nodeLeft == nodeRight)
        
        
          
          			return maxTree[node] = value;
        
        
          
          

        
        
          
          		int mid = (nodeLeft + nodeRight) / 2;
        
        
          
          		return maxTree[node] = max(maxUpdate(idx, value, node * 2, nodeLeft, mid), maxUpdate(idx, value, node * 2 + 1, mid + 1, nodeRight));
        
        
          
          	}
        
        
          
          };
        
        
          
          

        
        
          
          int arr[MAX];
        
        
          
          

        
        
          
          int main(void)
        
        
          
          {
        
        
          
          	ios_base::sync_with_stdio(0);
        
        
          
          	cin.tie(0);
        
        
          
          	int N, M;
        
        
          
          	cin >> N >> M;
        
        
          
          

        
        
          
          	SegmentTree segTree(N);
        
        
          
          	for (int i = 1; i <= N; i++)
        
        
          
          	{
        
        
          
          		cin >> arr[i];
        
        
          
          

        
        
          
          		// height가 인덱스, arr[i]의 인덱스가 value
        
        
          
          		segTree.minUpdate(arr[i], i, 1, 1, N);
        
        
          
          		segTree.maxUpdate(arr[i], i, 1, 1, N);
        
        
          
          	}
        
        
          
          

        
        
          
          	for (int i = 0; i < M; i++)
        
        
          
          	{
        
        
          
          		int op, a, b;
        
        
          
          		cin >> op >> a >> b;
        
        
          
          

        
        
          
          		// 위치를 맞바꾸어준다
        
        
          
          		if (op == 1)
        
        
          
          		{
        
        
          
          			segTree.minUpdate(arr[b], a, 1, 1, N);
        
        
          
          			segTree.minUpdate(arr[a], b, 1, 1, N);
        
        
          
          			segTree.maxUpdate(arr[b], a, 1, 1, N);
        
        
          
          			segTree.maxUpdate(arr[a], b, 1, 1, N);
        
        
          
          			
        
        
          
          			swap(arr[a], arr[b]);
        
        
          
          		}
        
        
          
          		else
        
        
          
          		{
        
        
          
          			// 범위 내에 a ~ b가 다 있는지 확인
        
        
          
          			int result = segTree.maxQuery(a, b, 1, 1, N) - segTree.minQuery(a, b, 1, 1, N);
        
        
          
          			int diff = b - a;
        
        
          
          

        
        
          
          			if (result == diff)
        
        
          
          				cout << "YES\n";
        
        
          
          			else
        
        
          
          				cout << "NO\n";
        
        
          
          		}
        
        
          
          	}
        
        
          
          	return 0;
        
        
          
          }
