
void FUN_00577260(undefined4 param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = FUN_00572ac0(param_1);
  if (iVar3 == 1) {
    iVar3 = 0;
    cVar1 = (char)*param_2;
    while (cVar1 != '\0') {
      iVar3 = iVar3 + 1;
      cVar1 = *(char *)(iVar3 + (int)param_2);
    }
    FUN_00576e80(param_1,(char *)(iVar3 + (int)param_2),param_3);
  }
  else {
    if (iVar3 == 2) {
      iVar3 = 0;
      sVar2 = (short)*param_2;
      while (sVar2 != 0) {
        iVar3 = iVar3 + 1;
        sVar2 = *(short *)((int)param_2 + iVar3 * 2);
      }
      FUN_00576e80(param_1,(short *)((int)param_2 + iVar3 * 2),param_3);
      return;
    }
    if (iVar3 == 4) {
      iVar4 = 0;
      iVar3 = *param_2;
      while (iVar3 != 0) {
        iVar4 = iVar4 + 1;
        iVar3 = param_2[iVar4];
      }
      FUN_00576e80(param_1,param_2 + iVar4,param_3);
      return;
    }
  }
  return;
}

