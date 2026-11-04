
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* Library Function - Single Match
    ___crtCompareStringA
   
   Library: Visual Studio 2003 Release */

int __cdecl
___crtCompareStringA
          (_locale_t _Plocinfo,LPCWSTR _LocaleName,DWORD _DwCmpFlags,LPCSTR _LpString1,
          int _CchCount1,LPCSTR _LpString2,int _CchCount2,int _Code_page)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  BOOL BVar5;
  BYTE *pBVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  size_t unaff_EDI;
  void *_Memory;
  DWORD DStackY_7c;
  undefined1 auStack_52 [2];
  size_t local_50 [5];
  void *local_3c;
  undefined1 *local_38;
  _cpinfo local_34;
  undefined4 local_20;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_007d4708;
  uStack_c = 0x50cc5b;
  local_20 = DAT_0084b484;
  _Memory = (void *)0x0;
  if (DAT_00a200a0 == 0) {
    DStackY_7c = 0x50cc81;
    iVar3 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00a200a0 = 2;
      }
    }
    else {
      DAT_00a200a0 = 1;
    }
  }
  if (0 < (int)_LpString1) {
    _LpString1 = (LPCSTR)_strncnt(_LpString1,unaff_EDI);
  }
  if (0 < (int)_LpString2) {
    _LpString2 = (LPCSTR)_strncnt(_LpString2,unaff_EDI);
  }
  if ((DAT_00a200a0 == 2) || (DAT_00a200a0 == 0)) {
    local_3c = (void *)0x0;
    if (_Plocinfo == (_locale_t)0x0) {
      _Plocinfo = DAT_00a1fe00;
    }
    if (_CchCount2 == 0) {
      _CchCount2 = DAT_00a1fe10;
    }
    iVar3 = ___ansicp();
    if (iVar3 == -1) {
      return 0;
    }
    if (iVar3 != _CchCount2) {
      DStackY_7c = 0x50cf5b;
      _Memory = (void *)___convertcp();
      if (_Memory == (void *)0x0) {
        return 0;
      }
      DStackY_7c = 0x50cf76;
      _CchCount1 = ___convertcp();
      if ((void *)_CchCount1 == (void *)0x0) {
        _free(_Memory);
        return 0;
      }
      _DwCmpFlags = (DWORD)_Memory;
      local_3c = (void *)_CchCount1;
    }
    DStackY_7c = 0x50cfaa;
    iVar3 = CompareStringA((LCID)_Plocinfo,(DWORD)_LocaleName,(PCNZCH)_DwCmpFlags,(int)_LpString1,
                           (PCNZCH)_CchCount1,(int)_LpString2);
    if (_Memory != (void *)0x0) {
      _free(_Memory);
      _free(local_3c);
    }
    return iVar3;
  }
  if (DAT_00a200a0 != 1) {
    return 0;
  }
  bVar2 = false;
  bVar1 = false;
  local_50[3] = 0;
  if (_CchCount2 == 0) {
    _CchCount2 = DAT_00a1fe10;
  }
  if ((_LpString1 == (LPCSTR)0x0) || (_LpString2 == (LPCSTR)0x0)) {
    if (_LpString1 == _LpString2) {
      return 2;
    }
    if (1 < (int)_LpString2) {
      return 1;
    }
    if (1 < (int)_LpString1) {
      return 3;
    }
    BVar5 = GetCPInfo(_CchCount2,&local_34);
    if (BVar5 == 0) {
      return 0;
    }
    if (0 < (int)_LpString1) {
      if (local_34.MaxCharSize < 2) {
        return 3;
      }
      pBVar6 = local_34.LeadByte;
      while( true ) {
        if (local_34.LeadByte[0] == 0) {
          return 3;
        }
        if (pBVar6[1] == 0) break;
        if ((*pBVar6 <= *(byte *)_DwCmpFlags) && (*(byte *)_DwCmpFlags <= pBVar6[1])) {
          return 2;
        }
        pBVar6 = pBVar6 + 2;
        local_34.LeadByte[0] = *pBVar6;
      }
      return 3;
    }
    if (0 < (int)_LpString2) {
      if (local_34.MaxCharSize < 2) {
        return 1;
      }
      pBVar6 = local_34.LeadByte;
      while( true ) {
        if (local_34.LeadByte[0] == 0) {
          return 1;
        }
        if (pBVar6[1] == 0) break;
        if ((*pBVar6 <= *(byte *)_CchCount1) && (*(byte *)_CchCount1 <= pBVar6[1])) {
          return 2;
        }
        pBVar6 = pBVar6 + 2;
        local_34.LeadByte[0] = *pBVar6;
      }
      return 1;
    }
  }
  DStackY_7c = 0x50cdcb;
  iVar3 = MultiByteToWideChar(_CchCount2,9,(LPCSTR)_DwCmpFlags,(int)_LpString1,(LPWSTR)0x0,0);
  if (iVar3 == 0) {
    return 0;
  }
  puVar7 = (undefined1 *)(iVar3 * 2 + 3U & 0xfffffffc);
  iVar8 = -(int)puVar7;
  local_38 = auStack_52 + iVar8 + -0xe;
  local_1c = auStack_52 + iVar8 + -0xe;
  local_8 = (undefined *)0xffffffff;
  if (auStack_52 + -0xe == puVar7) {
    *(int *)(auStack_52 + iVar8 + -0x12) = iVar3 * 2;
    *(undefined4 *)(auStack_52 + iVar8 + -0x16) = 0x50ce23;
    local_38 = _malloc(*(size_t *)(auStack_52 + iVar8 + -0x12));
    if (local_38 == (void *)0x0) {
      return 0;
    }
    bVar2 = true;
  }
  *(int *)(auStack_52 + iVar8 + -0x12) = iVar3;
  *(undefined1 **)(auStack_52 + iVar8 + -0x16) = local_38;
  *(LPCSTR *)(auStack_52 + iVar8 + -0x1a) = _LpString1;
  *(DWORD *)(auStack_52 + iVar8 + -0x1e) = _DwCmpFlags;
  *(undefined4 *)(auStack_52 + iVar8 + -0x22) = 1;
  *(int *)(auStack_52 + iVar8 + -0x26) = _CchCount2;
  puVar12 = auStack_52 + iVar8 + -0x2a;
  *(undefined4 *)(auStack_52 + iVar8 + -0x2a) = 0x50ce44;
  iVar8 = MultiByteToWideChar(*(UINT *)(auStack_52 + iVar8 + -0x26),
                              *(DWORD *)(auStack_52 + iVar8 + -0x22),
                              *(LPCSTR *)(auStack_52 + iVar8 + -0x1e),
                              *(int *)(auStack_52 + iVar8 + -0x1a),
                              *(LPWSTR *)(auStack_52 + iVar8 + -0x16),
                              *(int *)(auStack_52 + iVar8 + -0x12));
  puVar7 = puVar12;
  if (iVar8 != 0) {
    *(undefined4 *)(puVar12 + -4) = 0;
    *(undefined4 *)(puVar12 + -8) = 0;
    *(LPCSTR *)(puVar12 + -0xc) = _LpString2;
    *(int *)(puVar12 + -0x10) = _CchCount1;
    *(undefined4 *)(puVar12 + -0x14) = 9;
    *(int *)(puVar12 + -0x18) = _CchCount2;
    puVar13 = puVar12 + -0x1c;
    *(undefined4 *)(puVar12 + -0x1c) = 0x50ce61;
    iVar8 = MultiByteToWideChar(*(UINT *)(puVar12 + -0x18),*(DWORD *)(puVar12 + -0x14),
                                *(LPCSTR *)(puVar12 + -0x10),*(int *)(puVar12 + -0xc),
                                *(LPWSTR *)(puVar12 + -8),*(int *)(puVar12 + -4));
    puVar7 = puVar13;
    if (iVar8 != 0) {
      puVar9 = (undefined1 *)(iVar8 * 2 + 3U & 0xfffffffc);
      *(undefined4 *)(puVar13 + -4) = 0x50ce83;
      iVar11 = -(int)puVar9;
      puVar10 = puVar13 + iVar11;
      puVar7 = puVar13 + iVar11;
      local_1c = puVar13 + iVar11;
      local_8 = (undefined *)0xffffffff;
      if (puVar13 == puVar9) {
        sRamfffffffc = iVar8 * 2;
        uRamfffffff8 = 0x50ceb6;
        puVar10 = _malloc(sRamfffffffc);
        if (puVar10 == (undefined1 *)0x0) goto LAB_0050cefd;
        bVar1 = true;
      }
      *(int *)(puVar13 + iVar11 + -4) = iVar8;
      *(undefined1 **)(puVar13 + iVar11 + -8) = puVar10;
      *(LPCSTR *)(puVar13 + iVar11 + -0xc) = _LpString2;
      *(int *)(puVar13 + iVar11 + -0x10) = _CchCount1;
      *(undefined4 *)(puVar13 + iVar11 + -0x14) = 1;
      *(int *)(puVar13 + iVar11 + -0x18) = _CchCount2;
      puVar14 = puVar13 + iVar11 + -0x1c;
      *(undefined4 *)(puVar13 + iVar11 + -0x1c) = 0x50ced7;
      iVar11 = MultiByteToWideChar(*(UINT *)(puVar13 + iVar11 + -0x18),
                                   *(DWORD *)(puVar13 + iVar11 + -0x14),
                                   *(LPCSTR *)(puVar13 + iVar11 + -0x10),
                                   *(int *)(puVar13 + iVar11 + -0xc),
                                   *(LPWSTR *)(puVar13 + iVar11 + -8),
                                   *(int *)(puVar13 + iVar11 + -4));
      puVar7 = puVar14;
      if (iVar11 != 0) {
        *(int *)(puVar14 + -4) = iVar8;
        *(undefined1 **)(puVar14 + -8) = puVar10;
        *(int *)(puVar14 + -0xc) = iVar3;
        *(undefined1 **)(puVar14 + -0x10) = local_38;
        *(LPCWSTR *)(puVar14 + -0x14) = _LocaleName;
        *(_locale_t *)(puVar14 + -0x18) = _Plocinfo;
        puVar7 = puVar14 + -0x1c;
        *(undefined4 *)(puVar14 + -0x1c) = 0x50ceed;
        local_50[3] = CompareStringW(*(LCID *)(puVar14 + -0x18),*(DWORD *)(puVar14 + -0x14),
                                     *(PCNZWCH *)(puVar14 + -0x10),*(int *)(puVar14 + -0xc),
                                     *(PCNZWCH *)(puVar14 + -8),*(int *)(puVar14 + -4));
      }
      if (bVar1) {
        *(undefined1 **)(puVar7 + -4) = puVar10;
        *(undefined4 *)(puVar7 + -8) = 0x50cefc;
        _free(*(void **)(puVar7 + -4));
      }
    }
  }
LAB_0050cefd:
  if (bVar2) {
    *(undefined1 **)(puVar7 + -4) = local_38;
    *(undefined4 *)(puVar7 + -8) = 0x50cf0b;
    _free(*(void **)(puVar7 + -4));
  }
  return local_50[3];
}

