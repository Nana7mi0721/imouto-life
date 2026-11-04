
undefined4 FUN_00423060(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int local_10;
  int local_c;
  undefined1 local_8 [4];
  
  FUN_004cc870(local_8);
  local_c = 0;
  while( true ) {
    iVar1 = FUN_004cd340();
    if (iVar1 <= local_c) break;
    local_10 = 0;
    while( true ) {
      FUN_004cde80(local_c);
      iVar1 = FUN_004ce080();
      if (iVar1 <= local_10) break;
      uVar3 = 0;
      iVar1 = local_10;
      FUN_004cde80(local_c);
      puVar2 = (undefined4 *)FUN_004ce990(iVar1);
      FUN_00515700(*puVar2,uVar3);
      local_10 = local_10 + 1;
    }
    local_c = local_c + 1;
  }
  FUN_004cd4c0();
  FUN_004ccc40();
  FUN_004ce950();
  FUN_004ce950();
  return 1;
}

