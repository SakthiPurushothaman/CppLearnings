class Observer
{
  public:
  virtual void update(float temp)=0;
  virtual ~ Observer() = default;
};


class Subject
{
    public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void notifyObservers(Observer* observer) =0;
};

class WeatherStation : public Subject
{
   public:
   
};

class LCDdisplay : public Observer
{

};

class PhoneDisplay : public Observer
{

};

int main()
{
    return 0;
}