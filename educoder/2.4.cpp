#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <string>
#include <iostream>

typedef struct  stack
{
	char *base;
	char *top;
	int stacksize;

    void push(char val) {
        top += 1;
        base[++stacksize] = val; 
    };
    char pop() {
        top -= 1;
        return base[stacksize--];
    };
    bool empty() {
        return !stacksize;
    }
}stack;

void Initstack(stack& L) {
    const int N = 10000000;
    L.base = new char[N];
    L.top = L.base;
    L.stacksize = 0;

    std::string val = ""; std::cin >> val;
    for (int i = 0; i < val.size(); i++) L.push(val[i]);
    // char ch;
    // while (std::cin >> ch) L.push(ch);
};

bool creatstack(stack& L) {
    std::string str1 = "", str2 = "";
    while (!L.empty()) {
        char val = L.pop();
        str1 = str1 + val;
        str2 = val + str2;
    }
    return !str1.compare(str2);
};

int main()
{

	// 实现stack
	stack L;
	Initstack(L);
	printf("%d",creatstack(L));
	return 0;
}
