
undefined4 __thiscall FUN_0046d300(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 local_74 [4];
  CBitmapButton local_70 [84];
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af458;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004ce060(&local_14);
  if (*(int *)(param_1 + 100) < param_2) {
    param_2 = *(int *)(param_1 + 100);
  }
  for (local_18 = 0; local_18 < param_2; local_18 = local_18 + 1) {
    FUN_004cee70(local_1c,0);
  }
  uVar1 = FUN_0046d3c0();
  local_8 = 0;
  FUN_004cedd0(local_74,local_14,uVar1);
  local_8 = 0xffffffff;
  CBitmapButton::~CBitmapButton(local_70);
  ExceptionList = local_10;
  return 1;
}

