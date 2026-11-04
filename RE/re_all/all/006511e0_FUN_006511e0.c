
undefined4 FUN_006511e0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)FUN_006507d0(0x18);
  *(undefined4 **)(param_1 + 0xac) = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  if (*(short *)(param_1 + 0x32) == 6) {
    *puVar1 = 0;
    *(undefined4 *)(*(int *)(param_1 + 0xac) + 0x14) = 0x437f0000;
    *(undefined4 *)(*(int *)(param_1 + 0xac) + 0xc) = 0x437f0000;
    *(undefined4 *)(*(int *)(param_1 + 0xac) + 4) = 0x437f0000;
    *(undefined4 *)(*(int *)(param_1 + 0xac) + 0x10) = 0x43000000;
    *(undefined4 *)(*(int *)(param_1 + 0xac) + 8) = 0x43000000;
    return 1;
  }
  iVar2 = 0;
  do {
    *(undefined4 *)(iVar2 + *(int *)(param_1 + 0xac)) = 0;
    iVar3 = iVar2 + 8;
    *(float *)(iVar2 + 4 + *(int *)(param_1 + 0xac)) =
         (float)((1 << (*(byte *)(param_1 + 0x2c) & 0x1f)) + -1);
    iVar2 = iVar3;
  } while (iVar3 < 0x18);
  return 1;
}

