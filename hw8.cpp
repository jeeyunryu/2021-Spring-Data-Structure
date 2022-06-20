#include <iostream>
using namespace std;

class node {
public:
    string name;
    double score;
    node* link;
    void set_data(string s, double n);
};

void node::set_data(string s, double n) {
    name = s;
    score = n;
}

class my_list {
private:
    node* head, * tail;
public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    double score_sum();
    double get_score(string t_name);
    int remove_a_node(string t_name);
};

my_list::my_list() {
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t)
{
    node* p;
    p = new node;
    (*p) = t;
    p->link = head;
    head = p;
    if (tail == NULL)
        tail = p;
}

void my_list::add_to_tail(node t)
{
    node* p;
    p = new node;
    (*p) = t;
    if (tail != NULL)
        tail->link = p;
    else
        head = p;
    tail = p;
    
}

node my_list::delete_from_head()
{
    node temp;
    node* t;
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if (head == NULL)
        tail = NULL;
    return temp;
}

int my_list::num_nodes()
{
    node* t;
    int count = 0;
    for (t = head; t != NULL; t = t->link)
        count++;
    return count;
}

double my_list::score_sum()
{
    node* t;
    double sum = 0;
    for (t = head; t != NULL; t = t->link)
        sum += t->score;
    return sum;
}

double my_list::get_score(string t_name)
{
    node* t;
    for (t = head; t != NULL; t = t->link)
    {
        if (t->name == t_name)
            return t->score;
    }

}
int my_list::remove_a_node(string t_name)
{
    node* t;
    int isRemoved = 0;
    for (t = head; t != NULL; t = t->link)
    {
        if (t->name == t_name)
        {
            //�ش� node ����...
            
            /*if (head == t)
                head = head->link;*/
            t = t->link;
            isRemoved = 1;
        }

        if (isRemoved == 1)
            return 1;
        else
            return 0;

    }

}


int main()

{
    my_list    a;
    node   tmp;
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);           // head ��ġ�� 2���� ���� �߰�
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 1�ܰ� ����
    tmp.set_data("Park", 91.3);   
    a.add_to_tail(tmp);             // tail ��ġ�� 1���� ���� �߰�
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  //2�ܰ� ����
    tmp = a.delete_from_head();
    cout << tmp.name << " is deleted.\n";   // 3�ܰ� ����
    tmp.set_data("Choi", 85.1);   
    a.add_to_tail(tmp);
    tmp.set_data("Ryu", 94.3);   
    a.add_to_head(tmp);             // 2���� ���� �߰�
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";
    cout << "Park��s score : " << a.get_score("Park") << "\n";  // 4�ܰ� ����
    if (a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list. \n";     // 5�ܰ� ����
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // ���� ����       
    return 0;

}