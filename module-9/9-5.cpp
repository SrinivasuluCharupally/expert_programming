Cache: Imagine a web server for a simplified search engine. This system has 100 machines to
respond to search queries, which may then call out using processSearch(string query)
to another cluster of machines to actually get the result. The machine which responds to a given
query is chosen at random, so you cannot guarantee that the same machine will always respond to
th<> sam<> r<>quest. The method processSearch is very expensive. Design a caching mechanism
to cache the results of the most recent queries. Be sure to explain how you would update the cache
when data changes.
 

Ans: • A linked list would allow easy purging of old data, by moving "fresh" items to the front. We could imple­ ment it to remove the last element of the linked list when the list exceeds a certain size

A hashtable to efficient way of lookup data

public class Cache {public static int M  SIZE= 10;public Node head, tail;public HashMap<String, Node> map;public int size = 0; 
