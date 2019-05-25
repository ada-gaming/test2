#include<iostream>
#include<vector>
#include<set>

using namespace std;
template<typename T>
class Tree
{
	struct Node
	{
		T date = {};
		Node* left = 0;
		Node* right = 0;
		Node* father = 0;
		int deep=0;
	};
	set<Node*> doneWay;
	Node* root;
	Node* maxDeep;

public:
	Tree();
	~Tree();
	void addNode(T date);
	void Max();

private:
	void DellNode(Node* node);
	void DellTree(Node* node);
	void MaxDeep(Node* node);
	vector<Node*> MaxWay(Node* start)
	{
		vector<Node*>l;
		vector<Node*>r;
		vector<Node*>f;
		if (start)
		{
			doneWay.insert(start);
			if (bool is_in = doneWay.find(start->left) == doneWay.end())			l = MaxWay(start->left);
			if (bool is_in = doneWay.find(start->right) == doneWay.end())			r = MaxWay(start->right);
			if (bool is_in = doneWay.find(start->father) == doneWay.end())		    f = MaxWay(start->father);
			if (l.size() > r.size())
			{
				if (l.size() > f.size())
				{
					l.push_back(start);
					return l;
				}
				else
				{
					f.push_back(start);
					return f;
				}
			}
			else
			{
				if (r.size() > f.size())
				{
					r.push_back(start);
					return r;
				}
				else
				{
					f.push_back(start);
					return f;
				}
			}
		}
		else return l;
	}
};



int main()                                          //MAIN
{
	int firstTree[] = { 52,43,57,36,56,70,21,53,7,30,54,55 };
	Tree<int> fTree;
	for (auto i : firstTree)
	{
		fTree.addNode(i);
	}
	fTree.Max();
	return 0;
}

template<typename T>
Tree<T>::Tree()
{
	this->root = 0;
	maxDeep = 0;
}

template<typename T>
Tree<T>::~Tree()
{
	DellTree(root);
}

template<typename T>
void Tree<T>::addNode(T _date)
{
	if (!root)
	{
		this->root = new Node;
		this->root->date = _date;
		this->root->deep = 1;
		this->maxDeep = this->root;
	}
	else
	{
		bool done = false;
		Node* temp = this->root;
		while (!done)
		{
			if (temp->date < _date)
			{
				if (temp->right) temp = temp->right;
				else
				{
					temp->right = new Node;
					temp->right->date = _date;
					temp->right->deep = temp->deep + 1;
					temp->right->father = temp;
					MaxDeep(temp->right);
					done = true;
				}
			}
			else if (temp->date > _date)
			{
				if (temp->left) temp = temp->left;
				else
				{
					temp->left = new Node;
					temp->left->date = _date;
					temp->left->deep = temp->deep + 1;
					temp->left->father = temp;
					MaxDeep(temp->left);
					done = true;
				}
			}
			else done = true;
		}

	}
}

template<typename T>
void Tree<T>::Max()
{
	vector<Node*>a = MaxWay(maxDeep);
	for (auto i : a)
	{
		cout << i->date << endl;
	}

}

template<typename T>
void Tree<T>::DellNode(Node* node)
{

}

template<typename T>
void Tree<T>::DellTree(Node* node)
{
	if (node != nullptr)
	{
		DellTree(node->left);
		DellTree(node->right);
		delete node;
	}
}

template<typename T>
void Tree<T>::MaxDeep(Node* node)
{
	if (maxDeep->deep < node->deep) maxDeep = node;
}

