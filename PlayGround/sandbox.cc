#include<FISH.h>
#include <iostream>
class SandBox : public Fish::Application
{
public:
  SandBox()
  {

  }
  ~SandBox()
  {
 
  }
};

Fish::Application *  Fish::CreateApplication() {
	return new SandBox();
}
