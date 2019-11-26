#include <iostream> 
using namespace std;
class Strategy{
	public:
		virtual void algorithm() = 0;
};

class Algorithm{
	private:
		Strategy *m_strategy;/* �����ýӿ�ʵ�� */
	public:
		Algorithm(Strategy* strategy):m_strategy(strategy){}
		void callAlgorith()
		{
			m_strategy->algorithm();/* ���ò��Ե��㷨 */
		}
}; 

class Strategy1:public Strategy{/* ����1 */
	virtual void algorithm()
	{
		cout << "Strategy1 called" << endl;
	}
};

class Strategy2:public Strategy{/* ����2 */
	virtual void algorithm()
	{
		cout << "Strategy2 called" << endl;
	}
};
int main(int argc, char *argv[])
{	
	Strategy *strategy = new Strategy2;
	Algorithm *algorithm= new Algorithm(strategy);
	algorithm->callAlgorith();
	return 0;
}

