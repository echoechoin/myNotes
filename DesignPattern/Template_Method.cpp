#include <iostream> 
using namespace std; 
class Library{/* ¿â */
	public:
		virtual void step1(){cout << "step1" << endl;}
		virtual void step3(){cout << "step3" << endl;}
		void run()
		{
			cout << "begin" << endl;
			step1();
			step2();
			step3();
			step4();
			cout << "end" << endl;
		}
	protected:
		virtual void step2() = 0;
		virtual void step4() = 0;	
};
class Application:public Library{/* Ó¦ÓÃ */ 
	virtual void step2(){cout << "step2" << endl;};
	virtual void step4(){cout << "step4" << endl;};
}; 
int main(int argc,char *argv[])
{
	Library * app = new Application;
	app->run();
	return 0;
}
