class LRUCache {
public:
    int capacity, time;
    map<int,pair<int,int>> cache; // key -> value, timeStamp
    map<int,int> timeStamp;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->time = 0;
    }
    
    int get(int key) {
        
        if(cache.find(key) != cache.end())
        {
            // inside cache so update timestamp
            cache[key].second = this->time++;
            return cache[key].first;
        }
        this->time++;
        return -1;
    }
    
    void put(int key, int value) {
        
        if(cache.size() <= this->capacity)
        {
            cache[key] = make_pair(value,this->time++);
        }
        
        else
        {
            // evict the least recently used data
            int keyVictim=0, minTime = INT_MAX;
            for(auto itr=cache.begin(); itr != cache.end(); itr++)
            {
                // find the min timestamp to evict
                if((itr->second).second == 0)
                {
                    keyVictim = itr->first;
                    break;
                }
                
                if((itr->second).second < minTime)
                {
                    minTime = (itr->second).second;
                    keyVictim = itr->first;
                }
            }
            
            // key is present
            cache.erase(keyVictim);
            cache[key] = make_pair(value, this->time++);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// my thinking
// map for putting value ofc
// how to get least recently use
// need to find a victim
// generally we use timestaming
// max 2*10^5 calls made
// make a pq 


// another implementation can be maintain a doubly linked list that maintains the nodes with key value and keep the order
// maintain another key->node* map for O(1) get calls
// update DLL for put calls
// least recently node = tail -> prev (previous of tail node)