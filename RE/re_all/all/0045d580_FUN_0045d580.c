
undefined4 __fastcall FUN_0045d580(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_c;
  
  puVar1 = (undefined4 *)FUN_004ce990(1);
  iVar2 = FUN_00487080(*puVar1);
  if (iVar2 < 0) {
    local_c = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_004ce990(1);
    local_c = FUN_00487080(*puVar1);
  }
  *(undefined4 *)(param_1 + 0x20) = local_c;
  return 1;
}

