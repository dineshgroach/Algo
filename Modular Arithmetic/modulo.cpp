// Negative number modulo is given by :
long long MOD = 1e9+7;
cout << (n % MOD + MOD) % MOD << endl;

// To get nearest multiple after a number
// Assume y=10,k=6 then y1 will be 12 (nearest multiple of 6 after 10)
y1 = (y - (y % k)) + k;

// Modulus for multiplicaton of 2/3 integers
(a * b) % MOD = ((a % MOD) * (b % MOD)) % MOD
(a * b * c) % MOD = ((a % MOD) * (b % MOD) * (c % MOD)) % MOD
