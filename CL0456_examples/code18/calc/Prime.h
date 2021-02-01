#ifndef __PRIME_H__
#define __PRIME_H__

#include "BigInt.h"

/*****************************************************************
RSA相關運算
Rab，拉賓米勒演算法進行質數測試
Euc，歐幾里得演算法求解同余方程
RsaTrans，反復平方演算法進行冪模運算
GetPrime，產生指定長度的隨機大質數
*****************************************************************/
int RabPrimeTest(const CBigInt& prime);
//CBigInt Euc(CBigInt& A);
CBigInt RsaTrans(const CBigInt& N, const CBigInt& A, const CBigInt& B);
CBigInt GetBigIntPrime(int bits);

CBigInt ExtEuclid(const CBigInt& a, const CBigInt& b, CBigInt& x, CBigInt& y);
CBigInt CongruenceEquation(const CBigInt& a, const CBigInt& n);
__int64 CongruenceEquation64(__int64 a, __int64 n);
CBigInt ModularPower(const CBigInt& M, const CBigInt& E, const CBigInt& N);
CBigInt MontgomeryModularPower(const CBigInt& M, const CBigInt& E, const CBigInt& N);
bool MillerRabin(const CBigInt& n);
bool IsPrimeNumber(const CBigInt& n);
CBigInt GeneratePrime(int bits);


#endif //__PRIME_H__