#include <iostream>

void hanoi(char rod1, char rod2, char rod3, int x)
{
    if (x == 1) 
    { //base case
        std::cout << "moved disk 1 from " << rod1 << " to rod " << rod2 << std::endl;
        return;
    }
    hanoi(rod1, rod3, rod2, x-1);
    std::cout << "moved disk " << x << " from rod " << rod1 << " to rod " << rod2 << std::endl;
    hanoi(rod3, rod2, rod1, x-1);
}

int main() 
{
    hanoi('a', 'c', 'b', 2);
    std::cout << std::endl;
    return 0;
}
