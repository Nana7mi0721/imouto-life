
uint FUN_007a6a90(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  
  if ((int)param_3 < 2) {
    return 1;
  }
  uVar2 = param_2 / param_3;
  iVar3 = 0;
  param_2 = 0;
  do {
    uVar4 = 0;
    iVar5 = 0;
    puVar6 = param_1;
    do {
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      uVar4 = uVar4 | uVar1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar2);
    param_2 = param_2 | (uint)(uVar4 != 0) << ((byte)iVar3 & 0x1f);
    iVar3 = iVar3 + 1;
    param_1 = param_1 + uVar2;
  } while (iVar3 < (int)param_3);
  return param_2;
}

