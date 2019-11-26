#include <iostream>
#include <string>
using namespace std;
 
 class Resume{
 	private:
 		string m_name;
 		int m_age;
 		string m_cellNumber;
 	public:
 		Resume(string name,int age,string cellNumber):m_name(name),m_age(age),m_cellNumber(cellNumber){}
		
 		void setName(string name){
 			m_name = name;
		}
		void setAge(int age){
			m_age = age;
		}
		void setCellNumber(string cellNumber){
			m_cellNumber = cellNumber;
		}
		Resume *clone(){
			Resume *res = new Resume(*this);
			return res;
		} 
		void printMsg(){
			cout << m_name <<" "<< m_age << " " << m_cellNumber << endl;
		}
		
 };
 
int main(int argc,char *argv[])
{
	Resume *resume = new Resume("Tom",17,"177****4323");
	for(int i = 0; i<10; i++){
		Resume *res = resume->clone();/* �������캯���Ĺ���ʱ��ԶԶС�ڹ��캯���Ĺ���ʱ�� */
		res->printMsg();
	}
	return 0;
}
