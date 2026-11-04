
int FUN_006a9590(int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  puVar1 = (undefined4 *)FUN_00501f2f();
  *puVar1 = 0;
  if (param_1[0xb0] == 0) {
    return -1;
  }
  if (*param_1 == 0) {
    return 0;
  }
  uVar2 = FUN_006a8700(param_1 + 6,0x800);
  iVar3 = (*(code *)param_1[0xb0])(uVar2,1,0x800,*param_1);
  if (0 < iVar3) {
    FUN_006a87a0(param_1 + 6,iVar3);
  }
  if (iVar3 == 0) {
    piVar4 = (int *)FUN_00501f2f();
    if (*piVar4 != 0) {
      return -1;
    }
  }
  return iVar3;
}

