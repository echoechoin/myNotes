#include <iostream>
using namespace std;

class Shape{/* �ӿ��� */
public:
	virtual void draw() = 0;
};
/* �ӿڵ�ʵ���� */
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

/* ������������ */
class ShapeFactory{
public:
	virtual Shape *getShape() = 0;
}; 
/* Rectangle���� */
class RectangleFactory :public ShapeFactory{
public:
	Shape *getShape(){
		return new Rectangle;
	}
};
/* Square���� */
class SquareFactory :public ShapeFactory{
public:
	Shape *getShape(){
		return new Square;
	}
}; 
/* Circle���� */
class CircleFactory :public ShapeFactory{
public:
	Shape *getShape(){
		return new Circle;
	}	
};  
/* MainProcess������ ShapeFactory��������һ��ʵ��*/
class MainProcess{
private:
	ShapeFactory *m_shapeFactory;
public:	
	MainProcess(ShapeFactory *shapeFactory):m_shapeFactory(shapeFactory){}
	void run()
	{
		Shape *rectangle =m_shapeFactory->getShape();/* �麯���Ķ�̬ */
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
 
