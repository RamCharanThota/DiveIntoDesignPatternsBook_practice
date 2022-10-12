/* composite pattern example
- that lets you compose objects in to tree structures
- then work with these structures as if they were individual objects
- it makes only sense when your program represented as a tree
 */

#include <iostream>
#include <vector>
#include <string>

class Graphic
{
public:
  virtual void move(int x, int y) = 0;
  virtual void draw() = 0;
};

class Dot : public Graphic
{
protected:
  int x_, y_;

public:
  Dot(int x, int y)
  {
    x_ = x;
    y_ = y;
  }

  void move(int x, int y)
  {
    this->x_ += x;
    this->y_ += y;
  }

  void draw()
  {
    std::cout << "drawing the dot at x:" << this->x_ << " y:" << this->y_ << std::endl;
  }
  Dot()=default;
};

class Circle : public Dot
{
  int radius_;

public:
  Circle(int x, int y, int radius)
  {
    x_ = x;
    y_ = y;
    radius_ = radius;
  }

  void move(int x, int y)
  {
    this->x_ += x;
    this->y_ += y;
  }

  void draw()
  {
    std::cout << "drawing the circle at x:" << this->x_ << " y:" << this->y_ << "with radius: " << this->radius_
              << std::endl;
  }
};

class CompoundGraphic : public Graphic
{
  std::vector<Graphic*> children_;

public:
  void add(Graphic* child)
  {
    children_.push_back(child);
  }

  void remove(Graphic* child)
  {
    std::vector<Graphic*>::iterator it;
    for (it = children_.begin(); it != children_.end(); it++)
    {
      if (*it == child)
      {
        children_.erase(it);
        break;
      }
    }
  }

  void move(int x, int y)
  {
    for (auto child_list : children_)
    {
      child_list->move(x, y);
    }
  }

  void draw()
  {
    for (auto child_list : children_)
    {
      child_list->draw();
    }
  }
};
class ImageEditor
{
  Dot* dot_;
  Circle* circle_;
  CompoundGraphic cg_;

public:
  ImageEditor()
  {
    dot_ = new Dot(1, 2);
    circle_ = new Circle(5, 3, 10);
  }
  void load()
  {
    

    cg_.add(dot_);
    cg_.add(circle_);

  }

  void move(int x,int y){
    cg_.move(x,y);
  }

  void draw(){
    cg_.draw();
  }

  ~ImageEditor()
  {
    delete dot_;
    delete circle_;
  }
};

int main()
{
  ImageEditor id;
  id.load();
  id.move(4,5);
  id.draw();
}