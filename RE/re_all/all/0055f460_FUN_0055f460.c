
undefined4 FUN_0055f460(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = FUN_0057e0e0();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if ((((DAT_00cc4db0 == 0) || ((int)param_2 < 0)) || ((param_2 & 0x7c000000) != DAT_00cc4dd8)) ||
     (((DAT_00cc4de0 <= (int)(param_2 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc4db4 + (param_2 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_2 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  if (param_1 < 0x2711) {
    if (param_1 < -10000) {
      param_1 = -10000;
    }
  }
  else {
    param_1 = 10000;
  }
  iVar2 = 0;
  if (0 < piVar1[0x1c]) {
    piVar3 = piVar1 + 0x31;
    do {
      FUN_0055d3e0(piVar3,param_1);
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 0x6e;
    } while (iVar2 < piVar1[0x1c]);
  }
  piVar1[0x96a] = param_1;
  return 0;
}

