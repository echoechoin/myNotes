#include <iostream> 
#include <string>
using namespace std;
class Data{/* 基类 */
	protected:
		string m_data;
	public:
		virtual void printData(){
			cout << "Data: " <<m_data << endl;
		}
		Data(string data):m_data(data){}
		virtual ~Data(){}
};

class PrivateData:public Data{/* 隐私数据类 */
	public:
		PrivateData(string data):Data(data){}
		virtual void printData(){
			cout << "Private data: " <<m_data << endl;
		}
		virtual ~PrivateData(){}
}; 

class PublicData:public Data{/* 公开数据类 */
	public:
		PublicData(string data):Data(data){}
		virtual void printData(){
			cout << "Public data: " <<m_data << endl;
		}
		virtual ~PublicData(){}
	};
	
class Decorator:public Data{/* 装饰器基类 */
	protected:
		Data *m_Data;
	public:
		Decorator(Data *data):m_Data(data),Data("this is a Decorator"){}
		~Decorator(){}
};

class EncipheredData:public Decorator{/* 一个装饰器 */
	public:
		EncipheredData(Data *data):Decorator(data){}
		virtual void printData(){
			cout << "Encrypt the data..." << endl; 
			m_Data->printData();
		}
};
int main(int argc,char *argv[])
{
	Data *privateData = new PrivateData("2333");/* 隐私数据 */
	Data *encipheredPrivateData = new EncipheredData(privateData);/* 加密隐私数据 */
	encipheredPrivateData->printData();
	return 0;
}











