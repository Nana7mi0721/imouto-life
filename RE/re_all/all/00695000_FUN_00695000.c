
void FUN_00695000(int param_1,undefined4 *param_2,int *param_3,int param_4,int param_5)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  if (-1 < param_5 + -1) {
    iVar5 = param_4 << 2;
    do {
      iVar4 = iVar5 + 4;
      pcVar8 = (char *)*param_2;
      param_2 = param_2 + 1;
      pcVar7 = *(char **)(param_3[1] + -4 + iVar4);
      if (iVar3 != 0) {
        iVar6 = *(int *)(*param_3 + -4 + iVar4) - (int)pcVar7;
        iVar5 = *(int *)(iVar5 + param_3[2]) - (int)pcVar7;
        param_1 = iVar3;
        do {
          cVar1 = pcVar8[1];
          cVar2 = pcVar8[2];
          pcVar7[iVar6] = (*pcVar8 - cVar1) + -0x80;
          *pcVar7 = cVar1;
          pcVar7[iVar5] = (cVar2 - cVar1) + -0x80;
          pcVar8 = pcVar8 + 3;
          pcVar7 = pcVar7 + 1;
          param_1 = param_1 + -1;
        } while (param_1 != 0);
      }
      param_5 = param_5 + -1;
      iVar5 = iVar4;
    } while (param_5 != 0);
  }
  return;
}

