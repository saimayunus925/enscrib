**ENSCRIB: A FILE ENCRYPTION/DECRYPTION APP**

This is a simple C++ application that encrypts/decrypts files using the RSA algorithm.

**ALGORITHM**

The RSA algorithm is a widely used public-key cryptosystem for secure data transmission. It relies on the mathematical properties of large prime numbers. Here are the key steps involved in the RSA algorithm:

Key Generation:
* Choose two large prime numbers, p and q.
* Calculate their product, n = p * q. The security of the algorithm relies on the difficulty of factoring the product of two large primes.
* Compute Euler's totient function, φ(n) = (p-1) * (q-1).
* Choose an integer e such that 1 < e < φ(n) and e is coprime (has no common factors other than 1) with φ(n).
* Compute the private key d such that (d * e) mod φ(n) = 1. In other words, d is the modular multiplicative inverse of e modulo φ(n).
* The public key is (n, e), and the private key is (n, d).

Encryption:
* Represent the plaintext message as an integer m, where 0 < m < n.
* Compute the ciphertext c using the public key (n, e) and the encryption formula:
c = (m^e) mod n.

Decryption:
* Compute the original message m using the private key (n, d) and the decryption formula:
m = (c^d) mod n

**PLAN FOR FUTURE UPDATES**
* Write the AES and DES encryption/decryption algorithms, and use those to similarly encrypt the plaintext file and decrypt the ciphertext.
