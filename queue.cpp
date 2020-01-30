#include <iostream>
#include <stdlib.h>
#include <exception>

using namespace std;

typedef int Data;

struct Node{
    Data key;
    Node* next;
};



class Queue{

private:
    Node* first;
    int count = 0;

public:

    Queue(){
        first = NULL;
        count = 0;
    }

    ~Queue(){
        DeleteQueue();
    }

    int Push(Data k){
        Node *n = new Node;
        Node *aux = first;
        n->key = k;

        if(first == NULL){
            n->next = first;
            first = n;
        }

        else{

            while(aux->next != NULL){
                aux = aux->next;
            }

            n->next = aux->next;
            aux->next = n;

        }
        
        return 1;

    }

    void Show(){
        Node *aux;
        aux = first;
        cout<<"[ ";
        while(aux != NULL){
            cout<<aux->key<<' ';
            aux = aux->next;
        }
        cout<<" ]"<<endl;
        
    }

    int IsEmpty(){
        if (first == NULL){
            return 1;
        }
        else{
            return 0;
        }
    }

    void DeleteQueue(){
        Node* curr = first;
        Node* aux;

        while(curr!=NULL){
            aux = curr->next;
            delete curr;
            curr = aux;
        }

        first = NULL;
        count = 0;

    }

    void Pop(){
        Node* aux;
        aux  = first;
        first = aux->next;
        delete aux;    
    }

};

int main(){

    Queue t;
    t.Push(10);
    t.Push(11);
    t.Push(12);
    t.Show();
    t.Pop();
    t.Show();
    
    return 0;
}