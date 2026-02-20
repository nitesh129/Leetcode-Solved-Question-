class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=5) return n;
    
    vector<int>ugly(n);
    ugly[0] = 1;
    int i2=0,i3=0,i5=0;
    for(int i=1;i<n;i++){
        int nexttwo = ugly[i2]*2;
        int nextthree = ugly[i3]*3;
        int nextfive = ugly[i5]*5;

        int nextugly = min({nextfive,nextthree, nexttwo});
        ugly[i] = nextugly;
        

        if(nextugly == nexttwo)i2++;
        if(nextugly == nextthree)i3++;
        if(nextugly == nextfive)i5++;
    }
    return ugly[n-1];
    }
};