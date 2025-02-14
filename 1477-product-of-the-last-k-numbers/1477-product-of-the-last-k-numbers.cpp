class ProductOfNumbers {
public:
    vector<int> prods;
    ProductOfNumbers() {
        prods = {1};
    }
    void add(int num)
    {
        if(num==0)
        {
            prods.clear();
            prods.push_back(1);
        }
        else
            prods.push_back(prods.back()*num);
    }
    int getProduct(int k)
    {
        if(k>=prods.size())
            return 0;
        return prods.back()/(prods[prods.size()-k-1]);
    }
};