Mediator design pattern (Behavioral design techniques)
/*
Before
Node objects interact directly with each other, recursion is required, removing a Node is hard, and it is not possible to remove the first node.
*/
class Node
{
  public:
    Node(int v)
    {
        m_val = v;
        m_next = 0;
    }
    void add_node(Node *n)
    {
        if (m_next)
          m_next->add_node(n);
        else
          m_next = n;
    }
    void traverse()
    {
        cout << m_val << "  ";
        if (m_next)
          m_next->traverse();
        else
          cout << '\n';
    }
    void remove_node(int v)
    {
        if (m_next)
          if (m_next->m_val == v)
            m_next = m_next->m_next;
          else
            m_next->remove_node(v);
    }
  private:
    int m_val;
    Node *m_next;
};

int main()
{
  Node lst(11);
  Node two(22), thr(33), fou(44);
  lst.add_node(&two);
  lst.add_node(&thr);
  lst.add_node(&fou);
  lst.traverse();
  lst.remove_node(44);
  lst.traverse();
  lst.remove_node(22);
  lst.traverse();
  lst.remove_node(11);
  lst.traverse();
}
Output
11  22  33  44
11  22  33
11  33
11  33


After
A "mediating" List class focuses and simplifies all the administrative responsibilities, and the recursion (which does not scale up well) has been eliminated.

class Node
{
  public:
    Node(int v)
    {
        m_val = v;
    }
    int get_val()
    {
        return m_val;
    }
  private:
    int m_val;
};

class List
{
  public:
    void add_node(Node *n)
    {
        m_arr.push_back(n);
    }
    void traverse()
    {
        for (int i = 0; i < m_arr.size(); ++i)
          cout << m_arr[i]->get_val() << "  ";
        cout << '\n';
    }
    void remove_node(int v)
    {
        for (vector::iterator it = m_arr.begin(); it != m_arr.end(); ++it)
        if ((*it)->get_val() == v)
        {
            m_arr.erase(it);
            break;
        }
    }
  private:
    vector m_arr;
};

int main()
{
  List lst;
  Node one(11), two(22);
  Node thr(33), fou(44);
  lst.add_node(&one);
  lst.add_node(&two);
  lst.add_node(&thr);
  lst.add_node(&fou);
  lst.traverse();
  lst.remove_node(44);
  lst.traverse();
  lst.remove_node(22);
  lst.traverse();
  lst.remove_node(11);
  lst.traverse();
}
Output
11  22  33  44
11  22  33
11  33
33