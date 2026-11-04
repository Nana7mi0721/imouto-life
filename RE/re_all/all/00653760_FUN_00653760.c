
int * FUN_00653760(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int *local_28;
  int local_24;
  undefined2 local_20;
  undefined2 local_1e;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  undefined1 local_a;
  undefined1 local_9;
  undefined4 local_8;
  undefined4 local_4;
  
  local_28 = &local_24;
  piVar2 = *(int **)(param_1 + 0x298);
  local_20 = 0;
  local_1e = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_a = 0;
  local_9 = 0;
  local_8 = 0;
  local_4 = 0;
  if (((piVar2 == (int *)0x0) || (*piVar2 != param_2)) || ((param_3 != 0 && (param_3 != piVar2[2])))
     ) {
    if (*(void **)(param_1 + 0x290) == (void *)0x0) {
      return (int *)0x0;
    }
    local_1c = param_3;
    local_24 = param_2;
    puVar1 = _bsearch(&local_28,*(void **)(param_1 + 0x290),*(size_t *)(param_1 + 0x294),4,
                      (_PtFuncCompare *)&LAB_00653650);
    if (puVar1 != (undefined4 *)0x0) {
      piVar2 = (int *)*puVar1;
      *(int **)(param_1 + 0x298) = piVar2;
      return piVar2;
    }
    piVar2 = (int *)0x0;
    *(undefined4 *)(param_1 + 0x298) = 0;
  }
  return piVar2;
}

