#include <iostream>
using namespace std;

/*class bst_node {
public:
	string name;
	string s_id;
	double score;
	bst_node* left, * right;
};*/

/*class s_record {
public:
	string name;
	string s_id;
	double score;
};

class bst_node {
public:
	s_record s_data;
	bst_node* left, * right;
};*/

//node class
class bst_node {
public:
	string s_id;
	string name;
	double score;
	bst_node* left, * right;
	bst_node();
	bst_node(string s1, string s2, double n);
	void set_data(string s1, string s2, double n);
};

bst_node::bst_node()
{
	//s_id = " ";
	//name = " ";
	score = 0;
	left = NULL;
	right = NULL;
}

bst_node::bst_node(string s1, string s2, double n)
{
	s_id = s1;
	name = s2;
	score = n;
}

void bst_node::set_data(string s1, string s2, double n)
{
	s_id = s1;
	name = s2;
	score = n;
}

//tree class
class bst_tree {
	bst_node* root;
	int csize;
public:
	bst_tree();
	void insert_node(bst_node t);
	void show_inorder();
	bst_node search(string tid);
	//bool empty();
	int size();
	//s_record search(string s);
};

bst_tree::bst_tree()
{
	root = NULL;
	csize = 0;
}

int bst_tree::size()
{
	return csize;
}

bst_node bst_tree::search(string tid)
{
	bst_node* p;
	p = root;
	if (root == NULL)
	{
		bst_node tmp;
		tmp.set_data("0000000", "None", -1);
		cout << "The key" << tid << "does not exist.\n";
		return tmp;
	}

	while (1)
	{
		if (p->s_id == tid)
			return(*p);
		if (p->s_id < tid)
		{
			if (p->right == NULL)
			{
				bst_node tmp;
				tmp.set_data("0000000", "None", -1);
				cout << "The key" << tid << "does not exist.\n";
				return tmp;
			}
			else
				p = p->right;
		}
		if (p->s_id > tid)
		{
			if (p->left == NULL)
			{
				bst_node tmp;
				tmp.set_data("000000", "None", -1);
				cout << "The key" << tid << "does not exist.\n";
				return tmp;
			}
			else
				p = p->left;
		}
	}
}

void bst_tree::insert_node(bst_node t)
{
	bst_node* p;
	bst_node* tmp;

	tmp = new bst_node;
	*tmp = t;
	tmp->left = NULL;
	tmp->right = NULL;

	if (root == NULL)
	{
		root = tmp;
		return;
	}

	p = root;
	while (1)
	{
		if (p->s_id == t.s_id)
		{
			cout << "Insertion Failed : the Key " << t.s_id << " already exists." << endl;
			return;
		}
		if (p->s_id < t.s_id)
		{
			if (p->right == NULL)
			{
				p->right = tmp;
				//csize++;
				return;
			}
			else
				p = p->right;
		}
		else
		{
			if (p->left == NULL)
			{
				p->left = tmp;
				//csize++;
				return;
			}
			else
				p = p->left;
		}
	}
}

void bst_tree::show_inorder()
{
}

int loadMenu()
{
	int menu = 0;
	cout << "1. 새로운 원소 추가" << endl;
	cout << "2. 원소 조회" << endl;
	cout << "3. 전체 목록 보기" << endl;
	cout << "0. 종료" << endl;
	cout << "명령 선택 : ";
	cin >> menu;

	return menu;
}

int main()
{
	bst_node tmp;
	bst_tree t1;
	int menu = 0;
	while (1)
	{
		menu = loadMenu();
		if (menu == 0)
			break;
		/*if (menu == 2 || menu == 3)
		{
			if (t1.size() == 0)
				continue;
		}*/
		if (menu == 1)
		{
			string s1, s2;
			double n;
			cout << "학번 : ";
			cin >> s1;
			cout << "이름 : ";
			cin >> s2;
			cout << "점수: ";
			cin >> n;
			tmp.set_data(s1, s2, n);
			t1.insert_node(tmp);
		}
		if (menu == 2)
		{
			string s_key;
			cout << "학번 : ";
			cin >> s_key;
			tmp = t1.search(s_key);
			
			cout << "\n --" << s_key << "'s record ---" << endl;
			cout << "Student ID : " << tmp.s_id << endl;
			cout << "Student Name : " << tmp.name << endl;
			cout << "Score : " << tmp.score << endl;
		}
		if (menu == 3)
		{
			cout << "Node List : inorder sequence" << endl;
			//t1.show_inorder();
		}


	}
	return 0;
}