#include <iostream>
using namespace std;

class Shape{/* 接口类 */
public:
	virtual void draw() = 0;
};
/* 接口的实体类 */
class Rectangle : public Shape{
public:
	void draw(){
		cout << "draw a rectangle" << endl;
	}
};
class Square : public Shape{
public:
	void draw(){
		cout << "draw a square" << endl;
	}
};
class Circle : public Shape{
public:
	void draw(){
		cout << "draw a circle" << endl;
	}
};

/* 创建工厂基类 */
class ShapeFactory{
public:
	virtual Shape *getShape() = 0;
}; 
/* Rectangle工厂 */
class RectangleFactory :public ShapeFactory{
public:
	Shape *getShape(){
		return new Rectangle;
	}
};
/* Square工厂 */
class SquareFactory :public ShapeFactory{
public:
	Shape *getShape(){
		return new Square;
	}
}; 
/* Circle工厂 */
class CircleFactory :public ShapeFactory{
public:
	Shape *getShape(){
		return new Circle;
	}	
};  
/* MainProcess不依赖 ShapeFactory到底是哪一个实例*/
class MainProcess{
private:
	ShapeFactory *m_shapeFactory;
public:	
	MainProcess(ShapeFactory *shapeFactory):m_shapeFactory(shapeFactory){}
	void run()
	{
		Shape *rectangle =m_shapeFactory->getShape();/* 虚函数的多态 */
		rectangle->draw();
		delete m_shapeFactory;
		delete rectangle
	} 
};
int main(int argc ,char *argv[])
{
	MainProcess mainProcess(new RectangleFactory);
	mainProcess.run();
	
	return 0;
}
 
