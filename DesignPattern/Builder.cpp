#include <iostream>
#include <string>
using namespace std;
class HouseBuildDerectorBase{
	public:
		virtual void step1() = 0;
		virtual void step2() = 0;
		virtual void step3() = 0;
		virtual void step4() = 0;
		virtual void step5() = 0;
};
/* 稳定的步骤 */
class HouseBuild{
	private:
		HouseBuildDerectorBase *m_houseBuildDerector;
	public:
		HouseBuild(HouseBuildDerectorBase *houseBuildDerector):m_houseBuildDerector(houseBuildDerector){}
		void Build(){
			m_houseBuildDerector->step1();
			m_houseBuildDerector->step2();
			m_houseBuildDerector->step3();
			m_houseBuildDerector->step4();
			m_houseBuildDerector->step5();
		}
}; 
/* 不稳定的实现 */
class HouseBuildDerector1: public HouseBuildDerectorBase{
	public:
		void step1(){
			cout << "step1" << endl;
		}
		void step2(){
			cout << "step2" << endl;
		}
		void step3(){
			cout << "step3" << endl;
		}
		void step4(){
			cout << "step4" << endl;
		}
		void step5(){
			cout << "step5" << endl;
		}
};
int main(int argc,char *argv[])
{
	HouseBuild *houseBuild = new HouseBuild(new HouseBuildDerector1);
	houseBuild->Build();
	return 0;
}
