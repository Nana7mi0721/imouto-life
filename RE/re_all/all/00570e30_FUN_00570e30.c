
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4
FUN_00570e30(int *param_1,int param_2,undefined4 param_3,int *param_4,undefined4 *param_5)

{
  int iVar1;
  undefined1 local_1000 [4092];
  undefined4 uStack_4;
  
  uStack_4 = 0x570e3a;
  if (param_2 != param_1[0xe]) {
    FUN_005764b0(param_3,0xffffffff,param_2,local_1000,0x1000,param_1[0xe]);
  }
  if (param_1[0x221] == 1) {
    iVar1 = FUN_0056ef10(param_1);
    while (iVar1 == 0) {
      FUN_0056da20(0);
      iVar1 = FUN_0056ef10(param_1);
    }
  }
  if (*param_1 == 0) {
    iVar1 = FUN_005706d0(param_1);
    if (iVar1 != 0) {
      if (param_4 != (int *)0x0) {
        *param_4 = *(int *)(iVar1 + 0x28) + param_1[4];
      }
      if (param_5 == (undefined4 *)0x0) {
        return 0;
      }
      *param_5 = *(undefined4 *)(iVar1 + 0x30);
      return 0;
    }
  }
  else {
    iVar1 = FUN_00570590();
    if (iVar1 != 0) {
      if (param_4 != (int *)0x0) {
        *param_4 = *(int *)(iVar1 + 0x20) + param_1[4];
      }
      if (param_5 == (undefined4 *)0x0) {
        return 0;
      }
      *param_5 = *(undefined4 *)(iVar1 + 0x24);
      return 0;
    }
  }
  return 0xffffffff;
}

