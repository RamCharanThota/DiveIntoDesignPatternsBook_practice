/*
func(std::unique_ptr<int>) --- func takes ownership of resource
func(std::unique_ptr<int> &) -- func might reset int

*/

#include <iostream>
#include <memory>

using namespace std;

int gobal_val = 30;

/*
1) pass by pointer is passing a pointer by value
2) copy of pointer is passed to the function and changes to pointe (not its value) wont be reflect outside
3)  so  in func_pointer function the pointer value cannot be changed to point to global value
 */
void func_pointer(int* int_ptr)
{
  int_ptr = &gobal_val;
}

/*
1) it can be solved by passing the pointer to the pointer as pointer value can be changed
 */
void func_pointer_to_pointer(int** int_ptr)
{
  *int_ptr = &gobal_val;
}

/*
1) it can also be solved by passing the refernce to the pointer
 */
void func_pointer_reference(int*& int_ptr)
{
  int_ptr = &gobal_val;
}

int main()
{
  int val = 20;
  int* ptr = &val;
  cout << "Passing a pointer to function" << endl;
  func_pointer(ptr);
  cout << "after :" << *ptr << endl;  // display 23
  cout << "Passing a pointer to a pointer to function" << endl;
  func_pointer_to_pointer(&ptr);
  cout << "after :" << *ptr << endl;  // display 23
  cout << "Passing a refernce to a pointer to function" << endl;
  func_pointer_reference(ptr);
  cout << "after :" << *ptr << endl;  // display 23
}