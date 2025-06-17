#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
class list
{
    Node* head;
    Node* tail;

public:
    list(){
        head = tail = NULL;
    }

    void push_front(){
        int val;
        cout<<"Insert at Begining...\n\n";
        cout<<"Enter the data: ";
        cin>>val;
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
            return;
        }
        else{
            newnode->next = head;
            head = newnode;
        }

    }
    int printll(){
        cout<<"Traverse Link List...\n\n";
        if(head == NULL){
            cout<<"Linked List is empty\n";
            return 1;
        }
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n\n\n";
        return 0;
    }
    void push_back(){
        cout<<"Insert at End...\n\n";
        cout<<"Enter the data: ";
        int val;
        cin>>val;
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
            return;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    int pop_front(){
        if(head == NULL){
            cout<<"Linked List is empty\n\n";
            return 1;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return 0;
    }
    int pop_back(){
        if(head == NULL){
            cout<<"Linked List is empty\n\n";
            return 1;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        tail = temp;
        temp->next = NULL;
        delete temp;
        return 0;
    }
    int insert(){
        cout<<"Insert at Middle...\n\n";
        int t=1,p=0,val,pos;
        cout<<"Enter the data:";
        cin>>val;
        cout<<"Enter the position:";
        cin>>pos;
        Node* temp = head;
        Node* newnode = new Node(val);
        if(pos == 0){
            newnode->next = head;
            head = newnode;
            return 0;
        }
        while(temp != NULL){
            temp=temp->next;
            p++;
        }
        temp = head;
        if(pos>=(p+1) || pos<0){
            cout<<"Invalid position...\n";
            return 1;
        }
        while(t<(pos-1)){
            temp = temp->next;
            t++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        return 0;
    }
};

int main()
{
    list ll;
    x:
    cout<<"\t\t\tLink List\n\n";
    cout<<"1. Insert at Begining\t\t2. Insert at End\n\n";
    cout<<"3. Delete from Begining\t\t4. Delete from End\n\n";
    cout<<"5. Traverse Link List\t\t6. Insert at Middle\n\n";
    cout<<"7. Exit for any key\n\n";
    cout<<"Enter your choice:";
    char ch = getche();
    system("cls");
    if(ch == '1'){
        a:
        ll.push_front();
        cout<<"\nData is succesfully inserted at the begining...\n";
        cout<<"Want to add more data. If so press 1. else press 2.\n\n";
        cout<<"1. Insert at Begining\t2. Back to the home\n\n";
        cout<<"Enter your choice: ";
        ch = getche();
        if(ch == '1'){
            system("cls");
            goto a;
        }
        else if(ch == '2'){
            system("cls");
            goto x;
        }
    }
    else if(ch == '2'){
        b:
        ll.push_back();
        cout<<"\nData is succesfully inserted at the end...\n";
        cout<<"Want to add more data. If so press 1. else press 2.\n\n";
        cout<<"1. Insert at End\t2. Back to the home\n";
        cout<<"Enter your choice: ";
        ch = getche();
        if(ch == '1'){
            system("cls");
            goto b;
        }
        else if(ch == '2'){
            system("cls");
            goto x;
        }
    }

    else if(ch == '3'){
        c:
        int n = ll.pop_front();
        if(n == 1){
            cout<<"Please enter the data before perform delete operation...\n\n";
            cout<<"1. Back to the home or press any key to continue";
            ch = getche();
            if(ch == '1'){
                system("cls");
                goto x;
            }
        }
        else{
            cout<<"Data is succesfully deleted from the begining...\n";
            cout<<"Delete more data. If so press 1. else press 2.\n\n";
            cout<<"1. Delete from Begining\t2. Back to the home\n";
            cout<<"Enter your choice: ";
            ch = getche();
            if(ch == '1'){
                system("cls");
                goto c;
            }
            else if(ch == '2'){
                system("cls");
                goto x;
            }
        }
    }
    else if(ch == '4'){
        d:
        int n = ll.pop_back();
        if(n == 1){
            cout<<"Please enter the data before perform delete operation...\n\n";
            cout<<"1. Back to the home or press any key to continue";
            ch = getche();
            if(ch == '1'){
                system("cls");
                goto x;
            }
        }
        else{
            cout<<"\nData is succesfully deleted from the end...\n";
            cout<<"Delete more data. If so press 1. else press 2.\n\n";
            cout<<"1. Delete from end\t2. Back to the home\n";
            cout<<"Enter your choice: ";
            ch = getche();
            if(ch == '1'){
                system("cls");
                goto d;
            }
            else if(ch == '2'){
                system("cls");
                goto x;
            }
        }
    }

    else if(ch == '5'){
        int n = ll.printll();
        if(n == 1)
            cout<<"Please enter the data before traverse...\n\n\n";
        cout<<"1. Back to the home or press any key:";
        ch = getche();
        if(ch == '1'){
            system("cls");
            goto x;
        }
    }

    else if(ch == '6'){
        int n;
        e:
        n = ll.insert();
        if(n == 1){
            cout<<"1. Back to the home or press any key:";
            ch = getche();
            if(ch == '1'){
                system("cls");
                goto x;
            }
            else{
                return 0;
            }
        }
        cout<<"\nData is succesfully inserted at the middle...\n";
        cout<<"Want to add more data. If so press 1. else press 2.\n\n";
        cout<<"1. Insert at Middle\t2. Back to the home\n";
        cout<<"Enter your choice: ";
        ch = getche();
        if(ch == '1'){
            system("cls");
            goto e;
        }
        else if(ch == '2'){
            system("cls");
            goto x;
        }
    }
}
