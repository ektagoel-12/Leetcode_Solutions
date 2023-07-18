class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node * next;
        node * prev;
        node(int _key,int _val)
        {
            key=_key;
            val=_val;
        }
    };
    node* head= new node(-1,-1);
    node* tail= new node(-1,-1);
    int cap;
    unordered_map<int,node*>m;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void deletenode(node* delnode)
    {
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }

    void addnode(node* newnode)
    {
        node* temp=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            node* temp=m[key];
            int res=temp->val;
            m.erase(key);
            deletenode(temp);
            addnode(temp);
            m[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            node* existingnode= m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        node* newnode=new node(key,value);
        addnode(newnode);
        m[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */