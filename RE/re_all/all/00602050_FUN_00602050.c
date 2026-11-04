
void FUN_00602050(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  
  iVar1 = 4;
  bVar4 = true;
  piVar2 = param_2;
  piVar3 = &DAT_0085e914;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *piVar2 == *piVar3;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    if (param_1 != 0) {
      FUN_005fd080(param_1 + 0xc,param_3);
      return;
    }
  }
  else {
    iVar1 = 4;
    bVar4 = true;
    piVar2 = param_2;
    piVar3 = &DAT_0085ea04;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *piVar2 == *piVar3;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (bVar4);
    if (!bVar4) {
      FUN_00602f90(param_1,param_2,param_3);
      return;
    }
    if (param_1 != 0) {
      FUN_005fd080(param_1 + 0x10,param_3);
      return;
    }
  }
  FUN_005fd080(0,param_3);
  return;
}

