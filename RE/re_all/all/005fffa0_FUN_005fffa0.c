
void __fastcall FUN_005fffa0(int param_1)

{
  int *piVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b23d8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  _free(*(void **)(param_1 + 0x3c));
  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  local_4 = 0xffffffff;
  FUN_00602f20();
  ExceptionList = pvStack_c;
  return;
}

