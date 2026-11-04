
void FUN_00662eb0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = *(int *)(param_1 + 0x240);
  uVar2 = *(uint *)(iVar1 + 0x34);
  uVar5 = *(uint *)(iVar1 + 0x30);
  if (((*(byte *)(iVar1 + 0x1c) & 4) != 0) && (uVar2 != 4)) {
    uVar4 = uVar2 + 4;
    if (3 < (int)uVar2) {
      uVar4 = uVar2 - 4;
    }
    if (uVar2 < uVar4) {
      do {
        uVar4 = uVar4 - uVar2;
        if (*(int *)(param_1 + 0x250) <= *(int *)(param_1 + 0x260)) {
          FUN_0065e6b0(param_1);
        }
        **(byte **)(param_1 + 0x25c) = (byte)uVar5 | (byte)(0 >> ((byte)uVar4 & 0x1f));
        uVar2 = 8;
        *(int *)(param_1 + 0x260) = *(int *)(param_1 + 0x260) + 1;
        uVar5 = 0;
        *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + 1;
      } while (8 < uVar4);
    }
    uVar2 = uVar2 - uVar4;
    uVar5 = uVar5 | 0 << ((byte)uVar2 & 0x1f);
    if (uVar2 == 0) {
      if (*(int *)(param_1 + 0x250) <= *(int *)(param_1 + 0x260)) {
        FUN_0065e6b0(param_1);
      }
      **(undefined1 **)(param_1 + 0x25c) = (char)uVar5;
      *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + 1;
      *(int *)(param_1 + 0x260) = *(int *)(param_1 + 0x260) + 1;
      uVar5 = 0;
      uVar2 = 8;
    }
  }
  uVar4 = 1;
  uVar6 = 0xc;
  if ((*(byte *)(iVar1 + 0x1c) & 1) != 0) {
    uVar4 = *(int *)(iVar1 + 0x4c) == 0 | 2;
    uVar6 = 0xd;
  }
  if (uVar2 < uVar6) {
    do {
      uVar6 = uVar6 - uVar2;
      if (*(int *)(param_1 + 0x250) <= *(int *)(param_1 + 0x260)) {
        FUN_0065e6b0(param_1);
      }
      **(byte **)(param_1 + 0x25c) = (byte)uVar5 | (byte)(uVar4 >> ((byte)uVar6 & 0x1f));
      *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + 1;
      *(int *)(param_1 + 0x260) = *(int *)(param_1 + 0x260) + 1;
      uVar2 = 8;
      uVar5 = 0;
    } while (8 < uVar6);
  }
  iVar3 = uVar2 - uVar6;
  uVar5 = uVar5 | (*(uint *)(&DAT_0080598c + uVar6 * 4) & uVar4) << ((byte)iVar3 & 0x1f);
  if (iVar3 != 0) {
    *(uint *)(iVar1 + 0x30) = uVar5;
    *(int *)(iVar1 + 0x34) = iVar3;
    return;
  }
  if (*(int *)(param_1 + 0x250) <= *(int *)(param_1 + 0x260)) {
    FUN_0065e6b0(param_1);
  }
  **(undefined1 **)(param_1 + 0x25c) = (char)uVar5;
  *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + 1;
  *(int *)(param_1 + 0x260) = *(int *)(param_1 + 0x260) + 1;
  *(undefined4 *)(iVar1 + 0x30) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 8;
  return;
}

