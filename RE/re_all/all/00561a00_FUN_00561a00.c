
undefined4 FUN_00561a00(uint param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_0057e0e0();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if (((((DAT_00cc4db0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc4dd8)) ||
      ((DAT_00cc4de0 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc4db4 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)))) ||
     ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))) {
    return 0xffffffff;
  }
  if (piVar1[0x482] == 1) {
    uVar3 = FUN_00561830(param_1,param_2,param_3);
    return uVar3;
  }
  iVar2 = FUN_0055f060(param_3);
  if (iVar2 == 1) {
    return 0;
  }
  iVar2 = FUN_005517f0(piVar1 + piVar1[0x94b] * 0x6e + 0x31,param_2 == 3);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  if ((piVar1[0x10] != 0) && (piVar1[0x11] == 0)) {
    piVar1[0x11] = 1;
    FUN_0056da60(&DAT_00a83a30,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x13da);
    FUN_005807e0(&DAT_00a83a10,piVar1 + 0x12,param_1,piVar1);
    FUN_0056dac0(&DAT_00a83a30);
  }
  if (param_2 == 0) {
    iVar2 = FUN_005501a0();
    while ((iVar2 == 0 && (iVar2 = FUN_00560f10(param_1), iVar2 == 1))) {
      FUN_0056da20(1);
      iVar2 = FUN_005501a0();
    }
  }
  return 0;
}

