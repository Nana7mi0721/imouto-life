
undefined4 FUN_005f3730(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 local_80 [128];
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  piVar1 = (int *)(&DAT_00dda4d4 + param_2 * 4);
  if (*(int *)(&DAT_00dda4d4 + param_2 * 4) < 0) {
    iVar2 = FUN_005f2360(0);
    *piVar1 = iVar2;
    if (iVar2 < 0) {
      FUN_005764b0((&PTR_s_Invert_pso_00a0580c)[param_2],0xffffffff,0x7ffd,local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar2,piVar1);
  }
  FUN_005f23c0(*piVar1,0,1,0xffffffff,0);
  return 0;
}

