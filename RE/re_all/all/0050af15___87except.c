
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    __87except
   
   Library: Visual Studio 2003 Release */

void __87except(int param_1,int *param_2,ushort *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_94;
  undefined1 local_90 [48];
  undefined8 local_60;
  uint local_50;
  undefined4 local_14;
  
  local_14 = DAT_0084b484;
  local_94 = (uint)*param_3;
  iVar1 = *param_2;
  if (iVar1 == 1) {
LAB_0050af6d:
    uVar2 = 8;
  }
  else if (iVar1 == 2) {
    uVar2 = 4;
  }
  else if (iVar1 == 3) {
    uVar2 = 0x11;
  }
  else if (iVar1 == 4) {
    uVar2 = 0x12;
  }
  else {
    if (iVar1 == 5) goto LAB_0050af6d;
    if (iVar1 == 7) {
      *param_2 = 1;
      goto LAB_0050afc9;
    }
    if (iVar1 != 8) goto LAB_0050afc9;
    uVar2 = 0x10;
  }
  iVar1 = __handle_exc(uVar2,param_2 + 6,local_94);
  if (iVar1 == 0) {
    if (((param_1 == 0x10) || (param_1 == 0x16)) || (param_1 == 0x1d)) {
      local_60 = *(undefined8 *)(param_2 + 4);
      local_50 = local_50 & 0xffffffe3 | 3;
    }
    else {
      local_50 = local_50 & 0xfffffffe;
    }
    __raise_exc(local_90,&local_94,uVar2,param_1,param_2 + 2,param_2 + 6);
  }
LAB_0050afc9:
  __ctrlfp(local_94,0xffff);
  if (((*param_2 == 8) || (DAT_0084c248 != 0)) || (iVar1 = FUN_004fdac5(param_2), iVar1 == 0)) {
    __set_errno(*param_2);
    return;
  }
  return;
}

