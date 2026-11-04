
void FUN_006b8e40(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 3;
  piVar2 = (int *)(param_2 + 8);
  piVar3 = (int *)(param_1 + 4);
  do {
    piVar3[-1] = piVar2[-2];
    *piVar3 = piVar2[-1];
    iVar1 = *piVar2;
    *(int *)((param_1 - param_2) + (int)piVar2) = -iVar1;
    iVar4 = iVar4 + -1;
    piVar3[2] = (1 - *piVar3) * -iVar1 + piVar2[1];
    piVar2 = piVar2 + 4;
    piVar3 = piVar3 + 4;
  } while (iVar4 != 0);
  return;
}

