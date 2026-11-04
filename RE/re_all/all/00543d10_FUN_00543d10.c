
undefined4 FUN_00543d10(int param_1,int param_2,int param_3,int param_4,undefined1 *param_5)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  if (0 < param_3) {
    puVar5 = param_5;
    param_5 = (undefined1 *)(param_1 + 1);
    do {
      if (0 < param_2 / 2) {
        puVar2 = (undefined1 *)(param_4 + 1);
        puVar1 = param_5;
        iVar3 = param_2 / 2;
        puVar4 = puVar5;
        do {
          puVar2[-1] = puVar1[-1];
          *puVar2 = puVar1[1];
          *puVar4 = *puVar1;
          puVar2[(int)puVar5 - param_4] = puVar1[2];
          puVar1 = puVar1 + 4;
          puVar2 = puVar2 + 2;
          puVar4 = puVar4 + 2;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      puVar5 = puVar5 + param_2;
      param_5 = param_5 + param_2 * 2;
      param_4 = param_4 + param_2;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return 0;
}

