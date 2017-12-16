int const MAX = 100005;

// ix - node value in the original tree
// ip - centroid tree node value of the parent
struct node{
	int ix, ip, sz;

	node(){
		ix = ip = -1;
		sz = 0;
	}

	node(int ix, int ip, int sz) : ix(ix), ip(ip), sz(sz){

	}
};

vector<node> ct;
int sz[MAX], map_node[MAX];
bool vis[MAX];

void dfs_centroid(int v, int p){
	sz[v] = 1;

	for(int i = 0; i < adj[v].size(); i++){
		if(adj[v][i] != p && !vis[adj[v][i]]){
			dfs_centroid(adj[v][i], v);
			sz[v] += sz[adj[v][i]];
		}
	}
}

int centroid(int v, int p, int &n){
	for(int i = 0; i < adj[v].size(); i++)
		if(adj[v][i] != p && !vis[adj[v][i]] && sz[adj[v][i]] > n / 2)
			return centroid(adj[v][i], v, n);

	return v;
}

void decompose(int v, int p){
	dfs_centroid(v, p);
	int cd = centroid(v, p, sz[v]);
	ct.push_back(node(cd, (p == -1 ? -1 : map_node[p], sz[v])));
	mapNode[cd] = ct.size() - 1;
	vis[cd] = 1;

	for(int i = 0; i < adj[ct].size(); i++){
		if(adj[ct][i] != p && !vis[adj[ct][i]])
			decompose(adj[ct][i], ct);
	}
}

void build_centroid_tree(){
	memset(vis, 0, sizeof(vis));
	memset(map_node, -1, sizeof(map_node));
	memset(sz, 0, sizeof(sz));

	decompose(1, -1);
}