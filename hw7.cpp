#include <iostream>
using namespace std;

#define SIZE 10


class element {
public:  
    string s_title;
    int npages;
    int price;
    element();
    void set_data(string s, int n1, int n2);
};

class my_queue {
private:
    element q[SIZE];
    int front;
    int rear;
    

public:
    my_queue();
    void insert_q(element elem);
    element delete_q();
    bool empty(); 
    bool full();


};

my_queue::my_queue() {
    front = 0;
    rear = 0;
   
   
}
void my_queue::insert_q(element elem) {
    if (!full()) {
        q[rear] = elem;
        rear = (rear + 1) % SIZE;
    }
}

element my_queue::delete_q() {
    if (empty()) {
        element tmp;
        //tmp.set_data("", 0, 0);
        return(tmp);
    }
    else {
            int tmp = front;
            front = (front + 1) % SIZE;
            return(q[tmp]);
    }

}

bool my_queue::empty() {
    if (front == rear) {
        return true;
    }
    else
        return false;

}

bool my_queue::full() {
    if (((rear + 1) % SIZE) == front) {
        return true;

    }
    else
        return false;


}

element::element() { //nameofBooks 초기화 해야 하나?
    npages = 0;
    price = 0;
}

void element::set_data(string s, int n1, int n2) {
    s_title = s;
    npages = n1;
    price = n2;
}


int main()
{
    my_queue  a;
    element  tmp;
    // 사용자 정의 어떻게 함?

    tmp.set_data("C++ Programming", 534, 35000);
    a.insert_q(tmp);
    tmp.set_data("Data Structure", 621, 42000);
    a.insert_q(tmp);
    tmp.set_data("JAVA Programming", 485, 38000);
    a.insert_q(tmp);
    tmp.set_data("Logic Design", 532, 44000);
    a.insert_q(tmp);

    while (!a.empty()) {
        tmp = a.delete_q();
        cout << tmp.s_title << " : " << tmp.npages << " : " << tmp.price << "\n";
    }
    return 0;
}