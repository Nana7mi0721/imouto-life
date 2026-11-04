
int FUN_004d39f0(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_40 [7];
  undefined1 local_39 [33];
  undefined1 local_18 [4];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0ef8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004de7d0(&local_14,param_1);
  uVar2 = FUN_004ce060(local_18);
  cVar1 = const_iterator__operator__(uVar2);
  if (cVar1 == '\0') {
    uVar2 = FUN_004e9610();
    uVar2 = FUN_004d52c0(uVar2);
    cVar1 = FUN_004d59a0(param_1,uVar2);
    if (cVar1 == '\0') goto LAB_004d3aab;
  }
  local_39[0] = 0;
  uVar2 = FUN_004df360(param_1,local_39);
  local_8 = 0;
  puVar3 = (undefined4 *)FUN_004de160(local_40,local_14,uVar2);
  local_14 = *puVar3;
  local_8 = 0xffffffff;
  FUN_004d4160();
LAB_004d3aab:
  iVar4 = FUN_004df340();
  ExceptionList = local_10;
  return iVar4 + 0x1c;
}

