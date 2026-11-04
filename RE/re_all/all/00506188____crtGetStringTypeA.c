
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    ___crtGetStringTypeA
   
   Library: Visual Studio 2003 Release */

BOOL __cdecl
___crtGetStringTypeA
          (_locale_t _Plocinfo,DWORD _DWInfoType,LPCSTR _LpSrcStr,int _CchSrc,LPWORD _LpCharType,
          int _Code_page,BOOL _BError)

{
  int iVar1;
  bool bVar2;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  LPWORD pWVar8;
  undefined1 *puVar9;
  void *_Memory;
  undefined4 uStackY_58;
  undefined1 auStack_2e [2];
  size_t local_2c [3];
  WORD local_20 [2];
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_007d3f98;
  uStack_c = 0x506194;
  _Memory = (void *)0x0;
  if (DAT_00a1fe18 == 0) {
    BVar3 = GetStringTypeW(1,L"",1,local_20);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00a1fe18 = 2;
      }
    }
    else {
      DAT_00a1fe18 = 1;
    }
  }
  if ((DAT_00a1fe18 == 2) || (DAT_00a1fe18 == 0)) {
    if (_Code_page == 0) {
      _Code_page = DAT_00a1fe00;
    }
    if (_LpCharType == (LPWORD)0x0) {
      _LpCharType = DAT_00a1fe10;
    }
    pWVar8 = (LPWORD)___ansicp();
    if (pWVar8 != (LPWORD)0xffffffff) {
      if (pWVar8 != _LpCharType) {
        uStackY_58 = 0x50630b;
        _Memory = (void *)___convertcp();
        if (_Memory == (void *)0x0) {
          return 0;
        }
        _DWInfoType = (DWORD)_Memory;
      }
      BVar3 = GetStringTypeA(_Code_page,(DWORD)_Plocinfo,(LPCSTR)_DWInfoType,(int)_LpSrcStr,
                             (LPWORD)_CchSrc);
      if (_Memory != (void *)0x0) {
        _free(_Memory);
      }
      return BVar3;
    }
  }
  else if (DAT_00a1fe18 == 1) {
    local_2c[1] = 0;
    bVar2 = false;
    if (_LpCharType == (LPWORD)0x0) {
      _LpCharType = DAT_00a1fe10;
    }
    uStackY_58 = 0x506226;
    iVar5 = MultiByteToWideChar((UINT)_LpCharType,(uint)(_BError != 0) * 8 + 1,(LPCSTR)_DWInfoType,
                                (int)_LpSrcStr,(LPWSTR)0x0,0);
    if (iVar5 != 0) {
      local_8 = (undefined *)0x0;
      puVar6 = (undefined1 *)(iVar5 * 2 + 3U & 0xfffffffc);
      iVar1 = -(int)puVar6;
      puVar7 = auStack_2e + iVar1 + -0xe;
      local_1c = auStack_2e + iVar1 + -0xe;
      *(int *)(auStack_2e + iVar1 + -0x12) = iVar5 * 2;
      *(undefined4 *)(auStack_2e + iVar1 + -0x16) = 0;
      *(undefined1 **)(auStack_2e + iVar1 + -0x1a) = auStack_2e + iVar1 + -0xe;
      *(undefined4 *)(auStack_2e + iVar1 + -0x1e) = 0x506258;
      _memset(*(void **)(auStack_2e + iVar1 + -0x1a),*(int *)(auStack_2e + iVar1 + -0x16),
              *(size_t *)(auStack_2e + iVar1 + -0x12));
      local_8 = (undefined *)0xffffffff;
      if (auStack_2e + -0xe == puVar6) {
        *(int *)(auStack_2e + iVar1 + -0x12) = iVar5;
        *(undefined4 *)(auStack_2e + iVar1 + -0x16) = 2;
        *(undefined4 *)(auStack_2e + iVar1 + -0x1a) = 0x506282;
        puVar7 = _calloc(*(size_t *)(auStack_2e + iVar1 + -0x16),
                         *(size_t *)(auStack_2e + iVar1 + -0x12));
        if (puVar7 == (undefined1 *)0x0) {
          return 0;
        }
        bVar2 = true;
      }
      *(int *)(auStack_2e + iVar1 + -0x12) = iVar5;
      *(undefined1 **)(auStack_2e + iVar1 + -0x16) = puVar7;
      *(LPCSTR *)(auStack_2e + iVar1 + -0x1a) = _LpSrcStr;
      *(DWORD *)(auStack_2e + iVar1 + -0x1e) = _DWInfoType;
      *(undefined4 *)(auStack_2e + iVar1 + -0x22) = 1;
      *(LPWORD *)(auStack_2e + iVar1 + -0x26) = _LpCharType;
      puVar9 = auStack_2e + iVar1 + -0x2a;
      *(undefined4 *)(auStack_2e + iVar1 + -0x2a) = 0x5062a4;
      iVar5 = MultiByteToWideChar(*(UINT *)(auStack_2e + iVar1 + -0x26),
                                  *(DWORD *)(auStack_2e + iVar1 + -0x22),
                                  *(LPCSTR *)(auStack_2e + iVar1 + -0x1e),
                                  *(int *)(auStack_2e + iVar1 + -0x1a),
                                  *(LPWSTR *)(auStack_2e + iVar1 + -0x16),
                                  *(int *)(auStack_2e + iVar1 + -0x12));
      puVar6 = puVar9;
      if (iVar5 != 0) {
        *(int *)(puVar9 + -4) = _CchSrc;
        *(int *)(puVar9 + -8) = iVar5;
        *(undefined1 **)(puVar9 + -0xc) = puVar7;
        *(_locale_t *)(puVar9 + -0x10) = _Plocinfo;
        puVar6 = puVar9 + -0x14;
        *(undefined4 *)(puVar9 + -0x14) = 0x5062b6;
        local_2c[1] = GetStringTypeW(*(DWORD *)(puVar9 + -0x10),*(LPCWSTR *)(puVar9 + -0xc),
                                     *(int *)(puVar9 + -8),*(LPWORD *)(puVar9 + -4));
      }
      if (bVar2) {
        *(undefined1 **)(puVar6 + -4) = puVar7;
        *(undefined4 *)(puVar6 + -8) = 0x5062c5;
        _free(*(void **)(puVar6 + -4));
      }
      return local_2c[1];
    }
  }
  return 0;
}

