// Flyweight design pattern (structural design pattern)

// Before
// Trying to use objects at very low levels of granularity is nice, but the overhead may be prohibitive. Flyweight suggests removing the non-shareable state from the class, and having the client supply it when methods are called. This places more responsibility on the client, but, considerably fewer instances of the Flyweight class are now created. Sharing of these instances is facilitated by introducing a Factory class that maintains a "cache" of existing Flyweights.

//In this example, the "X" state is considered shareable (within each row anyways), and the "Y" state has been externalized (it is supplied by the client when report() is called).

class Gazillion
{
  public:
    Gazillion()
    {
        m_value_one = s_num / Y;
        m_value_two = s_num % Y;
        ++s_num;
    }
    void report()
    {
        cout << m_value_one << m_value_two << ' ';
    }
    static int X, Y;
  private:
    int m_value_one;
    int m_value_two;
    static int s_num;
};

int Gazillion::X = 6, Gazillion::Y = 10, Gazillion::s_num = 0;

int main()
{
  Gazillion matrix[Gazillion::X][Gazillion::Y];
  for (int i = 0; i < Gazillion::X; ++i)
  {
    for (int j = 0; j < Gazillion::Y; ++j)
      matrix[i][j].report();
    cout << '\n';
  }
/*
  Output
00 01 02 03 04 05 06 07 08 09
10 11 12 13 14 15 16 17 18 19
20 21 22 23 24 25 26 27 28 29
30 31 32 33 34 35 36 37 38 39
40 41 42 43 44 45 46 47 48 49
50 51 52 53 54 55 56 57 58 59
*/


// After
//================
class Gazillion
{
  public:
    Gazillion(int value_one)
    {
        m_value_one = value_one;
        cout << "ctor: " << m_value_one << '\n';
    }
    ~Gazillion()
    {
        cout << m_value_one << ' ';
    }
    void report(int value_two)
    {
        cout << m_value_one << value_two << ' ';
    }
  private:
    int m_value_one;
};

class Factory
{
  public:
    static Gazillion *get_fly(int in)
    {
        if (!s_pool[in])
          s_pool[in] = new Gazillion(in);
        return s_pool[in];
    }
    static void clean_up()
    {
        cout << "dtors: ";
        for (int i = 0; i < X; ++i)
          if (s_pool[i])
            delete s_pool[i];
        cout << '\n';
    }
    static int X, Y;
  private:
    static Gazillion *s_pool[];
};

int Factory::X = 6, Factory::Y = 10;
Gazillion *Factory::s_pool[] = 
{
  0, 0, 0, 0, 0, 0
};

int main()
{
  for (int i = 0; i < Factory::X; ++i)
  {
    for (int j = 0; j < Factory::Y; ++j)
      Factory::get_fly(i)->report(j);
    cout << '\n';
  }
  Factory::clean_up();
}

/*
Output
ctor: 0
00 01 02 03 04 05 06 07 08 09
ctor: 1
10 11 12 13 14 15 16 17 18 19
ctor: 2
20 21 22 23 24 25 26 27 28 29
ctor: 3
30 31 32 33 34 35 36 37 38 39
ctor: 4
40 41 42 43 44 45 46 47 48 49
ctor: 5
50 51 52 53 54 55 56 57 58 59
dtors: 0 1 2 3 4 5
*