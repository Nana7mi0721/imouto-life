
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_004d3570(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_4ebc [20132];
  undefined1 local_18 [4];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1176;
  local_10 = ExceptionList;
  local_14 = 0x4d3592;
  ExceptionList = &local_10;
  FUN_004ddaa0(&local_14,param_1);
  uVar2 = FUN_004ce060(local_18);
  cVar1 = const_iterator__operator__(uVar2);
  if (cVar1 == '\0') {
    uVar2 = FUN_004e9610();
    uVar2 = FUN_004dd3d0(uVar2);
    cVar1 = FUN_004d59a0(param_1,uVar2);
    if (cVar1 == '\0') goto LAB_004d3689;
  }
  uVar2 = FUN_004a66a0();
  local_8 = 0;
  uVar2 = FUN_004dea30(param_1,uVar2);
  local_8._0_1_ = 1;
  puVar3 = (undefined4 *)FUN_004dd430(local_4ebc,local_14,uVar2);
  local_14 = *puVar3;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004b3650();
  local_8 = 0xffffffff;
  FUN_004b34a0();
LAB_004d3689:
  iVar4 = FUN_004de9f0();
  ExceptionList = local_10;
  return iVar4 + 0x20;
}

