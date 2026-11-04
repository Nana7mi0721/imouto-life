
/* Library Function - Single Match
    __wsplitpath
   
   Library: Visual Studio 2003 Release */

void __cdecl
__wsplitpath(wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext)

{
  wchar_t wVar1;
  int iVar2;
  uint uVar3;
  size_t sVar4;
  wchar_t *pwVar5;
  wchar_t *local_c;
  wchar_t *local_8;
  
  local_8 = (wchar_t *)0x0;
  iVar2 = FUN_005015d9(_FullPath);
  if ((iVar2 == 0) || (_FullPath[1] != L':')) {
    if (_Drive != (wchar_t *)0x0) {
      *_Drive = L'\0';
    }
  }
  else {
    if (_Drive != (wchar_t *)0x0) {
      _wcsncpy(_Drive,_FullPath,2);
      _Drive[2] = L'\0';
    }
    _FullPath = _FullPath + 2;
  }
  wVar1 = *_FullPath;
  local_c = (wchar_t *)0x0;
  pwVar5 = _FullPath;
  if (wVar1 != L'\0') {
    do {
      if ((wVar1 == L'/') || (wVar1 == L'\\')) {
        local_c = pwVar5 + 1;
      }
      else if (wVar1 == L'.') {
        local_8 = pwVar5;
      }
      pwVar5 = pwVar5 + 1;
      wVar1 = *pwVar5;
    } while (wVar1 != L'\0');
    if (local_c != (wchar_t *)0x0) {
      if (_Dir != (wchar_t *)0x0) {
        uVar3 = (uint)((int)local_c - (int)_FullPath) >> 1;
        if (0xfe < uVar3) {
          uVar3 = 0xff;
        }
        _wcsncpy(_Dir,_FullPath,uVar3);
        _Dir[uVar3] = L'\0';
      }
      _FullPath = local_c;
      goto LAB_004fc1e7;
    }
  }
  if (_Dir != (wchar_t *)0x0) {
    *_Dir = L'\0';
  }
LAB_004fc1e7:
  if ((local_8 == (wchar_t *)0x0) || (local_8 < _FullPath)) {
    if (_Filename != (wchar_t *)0x0) {
      uVar3 = (uint)((int)pwVar5 - (int)_FullPath) >> 1;
      sVar4 = 0xff;
      if (uVar3 < 0xff) {
        sVar4 = uVar3;
      }
      _wcsncpy(_Filename,_FullPath,sVar4);
      _Filename[sVar4] = L'\0';
    }
    if (_Ext != (wchar_t *)0x0) {
      *_Ext = L'\0';
    }
  }
  else {
    if (_Filename != (wchar_t *)0x0) {
      uVar3 = (uint)((int)local_8 - (int)_FullPath) >> 1;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      _wcsncpy(_Filename,_FullPath,uVar3);
      _Filename[uVar3] = L'\0';
    }
    if (_Ext != (wchar_t *)0x0) {
      uVar3 = (uint)((int)pwVar5 - (int)local_8) >> 1;
      sVar4 = 0xff;
      if (uVar3 < 0xff) {
        sVar4 = uVar3;
      }
      _wcsncpy(_Ext,local_8,sVar4);
      _Ext[sVar4] = L'\0';
    }
  }
  return;
}

