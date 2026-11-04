
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    _TestDefaultLanguage
   
   Library: Visual Studio 2003 Release */

undefined4 _TestDefaultLanguage(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  size_t sVar4;
  undefined4 uVar5;
  undefined1 local_80 [120];
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  iVar1 = (*DAT_00a1fdf4)(param_1 & 0x3ff | 0x400,1,local_80,0x78);
  if (iVar1 == 0) {
LAB_00505bcb:
    uVar5 = 0;
  }
  else {
    uVar2 = _LcidFromHexString();
    if ((param_1 != uVar2) && (param_2 != 0)) {
      sVar3 = _strlen(DAT_00a1fdf0);
      sVar4 = _GetPrimaryLen();
      if (sVar4 == sVar3) goto LAB_00505bcb;
    }
    uVar5 = 1;
  }
  return uVar5;
}

