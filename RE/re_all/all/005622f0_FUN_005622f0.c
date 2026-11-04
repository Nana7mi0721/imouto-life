
undefined4 FUN_005622f0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint local_8;
  int local_4;
  
  if ((DAT_00a834f0 == 0) || (iVar1 = FUN_0057e0e0(), iVar1 == 0)) {
    return 0xffffffff;
  }
  FUN_0056da60(&DAT_00cc4df4,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x19c4);
  if (param_3 == 0) {
    if ((((DAT_00cc4db0 == 0) || ((int)param_2 < 0)) || ((param_2 & 0x7c000000) != DAT_00cc4dd8)) ||
       (DAT_00cc4de0 <= (int)(param_2 & 0xffff))) goto LAB_0056238c;
    local_4 = (param_2 & 0xffff) * 4;
    piVar2 = *(int **)(local_4 + DAT_00cc4db4);
    if (((piVar2 == (int *)0x0) || (*piVar2 * 0x10000 != (param_2 & 0x3ff0000))) || (piVar2[4] != 0)
       ) goto LAB_0056238c;
  }
  else {
    if (((DAT_00cc4db0 == 0) || ((int)param_2 < 0)) ||
       (((param_2 & 0x7c000000) != DAT_00cc4dd8 || (DAT_00cc4de0 <= (int)(param_2 & 0xffff)))))
    goto LAB_0056238c;
    local_4 = (param_2 & 0xffff) * 4;
    piVar2 = *(int **)(local_4 + DAT_00cc4db4);
    if ((piVar2 == (int *)0x0) || (*piVar2 * 0x10000 != (param_2 & 0x3ff0000))) goto LAB_0056238c;
  }
  local_8 = param_2 & 0x7c000000;
  iVar1 = FUN_005512e0(param_2,param_3);
  if (param_1 < iVar1) {
    if (param_1 == -1) {
      piVar2[0x498] = -1;
      FUN_0056dac0(&DAT_00cc4df4);
      return 0;
    }
    if ((piVar2[0x482] != 0) ||
       ((((param_3 == 0 && (iVar1 = FUN_00561be0(), -1 < iVar1)) && (DAT_00cc4db0 != 0)) &&
        (((local_8 == DAT_00cc4dd8 && ((int)(param_2 & 0xffff) < DAT_00cc4de0)) &&
         ((piVar2 = *(int **)(local_4 + DAT_00cc4db4), piVar2 != (int *)0x0 &&
          ((*piVar2 * 0x10000 == (param_2 & 0x3ff0000) && (piVar2[4] == 0)))))))))) {
      if (piVar2[0x92d] < 2) {
        piVar2[0x498] = param_1;
        if (param_1 < piVar2[0x930]) {
          FUN_0055c140(param_2,0xffffffff,0);
          FUN_00550d40(piVar2[0x933],param_2,param_3);
        }
        FUN_0056dac0(&DAT_00cc4df4);
        return 0;
      }
      FUN_0056bb10(&DAT_007d68a8);
    }
  }
LAB_0056238c:
  FUN_0056dac0(&DAT_00cc4df4);
  return 0xffffffff;
}

