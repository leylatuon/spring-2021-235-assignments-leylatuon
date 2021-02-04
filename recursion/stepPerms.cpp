#include <iostream>

int stepPerms(int n)
{
   if(n==0||n==1)
   {
       return 1;
   }
   else if(n==2)
   {
       return 2;
   }  
   else
   {
       return stepPerms(n-3) + stepPerms(n-2) + stepPerms(n-1);
   }
}

int main()
{
    std::cout << stepPerms(5) << std::endl; //print 13
}
