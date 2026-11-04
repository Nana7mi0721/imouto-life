
undefined4 * __thiscall
FUN_006099a0(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  void *pvVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b279f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00608d60(s_SampleGrabber_00a0613c,param_2,&DAT_0085e8a4,param_3,param_4 != 0);
  local_4 = 0;
  param_1[0x28] = &PTR_LAB_00803488;
  FUN_006034d0();
  param_1[0x3b] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x3c));
  local_4._0_1_ = 2;
  *param_1 = &PTR_LAB_00803dc4;
  param_1[3] = &PTR_LAB_00803800;
  param_1[4] = &PTR_LAB_00803db0;
  param_1[0x28] = &PTR_LAB_00803d94;
  pvVar1 = operator_new(0x108);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00609450(param_1,param_3);
  }
  param_1[0x23] = iVar2;
  if ((iVar2 == 0) && (param_3 != (undefined4 *)0x0)) {
    *param_3 = 0x8007000e;
  }
  ExceptionList = local_c;
  return param_1;
}

