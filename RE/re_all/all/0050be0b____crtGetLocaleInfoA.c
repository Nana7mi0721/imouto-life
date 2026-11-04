
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    ___crtGetLocaleInfoA
   
   Library: Visual Studio 2003 Release */

int __cdecl
___crtGetLocaleInfoA
          (_locale_t _Plocinfo,LPCWSTR _LocaleName,LCTYPE _LCType,LPSTR _LpLCData,int _CchData)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  size_t sStackY_4c;
  undefined1 auStack_2a [10];
  int local_20;
  
  if (DAT_00a2009c == 0) {
    sStackY_4c = 0x50be2e;
    iVar3 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00a2009c = 2;
      }
    }
    else {
      DAT_00a2009c = 1;
    }
  }
  if ((DAT_00a2009c == 2) || (DAT_00a2009c == 0)) {
    sStackY_4c = 0x50bf42;
    iVar3 = GetLocaleInfoA((LCID)_Plocinfo,(LCTYPE)_LocaleName,(LPSTR)_LCType,(int)_LpLCData);
    return iVar3;
  }
  if (DAT_00a2009c == 1) {
    local_20 = 0;
    bVar2 = false;
    if (_CchData == 0) {
      _CchData = DAT_00a1fe10;
    }
    sStackY_4c = 0x50be8b;
    iVar3 = GetLocaleInfoW((LCID)_Plocinfo,(LCTYPE)_LocaleName,(LPWSTR)0x0,0);
    if (iVar3 != 0) {
      puVar5 = (undefined1 *)(iVar3 * 2 + 3U & 0xfffffffc);
      iVar1 = -(int)puVar5;
      puVar6 = auStack_2a + iVar1 + -0xe;
      if (auStack_2a + -0xe == puVar5) {
        *(int *)(auStack_2a + iVar1 + -0x12) = iVar3 * 2;
        *(undefined4 *)(auStack_2a + iVar1 + -0x16) = 0x50bede;
        puVar6 = _malloc(*(size_t *)(auStack_2a + iVar1 + -0x12));
        if (puVar6 == (undefined1 *)0x0) {
          return 0;
        }
        bVar2 = true;
      }
      *(int *)(auStack_2a + iVar1 + -0x12) = iVar3;
      *(undefined1 **)(auStack_2a + iVar1 + -0x16) = puVar6;
      *(LPCWSTR *)(auStack_2a + iVar1 + -0x1a) = _LocaleName;
      *(_locale_t *)(auStack_2a + iVar1 + -0x1e) = _Plocinfo;
      puVar7 = auStack_2a + iVar1 + -0x22;
      *(undefined4 *)(auStack_2a + iVar1 + -0x22) = 0x50befa;
      iVar3 = GetLocaleInfoW(*(LCID *)(auStack_2a + iVar1 + -0x1e),
                             *(LCTYPE *)(auStack_2a + iVar1 + -0x1a),
                             *(LPWSTR *)(auStack_2a + iVar1 + -0x16),
                             *(int *)(auStack_2a + iVar1 + -0x12));
      puVar5 = puVar7;
      if (iVar3 != 0) {
        *(undefined4 *)(puVar7 + -4) = 0;
        *(undefined4 *)(puVar7 + -8) = 0;
        if (_LpLCData == (LPSTR)0x0) {
          *(undefined4 *)(puVar7 + -0xc) = 0;
          *(undefined4 *)(puVar7 + -0x10) = 0;
        }
        else {
          *(LPSTR *)(puVar7 + -0xc) = _LpLCData;
          *(LCTYPE *)(puVar7 + -0x10) = _LCType;
        }
        *(undefined4 *)(puVar7 + -0x14) = 0xffffffff;
        *(undefined1 **)(puVar7 + -0x18) = puVar6;
        *(undefined4 *)(puVar7 + -0x1c) = 0;
        *(int *)(puVar7 + -0x20) = _CchData;
        puVar5 = puVar7 + -0x24;
        *(undefined4 *)(puVar7 + -0x24) = 0x50bf1c;
        local_20 = WideCharToMultiByte(*(UINT *)(puVar7 + -0x20),*(DWORD *)(puVar7 + -0x1c),
                                       *(LPCWSTR *)(puVar7 + -0x18),*(int *)(puVar7 + -0x14),
                                       *(LPSTR *)(puVar7 + -0x10),*(int *)(puVar7 + -0xc),
                                       *(LPCSTR *)(puVar7 + -8),*(LPBOOL *)(puVar7 + -4));
      }
      if (bVar2) {
        *(undefined1 **)(puVar5 + -4) = puVar6;
        *(undefined4 *)(puVar5 + -8) = 0x50bf2a;
        _free(*(void **)(puVar5 + -4));
      }
      return local_20;
    }
  }
  return 0;
}

