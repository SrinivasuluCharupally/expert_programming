Observer design pattern(Behavioural design technique)

//Before

//The number and type of "user interface" (or dependent) objects is hard-wired in the Subject class. The user has no ability to affect this configuration.

class DivObserver
{
    int m_div;
  public:
    DivObserver(int div)
    {
        m_div = div;
    }
    void update(int val)
    {
        cout << val << " div " << m_div << " is " << val / m_div << '\n';
    }
};

class ModObserver
{
    int m_mod;
  public:
    ModObserver(int mod)
    {
        m_mod = mod;
    }
    void update(int val)
    {
        cout << val << " mod " << m_mod << " is " << val % m_mod << '\n';
    }
};

class Subject
{
    int m_value;
    DivObserver m_div_obj;
    ModObserver m_mod_obj;
  public:
    Subject(): m_div_obj(4), m_mod_obj(3){}
    void set_value(int value)
    {
        m_value = value;
        notify();
    }
    void notify()
    {
        m_div_obj.update(m_value);
        m_mod_obj.update(m_value);
    }
};

int main()
{
  Subject subj;
  subj.set_value(14);
}
/*
Output
14 div 4 is 3
14 mod 3 is 2
*/

//After
//=======
//The Subject class is now decoupled from the number and type of Observer objects. The client has asked for two DivObserver delegates (each configured differently), and one  ModObserver delegate.

class Observer
{
  public:
    virtual void update(int value) = 0;
};




class ModObserver: public Observer
{
    int m_mod;
  public:
    ModObserver(Subject *model, int mod)
    {
        model->attach(this);
        m_mod = mod;
    }
     /* virtual */void update(int v)
    {
        cout << v << " mod " << m_mod << " is " << v % m_mod << '\n';
    }
};

class DivObserver: public Observer
{
    int m_div;
  public:
    DivObserver(Subject *model, int div)
    {
        model->attach(this);
        m_div = div;
    }
     /* virtual */void update(int v)
    {
        cout << v << " div " << m_div << " is " << v / m_div << '\n';
    }
};

class Subject
{
    int m_value;
    vector<Observer> m_views;
  public:
    void attach(Observer *obs)
    {
        m_views.push_back(obs);
    }
    void set_val(int value)
    {
        m_value = value;
        notify();
    }
    void notify()
    {
        for (int i = 0; i < m_views.size(); ++i)
          m_views[i]->update(m_value);
    };
};


int main()
{
  Subject subj;
  DivObserver divObs1(&subj, 4);
  DivObserver divObs2(&subj, 3);
  ModObserver modObs3(&subj, 3);
  subj.set_val(14);
}
/*
Output
14 div 4 is 3
14 div 3 is 4
14 mod 3 is 2
*/