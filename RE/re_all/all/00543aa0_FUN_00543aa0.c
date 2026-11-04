
undefined4 FUN_00543aa0(int param_1,uint param_2,int param_3,int param_4,undefined1 *param_5)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  
  puVar8 = param_5;
  iVar5 = param_2 * param_3 + param_1;
  iVar1 = (int)(param_2 + ((int)param_2 >> 0x1f & 3U)) >> 2;
  if (0 < param_3) {
    param_5 = (undefined1 *)param_3;
    iVar4 = param_4;
    do {
      if (0 < iVar1) {
        puVar2 = (undefined1 *)(iVar4 + 2);
        puVar3 = (undefined1 *)(param_1 + 3);
        puVar6 = (undefined1 *)(iVar5 + 1);
        puVar7 = puVar8;
        param_4 = iVar1;
        do {
          puVar2[-2] = puVar3[-3];
          puVar2[-1] = puVar3[-2];
          *puVar2 = puVar2[param_1 - iVar4];
          puVar2[1] = *puVar3;
          *puVar7 = puVar6[-1];
          puVar6[(int)puVar8 - iVar5] = *puVar6;
          puVar3 = puVar3 + 4;
          puVar2 = puVar2 + 4;
          puVar6 = puVar6 + 2;
          puVar7 = puVar7 + 2;
          param_4 = param_4 + -1;
        } while (param_4 != 0);
      }
      iVar4 = iVar4 + param_2;
      param_1 = param_1 + param_2;
      puVar8 = puVar8 + (param_2 >> 1);
      iVar5 = iVar5 + (param_2 >> 1);
      param_5 = (undefined1 *)((int)param_5 + -1);
    } while (param_5 != (undefined1 *)0x0);
  }
  return 0;
}

