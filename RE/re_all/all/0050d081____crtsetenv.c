
/* Library Function - Single Match
    ___crtsetenv
   
   Library: Visual Studio 2003 Release */

int __cdecl ___crtsetenv(char **_POption,int _Primary)

{
  char *_Str;
  char *pcVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  LPCSTR lpName;
  BOOL BVar5;
  bool bVar6;
  int local_14;
  
  local_14 = 0;
  if (_POption == (char **)0x0) {
    return -1;
  }
  _Str = *_POption;
  if (_Str == (char *)0x0) {
    return -1;
  }
  pcVar1 = (char *)FUN_0050d3c2(_Str,0x3d);
  if (pcVar1 == (char *)0x0) {
    return -1;
  }
  if (_Str == pcVar1) {
    return -1;
  }
  bVar6 = pcVar1[1] == '\0';
  if (DAT_00a1fbe4 == DAT_00a1fbe8) {
    DAT_00a1fbe4 = (int *)copy_environ();
  }
  if (DAT_00a1fbe4 == (int *)0x0) {
    if ((_Primary != 0) && (DAT_00a1fbec != (undefined4 *)0x0)) {
      iVar2 = ___wtomb_environ();
      if (iVar2 != 0) {
        return -1;
      }
      goto LAB_0050d136;
    }
    if (!bVar6) {
      DAT_00a1fbe4 = _malloc(4);
      if (DAT_00a1fbe4 == (int *)0x0) {
        return -1;
      }
      *DAT_00a1fbe4 = 0;
      if (DAT_00a1fbec == (undefined4 *)0x0) {
        DAT_00a1fbec = _malloc(4);
        if (DAT_00a1fbec == (undefined4 *)0x0) {
          return -1;
        }
        *DAT_00a1fbec = 0;
      }
      goto LAB_0050d136;
    }
LAB_0050d104:
    local_14 = 0;
  }
  else {
LAB_0050d136:
    piVar3 = DAT_00a1fbe4;
    iVar2 = findenv(_Str);
    if ((iVar2 < 0) || (*piVar3 == 0)) {
      if (bVar6) {
        _free(_Str);
        *_POption = (char *)0x0;
        goto LAB_0050d104;
      }
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      piVar3 = _realloc(DAT_00a1fbe4,iVar2 * 4 + 8);
      if (piVar3 == (int *)0x0) {
        return -1;
      }
      piVar3[iVar2] = (int)_Str;
      (piVar3 + iVar2)[1] = 0;
      *_POption = (char *)0x0;
LAB_0050d1d3:
      DAT_00a1fbe4 = piVar3;
    }
    else {
      piVar3 = piVar3 + iVar2;
      _free((void *)*piVar3);
      if (bVar6) {
        for (; *piVar3 != 0; piVar3 = piVar3 + 1) {
          *piVar3 = piVar3[1];
          iVar2 = iVar2 + 1;
        }
        piVar3 = _realloc(DAT_00a1fbe4,iVar2 << 2);
        if (piVar3 != (int *)0x0) goto LAB_0050d1d3;
      }
      else {
        *piVar3 = (int)_Str;
        *_POption = (char *)0x0;
      }
    }
    if (_Primary != 0) {
      sVar4 = _strlen(_Str);
      lpName = _malloc(sVar4 + 2);
      if (lpName != (LPCSTR)0x0) {
        FUN_004fd700(lpName,_Str);
        pcVar1[(int)lpName - (int)_Str] = '\0';
        BVar5 = SetEnvironmentVariableA
                          (lpName,(LPCSTR)(~-(uint)bVar6 &
                                          (uint)(pcVar1 + ((int)lpName - (int)_Str) + 1)));
        if (BVar5 == 0) {
          local_14 = -1;
        }
        _free(lpName);
      }
    }
    if (bVar6) {
      _free(_Str);
    }
  }
  return local_14;
}

