
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006b0170(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  float10 fVar4;
  
  puVar3 = param_1;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  param_1[3] = param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[1];
  *param_1 = *param_2;
  uVar1 = FUN_006afca0(param_2[2],param_2[1],0);
  param_1[5] = uVar1;
  uVar1 = FUN_006afe60(param_2);
  param_1[0xb] = uVar1;
  fVar4 = (float10)FUN_006afc50(param_2[4]);
  FUN_006c5af0((double)(fVar4 + (float10)_DAT_007d589c));
  uVar1 = __ftol();
  param_1[0xc] = uVar1;
  fVar4 = (float10)FUN_006afc50(param_2[5]);
  FUN_006c5af0((double)(fVar4 + (float10)_DAT_007d589c));
  uVar1 = __ftol();
  param_1[0xd] = uVar1;
  return 0;
}

