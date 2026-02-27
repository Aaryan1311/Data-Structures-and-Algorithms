class Node{
public:
    int key, val;
    Node *prev, *next;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        prev = next = nullptr;
    }
};

void insertAfterHead(Node* node, Node* head){
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    node->prev = head;
}

void deleteNode(Node* node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

class LRUCache {
public:
    unordered_map<int,Node*> mp;   // better than map
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];

        // move to front
        deleteNode(node);
        insertAfterHead(node, head);

        return node->val;
    }
    
    void put(int key, int value) {

        if(mp.find(key) != mp.end()){
            Node* existing = mp[key];
            deleteNode(existing);
            mp.erase(key);
            delete existing;
        }

        if(mp.size() == cap){
            Node* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key,value);
        insertAfterHead(node,head);
        mp[key] = node;
    }
};