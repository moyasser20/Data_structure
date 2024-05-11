#include <iostream>
#include <string>
using namespace std;

class Student {

private:
    string Name;
    int ID;
    double GPA;

public:

    Student (){
        Name = "";
        ID = 0;
        GPA = 0;
    }

    Student (string name,int id,double gpa) {
        Name = name;
        ID = id;
        GPA = gpa;
    }

    friend class StudentList;
};

class StudentList {

private:

    struct Node {
        Student *data;
        Node *next;
    };

    Node *Head;
    Node *Tail;
    int Length;

public:

    StudentList() {
        Head = Tail = nullptr;
        Length = 0;
    }

    ~StudentList(){
        Node *temp;
        while (Head != nullptr)
        {
            temp = Head;
            Head = Head->next;
            delete temp;
        }
        Tail = nullptr;
        Length = 0;
    }


    bool isEmpty () const{
        return Length ==0;
    }

    void InsertAndSort(Student *s){
        Node *newNode = new Node;
        newNode -> data = s;

        if (Head == nullptr || s -> ID < Head -> data ->ID) {
            newNode -> next = Head;
            Head = newNode;
        }

        else {
            Node *current = Head;
            while (current -> next != nullptr && s -> ID > current -> next -> data -> ID) {
                current = current->next;
            }
            newNode -> next = current -> next;
            current -> next = newNode;

        }
        Length++;
    }

    void RemoveById(int id) {

        if (isEmpty())  {
            return;
        }

        Node *current;
        Node *previous;

        if (Head -> data -> ID == id) {
            current = Head;
            Head = Head -> next;
            delete current -> data;
            delete current;
            Length--;
        }

        else {

            current = Head -> next;
            previous = Head;

            while (current != nullptr) {

                if (current -> data -> ID == id) {
                    break;
                }
                previous = current;
                current = current -> next;
            }

            if (current == nullptr) {
                cout<<"ID not found\n";
            }
            if (Tail == current) {
                Tail = previous;
            }
            else {

                previous -> next = current -> next;
                delete current -> data;
                delete current;
                Length--;

            }

        }

    }

    void Print(){

        Node *current = Head;
        while (current != nullptr){
            cout<<current->data -> Name<<"         "<< current -> data -> ID <<"         " << current -> data -> GPA;
            cout <<endl;
            current = current -> next;
        }

    }

    void Search (int id) {

        Node *current = Head;
        while (current != nullptr) {
            if (current -> data -> ID == id) {
                cout<<current->data -> Name<<"         "<< current -> data -> ID <<"         " << current -> data -> GPA<<endl;
                return;
            }
            current = current -> next;
        }

        cout<<"Student not found!\n";

    }

    int size() const{
        return Length;
    }

};


class DoublyLinkedList {

private:

    struct Node {
        char Character;
        Node *next;
        Node *prev;
    };

    Node *Head;
    Node *Tail;
    int Length;

public:

    DoublyLinkedList() {
        Head = Tail = nullptr;
        Length = 0;
    }

    bool isEmpty() {
        return (Head == nullptr);
    }

    void InsertFirst(char character) {

        Node *newNode = new Node;
        newNode->Character = character;

        if (Length == 0) {
            Head = Tail = newNode;
            newNode->next = newNode->prev = nullptr;
        } else {

            newNode->next = Head;
            newNode->prev = nullptr;
            Head->prev = newNode;
            Head = newNode;

        }
        Length++;
    }

    void InsertLast(char character) {

        Node *newNode = new Node;
        newNode->Character = character;

        if (Length == 0) {

            Head = Tail = newNode;
            newNode->next = newNode->prev = nullptr;

        } else {

            newNode->prev = Tail;
            newNode->next = nullptr;
            Tail->next = newNode;
            Tail = newNode;

        }
        Length++;
    }
    void InsertAtPosition(char character, int pos) {
        if (pos < 0 || pos > Length) {
            cout << "Out of range\n";
            return;
        }

        if (pos == 0) {
            InsertFirst(character);
        } else if (pos == Length) {
            InsertLast(character);
        } else {
            Node *newNode = new Node;
            newNode->Character = character;

            Node *current;
            int midpoint = Length / 2;

            if (pos <= midpoint) {
                current = Head;
                for (int i = 1; i < pos; i++) {
                    current = current->next;
                }
            } else {
                current = Tail;
                for (int i = Length - 1; i > pos; i--) {
                    current = current->prev;
                }
            }

            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;

            Length++;
        }
    }

    void RemoveFirst() {

        if (Length == 0) {
            cout << "Empty list\n";
            return;
        } else if (Length == 1) {
            delete Head;
            Head = Tail = nullptr;
        } else {
            Node *current = Head;
            Head = Head->next;
            Head->prev = nullptr;
            delete current;
        }
        Length--;
    }

    void RemoveLast() {

        if (Length == 0) {
            cout << "Empty list\n";
            return;
        } else if (Length == 1) {

            delete Head;
            Head = Tail = nullptr;

        } else {

            Node *current = Tail;
            Tail = Tail->prev;
            Tail->next = nullptr;
            delete current;

        }
        Length--;
    }

    void RemoveAtPosition(int pos) {

        if (pos < 0 || pos > Length) {
            cout << "Out of range\n";
            return;
        } else {

            if (pos == 0) {
                RemoveFirst();
            }

            else if (pos == Length - 1) {
                RemoveLast();
            }

            else {

                Node *current = Head->next;
                Node *prev = Head;
                for (int i = 1; i < pos; i++) {
                    prev = current;
                    current = current->next;
                }

                prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                Length--;

            }

        }

    }

    void Concatenate(DoublyLinkedList &list) {

        if (list.isEmpty()) {
            cout << "list to concatenate is empty\n";
            return;
        }

        if (this->Head == nullptr) {
            this->Head = list.Head;
            this->Tail = list.Tail;
        } else {
            this->Tail->next = list.Head;
            this->Tail->next->prev = this->Tail;
            this->Tail = list.Tail;
        }
        this->Length += list.Length;

    }

    string ExtractSubString (int start,int length) {

        if (start < 0 || start >= Length || length <=0) {

            return "oops cant extract";
        }


        Node *current = Head;

        for (int i = 0;i<start;i++) {
            current = current -> next;
        }
        string substring="";
        for (int i = 0;i<length;i++) {
            substring += current ->Character;
            current = current -> next;
        }
        return substring;

    }

    int Search (string substring) {

        if (substring == "") {
            return -1;
        }

        Node * current = Head;
        int idx1 = 0;

        while (current != nullptr) {
            int idx2 = 0;
            while (current != nullptr && current -> Character == substring[idx2]) {
                idx2++;
                current = current->next;
            }
            if (substring[idx2] == '\0') {
                return idx1;
            }
            idx1++;
            current = current -> next;

        }

        return -1;

    }


    void Print(){

        Node *current = Head;
        while (current != NULL){
            cout<<current->Character;
            current = current -> next;
        }
        cout<<endl;
    }

    void Replace(const string& oldSubstr, const string& newSubstr)
    {
        int oldLen = oldSubstr.size();
        int newLen = newSubstr.size();

        Node* current = Head;
        while (current != nullptr) {
            bool found = true;
            Node* temp = current;

            for (int i = 0; i < oldLen; ++i) {
                if (temp == nullptr || temp->Character != oldSubstr[i]) {
                    found = false;
                    break;
                }
                temp = temp->next;
            }

            if (found)
            {
                Node* prev = current->prev;
                Node* next = temp;
                for (int i = 0; i < newLen; ++i) {
                    Node* newNode = new Node;
                    newNode->Character = newSubstr[i];
                    newNode->prev = prev;
                    if (prev == nullptr)
                        Head = newNode;
                    else
                        prev->next = newNode;
                    prev = newNode;
                    Length++;
                }
                if (next != nullptr)
                    next->prev = prev;
                else
                    Tail = prev;
                prev->next = next;

                current = next;
            } else
            {
                current = current->next;
            }
        }
    }

    void Reverse()
    {
        Node *next, *cur, *prev;

        prev = NULL;
        cur = Head;
        next = cur->next;

        while(next != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        Head = prev;
    }

};

int main() {



    StudentList list;
    Student *s11 = new Student("mike",20,3.5);
    Student *s22 = new Student("essam",10,3.6);
    Student *s33 = new Student("mazen",40,3.7);
    Student *s44 = new Student("yasser",50,3.8);
    Student *s55 = new Student("mona",60,3.9);

    list.InsertAndSort(s11);
    list.InsertAndSort(s22);
    list.InsertAndSort(s33);
    list.InsertAndSort(s44);

    cout <<"Name          ID         GPA\n";
    list.Print();
    cout<<"-------------------------\n";
    list.RemoveById(40);
    list.RemoveById(10);
    list.InsertAndSort(s55);
    list.Print();
    cout<<"-------------------------\n";
    list.Search(20);
    cout<<"Linked List size : ";
    cout<<list.size()<<endl;


    DoublyLinkedList list1;
    DoublyLinkedList list2;

    string s1;
    cout << "Enter string in list 1: ";
    cin >> s1;

    for (int i = 0;i < s1.size();i++) {
        list1.InsertAtPosition(s1[i],i);
    }

    string s2;
    cout << "Enter string in list 2: ";
    cin >> s2;
    for (int j = 0;j < s2.size();j++) {
        list2.InsertAtPosition(s2[j],j);
    }

    cout<<"Concatenated Lists: ";
    list1.Concatenate(list2);
    list1.Print();

    int index1;
    cout <<"Choose a character By index to remove: ";
    cin >> index1;
    list1.RemoveAtPosition(index1);
    list1.Print();

    int i1, i2;
    cout<<"Enter index and length to get substring: ";
    cin>>i1>>i2;
    cout<<"substring: "<<list1.ExtractSubString(i1,i2)<<endl;

    string search;
    cout<<"Search for a string in the list: ";
    cin>>search;
    cout<<"Found at index "<<list1.Search(search)<<endl;

    string ss1,ss2;
    cout<<"Enter two substrings to replace one with another: ";
    cin>>ss1>>ss2;
    cout<<"List after replacement: ";
    list1.Replace(ss1,ss2);
    list1.Print();

    cout<<"Reversed List: ";
    list1.Reverse();
    list1.Print();
    return 0;
}