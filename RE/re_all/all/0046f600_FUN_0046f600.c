
int __thiscall FUN_0046f600(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    iVar1 = FUN_004cf550(param_1);
    if (iVar1 <= local_8) {
      return -1;
    }
    piVar2 = (int *)FUN_004cf590(local_8);
    if (*piVar2 == param_2) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

