struct Node{
	int cnt;
	Node *l;
	Node *r;
	Node(){
		this -> cnt = 0;
		this -> l = this;
		this -> r = this;
	}

	Node(int cnt, Node *l, Node *r) : cnt(cnt), l(l), r(r){
	}
	Node *get(int s, int e, int val);
};

Node *null;

Node* Node::get(int s, int e, int val){
	if(s == e)
		return new Node(this -> cnt + 1, null, null);
	else{
		int mid = s + (e - s) / 2;

		if(val <= mid)
			return new Node(this -> cnt + 1, this -> l -> get(s, mid, val), this -> r);
		else
			return new Node(this -> cnt + 1, this -> l, this -> r -> get(mid + 1, e, val));
	}
}

Node *Head[MAX];

// Main
null = new Node();
Head[0] = new Node();