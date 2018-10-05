#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
typedef unsigned long ul;

void error_Handler(ul descriptor) {
    if (descriptor == 2) {
        cerr << "[ERROR] Invalid filepath. Aborting!" << endl;
        exit(1);
    }
}

class listElement {
public:
    listElement* next;
    listElement* prev;
    char liter;
};

class listStack {
public:
    listStack() {
        mSize = 0;
    }
    ~listStack() {
        while(!empty())
            pop_Back();
    }

    void push_Back(char &data){ // Вставка в конец
        listElement* ptr = new listElement;
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

    void pop_Back(){ // Удаление
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

    void clear(ofstream &mStream){ // вывод в поток stream и удаление стэка
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
            cerr << "[ERROR] Trying to pop() in empty stack" << endl;
            exit(1);
        } else if(descriptor == 2) {
            cerr << "[ERROR] Trying to top() in empty stack" << endl;
            exit(1);
        }
    }

    ul mSize;
    listElement* root;
    listElement* end;
};


void reverseStrings() // Реверс строк
{
    string str;
    string filePath;
    cin >> filePath;

    ifstream mInFile; // Поток файловый входной
    mInFile.open(filePath, std::ifstream::binary);
    if(!mInFile)
        error_Handler(2);

    ofstream mOutFile; // Поток файловый выходной
    mOutFile.open("output.txt", std::ofstream::binary);

    while(getline(mInFile, str, '\n')) {  // Считывая построчно файл, записываем символы в стэк
        listStack mStack;
        for(ul it = 0; it<str.size(); it++)
            mStack.push_Back(str[it]);
        mStack.clear(mOutFile); // Вывод в поток
    }
}

int main()
{
    reverseStrings();
    return 0;
}
