
void FUN_00663ae0(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x240);
  uVar2 = *(uint *)(iVar1 + 0x34);
  uVar4 = *(uint *)(iVar1 + 0x30);
  if (uVar2 < param_3) {
    do {
      param_3 = param_3 - uVar2;
      if (*(int *)(param_1 + 0x250) <= *(int *)(param_1 + 0x260)) {
        FUN_0065e6b0(param_1);
      }
      uVar2 = 8;
      **(byte **)(param_1 + 0x25c) = (byte)uVar4 | (byte)(param_2 >> ((byte)param_3 & 0x1f));
      *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + 1;
      uVar4 = 0;
      *(int *)(param_1 + 0x260) = *(int *)(param_1 + 0x260) + 1;
    } while (8 < param_3);
  }
  iVar3 = uVar2 - param_3;
  uVar4 = uVar4 | (*(uint *)(&DAT_0080598c + param_3 * 4) & param_2) << ((byte)iVar3 & 0x1f);
  if (iVar3 != 0) {
    *(uint *)(iVar1 + 0x30) = uVar4;
    *(int *)(iVar1 + 0x34) = iVar3;
    return;
  }
  if (*(int *)(param_1 + 0x250) <= *(int *)(param_1 + 0x260)) {
    FUN_0065e6b0(param_1);
  }
  **(undefined1 **)(param_1 + 0x25c) = (char)uVar4;
  *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + 1;
  *(int *)(param_1 + 0x260) = *(int *)(param_1 + 0x260) + 1;
  *(undefined4 *)(iVar1 + 0x30) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 8;
  return;
}

