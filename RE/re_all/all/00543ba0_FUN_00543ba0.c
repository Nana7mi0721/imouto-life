
undefined4 FUN_00543ba0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int local_30;
  
  iVar1 = param_3;
  local_30 = param_1;
  param_1 = param_4;
  puVar6 = (undefined1 *)(param_2 * param_3 + local_30);
  param_3 = param_5;
  param_5 = iVar1 / 2;
  if (0 < param_5) {
    do {
      if (0 < param_2 / 2) {
        puVar3 = (undefined1 *)(local_30 + param_2);
        puVar4 = (undefined1 *)(param_2 + 1 + param_1);
        puVar2 = (undefined1 *)(param_3 + 1);
        puVar5 = puVar6;
        param_4 = param_2 / 2;
        do {
          puVar5[param_1 - (int)puVar6] = puVar5[local_30 - (int)puVar6];
          puVar2[param_1 - param_3] = puVar3[1 - param_2];
          puVar4[param_2 - (param_2 + 1)] = *puVar3;
          *puVar4 = puVar3[1];
          puVar2[-1] = *puVar5;
          *puVar2 = puVar2[(int)puVar6 - param_3];
          puVar3 = puVar3 + 2;
          puVar4 = puVar4 + 2;
          puVar5 = puVar5 + 2;
          puVar2 = puVar2 + 2;
          param_4 = param_4 + -1;
        } while (param_4 != 0);
      }
      param_1 = param_1 + param_2 * 2;
      param_3 = param_3 + param_2;
      local_30 = local_30 + param_2 * 2;
      puVar6 = puVar6 + param_2;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  return 0;
}

