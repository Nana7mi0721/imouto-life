
void FUN_0068d080(int param_1,int *param_2,int param_3,undefined4 *param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  
  iVar5 = *(int *)(param_1 + 0x5c);
  if (-1 < param_5 + -1) {
    param_3 = param_3 << 2;
    do {
      piVar1 = (int *)(param_2[1] + param_3);
      pcVar9 = (char *)*param_4;
      piVar2 = (int *)(*param_2 + param_3);
      param_4 = param_4 + 1;
      pcVar8 = *(char **)(param_3 + param_2[2]);
      param_3 = param_3 + 4;
      if (iVar5 != 0) {
        iVar7 = *piVar1 - (int)pcVar8;
        iVar6 = *piVar2 - (int)pcVar8;
        param_1 = iVar5;
        do {
          cVar3 = pcVar8[iVar7];
          cVar4 = *pcVar8;
          *pcVar9 = pcVar8[iVar6] + cVar3 + -0x80;
          pcVar9[1] = cVar3;
          pcVar9[2] = cVar4 + cVar3 + -0x80;
          pcVar9 = pcVar9 + 3;
          pcVar8 = pcVar8 + 1;
          param_1 = param_1 + -1;
        } while (param_1 != 0);
      }
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  return;
}

