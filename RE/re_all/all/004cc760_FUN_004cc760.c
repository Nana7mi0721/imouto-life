
undefined4 __thiscall FUN_004cc760(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uStack_30;
  undefined1 local_19;
  undefined1 *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0f10;
  pvStack_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x2c);
  local_18 = (undefined1 *)&uStack_30;
  ExceptionList = &pvStack_10;
  uStack_30 = param_1;
  FUN_004d6890(&uStack_30);
  uVar1 = FUN_004d68b0(&local_19);
  FUN_004d77e0(uVar1);
  uStack_30 = 0x4cc7b1;
  FUN_004d70b0();
  local_8 = 0;
  uStack_30 = param_2;
  FUN_004d6f70();
  ExceptionList = pvStack_10;
  return param_1;
}

