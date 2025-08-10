//class to implement Nodes of a DLL
class Node {
public:
    int key, val;
    Node* next;
    Node* prev;
    //Constructors
    Node(){
        key = val = -1;
        next = prev = NULL;
    }
    Node(int k, int value){
        key = k;
        val = value;
        next = prev = NULL;
    }
};
//class implementing LRU Cache
class LRUCache {
private:
    map<int, Node*> mp;
    int cap;
    Node* head;
    Node* tail;

    void deleteNode(Node* node){
        //get pointers 
        Node* prevnode = node->prev;
        Node* nextnode = node->next;
        //remove pointers to node
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }
    void insertAfterHead(Node* node){
        Node* nextnode = head->next;
        head->next = node;
        nextnode->prev = node;
        node->prev = head;
        node->next = nextnode;
    }

  public:

  LRUCache(int capacity) { //O(1)
   cap = capacity; //set the capacity
   mp.clear(); //clear the cache
   head = new Node();
   tail = new Node();
   //make the connections
   head->next = tail;
   tail->prev = head;
  }

  int get(int key_) { //O(n) acc to map
    //not present in cache
    if(mp.find(key_) == mp.end()) return -1;

    Node* node = mp[key_]; //get the code
    int val = node->val; //get the value
    deleteNode(node);
    insertAfterHead(node); //it is recently used
    return val;
  }

  void put(int key_, int value) { //acc to map O(n)
    if(mp.find(key_) != mp.end()){
        Node* node = mp[key_];
        node->val = value;
        deleteNode(node);
        insertAfterHead(node);
        return;
    }
    if(mp.size() == cap){
        Node* node = tail->prev;
        mp.erase(node->key);
        deleteNode(node);
    }
    Node* newnode = new Node(key_, value);
    mp[key_] = newnode;
    insertAfterHead(newnode);
  }
};

TC = O(N), SC = O(Cap)