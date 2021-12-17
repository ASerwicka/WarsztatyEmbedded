#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>

typedef struct CString
{
    size_t length;
    char* chars;
}CString;

const char* getString(CString* str)
{
    return str->chars;
}

CString* cstring_new(const char* str)
{
    CString* cNewString;
    cNewString = malloc(sizeof(CString));
    if(cNewString == NULL) return NULL;
    cNewString->length = strlen(str);
    cNewString->chars = malloc(cNewString->length+1);
    if(cNewString->chars == NULL) return NULL;
    strncpy(cNewString->chars,str,cNewString->length+1);
    return cNewString;
}

size_t iStringLength(CString* str)
{
    return str->length;
}

char chCharAt(CString* str,size_t index)
{
    if(index >= str->length || index < 0) return '\0';
    return str->chars[index];
}

bool bChangeCharAt(CString* str,size_t index, char newChar)
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
    assert(strcmp(getString(str),"oba")==0);


    CString* str1;
    str1 = cstring_new("");
    assert(iStringLength(str1)==0);
    assert(chCharAt(str1,0)=='\0');
    assert(bChangeCharAt(str1,0,'b')==false);
    assert(chCharAt(str1,0)=='\0');
    assert(strcmp(getString(str1),"")==0);

    free(str->chars);
    free(str);

    return 0;
}



