#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct CString
{
    int length;
    char* chars;
}CString;

CString* cstring_new(const char* str)
{
    CString* cNewString;
    cNewString = malloc(sizeof(CString));
    if(cNewString == 0) return NULL;
    cNewString->length = strlen(str);
    cNewString->chars = malloc(cNewString->length);
    strncpy(cNewString->chars,str,cNewString->length);
    return cNewString;
}

int iStringLength(struct CString* str)
{
    return str->length;
}

char chCharAt(struct CString* str,int index)
{
    if(index >= str->length) return '-';
    return str->chars[index];
}

bool bChangeCharAt(struct CString* str,int index, char newChar)
{
    if( index >= str->length) return false;
    str->chars[index] = newChar;
    return true;
}

int main() {
    CString* str;
    str = cstring_new("ola");
    assert(iStringLength(str)==3);
    assert(chCharAt(str,1)=='l');
    assert(bChangeCharAt(str,1,'b')==true);
    assert(chCharAt(str,1)=='b');


    CString* str1;
    str1 = cstring_new("");
    assert(iStringLength(str1)==0);
    assert(chCharAt(str1,0)=='-');
    assert(bChangeCharAt(str1,0,'b')==false);
    assert(chCharAt(str1,0)=='-');


    return 0;
}



