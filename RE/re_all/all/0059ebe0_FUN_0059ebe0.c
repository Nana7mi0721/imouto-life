
undefined4
FUN_0059ebe0(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int local_8;
  int local_4;
  
  local_4 = 0;
  local_8 = 0;
  if (param_6 == 0) {
    if (DAT_00cc6820 == 0) {
      return 0xffffffff;
    }
    if ((int)param_1 < 0) {
      return 0xffffffff;
    }
    if ((param_1 & 0x7c000000) != DAT_00cc6848) {
      return 0xffffffff;
    }
    if (DAT_00cc6850 <= (int)(param_1 & 0xffff)) {
      return 0xffffffff;
    }
    piVar2 = *(int **)(DAT_00cc6824 + (param_1 & 0xffff) * 4);
    if (piVar2 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar2 * 0x10000 != (param_1 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar2[4] != 0) {
      return 0xffffffff;
    }
  }
  else if (((((DAT_00cc6820 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc6848)
            ) || ((DAT_00cc6850 <= (int)(param_1 & 0xffff) ||
                  (piVar2 = *(int **)(DAT_00cc6824 + (param_1 & 0xffff) * 4), piVar2 == (int *)0x0))
                 )) || (*piVar2 * 0x10000 != (param_1 & 0x3ff0000))) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    iVar1 = FUN_005d5b50(param_3,&local_4,param_6);
    if (iVar1 != 0) {
      FUN_0056bb10(&DAT_007fc4bc);
      goto LAB_0059ed10;
    }
  }
  else {
    iVar1 = FUN_005d5b00(param_3,&local_8);
    if (iVar1 != 0) {
      FUN_0056bb10(&DAT_007fc4e8);
      goto LAB_0059ed10;
    }
  }
  iVar1 = FUN_0056e050(param_4,"..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D9.cpp",
                       0x6840);
  piVar2[0xd] = iVar1;
  if (iVar1 != 0) {
    FUN_0056d420(iVar1,param_3,param_4);
    piVar2[0xc] = (uint)(param_2 != 0);
    iVar1 = piVar2[0xd];
    if ((*(char *)(iVar1 + 4) == -2) && (*(char *)(iVar1 + 5) == -1)) {
      *(int *)(piVar2[0xf] + 8) = iVar1 + 0x28;
      *(undefined4 *)(piVar2[0xf] + 4) = *(undefined4 *)(piVar2[0xd] + 0x18);
    }
    else {
      *(undefined4 *)(piVar2[0xf] + 8) = 0;
      *(undefined4 *)(piVar2[0xf] + 4) = 0;
    }
    iVar1 = local_8;
    if (param_2 == 0) {
      iVar1 = local_4;
    }
    *(int *)piVar2[0xf] = iVar1;
    if (param_5 != 0) {
      FUN_0056e1d0(param_3);
    }
    return 0;
  }
  FUN_0056bb10(&DAT_007d5534);
LAB_0059ed10:
  if (local_8 != 0) {
    FUN_005d5640(local_8,param_6);
  }
  if (local_4 != 0) {
    FUN_005d5640(local_4,param_6);
  }
  if (param_5 != 0) {
    FUN_0056e1d0(param_3);
  }
  return 0xffffffff;
}

