
undefined4 * __thiscall FUN_00446ca0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007ad69d;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_00440ae0();
  local_8._0_1_ = 1;
  *param_1 = &PTR_FUN_007d0aac;
  FUN_004d1f30();
  local_8._0_1_ = 2;
  FUN_0046d0e0();
  local_8._0_1_ = 3;
  FUN_0046cff0(0xffffffff);
  local_8._0_1_ = 4;
  FUN_004ce9d0();
  local_8 = CONCAT31(local_8._1_3_,5);
  param_1[0x52] = param_2;
  FUN_0046f560(&param_3);
  param_1[9] = param_3;
  *(undefined1 *)((int)param_1 + 0xbe) = 0;
  *(undefined1 *)((int)param_1 + 0x1f1) = 0;
  *(undefined1 *)((int)param_1 + 0x53) = 1;
  param_1[0x57] = 0xffffffff;
  param_1[0x7a] = 0;
  FUN_004d2300();
  param_1[0x94] = 0xffffffff;
  param_1[0x95] = 0xffffffff;
  FUN_00442fb0(param_1[0x85],param_1[0x86],0);
  local_14 = 0;
  local_18 = FUN_004cf130();
  local_18 = local_18 + -1;
  do {
    if (0 < local_18) {
LAB_00446e27:
      FUN_004cf170(local_14);
      cVar1 = FUN_004799b0();
      if (cVar1 != '\0') {
        param_1[0xb] = param_1[0x86] * 2 + -1;
        param_1[0xf] = DAT_0084b264 * 2 * param_1[0xb];
      }
      FUN_00446f20();
      local_8 = 0xffffffff;
      FUN_0046f510();
      ExceptionList = local_10;
      return param_1;
    }
    uVar2 = param_1[0x7d];
    FUN_004cf170(local_18);
    cVar1 = FUN_00479720(uVar2);
    if (cVar1 != '\0') {
      local_14 = local_18;
      goto LAB_00446e27;
    }
    local_18 = local_18 + 1;
  } while( true );
}

