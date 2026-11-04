
uint FUN_00603310(int param_1,uint param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint local_4;
  
  if (param_3 == (int *)0x0) {
    return 0x80004003;
  }
  if (param_4 == (uint *)0x0) {
    if (1 < param_2) {
      return 0x80070057;
    }
  }
  else {
    *param_4 = 0;
  }
  local_4 = 0;
  iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  if (iVar2 != *(int *)(param_1 + 0x10)) {
    FUN_00603490(param_1);
  }
  uVar3 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
  uVar5 = param_2;
  if ((int)uVar3 <= (int)param_2) {
    uVar5 = uVar3;
  }
  if (uVar5 == 0) {
    return 1;
  }
  do {
    iVar2 = *(int *)(param_1 + 4);
    if (*(int *)(param_1 + 8) == iVar2) break;
    *(int *)(param_1 + 4) = iVar2 + 1;
    iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))(iVar2);
    if (iVar2 == 0) {
      return 0x80040203;
    }
    iVar4 = FUN_00603990(iVar2);
    if (iVar4 == 0) {
      piVar1 = (int *)(iVar2 + 0xc);
      *param_3 = (int)piVar1;
      (**(code **)(*piVar1 + 4))(piVar1);
      local_4 = local_4 + 1;
      param_3 = param_3 + 1;
      FUN_00603a60(iVar2);
      uVar5 = uVar5 - 1;
    }
  } while (uVar5 != 0);
  if (param_4 != (uint *)0x0) {
    *param_4 = local_4;
  }
  return (uint)(param_2 != local_4);
}

