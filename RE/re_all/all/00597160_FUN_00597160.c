
int FUN_00597160(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    if (*(short *)(param_1 + 0x5e) == 1) {
      return *(int *)(param_1 + 0x34);
    }
    if (*(short *)(param_1 + 0x5e) == 3) {
      return *(int *)(param_1 + 0x34) /
             (int)((ulonglong)*(ushort *)(param_1 + 0x6c) /
                  (ulonglong)(longlong)(int)(uint)*(ushort *)(param_1 + 0x46));
    }
    return -1;
  }
  if (iVar1 == 1) {
    iVar1 = FUN_005fa1c0();
    return iVar1;
  }
  if (iVar1 == 2) {
    iVar1 = FUN_005fa240();
    return iVar1;
  }
  iVar1 = FUN_005dd370();
  return iVar1;
}

