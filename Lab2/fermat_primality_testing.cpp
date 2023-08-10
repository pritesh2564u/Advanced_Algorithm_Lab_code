#include <iostream>
#define int unsigned long long int
using namespace std;

int gcd(int a, int b) {
	while(b != 0) {
    	int r = a % b;
    	a = b;
    	b = r;
	}
	return a;
}

int power(int a, int x, int n) {
	int res = 1;
	a = a % n;
	while(x > 0) {
    	if(x & 1) {
        	res = (res * a) % n;
    	}
    	x = x >> 1;
    	a = (a * a) % n;
	}
	return res;
}

bool isPrime(int n) {
	if(n <= 1 || n == 4)
    	return false;
	if(n <= 3)
    	return true;
	int k = 100;
	while(k > 0) {
    	int a = 2 + rand() % (n - 4);
    	if(gcd(n, a) != 1)
        	return false;
    	if(power(a, n - 1, n) != 1)
        	return false;
    	k--;
	}
	return true;
}

signed main()
{
	int num;
	cin >> num;
	if(isPrime(num))
    	cout <<  num << " is a prime" << endl;
	else
    	cout << num << " is not a prime" << endl;
	int count = 0;
	for(int i = 2 ; i < num - 1 ; i++) {
    	if(power(i, num - 1, num) == 1)
        	count++;
	}
	cout << count << endl;
	return 0;
}