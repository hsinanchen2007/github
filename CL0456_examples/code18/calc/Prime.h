#ifndef __PRIME_H__
#define __PRIME_H__

#include "BigInt.h"

/*****************************************************************
RSA�����B��
Rab�A�Ի��̰Ǻt��k�i���ƴ���
Euc�A�ڴX���o�t��k�D�ѦP�E��{
RsaTrans�A�ϴ_����t��k�i�澭�ҹB��
GetPrime�A���ͫ��w���ת��H���j���
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