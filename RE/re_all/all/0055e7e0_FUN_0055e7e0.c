
undefined4 FUN_0055e7e0(uint param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_4;
  
  if ((DAT_00a834f0 == 0) || (iVar4 = FUN_0057e0e0(), iVar4 == 0)) {
    return 0xffffffff;
  }
  FUN_0056da60(&DAT_00cc4df4,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x6b7);
  if (((DAT_00cc4db0 == 0) ||
      ((((int)param_1 < 0 || ((param_1 & 0x7c000000) != DAT_00cc4dd8)) ||
       (DAT_00cc4de0 <= (int)(param_1 & 0xffff))))) ||
     (((piVar1 = *(int **)(DAT_00cc4db4 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0 ||
       (*piVar1 * 0x10000 != (param_1 & 0x3ff0000))) || (piVar1[4] != 0)))) {
    FUN_0056dac0(&DAT_00cc4df4);
    return 0xffffffff;
  }
  FUN_0055c140(param_1,0xffffffff,0);
  iVar4 = FUN_0055fa80(param_1,piVar1,&local_4,0);
  if (iVar4 != -1) {
    uVar2 = piVar1[0x484];
    if (((uVar2 != 0xffffffff) && (DAT_00cc4db0 != 0)) &&
       ((-1 < (int)uVar2 &&
        (((((uVar2 & 0x7c000000) == DAT_00cc4dd8 && ((int)(uVar2 & 0xffff) < DAT_00cc4de0)) &&
          (piVar3 = *(int **)(DAT_00cc4db4 + (uVar2 & 0xffff) * 4), piVar3 != (int *)0x0)) &&
         ((*piVar3 * 0x10000 == (uVar2 & 0x3ff0000) && (piVar3[4] == 0)))))))) {
      piVar3[0x486] = -1;
    }
    iVar4 = FUN_00551870(local_4);
    if (iVar4 == -1) {
      return 0xffffffff;
    }
    if (iVar4 != 0) {
      FUN_00551830(local_4,1);
      piVar1[0x1d] = 0;
      piVar1[0x27] = 0;
    }
  }
  FUN_0056dac0(&DAT_00cc4df4);
  return 0;
}

