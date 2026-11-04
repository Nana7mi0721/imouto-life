
/* Library Function - Single Match
    __Toupper_lk
   
   Library: Visual Studio 2003 Release */

uint __Toupper_lk(uint param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  UINT _CchDest;
  LPCSTR _LpSrcStr;
  BOOL unaff_EBX;
  _locale_t _Plocinfo;
  bool bVar3;
  byte local_c;
  byte local_8;
  undefined1 local_7;
  
  puVar1 = param_2;
  if (param_2 == (undefined4 *)0x0) {
    iVar2 = ____lc_handle_func();
    _Plocinfo = *(_locale_t *)(iVar2 + 8);
    _CchDest = ____lc_codepage_func();
  }
  else {
    _Plocinfo = (_locale_t)*param_2;
    _CchDest = param_2[1];
  }
  if (_Plocinfo == (_locale_t)0x0) {
    if ((int)param_1 < 0x61) {
      return param_1;
    }
    if ((int)param_1 < 0x7b) {
      return param_1 - 0x20;
    }
    return param_1;
  }
  if (param_1 < 0x100) {
    if (puVar1 == (undefined4 *)0x0) {
      iVar2 = _islower(param_1);
      bVar3 = iVar2 == 0;
    }
    else {
      bVar3 = (*(byte *)(puVar1[2] + param_1 * 2) & 2) == 0;
    }
    if (bVar3) {
      return param_1;
    }
  }
  iVar2 = FUN_00504a64();
  puVar1 = param_2;
  local_c = (byte)(param_1 >> 8);
  if ((*(byte *)(iVar2 + 1 + (uint)local_c * 2) & 0x80) == 0) {
    param_2._0_2_ = (ushort)(byte)param_1;
    _LpSrcStr = (LPCSTR)0x1;
  }
  else {
    param_2._0_2_ = CONCAT11((byte)param_1,local_c);
    param_2._3_1_ = SUB41(puVar1,3);
    param_2._0_3_ = (uint3)(ushort)param_2;
    _LpSrcStr = (LPCSTR)0x2;
  }
  iVar2 = ___crtLCMapStringA(_Plocinfo,(LPCWSTR)0x200,(DWORD)&param_2,_LpSrcStr,(int)&local_8,
                             (LPSTR)0x3,_CchDest,1,unaff_EBX);
  if (iVar2 == 0) {
    return param_1;
  }
  if (iVar2 == 1) {
    return (uint)local_8;
  }
  return (uint)CONCAT11(local_8,local_7);
}

