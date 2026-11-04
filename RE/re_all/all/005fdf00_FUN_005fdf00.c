
bool __thiscall FUN_005fdf00(int *param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 local_10 [8];
  undefined1 local_8 [8];
  
  if (param_2 == 0) {
    return false;
  }
  puVar3 = local_8;
  puVar2 = local_10;
  iVar1 = (**(code **)(*param_1 + 0x58))(param_2,puVar2,puVar3);
  if (iVar1 < 0) {
    return false;
  }
  if (iVar1 == 0) {
    SetEvent((HANDLE)param_1[0x15]);
    return true;
  }
  iVar1 = (**(code **)(*(int *)param_1[6] + 0x10))
                    ((int *)param_1[6],param_1[8],param_1[9],puVar2,puVar3,param_1[0x15],
                     param_1 + 0x1a);
  return -1 < iVar1;
}

