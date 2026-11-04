
undefined4 __thiscall FUN_00561830(undefined4 param_1,uint param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  if ((DAT_00a834f0 == 0) || (iVar2 = FUN_0057e0e0(param_1), iVar2 == 0)) {
    return 0xffffffff;
  }
  FUN_0056da60(&DAT_00cc4df4,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x642);
  if (((DAT_00cc4db0 == 0) ||
      (((((int)param_2 < 0 || ((param_2 & 0x7c000000) != DAT_00cc4dd8)) ||
        (DAT_00cc4de0 <= (int)(param_2 & 0xffff))) ||
       ((piVar1 = *(int **)(DAT_00cc4db4 + (param_2 & 0xffff) * 4), piVar1 == (int *)0x0 ||
        (*piVar1 * 0x10000 != (param_2 & 0x3ff0000))))))) || (piVar1[4] != 0)) {
    FUN_0056dac0(&DAT_00cc4df4);
    return 0xffffffff;
  }
  iVar2 = FUN_00561500(param_3,param_4);
  if ((iVar2 != 0) || (iVar2 = FUN_005517f0(param_1,1), iVar2 < 0)) {
    FUN_0056dac0(&DAT_00cc4df4);
    return 0xffffffff;
  }
  if ((piVar1[0x10] != 0) && (piVar1[0x11] == 0)) {
    piVar1[0x11] = 1;
    FUN_0056da60(&DAT_00a83a30,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x66b);
    FUN_005807e0(&DAT_00a83a10,piVar1 + 0x12,param_2,piVar1);
    FUN_0056dac0(&DAT_00a83a30);
  }
  FUN_0056dac0(&DAT_00cc4df4);
  if (param_3 == 0) {
    iVar2 = FUN_005501a0();
    while ((iVar2 == 0 && (iVar2 = FUN_00560f10(param_2), iVar2 == 1))) {
      FUN_0056da20(1);
      iVar2 = FUN_005501a0();
    }
  }
  return 0;
}

