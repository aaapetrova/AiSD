#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
typedef unsigned long ul;

class ListElement {
public:
    ListElement* next;
    ListElement* prev;
    char liter;
};

class ListStack {
public:
    ListStack() {
        mSize = 0;
    }
    ~ListStack() {
        while(!empty())
            pop_Back();
    }

// Вставка в элемента в конец стэка
    void push_Back(char &data){ 
        ListElement* ptr = new ListElement;
        if(!mSize) {
            root = ptr;
            end = ptr;
            ptr->next = NULL;
            ptr->prev = NULL;
        } else {
            ptr->next = NULL;
            ptr->prev = end;
            end->next = ptr;
            end = ptr;
        }
        ptr->liter = data;
        mSize++;
    }

// Удаление элемента 
    void pop_Back(){ 
        if(!mSize)
            error_Handler(1);
        else if(mSize == 1) {
            delete root;
            root = NULL;
            end = NULL;
        } else {
            end = end->prev;
            delete end->next;
            end->next = NULL;
        }
        mSize--;
    }
// Вывод в поток stream и удаление стэка
    void clear(ofstream &mStream){ 
        while(!empty()) {
            mStream << top();
            pop_Back();
        }
        mStream << '\n';
    }

    char top(){
        if(!mSize)
            error_Handler(2);
        return end->liter;
    }

    bool empty(){
        if(!mSize)
            return true;
        else
            return false;
    }

private:

    void error_Handler(ul descriptor){
        if(descriptor == 1) {
            cerr << "[ERROR] Trying to pop() in empty stack." << endl;
            exit(1);
        } else if(descriptor == 2) {
            cerr << "[ERROR] Trying to top() in empty stack." << endl;
            exit(1);
        }
    }

    ul mSize;
    ListElement* root;
    ListElement* end;
};

int main()
{
    string str;
    string filePath;
    cin >> filePath;

// Поток файловый входной
    ifstream mInFile; 

    mInFile.open(filePath, std::ifstream::binary);
    if(!mInFile){
        cerr << "[ERROR] Invalid filepath.";
        exit(1);
    }

// Поток файловый выходной
    ofstream mOutFile; 
    mOutFile.open("output.txt", std::ofstream::binary);

// Считывая построчно файл, записываем символы в стэк
    while(getline(mInFile, str, '\n')) {  
        ListStack mStack;
        for(ul it = 0; it<str.size(); it++)
            mStack.push_Back(str[it]);
        mStack.clear(mOutFile); // Вывод в поток
    }
    return 0;
}
