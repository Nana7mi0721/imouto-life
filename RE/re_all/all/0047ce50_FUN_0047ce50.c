
void __fastcall FUN_0047ce50(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int local_c;
  int local_8;
  
  FUN_004ce950(param_1);
  FUN_004ce950();
  FUN_004ce950();
  local_8 = 0;
  while( true ) {
    iVar1 = FUN_004717c0(3);
    if (iVar1 <= local_8) break;
    puVar2 = (undefined4 *)FUN_004cc020(&local_8);
    FUN_0055f370(*puVar2);
    local_8 = local_8 + 1;
  }
  local_c = 0;
  while( true ) {
    iVar1 = FUN_004ce080();
    if (iVar1 <= local_c) break;
    puVar2 = (undefined4 *)FUN_004ce990(local_c);
    iVar1 = FUN_00560f10(*puVar2);
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)FUN_004ce990(local_c);
      FUN_0055f370(*puVar2);
    }
    local_c = local_c + 1;
  }
  FUN_004ce950();
  return;
}

