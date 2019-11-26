#include <iostream> 
#include <string>
using namespace std;
class Brand{/* 商标 */
	protected:
		string m_brandName;
	public:
		virtual showMessage() = 0;
		virtual ~Brand(){}
};

class Type{/* 产品类型 */
	protected:
		Brand * m_brand;
	public:
		Type(Brand *brand):m_brand(brand){}
		virtual void showMessage() = 0;		
		virtual ~Type(){}
};

/* 方便添加商标 */
class Lenovo : public Brand{
	public:
		Lenovo(){m_brandName = "Lenovo";}
		virtual showMessage(){cout << m_brandName<< " ";}
};
class Asus : public Brand{
	public:
		Asus(){m_brandName = "Asus";}
		virtual showMessage(){cout << m_brandName << " ";}
};
class Dell : public Brand{
	public:
		Dell(){m_brandName = "Dell";}
		virtual showMessage(){cout << m_brandName << " ";}
};

/*方便添加产品类型*/
class Laptop : public Type{
	public:
		Laptop(Brand *brand):Type(brand){}
		void showMessage(){
			m_brand->showMessage();
			cout << "Laptop" << endl;
		}
};
class PC : public Type{
	public:
		PC(Brand *brand):Type(brand){}
		void showMessage(){
			m_brand->showMessage();
			cout << "PC" << endl;
		}
};

int main(int argc,char *argv[]) 
{
	Type *lenovoLaptop = new Laptop(new Dell);
	lenovoLaptop->showMessage();
	return 0;
}
