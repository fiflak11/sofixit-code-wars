#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int material(deque<int> lines){
    int fluid{0};
    for(int i=*max_element(lines.begin(),lines.end()); i>0; i--){ //at the beginning i is the biggest "column" in lines
        //DELETE 0 FROM EDGES OF LINES
        while(lines.size() && !lines.front())
            lines.pop_front();
        while(lines.size() && !lines.back())
            lines.pop_back();
        //ZEROES COUNTING
        for(auto& cell : lines)
            if(!cell)
                fluid++;
            else
                cell--;
    }
    return fluid;
}

int main()
{
    deque<int> test1 = {6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3};
    deque<int> test2 = {6, 2, 1, 1, 8, 0, 5, 5, 0, 1, 8, 9, 6, 9, 4, 8, 0, 0};
    deque<int> test3 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; //from images
    deque<int> test4 = {0, 1, 0, 2, 1, 0, 3, 1, 0, 1, 2};
    deque<int> test5 = {4, 2, 0, 3, 2, 5};
    deque<int> test6 = {0, 1, 0, 2, 1, 0, 3, 1, 2};
    deque<int> test7 = {0, 3, 2, 0, 3, 2, 0, 4, 2};
    deque<int> test8 = {1,2,3,5,1,2,4,0,0,3,2,3,4,0,7,0,12,0,12,0,0,0,10,0,0,6,0,0};
    cout<<material(test8);
    return 0;
}
