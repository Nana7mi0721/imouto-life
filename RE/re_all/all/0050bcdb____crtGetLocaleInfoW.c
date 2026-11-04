
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    ___crtGetLocaleInfoW
   
   Library: Visual Studio 2003 Release */

int ___crtGetLocaleInfoW(LCID param_1,LCTYPE param_2,LPWSTR param_3,int param_4,int param_5)

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
  
  if (DAT_00a20098 == 0) {
    sStackY_4c = 0x50bcfe;
    iVar3 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00a20098 = 2;
      }
    }
    else {
      DAT_00a20098 = 1;
    }
  }
  if (DAT_00a20098 == 1) {
    sStackY_4c = 0x50bd3a;
    iVar3 = GetLocaleInfoW(param_1,param_2,param_3,param_4);
    return iVar3;
  }
  if ((DAT_00a20098 == 2) || (DAT_00a20098 == 0)) {
    local_20 = 0;
    bVar2 = false;
    if (param_5 == 0) {
      param_5 = DAT_00a1fe10;
    }
    sStackY_4c = 0x50bd69;
    iVar3 = GetLocaleInfoA(param_1,param_2,(LPSTR)0x0,0);
    if (iVar3 != 0) {
      puVar5 = (undefined1 *)(iVar3 + 3U & 0xfffffffc);
      iVar1 = -(int)puVar5;
      puVar6 = auStack_2a + iVar1 + -0xe;
      if (auStack_2a + -0xe == puVar5) {
        *(int *)(auStack_2a + iVar1 + -0x12) = iVar3;
        *(undefined4 *)(auStack_2a + iVar1 + -0x16) = 0x50bdb6;
        puVar6 = _malloc(*(size_t *)(auStack_2a + iVar1 + -0x12));
        if (puVar6 == (undefined1 *)0x0) {
          return 0;
        }
        bVar2 = true;
      }
      *(int *)(auStack_2a + iVar1 + -0x12) = iVar3;
      *(undefined1 **)(auStack_2a + iVar1 + -0x16) = puVar6;
      *(LCTYPE *)(auStack_2a + iVar1 + -0x1a) = param_2;
      *(LCID *)(auStack_2a + iVar1 + -0x1e) = param_1;
      puVar7 = auStack_2a + iVar1 + -0x22;
      *(undefined4 *)(auStack_2a + iVar1 + -0x22) = 0x50bdd0;
      iVar3 = GetLocaleInfoA(*(LCID *)(auStack_2a + iVar1 + -0x1e),
                             *(LCTYPE *)(auStack_2a + iVar1 + -0x1a),
                             *(LPSTR *)(auStack_2a + iVar1 + -0x16),
                             *(int *)(auStack_2a + iVar1 + -0x12));
      puVar5 = puVar7;
      if (iVar3 != 0) {
        if (param_4 == 0) {
          *(undefined4 *)(puVar7 + -4) = 0;
          *(undefined4 *)(puVar7 + -8) = 0;
        }
        else {
          *(int *)(puVar7 + -4) = param_4;
          *(LPWSTR *)(puVar7 + -8) = param_3;
        }
        *(undefined4 *)(puVar7 + -0xc) = 0xffffffff;
        *(undefined1 **)(puVar7 + -0x10) = puVar6;
        *(undefined4 *)(puVar7 + -0x14) = 1;
        *(int *)(puVar7 + -0x18) = param_5;
        puVar5 = puVar7 + -0x1c;
        *(undefined4 *)(puVar7 + -0x1c) = 0x50bdf0;
        local_20 = MultiByteToWideChar(*(UINT *)(puVar7 + -0x18),*(DWORD *)(puVar7 + -0x14),
                                       *(LPCSTR *)(puVar7 + -0x10),*(int *)(puVar7 + -0xc),
                                       *(LPWSTR *)(puVar7 + -8),*(int *)(puVar7 + -4));
      }
      if (bVar2) {
        *(undefined1 **)(puVar5 + -4) = puVar6;
        *(undefined4 *)(puVar5 + -8) = 0x50bdfe;
        _free(*(void **)(puVar5 + -4));
      }
      return local_20;
    }
  }
  return 0;
}

