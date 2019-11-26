#include <iostream> 
#include <string>
using namespace std;
class Data{/* ���� */
	protected:
		string m_data;
	public:
		virtual void printData(){
			cout << "Data: " <<m_data << endl;
		}
		Data(string data):m_data(data){}
		virtual ~Data(){}
};

class PrivateData:public Data{/* ��˽������ */
	public:
		PrivateData(string data):Data(data){}
		virtual void printData(){
			cout << "Private data: " <<m_data << endl;
		}
		virtual ~PrivateData(){}
}; 

class PublicData:public Data{/* ���������� */
	public:
		PublicData(string data):Data(data){}
		virtual void printData(){
			cout << "Public data: " <<m_data << endl;
		}
		virtual ~PublicData(){}
	};
	
class Decorator:public Data{/* װ�������� */
	protected:
		Data *m_Data;
	public:
		Decorator(Data *data):m_Data(data),Data("this is a Decorator"){}
		~Decorator(){}
};

class EncipheredData:public Decorator{/* һ��װ���� */
	public:
		EncipheredData(Data *data):Decorator(data){}
		virtual void printData(){
			cout << "Encrypt the data..." << endl; 
			m_Data->printData();
		}
};
int main(int argc,char *argv[])
{
	Data *privateData = new PrivateData("2333");/* ��˽���� */
	Data *encipheredPrivateData = new EncipheredData(privateData);/* ������˽���� */
	encipheredPrivateData->printData();
	return 0;
}











