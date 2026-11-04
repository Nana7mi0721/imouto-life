
undefined4 FUN_005c31f0(int param_1)

{
  int iVar1;
  int iVar2;
  int local_18 [6];
  
  if (DAT_00f07354 < param_1) {
    FUN_005bce70();
    iVar2 = ((int)(param_1 + 0x400f + (param_1 + 0x400f >> 0x1f & 0xfU)) >> 4) << 4;
    FUN_0056d380(local_18,0,0x18);
    local_18[1] = 2;
    local_18[2] = 1;
    local_18[3] = 0x10000;
    local_18[0] = iVar2;
    iVar1 = FUN_005d27b0(local_18,0,&DAT_00f07350);
    if (iVar1 < 0) {
      FUN_0056bca0(&DAT_007fecd0,iVar2);
      return 0xffffffff;
    }
    DAT_00f07354 = iVar2;
  }
  return 0;
}

