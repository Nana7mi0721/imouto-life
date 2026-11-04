
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0055cf80(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  float10 fVar5;
  
  iVar2 = FUN_0057e0e0();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  iVar2 = 0;
  if ((((DAT_00cc4db0 == 0) || ((int)param_2 < 0)) || ((param_2 & 0x7c000000) != DAT_00cc4dd8)) ||
     (((DAT_00cc4de0 <= (int)(param_2 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc4db4 + (param_2 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_2 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (param_1 != 0) {
    if (DAT_00a83c58 == 0) {
      fVar5 = (float10)FUN_0056d570((double)param_1 / _DAT_0081ec30);
      fVar5 = fVar5 * (float10)_DAT_008053a0;
    }
    else {
      fVar5 = (float10)FUN_0056d570((double)param_1 / _DAT_0081ec30);
      fVar5 = fVar5 * (float10)_DAT_0081ec08;
    }
    iVar4 = FUN_0050e240((double)(fVar5 * (float10)_DAT_00829840));
    if (-0x2711 < iVar4) goto LAB_0055d060;
  }
  iVar4 = -10000;
LAB_0055d060:
  if (0 < piVar1[0x1c]) {
    piVar3 = piVar1 + 0x31;
    do {
      FUN_00551c00(piVar3,iVar4);
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 0x6e;
    } while (iVar2 < piVar1[0x1c]);
  }
  piVar1[0x95a] = iVar4;
  piVar1[0x95b] = iVar4;
  piVar1[0x95c] = iVar4;
  piVar1[0x95d] = iVar4;
  piVar1[0x95e] = iVar4;
  piVar1[0x95f] = iVar4;
  piVar1[0x960] = iVar4;
  piVar1[0x961] = iVar4;
  piVar1[0x962] = param_1;
  piVar1[0x963] = param_1;
  piVar1[0x964] = param_1;
  piVar1[0x965] = param_1;
  piVar1[0x966] = param_1;
  piVar1[0x967] = param_1;
  piVar1[0x968] = param_1;
  piVar1[0x969] = param_1;
  return 0;
}

