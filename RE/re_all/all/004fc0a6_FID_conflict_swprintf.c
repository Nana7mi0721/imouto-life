
/* Library Function - Multiple Matches With Different Base Names
    int __cdecl swprintf(wchar_t *,unsigned int,wchar_t const *,...)
    __snwprintf
   
   Library: Visual Studio 2003 Release */

int __cdecl FID_conflict_swprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,...)

{
  int iVar1;
  undefined1 uStack00000010;
  FILE local_24;
  
  local_24._base = (char *)_Dest;
  local_24._ptr = (char *)_Dest;
  local_24._cnt = _Count * 2;
  local_24._flag = 0x42;
  iVar1 = __woutput(&local_24,_Format,&uStack00000010);
  local_24._cnt = local_24._cnt + -1;
  if (local_24._cnt < 0) {
    __flsbuf(0,&local_24);
  }
  else {
    *local_24._ptr = 0;
    local_24._ptr = (char *)((int)local_24._ptr + 1);
  }
  local_24._cnt = local_24._cnt + -1;
  if (local_24._cnt < 0) {
    __flsbuf(0,&local_24);
  }
  else {
    *local_24._ptr = 0;
  }
  return iVar1;
}

