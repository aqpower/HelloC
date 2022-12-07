#include "iostream"
#include "bitset"
using namespace std;

int main()
{
    
    int n;
    int t = 5;
    while (t--) {
        cin >> n;
        int temp = n, j = 1;
        int ans = 0;
        while(temp){
		    ans = ans + j * (temp % 2);
		    temp = temp / 2;
		    j = j * 10;
	    }
        cout << n << "-->" << ans << '\n';
    }
    
    return 0;
}
