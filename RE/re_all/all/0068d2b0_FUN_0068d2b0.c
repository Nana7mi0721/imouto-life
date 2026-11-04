
void FUN_0068d2b0(int param_1,int *param_2,int param_3,int *param_4,int param_5)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  
  iVar2 = *(int *)(param_1 + 0x24);
  iVar3 = *(int *)(param_1 + 0x5c);
  if (-1 < param_5 + -1) {
    param_1 = param_3 << 2;
    do {
      iVar7 = 0;
      if (0 < iVar2) {
        piVar6 = param_2;
        do {
          puVar5 = *(undefined1 **)(*piVar6 + param_1);
          puVar4 = (undefined1 *)(*param_4 + iVar7);
          for (iVar8 = iVar3; iVar8 != 0; iVar8 = iVar8 + -1) {
            uVar1 = *puVar5;
            puVar5 = puVar5 + 1;
            *puVar4 = uVar1;
            puVar4 = puVar4 + iVar2;
          }
          iVar7 = iVar7 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar7 < iVar2);
      }
      param_1 = param_1 + 4;
      param_4 = param_4 + 1;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  return;
}

