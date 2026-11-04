
undefined4 __thiscall FUN_0055d100(undefined4 param_1,int param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = FUN_0057e0e0(param_1);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  iVar2 = 0;
  if ((((DAT_00cc4db0 == 0) || ((int)param_3 < 0)) || ((param_3 & 0x7c000000) != DAT_00cc4dd8)) ||
     (((DAT_00cc4de0 <= (int)(param_3 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc4db4 + (param_3 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_3 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  if (param_2 == -1) {
    param_2 = 0;
  }
  iVar3 = param_2;
  if (piVar1[0x973] != 0) {
    iVar3 = FUN_0050e270((float)piVar1[0x974] * (float)param_2);
  }
  if (0 < piVar1[0x1c]) {
    piVar4 = piVar1 + 0x31;
    do {
      FUN_005519c0(piVar4,iVar3);
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 0x6e;
    } while (iVar2 < piVar1[0x1c]);
  }
  piVar1[0x96b] = param_2;
  return 0;
}

