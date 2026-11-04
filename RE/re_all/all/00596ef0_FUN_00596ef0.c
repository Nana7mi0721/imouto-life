
undefined4 FUN_00596ef0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (uint)*(ushort *)(param_1 + 0x44) * param_2 - *(int *)(param_1 + 0x45c);
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar1 < 0x10) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    uVar2 = FUN_00596eb0(param_2);
    *(undefined4 *)(param_1 + 4) = 0;
    return uVar2;
  }
  if (iVar1 == 1) {
    uVar2 = FUN_005f9610(param_1);
    *(undefined4 *)(param_1 + 4) = 0;
    return uVar2;
  }
  if (iVar1 == 2) {
    uVar2 = FUN_005fa440();
    *(undefined4 *)(param_1 + 4) = 0;
    return uVar2;
  }
  uVar2 = FUN_005dd290();
  *(undefined4 *)(param_1 + 4) = 0;
  return uVar2;
}

