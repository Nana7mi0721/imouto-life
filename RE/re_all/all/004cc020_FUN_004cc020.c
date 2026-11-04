
int FUN_004cc020(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 extraout_var;
  undefined1 local_1c [4];
  undefined4 local_18 [3];
  undefined1 local_c [4];
  undefined4 local_8;
  
  FUN_004d6070(&local_8,param_1);
  uVar3 = extraout_var;
  uVar2 = FUN_004ce060(local_c);
  cVar1 = const_iterator__operator__(uVar2);
  if (cVar1 == '\0') {
    uVar3 = FUN_004e9610(uVar3);
    uVar3 = FUN_004d52c0(uVar3);
    cVar1 = FUN_004d6210(param_1,uVar3);
    if (cVar1 == '\0') goto LAB_004cc0a7;
  }
  local_18[0] = 0;
  uVar3 = FUN_004df0e0(param_1,local_18);
  puVar4 = (undefined4 *)FUN_004d5a00(local_1c,local_8,uVar3);
  local_8 = *puVar4;
LAB_004cc0a7:
  iVar5 = FUN_004df340();
  return iVar5 + 4;
}

