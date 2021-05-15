#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m; int n;
//weight, v,w
vector<pair<int, pair<int, int>>>edgeList;
vector<int>mst;

//root, weight sum
pair<int, int> tree[100001];

int findRoot(int x) {
	if (tree[x].first != x) {
		x = findRoot(tree[x].first);
	}
	return tree[x].first;
}

bool isSameRoot(int a, int b) {
	if (findRoot(a) == findRoot(b)) {
		return true;
	}
	return false;
}



void merge(int a, int b, int val) {
	//root 찾기
	int rootA = findRoot(a);
	int rootB = findRoot(b);

	if (tree[rootA].second > tree[rootB].second) {
		tree[rootB].first = tree[rootA].first;
	}
	else {
		tree[rootA].first = tree[rootB].first;
		if (tree[rootA].second == tree[rootB].second) {
			tree[rootB].second += 1;
		}
	}
}

void kruskal() {
	sort(edgeList.begin(), edgeList.end());
	for (int i = 0; i < edgeList.size(); i++) {
		pair<int, pair<int, int>> curr = edgeList[i];

		if (isSameRoot(curr.second.first, curr.second.second)) {//이미 이어져 있음
			continue;
		}
		else {//연결 안됨
			merge(curr.second.first, curr.second.second, curr.first);
			mst.push_back(curr.first);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a; int b; int c;
		cin >> a >> b >> c;
		edgeList.push_back(make_pair(c, make_pair(a, b)));
	}
	for (int i = 1; i <= n; i++) {
		tree[i] = make_pair(i,0);
	}

	kruskal();

	int res = 0;
	int maxVal = -1;
	for (int i = 0; i < mst.size(); i++) {
		if (maxVal < mst[i]) {
			maxVal = mst[i];
		}
		res += mst[i];
	}
	cout << res - maxVal;
	return 0;
}