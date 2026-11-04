
void FUN_00695cc0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  iVar1 = (int)param_1;
  iVar5 = 0;
  iVar4 = 0;
  if (*(int *)((int)param_1 + 200) < 1) {
    *(undefined4 *)((int)param_1 + 200) = 0;
    return;
  }
  piVar2 = *(int **)((int)param_1 + 0xcc) + 6;
  param_1 = *(int **)((int)param_1 + 0xcc);
  do {
    if (iVar4 != iVar5) {
      piVar6 = param_1;
      piVar7 = piVar2 + -6;
      for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar7 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
      }
    }
    iVar3 = *(int *)(iVar1 + 0x174);
    if (piVar2[-1] <= iVar3) {
      if (iVar3 < *piVar2) {
        *piVar2 = iVar3;
      }
      iVar5 = iVar5 + 1;
      piVar2 = piVar2 + 9;
    }
    iVar4 = iVar4 + 1;
    param_1 = param_1 + 9;
  } while (iVar4 < *(int *)(iVar1 + 200));
  *(int *)(iVar1 + 200) = iVar5;
  return;
}

