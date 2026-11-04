
undefined4 FUN_00680c90(int param_1)

{
  int iVar1;
  short *psVar2;
  uint uVar3;
  
  uVar3 = 0xf3ffc07f;
  iVar1 = 0;
  psVar2 = (short *)(param_1 + 0x94);
  while (((uVar3 & 1) == 0 || (*psVar2 == 0))) {
    iVar1 = iVar1 + 1;
    psVar2 = psVar2 + 2;
    uVar3 = uVar3 >> 1;
    if (0x1f < iVar1) {
      if (((*(short *)(param_1 + 0xb8) == 0) && (*(short *)(param_1 + 0xbc) == 0)) &&
         (*(short *)(param_1 + 200) == 0)) {
        iVar1 = 0x20;
        psVar2 = (short *)(param_1 + 0x114);
        while (*psVar2 == 0) {
          iVar1 = iVar1 + 1;
          psVar2 = psVar2 + 2;
          if (0xff < iVar1) {
            return 0;
          }
        }
      }
      return 1;
    }
  }
  return 0;
}

