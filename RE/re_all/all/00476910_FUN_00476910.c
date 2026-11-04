
void __fastcall FUN_00476910(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int local_c;
  int local_8;
  
  if (*(char *)(param_1 + 0x19d) != '\0') {
    FUN_00515700(*(undefined4 *)(param_1 + 0x168),0);
    *(undefined1 *)(param_1 + 0x19d) = 0;
  }
  local_8 = 0;
  while( true ) {
    iVar1 = FUN_004ce080();
    if (iVar1 <= local_8) break;
    uVar3 = 0;
    puVar2 = (undefined4 *)FUN_004ce990(local_8);
    FUN_00515700(*puVar2,uVar3);
    local_8 = local_8 + 1;
  }
  local_c = 0;
  while( true ) {
    iVar1 = FUN_004ce080();
    if (iVar1 <= local_c) break;
    uVar3 = 0;
    puVar2 = (undefined4 *)FUN_004ce990(local_c);
    FUN_00515700(*puVar2,uVar3);
    local_c = local_c + 1;
  }
  return;
}

