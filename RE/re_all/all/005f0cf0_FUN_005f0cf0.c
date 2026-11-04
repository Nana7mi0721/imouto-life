
undefined4 FUN_005f0cf0(void)

{
  int iVar1;
  undefined1 local_a4 [32];
  undefined4 local_84;
  undefined1 local_80 [128];
  
  iVar1 = FUN_00567b30();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  FUN_005160a0(0);
  if (DAT_00dda504 < 0) {
    DAT_00dda504 = FUN_005ee300(0);
    if (DAT_00dda504 < 0) {
      FUN_005764b0(PTR_s_PremultipliedAlpha_pso_00a056ec,0xffffffff,0x7ffd,local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(DAT_00dda504,&DAT_00dda504);
  }
  FUN_0059c240(&DAT_00ddb600,3);
  FUN_0056d420(local_a4,&DAT_00a38d78,4);
  local_84 = 1;
  FUN_00516d40(DAT_00dda504);
  FUN_005ee5d0(1,0);
  FUN_005ee580();
  return 0;
}

