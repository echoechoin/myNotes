#include <iostream>
#include <string>
using namespace std;

/* ������� */
class Component1{
	protected:
		string m_componentDesc;
	public:
		virtual string getComponentDesc() = 0;
		Component1(string componentDesc):m_componentDesc(componentDesc){}
		virtual ~Component1(){}
}; 
class Component2{
	protected:
		string m_componentDesc;
	public:
		virtual string getComponentDesc() = 0;
		Component2(string componentDesc):m_componentDesc(componentDesc){}
		virtual ~Component2(){}
}; 
class Component3{
	protected:
		string m_componentDesc;
	public:
		virtual string getComponent3Desc() = 0;
		Component3(string componentDesc):m_componentDesc(componentDesc){}
		virtual ~Component3(){}
}; 

/* ��Ʒ1����� */
class Product1Component1: public Component1{/* ���1 */
	public:
		Product1Component1(string componentDesc):Component1(componentDesc){}
		string getComponent1Desc(){return m_component1Desc;	}
};
class Product1Component2: public Component2{/* ���2 */
	public:
		Product1Component2(string componentDesc):Component2(componentDesc){}
		string getComponent2Desc(){return m_component2Desc;	}
};
class Product1Component3: public Component3{/* ���3 */
	public:
		Product1Component3(string componentDesc):Component3(componentDesc){}
		string getComponent3Desc(){return m_component3Desc;	}
};

/* ���󹤳����� */
class AbstractFactory{
	public:
		virtual Component1 *createComponent1() = 0;
		virtual Component2 *createComponent2() = 0;
		virtual Component3 *createComponent3() = 0;
};


/* ��Ʒ1���󹤳��� */
class Product1Factory:public AbstractFactory{
	public:
		virtual Component1 *createComponent1(){
			return new Product1Component1("Product1Component1"); 
		}
		virtual Component2 *createComponent2(){
			return new Product1Component2("Product1Component2"); 
		}
		virtual Component3 *createComponent3(){
			return new Product1Component3("Product1Component3"); 
		}
}; 


/* �����װ�� �������������ʵ����*/
class Assembly{
	private:
		Component1 *component1;
		Component2 *component2;
		Component3 *component3;
	public:
		Assembly(AbstractFactory *aF){
			component1 = aF->createComponent1();
			component2 = aF->createComponent2();
			component3 = aF->createComponent3();
		}
		void startAssembly()
		{
			cout << component1->getComponent1Desc() << " " \
				 << component2->getComponent2Desc() << " " \
				 << component3->getComponent3Desc()
				 << endl;
		}
}; 
int main(int argc, char *argv[])
{
	Assembly as(new Product1Factory);
	as.startAssembly();
	return 0;
}
