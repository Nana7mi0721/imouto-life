
/* Library Function - Single Match
    _sprintf
   
   Library: Visual Studio 2003 Release */

int __cdecl _sprintf(char *_Dest,char *_Format,...)

{
  int iVar1;
  undefined1 uStack0000000c;
  FILE local_24;
  
  local_24._cnt = 0x7fffffff;
  local_24._flag = 0x42;
  local_24._base = _Dest;
  local_24._ptr = _Dest;
  iVar1 = __output(&local_24,_Format,&uStack0000000c);
  if (_Dest != (char *)0x0) {
    local_24._cnt = local_24._cnt + -1;
    if (local_24._cnt < 0) {
      __flsbuf(0,&local_24);
    }
    else {
      *local_24._ptr = '\0';
    }
  }
  return iVar1;
}

