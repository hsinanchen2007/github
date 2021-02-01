#ifndef __BIG_INT_H__
#define __BIG_INT_H__

#include <string>

#define MAX_BI_LEN   256

#define DEC 10
#define HEX 16

#define MSBIT ((unsigned long)1 << 31)
#define OBITS (MSBIT - 1)

class CBigInt
{
public:
    CBigInt();
    ~CBigInt();
    CBigInt(const CBigInt& value);
    CBigInt(__int64 value);

    int ToInt();
    bool IsZero() const;
    bool IsEven() const;
    CBigInt GetNegative() const;

    const CBigInt& operator=(__int64 value);
	const CBigInt& operator=(const CBigInt& value);
    bool operator<(const CBigInt& value) const;
    bool operator<=(const CBigInt& value) const;
    bool operator==(const CBigInt& value) const;
    bool operator!=(const CBigInt& value) const;
    bool operator>(const CBigInt& value) const;
    bool operator>=(const CBigInt& value) const;

	CBigInt operator+(const CBigInt& value) const;
	const CBigInt& operator+=(const CBigInt& value);
	CBigInt operator-(const CBigInt& value) const;
	const CBigInt& operator-=(const CBigInt& value);
	CBigInt operator*(const CBigInt& value) const;
	const CBigInt& operator*=(const CBigInt& value);
	CBigInt operator/(const CBigInt& value) const;
	const CBigInt& operator/=(const CBigInt& value);
	CBigInt operator%(const CBigInt& value) const;
	const CBigInt& operator%=(const CBigInt& value);
	CBigInt operator^(const CBigInt& n) const;
	const CBigInt& operator^=(const CBigInt& n);
	CBigInt operator << (__int64 bits) const;
	const CBigInt& operator <<=(__int64 bits);
	CBigInt operator >> (__int64 bits) const;
	const CBigInt& operator >>=(__int64 bits);

    /*俱计巨*/
    void GetRightBigN(unsigned int N, CBigInt& rightN);
    int GetBigNCount() const { return m_nLength; };
    bool ShiftLeftBigN(unsigned int N);
    void ShiftRightBigN(unsigned int N);
    void RemRightBigN(unsigned int N);
    void TrimRightBigN(unsigned int N);


    bool TestBit(__int64 bits) const;
    __int64 GetTotalBits() const;
    /*戈锣传ざ*/
    void GetFromString(const char* str, unsigned int system=HEX);
    void PutToString(std::string& str, unsigned int system=HEX);
    void GetLong(unsigned long *values, unsigned int count);
    int PutLong(unsigned long *values, unsigned int bufLen);
	int  GetFromData(const char *pData, int nBytes);//龟悔计
	int  PutToData(char *pBuffer, int nBufferBytes);//戈じ舱计

    static CBigInt GenRandomInteger(__int64 bits);

protected:
    void ZeroData(unsigned int length);
    void SetValue(const CBigInt& value);
    void SetValue(__int64 value);
    int CompareNoSign(const CBigInt& value) const; 
    static void Add(const CBigInt& value1, const CBigInt& value2, CBigInt& result);
    static void Sub(const CBigInt& value1, const CBigInt& value2, CBigInt& result);
    static void Mul(const CBigInt& value1, const CBigInt& value2, CBigInt& result);
    static void Div(const CBigInt& value1, const CBigInt& value2, CBigInt& quotient, CBigInt& mod);
    static void Mod(const CBigInt& value1, const CBigInt& value2, CBigInt& result);
    static void Power(const CBigInt& value, const CBigInt& n, CBigInt& result);
    static void ShiftLeft(const CBigInt& value, __int64 bits, CBigInt& result);
    static void ShiftRight(const CBigInt& value, __int64 bits, CBigInt& result);

public:
    //才腹じ0ボタ计1ボ璽计
    unsigned int m_Sign;
    //计0x100000000秈计计    
    unsigned int m_nLength;
    //ノ皚癘魁计0x100000000秈–
    unsigned long m_ulValue[MAX_BI_LEN];
};


#endif //__BIG_INT_H__