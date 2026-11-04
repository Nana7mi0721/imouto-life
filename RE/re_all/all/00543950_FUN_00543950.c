
undefined4
FUN_00543950(undefined1 *param_1,uint param_2,int param_3,int param_4,undefined1 *param_5)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  int local_24;
  int local_20;
  
  iVar4 = param_3;
  iVar1 = param_2 * param_3;
  local_24 = (int)param_1;
  local_20 = iVar1 + (int)param_1;
  param_1 = param_5;
  param_3 = param_4;
  iVar1 = ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) + local_20;
  param_4 = iVar4 / 2;
  if (0 < param_4) {
    do {
      iVar4 = 0;
      if (0 < (int)param_2 / 2) {
        puVar2 = (undefined1 *)(param_3 + 1);
        puVar3 = (undefined1 *)(local_24 + param_2);
        puVar5 = param_1;
        do {
          puVar2[-1] = puVar5[local_24 - (int)param_1];
          *puVar2 = puVar3[1 - param_2];
          puVar2[param_2 - 1] = *puVar3;
          puVar2[param_2] = puVar3[1];
          *puVar5 = *(undefined1 *)(iVar4 + iVar1);
          puVar2[(int)param_1 - param_3] = *(undefined1 *)(iVar4 + local_20);
          iVar4 = iVar4 + 1;
          puVar2 = puVar2 + 2;
          puVar3 = puVar3 + 2;
          puVar5 = puVar5 + 2;
        } while (iVar4 < (int)param_2 / 2);
      }
      param_3 = param_3 + param_2 * 2;
      param_1 = param_1 + param_2;
      local_24 = local_24 + param_2 * 2;
      local_20 = local_20 + (param_2 >> 1);
      iVar1 = iVar1 + (param_2 >> 1);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return 0;
}

