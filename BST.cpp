#include <iostream>

using namespace std;

template <typename T>
class BSTree;

template <typename T>
struct TNode {
	TNode *left_, *right_;
	T value_;

	TNode(T value = 0) : value_(value), left_(NULL), right_(NULL)
	{ }

	inline void setValue(T value)
	{
		this->value_ = value;
	}

	inline T &getValue()
	{
		return this->value_;
	}
};

template <typename T>
class BSTree {
private:
	TNode<T> root;

public:
	BSTree()
	{ }

	~BSTree()
	{ }

	void insert(T value)
	{
		TNode<int> *p = &root;
		_insert(p, value);
	}

	void remove(T value)
	{
		TNode<int> *p = &root;
		_remove(p, value);
	}

	TNode<T> *find(T value)
	{
		return _find(&root, value);
	}

	void print() 
	{
		_print(&root);
	}

private:
	void _insert(TNode<T> *&p, T value)
	{
		if (!p) {
			p = new TNode<T>(value);
		} else if (value <= p->value_) {
			_insert(p->left_, value);
		} else {
			_insert(p->right_, value);
		}
	}

	T _remove_min(TNode<T> *&p)
	{
		if (!p->left_) {
			T value = p->value_;
			TNode<T> *tmp = p;
			p = p->right_;
			delete tmp;
			return value;
		} else {
			return _remove_min(p->left_);
		}
	}

	void _remove(TNode<T> *&p, T value)
	{
		if (!p) {
			return;
		}
		if (value == p->value_) {
			if (p->left_ && p->right_) {
				p->value_ = _remove_min(p->right_);
			} else {
				TNode<T> *tmp = p;
				p = p->left_ ? p->left_ : p->right_;
				delete tmp;
			}
		} else if (value < p->value_) {
			_remove(p->left_, value);
		} else {
			_remove(p->right_, value);
		}
	}

	TNode<T> *_find(TNode<T> *p, T value)
	{
		if (p) {
			if (value < p->value_) {
				return _find(p->left_, value);
			} else if (value > p->value_) {
				return _find(p->right_, value);
			} else {
				return p;
			}
		}

		return NULL;
	}

	void _print(TNode<T> *p)
	{
		if (p) {
			_print(p->left_);
			cout << p->value_ << " ";
			_print(p->right_);
		}
	}

	void _delete(TNode<T> *p)
	{
		if (!p) {
			return;
		}
		_delete(p->left_);
		_delete(p->right_);
		delete p;
	}

};

int main()
{
	BSTree<int> *tree = new BSTree<int>();

	tree->insert(1);
	tree->insert(2);
	tree->insert(3);
	tree->insert(4);
	tree->insert(5);

	cout << endl;
	tree->print();
	cout << endl;

	cout << tree->find(1)->getValue() << endl;
	cout << tree->find(2)->getValue() << endl;
	cout << tree->find(3)->getValue() << endl;
	cout << tree->find(4)->getValue() << endl;
	cout << tree->find(5)->getValue() << endl;

	tree->remove(1);
	tree->remove(2);
	tree->remove(3);
	tree->remove(4);
	tree->remove(5);

	cout << endl;
	tree->print();
	cout << endl;

	delete tree;

	return 0;
}