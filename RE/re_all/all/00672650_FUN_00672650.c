
void FUN_00672650(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return;
  }
  if ((param_4 < 0) || (0x100 < param_4)) {
    if (*(char *)(param_2 + 0x19) != '\x03') {
      FUN_006687b0(param_1,s_Invalid_palette_length_00a0cbbc);
      return;
    }
    FUN_00668620();
  }
  if (((0 < param_4) && (param_3 == (undefined4 *)0x0)) ||
     ((param_4 == 0 && ((*(byte *)(param_1 + 0x268) & 1) == 0)))) {
    FUN_00668620(param_1,s_Invalid_palette_00a0cbac);
    return;
  }
  FUN_00669290(param_1,param_2,0x1000,0);
  puVar1 = (undefined4 *)FUN_0066c950(param_1,0x300);
  *(undefined4 **)(param_1 + 0x144) = puVar1;
  if (0 < param_4) {
    for (uVar2 = (uint)(param_4 * 3) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar1 = *param_3;
      param_3 = param_3 + 1;
      puVar1 = puVar1 + 1;
    }
    for (uVar2 = param_4 * 3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar1 = *(undefined1 *)param_3;
      param_3 = (undefined4 *)((int)param_3 + 1);
      puVar1 = (undefined4 *)((int)puVar1 + 1);
    }
  }
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x144);
  *(short *)(param_1 + 0x148) = (short)param_4;
  *(short *)(param_2 + 0x14) = (short)param_4;
  *(uint *)(param_2 + 0xe8) = *(uint *)(param_2 + 0xe8) | 0x1000;
  *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 8;
  return;
}

