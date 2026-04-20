/* 

----- Observer Design Pattern -----

Observer Design Pattern is a way to make sure that when something important changes in one part of your program, all the other parts that care about it get updated right away.
It's called a one-to-many relationship because one main object (the subject)  can have many other objects (the observers) watching it. When the subject changes, it tells all its 
observers so they can update themselves. This is super helpful when you want different parts of your program to always show the lastest information, but you don't want them to 
be tightly connected or mixed together. 

Sometimes people mix up the Observer Design Pattern with the Mediator Design Pattern. The difference is important: in the Observer Pattern, the subject keeps a list of observers
and tells them when something changes. In the Mediator Pattern, there's a special mediator object in the middle that helps different objects talk to each other, so they don't talk 
directly. The Observer Pattern is all about keeping things in sync, while the Mediator Pattern is about organizing communication. 

--- Components of Observer Design --- 

The observer design pattern consists of the following main components: 

1) Subject - This is the main object that has some important information or state. When something changes inside the subject, it lets others know about it. The subject keeps a list 
             of all people (observers) who want to know when something changes. For example, a wether app updating multiple devices. 

2) Observer - An observer is anyone who wants to know when the subject changes. Observers sign up with the subject, and whenever there is an update, the subject tells all its observers.
              In our weather app example, the other devices are observers because they show the latest weather whenever the data changes. 

3) Concrete Subject - This is a real, working version of the subject. It actually stores the data and knows how to tell the observers when something changes. In the weather app, the Weather Data
                      class is the concrete subject because it keeps the weather info and notifies the displays. 

4) Concrete Observer - This is a real, working version of an observer. It knows how to react when the subject tells it about a change. In the weather app, the WeatherDisplay class is a concrete observer
                       because it updates what it shows whenever the weather changes. 

--- Conclusion --- 

In this chapter, you learned about the Observer Design Pattern, how it works, its good and bad sides, and where it is used in real life. This pattern is very helpful for making programs where changes in one
part need to be shared with many other parts, that keeps everything up to date and easy to manage. 

*/

#include <iostream>
#include <string>
#include <vector> 
using namespace std; 


class Observer{ 
    public: 
        virtual void update(float tempature, float humidity, float pressure) = 0;
};

class WeatherDisplay : public Observer { 
    private: 
        float tempature;
        float humidity;
        float pressure; 

    public: 
        void update(float temp, float hum, float pres) override { 
            tempature = temp;
            humidity = hum;
            pressure = pres;
            display();
        }
        void display() { 
            cout << "Weather Update - Temperature: " << tempature
                 << ", Humidity: " << humidity
                 << ", Pressure: " << pressure << endl;
        }
};

// Subject interface
class Subject {
    public: 
        virtual void attach(Observer* observer) = 0;
        virtual void detach(Observer* observer) = 0;
        virtual void notify() = 0;
};

// Concrete Subject class
class WeatherData : public Subject {
    private: 
        vector<Observers*> observers;
        float tempature;
        float humidity;
        float pressure;

    public: 
        void attach(Observer* observer) override{
            observers.push_back(observer);
        }
        void detach(Observer* observer) override{
            observers.erase(remove(observers.begin(), observers.end(), observer), observer.end());
        }
        void notify() override {
            for (Observer* observer : observers){
                observer->update(tempature, humidity, pressure);
            }
        }
        void setMeasurements(float temp, float hum, float pres){
            tempature = temp;
            humidity = hum;
            pressure = pres; 
            notify();
        }
};

int main(){
    WeatherData weatherData;

    WeatherDisplay display1;
    WeatherDisplay display2;

    weatherData.attach(&display1);
    weatherData.attach(&display2);

    weatherData.setMeasurements(112.1, 43.2, 12.2);
    weatherData.setMeasurements(151.1, 28.1, 32.2);

    weatherData.detach(&display1);
    weatherData.deatch(&display2);

    return 0;
}