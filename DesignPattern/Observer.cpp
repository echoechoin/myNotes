#include <iostream>
#include <list>
using namespace std;
class Observer{/* 观察者基类 */
	public:
		virtual void updateWeather(float temperature,float pressure,float humidity) = 0;
};
class WeatherStation{
	private:
		list<Observer *> m_observerList;
		float m_temperature;
		float m_pressure;
		float m_humidity;
	public:
		WeatherStation(float temperature,float pressure,float humidity):
		m_temperature(temperature),m_pressure(pressure),m_humidity(humidity)
		{
			
		}
		void setData(float temperature,float pressure,float humidity)
		{
			m_temperature = temperature;
			m_pressure = pressure;
			m_humidity = humidity;
			noticeThirdParty(); // 通知第三方 
		}
		void addObserver(Observer *observer)/* 添加观察者 */ 
		{
			m_observerList.push_back(observer);
		}
		void deleteObserver(Observer *observer)/* 删除观察者 */ 
		{
			m_observerList.remove(observer);
		}
	private:
		void noticeThirdParty()
		{
			for(list<Observer *>::iterator i = m_observerList.begin();i != m_observerList.end();i++){
				(*i)->updateWeather(m_temperature,m_pressure,m_humidity);
			}
		} 
		
}; 
class WeatherApp1:public Observer{
	private:
		float m_temperature;
		float m_pressure;
		float m_humidity;
	public:
		virtual void updateWeather(float temperature,float pressure,float humidity)
		{
			m_temperature = temperature;
			m_pressure = pressure;
			m_humidity = humidity;
			cout << temperature << pressure << humidity << endl;
		}
};
class WeatherApp2:public Observer{
	private:
		float m_temperature;
		float m_pressure;
		float m_humidity;
	public:
		virtual void updateWeather(float temperature,float pressure,float humidity)
		{
			m_temperature = temperature;
			m_pressure = pressure;
			m_humidity = humidity;
			cout << temperature << pressure << humidity << endl;
		}
};
int 
main(int argc,char *argv[])
{
	WeatherStation *station = new WeatherStation(1,2,3);
	Observer *weatherApp1 = new WeatherApp1; 
	Observer *weatherApp2 = new WeatherApp2;
	station->addObserver(weatherApp1);
	station->addObserver(weatherApp2);
	station->setData(2,3,5);
	return 0;
}











