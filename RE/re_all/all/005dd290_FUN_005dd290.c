
undefined4 FUN_005dd290(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  uVar2 = 0xffffffff;
  if (iVar1 == 3) {
    uVar2 = FUN_005dca30();
    return uVar2;
  }
  if (iVar1 == 4) {
    param_2 = (uint)*(ushort *)(param_1 + 0x44) * param_2;
    *(int *)(param_1 + 0x45c) = param_2;
    *(undefined4 *)(param_1 + 0x454) = 0;
    *(undefined4 *)(param_1 + 0x458) = 0;
    *(int *)(param_1 + 0x56) = param_2;
    uVar2 = 0;
  }
  else if (iVar1 == 5) {
    uVar2 = FUN_005dd170();
    return uVar2;
  }
  return uVar2;
}

