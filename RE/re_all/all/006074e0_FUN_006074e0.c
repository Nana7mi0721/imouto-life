
undefined4 * __thiscall
FUN_006074e0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  LPCRITICAL_SECTION lpCriticalSection;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b269c;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x14);
  ExceptionList = &local_c;
  FUN_005fff30(param_2,param_3,lpCriticalSection,&DAT_00a05fd8,0);
  local_4 = 0;
  InitializeCriticalSection(lpCriticalSection);
  FUN_00606b60(param_4);
  local_4._0_1_ = 2;
  FUN_006061e0(param_5,param_1,param_1 + 0x1a,lpCriticalSection);
  local_4 = CONCAT31(local_4._1_3_,3);
  FUN_006034d0();
  *param_1 = &PTR_FUN_00803a8c;
  param_1[3] = &PTR_LAB_00803a50;
  param_1[4] = &PTR_LAB_00803db0;
  ExceptionList = local_c;
  return param_1;
}

