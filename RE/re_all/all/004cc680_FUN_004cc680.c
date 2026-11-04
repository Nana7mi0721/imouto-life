
int FUN_004cc680(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_40 [4];
  undefined4 local_3c [9];
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
    if (cVar1 == '\0') goto LAB_004cc73e;
  }
  local_3c[0] = 0;
  uVar2 = FUN_004f0d00(param_1,local_3c);
  local_8 = 0;
  puVar3 = (undefined4 *)FUN_004d68c0(local_40,local_14,uVar2);
  local_14 = *puVar3;
  local_8 = 0xffffffff;
  FUN_004d4160();
LAB_004cc73e:
  iVar4 = FUN_004df340();
  ExceptionList = local_10;
  return iVar4 + 0x1c;
}

