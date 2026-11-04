
void __fastcall FUN_004c03f0(undefined4 param_1)

{
  int iVar1;
  uint *puVar2;
  undefined1 *puVar3;
  int local_8;
  
  FUN_004c04a0(param_1);
  local_8 = 0;
  while( true ) {
    iVar1 = FUN_004ce080();
    if (iVar1 <= local_8) break;
    puVar2 = (uint *)FUN_004ce990(local_8);
    if ((*puVar2 & 0x10) == 0) {
      puVar2 = (uint *)FUN_004ce990(local_8);
      if ((*puVar2 & 0x100) == 0) {
        puVar3 = (undefined1 *)FUN_004cd7c0(local_8);
        *puVar3 = 0;
      }
      else {
        puVar3 = (undefined1 *)FUN_004cd7c0(local_8);
        *puVar3 = 1;
      }
    }
    else {
      puVar3 = (undefined1 *)FUN_004cd7c0(local_8);
      *puVar3 = 2;
    }
    local_8 = local_8 + 1;
  }
  return;
}

