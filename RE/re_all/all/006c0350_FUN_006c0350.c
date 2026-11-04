
int FUN_006c0350(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined1 *param_7)

{
  uint uVar1;
  int iVar2;
  int extraout_EDX;
  undefined1 local_10 [16];
  
  if (param_7 == (undefined1 *)0x0) {
    iVar2 = *(int *)(param_1 + 0x34);
    uVar1 = *(uint *)(param_1 + 0x30);
    if ((0x7ffffffe < iVar2) && (0xfffefffe < uVar1)) {
      uVar1 = 0xfffeffff;
      iVar2 = 0x7fffffff;
    }
    FUN_006c03f0(param_1,local_10,uVar1 + 0x10000,iVar2 + (uint)(0xfffeffff < uVar1));
    if ((extraout_EDX < 1) && (extraout_EDX < 0)) {
      return -0x84;
    }
    param_7 = local_10;
  }
  *(undefined4 *)(param_1 + 0x5c) = 2;
  iVar2 = FUN_006c0570(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  if (iVar2 < 0) {
    *(undefined4 *)(param_1 + 0x5c) = 2;
  }
  return iVar2;
}

