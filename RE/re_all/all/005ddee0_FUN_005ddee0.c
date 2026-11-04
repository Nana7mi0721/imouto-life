
undefined4 FUN_005ddee0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0;
  local_c = 0;
  local_8 = param_1;
  local_4 = param_2;
  FUN_005dddd0(&local_10);
  (**(code **)(*DAT_00f3a158 + 8))(DAT_00f3a158);
  DAT_00f3a158 = (int *)0x0;
  FUN_005d3850(DAT_00f3a160,(int)register0x00000010 + -0x14,DAT_00f3a154,
               (int)register0x00000010 + -0x14,0);
  iVar2 = 0;
  piVar1 = DAT_00f3a160;
  do {
    if ((int *)(&DAT_00e8063c)[iVar2] == piVar1) {
      FUN_005a0bd0(DAT_00f3a154,iVar2);
      piVar1 = DAT_00f3a160;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  (**(code **)(*piVar1 + 8))(piVar1);
  DAT_00f3a160 = (int *)0x0;
  (**(code **)(*DAT_00f3a15c + 8))(DAT_00f3a15c);
  DAT_00f3a15c = (int *)0x0;
  return 0;
}

