#include <cassert>
#include <stdexcept>

// TODO: Define class Pyramid
class Pyramid
{
// public class members
    public:
// constructor
    Pyramid(int l,int w,int h)
    {
        Length(l);
        Width(w);
        Height(h); 
    }

// accessors
    int Length(){return length;}
    int Width(){return width;}
    int Height(){return height;}

// mutators
    void Length(int l){
        if(l>0)
            length=l;
        else
            throw "invalid invarient";
    }
    void Width(int w){if(w>0)width=w;}
    void Height(int h){if(h>0)height=h;}

// public Volume() function
        int Volume(){return (length*width*height)/3;}

// private class members
    private:
    int length;
    int width;
    int height;
    int volume;
};
// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}