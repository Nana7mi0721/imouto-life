
int FUN_006c49c0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = FUN_006c4a50(0,param_2,param_3);
    return iVar1;
  }
  FUN_006ab9d0(&local_10);
  iVar1 = FUN_006c4a50(&local_10,param_2,param_3);
  if (iVar1 < 0) {
    FUN_006c4970(&local_10);
    return iVar1;
  }
  *param_1 = local_10;
  param_1[1] = local_c;
  param_1[2] = local_8;
  param_1[3] = local_4;
  return iVar1;
}

