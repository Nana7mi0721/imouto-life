
void __fastcall FUN_0044b0a0(int param_1)

{
  int iVar1;
  
  if ((0 < *(int *)(param_1 + 0x18b0)) || (*(int *)(param_1 + 0x18bc) != 0)) {
    iVar1 = ((*(int *)(param_1 + 0x18a0) * *(int *)(param_1 + 0x18a4) * *(int *)(param_1 + 0x18c4) *
             0x40) / DAT_0084b244) / 10;
    if ((*(int *)(param_1 + 0x18b0) < 2) &&
       ((*(int *)(param_1 + 0x18bc) + iVar1) * *(int *)(param_1 + 0x18bc) < 1)) {
      *(undefined4 *)(param_1 + 0x18bc) = 0;
    }
    else {
      *(int *)(param_1 + 0x18bc) = *(int *)(param_1 + 0x18bc) + iVar1;
    }
    if (*(int *)(param_1 + 0x18a0) * 0x80 < *(int *)(param_1 + 0x18bc)) {
      *(undefined4 *)(param_1 + 0x18c4) = 0xffffffff;
    }
    if (*(int *)(param_1 + 0x18bc) < *(int *)(param_1 + 0x18a0) * -0x80) {
      *(undefined4 *)(param_1 + 0x18c4) = 1;
    }
    if (0 < *(int *)(param_1 + 0x18b0)) {
      *(int *)(param_1 + 0x18b0) = *(int *)(param_1 + 0x18b0) + -1;
    }
  }
  if ((0 < *(int *)(param_1 + 0x18b4)) || (*(int *)(param_1 + 0x18c0) != 0)) {
    iVar1 = ((*(int *)(param_1 + 0x18a8) * *(int *)(param_1 + 0x18ac) * *(int *)(param_1 + 0x18c8) *
             0x40) / DAT_0084b244) / 10;
    if ((*(int *)(param_1 + 0x18b4) < 2) &&
       ((*(int *)(param_1 + 0x18c0) + iVar1) * *(int *)(param_1 + 0x18c0) < 1)) {
      *(undefined4 *)(param_1 + 0x18c0) = 0;
    }
    else {
      *(int *)(param_1 + 0x18c0) = *(int *)(param_1 + 0x18c0) + iVar1;
    }
    if (*(int *)(param_1 + 0x18a8) * 0x80 < *(int *)(param_1 + 0x18c0)) {
      *(undefined4 *)(param_1 + 0x18c8) = 0xffffffff;
    }
    if (*(int *)(param_1 + 0x18c0) < *(int *)(param_1 + 0x18a8) * -0x80) {
      *(undefined4 *)(param_1 + 0x18c8) = 1;
    }
    if (0 < *(int *)(param_1 + 0x18b4)) {
      *(int *)(param_1 + 0x18b4) = *(int *)(param_1 + 0x18b4) + -1;
    }
  }
  return;
}

