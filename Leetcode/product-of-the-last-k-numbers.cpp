class ProductOfNumbers {
public:
    vector<int>arr = {1};
    ProductOfNumbers() {
        

    }
    
    void add(int num) {
        if(num==0){
            arr = {1};
            return;
        } 
        arr.push_back(arr[arr.size()-1] * num);
    }
    
    int getProduct(int k) {
        if(arr.size() > k) return arr[arr.size()-1]/arr[arr.size()-k-1];
        else return 0;
        
    }
};

// https://leetcode.com/problems/product-of-the-last-k-numbers/

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */