
undefined4 FUN_005c3280(int param_1)

{
  int iVar1;
  int iVar2;
  int local_18 [6];
  
  if (DAT_00f0735c < param_1) {
    FUN_005bced0();
    iVar2 = ((int)(param_1 + 0x400f + (param_1 + 0x400f >> 0x1f & 0xfU)) >> 4) << 4;
    FUN_0056d380(local_18,0,0x18);
    local_18[1] = 2;
    local_18[2] = 2;
    local_18[3] = 0x10000;
    local_18[0] = iVar2;
    iVar1 = FUN_005d27b0(local_18,0,&DAT_00f07358);
    if (iVar1 < 0) {
      FUN_0056bca0(&DAT_007fed20,iVar2);
      return 0xffffffff;
    }
    DAT_00f0735c = iVar2;
  }
  return 0;
}

