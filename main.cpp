#include <iostream>
#include <math.h>
#include<iomanip>
using namespace std;

//�������븨������ Point����������������Point��ĳ�Ա����
class Point{
public:
    Point(double a,double b){
        x=a;
        y=b;
    }
    double getx() const{
        return this->x;
    }
    double gety() const{
        return this->y;
    }
private:
    double x;
    double y;
};
// ��ս���

class Triangle {
public:
    Triangle(Point p1, Point p2, Point p3);
    Triangle(const Triangle & t);
    bool isLargerThan(const Triangle &t);//�����ǰ������������ t �����������true�����򷵻� false
    double getArea() const;

private:
    Point _p1, _p2, _p3;
};

//���������Triangle �ĳ�Ա����
Triangle::Triangle(Point p1, Point p2, Point p3):_p1(p1),_p2(p2),_p3(p3){}
Triangle::Triangle(const Triangle &t):_p1(t._p1),_p2(t._p2),_p3(t._p3){}
bool Triangle::isLargerThan(const Triangle &t){
    if(this->getArea()>t.getArea())
        return true;
    else
        return false;
}
double Triangle::getArea() const{
    double p;
    p=_p1.getx()*_p2.gety()+_p2.getx()*_p3.gety()+_p3.getx()*_p1.gety()-_p1.getx()*_p3.gety()-_p2.getx()*_p1.gety()-_p3.getx()*_p2.gety();
    return p;
}
//��ս���

int main()
{
    double x1, x2, x3, y1, y2, y3;
    cin >>x1>>y1>>x2>>y2>>x3>>y3;
    Point p11(x1,y1), p12(x2,y2), p13(x3,y3);
    Triangle t1(p11,p12,p13);

    cin >>x1>>y1>>x2>>y2>>x3>>y3;
    Point p21(x1,y1), p22(x2,y2), p23(x3,y3);
    Triangle t2(p21,p22,p23);

    if(t1.isLargerThan(t2))
        cout<<"the first triangle's area is larger than the second one's";
    else
        cout<<"the first triangle's area is not larger than the second one's";
    return 0;
}
