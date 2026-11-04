
int FUN_00608900(int param_1,int *param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  piVar3 = param_2;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2718;
  local_c = ExceptionList;
  iVar4 = 0;
  if (param_2 == (int *)0x0) {
    return -0x7fffbffd;
  }
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x78);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  *(int *)(param_1 + 0x4c) = param_3;
  iVar1 = *(int *)(param_1 + 0x48);
  if (*(int *)(*(int *)(iVar1 + 0x90) + 0x18) == 0) {
    iVar4 = FUN_00601a30(param_1,piVar3,param_3);
    goto LAB_00608adf;
  }
  if ((param_3 == 0) || (*(char *)(iVar1 + 0x98) == '\0')) {
    piVar2 = *(int **)(*(int *)(iVar1 + 0x90) + 0x9c);
    iVar4 = (**(code **)(*piVar2 + 0x10))(piVar2,piVar3,param_3);
    if (iVar4 < 0) goto LAB_00608adf;
    FUN_00608d00(piVar3);
  }
  else {
    param_2 = *(int **)(*(int *)(iVar1 + 0x90) + 0x98);
    if (param_2 == (int *)0x0) {
      piVar2 = *(int **)(*(int *)(iVar1 + 0x90) + 0x9c);
      iVar4 = (**(code **)(*piVar2 + 0xc))(piVar2,&param_2);
      if (iVar4 < 0) {
        iVar4 = FUN_00601980(&param_2);
        if (iVar4 < 0) goto LAB_006089f4;
      }
      FUN_00608d00(param_2);
      (**(code **)(*param_2 + 8))(param_2);
    }
LAB_006089f4:
    if (piVar3 == param_2) {
      iVar4 = -0x7fffbffb;
      goto LAB_00608adf;
    }
    if (iVar4 < 0) goto LAB_00608adf;
    iStack_28 = 0;
    iStack_24 = 0;
    iStack_2c = 0;
    uStack_20 = 0;
    iVar4 = (**(code **)(*piVar3 + 0x10))(piVar3,&iStack_1c);
    if (iVar4 < 0) goto LAB_00608adf;
    iVar4 = (**(code **)(*param_2 + 0xc))(param_2,&iStack_1c,&iStack_2c);
    if (iVar4 < 0) goto LAB_00608adf;
    if (((iStack_2c < iStack_1c) || (iStack_28 < iStack_18)) || (iStack_24 < iStack_14)) {
      iVar4 = -0x7fffbffb;
      goto LAB_00608adf;
    }
    piVar2 = *(int **)(*(int *)(*(int *)(param_1 + 0x48) + 0x90) + 0x9c);
    iVar4 = (**(code **)(*piVar2 + 0x10))(piVar2,param_2,0);
  }
  if (-1 < iVar4) {
    (**(code **)(*piVar3 + 4))(piVar3);
    piVar2 = *(int **)(param_1 + 4);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    *(int **)(param_1 + 4) = piVar3;
  }
LAB_00608adf:
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return iVar4;
}

