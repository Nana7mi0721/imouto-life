
void FUN_0068d220(int param_1,int *param_2,int param_3,undefined4 *param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar3 = *(int *)(param_1 + 0x5c);
  if (-1 < param_5 + -1) {
    param_3 = param_3 * 4;
    param_1 = param_5;
    do {
      piVar1 = (int *)(param_3 + param_2[2]);
      piVar2 = (int *)(*param_2 + param_3);
      puVar4 = *(undefined1 **)(param_2[1] + param_3);
      puVar5 = (undefined1 *)*param_4;
      param_4 = param_4 + 1;
      param_3 = param_3 + 4;
      if (iVar3 != 0) {
        iVar8 = *piVar2 - (int)puVar4;
        iVar7 = *piVar1 - (int)puVar4;
        iVar6 = iVar3;
        do {
          *puVar5 = puVar4[iVar8];
          puVar5[1] = *puVar4;
          puVar5[2] = puVar4[iVar7];
          puVar5 = puVar5 + 3;
          puVar4 = puVar4 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}

