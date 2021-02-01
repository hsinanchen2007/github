// chinese_num.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <cassert>

//using namespace std;

const int CHN_NUM_CHAR_COUNT = 10;
const int CHN_CHAR_LENGTH = 2;

const char *chnNumChar[CHN_NUM_CHAR_COUNT] = { "�s", "�@", "�G", "�T", "�|", "��", "��", "�C", "�K", "�E" };
const char *chnUnitChar[] = { "", "�Q", "��", "�d" };
const char *chnUnitSection[] = { "", "�U", "��", "�U��" };

typedef struct 
{
    const char *name; //�����v��W��
    int value; //10�����ƭ�
    bool secUnit; //�O�_�O�`�v��
}CHN_NAME_VALUE;

CHN_NAME_VALUE chnValuePair[] = 
{
    { "�Q", 10, false }, { "��", 100, false }, { "�d", 1000, false }, 
    { "�U", 10000, true }, { "��", 100000000, true }
};



void SectionToChinese(unsigned int section, std::string& chnStr)
{
    chnStr.clear();
    std::string strIns;
    int unitPos = 0;
    bool zero = true;
    while(section > 0)
    {
        int v = section % 10;
        if(v == 0)
        {
            if( (section == 0) || !zero )
            {
                zero = true; /*�ݭn��0�Azero���@�άO�T�O��s�򪺦h��0�A�u�ɤ@�Ӥ���s*/
                chnStr.insert(0, chnNumChar[v]);
            }
        }
        else
        {
            zero = false; //�ܤ֦��@�ӼƦr���O0
            strIns = chnNumChar[v]; //���줸����������Ʀr
            strIns += chnUnitChar[unitPos]; //��������������v��
            chnStr.insert(0, strIns); 
        }
        unitPos++; //����
        section = section / 10;
    }
}

//num == 0�ݭn�S��B�z�A������^"�s"
void NumberToChinese(unsigned int num, std::string& chnStr)
{
    chnStr.clear();
    int unitPos = 0;
    std::string strIns;
    bool needZero = false;

    if(num == 0)
    {
        chnStr = chnNumChar[0];
        return;
    }

    while(num > 0)
    {
        unsigned int section = num % 10000;
        if(needZero)
        {
            chnStr.insert(0, chnNumChar[0]);
        }
        SectionToChinese(section, strIns);
        /*�O�_�ݭn�`�v��H*/
        strIns += (section != 0) ? chnUnitSection[unitPos] : chnUnitSection[0]; 
        chnStr.insert(0, strIns);
        /*�d��O0�H�ݭn�b�U�@��section�ɹs*/
        needZero = (section < 1000) && (section > 0); 
        num = num / 10000;
        unitPos++;
    }
}

int ChineseToValue(const std::string& chnStr)
{
    for(int val = 0; val < sizeof(chnNumChar) / sizeof(chnNumChar[0]); val++)
    {
        if(chnStr.compare(chnNumChar[val]) == 0)
        {
            return val;
        }
    }

    return -1;
}

int ChineseToUnit(const std::string& chnStr, bool& secUnit)
{
    for(int unit = 0; unit < sizeof(chnValuePair) / sizeof(chnValuePair[0]); unit++)
    {
        if(chnStr.compare(chnValuePair[unit].name) == 0)
        {
            secUnit = chnValuePair[unit].secUnit;
            return chnValuePair[unit].value;
        }
    }

    return 1;
}

unsigned int ChineseToNumber(const std::string& chnString)
{
    unsigned int rtn = 0;
    unsigned int section = 0;
    int number = 0;
    bool secUnit = false;
    std::string::size_type pos = 0;
    
    while(pos < chnString.length())
    {
        int num = ChineseToValue(chnString.substr(pos, CHN_CHAR_LENGTH));
        if(num >= 0) /*�Ʀr�٬O���H*/
        {
            number = num;
            pos += CHN_CHAR_LENGTH;
            if(pos >= chnString.length())//�p�G�O�̫�@��Ʀr�A��������
            {
                section += number;
                rtn += section;
                break;
            }
        }
        else
        {
            int unit = ChineseToUnit(chnString.substr(pos, CHN_CHAR_LENGTH), secUnit);
            if(secUnit)//�O�`�v�컡���@�Ӹ`�w�g����
            {
                section = (section + number) * unit;
                rtn += section;
                section = 0;
            }
            else
            {
                section += (number * unit);
            }
            number = 0;
            pos += CHN_CHAR_LENGTH;
            if(pos >= chnString.length())
            {
                rtn += section;
                break;
            }
        }
    }

    return rtn;
}

typedef struct 
{
    int num;
    const char *chnNumStr;
}TEST_DATA;

TEST_DATA testPair[] = 
{
    {0, "�s"},
    {1, "�@"},
    {2, "�G"},
    {3, "�T"},
    {4, "�|"},
    {5, "��"},
    {6, "��"},
    {7, "�C"},
    {8, "�K"},
    {9, "�E"},
    {10, "�@�Q"},
    {11, "�@�Q�@"},
    {110, "�@�ʤ@�Q"},
    {111, "�@�ʤ@�Q�@"},
    {100, "�@��"},
    {102, "�@�ʹs�G"},
    {1020, "�@�d�s�G�Q"},
    {1001, "�@�d�s�@"},
    {1015, "�@�d�s�@�Q��"},
    {1000, "�@�d"},
    {10000, "�@�U"},
    {20010, "�G�U�s�@�Q"},
    {20001, "�G�U�s�@"},
    {100000, "�@�Q�U"},
    {1000000, "�@�ʸU"},
    {10000000, "�@�d�U"},
    {100000000, "�@��"},
    {1000000000, "�@�Q��"},
    {1000001000, "�@�Q���@�d"},
    {1000000100, "�@�Q���s�@��"},
    {200010, "�G�Q�U�s�@�Q"},
    {2000105, "�G�ʸU�s�@�ʹs��"},
    {20001007, "�G�d�U�@�d�s�C"},
    {2000100190, "�G�Q���s�@�Q�U�s�@�ʤE�Q"},
    {1040010000, "�@�Q���|�d�s�@�U"},
    {200012301, "�G���s�@�U�G�d�T�ʹs�@"},
    {2005010010, "�G�Q���s���ʹs�@�U�s�@�Q"},
    {4009060200, "�|�Q���s�E�ʹs���U�s�G��"},
    {4294967295, "�|�Q�G���E�d�|�ʤE�Q���U�C�d�G�ʤE�Q��"}
};

void testNumberToChinese()
{
    std::string chnNum;

    for(int i = 0; i < sizeof(testPair)/sizeof(testPair[0]); i++)
    {
        NumberToChinese(testPair[i].num, chnNum);
        assert(strcmp(chnNum.c_str(), testPair[i].chnNumStr) == 0);
    }
}

void testChineseToNumber()
{
    for(int i = 0; i < sizeof(testPair)/sizeof(testPair[0]); i++)
    {
        unsigned int num = ChineseToNumber(testPair[i].chnNumStr);
        assert(num == testPair[i].num);
    }
}

int main(int argc, char* argv[])
{
    testNumberToChinese();
    testChineseToNumber();
	return 0;
}

