
int FUN_0055e970(uint param_1)

{
  int *piVar1;
  int iVar2;
  
  if (DAT_00a834f0 != 0) {
    iVar2 = FUN_0057e0e0();
    if (iVar2 != 0) {
      FUN_0056da60(&DAT_00cc4df4,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x751);
      if ((((DAT_00cc4db0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc4dd8))
         || (((DAT_00cc4de0 <= (int)(param_1 & 0xffff) ||
              (piVar1 = *(int **)(DAT_00cc4db4 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
             ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))))) {
        FUN_0056dac0(&DAT_00cc4df4);
        return -1;
      }
      FUN_0055c140(param_1,0xffffffff,0);
      iVar2 = piVar1[0x933];
      FUN_0056dac0(&DAT_00cc4df4);
      return iVar2;
    }
  }
  return -1;
}

