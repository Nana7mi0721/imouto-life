
undefined4 FUN_005f3c10(void)

{
  undefined1 local_80 [128];
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (DAT_00dda508 < 0) {
    DAT_00dda508 = FUN_005f2360(0);
    if (DAT_00dda508 < 0) {
      FUN_005764b0(PTR_s_InterpolatedAlpha_pso_00a05838,0xffffffff,0x7ffd,local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(DAT_00dda508,&DAT_00dda508);
  }
  FUN_005f23c0(DAT_00dda508,0,1,0xffffffff,0);
  return 0;
}

