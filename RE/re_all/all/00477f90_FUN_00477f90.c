
bool FUN_00477f90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  bool bVar4;
  
  FUN_004d0120(param_1);
  piVar1 = (int *)FUN_004ce990(param_3);
  bVar4 = *piVar1 / 1000 == 1;
  if (bVar4) {
    iVar3 = *piVar1 % 1000;
    FUN_004d0120(param_1);
    FUN_004cfcd0(param_2);
    puVar2 = (undefined4 *)FUN_004ce990(iVar3);
    *puVar2 = param_4;
  }
  return bVar4;
}

