#include<iostream>
#include<cmath>

class RoundPeg
{
private:
    int radius_;
public:
 RoundPeg(int radius){
    radius_=radius;
 };
 int getRadius(){
    return radius_;
 }
 RoundPeg()=default;
 ~RoundPeg()=default;
};


class RoundHole
{
private:
    int radius_;
public:
    RoundHole(int radius){
        radius_=radius;
    }
    int getRadius(){
        return radius_;
    }
    bool fits(RoundPeg* peg){
        return this->getRadius()>=peg->getRadius()?true:false;
    }
    ~RoundHole()=default;
};

class SquarePeg
{
private:
    int width_;
public:
    SquarePeg(int width){
        width_=width;
    };
    int getWidth(){
        return width_;
    }
    ~SquarePeg(){

    }
};

class SquarePegAdapter:public RoundPeg {
    private:
    SquarePeg* square_peg_;
    int value;
    public:
    SquarePegAdapter(SquarePeg* peg){
        square_peg_=peg;
    }
    int getRadius(){
        value=square_peg_->getWidth()/sqrt(2);
        return value;
    }
};

int main(){
    RoundHole hole(5);
    RoundPeg rpeg(5);
    SquarePeg small_speg(5);
    SquarePeg large_speg(10);
    std::cout<<"is round peg fits"<<hole.fits(&rpeg)<<std::endl;
    SquarePegAdapter speg_adapter(&small_speg);
    std::cout<<"is round peg fits"<<hole.fits(&speg_adapter)<<std::endl;
    SquarePegAdapter lpeg_adapter(&large_speg);
    std::cout<<"is round peg fits"<<hole.fits(&lpeg_adapter)<<std::endl;
    


}


    