
void __fastcall FUN_0078bd20(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  *param_1 = &PTR_FUN_00837304;
  if (0 < (int)param_1[2]) {
    do {
      iVar1 = *(int *)(param_1[4] + iVar4 * 4);
      iVar2 = *(int *)(iVar1 + 0xbc);
      if (iVar2 != 0) {
        piVar3 = (int *)(**(code **)(*(int *)param_1[0x13] + 0x20))();
        (**(code **)(*piVar3 + 0x24))(iVar2,param_1[6]);
        (**(code **)(*(int *)param_1[0x13] + 8))(iVar2,param_1[6]);
        *(undefined4 *)(iVar1 + 0xbc) = 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)param_1[2]);
  }
  if (param_1[4] != 0) {
    if (*(char *)(param_1 + 5) != '\0') {
      FUN_00646b80(param_1[4]);
    }
    param_1[4] = 0;
  }
  *(undefined1 *)(param_1 + 5) = 1;
  param_1[4] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}

