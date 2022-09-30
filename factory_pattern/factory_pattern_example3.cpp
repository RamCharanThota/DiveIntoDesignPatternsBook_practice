#include <iostream>
#include <string>

class ButtonInterface
{
public:
  virtual void render() = 0;
  virtual void onClick() = 0;
};

class WindowsButton : public ButtonInterface
{
public:
  void render()
  {
    std::cout << "windows render function implemented" << std::endl;
  }

  void onClick()
  {
    std::cout << "windows onClick function implemented" << std::endl;
  }
};

class HtmlButton : public ButtonInterface
{
public:
  void render()
  {
    std::cout << "HtmlButton render function implemented" << std::endl;
  }

  void onClick()
  {
    std::cout << "HtmlButton onClick function implemented" << std::endl;
  }
};

class Dialog
{
public:
  virtual ButtonInterface* CreateButton()=0;
  void render();
};

void Dialog::render()
{
  ButtonInterface* okButton = CreateButton();
  okButton->onClick();
  okButton->render();
}

class WindowsDialog : public Dialog
{
public:
  ButtonInterface* CreateButton()
  {
    return new WindowsButton;
  }
};

class WebDialog : public Dialog
{
public:
  ButtonInterface* CreateButton()
  {
    return new HtmlButton;
  }
};

class Application
{
public:
  Dialog* d;
  void initialize()
  {
    std::string config = "";
    std::cout << "choose the config win or web:";
    std::cin >> config;
    try
    {
      if (config == "win")
      {
        d = new WindowsDialog();
      }
      else if (config == "web")
      {
        d = new WebDialog();
      }
      else
      {
        throw std::string("exception ! error");;
      }
    } catch(std::string e){
      std::cout<<e<<std::endl;
    }
  }

  ~Application()
  {
    delete d;
  }
};

int main(){
    Application ap;
    ap.initialize();
    ap.d->render();
}