
void FUN_006bd010(int param_1,int *param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int local_4;
  
  local_4 = 0;
  do {
    uVar1 = 0;
    do {
      uVar3 = local_4 * 2 | uVar1;
      iVar2 = *param_2 * (param_4 + local_4) + uVar1;
      uVar1 = uVar1 + 1;
      *(int *)(param_1 + uVar3 * 4) = iVar2 + param_3;
    } while ((int)uVar1 < 2);
    local_4 = local_4 + 1;
  } while (local_4 < 2);
  return;
}

