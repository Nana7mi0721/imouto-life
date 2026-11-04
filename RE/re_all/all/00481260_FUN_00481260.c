
undefined1 FUN_00481260(int param_1)

{
  int iVar1;
  undefined4 extraout_var;
  undefined4 uVar2;
  undefined1 local_7c [4];
  undefined1 local_78 [4];
  int local_74;
  CBitmapButton local_70 [92];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af458;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004ce060(&local_14);
  uVar2 = extraout_var;
  iVar1 = FUN_004cec90(extraout_var);
  if (iVar1 < param_1) {
    param_1 = FUN_004cec90(uVar2);
  }
  for (local_74 = 0; local_74 < param_1; local_74 = local_74 + 1) {
    FUN_004cee70(local_78,0);
  }
  FUN_0046d3c0();
  local_8 = 0;
  FUN_004cedd0(local_7c,local_14,local_70);
  local_8 = 0xffffffff;
  CBitmapButton::~CBitmapButton(local_70);
  ExceptionList = local_10;
  return 1;
}

