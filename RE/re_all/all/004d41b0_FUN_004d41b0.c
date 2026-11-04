
int __thiscall FUN_004d41b0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae85e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004d4260(param_2);
  local_8 = 0;
  puVar2 = (undefined4 *)(param_2 + 0x24);
  puVar3 = (undefined4 *)(param_1 + 0x24);
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_004a5960(param_2 + 0x4c);
  local_8._0_1_ = 1;
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 100);
  FUN_004cea00(param_2 + 0x68);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_004cd4e0(param_2 + 0x78);
  ExceptionList = local_10;
  return param_1;
}

