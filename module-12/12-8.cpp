// Copy Node: Write a method that takes a pointer to a Node structure as a parameter and returns a complete copy of the passed in data structure. The Node data structure contains two pointers to other Nodes.

// source https://stackoverflow.com/questions/7681174/interview-coding-take-a-pointer-to-a-node-structure-as-a-parameter-and-return

#include<iostream>
#include<memory>
#include<string.h>
#include<map>
#include<deque>

using namespace std;


typedef struct Node
{
    Node(int _data) : data(_data) { memset(links, 0, sizeof(links)); }

    int data;
    Node *links[2];
} Node;

Node* Copy(Node *root)
{
    typedef std::map<Node*, Node*> NodeMap;
    NodeMap nodeMap;
    std::deque<Node*> nodesToVisit;

    // Set up initial new root and mapping for the root
    Node *newRoot = new Node(root->data);
    nodeMap[root] = newRoot;

    // Breadth-first search the graph
    nodesToVisit.push_back(root);

    while(!nodesToVisit.empty())
    {
        Node *cur = nodesToVisit.front();
        nodesToVisit.pop_front();

        Node *newCur = nodeMap[cur];
        for(int i = 0; i < 2; i++)
        {
            Node *link = cur->links[i];
            if(link)
            {
                // If we've already created the corresponding node for this
                // link, use that.  Otherwise, create it and add it to the map.
                NodeMap::iterator mappedLink = nodeMap.find(link);
                if(mappedLink != nodeMap.end())
                {
                    newCur->links[i] = mappedLink->second;
                }
                else
                {
                    Node *newLink = new Node(link->data);
                    nodeMap[link] = newLink;
                    newCur->links[i] = newLink;
                    nodesToVisit.push_back(link);
                }
            }
        }
    }
}

int main() { 
}
