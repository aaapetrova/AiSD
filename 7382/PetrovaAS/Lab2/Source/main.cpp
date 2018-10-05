#include "hierarchial_list.h"

using namespace std;
using namespace h_list;

typedef unsigned long ul;

void print_list(list<char> &mList);

int main (){

    cout << "Enter your hierarchial list: \n"
    lisp s1;
    list<char> mList;
    cout << "Linear list after processing:  ";
    read_lisp (s1);

    write_lisp (s1, mList);
    mList.sort();
    mList.unique();

    print_list(mList);
    destroy (s1);

    return 0;
}

void print_list(list<char> &mList) { // Вывод списка аргументов в консоль
    ul i=0;
    if(mList.empty()) {
        cout << "List is empty, cause hierarchial list has no atoms.\n";
        return;
    }
    list<char> :: iterator it;  // обьект итератора (спец. переменная stl контейнеров таких как vector stack и прочих, для обозначения положения указателя на нужный элемент контейнера)
    for (it = mList.begin(); it != mList.end(); it++, i++) {
        if(i == mList.size()-1) {
            cout << (*it);
            break;
        }
        cout << (*it) << " <-> ";
    }
    cout << '\n' << "Count of different elements [" << i+1 << "]\n";
}
