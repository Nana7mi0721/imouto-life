
void __fastcall FUN_006018c0(int param_1)

{
  int *piVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b2458;
  pvStack_c = ExceptionList;
  piVar1 = *(int **)(param_1 + 0x9c);
  local_4 = 0;
  ExceptionList = &pvStack_c;
  if (piVar1 != (int *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  local_4 = 0xffffffff;
  FUN_00601fe0();
  ExceptionList = pvStack_c;
  return;
}

