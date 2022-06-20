#include <iostream>
using namespace std;

#define SIZE 10


class node {
public:
    string s_title;
    int npages;
    int price;
    node* link;
    void set_data(string s, int n1, int n2);
};

class my_queue {
private:
    node* front, * rear;
public:
    my_queue();
    void insert_q(node t);
    node delete_q();
    bool empty();
   


};

my_queue::my_queue() {
    front = NULL;
    rear = NULL;


}
void my_queue::insert_q(node t) {
    node* p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if (rear != NULL)
        rear->link = p;
    else
        front = p;
    rear = p;
   

   
}

node my_queue::delete_q() {
    
    node* t;
    node temp; 
    t = front;
    temp = *front;
    front = front->link;
        
    if (front == NULL)
        rear = NULL;
    delete t;

    return temp;
   
 

    

}

bool my_queue::empty() {
    if (front == NULL) {
        return true;
    }
    else
        return false;

}



void node::set_data(string s, int n1, int n2) {
    s_title = s;
    npages = n1;
    price = n2;
}


int main()
{
    my_queue  a;
    node  tmp;
  

    tmp.set_data("C++ Programming", 534, 35000);
    a.insert_q(tmp);
    tmp.set_data("Data Structure", 621, 42000);
    a.insert_q(tmp);
    tmp.set_data("JAVA Programming", 485, 38000);
    a.insert_q(tmp);
    tmp.set_data("Logic Design", 532, 44000);
    a.insert_q(tmp);

    while (!a.empty()){
        tmp = a.delete_q();
        cout << tmp.s_title << " : " << tmp.npages << " : " << tmp.price << "\n";
    }
    return 0;
}