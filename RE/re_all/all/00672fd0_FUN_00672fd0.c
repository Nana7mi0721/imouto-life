
void FUN_00672fd0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  
  if (7 < *(byte *)(param_1 + 0x15d)) {
    return;
  }
  uVar1 = (uint)*(byte *)(param_1 + 0x15d);
  *(undefined4 *)(param_1 + 0x2c4) = 0x11;
  iVar2 = -uVar1 + 8;
  FUN_00668560(param_1,uVar1 + 0x20 + param_2,iVar2);
  *(undefined1 *)(param_1 + 0x15d) = 8;
  iVar2 = FUN_00668e30(param_2 + 0x20,uVar1,iVar2);
  if (iVar2 != 0) {
    if ((uVar1 < 4) && (iVar2 = FUN_00668e30(param_2 + 0x20,uVar1,-uVar1 + 4), iVar2 != 0)) {
      pcVar3 = s_Not_a_PNG_file_00a0cd90;
    }
    else {
      pcVar3 = s_PNG_file_corrupted_by_ASCII_conv_00a0cd68;
    }
    FUN_00668620(param_1,pcVar3);
  }
  if (uVar1 < 3) {
    *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 0x1000;
  }
  return;
}

