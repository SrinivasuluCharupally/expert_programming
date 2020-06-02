// Template Method desing pattern (behavioural desing technique)
//Before
//============
//The SortUp and SortDown classes are almost identical. There is a massive opportunity for reuse - if - the embedded comparison could be refactored.

class SortUp
{
    // Shell sort
  public:
    void sort(int v[], int n)
    {
        for (int g = n / 2; g > 0; g /= 2)
          for (int i = g; i < n; i++)
            for (int j = i - g; j >= 0; j -= g)
              if (v[j] > v[j + g])
                doSwap(v[j], v[j + g]);
    }
  private:
    void doSwap(int &a, int &b)
    {
        int t = a;
        a = b;
        b = t;
    }
};

class SortDown
{
  public:
    void sort(int v[], int n)
    {
        for (int g = n / 2; g > 0; g /= 2)
          for (int i = g; i < n; i++)
            for (int j = i - g; j >= 0; j -= g)
              if (v[j] < v[j + g])
                doSwap(v[j], v[j + g]);
    }
  private:
    void doSwap(int &a, int &b)
    {
        int t = a;
        a = b;
        b = t;
    }
};

int main()
{
  const int NUM = 10;
  int array[NUM];
  srand((unsigned)time(0));
  for (int i = 0; i < NUM; i++)
  {
    array[i] = rand() % 10+1;
    cout << array[i] << ' ';
  }
  cout << '\n';

  SortUp upObj;
  upObj.sort(array, NUM);
  for (int u = 0; u < NUM; u++)
    cout << array[u] << ' ';
  cout << '\n';

  SortDown downObj;
  downObj.sort(array, NUM);
  for (int d = 0; d < NUM; d++)
    cout << array[d] << ' ';
  cout << '\n';
  system("pause");
}
Output
3 10 5 5 5 4 2 1 5 9
1 2 3 4 5 5 5 5 9 10
10 9 5 5 5 5 4 3 2 1


// After
//============
// The common implementation has been moved to an abstract base class, and a "placeholder" has been defined to encapsulate the embedded comparison.
// All that remains for the SortUp and SortDown classes is to implement that placeholder.

class AbstractSort
{
    // Shell sort
  public:
    void sort(int v[], int n)
    {
        for (int g = n / 2; g > 0; g /= 2)
          for (int i = g; i < n; i++)
            for (int j = i - g; j >= 0; j -= g)
              if (needSwap(v[j], v[j + g]))
                doSwap(v[j], v[j + g]);
    }
  private:
    virtual int needSwap(int, int) = 0;
    void doSwap(int &a, int &b)
    {
        int t = a;
        a = b;
        b = t;
    }
};

class SortUp: public AbstractSort
{
    /* virtual */
    int needSwap(int a, int b)
    {
        return (a > b);
    }
};
class SortDown: public AbstractSort
{
    /* virtual */
    int needSwap(int a, int b)
    {
        return (a < b);
    }
};

int main()
{
  const int NUM = 10;
  int array[NUM];
  srand((unsigned)time(0));
  for (int i = 0; i < NUM; i++)
  {
    array[i] = rand() % 10+1;
    cout << array[i] << ' ';
  }
  cout << '\n';

  AbstractSort *sortObjects[] = 
  {
    new SortUp, new SortDown
  };
  sortObjects[0]->sort(array, NUM);
  for (int u = 0; u < NUM; u++)
    cout << array[u] << ' ';
  cout << '\n';

  sortObjects[1]->sort(array, NUM);
  for (int d = 0; d < NUM; d++)
    cout << array[d] << ' ';
  cout << '\n';
  system("pause");
}
/*
Output
1 6 6 2 10 9 4 10 6 4
1 2 4 4 6 6 6 9 10 10
10 10 9 6 6 6 4 4 2 1
*/