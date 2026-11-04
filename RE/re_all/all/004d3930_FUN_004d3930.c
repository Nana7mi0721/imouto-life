
undefined4 * FUN_004d3930(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *local_1c;
  undefined1 local_14 [4];
  undefined1 local_10 [8];
  undefined4 local_8;
  
  FUN_004ddaa0(&local_8,param_2);
  uVar2 = FUN_004ce060(local_10);
  cVar1 = const_iterator__operator__(uVar2);
  if (cVar1 == '\0') {
    uVar2 = FUN_004e9610();
    uVar2 = FUN_004dd3d0(uVar2);
    cVar1 = FUN_004d59a0(param_2,uVar2);
    if (cVar1 == '\0') {
      local_1c = &local_8;
      goto LAB_004d39a1;
    }
  }
  local_1c = (undefined4 *)FUN_004ce060(local_14);
LAB_004d39a1:
  *param_1 = *local_1c;
  return param_1;
}

