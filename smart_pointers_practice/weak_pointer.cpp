#include <iostream>
#include <memory>

int main()
{
  std::cout << std::boolalpha << std::endl;

  auto sharedptr = std::make_shared<int>(2011);
  std::weak_ptr<int> weakptr(sharedptr);

  std::cout << "weak ptr.use_count(): " << weakptr.use_count() << std::endl;
  std::cout << "shared ptr .use count()" << sharedptr.use_count() << std::endl;
  /* weak pointer is a reference to shared pointer
     it cant hold a resource by itself
     .expired() tell us weather weaker ptr still reference to shared pointer
   */
  std::cout << " weakptr .use count()" << weakptr.expired() << std::endl;

  if (std::shared_ptr<int> sharedptr1 = weakptr.lock())
  {
    std::cout << "sharedptr : " << *sharedptr << std::endl;
    std::cout << "sharedptr1 : " << *sharedptr1 << std::endl;
    std::cout << "shared ptr .use count()" << sharedptr.use_count() << std::endl;
  }
  else
  {
    std::cout << "Dont get the resource " << std::endl;
  }

  weakptr.reset();

  if (std::shared_ptr<int> sharedptr1 = weakptr.lock())
  {
    std::cout << "sharedptr : " << *sharedptr << std::endl;
    std::cout << "sharedptr1 : " << *sharedptr1 << std::endl;
    std::cout << "shared ptr .use count()" << sharedptr.use_count() << std::endl;
  }
  else
  {
    std::cout << "Dont get the resource " << std::endl;
  }
}