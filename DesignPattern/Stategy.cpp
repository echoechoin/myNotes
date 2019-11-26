#include <iostream> 
using namespace std;
class Strategy{
	public:
		virtual void algorithm() = 0;
};

class Algorithm{
	private:
		Strategy *m_strategy;/* 策略用接口实现 */
	public:
		Algorithm(Strategy* strategy):m_strategy(strategy){}
		void callAlgorith()
		{
			m_strategy->algorithm();/* 调用策略的算法 */
		}
}; 

class Strategy1:public Strategy{/* 策略1 */
	virtual void algorithm()
	{
		cout << "Strategy1 called" << endl;
	}
};

class Strategy2:public Strategy{/* 策略2 */
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

