
undefined4 FUN_00563630(int *param_1,_GUID *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x80070057;
  }
  *param_3 = 0;
  iVar1 = FID_conflict_operator__(param_2,(_GUID *)&DAT_0085e5a4);
  if ((iVar1 == 0) && (iVar1 = FID_conflict_operator__(param_2,(_GUID *)&DAT_0085ef34), iVar1 == 0))
  {
    return 0x80004002;
  }
  *param_3 = param_1;
  if (param_1 == (int *)0x0) {
    return 0x80004002;
  }
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}

