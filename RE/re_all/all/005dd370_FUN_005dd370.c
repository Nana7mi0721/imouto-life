
int FUN_005dd370(int param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 3) {
    if (*(int *)(param_1 + 0x62) == -1) {
      iVar1 = *(int *)(param_1 + 0x34);
      (*DAT_00f3a12c)(*(undefined4 *)(param_1 + 0x4e),iVar1,&param_1,0);
      return iVar1;
    }
    return (uint)*(ushort *)(param_1 + 0x44) * *(int *)(param_1 + 0x62);
  }
  if (iVar1 == 4) {
    return *(int *)(param_1 + 0x52);
  }
  if (iVar1 == 5) {
    uVar2 = __allmul(*(undefined4 *)(param_1 + 0x40),0,*(undefined4 *)(param_1 + 0x5a),
                     *(undefined4 *)(param_1 + 0x5e));
    iVar1 = __aulldiv(uVar2,&DAT_00989680,0);
    return iVar1;
  }
  return 0;
}

