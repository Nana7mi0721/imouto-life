
undefined4 * __thiscall FUN_004b4820(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af07c;
  local_10 = ExceptionList;
  puVar2 = param_2;
  puVar3 = param_1;
  ExceptionList = &local_10;
  for (iVar1 = 0x500; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_004b5100(param_2 + 0x500);
  local_8 = 0;
  FUN_004cd960(param_2 + 0x50b);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004cf2d0(param_2 + 0x50f);
  ExceptionList = local_10;
  return param_1;
}

