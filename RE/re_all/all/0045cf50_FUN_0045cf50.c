
undefined4 __fastcall FUN_0045cf50(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  local_8 = (int)*(char *)(*(int *)(param_1 + 0x898) + 0x10);
  FUN_004ce160(&local_8);
  puVar1 = (undefined4 *)FUN_004ce990(1);
  local_c = FUN_00487080(*puVar1);
  local_c = local_c + -1;
  FUN_004ce160(&local_c);
  puVar1 = (undefined4 *)FUN_004ce990(1);
  iVar2 = FUN_00487080(*puVar1);
  if (iVar2 < 1) {
    FUN_0045d090();
  }
  return 1;
}

