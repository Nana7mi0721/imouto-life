
undefined4 __thiscall FUN_005fd810(int *param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1[0x1e] + 0x18) == 0) {
    SetEvent((HANDLE)param_1[0x17]);
    return 0;
  }
  if (param_1[0x1c] == 1) {
    SetEvent((HANDLE)param_1[0x17]);
    return 0;
  }
  iVar1 = (**(code **)(*param_1 + 0xa0))();
  if ((iVar1 == 1) && (param_2 != 0)) {
    SetEvent((HANDLE)param_1[0x17]);
    return 0;
  }
  ResetEvent((HANDLE)param_1[0x17]);
  return 1;
}

