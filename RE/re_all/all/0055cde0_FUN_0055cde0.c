
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0055cde0(undefined4 param_1,int param_2,uint param_3)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int *piVar4;
  float10 fVar5;
  undefined8 uVar6;
  
  iVar3 = FUN_0057e0e0(param_1);
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  if ((((DAT_00cc4db0 == 0) || ((int)param_3 < 0)) || ((param_3 & 0x7c000000) != DAT_00cc4dd8)) ||
     (((DAT_00cc4de0 <= (int)(param_3 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc4db4 + (param_3 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_3 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  param_2 = param_2 + -10000;
  if (param_2 < -10000) {
    param_2 = -10000;
  }
  iVar3 = 0;
  if (0 < piVar1[0x1c]) {
    uVar6 = CONCAT44(unaff_EBX,unaff_EBP);
    piVar4 = piVar1 + 0x31;
    do {
      FUN_00551c00(piVar4,param_2,uVar6);
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 0x6e;
    } while (iVar3 < piVar1[0x1c]);
  }
  if (DAT_00a83c58 == 0) {
    fVar2 = ((float)param_2 / (float)_DAT_008053a0) / (float)_DAT_00829840;
  }
  else {
    fVar2 = ((float)param_2 / (float)_DAT_0081ec08) / (float)_DAT_00829840;
  }
  fVar5 = (float10)FUN_0056d500(_DAT_007d52d8,fVar2);
  iVar3 = FUN_0050e240((double)((fVar5 / (float10)_DAT_007d6148) * (float10)_DAT_008052e8));
  piVar1[0x95a] = param_2;
  piVar1[0x95b] = param_2;
  piVar1[0x95c] = param_2;
  piVar1[0x95d] = param_2;
  piVar1[0x95e] = param_2;
  piVar1[0x95f] = param_2;
  piVar1[0x960] = param_2;
  piVar1[0x961] = param_2;
  piVar1[0x962] = iVar3;
  piVar1[0x963] = iVar3;
  piVar1[0x964] = iVar3;
  piVar1[0x965] = iVar3;
  piVar1[0x966] = iVar3;
  piVar1[0x967] = iVar3;
  piVar1[0x968] = iVar3;
  piVar1[0x969] = iVar3;
  return 0;
}

