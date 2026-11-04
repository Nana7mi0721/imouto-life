
void FUN_00680e30(int param_1,undefined1 *param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  
  FUN_00680db0(param_1);
  if (param_4 != 0) {
    *(byte *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (byte)param_3;
    iVar2 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar2;
    bVar1 = (byte)((uint)param_3 >> 8);
    *(byte *)(*(int *)(param_1 + 8) + iVar2) = bVar1;
    iVar2 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar2;
    *(byte *)(*(int *)(param_1 + 8) + iVar2) = ~(byte)param_3;
    iVar2 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar2;
    *(byte *)(*(int *)(param_1 + 8) + iVar2) = ~bVar1;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  if (param_3 != 0) {
    do {
      *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    } while (param_3 != 0);
  }
  return;
}

