
undefined4 FUN_0055f370(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  iVar2 = FUN_0057e0e0();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if ((((DAT_00cc4db0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc4dd8)) ||
     (((DAT_00cc4de0 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc4db4 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  if (piVar1[0x482] == 1) {
    uVar3 = FUN_0055e7e0();
    return uVar3;
  }
  iVar2 = 0;
  if (0 < piVar1[0x1c]) {
    piVar6 = piVar1 + 0x31;
    piVar5 = piVar1 + 0x27;
    do {
      piVar5[-10] = 0;
      *piVar5 = 0;
      iVar4 = FUN_00551870(piVar6);
      if (iVar4 == -1) {
        return 0xffffffff;
      }
      if (iVar4 != 0) {
        FUN_00551830(piVar6,1);
      }
      iVar2 = iVar2 + 1;
      piVar5 = piVar5 + 1;
      piVar6 = piVar6 + 0x6e;
    } while (iVar2 < piVar1[0x1c]);
  }
  return 0;
}

