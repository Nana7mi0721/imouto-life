
/* Library Function - Single Match
    __splitpath
   
   Library: Visual Studio 2003 Release */

void __cdecl __splitpath(char *_FullPath,char *_Drive,char *_Dir,char *_Filename,char *_Ext)

{
  byte bVar1;
  size_t sVar2;
  byte *_Source;
  byte *local_c;
  byte *local_8;
  
  local_8 = (byte *)0x0;
  sVar2 = _strlen(_FullPath);
  if ((sVar2 == 0) || (_FullPath[1] != ':')) {
    _Source = (byte *)_FullPath;
    if (_Drive != (char *)0x0) {
      *_Drive = '\0';
    }
  }
  else {
    if (_Drive != (char *)0x0) {
      __mbsnbcpy((uchar *)_Drive,(uchar *)_FullPath,2);
      _Drive[2] = '\0';
    }
    _Source = (byte *)(_FullPath + 2);
  }
  _FullPath = (char *)0x0;
  local_c = _Source;
  if (*_Source != 0) {
    do {
      bVar1 = *local_c;
      if (((&DAT_00f48921)[bVar1] & 4) == 0) {
        if ((bVar1 == 0x2f) || (bVar1 == 0x5c)) {
          _FullPath = (char *)(local_c + 1);
        }
        else if (bVar1 == 0x2e) {
          local_8 = local_c;
        }
      }
      else {
        local_c = local_c + 1;
      }
      local_c = local_c + 1;
    } while (*local_c != 0);
    if (_FullPath != (char *)0x0) {
      if (_Dir != (char *)0x0) {
        sVar2 = (int)_FullPath - (int)_Source;
        if (0xfe < sVar2) {
          sVar2 = 0xff;
        }
        __mbsnbcpy((uchar *)_Dir,_Source,sVar2);
        _Dir[sVar2] = '\0';
      }
      _Source = (byte *)_FullPath;
      goto LAB_004fd3fe;
    }
  }
  if (_Dir != (char *)0x0) {
    *_Dir = '\0';
  }
LAB_004fd3fe:
  if ((local_8 == (byte *)0x0) || (local_8 < _Source)) {
    if (_Filename != (char *)0x0) {
      sVar2 = 0xff;
      if ((uint)((int)local_c - (int)_Source) < 0xff) {
        sVar2 = (int)local_c - (int)_Source;
      }
      __mbsnbcpy((uchar *)_Filename,_Source,sVar2);
      _Filename[sVar2] = '\0';
    }
    if (_Ext != (char *)0x0) {
      *_Ext = '\0';
    }
  }
  else {
    if (_Filename != (char *)0x0) {
      sVar2 = (int)local_8 - (int)_Source;
      if (0xfe < sVar2) {
        sVar2 = 0xff;
      }
      __mbsnbcpy((uchar *)_Filename,_Source,sVar2);
      _Filename[sVar2] = '\0';
    }
    if (_Ext != (char *)0x0) {
      sVar2 = 0xff;
      if ((uint)((int)local_c - (int)local_8) < 0xff) {
        sVar2 = (int)local_c - (int)local_8;
      }
      __mbsnbcpy((uchar *)_Ext,local_8,sVar2);
      _Ext[sVar2] = '\0';
    }
  }
  return;
}

