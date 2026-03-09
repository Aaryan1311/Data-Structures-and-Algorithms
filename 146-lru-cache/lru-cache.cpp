class Node {
    public:
    int val,key;
    Node* prev;
    Node* next;
    Node(int key, int val){
        this->key = key;
        this->val = val;
    }
};


class LRUCache {
public:
    int cap;
    Node* dummy_head = new Node(-1,-1);
    Node* dummy_tail = new Node(-1,-1);
    map<int,Node*> mp;
    LRUCache(int capacity) {
        this->cap = capacity;
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = dummy_head->next;
            node->prev = dummy_head;
            dummy_head->next->prev = node;
            dummy_head->next = node;
            return node->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = dummy_head->next;
            node->prev = dummy_head;
            dummy_head->next->prev = node;
            dummy_head->next = node;
            node->val = value;
        }
        else{
            Node* node = new Node(key, value);
            node->next = dummy_head->next;
            node->prev = dummy_head;
            dummy_head->next->prev = node;
            dummy_head->next = node;
            mp[key] = node;
        }
        if(mp.size() > cap){
            mp.erase(dummy_tail->prev->key);
            dummy_tail->prev->prev->next = dummy_tail;
            dummy_tail->prev = dummy_tail->prev->prev;
        }
    }

};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */